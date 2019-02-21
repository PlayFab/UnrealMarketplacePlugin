//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////

#include "ExampleProject.h"
#include "PlayFabApiTests.h"
#include "PlayFabError.h"
#include "IPlayFab.h"

// This is a separate project from the PlayFab plugin, so this has to be re-defined in this project - This is not standard, but these tests should log as playfab, even from another project
DEFINE_LOG_CATEGORY(LogPlayFabTest);

/*
* ==== Test Suite ====
*/
FString PlayFabApiTestSuite::playFabId;
FString PlayFabApiTestSuite::entityId;
FString PlayFabApiTestSuite::entityType;

/*
* ==== LoginWithEmailAddress ====
*/
PlayFabApiTest_0LoginWithEmail::PlayFabApiTest_0LoginWithEmail(const FString& email, const FString& password)
{
    this->email = email;
    this->password = password;
}

bool PlayFabApiTest_0LoginWithEmail::Update()
{
    // Initialize, setup the call, and wait for the result
    if (!clientAPI.IsValid())
    {
        clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

        PlayFab::ClientModels::FLoginWithEmailAddressRequest request;
        request.Email = email;
        request.Password = password;

        clientAPI->LoginWithEmailAddress(request
            , PlayFab::UPlayFabClientAPI::FLoginWithEmailAddressDelegate::CreateRaw(this, &PlayFabApiTest_0LoginWithEmail::OnSuccess)
            , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_0LoginWithEmail::OnError)
        );
    }

    // Return when the api call is resolved
    return clientAPI->GetPendingCalls() == 0;
}

void PlayFabApiTest_0LoginWithEmail::OnSuccess(const PlayFab::ClientModels::FLoginResult& result) const
{
    UE_LOG(LogPlayFabTest, Error, TEXT("LoginWithEmailAddress Succeeded where it should have failed"));
}

void PlayFabApiTest_0LoginWithEmail::OnError(const PlayFab::FPlayFabCppError& ErrorResult) const
{
    if (ErrorResult.ErrorMessage.Find(TEXT("password")) == -1) // Check that we correctly received a notice about invalid password
    {
        UE_LOG(LogPlayFabTest, Error, TEXT("Non-password error with login"));
    }
}



/*
* ==== LoginWithCustomID ====
*/
PlayFabApiTest_0LoginWithCustomID::PlayFabApiTest_0LoginWithCustomID(const FString& customId)
{
    this->customId = customId;
}

bool PlayFabApiTest_0LoginWithCustomID::Update()
{
    // Initialize, setup the call, and wait for the result
    if (!clientAPI.IsValid())
    {
        clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

        PlayFab::ClientModels::FLoginWithCustomIDRequest request;
        request.CustomId = customId;
        request.CreateAccount = true;

        clientAPI->LoginWithCustomID(request
            , PlayFab::UPlayFabClientAPI::FLoginWithCustomIDDelegate::CreateRaw(this, &PlayFabApiTest_0LoginWithCustomID::OnSuccess)
            , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_0LoginWithCustomID::OnError)
        );
    }

    // Return when the api call is resolved
    return clientAPI->GetPendingCalls() == 0;
}

void PlayFabApiTest_0LoginWithCustomID::OnSuccess(const PlayFab::ClientModels::FLoginResult& result) const
{
    PlayFabApiTestSuite::playFabId = result.PlayFabId;
    UE_LOG(LogPlayFabTest, Log, TEXT("PlayFab login successful: %s, %s"), *PlayFabApiTestSuite::playFabId, *customId);
}

void PlayFabApiTest_0LoginWithCustomID::OnError(const PlayFab::FPlayFabCppError& ErrorResult) const
{
    UE_LOG(LogPlayFabTest, Error, TEXT("Login failed"));
}


/*
* ==== LoginWithAdvertisingId ====
*/
PlayFabApiTest_0LoginWithAdvertisingId::PlayFabApiTest_0LoginWithAdvertisingId(const FString& customId)
{
    this->tickCounter = 0;
    this->customId = customId;
}

bool PlayFabApiTest_0LoginWithAdvertisingId::Update()
{
    if (!clientAPI.IsValid())
    {
        clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
        clientAPI->SetAdvertId(TEXT("Adid"), TEXT("PlayFabTestId"));

        PlayFab::ClientModels::FLoginWithCustomIDRequest request;
        request.CustomId = customId;
        request.CreateAccount = true;

        clientAPI->LoginWithCustomID(request
            , PlayFab::UPlayFabClientAPI::FLoginWithCustomIDDelegate::CreateRaw(this, &PlayFabApiTest_0LoginWithAdvertisingId::OnSuccess)
            , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_0LoginWithAdvertisingId::OnError)
        );
    }

    tickCounter += 1;
    bool success = clientAPI->AdvertIdSuccessful();
    bool failure = tickCounter > 300 && !success;
    if (failure)
        UE_LOG(LogPlayFabTest, Error, TEXT("advertisingId not submitted properly"));

    // Return when the api call is resolved
    return clientAPI->GetPendingCalls() == 0 && (failure || success);
}

void PlayFabApiTest_0LoginWithAdvertisingId::OnSuccess(const PlayFab::ClientModels::FLoginResult& result) const
{
    PlayFabApiTestSuite::playFabId = result.PlayFabId;
    UE_LOG(LogPlayFabTest, Log, TEXT("PlayFab login successful: %s, %s"), *PlayFabApiTestSuite::playFabId, *customId);
}

void PlayFabApiTest_0LoginWithAdvertisingId::OnError(const PlayFab::FPlayFabCppError& ErrorResult) const
{
    UE_LOG(LogPlayFabTest, Error, TEXT("LoginWithAdvertisingId Failed: %s"), *(ErrorResult.ErrorMessage));
}


/*
* ==== GetUserData ====
*/
PlayFabApiTest_GetUserData::PlayFabApiTest_GetUserData(const FString& TEST_DATA_KEY_1, const FString& TEST_DATA_KEY_2, int expectedValue = -1)
{
    this->TEST_DATA_KEY_1 = TEST_DATA_KEY_1;
    this->TEST_DATA_KEY_2 = TEST_DATA_KEY_2;

    this->expectedValue = expectedValue;
}

bool PlayFabApiTest_GetUserData::Update()
{
    // Initialize, setup the call, and wait for the result
    if (!clientAPI.IsValid())
    {
        clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

        PlayFab::ClientModels::FGetUserDataRequest request;

        clientAPI->GetUserData(request
            , PlayFab::UPlayFabClientAPI::FGetUserDataDelegate::CreateRaw(this, &PlayFabApiTest_GetUserData::OnSuccess)
            , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_GetUserData::OnError)
        );
    }

    // Return when the api call is resolved
    return clientAPI->GetPendingCalls() == 0;
}

void PlayFabApiTest_GetUserData::OnSuccess(const PlayFab::ClientModels::FGetUserDataResult& result) const
{
    int actualValue = -1;

    const PlayFab::ClientModels::FUserDataRecord* target = result.Data.Find(TEST_DATA_KEY_1);
    if (target != nullptr)
        actualValue = FCString::Atoi(*(target->Value));

    if (expectedValue != -1 && expectedValue != actualValue)
    {
        // If I know what value I'm expecting, and I did not get it, log an error
        UE_LOG(LogPlayFabTest, Error, TEXT("GetUserData: Update value did not match new value %d!=%d"), expectedValue, actualValue);
    }
    else if (expectedValue != -1 && expectedValue == actualValue)
    {
        // If I know what value I'm expecting, and I got it, test passed, exit
        CheckTimestamp(target->LastUpdated); // If the value was updated correctly, check the timestamp
        UE_LOG(LogPlayFabTest, Log, TEXT("GetUserData Success"));
    }
    else if (expectedValue == -1)
    {
        // If I don't know what value I was expecting, Call Update with (actualValue + 1)
        actualValue = (actualValue + 1) % 100;
        ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_UpdateUserData(TEST_DATA_KEY_1, TEST_DATA_KEY_2, actualValue));
    }
}

void PlayFabApiTest_GetUserData::CheckTimestamp(const FDateTime& updateTime) const
{
    FDateTime utcNow = FDateTime::UtcNow();
    FTimespan delta = FTimespan(0, 5, 0);
    FDateTime minTest = utcNow - delta;
    FDateTime maxTest = utcNow + delta;

    if (minTest <= updateTime && updateTime <= maxTest)
    {
        UE_LOG(LogPlayFabTest, Log, TEXT("GetUserData: LastUpdated timestamp parsed as expected"));
    }
    else
    {
        UE_LOG(LogPlayFabTest, Error, TEXT("GetUserData: LastUpdated timestamp was not parsed correctly"));
    }
}

void PlayFabApiTest_GetUserData::OnError(const PlayFab::FPlayFabCppError& ErrorResult) const
{
    UE_LOG(LogPlayFabTest, Error, TEXT("GetUserData Failed: %s"), *(ErrorResult.ErrorMessage));
}

/*
* ==== UpdateUserData ====
*/
PlayFabApiTest_UpdateUserData::PlayFabApiTest_UpdateUserData(const FString& TEST_DATA_KEY_1, const FString& TEST_DATA_KEY_2, int updateValue)
{
    this->TEST_DATA_KEY_1 = TEST_DATA_KEY_1;
    this->TEST_DATA_KEY_2 = TEST_DATA_KEY_2;

    this->updateValue = updateValue;
}

bool PlayFabApiTest_UpdateUserData::Update()
{
    // Initialize, setup the call, and wait for the result
    if (!clientAPI.IsValid())
    {
        clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

        FString strUpdateValue;
        strUpdateValue.AppendInt(updateValue);

        PlayFab::ClientModels::FUpdateUserDataRequest request;
        request.Data.Add(TEST_DATA_KEY_1, strUpdateValue);

        clientAPI->UpdateUserData(request
            , PlayFab::UPlayFabClientAPI::FUpdateUserDataDelegate::CreateRaw(this, &PlayFabApiTest_UpdateUserData::OnSuccess)
            , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_UpdateUserData::OnError)
        );
    }

    // Return when the api call is resolved
    return clientAPI->GetPendingCalls() == 0;
}

void PlayFabApiTest_UpdateUserData::OnSuccess(const PlayFab::ClientModels::FUpdateUserDataResult& result) const
{
    // Update is always followed by another get w/ verification
    ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_GetUserData(TEST_DATA_KEY_1, TEST_DATA_KEY_2, updateValue));
}

void PlayFabApiTest_UpdateUserData::OnError(const PlayFab::FPlayFabCppError& ErrorResult) const
{
    UE_LOG(LogPlayFabTest, Error, TEXT("UpdateUserData Failed: %s"), *(ErrorResult.ErrorMessage));
}

/*
* ==== GetPlayerStatistics ====
*/
PlayFabApiTest_GetPlayerStatistics::PlayFabApiTest_GetPlayerStatistics(const FString& TEST_STAT_NAME, int expectedValue = -1)
{
    this->TEST_STAT_NAME = TEST_STAT_NAME;

    this->expectedValue = expectedValue;
}

bool PlayFabApiTest_GetPlayerStatistics::Update()
{
    // Initialize, setup the call, and wait for the result
    if (!clientAPI.IsValid())
    {
        clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

        PlayFab::ClientModels::FGetPlayerStatisticsRequest request;
        clientAPI->GetPlayerStatistics(
            request,
            PlayFab::UPlayFabClientAPI::FGetPlayerStatisticsDelegate::CreateRaw(this, &PlayFabApiTest_GetPlayerStatistics::OnSuccess)
            , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_GetPlayerStatistics::OnError)
        );
    }

    // Return when the api call is resolved
    return clientAPI->GetPendingCalls() == 0;
}

void PlayFabApiTest_GetPlayerStatistics::OnSuccess(const PlayFab::ClientModels::FGetPlayerStatisticsResult& result) const
{
    int actualValue = -1000;
    for (int i = 0; i < result.Statistics.Num(); i++)
        if (result.Statistics[i].StatisticName == TEST_STAT_NAME)
            actualValue = result.Statistics[i].Value;

    if (expectedValue != -1 && expectedValue != actualValue)
    {
        UE_LOG(LogPlayFabTest, Error, TEXT("GetPlayerStatistics: Update value did not match new value"));
    }
    else if (expectedValue != -1 && expectedValue == actualValue)
    {
        UE_LOG(LogPlayFabTest, Log, TEXT("GetPlayerStatistics Success"));
    }
    else if (expectedValue == -1)
    {
        // Call Update with (actualValue + 1)
        actualValue = (actualValue + 1) % 100;
        ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_UpdatePlayerStatistics(TEST_STAT_NAME, actualValue));
    }
}

void PlayFabApiTest_GetPlayerStatistics::OnError(const PlayFab::FPlayFabCppError& ErrorResult) const
{
    UE_LOG(LogPlayFabTest, Error, TEXT("GetPlayerStatistics Failed: %s"), *(ErrorResult.ErrorMessage));
}

/*
* ==== UpdatePlayerStatistics ====
*/
PlayFabApiTest_UpdatePlayerStatistics::PlayFabApiTest_UpdatePlayerStatistics(const FString& TEST_STAT_NAME, int updateValue)
{
    this->TEST_STAT_NAME = TEST_STAT_NAME;

    this->updateValue = updateValue;
}

bool PlayFabApiTest_UpdatePlayerStatistics::Update()
{
    // Initialize, setup the call, and wait for the result
    if (!clientAPI.IsValid())
    {
        clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

        PlayFab::ClientModels::FUpdatePlayerStatisticsRequest request;
        PlayFab::ClientModels::FStatisticUpdate statUpdate;
        statUpdate.StatisticName = TEST_STAT_NAME;
        statUpdate.Value = updateValue;
        request.Statistics.Add(statUpdate);

        clientAPI->UpdatePlayerStatistics(request
            , PlayFab::UPlayFabClientAPI::FUpdatePlayerStatisticsDelegate::CreateRaw(this, &PlayFabApiTest_UpdatePlayerStatistics::OnSuccess)
            , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_UpdatePlayerStatistics::OnError)
        );
    }

    // Return when the api call is resolved
    return clientAPI->GetPendingCalls() == 0;
}

void PlayFabApiTest_UpdatePlayerStatistics::OnSuccess(const PlayFab::ClientModels::FUpdatePlayerStatisticsResult& result) const
{
    // Update is always followed by another get w/ verification
    ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_GetPlayerStatistics(TEST_STAT_NAME, updateValue));
}

void PlayFabApiTest_UpdatePlayerStatistics::OnError(const PlayFab::FPlayFabCppError& ErrorResult) const
{
    UE_LOG(LogPlayFabTest, Error, TEXT("UpdatePlayerStatistics Failed: %s"), *(ErrorResult.ErrorMessage));
}

/*
* ==== GetAllUsersCharacters ====
*/
PlayFabApiTest_GetAllUsersCharacters::PlayFabApiTest_GetAllUsersCharacters()
{
}

bool PlayFabApiTest_GetAllUsersCharacters::Update()
{
    // Initialize, setup the call, and wait for the result
    if (!clientAPI.IsValid())
    {
        clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

        PlayFab::ClientModels::FListUsersCharactersRequest request;

        clientAPI->GetAllUsersCharacters(request
            , PlayFab::UPlayFabClientAPI::FGetAllUsersCharactersDelegate::CreateRaw(this, &PlayFabApiTest_GetAllUsersCharacters::OnSuccess)
            , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_GetAllUsersCharacters::OnError)
        );
    }

    // Return when the api call is resolved
    return clientAPI->GetPendingCalls() == 0;
}

void PlayFabApiTest_GetAllUsersCharacters::OnSuccess(const PlayFab::ClientModels::FListUsersCharactersResult& result) const
{
    UE_LOG(LogPlayFabTest, Log, TEXT("GetAllUsersCharacters Success (Can't fail)"));
}

void PlayFabApiTest_GetAllUsersCharacters::OnError(const PlayFab::FPlayFabCppError& ErrorResult) const
{
    UE_LOG(LogPlayFabTest, Error, TEXT("GetAllUsersCharacters Failed: %s"), *(ErrorResult.ErrorMessage));
}

/*
* ==== GetLeaderboard Client ====
*/
PlayFabApiTest_GetLeaderboardC::PlayFabApiTest_GetLeaderboardC(const FString& TEST_STAT_NAME)
{
    this->TEST_STAT_NAME = TEST_STAT_NAME;
}

bool PlayFabApiTest_GetLeaderboardC::Update()
{
    // Initialize, setup the call, and wait for the result
    if (!clientAPI.IsValid())
    {
        clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

        PlayFab::ClientModels::FGetLeaderboardRequest request;
        request.MaxResultsCount = 3;
        request.StatisticName = TEST_STAT_NAME;

        clientAPI->GetLeaderboard(request
            , PlayFab::UPlayFabClientAPI::FGetLeaderboardDelegate::CreateRaw(this, &PlayFabApiTest_GetLeaderboardC::OnSuccess)
            , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_GetLeaderboardC::OnError)
        );
    }

    // Return when the api call is resolved
    return clientAPI->GetPendingCalls() == 0;
}

void PlayFabApiTest_GetLeaderboardC::OnSuccess(const PlayFab::ClientModels::FGetLeaderboardResult& result) const
{
    int count = result.Leaderboard.Num();

    if (count > 0)
    {
        UE_LOG(LogPlayFabTest, Log, TEXT("GetLeaderboard Succeeded"));
    }
    else
    {
        UE_LOG(LogPlayFabTest, Error, TEXT("GetLeaderboard found zero results."));
    }
}

void PlayFabApiTest_GetLeaderboardC::OnError(const PlayFab::FPlayFabCppError& ErrorResult) const
{
    UE_LOG(LogPlayFabTest, Error, TEXT("GetLeaderboard Failed: %s"), *(ErrorResult.ErrorMessage));
}

/*
* ==== GetLeaderboard Server ====
*/
PlayFabApiTest_GetLeaderboardS::PlayFabApiTest_GetLeaderboardS(const FString& TEST_STAT_NAME)
{
    this->TEST_STAT_NAME = TEST_STAT_NAME;
}

bool PlayFabApiTest_GetLeaderboardS::Update()
{
    // Initialize, setup the call, and wait for the result
    if (!serverAPI.IsValid())
    {
        serverAPI = IPlayFabModuleInterface::Get().GetServerAPI();

        PlayFab::ServerModels::FGetLeaderboardRequest request;
        request.MaxResultsCount = 3;
        request.StatisticName = TEST_STAT_NAME;

        serverAPI->GetLeaderboard(request
            , PlayFab::UPlayFabServerAPI::FGetLeaderboardDelegate::CreateRaw(this, &PlayFabApiTest_GetLeaderboardS::OnSuccess)
            , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_GetLeaderboardS::OnError)
        );
    }

    // Return when the api call is resolved
    return serverAPI->GetPendingCalls() == 0;
}

void PlayFabApiTest_GetLeaderboardS::OnSuccess(const PlayFab::ServerModels::FGetLeaderboardResult& result) const
{
    int count = result.Leaderboard.Num();

    if (count > 0)
    {
        UE_LOG(LogPlayFabTest, Log, TEXT("GetLeaderboard Succeeded"));
    }
    else
    {
        UE_LOG(LogPlayFabTest, Error, TEXT("GetLeaderboard found zero results."));
    }
}

void PlayFabApiTest_GetLeaderboardS::OnError(const PlayFab::FPlayFabCppError& ErrorResult) const
{
    UE_LOG(LogPlayFabTest, Error, TEXT("GetLeaderboard Failed: %s"), *(ErrorResult.ErrorMessage));
}

/*
* ==== GetAccountInfo ====
*/
PlayFabApiTest_GetAccountInfo::PlayFabApiTest_GetAccountInfo()
{
}

bool PlayFabApiTest_GetAccountInfo::Update()
{
    // Initialize, setup the call, and wait for the result
    if (!clientAPI.IsValid())
    {
        clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

        PlayFab::ClientModels::FGetAccountInfoRequest request;

        clientAPI->GetAccountInfo(request
            , PlayFab::UPlayFabClientAPI::FGetAccountInfoDelegate::CreateRaw(this, &PlayFabApiTest_GetAccountInfo::OnSuccess)
            , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_GetAccountInfo::OnError)
        );
    }

    // Return when the api call is resolved
    return clientAPI->GetPendingCalls() == 0;
}

void PlayFabApiTest_GetAccountInfo::OnSuccess(const PlayFab::ClientModels::FGetAccountInfoResult& result) const
{
    auto origination = result.AccountInfo->TitleInfo->Origination.mValue; // C++ can't really do anything with this once fetched
    UE_LOG(LogPlayFabTest, Log, TEXT("GetAccountInfo Succeeded"));
}

void PlayFabApiTest_GetAccountInfo::OnError(const PlayFab::FPlayFabCppError& ErrorResult) const
{
    UE_LOG(LogPlayFabTest, Error, TEXT("GetAccountInfo Failed: %s"), *(ErrorResult.ErrorMessage));
}


/*
* ==== ExecuteCloudScript ====
*/
PlayFabApiTest_ExecuteCloudScript::PlayFabApiTest_ExecuteCloudScript(const FString& functionName, bool expectFail)
{
    this->functionName = functionName;
    this->expectFail = expectFail;
}

bool PlayFabApiTest_ExecuteCloudScript::Update()
{
    // Initialize, setup the call, and wait for the result
    if (!clientAPI.IsValid())
    {
        clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

        PlayFab::ClientModels::FExecuteCloudScriptRequest request;
        request.FunctionName = functionName;

        clientAPI->ExecuteCloudScript(request
            , PlayFab::UPlayFabClientAPI::FExecuteCloudScriptDelegate::CreateRaw(this, &PlayFabApiTest_ExecuteCloudScript::OnSuccess)
            , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_ExecuteCloudScript::OnError)
        );
    }

    // Return when the api call is resolved
    return clientAPI->GetPendingCalls() == 0;
}

void PlayFabApiTest_ExecuteCloudScript::OnSuccess(const PlayFab::ClientModels::FExecuteCloudScriptResult& result) const
{
    if (!expectFail == result.Error.IsValid()) {
        UE_LOG(LogPlayFabTest, Error, TEXT("ExecuteCloudScript succeeded when it should have failed"));
    }
    else {
        UE_LOG(LogPlayFabTest, Log, TEXT("ExecuteCloudScript Succeeded"));
    }
}

void PlayFabApiTest_ExecuteCloudScript::OnError(const PlayFab::FPlayFabCppError& ErrorResult) const
{
    if (expectFail) {
        UE_LOG(LogPlayFabTest, Log, TEXT("ExecuteCloudScript failed as expected"));
    }
    else {
        UE_LOG(LogPlayFabTest, Error, TEXT("ExecuteCloudScript Failed: %s"), *(ErrorResult.ErrorMessage));
    }
}


/*
* ==== WriteEvent ====
*/
PlayFabApiTest_WriteEvent::PlayFabApiTest_WriteEvent()
{
}

bool PlayFabApiTest_WriteEvent::Update()
{
    // Initialize, setup the call, and wait for the result
    if (!clientAPI.IsValid())
    {
        clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

        PlayFab::ClientModels::FWriteClientPlayerEventRequest request;
        request.EventName = TEXT("ForumPostEvent");
        request.Body.Add(TEXT("Subject"), TEXT("My First Post"));
        request.Body.Add(TEXT("Body"), TEXT("My awesome Post."));

        clientAPI->WritePlayerEvent(request
            , PlayFab::UPlayFabClientAPI::FWritePlayerEventDelegate::CreateRaw(this, &PlayFabApiTest_WriteEvent::OnSuccess)
            , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_WriteEvent::OnError)
        );
    }

    // Return when the api call is resolved
    return clientAPI->GetPendingCalls() == 0;
}

void PlayFabApiTest_WriteEvent::OnSuccess(const PlayFab::ClientModels::FWriteEventResponse& result) const
{
    UE_LOG(LogPlayFabTest, Log, TEXT("WriteEvent Succeeded"));
}

void PlayFabApiTest_WriteEvent::OnError(const PlayFab::FPlayFabCppError& ErrorResult) const
{
    UE_LOG(LogPlayFabTest, Error, TEXT("WriteEvent Failed: %s"), *(ErrorResult.ErrorMessage));
}


/*
* ==== GetEntityToken ====
*/
PlayFabApiTest_GetEntityToken::PlayFabApiTest_GetEntityToken()
{
}

bool PlayFabApiTest_GetEntityToken::Update()
{
    // Initialize, setup the call, and wait for the result
    if (!authenticationAPI.IsValid())
    {
        authenticationAPI = IPlayFabModuleInterface::Get().GetAuthenticationAPI();

        PlayFab::AuthenticationModels::FGetEntityTokenRequest request;
        authenticationAPI->GetEntityToken(
            request,
            PlayFab::UPlayFabAuthenticationAPI::FGetEntityTokenDelegate::CreateRaw(this, &PlayFabApiTest_GetEntityToken::OnSuccess)
            , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_GetEntityToken::OnError)
        );
    }

    // Return when the api call is resolved
    return authenticationAPI->GetPendingCalls() == 0;
}

void PlayFabApiTest_GetEntityToken::OnSuccess(const PlayFab::AuthenticationModels::FGetEntityTokenResponse& result) const
{
    PlayFabApiTestSuite::entityId = result.Entity->Id;
    PlayFabApiTestSuite::entityType = result.Entity->Type;
    UE_LOG(LogPlayFabTest, Log, TEXT("GetEntityToken Succeeded"));
}

void PlayFabApiTest_GetEntityToken::OnError(const PlayFab::FPlayFabCppError& ErrorResult) const
{
    UE_LOG(LogPlayFabTest, Error, TEXT("GetEntityToken Failed: %s"), *(ErrorResult.ErrorMessage));
}


/*
* ==== ObjectApi ====
*/
PlayFabApiTest_ObjectApi::PlayFabApiTest_ObjectApi()
{
}

bool PlayFabApiTest_ObjectApi::Update()
{
    // Initialize, setup the call, and wait for the result
    if (!dataAPI.IsValid())
    {
        dataAPI = IPlayFabModuleInterface::Get().GetDataAPI();

        PlayFab::DataModels::FGetObjectsRequest request;
        request.Entity.Id = PlayFabApiTestSuite::entityId;
        request.Entity.Type = PlayFabApiTestSuite::entityType;
        request.EscapeObject = true;

        dataAPI->GetObjects(request
            , PlayFab::UPlayFabDataAPI::FGetObjectsDelegate::CreateRaw(this, &PlayFabApiTest_ObjectApi::OnSuccess)
            , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_ObjectApi::OnError)
        );
    }

    // Return when the api call is resolved
    return dataAPI->GetPendingCalls() == 0;
}

void PlayFabApiTest_ObjectApi::OnSuccess(const PlayFab::DataModels::FGetObjectsResponse& result) const
{
    UE_LOG(LogPlayFabTest, Log, TEXT("ObjectApi Succeeded"));
}

void PlayFabApiTest_ObjectApi::OnError(const PlayFab::FPlayFabCppError& ErrorResult) const
{
    UE_LOG(LogPlayFabTest, Error, TEXT("ObjectApi Failed: %s"), *(ErrorResult.ErrorMessage));
}

/*
* ==== Multiple Users ====
*/
PlayFabApiTest_MultipleUsers::PlayFabApiTest_MultipleUsers()
{
}

bool PlayFabApiTest_MultipleUsers::Update()
{
    // Initialize, setup the call, and wait for the result
    if (!clientAPI.IsValid())
    {
        clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

        // Cache the static login credentials. We will be clearing these in order to test the multi-user functionality
        //  that circumvents them, but other tests depend on these being set so we need to clean up after ourselves
        //  TODO: Update test framework with a setup/teardown for each test that handles this, so that tests don't depend on each other's side effects
        cachedClientSessionTicket = IPlayFabCommonModuleInterface::Get().GetClientSessionTicket();
        cachedEntityToken = IPlayFabCommonModuleInterface::Get().GetEntityToken();
        cachedDeveloperSecretKey = IPlayFabCommonModuleInterface::Get().GetDeveloperSecretKey();

        // Log In User 1
        PlayFab::ClientModels::FLoginWithCustomIDRequest user1LoginRequest{};
        user1LoginRequest.CustomId = TEXT("UE4MultiUserCpp_1");
        user1LoginRequest.CreateAccount = true;
        clientAPI->LoginWithCustomID(user1LoginRequest
            , PlayFab::UPlayFabClientAPI::FLoginWithCustomIDDelegate::CreateRaw(this, &PlayFabApiTest_MultipleUsers::OnUser1LoginSuccess)
            , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_MultipleUsers::OnError)
        );

        // Log In User 2
        PlayFab::ClientModels::FLoginWithCustomIDRequest user2LoginRequest{};
        user2LoginRequest.CustomId = TEXT("UE4MultiUserCpp_2");
        user2LoginRequest.CreateAccount = true;
        clientAPI->LoginWithCustomID(user2LoginRequest
            , PlayFab::UPlayFabClientAPI::FLoginWithCustomIDDelegate::CreateRaw(this, &PlayFabApiTest_MultipleUsers::OnUser2LoginSuccess)
            , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_MultipleUsers::OnError)
        );
    }

    // Return when the api call is resolved
    return clientAPI->GetPendingCalls() == 0;
}

void PlayFabApiTest_MultipleUsers::OnUser1LoginSuccess(const PlayFab::ClientModels::FLoginResult& result)
{
    UE_LOG(LogPlayFabTest, Log, TEXT("MultipleUsers: User 1 logged in"));
    user1LoginResult = result;
    if (user2LoginResult.EntityToken.IsValid())
        OnBothUsersLoggedIn();
}

void PlayFabApiTest_MultipleUsers::OnUser2LoginSuccess(const PlayFab::ClientModels::FLoginResult& result)
{
    UE_LOG(LogPlayFabTest, Log, TEXT("MultipleUsers: User 2 logged in"));
    user2LoginResult = result;
    if (user1LoginResult.EntityToken.IsValid())
        OnBothUsersLoggedIn();
}

void PlayFabApiTest_MultipleUsers::OnBothUsersLoggedIn()
{
    // Ensure that classic credentials (global, statically stored) aren't used:
    IPlayFabCommonModuleInterface::Get().SetClientSessionTicket(TEXT(""));
    IPlayFabCommonModuleInterface::Get().SetEntityToken(TEXT(""));
    IPlayFabCommonModuleInterface::Get().SetDeveloperSecretKey(TEXT(""));

    // Get User 1 Profile
    PlayFab::ClientModels::FGetPlayerProfileRequest user1ProfileRequest{};
    user1ProfileRequest.AuthenticationContext = user1LoginResult.AuthenticationContext;
    clientAPI->GetPlayerProfile(user1ProfileRequest
        , PlayFab::UPlayFabClientAPI::FGetPlayerProfileDelegate::CreateRaw(this, &PlayFabApiTest_MultipleUsers::OnUser1GetProfileSuccess)
        , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_MultipleUsers::OnError)
    );

    // Get User 2 Profile
    PlayFab::ClientModels::FGetPlayerProfileRequest user2ProfileRequest{};
    user2ProfileRequest.AuthenticationContext = user2LoginResult.AuthenticationContext;
    clientAPI->GetPlayerProfile(user2ProfileRequest
        , PlayFab::UPlayFabClientAPI::FGetPlayerProfileDelegate::CreateRaw(this, &PlayFabApiTest_MultipleUsers::OnUser2GetProfileSuccess)
        , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_MultipleUsers::OnError)
    );
}

void PlayFabApiTest_MultipleUsers::OnUser1GetProfileSuccess(const PlayFab::ClientModels::FGetPlayerProfileResult& result)
{
    UE_LOG(LogPlayFabTest, Log, TEXT("MultipleUsers: Got User 1 Profile with player ID %s"), *result.PlayerProfile->PlayerId);

    user1ProfileResult = result;
    if (user2ProfileResult.PlayerProfile.IsValid())
        OnBothUsersGetProfile();
}

void PlayFabApiTest_MultipleUsers::OnUser2GetProfileSuccess(const PlayFab::ClientModels::FGetPlayerProfileResult& result)
{
    RestoreCachedStaticCredentials();
    UE_LOG(LogPlayFabTest, Log, TEXT("MultipleUsers: Got User 2 Profile with player ID %s"), *result.PlayerProfile->PlayerId);

    user2ProfileResult = result;
    if (user1ProfileResult.PlayerProfile.IsValid())
        OnBothUsersGetProfile();
}

void PlayFabApiTest_MultipleUsers::OnBothUsersGetProfile()
{
    if (user1LoginResult.PlayFabId != user1ProfileResult.PlayerProfile->PlayerId) {
        UE_LOG(LogPlayFabTest, Error, TEXT("MultipleUsers failed: IDs from User 1's LoginResult (%s) and GetPlayerProfileResult (%s) don't match"), *user1LoginResult.PlayFabId, *user1ProfileResult.PlayerProfile->PlayerId);
        return;
    }
    if (user2LoginResult.PlayFabId != user2ProfileResult.PlayerProfile->PlayerId) {
        UE_LOG(LogPlayFabTest, Error, TEXT("MultipleUsers failed: IDs from User 2's LoginResult (%s) and GetPlayerProfileResult (%s) don't match"), *user2LoginResult.PlayFabId, *user2ProfileResult.PlayerProfile->PlayerId);
        return;
    }

    UE_LOG(LogPlayFabTest, Log, TEXT("MultipleUsers Succeeded"));
}

void PlayFabApiTest_MultipleUsers::OnError(const PlayFab::FPlayFabCppError& ErrorResult)
{
    RestoreCachedStaticCredentials();
    UE_LOG(LogPlayFabTest, Error, TEXT("MultipleUsers failed: %s"), *(ErrorResult.ErrorMessage));
}

/**
 *  Restore the static credentials originally set by LoginOrRegister but wiped in this test, as other tests depend on them
 *  TODO: Update test framework with a setup/teardown for each test that handles this, so that tests don't depend on each other's side effects
 */
void PlayFabApiTest_MultipleUsers::RestoreCachedStaticCredentials()
{
    IPlayFabCommonModuleInterface::Get().SetClientSessionTicket(cachedClientSessionTicket);
    IPlayFabCommonModuleInterface::Get().SetEntityToken(cachedEntityToken);
    IPlayFabCommonModuleInterface::Get().SetDeveloperSecretKey(cachedDeveloperSecretKey);
}