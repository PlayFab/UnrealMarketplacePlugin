//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "GameFramework/Actor.h"

#include "PlayFabClientModels.h"
#include "PlayFabClientApi.h"

#include "PlayFabAuthenticationModels.h"
#include "PlayFabAuthenticationApi.h"
#include "PlayFabDataModels.h"
#include "PlayFabDataApi.h"

#include "PlayFabServerModels.h"
#include "PlayFabServerApi.h"

#include "PfTestActor.generated.h"

UENUM(BlueprintType)
enum class PlayFabApiTestActiveState : uint8
{
    PENDING UMETA(DisplayName = "PENDING"), // Not started
    ACTIVE UMETA(DisplayName = "ACTIVE"), // Currently testing
    READY UMETA(DisplayName = "READY"), // An answer is sent by the http thread, but the main thread hasn't finalized the test yet
    COMPLETE UMETA(DisplayName = "COMPLETE"), // Test is finalized and recorded
    ABORTED UMETA(DisplayName = "ABORTED"), // todo
};

UENUM(BlueprintType)
enum class PlayFabApiTestFinishState : uint8
{
    PASSED UMETA(DisplayName = "PASSED"),
    FAILED UMETA(DisplayName = "FAILED"),
    SKIPPED UMETA(DisplayName = "SKIPPED"),
    TIMEDOUT UMETA(DisplayName = "TIMEDOUT"),
};

UCLASS(Blueprintable, BlueprintType)
class UPfTestContext : public UObject
{
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_DELEGATE_OneParam(FApiTestCase, UPfTestContext*, error);

    UPROPERTY()
        FString testName;
    UPROPERTY()
        PlayFabApiTestActiveState activeState;
    UPROPERTY()
        PlayFabApiTestFinishState finishState;
    UPROPERTY()
        FString testResultMsg;
    UPROPERTY()
        FApiTestCase testFunc;
    UPROPERTY()
        FDateTime startTime;
    UPROPERTY()
        FDateTime endTime;

    UFUNCTION()
        void Setup(FString name, FApiTestCase func)
    {
        testName = name;
        activeState = PlayFabApiTestActiveState::PENDING;
        finishState = PlayFabApiTestFinishState::TIMEDOUT;
        testResultMsg = "";
        testFunc = func;
        startTime = 0;
        endTime = 0;
    };

    UFUNCTION()
        FString GenerateTestSummary(FDateTime now)
    {
        FDateTime tempEndTime = (activeState == PlayFabApiTestActiveState::COMPLETE) ? endTime : now;
        FDateTime tempStartTime = (startTime != 0) ? startTime : now;

        FString temp;
        temp = FString::FromInt((tempEndTime - tempStartTime).GetTotalMilliseconds());
        while (temp.Len() < 12)
            temp = " " + temp;
        temp += " ms, ";
        switch (finishState)
        {
        case PlayFabApiTestFinishState::PASSED: temp += "pass: "; break;
        case PlayFabApiTestFinishState::FAILED: temp += "FAILED: "; break;
        case PlayFabApiTestFinishState::SKIPPED: temp += "SKIPPED: "; break;
        case PlayFabApiTestFinishState::TIMEDOUT: temp += "TIMED OUT: "; break;
        }
        temp += testName;
        if (testResultMsg.Len() > 0)
        {
            temp += " - ";
            temp += testResultMsg;
        }
        return temp;
    }
};

UCLASS()
class APfTestActor : public AActor
{
    GENERATED_BODY()

public:
    ///////////////////// Actor stuff /////////////////////
    APfTestActor(); // Sets default values for this actor's properties
    virtual void BeginPlay() override; // Called when the game starts or when spawned
    virtual void Tick(float DeltaSeconds) override; // Called every frame

    ///////////////////// API-test stuff /////////////////////

    /* The active test summary */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = PfTestSummary)
        FString _outputSummary;
    // A bunch of constants: load these from testTitleData.json
    UPROPERTY()
        FString TEST_TITLE_DATA_LOC = "testTitleData.json";
    UPROPERTY()
        FString userEmail;
    UPROPERTY()
        FString TEST_DATA_KEY = "testCounter";
    UPROPERTY()
        FString TEST_STAT_NAME = "str";
    UPROPERTY()
        FString playFabId;
    UPROPERTY()
        FString entityId;
    UPROPERTY()
        FString entityType;
    UPROPERTY()
        FDateTime testMessageTime;
    UPROPERTY()
        TArray<UPfTestContext*> testContexts;
    int testMessageInt;

    UFUNCTION()
        void InitializeTestSuite();
    UFUNCTION()
        void AppendTest(const FString& testFuncName);
    UFUNCTION()
        bool TickTestSuite();
    UFUNCTION()
        FString GenerateTestSummary();

    UFUNCTION()
        bool ClassSetup();
    // Start a test, and block until the threaded response arrives
    UFUNCTION()
        void StartTest(UPfTestContext* testContext);
    UFUNCTION()
        void TickTest(UPfTestContext* testContext);
    // This should be called in the api-responses, which are threaded.  This will allow TickTest to finalize the test
    UFUNCTION()
        void EndTest(UPfTestContext* testContext, PlayFabApiTestFinishState finishState, FString resultMsg);

    UFUNCTION()
        void OnSharedError(FPlayFabError error, UObject* customData);

    /// <summary>
    /// CLIENT API
    /// Try to deliberately log in with an inappropriate password,
    ///   and verify that the error displays as expected.
    /// </summary>
    UFUNCTION()
        void InvalidLogin(UPfTestContext* testContext);
    UFUNCTION()
        void InvalidLoginSuccess(FClientLoginResult result, UObject* customData);
    UFUNCTION()
        void InvalidLoginFail(FPlayFabError error, UObject* customData);

    /// <summary>
    /// CLIENT API
    /// Try to deliberately register a user with an invalid email and password
    ///   Verify that errorDetails are populated correctly.
    /// </summary>
    UFUNCTION()
        void InvalidRegistration(UPfTestContext* testContext);
    UFUNCTION()
        void InvalidRegistrationSuccess(FClientRegisterPlayFabUserResult result, UObject* customData);
    UFUNCTION()
        void InvalidRegistrationFail(FPlayFabError error, UObject* customData);

    /// <summary>
    /// CLIENT API
    /// Test a sequence of calls that modifies saved data,
    ///   and verifies that the next sequential API call contains updated data.
    /// Verify that the data is correctly modified on the next call.
    /// Parameter types tested: string, Dictionary<string, string>, DateTime
    /// </summary>
    UFUNCTION()
        void LoginOrRegister(UPfTestContext* testContext);
    UFUNCTION()
        void OnLoginOrRegister(FClientLoginResult result, UObject* customData);

    /// <summary>
    /// CLIENT API
    /// Test that the login call sequence sends the AdvertisingId when set
    /// </summary>
    UFUNCTION()
        void LoginWithAdvertisingId(UPfTestContext* testContext);
    UFUNCTION()
        void OnLoginWithAdvertisingId(FClientLoginResult result, UObject* customData);

    /// <summary>
    /// CLIENT API
    /// Test a sequence of calls that modifies saved data,
    ///   and verifies that the next sequential API call contains updated data.
    /// Verify that the data is correctly modified on the next call.
    /// Parameter types tested: string, Dictionary<string, string>, DateTime
    /// </summary>
    UFUNCTION()
        void UserDataApi(UPfTestContext* testContext);
    UFUNCTION()
        void OnUserDataApiGet1(FClientGetUserDataResult result, UObject* customData);
    UFUNCTION()
        void OnUserDataApiUpdate(FClientUpdateUserDataResult result, UObject* customData);
    UFUNCTION()
        void OnUserDataApiGet2(FClientGetUserDataResult result, UObject* customData);
    bool TryExtractIntFromUserData(const UPlayFabJsonObject* jsonObj, const FString& key, int& outValue, FDateTime& outTime);

    /// <summary>
    /// CLIENT API
    /// Test a sequence of calls that modifies saved data,
    ///   and verifies that the next sequential API call contains updated data.
    /// Verify that the data is saved correctly, and that specific types are tested
    /// Parameter types tested: Dictionary<string, int>
    /// </summary>
    UFUNCTION()
        void PlayerStatisticsApi(UPfTestContext* testContext);
    UFUNCTION()
        void OnPlayerStatisticsApiGet1(FClientGetPlayerStatisticsResult result, UObject* customData);
    UFUNCTION()
        void OnPlayerStatisticsApiUpdate(FClientUpdatePlayerStatisticsResult result, UObject* customData);
    UFUNCTION()
        void OnPlayerStatisticsApiGet2(FClientGetPlayerStatisticsResult result, UObject* customData);

    /// <summary>
    /// CLIENT API
    /// Get or create the given test character for the given user
    /// Parameter types tested: Contained-Classes, string
    /// </summary>
    UFUNCTION()
        void UserCharacter(UPfTestContext* testContext);
    UFUNCTION()
        void OnUserCharacter(FClientListUsersCharactersResult result, UObject* customData);

    /// <summary>
    /// CLIENT API
    /// Test that leaderboard results can be requested
    /// Parameter types tested: List of contained-classes
    /// </summary>
    UFUNCTION()
        void LeaderBoard(UPfTestContext* testContext);
    UFUNCTION()
        void OnLeaderBoard(FClientGetLeaderboardResult result, UObject* customData);

    /// <summary>
    /// CLIENT API
    /// Test that AccountInfo can be requested
    /// Parameter types tested: List of enum-as-strings converted to list of enums
    /// </summary>
    UFUNCTION()
        void AccountInfo(UPfTestContext* testContext);
    UFUNCTION()
        void OnAccountInfo(FClientGetAccountInfoResult result, UObject* customData);

    /// <summary>
    /// CLIENT API
    /// Test that CloudScript can be properly set up and invoked
    /// </summary>
    UFUNCTION()
        void CloudScript(UPfTestContext* testContext);
    UFUNCTION()
        void OnHelloWorldCloudScript(FClientExecuteCloudScriptResult result, UObject* customData);
        
    /// <summary>
    /// CLIENT API
    /// Test that CloudScript errors can be deciphered
    /// </summary>
    UFUNCTION()
        void CloudScriptError(UPfTestContext* testContext);
    UFUNCTION()
        void OnCloudScriptError(FClientExecuteCloudScriptResult result, UObject* customData);

    /// <summary>
    /// CLIENT API
    /// Test that the client can publish custom PlayStream events
    /// </summary>
    UFUNCTION()
        void WriteEvent(UPfTestContext* testContext);
    UFUNCTION()
        void OnWritePlayerEvent(FClientWriteEventResponse result, UObject* customData);

    /// <summary>
    /// SERVER API
    /// Test that server apis can be called successfully
    /// Parameter types tested: none
    /// </summary>
    UFUNCTION()
        void ServerTitleData(UPfTestContext* testContext);
    UFUNCTION()
        void OnServerTitleData(FServerGetTitleDataResult result, UObject* customData);

    /// <summary>
    /// ENTITY API
    /// Convert the ClientToken to an EntityToken
    /// </summary>
    UFUNCTION()
        void GetEntityToken(UPfTestContext* testContext);
    UFUNCTION()
        void OnGetEntityToken(FAuthenticationGetEntityTokenResponse result, UObject* customData);

    /// <summary>
    /// ENTITY API
    /// Save and load an Entity object
    /// </summary>
    UFUNCTION()
        void ObjectApi(UPfTestContext* testContext);
    UFUNCTION()
        void OnGetObjectApi1(FDataGetObjectsResponse result, UObject* customData);
    UFUNCTION()
        void OnSetObjectApi(FDataSetObjectsResponse result, UObject* customData);
    UFUNCTION()
        void OnGetObjectApi2(FDataGetObjectsResponse result, UObject* customData);
};
