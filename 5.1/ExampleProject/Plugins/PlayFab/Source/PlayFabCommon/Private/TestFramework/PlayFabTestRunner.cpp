//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "TestFramework/PlayFabTestRunner.h"

#include "PlayFab/Public/IPlayFab.h"
#include "PlayFab/Private/PlayFabPrivate.h"
#include "PlayFabCommon/Public/PlayFabRuntimeSettings.h"
#include "TestFramework/PlayFabTestCase.h"
#include "TestFramework/PlayFabTestContext.h"

#include "Misc/App.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Kismet/GameplayStatics.h"

const int SUMMARY_INIT_BUFFER_SIZE = 10000;
const int TEST_TIMEOUT_SECONDS = 10;

UPlayFabTestRunner::UPlayFabTestRunner(const FObjectInitializer& ObjectInitializer)
{
}

UTestTitleDataLoader::UTestTitleDataLoader()
{
    isValid = LoadTestTitleData();
}

bool UTestTitleDataLoader::LoadFromCode()
{
    // README:
    //   In order for tests to run, you need a valid testTitleData.json file
    //   Format specification here: https://github.com/PlayFab/SDKGenerator/blob/master/JenkinsConsoleUtility/testTitleData.md
    // Option 1: You can drop a testTitleData.json file into this location in your Unreal Project:
    //   FPaths::ProjectContentDir() + TEXT("/TestTitleData/testTitleData.json");
    // Option 2: You can specify the PF_TEST_TITLE_DATA_JSON environment variable
    //   (Windows or Linux), containing the full path of a testTitleData.json file, anywhere on your computer
    // Option 3:
    //   Delete this "return false;", and fill in the code variables below with your title's information

    return false;

    // titleId = "<your title id>";
    // developerSecretKey = "<your title secret>";
    // userEmail = "<a valid email linked to LoginWithEmailAddress>";

    // return true;
}

bool UTestTitleDataLoader::LoadFromFile()
{
    FString jsonInput;
    FString filename = FPaths::ProjectContentDir() + TEXT("/TestTitleData/testTitleData.json");

    if (!FPaths::FileExists(filename))
    {
        // Prefer to load path from environment variable, if present
#if PLATFORM_WINDOWS
        char* envPath = nullptr;
        size_t envPathStrLen;
        errno_t err = _dupenv_s(&envPath, &envPathStrLen, "PF_TEST_TITLE_DATA_JSON");
        if (err == 0 && envPath != nullptr)
            filename = FString(ANSI_TO_TCHAR(envPath));
        if (envPath != nullptr)
            free(envPath);
#endif
    }

    FString titleDataJson;
    bool success = FPaths::FileExists(filename) && FFileHelper::LoadFileToString(titleDataJson, *filename);
    if (!success)
        return success;

    TSharedPtr<FJsonObject> ttdJson;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(titleDataJson);
    FJsonSerializer::Deserialize(Reader, ttdJson);
    success &= ttdJson->TryGetStringField("titleId", titleId) && titleId.Len() > 0;
    success &= ttdJson->TryGetStringField("developerSecretKey", developerSecretKey) && developerSecretKey.Len() > 0;
    success &= ttdJson->TryGetStringField("userEmail", userEmail) && userEmail.Len() > 0;

    return success;
}

void UTestTitleDataLoader::ApplyToSettings()
{
    // Settings are globally shared
    GetMutableDefault<UPlayFabRuntimeSettings>()->TitleId = titleId;
}

bool UTestTitleDataLoader::LoadTestTitleData()
{
    bool loadSuccessful = LoadFromFile() || LoadFromCode();
    if (loadSuccessful)
    {
        ApplyToSettings();
    }
    return loadSuccessful;
}

FString IPlayFabTestRunner::GenerateTestSummary()
{
    TArray<UPlayFabTestContext*>& SuiteTests = GetSuiteTests();
    FString& OutputSummary = GetCachedSummary();

    OutputSummary.Empty(SUMMARY_INIT_BUFFER_SIZE); // Set the capacity to handle everything we're about to put into it

    FDateTime now = FDateTime::UtcNow();
    for (int i = 0; i < SuiteTests.Num(); i++)
    {
        if (OutputSummary.Len() != 0)
            OutputSummary += '\n';
        OutputSummary += SuiteTests[i]->GenerateTestSummary(now);
    }

    FString testCountLine = "\nTotal tests: ";
    testCountLine += FString::FromInt(numberOfTests);
    testCountLine += ", Passed: ";
    testCountLine += FString::FromInt(passedTests);
    testCountLine += ", Failed: ";
    testCountLine += FString::FromInt(failedTests);

    OutputSummary += testCountLine;

    int Day, Month, Year;
    now.GetDate(Year, Month, Day);

    OutputSummary += FString::Format(TEXT(". {0} {1}.{2}.{3}, {4}, {5}/{6}/{7}."),
                                     {
                                         FApp::GetEpicProductIdentifier(),
                                         ENGINE_MAJOR_VERSION,
                                         ENGINE_MINOR_VERSION,
                                         ENGINE_PATCH_VERSION,
                                         UGameplayStatics::GetPlatformName(),
                                         Month, Day, Year
                                     });

    return OutputSummary;
}

void IPlayFabTestRunner::AddTestCase(UPlayFabTestCase* InTestCase)
{
    if (SuiteState != PlayFabApiTestActiveState::PENDING)
        return;

    TArray<UPlayFabTestContext*>& SuiteTests = GetSuiteTests();
    InTestCase->GetTests(SuiteTests);
    const UTestTitleDataLoader& testTitleData = GetCachedTitleData();
    if (testTitleData.isValid)
        InTestCase->SetTestTitleData(testTitleData);
}

void IPlayFabTestRunner::ManageTestCase(UPlayFabTestCase* nextTestCase)
{
    UPlayFabTestCase* prevTestCase = GetActiveTest();

    if (prevTestCase != nextTestCase)
    {
        if (IsValid(prevTestCase))
            prevTestCase->ClassTearDown();

        if (IsValid(nextTestCase))
        {
            SetActiveTest(nextTestCase);
            nextTestCase->ClassSetUp();
        }
    }
}

void IPlayFabTestRunner::Run(const float InDeltaTime)
{
    if (SuiteState != PlayFabApiTestActiveState::PENDING)
        return;

    TArray<UPlayFabTestContext*>& SuiteTests = GetSuiteTests();
    const auto Index = CurrentTestIndex;
    if (Index < SuiteTests.Num())
    {
        auto CurrentTestData = SuiteTests[Index];
        UPlayFabTestCase* CurrentTestCase = CurrentTestData->GetTestCase();

        ManageTestCase(CurrentTestCase);

        if (CurrentTestData->activeState == PlayFabApiTestActiveState::PENDING)
        {
            numberOfTests++;

            UE_LOG(LogPlayFabCommon, Log, TEXT("Starting test: %s"), *CurrentTestData->testName);
            CurrentTestCase->SetUp(CurrentTestData);
            CurrentTestData->startTime = FDateTime::UtcNow();
            if (CurrentTestData->activeState == PlayFabApiTestActiveState::PENDING)
            {
                CurrentTestData->activeState = PlayFabApiTestActiveState::ACTIVE;
                CurrentTestData->testFunc.Execute(CurrentTestData);
            }
        }

        if (CurrentTestData->GetDurationInSeconds() > TEST_TIMEOUT_SECONDS)
        {
            CurrentTestData->EndTest(PlayFabApiTestFinishState::TIMEDOUT, TEXT("Timed Out"));
        }

        if (CurrentTestData->activeState == PlayFabApiTestActiveState::ACTIVE)
        {
            CurrentTestCase->Tick(CurrentTestData);
        }
        else
        {
            switch (CurrentTestData->finishState)
            {
            case PlayFabApiTestFinishState::PASSED: passedTests++; break;
            case PlayFabApiTestFinishState::FAILED: failedTests++; break;
            default: break;
            }

            CurrentTestCase->TearDown(CurrentTestData);
            ++CurrentTestIndex;
        }

        SuiteTests[Index] = CurrentTestData;
    }
    else
    {
        ManageTestCase(nullptr); // Cleanup

        SuiteState = PlayFabApiTestActiveState::COMPLETE;
        GEngine->ForceGarbageCollection(true);
    }
}
