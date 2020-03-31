//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "TestFramework/PlayFabTestCase.h"
#include "TestFramework/PlayFabTestContext.h"

#include "PlayFabBaseModel.h"
#include "PlayFabClientModels.h"
#include "PlayFabAuthenticationModels.h"
#include "PlayFabDataModels.h"
#include "PlayFabServerModels.h"

#include "PlayFabBlueprintTests.generated.h"


UCLASS()
class PLAYFAB_API UPlayFabBlueprintTests : public UPlayFabTestCase
{
    GENERATED_BODY()

public:
    int testMessageInt;

    // #### PlayFab TestSuite Interface ####

    virtual void ClassSetUp() override;

    virtual void GetTests(TArray<UPlayFabTestContext*>& InOutTests) override
    {

        InOutTests.ADD_TEST(Invalid Login (Blueprint), InvalidLogin);
        InOutTests.ADD_TEST(Invalid Registration (Blueprint), InvalidRegistration);
        InOutTests.ADD_TEST(Login Or Register(Blueprint), LoginOrRegister);
        InOutTests.ADD_TEST(Login With Advertising ID (Blueprint), LoginWithAdvertisingId);
        InOutTests.ADD_TEST(User Data API (Blueprint), UserDataApi);
        InOutTests.ADD_TEST(Player Statistics API (Blueprint), PlayerStatisticsApi);
        InOutTests.ADD_TEST(LeaderBoard (Blueprint), LeaderBoard);
        InOutTests.ADD_TEST(Account Info (Blueprint), AccountInfo);
        InOutTests.ADD_TEST(Cloud Script (Blueprint), CloudScript);
        InOutTests.ADD_TEST(Cloud Script Error (Blueprint), CloudScriptError);
        InOutTests.ADD_TEST(Write Event (Blueprint), WriteEvent);

        // BUG 41305 This test fails in AppCenter for Android
        //InOutTests.ADD_TEST(Server Title Data (Blueprint), ServerTitleData);

        InOutTests.ADD_TEST(Get Entity Token (Blueprint), GetEntityToken);
        // BUG 41305 This test fails in AppCenter for Android
        //InOutTests.ADD_TEST(Object API (Blueprint), ObjectApi);
    }

    UFUNCTION()
    void OnSharedError(FPlayFabError error, UObject* customData)
    {
        auto testContext = static_cast<UPlayFabTestContext*>(customData);
        testContext->EndTest(PlayFabApiTestFinishState::FAILED, "Unexpected error: " + error.ErrorMessage + "\n" + error.ErrorDetails);
    }
    

    /// <summary> 
    /// CLIENT API
    /// Try to deliberately log in with an inappropriate password,
    ///   and verify that the error displays as expected.
    /// </summary>
    UFUNCTION()
    void InvalidLogin(UPlayFabTestContext* testContext);
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
    void InvalidRegistration(UPlayFabTestContext* testContext);
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
    void LoginOrRegister(UPlayFabTestContext* testContext);
    UFUNCTION()
    void OnLoginOrRegister(FClientLoginResult result, UObject* customData);

    /// <summary>
    /// CLIENT API
    /// Test that the login call sequence sends the AdvertisingId when set
    /// </summary>
    UFUNCTION()
    void LoginWithAdvertisingId(UPlayFabTestContext* testContext);
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
    void UserDataApi(UPlayFabTestContext* testContext);
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
    void PlayerStatisticsApi(UPlayFabTestContext* testContext);
    UFUNCTION()
    void OnPlayerStatisticsApiGet1(FClientGetPlayerStatisticsResult result, UObject* customData);
    UFUNCTION()
    void OnPlayerStatisticsApiUpdate(FClientUpdatePlayerStatisticsResult result, UObject* customData);
    UFUNCTION()
    void OnPlayerStatisticsApiGet2(FClientGetPlayerStatisticsResult result, UObject* customData);

    /// <summary>
    /// CLIENT API
    /// Test that leaderboard results can be requested
    /// Parameter types tested: List of contained-classes
    /// </summary>
    UFUNCTION()
    void LeaderBoard(UPlayFabTestContext* testContext);
    UFUNCTION()
    void OnLeaderBoard(FClientGetLeaderboardResult result, UObject* customData);

    /// <summary>
    /// CLIENT API
    /// Test that AccountInfo can be requested
    /// Parameter types tested: List of enum-as-strings converted to list of enums
    /// </summary>
    UFUNCTION()
    void AccountInfo(UPlayFabTestContext* testContext);
    UFUNCTION()
    void OnAccountInfo(FClientGetAccountInfoResult result, UObject* customData);

    /// <summary>
    /// CLIENT API
    /// Test that CloudScript can be properly set up and invoked
    /// </summary>
    UFUNCTION()
    void CloudScript(UPlayFabTestContext* testContext);
    UFUNCTION()
    void OnHelloWorldCloudScript(FClientExecuteCloudScriptResult result, UObject* customData);

    /// <summary>
    /// CLIENT API
    /// Test that CloudScript errors can be deciphered
    /// </summary>
    UFUNCTION()
    void CloudScriptError(UPlayFabTestContext* testContext);
    UFUNCTION()
    void OnCloudScriptError(FClientExecuteCloudScriptResult result, UObject* customData);

    /// <summary>
    /// CLIENT API
    /// Test that the client can publish custom PlayStream events
    /// </summary>
    UFUNCTION()
    void WriteEvent(UPlayFabTestContext* testContext);
    UFUNCTION()
    void OnWritePlayerEvent(FClientWriteEventResponse result, UObject* customData);
    

    /// <summary>
    /// SERVER API
    /// Test that server apis can be called successfully
    /// Parameter types tested: none
    /// </summary>
    UFUNCTION()
    void ServerTitleData(UPlayFabTestContext* testContext);
    UFUNCTION()
    void OnServerTitleData(FServerGetTitleDataResult result, UObject* customData);
    

    /// <summary>
    /// ENTITY API
    /// Convert the ClientToken to an EntityToken
    /// </summary>
    UFUNCTION()
    void GetEntityToken(UPlayFabTestContext* testContext);
    UFUNCTION()
    void OnGetEntityToken(FAuthenticationGetEntityTokenResponse result, UObject* customData);

    /// <summary>
    /// ENTITY API
    /// Save and load an Entity object
    /// </summary>
    UFUNCTION()
    void ObjectApi(UPlayFabTestContext* testContext);
    UFUNCTION()
    void OnGetObjectApi1(FDataGetObjectsResponse result, UObject* customData);
    UFUNCTION()
    void OnSetObjectApi(FDataSetObjectsResponse result, UObject* customData);
    UFUNCTION()
    void OnGetObjectApi2(FDataGetObjectsResponse result, UObject* customData);
};
