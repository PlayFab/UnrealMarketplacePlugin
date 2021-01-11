//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "Tests/PlayFabBlueprintTests.h"
#include "TestFramework/PlayFabTestContext.h"

#include "IPlayFab.h"
#include "PlayFabClientApi.h"
#include "PlayFabAuthenticationApi.h"
#include "PlayFabDataApi.h"
#include "PlayFabServerApi.h"
#include "TestFramework/PlayFabTestRunner.h"

void UPlayFabBlueprintTests::SetTestTitleData(const UTestTitleDataLoader& testTitleData)
{
    UserEmail = testTitleData.userEmail;
}

void UPlayFabBlueprintTests::ClassSetUp()
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    playFabSettings->setAdvertisingIdType(TEXT(""));
    playFabSettings->setAdvertisingIdValue(TEXT(""));
}


/// <summary>
/// CLIENT API
/// Try to deliberately log in with an inappropriate password,
///   and verify that the error displays as expected.
/// </summary>
void UPlayFabBlueprintTests::InvalidLogin(UPlayFabTestContext* testContext)
{
    FClientLoginWithEmailAddressRequest request;
    request.Email = UserEmail;
    request.Password = "INVALID";
    request.InfoRequestParameters = nullptr;

    UPlayFabClientAPI::FDelegateOnSuccessLoginWithEmailAddress onSuccess;
    onSuccess.BindUFunction(this, "InvalidLoginSuccess");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError;
    onError.BindUFunction(this, "InvalidLoginFail");

    UPlayFabClientAPI* callObj = UPlayFabClientAPI::LoginWithEmailAddress(request, onSuccess, onError, testContext);
    callObj->Activate();
}

void UPlayFabBlueprintTests::InvalidLoginSuccess(FClientLoginResult result, UObject* customData)
{
    UPlayFabTestContext* testContext = static_cast<UPlayFabTestContext*>(customData);
    testContext->EndTest(PlayFabApiTestFinishState::FAILED, "Expected login to fail");
}

void UPlayFabBlueprintTests::InvalidLoginFail(FPlayFabError error, UObject* customData)
{
    UPlayFabTestContext* testContext = static_cast<UPlayFabTestContext*>(customData);
    if (error.ErrorMessage.Find("password") != -1)
        testContext->EndTest(PlayFabApiTestFinishState::PASSED, "");
    else
        testContext->EndTest(PlayFabApiTestFinishState::FAILED, "Password error message not found: " + error.ErrorMessage + "\n - " + error.ErrorDetails);
}

/// <summary>
/// CLIENT API
/// Try to deliberately register a user with an invalid email and password
///   Verify that errorDetails are populated correctly.
/// </summary>
void UPlayFabBlueprintTests::InvalidRegistration(UPlayFabTestContext* testContext)
{
    FClientRegisterPlayFabUserRequest request;
    request.Username = "x";
    request.Email = "x";
    request.Password = "x";
    UPlayFabClientAPI::FDelegateOnSuccessRegisterPlayFabUser onSuccess;
    onSuccess.BindUFunction(this, "InvalidRegistrationSuccess");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError;
    onError.BindUFunction(this, "InvalidRegistrationFail");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::RegisterPlayFabUser(request, onSuccess, onError, testContext);
    callObj->Activate();
}

void UPlayFabBlueprintTests::InvalidRegistrationSuccess(FClientRegisterPlayFabUserResult result, UObject* customData)
{
    UPlayFabTestContext* testContext = static_cast<UPlayFabTestContext*>(customData);
    testContext->EndTest(PlayFabApiTestFinishState::FAILED, "Expected registration to fail");
}

void UPlayFabBlueprintTests::InvalidRegistrationFail(FPlayFabError error, UObject* customData)
{
    bool foundEmailMsg, foundPasswordMsg;
    FString expectedEmailMsg = "Email address is not valid.";
    FString expectedPasswordMsg = "Password must be between";

    foundEmailMsg = (error.ErrorDetails.Find(expectedEmailMsg) != -1);
    foundPasswordMsg = (error.ErrorDetails.Find(expectedPasswordMsg) != -1);

    UPlayFabTestContext* testContext = static_cast<UPlayFabTestContext*>(customData);
    if (foundEmailMsg && foundPasswordMsg)
        testContext->EndTest(PlayFabApiTestFinishState::PASSED, "");
    else
        testContext->EndTest(PlayFabApiTestFinishState::FAILED, "All error details: " + error.ErrorDetails);
}

/// <summary>
/// CLIENT API
/// Test a sequence of calls that modifies saved data,
///   and verifies that the next sequential API call contains updated data.
/// Verify that the data is correctly modified on the next call.
/// Parameter types tested: string, Dictionary<string, string>, DateTime
/// </summary>
void UPlayFabBlueprintTests::LoginOrRegister(UPlayFabTestContext* testContext)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());

    FClientLoginWithCustomIDRequest request;
    request.CustomId = playFabSettings->getBuildIdentifier();
    request.CreateAccount = true;
    request.InfoRequestParameters = nullptr;
    UPlayFabClientAPI::FDelegateOnSuccessLoginWithCustomID onSuccess;
    onSuccess.BindUFunction(this, "OnLoginOrRegister");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError;
    onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::LoginWithCustomID(request, onSuccess, onError, testContext);
    callObj->Activate();
}

void UPlayFabBlueprintTests::OnLoginOrRegister(FClientLoginResult result, UObject* customData)
{
    PlayFabId = result.PlayFabId;
    UPlayFabTestContext* testContext = static_cast<UPlayFabTestContext*>(customData);
    testContext->EndTest(PlayFabApiTestFinishState::PASSED, "");
}

/// <summary>
/// CLIENT API
/// Test that the login call sequence sends the AdvertisingId when set
/// </summary>
void UPlayFabBlueprintTests::LoginWithAdvertisingId(UPlayFabTestContext* testContext)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    playFabSettings->setAdvertisingIdType(playFabSettings->getAD_TYPE_ANDROID_ID());
    playFabSettings->setAdvertisingIdValue(TEXT("PlayFabTestId"));

    FClientLoginWithCustomIDRequest request;
    request.CustomId = playFabSettings->getBuildIdentifier();
    request.CreateAccount = true;
    request.InfoRequestParameters = nullptr;
    UPlayFabClientAPI::FDelegateOnSuccessLoginWithCustomID onSuccess;
    onSuccess.BindUFunction(this, "OnLoginWithAdvertisingId");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError;
    onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::LoginWithCustomID(request, onSuccess, onError, testContext);
    callObj->Activate();
}

void UPlayFabBlueprintTests::OnLoginWithAdvertisingId(FClientLoginResult result, UObject* customData)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    // TODO: Need to wait for the NEXT api call to complete, and then test playFabSettings->AdvertisingIdType (Oh right... need to actually change AdvertisingIdType too...
    UPlayFabTestContext* testContext = static_cast<UPlayFabTestContext*>(customData);
    testContext->EndTest(PlayFabApiTestFinishState::PASSED, "");
}

/// <summary>
/// CLIENT API
/// Test a sequence of calls that modifies saved data,
///   and verifies that the next sequential API call contains updated data.
/// Verify that the data is correctly modified on the next call.
/// Parameter types tested: string, Dictionary<string, string>, DateTime
/// </summary>
void UPlayFabBlueprintTests::UserDataApi(UPlayFabTestContext* testContext)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    if (!playFabSettings->IsClientLoggedIn())
    {
        testContext->EndTest(PlayFabApiTestFinishState::SKIPPED, "Earlier tests failed to log in");
        return;
    }

    FClientGetUserDataRequest request;
    request.IfChangedFromDataVersion = 0;
    UPlayFabClientAPI::FDelegateOnSuccessGetUserData onSuccess;
    onSuccess.BindUFunction(this, "OnUserDataApiGet1");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError;
    onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::GetUserData(request, onSuccess, onError, testContext);
    callObj->Activate();
}

void UPlayFabBlueprintTests::OnUserDataApiGet1(FClientGetUserDataResult result, UObject* customData)
{
    TryExtractIntFromUserData(result.Data, TEST_DATA_KEY, testMessageInt, testMessageTime); // We don't care about failure here, because it's legitimate if the data doesn't exist yet
    testMessageInt = (testMessageInt + 1) % 100;

    FClientUpdateUserDataRequest updateRequest;
    updateRequest.Data = NewObject<UPlayFabJsonObject>(); // This will be GC'd almost immediately since there's no living UPROPERTY references to it (updateRequest doesn't count), but that's ok, because it only needs to survive until UPlayFabClientAPI::UpdateUserData returns
    updateRequest.Data->SetStringField(TEST_DATA_KEY, FString::FromInt(testMessageInt));
    updateRequest.Permission = EUserDataPermission::pfenum_Public;
    UPlayFabClientAPI::FDelegateOnSuccessUpdateUserData onSuccess;
    onSuccess.BindUFunction(this, "OnUserDataApiUpdate");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError;
    onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::UpdateUserData(updateRequest, onSuccess, onError, customData);
    callObj->Activate();
}

void UPlayFabBlueprintTests::OnUserDataApiUpdate(FClientUpdateUserDataResult result, UObject* customData)
{
    FClientGetUserDataRequest request;
    request.IfChangedFromDataVersion = 0;
    UPlayFabClientAPI::FDelegateOnSuccessGetUserData onSuccess;
    onSuccess.BindUFunction(this, "OnUserDataApiGet2");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError;
    onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::GetUserData(request, onSuccess, onError, customData);
    callObj->Activate();
}

void UPlayFabBlueprintTests::OnUserDataApiGet2(FClientGetUserDataResult result, UObject* customData)
{
    UPlayFabTestContext* testContext = static_cast<UPlayFabTestContext*>(customData);

    FDateTime now = FDateTime::UtcNow();
    FDateTime minTime = now - FTimespan(0, 5, 0);
    FDateTime maxTime = now + FTimespan(0, 5, 0);

    int actualDataValue;
    bool exists = TryExtractIntFromUserData(result.Data, TEST_DATA_KEY, actualDataValue, testMessageTime);
    if (!exists)
        testContext->EndTest(PlayFabApiTestFinishState::FAILED, "Expected data is not present.");
    else if (testMessageInt != actualDataValue)
        testContext->EndTest(PlayFabApiTestFinishState::FAILED, "User data not updated as expected.");
    else if (testMessageTime < minTime || maxTime < testMessageTime)
        testContext->EndTest(PlayFabApiTestFinishState::FAILED, "Timestamp out of range: " + minTime.ToString() + "!<" + testMessageTime.ToString() + "!<" + maxTime.ToString());
    else if (!(minTime <= testMessageTime && testMessageTime <= maxTime))
        testContext->EndTest(PlayFabApiTestFinishState::FAILED, "DateTime not parsed correctly.");
    else
        testContext->EndTest(PlayFabApiTestFinishState::PASSED, "");
}

bool UPlayFabBlueprintTests::TryExtractIntFromUserData(const UPlayFabJsonObject* jsonObj, const FString& key, int& outValue, FDateTime& outTime)
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
void UPlayFabBlueprintTests::PlayerStatisticsApi(UPlayFabTestContext* testContext)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    if (!playFabSettings->IsClientLoggedIn())
    {
        testContext->EndTest(PlayFabApiTestFinishState::SKIPPED, "Earlier tests failed to log in");
        return;
    }

    FClientGetPlayerStatisticsRequest request;
    UPlayFabClientAPI::FDelegateOnSuccessGetPlayerStatistics onSuccess;
    onSuccess.BindUFunction(this, "OnPlayerStatisticsApiGet1");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError;
    onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::GetPlayerStatistics(request, onSuccess, onError, testContext);
    callObj->Activate();
}

void UPlayFabBlueprintTests::OnPlayerStatisticsApiGet1(FClientGetPlayerStatisticsResult result, UObject* customData)
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
    UPlayFabClientAPI::FDelegateOnSuccessUpdatePlayerStatistics onSuccess;
    onSuccess.BindUFunction(this, "OnPlayerStatisticsApiUpdate");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError;
    onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::UpdatePlayerStatistics(updateRequest, onSuccess, onError, customData);
    callObj->Activate();
}

void UPlayFabBlueprintTests::OnPlayerStatisticsApiUpdate(FClientUpdatePlayerStatisticsResult result, UObject* customData)
{
    FClientGetPlayerStatisticsRequest request;
    UPlayFabClientAPI::FDelegateOnSuccessGetPlayerStatistics onSuccess;
    onSuccess.BindUFunction(this, "OnPlayerStatisticsApiGet2");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError;
    onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::GetPlayerStatistics(request, onSuccess, onError, customData);
    callObj->Activate();
}

void UPlayFabBlueprintTests::OnPlayerStatisticsApiGet2(FClientGetPlayerStatisticsResult result, UObject* customData)
{
    int actualStatValue = -1000;
    for (int i = 0; i < result.Statistics.Num(); i++)
        if (result.Statistics[i]->HasField(TEXT("StatisticName"))
            && result.Statistics[i]->HasField(TEXT("Value"))
            && result.Statistics[i]->GetStringField(TEXT("StatisticName")) == TEST_STAT_NAME)
            actualStatValue = result.Statistics[i]->GetNumberField(TEXT("Value"));

    UPlayFabTestContext* testContext = static_cast<UPlayFabTestContext*>(customData);
    if (testMessageInt != actualStatValue)
        testContext->EndTest(PlayFabApiTestFinishState::FAILED, "User statistic not updated as expected, E:" + FString::FromInt(testMessageInt) + " != A:" + FString::FromInt(actualStatValue));
    else
        testContext->EndTest(PlayFabApiTestFinishState::PASSED, "");
}

/// <summary>
/// CLIENT API
/// Test that leaderboard results can be requested
/// Parameter types tested: List of contained-classes
/// </summary>
void UPlayFabBlueprintTests::LeaderBoard(UPlayFabTestContext* testContext)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    if (!playFabSettings->IsClientLoggedIn())
    {
        testContext->EndTest(PlayFabApiTestFinishState::SKIPPED, "Earlier tests failed to log in");
        return;
    }

    testMessageInt = 0;
    FClientGetLeaderboardRequest clientRequest;
    clientRequest.StartPosition = 0;
    clientRequest.MaxResultsCount = 3;
    clientRequest.StatisticName = TEST_STAT_NAME;
    UPlayFabClientAPI::FDelegateOnSuccessGetLeaderboard onSuccess;
    onSuccess.BindUFunction(this, "OnLeaderBoard");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError;
    onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::GetLeaderboard(clientRequest, onSuccess, onError, testContext);
    callObj->Activate();
}

void UPlayFabBlueprintTests::OnLeaderBoard(FClientGetLeaderboardResult result, UObject* customData)
{
    UPlayFabTestContext* testContext = static_cast<UPlayFabTestContext*>(customData);
    if (result.Leaderboard.Num() > 0)
        testContext->EndTest(PlayFabApiTestFinishState::PASSED, "");
    else
        testContext->EndTest(PlayFabApiTestFinishState::FAILED, "Leaderboard entry not found.");
}

/// <summary>
/// CLIENT API
/// Test that AccountInfo can be requested
/// Parameter types tested: List of enum-as-strings converted to list of enums
/// </summary>
void UPlayFabBlueprintTests::AccountInfo(UPlayFabTestContext* testContext)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    if (!playFabSettings->IsClientLoggedIn())
    {
        testContext->EndTest(PlayFabApiTestFinishState::SKIPPED, "Earlier tests failed to log in");
        return;
    }

    FClientGetAccountInfoRequest request;
    UPlayFabClientAPI::FDelegateOnSuccessGetAccountInfo onSuccess;
    onSuccess.BindUFunction(this, "OnAccountInfo");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError;
    onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::GetAccountInfo(request, onSuccess, onError, testContext);
    callObj->Activate();
}

void UPlayFabBlueprintTests::OnAccountInfo(FClientGetAccountInfoResult result, UObject* customData)
{
    UPlayFabTestContext* testContext = static_cast<UPlayFabTestContext*>(customData);

    if (!result.AccountInfo->HasField("TitleInfo"))
    {
        testContext->EndTest(PlayFabApiTestFinishState::FAILED, "AccountInfo does not contain TitleInfo object");
        return;
    }
    auto titleInfoObj = result.AccountInfo->GetObjectField("TitleInfo");


    if (!titleInfoObj->HasField("Origination"))
    {
        testContext->EndTest(PlayFabApiTestFinishState::FAILED, "titleInfoObj does not contain Origination");
        return;
    }
    EUserOrigination originationEnum;
    FString originationStr = titleInfoObj->GetStringField("Origination");
    if (GetEnumValueFromString<EUserOrigination>(TEXT("EUserOrigination"), originationStr, originationEnum))
    {
        testContext->EndTest(PlayFabApiTestFinishState::PASSED, "");
    }
    else
    {
        testContext->EndTest(PlayFabApiTestFinishState::FAILED, "Could not resolve input as an Origination Enum value: " + originationStr);
    }
}

/// <summary>
/// CLIENT API
/// Test that CloudScript can be properly set up and invoked
/// </summary>
void UPlayFabBlueprintTests::CloudScript(UPlayFabTestContext* testContext)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    if (!playFabSettings->IsClientLoggedIn())
    {
        testContext->EndTest(PlayFabApiTestFinishState::SKIPPED, "Earlier tests failed to log in");
        return;
    }

    FClientExecuteCloudScriptRequest request;
    request.FunctionName = "helloWorld";
    request.FunctionParameter = nullptr;
    request.RevisionSelection = ECloudScriptRevisionOption::pfenum_Live;
    request.SpecificRevision = 0;
    UPlayFabClientAPI::FDelegateOnSuccessExecuteCloudScript onSuccess;
    onSuccess.BindUFunction(this, "OnHelloWorldCloudScript");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError;
    onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::ExecuteCloudScript(request, onSuccess, onError, testContext);
    callObj->Activate();
}

void UPlayFabBlueprintTests::OnHelloWorldCloudScript(FClientExecuteCloudScriptResult result, UObject* customData)
{
    UPlayFabTestContext* testContext = static_cast<UPlayFabTestContext*>(customData);

    if (!result.FunctionResult->HasField("messageValue"))
    {
        testContext->EndTest(PlayFabApiTestFinishState::FAILED, "FunctionResult did not contain messageValue");
        return;
    }
    FString message = result.FunctionResult->GetStringField("messageValue");

    FString expected = TEXT("Hello " + PlayFabId + "!");
    if (message.Find(expected) == -1)
        testContext->EndTest(PlayFabApiTestFinishState::FAILED, message);
    else
        testContext->EndTest(PlayFabApiTestFinishState::PASSED, "");
}

/// <summary>
/// CLIENT API
/// Test that CloudScript errors can be deciphered
/// </summary>
void UPlayFabBlueprintTests::CloudScriptError(UPlayFabTestContext* testContext)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    if (!playFabSettings->IsClientLoggedIn())
    {
        testContext->EndTest(PlayFabApiTestFinishState::SKIPPED, "Earlier tests failed to log in");
        return;
    }

    FClientExecuteCloudScriptRequest request;
    request.FunctionName = "throwError";
    request.FunctionParameter = nullptr;
    request.RevisionSelection = ECloudScriptRevisionOption::pfenum_Live;
    request.SpecificRevision = 0;
    UPlayFabClientAPI::FDelegateOnSuccessExecuteCloudScript onSuccess;
    onSuccess.BindUFunction(this, "OnCloudScriptError");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError;
    onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::ExecuteCloudScript(request, onSuccess, onError, testContext);
    callObj->Activate();
}

void UPlayFabBlueprintTests::OnCloudScriptError(FClientExecuteCloudScriptResult result, UObject* customData)
{
    UPlayFabTestContext* testContext = static_cast<UPlayFabTestContext*>(customData);

    if (result.FunctionResult != nullptr)
    {
        testContext->EndTest(PlayFabApiTestFinishState::FAILED, "FunctionResult should be null");
        return;
    }
    if (result.Error == nullptr)
    {
        testContext->EndTest(PlayFabApiTestFinishState::FAILED, "Cloud Script error not found");
        return;
    }

    if (result.Error->GetStringField(TEXT("Error")).Find("JavascriptException") == 0)
        testContext->EndTest(PlayFabApiTestFinishState::PASSED, "");
    else
        testContext->EndTest(PlayFabApiTestFinishState::FAILED, "Can't find Cloud Script failure details.");
}

/// <summary>
/// CLIENT API
/// Test that the client can publish custom PlayStream events
/// </summary>
void UPlayFabBlueprintTests::WriteEvent(UPlayFabTestContext* testContext)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    if (!playFabSettings->IsClientLoggedIn())
    {
        testContext->EndTest(PlayFabApiTestFinishState::SKIPPED, "Earlier tests failed to log in");
        return;
    }

    FClientWriteClientPlayerEventRequest request;
    request.EventName = "ForumPostEvent";
    request.Body = NewObject<UPlayFabJsonObject>();
    request.Body->SetStringField("Subject", "My First Post");
    request.Body->SetStringField("Body", "My awesome post.");
    UPlayFabClientAPI::FDelegateOnSuccessWritePlayerEvent onSuccess;
    onSuccess.BindUFunction(this, "OnWritePlayerEvent");
    UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError;
    onError.BindUFunction(this, "OnSharedError");
    UPlayFabClientAPI* callObj = UPlayFabClientAPI::WritePlayerEvent(request, onSuccess, onError, testContext);
    callObj->Activate();
}

void UPlayFabBlueprintTests::OnWritePlayerEvent(FClientWriteEventResponse result, UObject* customData)
{
    UPlayFabTestContext* testContext = static_cast<UPlayFabTestContext*>(customData);
    testContext->EndTest(PlayFabApiTestFinishState::PASSED, "");
}


/// <summary>
/// ENTITY API
/// Convert the ClientToken to an EntityToken
/// </summary>
void UPlayFabBlueprintTests::GetEntityToken(UPlayFabTestContext* testContext)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    if (!playFabSettings->IsClientLoggedIn())
    {
        testContext->EndTest(PlayFabApiTestFinishState::SKIPPED, "Earlier tests failed to log in");
        return;
    }

    FAuthenticationGetEntityTokenRequest request;
    UPlayFabAuthenticationAPI::FDelegateOnSuccessGetEntityToken onSuccess;
    onSuccess.BindUFunction(this, "OnGetEntityToken");
    UPlayFabAuthenticationAPI::FDelegateOnFailurePlayFabError onError;
    onError.BindUFunction(this, "OnSharedError");
    UPlayFabAuthenticationAPI* callObj = UPlayFabAuthenticationAPI::GetEntityToken(request, onSuccess, onError, testContext);
    callObj->Activate();
}

void UPlayFabBlueprintTests::OnGetEntityToken(FAuthenticationGetEntityTokenResponse result, UObject* customData)
{
    entityId = result.Entity->GetStringField("Id");
    entityType = result.Entity->GetStringField("Type");

    UPlayFabTestContext* testContext = static_cast<UPlayFabTestContext*>(customData);
    testContext->EndTest(PlayFabApiTestFinishState::PASSED, "");
}

/// <summary>
/// ENTITY API
/// Save and load an Entity object
/// </summary>
void UPlayFabBlueprintTests::ObjectApi(UPlayFabTestContext* testContext)
{
    IPlayFab* playFabSettings = &(IPlayFab::Get());
    if (!playFabSettings->IsClientLoggedIn())
    {
        testContext->EndTest(PlayFabApiTestFinishState::SKIPPED, "Earlier tests failed to log in");
        return;
    }

    FDataGetObjectsRequest request;
    request.Entity = NewObject<UPlayFabJsonObject>();
    request.Entity->SetStringField("Id", entityId);
    request.Entity->SetStringField("Type", entityType);
    request.EscapeObject = true;

    UPlayFabDataAPI::FDelegateOnSuccessGetObjects onSuccess;
    onSuccess.BindUFunction(this, "OnGetObjectApi1");
    UPlayFabDataAPI::FDelegateOnFailurePlayFabError onError;
    onError.BindUFunction(this, "OnSharedError");
    UPlayFabDataAPI* callObj = UPlayFabDataAPI::GetObjects(request, onSuccess, onError, testContext);
    callObj->Activate();
}

void UPlayFabBlueprintTests::OnGetObjectApi1(FDataGetObjectsResponse result, UObject* customData)
{
    testMessageInt = 0; // Default if the data isn't present
    if (result.Objects->HasField(TEST_DATA_KEY))
    {
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

    UPlayFabDataAPI::FDelegateOnSuccessSetObjects onSuccess;
    onSuccess.BindUFunction(this, "OnSetObjectApi");
    UPlayFabDataAPI::FDelegateOnFailurePlayFabError onError;
    onError.BindUFunction(this, "OnSharedError");
    UPlayFabDataAPI* callObj = UPlayFabDataAPI::SetObjects(request, onSuccess, onError, customData);
    callObj->Activate();
}

void UPlayFabBlueprintTests::OnSetObjectApi(FDataSetObjectsResponse result, UObject* customData)
{
    FDataGetObjectsRequest request;
    request.Entity = NewObject<UPlayFabJsonObject>();
    request.Entity->SetStringField("Id", entityId);
    request.Entity->SetStringField("Type", entityType);
    request.EscapeObject = true;

    UPlayFabDataAPI::FDelegateOnSuccessGetObjects onSuccess;
    onSuccess.BindUFunction(this, "OnGetObjectApi2");
    UPlayFabDataAPI::FDelegateOnFailurePlayFabError onError;
    onError.BindUFunction(this, "OnSharedError");
    UPlayFabDataAPI* callObj = UPlayFabDataAPI::GetObjects(request, onSuccess, onError, customData);
    callObj->Activate();
}

void UPlayFabBlueprintTests::OnGetObjectApi2(FDataGetObjectsResponse result, UObject* customData)
{
    UPlayFabTestContext* testContext = static_cast<UPlayFabTestContext*>(customData);

    int actualValue = -1000; // Fail if the data isn't present
    if (result.Objects->HasField(TEST_DATA_KEY))
    {
        auto eachObjString = result.Objects->GetObjectField(TEST_DATA_KEY)->GetStringField("EscapedDataObject");
        actualValue = FCString::Atoi(*eachObjString);
    }

    // Verify output and end test
    if (testMessageInt != actualValue)
        testContext->EndTest(PlayFabApiTestFinishState::FAILED, FString::Printf(TEXT("Saved/Loaded Object Data did not match: %d != %d"), testMessageInt, actualValue));
    else
        testContext->EndTest(PlayFabApiTestFinishState::PASSED, "");
}


/// <summary>
/// SERVER API
/// Test that leaderboard results can be requested
/// Parameter types tested: List of contained-classes
/// </summary>
void UPlayFabBlueprintTests::ServerTitleData(UPlayFabTestContext* testContext)
{
    testMessageInt = 0;
    FServerGetTitleDataRequest request;
    UPlayFabServerAPI::FDelegateOnSuccessGetTitleData onSuccess;
    onSuccess.BindUFunction(this, "OnServerTitleData");
    UPlayFabServerAPI::FDelegateOnFailurePlayFabError onError;
    onError.BindUFunction(this, "OnSharedError");
    UPlayFabServerAPI* callObj = UPlayFabServerAPI::GetTitleData(request, onSuccess, onError, testContext);
    callObj->Activate();
}

void UPlayFabBlueprintTests::OnServerTitleData(FServerGetTitleDataResult result, UObject* customData)
{
    UPlayFabTestContext* testContext = static_cast<UPlayFabTestContext*>(customData);
    // There is no guarantee about content in titleData, so as long as this request succeeds, test passes
    testContext->EndTest(PlayFabApiTestFinishState::PASSED, "");
}
