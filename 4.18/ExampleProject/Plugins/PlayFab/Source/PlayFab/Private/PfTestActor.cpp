
#include "PfTestActor.h"
#include "PlayFabPrivate.h"
#include "PlayFabEnums.h"
#include "PlayFabClientAPI.h"

const int SUMMARY_INIT_BUFFER_SIZE = 10000;
const int TEST_TIMEOUT_SECONDS = 10;

// Sets default values
APfTestActor::APfTestActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APfTestActor::BeginPlay()
{
    Super::BeginPlay();
    InitializeTestSuite();
}

// Called every frame
void APfTestActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    TickTestSuite();
    _outputSummary = GenerateTestSummary();
}

/////////////////////////////////////// The actual testing framework ///////////////////////////////////////
void APfTestActor::InitializeTestSuite()
{
    bool setupSuccessful = ClassSetup();

    // Reset testContexts if this has already been run (The results are kept for later viewing)
    testContexts.Empty();

    if (setupSuccessful)
    {

        AppendTest("InvalidLogin");
        AppendTest("InvalidRegistration");
        AppendTest("LoginOrRegister");
        AppendTest("MultiUserLogin");
        AppendTest("LoginWithAdvertisingId");
        AppendTest("UserDataApi");
        AppendTest("PlayerStatisticsApi");
        AppendTest("UserCharacter");
        AppendTest("LeaderBoard");
        AppendTest("AccountInfo");
        AppendTest("CloudScript");
        AppendTest("CloudScriptError");
        AppendTest("WriteEvent");

        AppendTest("ServerTitleData");

        AppendTest("GetEntityToken");
        AppendTest("ObjectApi");
    }
}

void APfTestActor::AppendTest(const FString& testFuncName)
{
    UPfTestContext::FApiTestCase eachTestDelegate;
    eachTestDelegate.BindUFunction(this, *testFuncName);
    if (eachTestDelegate.IsBound())
    {
        UPfTestContext* eachTestContext = NewObject<UPfTestContext>(this);
        eachTestContext->Setup(testFuncName, eachTestDelegate);
        testContexts.Add(eachTestContext);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("%s: %s"), *testFuncName, TEXT("Critical Failure: Cannot bind test UFUNCTION."));
    }
}

bool APfTestActor::TickTestSuite()
{
    if (IPlayFab::Get().GetPendingCallCount() > 0)
        return false; // The active test won't advance until all outstanding calls return

    int unfinishedTests = 0;
    UPfTestContext* nextTest = nullptr;
    for (int i = 0; i < testContexts.Num(); i++)
    {
        auto eachState = testContexts[i]->activeState;

        if (eachState != PlayFabApiTestActiveState::COMPLETE && eachState != PlayFabApiTestActiveState::ABORTED)
            unfinishedTests++;

        if (eachState == PlayFabApiTestActiveState::ACTIVE || eachState == PlayFabApiTestActiveState::READY) // Find the active test, and prioritize it
            nextTest = testContexts[i];
        else if (eachState == PlayFabApiTestActiveState::PENDING && nextTest == nullptr) // Or find a test to start
            nextTest = testContexts[i];
    }

    if (nextTest != nullptr && !nextTest->IsValidLowLevel())
    {
        UE_LOG(LogTemp, Error, TEXT("%s"), TEXT("Critical Failure: Test context has become invalid."));
        return true;
    }

    if (nextTest != nullptr && nextTest->activeState == PlayFabApiTestActiveState::PENDING)
        StartTest(nextTest);
    else if (nextTest != nullptr)
        TickTest(nextTest);

    bool result = unfinishedTests == 0; // Return whether tests are complete
    return result;
}

FString APfTestActor::GenerateTestSummary()
{
    _outputSummary.Empty(SUMMARY_INIT_BUFFER_SIZE); // Set the capacity to handle everything we're about to put into it

    FDateTime now = FDateTime::UtcNow();
    int numPassed = 0;
    int numFailed = 0;
    for (int i = 0; i < testContexts.Num(); i++)
    {
        if (_outputSummary.Len() != 0)
            _outputSummary += '\n';
        _outputSummary += testContexts[i]->GenerateTestSummary(now);
        if (testContexts[i]->finishState == PlayFabApiTestFinishState::PASSED) numPassed++;
        else if (testContexts[i]->finishState == PlayFabApiTestFinishState::FAILED) numFailed++;
    }

    FString testCountLine = "\nTotal tests: ";
    testCountLine += FString::FromInt(testContexts.Num());
    testCountLine += ", Passed: ";
    testCountLine += FString::FromInt(numPassed);
    testCountLine += ", Failed: ";
    testCountLine += FString::FromInt(numFailed);

    _outputSummary += testCountLine;
    return _outputSummary;
}

bool APfTestActor::ClassSetup()
{
    // README:
    // modify the TEST_TITLE_DATA_LOC to a location of a testTitleData.json file
    // The format of this file is described in the sdk readme
    //  - OR -
    // Comment the "return false;" below, and
    //   Fill in all the variables under: POPULATE THIS SECTION WITH REAL INFORMATION

    IPlayFab* playFabSettings = &(IPlayFab::Get());

    playFabSettings->setAdvertisingIdType(TEXT(""));
    playFabSettings->setAdvertisingIdValue(TEXT(""));

    // Prefer to load path from environment variable, if present
#if PLATFORM_WINDOWS
    char* envPath = nullptr;
    size_t envPathStrLen;
    errno_t err = _dupenv_s(&envPath, &envPathStrLen, "PF_TEST_TITLE_DATA_JSON");
    if (err == 0 && envPath != nullptr)
        TEST_TITLE_DATA_LOC = FString(ANSI_TO_TCHAR(envPath));
    free(envPath); // It's OK to call free with NULL
#endif

    FString titleDataJson;
    if (FFileHelper::LoadFileToString(titleDataJson, *TEST_TITLE_DATA_LOC))
    {
        TSharedPtr<FJsonObject> JsonObject;
        TSharedRef< TJsonReader<> > Reader = TJsonReaderFactory<>::Create(titleDataJson);
        FJsonSerializer::Deserialize(Reader, JsonObject);
        playFabSettings->setGameTitleId(JsonObject->GetStringField(TEXT("titleId")));
        playFabSettings->setApiSecretKey(JsonObject->GetStringField(TEXT("developerSecretKey")));
        userEmail = JsonObject->GetStringField(TEXT("userEmail"));
    }
    else
    {
        // Add your real test data here and remove this return if you want to skip testTitleData
        return false;

        // Populate this section with real information, if you're not using the testTitleData.json file (or are using a device)
        playFabSettings->setGameTitleId(TEXT("")); // Without a titleId, your game will do terrible things (usually crash)
        playFabSettings->setApiSecretKey(TEXT("")); // Non-client api calls will all crash without a secret key
        userEmail = "yourEmail"; // This is the email for the user
    }

    // Verify all the inputs won't cause crashes in the tests
    return playFabSettings->getGameTitleId().Len() > 0
        && (userEmail.Len() > 0);
}

// Start a test, and block until the threaded response arrives
void APfTestActor::StartTest(UPfTestContext* testContext)
{
    UE_LOG(LogTemp, Log, TEXT("Starting Test: %s"), *(testContext->testName));
    testContext->activeState = PlayFabApiTestActiveState::ACTIVE;
    testContext->startTime = FDateTime::UtcNow();
    testContext->testFunc.Execute(testContext);
    // Async tests can't resolve this tick, so just return
}

void APfTestActor::TickTest(UPfTestContext* testContext)
{
    FDateTime now = FDateTime::UtcNow();
    if (testContext->activeState != PlayFabApiTestActiveState::READY // Not finished
        && (now - testContext->startTime) < FTimespan::FromSeconds(TEST_TIMEOUT_SECONDS)) // Not timed out
        return;

    testContext->endTime = now;
    testContext->activeState = PlayFabApiTestActiveState::COMPLETE;
}

// This should be called in the api-responses, which are threaded.  This will allow TickTest to finalize the test
void APfTestActor::EndTest(UPfTestContext* testContext, PlayFabApiTestFinishState finishState, FString resultMsg)
{
    testContext->testResultMsg = resultMsg;
    testContext->finishState = finishState;
    testContext->activeState = PlayFabApiTestActiveState::READY;
}

void APfTestActor::OnSharedError(FPlayFabError error, UObject* customData)
{
    UPfTestContext* testContext = dynamic_cast<UPfTestContext*>(customData);
    EndTest(testContext, PlayFabApiTestFinishState::FAILED, "Unexpected error: " + error.ErrorMessage + "\n" + error.ErrorDetails);
}

/// <summary>
/// CLIENT API
/// Try to deliberately log in with an inappropriate password,
///   and verify that the error displays as expected.
/// </summary>
void APfTestActor::InvalidLogin(UPfTestContext* testContext)
{
    FClientLoginWithEmailAddressRequest request;
    request.Email = userEmail;
    request.Password = "INVALID";
    request.InfoRequestParameters = nullptr;
    UPlayFabClientAPI::FDelegateOnSuccessLoginWithEmailAddress onSuccess; onSuccess.BindUFunction(this, "InvalidLoginSuccess");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError; onError.BindUFunction(this, "InvalidLoginFail");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::LoginWithEmailAddress(request, onSuccess, onError, testContext);
    callObj->Activate();
}
void APfTestActor::InvalidLoginSuccess(FClientLoginResult result, UObject* customData)
{
    UPfTestContext* testContext = dynamic_cast<UPfTestContext*>(customData);
    EndTest(testContext, PlayFabApiTestFinishState::FAILED, "Expected login to fail");
}
void APfTestActor::InvalidLoginFail(FPlayFabError error, UObject* customData)
{
    UPfTestContext* testContext = dynamic_cast<UPfTestContext*>(customData);
    if (error.ErrorMessage.Find("password") != -1)
        EndTest(testContext, PlayFabApiTestFinishState::PASSED, "");
    else
        EndTest(testContext, PlayFabApiTestFinishState::FAILED, "Password error message not found: " + error.ErrorMessage + "\n - " + error.ErrorDetails);
}

/// <summary>
/// CLIENT API
/// Try to deliberately register a user with an invalid email and password
///   Verify that errorDetails are populated correctly.
/// </summary>
void APfTestActor::InvalidRegistration(UPfTestContext* testContext)
{
    FClientRegisterPlayFabUserRequest request;
    request.Username = "x";
    request.Email = "x";
    request.Password = "x";
    UPlayFabClientAPI::FDelegateOnSuccessRegisterPlayFabUser onSuccess; onSuccess.BindUFunction(this, "InvalidRegistrationSuccess");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError; onError.BindUFunction(this, "InvalidRegistrationFail");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::RegisterPlayFabUser(request, onSuccess, onError, testContext);
    callObj->Activate();
}
void APfTestActor::InvalidRegistrationSuccess(FClientRegisterPlayFabUserResult result, UObject* customData)
{
    UPfTestContext* testContext = dynamic_cast<UPfTestContext*>(customData);
    EndTest(testContext, PlayFabApiTestFinishState::FAILED, "Expected registration to fail");
}
void APfTestActor::InvalidRegistrationFail(FPlayFabError error, UObject* customData)
{
    bool foundEmailMsg, foundPasswordMsg;
    FString expectedEmailMsg = "Email address is not valid.";
    FString expectedPasswordMsg = "Password must be between";

    foundEmailMsg = (error.ErrorDetails.Find(expectedEmailMsg) != -1);
    foundPasswordMsg = (error.ErrorDetails.Find(expectedPasswordMsg) != -1);

    UPfTestContext* testContext = dynamic_cast<UPfTestContext*>(customData);
    if (foundEmailMsg && foundPasswordMsg)
        EndTest(testContext, PlayFabApiTestFinishState::PASSED, "");
    else
        EndTest(testContext, PlayFabApiTestFinishState::FAILED, "All error details: " + error.ErrorDetails);
}

/// <summary>
/// CLIENT API
/// Test a sequence of calls that modifies saved data,
///   and verifies that the next sequential API call contains updated data.
/// Verify that the data is correctly modified on the next call.
/// Parameter types tested: string, Dictionary<string, string>, DateTime
/// </summary>
void APfTestActor::LoginOrRegister(UPfTestContext* testContext)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());

    FClientLoginWithCustomIDRequest request;
    request.CustomId = playFabSettings->getBuildIdentifier();
    request.CreateAccount = true;
    request.InfoRequestParameters = nullptr;
    UPlayFabClientAPI::FDelegateOnSuccessLoginWithCustomID onSuccess; onSuccess.BindUFunction(this, "OnLoginOrRegister");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError; onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::LoginWithCustomID(request, onSuccess, onError, testContext);
    callObj->Activate();
}
void APfTestActor::OnLoginOrRegister(FClientLoginResult result, UObject* customData)
{
    playFabId = result.PlayFabId;
    UPfTestContext* testContext = dynamic_cast<UPfTestContext*>(customData);
    EndTest(testContext, PlayFabApiTestFinishState::PASSED, "");
}

/// <summary>
/// CLIENT API
/// Test the multi-user login functionality by logging in as two separate 
///  users, getting the profile data for each, and verifying that their 
///  specified credentials are being used instead of the statically 
///  stored ones
/// </summary>
void APfTestActor::MultiUserLogin(UPfTestContext* testContext)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());

    // Cache the static login credentials. We will be clearing these in order to test the multi-user functionality
    //  that circumvents them, but other tests depend on these being set so we need to clean up after ourselves
    // TODO: Update test framework with a setup/teardown for each test that handles this, so that tests don't depend on each other's side effects
    cachedClientSessionTicket = playFabSettings->getSessionTicket();
    cachedEntityToken         = playFabSettings->getEntityToken();
    cachedDeveloperSecretKey  = playFabSettings->getSecretApiKey();

    // Log In User 1
    FClientLoginWithCustomIDRequest request1{};
    request1.CustomId = TEXT("UE4MultiUserBp_1");
    request1.CreateAccount = true;

    UPlayFabClientAPI::FDelegateOnSuccessLoginWithCustomID onSuccess1; onSuccess1.BindUFunction(this, "OnMultiUser1Login");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError1; onError1.BindUFunction(this, "OnMultiUserFail");
    UPlayFabClientAPI* callObj1 = UPlayFabClientAPI::LoginWithCustomID(request1, onSuccess1, onError1, testContext);
    callObj1->Activate();

    // Log In User 2
    FClientLoginWithCustomIDRequest request2{};
    request2.CustomId = TEXT("UE4MultiUserBp_2");
    request2.CreateAccount = true;

    UPlayFabClientAPI::FDelegateOnSuccessLoginWithCustomID onSuccess2; onSuccess2.BindUFunction(this, "OnMultiUser2Login");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError2; onError2.BindUFunction(this, "OnMultiUserFail");
    UPlayFabClientAPI* callObj2 = UPlayFabClientAPI::LoginWithCustomID(request2, onSuccess2, onError2, testContext);
    callObj2->Activate();
}

void APfTestActor::OnMultiUser1Login(FClientLoginResult result, UObject* customData)
{
    multiUser1LoginResult = result;
    
    if (multiUser2LoginResult.EntityToken != nullptr)
        OnBothUsersLogin(customData);
}

void APfTestActor::OnMultiUser2Login(FClientLoginResult result, UObject* customData)
{
    multiUser2LoginResult = result;
    
    if (multiUser1LoginResult.EntityToken != nullptr)
        OnBothUsersLogin(customData);
}

void APfTestActor::OnBothUsersLogin(UObject* customData)
{
    UPfTestContext* testContext = dynamic_cast<UPfTestContext*>(customData);

    // Ensure that classic credentials (global, statically stored) aren't used:
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    playFabSettings->setSessionTicket(TEXT(""));
    playFabSettings->setEntityToken(TEXT(""));
    playFabSettings->setApiSecretKey(TEXT(""));

    // Get User 1 Profile
    FClientGetPlayerProfileRequest request1{};
    request1.AuthenticationContext = multiUser1LoginResult.AuthenticationContext;
    request1.PlayFabId = multiUser1LoginResult.PlayFabId;

    UPlayFabClientAPI::FDelegateOnSuccessGetPlayerProfile onSuccess1; onSuccess1.BindUFunction(this, "OnMultiUser1GetProfile");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError1; onError1.BindUFunction(this, "OnMultiUserFail");
    UPlayFabClientAPI* callObj1 = UPlayFabClientAPI::GetPlayerProfile(request1, onSuccess1, onError1, testContext);
    callObj1->Activate();

    // Get User 2 Profile
    FClientGetPlayerProfileRequest request2{};
    request2.AuthenticationContext = multiUser2LoginResult.AuthenticationContext;
    request2.PlayFabId = multiUser2LoginResult.PlayFabId;

    UPlayFabClientAPI::FDelegateOnSuccessGetPlayerProfile onSuccess2; onSuccess2.BindUFunction(this, "OnMultiUser2GetProfile");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError2; onError2.BindUFunction(this, "OnMultiUserFail");
    UPlayFabClientAPI* callObj2 = UPlayFabClientAPI::GetPlayerProfile(request2, onSuccess2, onError2, testContext);
    callObj2->Activate();
}

void APfTestActor::OnMultiUser1GetProfile(FClientGetPlayerProfileResult result, UObject* customData)
{
    multiUser1ProfileResult = result;
    
    if (multiUser2ProfileResult.PlayerProfile != nullptr)
        OnBothUsersGetProfile(customData);
}

void APfTestActor::OnMultiUser2GetProfile(FClientGetPlayerProfileResult result, UObject* customData)
{
    multiUser2ProfileResult = result;
    
    if (multiUser1ProfileResult.PlayerProfile != nullptr)
        OnBothUsersGetProfile(customData);
}

void APfTestActor::OnBothUsersGetProfile(UObject* customData)
{
    UPfTestContext* testContext = dynamic_cast<UPfTestContext*>(customData);
    ApplyCachedCredentials();
    EndTest(testContext, PlayFabApiTestFinishState::PASSED, "");
}

void APfTestActor::OnMultiUserFail(FPlayFabError error, UObject* customData)
{
    ApplyCachedCredentials();
    OnSharedError(error, customData);
}

/// <summary>
/// Restore the static credentials originally set by LoginOrRegister but wiped in this test, as other tests depend on them
///  TODO: Update test framework with a setup/teardown for each test that handles this, so that tests don't depend on each other's side effects
/// </summary>
void APfTestActor::ApplyCachedCredentials()
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    
    playFabSettings->setSessionTicket(cachedClientSessionTicket);
    playFabSettings->setEntityToken(cachedEntityToken);
    playFabSettings->setApiSecretKey(cachedDeveloperSecretKey);
}

/// <summary>
/// CLIENT API
/// Test that the login call sequence sends the AdvertisingId when set
/// </summary>
void APfTestActor::LoginWithAdvertisingId(UPfTestContext* testContext)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    playFabSettings->setAdvertisingIdType(playFabSettings->getAD_TYPE_ANDROID_ID());
    playFabSettings->setAdvertisingIdValue(TEXT("PlayFabTestId"));

    FClientLoginWithCustomIDRequest request;
    request.CustomId = playFabSettings->getBuildIdentifier();
    request.CreateAccount = true;
    request.InfoRequestParameters = nullptr;
    UPlayFabClientAPI::FDelegateOnSuccessLoginWithCustomID onSuccess; onSuccess.BindUFunction(this, "OnLoginWithAdvertisingId");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError; onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::LoginWithCustomID(request, onSuccess, onError, testContext);
    callObj->Activate();
}
void APfTestActor::OnLoginWithAdvertisingId(FClientLoginResult result, UObject* customData)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    // TODO: Need to wait for the NEXT api call to complete, and then test playFabSettings->AdvertisingIdType (Oh right... need to actually change AdvertisingIdType too...
    UPfTestContext* testContext = dynamic_cast<UPfTestContext*>(customData);
    EndTest(testContext, PlayFabApiTestFinishState::PASSED, "");
}

/// <summary>
/// CLIENT API
/// Test a sequence of calls that modifies saved data,
///   and verifies that the next sequential API call contains updated data.
/// Verify that the data is correctly modified on the next call.
/// Parameter types tested: string, Dictionary<string, string>, DateTime
/// </summary>
void APfTestActor::UserDataApi(UPfTestContext* testContext)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    if (!playFabSettings->IsClientLoggedIn())
    {
        EndTest(testContext, PlayFabApiTestFinishState::SKIPPED, "Earlier tests failed to log in");
        return;
    }

    FClientGetUserDataRequest request;
    request.IfChangedFromDataVersion = 0;
    UPlayFabClientAPI::FDelegateOnSuccessGetUserData onSuccess; onSuccess.BindUFunction(this, "OnUserDataApiGet1");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError; onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::GetUserData(request, onSuccess, onError, testContext);
    callObj->Activate();
}
void APfTestActor::OnUserDataApiGet1(FClientGetUserDataResult result, UObject* customData)
{
    TryExtractIntFromUserData(result.Data, TEST_DATA_KEY, testMessageInt, testMessageTime); // We don't care about failure here, because it's legitimate if the data doesn't exist yet
    testMessageInt = (testMessageInt + 1) % 100;

    FClientUpdateUserDataRequest updateRequest;
    updateRequest.Data = NewObject<UPlayFabJsonObject>(); // This will be GC'd almost immediately since there's no living UPROPERTY references to it (updateRequest doesn't count), but that's ok, because it only needs to survive until UPlayFabClientAPI::UpdateUserData returns
    updateRequest.Data->SetStringField(TEST_DATA_KEY, FString::FromInt(testMessageInt));
    updateRequest.Permission = EUserDataPermission::pfenum_Public;
    UPlayFabClientAPI::FDelegateOnSuccessUpdateUserData onSuccess; onSuccess.BindUFunction(this, "OnUserDataApiUpdate");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError; onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::UpdateUserData(updateRequest, onSuccess, onError, customData);
    callObj->Activate();
}
void APfTestActor::OnUserDataApiUpdate(FClientUpdateUserDataResult result, UObject* customData)
{
    FClientGetUserDataRequest request;
    request.IfChangedFromDataVersion = 0;
    UPlayFabClientAPI::FDelegateOnSuccessGetUserData onSuccess; onSuccess.BindUFunction(this, "OnUserDataApiGet2");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError; onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::GetUserData(request, onSuccess, onError, customData);
    callObj->Activate();
}
void APfTestActor::OnUserDataApiGet2(FClientGetUserDataResult result, UObject* customData)
{
    UPfTestContext* testContext = dynamic_cast<UPfTestContext*>(customData);

    FDateTime now = FDateTime::UtcNow();
    FDateTime minTime = now - FTimespan(0, 5, 0);
    FDateTime maxTime = now + FTimespan(0, 5, 0);

    int actualDataValue;
    bool exists = TryExtractIntFromUserData(result.Data, TEST_DATA_KEY, actualDataValue, testMessageTime);
    if (!exists)
        EndTest(testContext, PlayFabApiTestFinishState::FAILED, "Expected data is not present.");
    else if (testMessageInt != actualDataValue)
        EndTest(testContext, PlayFabApiTestFinishState::FAILED, "User data not updated as expected.");
    else if (testMessageTime < minTime || maxTime < testMessageTime)
        EndTest(testContext, PlayFabApiTestFinishState::FAILED, "Timestamp out of range: " + minTime.ToString() + "!<" + testMessageTime.ToString() + "!<" + maxTime.ToString());
    else if (!(minTime <= testMessageTime && testMessageTime <= maxTime))
        EndTest(testContext, PlayFabApiTestFinishState::FAILED, "DateTime not parsed correctly.");
    else
        EndTest(testContext, PlayFabApiTestFinishState::PASSED, "");
}
bool APfTestActor::TryExtractIntFromUserData(const UPlayFabJsonObject* jsonObj, const FString& key, int& outValue, FDateTime& outTime)
{
    outValue = 1; // The default if we fail
    outTime = FDateTime::MinValue();

    if (!jsonObj->HasField(key))
    {
        return false;
    }
    auto dataElementObj = jsonObj->GetObjectField(key);

    if (!dataElementObj->HasField("Value"))
    {
        return false;
    }
    FString valueStr = dataElementObj->GetStringField("Value");

    if (!dataElementObj->HasField("LastUpdated"))
    {
        return false;
    }
    FString dateStr = dataElementObj->GetStringField("LastUpdated");

    outValue = FCString::Atoi(*valueStr);
    FDateTime::ParseIso8601(*dateStr, outTime);
    return true;
}

/// <summary>
/// CLIENT API
/// Test a sequence of calls that modifies saved data,
///   and verifies that the next sequential API call contains updated data.
/// Verify that the data is saved correctly, and that specific types are tested
/// Parameter types tested: Dictionary<string, int>
/// </summary>
void APfTestActor::PlayerStatisticsApi(UPfTestContext* testContext)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    if (!playFabSettings->IsClientLoggedIn())
    {
        EndTest(testContext, PlayFabApiTestFinishState::SKIPPED, "Earlier tests failed to log in");
        return;
    }

    FClientGetPlayerStatisticsRequest request;
    UPlayFabClientAPI::FDelegateOnSuccessGetPlayerStatistics onSuccess; onSuccess.BindUFunction(this, "OnPlayerStatisticsApiGet1");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError; onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::GetPlayerStatistics(request, onSuccess, onError, testContext);
    callObj->Activate();
}
void APfTestActor::OnPlayerStatisticsApiGet1(FClientGetPlayerStatisticsResult result, UObject* customData)
{
    testMessageInt = 0;
    for (int i = 0; i < result.Statistics.Num(); i++)
        if (result.Statistics[i]->HasField(TEXT("StatisticName"))
            && result.Statistics[i]->HasField(TEXT("Value"))
            && result.Statistics[i]->GetStringField(TEXT("StatisticName")) == TEST_STAT_NAME)
            testMessageInt = result.Statistics[i]->GetNumberField(TEXT("Value"));
    testMessageInt = (testMessageInt + 1) % 100;

    FClientUpdatePlayerStatisticsRequest updateRequest;
    updateRequest.Statistics.Add(NewObject<UPlayFabJsonObject>());
    updateRequest.Statistics[0]->SetStringField(TEXT("StatisticName"), TEST_STAT_NAME);
    updateRequest.Statistics[0]->SetNumberField(TEXT("Value"), testMessageInt);
    UPlayFabClientAPI::FDelegateOnSuccessUpdatePlayerStatistics onSuccess; onSuccess.BindUFunction(this, "OnPlayerStatisticsApiUpdate");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError; onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::UpdatePlayerStatistics(updateRequest, onSuccess, onError, customData);
    callObj->Activate();
}
void APfTestActor::OnPlayerStatisticsApiUpdate(FClientUpdatePlayerStatisticsResult result, UObject* customData)
{
    FClientGetPlayerStatisticsRequest request;
    UPlayFabClientAPI::FDelegateOnSuccessGetPlayerStatistics onSuccess; onSuccess.BindUFunction(this, "OnPlayerStatisticsApiGet2");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError; onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::GetPlayerStatistics(request, onSuccess, onError, customData);
    callObj->Activate();
}
void APfTestActor::OnPlayerStatisticsApiGet2(FClientGetPlayerStatisticsResult result, UObject* customData)
{
    int actualStatValue = -1000;
    for (int i = 0; i < result.Statistics.Num(); i++)
        if (result.Statistics[i]->HasField(TEXT("StatisticName"))
            && result.Statistics[i]->HasField(TEXT("Value"))
            && result.Statistics[i]->GetStringField(TEXT("StatisticName")) == TEST_STAT_NAME)
            actualStatValue = result.Statistics[i]->GetNumberField(TEXT("Value"));

    UPfTestContext* testContext = dynamic_cast<UPfTestContext*>(customData);
    if (testMessageInt != actualStatValue)
        EndTest(testContext, PlayFabApiTestFinishState::FAILED, "User statistic not updated as expected, E:" + FString::FromInt(testMessageInt) + " != A:" + FString::FromInt(actualStatValue));
    else
        EndTest(testContext, PlayFabApiTestFinishState::PASSED, "");
}

/// <summary>
/// CLIENT API
/// Get or create the given test character for the given user
/// Parameter types tested: Contained-Classes, string
/// </summary>
void APfTestActor::UserCharacter(UPfTestContext* testContext)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    if (!playFabSettings->IsClientLoggedIn())
    {
        EndTest(testContext, PlayFabApiTestFinishState::SKIPPED, "Earlier tests failed to log in");
        return;
    }

    FClientListUsersCharactersRequest request;
    UPlayFabClientAPI::FDelegateOnSuccessGetAllUsersCharacters onSuccess; onSuccess.BindUFunction(this, "OnUserCharacter");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError; onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::GetAllUsersCharacters(request, onSuccess, onError, testContext);
    callObj->Activate();
}
void APfTestActor::OnUserCharacter(FClientListUsersCharactersResult result, UObject* customData)
{
    UPfTestContext* testContext = dynamic_cast<UPfTestContext*>(customData);
    // Generally a character won't exist
    EndTest(testContext, PlayFabApiTestFinishState::PASSED, "");
}

/// <summary>
/// CLIENT API
/// Test that leaderboard results can be requested
/// Parameter types tested: List of contained-classes
/// </summary>
void APfTestActor::LeaderBoard(UPfTestContext* testContext)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    if (!playFabSettings->IsClientLoggedIn())
    {
        EndTest(testContext, PlayFabApiTestFinishState::SKIPPED, "Earlier tests failed to log in");
        return;
    }

    testMessageInt = 0;
    FClientGetLeaderboardRequest clientRequest;
    clientRequest.StartPosition = 0;
    clientRequest.MaxResultsCount = 3;
    clientRequest.StatisticName = TEST_STAT_NAME;
    UPlayFabClientAPI::FDelegateOnSuccessGetLeaderboard onSuccess; onSuccess.BindUFunction(this, "OnLeaderBoard");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError; onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::GetLeaderboard(clientRequest, onSuccess, onError, testContext);
    callObj->Activate();
}
void APfTestActor::OnLeaderBoard(FClientGetLeaderboardResult result, UObject* customData)
{
    UPfTestContext* testContext = dynamic_cast<UPfTestContext*>(customData);
    if (result.Leaderboard.Num() > 0)
        EndTest(testContext, PlayFabApiTestFinishState::PASSED, "");
    else
        EndTest(testContext, PlayFabApiTestFinishState::FAILED, "Leaderboard entry not found.");
}

/// <summary>
/// CLIENT API
/// Test that AccountInfo can be requested
/// Parameter types tested: List of enum-as-strings converted to list of enums
/// </summary>
void APfTestActor::AccountInfo(UPfTestContext* testContext)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    if (!playFabSettings->IsClientLoggedIn())
    {
        EndTest(testContext, PlayFabApiTestFinishState::SKIPPED, "Earlier tests failed to log in");
        return;
    }

    FClientGetAccountInfoRequest request;
    UPlayFabClientAPI::FDelegateOnSuccessGetAccountInfo onSuccess; onSuccess.BindUFunction(this, "OnAccountInfo");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError; onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::GetAccountInfo(request, onSuccess, onError, testContext);
    callObj->Activate();
}
void APfTestActor::OnAccountInfo(FClientGetAccountInfoResult result, UObject* customData)
{
    UPfTestContext* testContext = dynamic_cast<UPfTestContext*>(customData);

    if (!result.AccountInfo->HasField("TitleInfo"))
    {
        EndTest(testContext, PlayFabApiTestFinishState::FAILED, "AccountInfo does not contain TitleInfo object");
        return;
    }
    auto titleInfoObj = result.AccountInfo->GetObjectField("TitleInfo");


    if (!titleInfoObj->HasField("Origination"))
    {
        EndTest(testContext, PlayFabApiTestFinishState::FAILED, "titleInfoObj does not contain Origination");
        return;
    }
    EUserOrigination originationEnum;
    FString originationStr = titleInfoObj->GetStringField("Origination");
    if (GetEnumValueFromString<EUserOrigination>(TEXT("EUserOrigination"), originationStr, originationEnum))
    {
        EndTest(testContext, PlayFabApiTestFinishState::PASSED, "");
    }
    else
    {
        EndTest(testContext, PlayFabApiTestFinishState::FAILED, "Could not resolve input as an Origination Enum value: " + originationStr);
    }
}

/// <summary>
/// CLIENT API
/// Test that CloudScript can be properly set up and invoked
/// </summary>
void APfTestActor::CloudScript(UPfTestContext* testContext)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    if (!playFabSettings->IsClientLoggedIn())
    {
        EndTest(testContext, PlayFabApiTestFinishState::SKIPPED, "Earlier tests failed to log in");
        return;
    }

    FClientExecuteCloudScriptRequest request;
    request.FunctionName = "helloWorld";
    request.FunctionParameter = nullptr;
    request.RevisionSelection = ECloudScriptRevisionOption::pfenum_Live;
    request.SpecificRevision = 0;
    UPlayFabClientAPI::FDelegateOnSuccessExecuteCloudScript onSuccess; onSuccess.BindUFunction(this, "OnHelloWorldCloudScript");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError; onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::ExecuteCloudScript(request, onSuccess, onError, testContext);
    callObj->Activate();
}
void APfTestActor::OnHelloWorldCloudScript(FClientExecuteCloudScriptResult result, UObject* customData)
{
    UPfTestContext* testContext = dynamic_cast<UPfTestContext*>(customData);

    if (!result.FunctionResult->HasField("messageValue"))
    {
        EndTest(testContext, PlayFabApiTestFinishState::FAILED, "FunctionResult did not contain messageValue");
        return;
    }
    FString message = result.FunctionResult->GetStringField("messageValue");

    FString expected = TEXT("Hello " + playFabId + "!");
    if (message.Find(expected) == -1)
        EndTest(testContext, PlayFabApiTestFinishState::FAILED, message);
    else
        EndTest(testContext, PlayFabApiTestFinishState::PASSED, "");
}

/// <summary>
/// CLIENT API
/// Test that CloudScript errors can be deciphered
/// </summary>
void APfTestActor::CloudScriptError(UPfTestContext* testContext)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    if (!playFabSettings->IsClientLoggedIn())
    {
        EndTest(testContext, PlayFabApiTestFinishState::SKIPPED, "Earlier tests failed to log in");
        return;
    }

    FClientExecuteCloudScriptRequest request;
    request.FunctionName = "throwError";
    request.FunctionParameter = nullptr;
    request.RevisionSelection = ECloudScriptRevisionOption::pfenum_Live;
    request.SpecificRevision = 0;
    UPlayFabClientAPI::FDelegateOnSuccessExecuteCloudScript onSuccess; onSuccess.BindUFunction(this, "OnCloudScriptError");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError; onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::ExecuteCloudScript(request, onSuccess, onError, testContext);
    callObj->Activate();
}
void APfTestActor::OnCloudScriptError(FClientExecuteCloudScriptResult result, UObject* customData)
{
    UPfTestContext* testContext = dynamic_cast<UPfTestContext*>(customData);

    if (result.FunctionResult != nullptr)
    {
        EndTest(testContext, PlayFabApiTestFinishState::FAILED, "FunctionResult should be null");
        return;
    }
    if (result.Error == nullptr)
    {
        EndTest(testContext, PlayFabApiTestFinishState::FAILED, "Cloud Script error not found");
        return;
    }

    if (result.Error->GetStringField(TEXT("Error")).Find("JavascriptException") == 0)
        EndTest(testContext, PlayFabApiTestFinishState::PASSED, "");
    else
        EndTest(testContext, PlayFabApiTestFinishState::FAILED, "Can't find Cloud Script failure details.");
}

/// <summary>
/// CLIENT API
/// Test that the client can publish custom PlayStream events
/// </summary>
void APfTestActor::WriteEvent(UPfTestContext* testContext)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    if (!playFabSettings->IsClientLoggedIn())
    {
        EndTest(testContext, PlayFabApiTestFinishState::SKIPPED, "Earlier tests failed to log in");
        return;
    }

    FClientWriteClientPlayerEventRequest request;
    request.EventName = "ForumPostEvent";
    request.Body = NewObject<UPlayFabJsonObject>();
    request.Body->SetStringField("Subject", "My First Post");
    request.Body->SetStringField("Body", "My awesome post.");
    UPlayFabClientAPI::FDelegateOnSuccessWritePlayerEvent onSuccess; onSuccess.BindUFunction(this, "OnWritePlayerEvent");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError; onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::WritePlayerEvent(request, onSuccess, onError, testContext);
    callObj->Activate();
}
void APfTestActor::OnWritePlayerEvent(FClientWriteEventResponse result, UObject* customData)
{
    UPfTestContext* testContext = dynamic_cast<UPfTestContext*>(customData);
    EndTest(testContext, PlayFabApiTestFinishState::PASSED, "");
}

/// <summary>
/// ENTITY API
/// Convert the ClientToken to an EntityToken
/// </summary>
void APfTestActor::GetEntityToken(UPfTestContext* testContext)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    if (!playFabSettings->IsClientLoggedIn())
    {
        EndTest(testContext, PlayFabApiTestFinishState::SKIPPED, "Earlier tests failed to log in");
        return;
    }

    FAuthenticationGetEntityTokenRequest request;
    UPlayFabAuthenticationAPI::FDelegateOnSuccessGetEntityToken onSuccess; onSuccess.BindUFunction(this, "OnGetEntityToken");
    UPlayFabAuthenticationAPI::FDelegateOnFailurePlayFabError onError; onError.BindUFunction(this, "OnSharedError");
    UPlayFabAuthenticationAPI* callObj = UPlayFabAuthenticationAPI::GetEntityToken(request, onSuccess, onError, testContext);
    callObj->Activate();
}
void APfTestActor::OnGetEntityToken(FAuthenticationGetEntityTokenResponse result, UObject* customData)
{
    entityId = result.Entity->GetStringField("Id");
    entityType = result.Entity->GetStringField("Type");

    UPfTestContext* testContext = dynamic_cast<UPfTestContext*>(customData);
    EndTest(testContext, PlayFabApiTestFinishState::PASSED, "");
}

/// <summary>
/// ENTITY API
/// Save and load an Entity object
/// </summary>
void APfTestActor::ObjectApi(UPfTestContext* testContext)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    if (!playFabSettings->IsClientLoggedIn())
    {
        EndTest(testContext, PlayFabApiTestFinishState::SKIPPED, "Earlier tests failed to log in");
        return;
    }

    FDataGetObjectsRequest request;
    request.Entity = NewObject<UPlayFabJsonObject>();
    request.Entity->SetStringField("Id", entityId);
    request.Entity->SetStringField("Type", entityType);
    request.EscapeObject = true;

    UPlayFabDataAPI::FDelegateOnSuccessGetObjects onSuccess; onSuccess.BindUFunction(this, "OnGetObjectApi1");
    UPlayFabDataAPI::FDelegateOnFailurePlayFabError onError; onError.BindUFunction(this, "OnSharedError");
    UPlayFabDataAPI* callObj = UPlayFabDataAPI::GetObjects(request, onSuccess, onError, testContext);
    callObj->Activate();
}
void APfTestActor::OnGetObjectApi1(FDataGetObjectsResponse result, UObject* customData)
{
    testMessageInt = 0; // Default if the data isn't present
    if (result.Objects->HasField(TEST_DATA_KEY)) {
        auto eachObjString = result.Objects->GetObjectField(TEST_DATA_KEY)->GetStringField("EscapedDataObject");
        testMessageInt = FCString::Atoi(*eachObjString);
    }
    testMessageInt = (testMessageInt + 1) % 100; // This test is about the Expected value changing - but not testing more complicated issues like bounds

    FDataSetObjectsRequest request;
    request.Entity = NewObject<UPlayFabJsonObject>();
    request.Entity->SetStringField("Id", entityId);
    request.Entity->SetStringField("Type", entityType);

    auto saveObj = NewObject<UPlayFabJsonObject>();
    saveObj->SetStringField(TEXT("ObjectName"), TEST_DATA_KEY);
    saveObj->SetNumberField(TEXT("DataObject"), testMessageInt);
    request.Objects.Add(saveObj);

    UPlayFabDataAPI::FDelegateOnSuccessSetObjects onSuccess; onSuccess.BindUFunction(this, "OnSetObjectApi");
    UPlayFabDataAPI::FDelegateOnFailurePlayFabError onError; onError.BindUFunction(this, "OnSharedError");
    UPlayFabDataAPI* callObj = UPlayFabDataAPI::SetObjects(request, onSuccess, onError, customData);
    callObj->Activate();
}
void APfTestActor::OnSetObjectApi(FDataSetObjectsResponse result, UObject* customData)
{
    FDataGetObjectsRequest request;
    request.Entity = NewObject<UPlayFabJsonObject>();
    request.Entity->SetStringField("Id", entityId);
    request.Entity->SetStringField("Type", entityType);
    request.EscapeObject = true;

    UPlayFabDataAPI::FDelegateOnSuccessGetObjects onSuccess; onSuccess.BindUFunction(this, "OnGetObjectApi2");
    UPlayFabDataAPI::FDelegateOnFailurePlayFabError onError; onError.BindUFunction(this, "OnSharedError");
    UPlayFabDataAPI* callObj = UPlayFabDataAPI::GetObjects(request, onSuccess, onError, customData);
    callObj->Activate();
}
void APfTestActor::OnGetObjectApi2(FDataGetObjectsResponse result, UObject* customData)
{
    UPfTestContext* testContext = dynamic_cast<UPfTestContext*>(customData);

    int actualValue = -1000; // Fail if the data isn't present
    if (result.Objects->HasField(TEST_DATA_KEY)) {
        auto eachObjString = result.Objects->GetObjectField(TEST_DATA_KEY)->GetStringField("EscapedDataObject");
        actualValue = FCString::Atoi(*eachObjString);
    }

    // Verify output and end test
    if (testMessageInt != actualValue)
        EndTest(testContext, PlayFabApiTestFinishState::FAILED, FString::Printf(TEXT("Saved/Loaded Object Data did not match: %d != %d"), testMessageInt, actualValue));
    else
        EndTest(testContext, PlayFabApiTestFinishState::PASSED, "");
}

/// <summary>
/// SERVER API
/// Test that leaderboard results can be requested
/// Parameter types tested: List of contained-classes
/// </summary>
void APfTestActor::ServerTitleData(UPfTestContext* testContext)
{
    testMessageInt = 0;
    FServerGetTitleDataRequest request;
    UPlayFabServerAPI::FDelegateOnSuccessGetTitleData onSuccess; onSuccess.BindUFunction(this, "OnServerTitleData");
    UPlayFabServerAPI::FDelegateOnFailurePlayFabError onError; onError.BindUFunction(this, "OnSharedError");
    UPlayFabServerAPI* callObj = UPlayFabServerAPI::GetTitleData(request, onSuccess, onError, testContext);
    callObj->Activate();
}
void APfTestActor::OnServerTitleData(FServerGetTitleDataResult result, UObject* customData)
{
    UPfTestContext* testContext = dynamic_cast<UPfTestContext*>(customData);
    // There is no guarantee about content in titleData, so as long as this request succeeds, test passes
    EndTest(testContext, PlayFabApiTestFinishState::PASSED, "");
}

