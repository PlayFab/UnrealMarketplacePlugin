//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////

#pragma once

#include "CoreMisc.h"
#include "Runtime/Launch/Resources/Version.h"

#include "PlayFab.h"
#include "Core/PlayFabAuthenticationDataModels.h"
#include "Core/PlayFabAuthenticationAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabDataDataModels.h"
#include "Core/PlayFabDataAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Core/PlayFabServerAPI.h"
#include "PlayFabBaseModel.h"
#include "PlayFabError.h"

#include "Misc/AutomationTest.h"

DECLARE_LOG_CATEGORY_EXTERN(LogPlayFabTest, Log, All);

/*
* ==== LoginWithEmail ====
*/
class PlayFabApiTest_0LoginWithEmail : public IAutomationLatentCommand
{
public:
	PlayFabApiTest_0LoginWithEmail(const FString& email, const FString& password);

	bool Update() override;
private:
	void OnSuccess(const PlayFab::ClientModels::FLoginResult& result) const;
	void OnError(const PlayFab::FPlayFabCppError& ErrorResult) const;

	FString email;
	FString password;
	PlayFabClientPtr clientAPI = nullptr;
};

/*
* ==== LoginWithCustomID ====
*/
class PlayFabApiTest_0LoginWithCustomID : public IAutomationLatentCommand
{
public:
	PlayFabApiTest_0LoginWithCustomID(const FString& customId);

	bool Update() override;
private:
	void OnSuccess(const PlayFab::ClientModels::FLoginResult& result) const;
	void OnError(const PlayFab::FPlayFabCppError& ErrorResult) const;

	FString customId;
	PlayFabClientPtr clientAPI = nullptr;
};

/*
* ==== LoginWithAdvertisingId ====
*/
class PlayFabApiTest_0LoginWithAdvertisingId : public IAutomationLatentCommand
{
public:
	PlayFabApiTest_0LoginWithAdvertisingId(const FString& customId);

	bool Update() override;
private:
	void OnSuccess(const PlayFab::ClientModels::FLoginResult& result) const;
	void OnError(const PlayFab::FPlayFabCppError& ErrorResult) const;

	int tickCounter = 0;
	FString customId;
	PlayFabClientPtr clientAPI = nullptr;
};

/*
* ==== UserData ====
*/
class PlayFabApiTest_GetUserData : public IAutomationLatentCommand
{
public:
	PlayFabApiTest_GetUserData(const FString& TEST_DATA_KEY_1, const FString& TEST_DATA_KEY_2, int expectedValue);

	bool Update() override;
private:
	void OnSuccess(const PlayFab::ClientModels::FGetUserDataResult& result) const;
	void CheckTimestamp(const FDateTime& updateTime) const;
	void OnError(const PlayFab::FPlayFabCppError& ErrorResult) const;

	FString TEST_DATA_KEY_1;
	FString TEST_DATA_KEY_2;
	int expectedValue = -1;

	PlayFabClientPtr clientAPI = nullptr;
};

class PlayFabApiTest_UpdateUserData : public IAutomationLatentCommand
{
public:
	PlayFabApiTest_UpdateUserData(const FString& TEST_DATA_KEY_1, const FString& TEST_DATA_KEY_2, int updateValue);

	bool Update() override;
private:
	void OnSuccess(const PlayFab::ClientModels::FUpdateUserDataResult& result) const;
	void OnError(const PlayFab::FPlayFabCppError& ErrorResult) const;

	FString TEST_DATA_KEY_1;
	FString TEST_DATA_KEY_2;
	int updateValue = -1;

	PlayFabClientPtr clientAPI = nullptr;
};

/*
* ==== PlayerStatistics ====
*/
class PlayFabApiTest_GetPlayerStatistics : public IAutomationLatentCommand
{
public:
	PlayFabApiTest_GetPlayerStatistics(const FString& TEST_STAT_NAME, int expectedValue);

	bool Update() override;
private:
	void OnSuccess(const PlayFab::ClientModels::FGetPlayerStatisticsResult& result) const;
	void OnError(const PlayFab::FPlayFabCppError& ErrorResult) const;

	FString TEST_STAT_NAME;
	int expectedValue = -1;

	PlayFabClientPtr clientAPI = nullptr;
};

class PlayFabApiTest_UpdatePlayerStatistics : public IAutomationLatentCommand
{
public:
	PlayFabApiTest_UpdatePlayerStatistics(const FString& TEST_STAT_NAME, int updateValue);

	bool Update() override;
private:
	void OnSuccess(const PlayFab::ClientModels::FUpdatePlayerStatisticsResult& result) const;
	void OnError(const PlayFab::FPlayFabCppError& ErrorResult) const;

	FString TEST_STAT_NAME;
	int updateValue = -1;

	PlayFabClientPtr clientAPI = nullptr;
};

/*
* ==== GetLeaderboard ====
*/
class PlayFabApiTest_GetLeaderboardC : public IAutomationLatentCommand
{
public:
	PlayFabApiTest_GetLeaderboardC(const FString& TEST_STAT_NAME);

	bool Update() override;
private:
	void OnSuccess(const PlayFab::ClientModels::FGetLeaderboardResult& result) const;
	void OnError(const PlayFab::FPlayFabCppError& ErrorResult) const;

	FString TEST_STAT_NAME;
	bool expectSuccess = false;

	PlayFabClientPtr clientAPI = nullptr;
};

class PlayFabApiTest_GetLeaderboardS : public IAutomationLatentCommand
{
public:
	PlayFabApiTest_GetLeaderboardS(const FString& TEST_STAT_NAME);

	bool Update() override;
private:
	void OnSuccess(const PlayFab::ServerModels::FGetLeaderboardResult& result) const;
	void OnError(const PlayFab::FPlayFabCppError& ErrorResult) const;

	FString TEST_STAT_NAME;

	PlayFabServerPtr serverAPI = nullptr;
};

/*
* ==== GetAllUsersCharacters ====
*/
class PlayFabApiTest_GetAllUsersCharacters : public IAutomationLatentCommand
{
public:
	PlayFabApiTest_GetAllUsersCharacters();

	bool Update() override;
private:
	void OnSuccess(const PlayFab::ClientModels::FListUsersCharactersResult& result) const;
	void OnError(const PlayFab::FPlayFabCppError& ErrorResult) const;

	PlayFabClientPtr clientAPI = nullptr;
};

/*
* ==== GetAccountInfo ====
*/
class PlayFabApiTest_GetAccountInfo : public IAutomationLatentCommand
{
public:
	PlayFabApiTest_GetAccountInfo();

	bool Update() override;
private:
	void OnSuccess(const PlayFab::ClientModels::FGetAccountInfoResult& result) const;
	void OnError(const PlayFab::FPlayFabCppError& ErrorResult) const;

	PlayFabClientPtr clientAPI = nullptr;
};

/*
* ==== ExecuteCloudScript ====
*/
class PlayFabApiTest_ExecuteCloudScript : public IAutomationLatentCommand
{
public:
	PlayFabApiTest_ExecuteCloudScript(const FString& functionName, bool expectFail);

	bool Update() override;
private:
	void OnSuccess(const PlayFab::ClientModels::FExecuteCloudScriptResult& result) const;
	void OnError(const PlayFab::FPlayFabCppError& ErrorResult) const;

	FString functionName;
	bool expectFail;

	PlayFabClientPtr clientAPI = nullptr;
};

/*
* ==== WriteEvent ====
*/
class PlayFabApiTest_WriteEvent : public IAutomationLatentCommand
{
public:
	PlayFabApiTest_WriteEvent();

	bool Update() override;
private:
	void OnSuccess(const PlayFab::ClientModels::FWriteEventResponse& result) const;
	void OnError(const PlayFab::FPlayFabCppError& ErrorResult) const;

	FString functionName;
	bool expectFail;

	PlayFabClientPtr clientAPI = nullptr;
};


/*
* ==== GetEntityToken ====
*/
class PlayFabApiTest_GetEntityToken : public IAutomationLatentCommand
{
public:
	PlayFabApiTest_GetEntityToken();

	bool Update() override;
private:
	void OnSuccess(const PlayFab::AuthenticationModels::FGetEntityTokenResponse& result) const;
	void OnError(const PlayFab::FPlayFabCppError& ErrorResult) const;

	PlayFabAuthenticationPtr authenticationAPI = nullptr;
};


/*
* ==== ObjectApi ====
*/
class PlayFabApiTest_ObjectApi : public IAutomationLatentCommand
{
public:
	PlayFabApiTest_ObjectApi();

	bool Update() override;
private:
	void OnSuccess(const PlayFab::DataModels::FGetObjectsResponse& result) const;
	void OnError(const PlayFab::FPlayFabCppError& ErrorResult) const;

	PlayFabDataPtr dataAPI = nullptr;
};


/*
* ==== Test Suite ====
*/
struct TestTitleData
{
public:
	FString titleId = TEXT("Your titleID");
	FString developerSecretKey = TEXT("For the security of your title, keep your secret key private!");
	FString userEmail = TEXT("An email associated with an existing user");
};

#define ADD_TEST(Name) TestFunctions.Add(&PlayFabApiTestSuite::Name); TestFunctionNames.Add(TEXT(#Name));
class PlayFabApiTestSuite : public FAutomationTestBase
{
	typedef bool (PlayFabApiTestSuite::*TestFunc)() const;

public:
	static FString playFabId; // Set by PlayFabApiTest_0LoginWithEmail upon successful login
	static FString entityId; // Set by PlayFabApiTest_GetEntityToken if retrieved successfully
	static FString entityType; // Set by PlayFabApiTest_GetEntityToken if retrieved successfully

							   // TEST CONSTANTS
	FString TEST_DATA_KEY_1 = TEXT("testCounter");
	FString TEST_DATA_KEY_2 = TEXT("deleteCounter");
	FString TEST_STAT_NAME = TEXT("str");
	FString INVALID_PASSWORD = TEXT("INVALID_PASSWORD");
	FString CLOUD_FUNCTION_HELLO_WORLD = TEXT("helloWorld");
	FString CLOUD_FUNCTION_THROW_ERROR = TEXT("throwError");

	// Input from TestTitleData.json
	TestTitleData testTitleData;

	PlayFabApiTestSuite(const FString& InName)
		: FAutomationTestBase(InName, false)
	{
		if (!LoadTitleData())
			return;
		// IPlayFabModuleInterface::Get().SetTitleInformationFromJson(//todo);

		ADD_TEST(InvalidLogin);
		ADD_TEST(LoginOrRegister);
		ADD_TEST(LoginWithAdvertisingId);
		ADD_TEST(UserDataApi);
		ADD_TEST(PlayerStatisticsApi);
		ADD_TEST(UserCharacter);
		ADD_TEST(LeaderBoard);
		ADD_TEST(AccountInfo);
		ADD_TEST(CloudScript);
		ADD_TEST(CloudScriptError);
		ADD_TEST(WriteEvent);
		ADD_TEST(GetEntityToken);
		ADD_TEST(ObjectApi);
	}

#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 11)
	virtual uint32 GetTestFlags() const override { return EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter; }
#elif (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION == 9)
	virtual uint32 GetTestFlags() const override { return EAutomationTestFlags::ATF_Editor; }
#endif
	virtual bool IsStressTest() const { return false; }
	virtual uint32 GetRequiredDeviceNum() const override { return 1; }

protected:
	bool LoadTitleData()
	{
		bool success = true;

		FString jsonInput;
		FString filename = TEXT("testTitleData.json");

		// Prefer to load path from environment variable, if present
		char* envPath = nullptr;
		size_t envPathStrLen;
		errno_t err = _dupenv_s(&envPath, &envPathStrLen, "PF_TEST_TITLE_DATA_JSON");
		if (err == 0 && envPath != nullptr)
			filename = FString(ANSI_TO_TCHAR(envPath));
		if (envPath != nullptr)
			free(envPath);

		success &= FFileHelper::LoadFileToString(jsonInput, *filename);

		TSharedPtr<FJsonObject> jsonParsed = nullptr;
		if (success)
		{
			TSharedRef<TJsonReader<>> jsonReader = TJsonReaderFactory<>::Create(jsonInput);
			success &= FJsonSerializer::Deserialize(jsonReader, jsonParsed);
		}

		if (success) success &= jsonParsed->TryGetStringField("titleId", testTitleData.titleId);
		if (success) success &= jsonParsed->TryGetStringField("developerSecretKey", testTitleData.developerSecretKey);
		if (success) success &= jsonParsed->TryGetStringField("userEmail", testTitleData.userEmail);

		return success;
	}

	virtual FString GetBeautifiedTestName() const override { return "PlayFabApiTests"; }
	virtual void GetTests(TArray<FString>& OutBeautifiedNames, TArray <FString>& OutTestCommands) const override
	{
		for (const FString& pfTestName : TestFunctionNames)
		{
			OutBeautifiedNames.Add(pfTestName);
			OutTestCommands.Add(pfTestName);
		}
	}

	bool RunTest(const FString& Parameters) override
	{
		clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
		serverAPI = IPlayFabModuleInterface::Get().GetServerAPI();
		TestTrue(TEXT("The clientAPI reports itself as invalid."), clientAPI.IsValid());
		TestTrue(TEXT("The serverAPI reports itself as invalid."), serverAPI.IsValid());
		serverAPI->SetTitleId(testTitleData.titleId);
		serverAPI->SetDevSecretKey(testTitleData.developerSecretKey);

		if (clientAPI.IsValid() && serverAPI.IsValid())
		{
			// find the matching test
			for (int32 i = 0; i < TestFunctionNames.Num(); ++i)
			{
				if (TestFunctionNames[i] == Parameters)
				{
					TestFunc TestFunction = TestFunctions[i];
					return (this->*TestFunction)();
				}
			}
		}
		return false;
	}

	bool InvalidLogin() const
	{
		ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_0LoginWithEmail(testTitleData.userEmail, INVALID_PASSWORD));

		return true;
	};

	bool LoginOrRegister() const
	{
		ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_0LoginWithCustomID(clientAPI->GetBuildIdentifier()));

		return true;
	};

	bool LoginWithAdvertisingId() const
	{
		ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_0LoginWithAdvertisingId(clientAPI->GetBuildIdentifier()));

		return true;
	};

	bool UserDataApi() const
	{
		ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_GetUserData(TEST_DATA_KEY_1, TEST_DATA_KEY_2, -1));

		return true;
	};

	bool PlayerStatisticsApi() const
	{
		ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_UpdatePlayerStatistics(TEST_STAT_NAME, -1));

		return true;
	};

	bool UserCharacter() const
	{
		ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_GetAllUsersCharacters());

		return true;
	};

	bool LeaderBoard() const
	{
		// These are both read-only, and don't interfere, so they can be run in parallel
		ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_GetLeaderboardC(TEST_STAT_NAME));
		ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_GetLeaderboardS(TEST_STAT_NAME));

		return true;
	};

	bool AccountInfo() const
	{
		ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_GetAccountInfo());

		return true;
	};

	bool CloudScript() const
	{
		ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_ExecuteCloudScript(CLOUD_FUNCTION_HELLO_WORLD, false));

		return true;
	};

	bool CloudScriptError() const
	{
		ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_ExecuteCloudScript(CLOUD_FUNCTION_THROW_ERROR, true));

		return true;
	};

	bool WriteEvent() const
	{
		ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_WriteEvent());

		return true;
	};

	bool GetEntityToken() const
	{
		ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_GetEntityToken());

		return true;
	};

	bool ObjectApi() const
	{
		ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_ObjectApi());

		return true;
	};

	PlayFabAuthenticationPtr authenticationAPI;
	PlayFabClientPtr clientAPI;
	PlayFabDataPtr dataAPI;
	PlayFabServerPtr serverAPI;
	TArray<TestFunc> TestFunctions;
	TArray<FString> TestFunctionNames;
};

namespace
{
	PlayFabApiTestSuite FPlayFabApiTestsAutomationTestInstance(TEXT("FPlayFabApiTests"));
}
