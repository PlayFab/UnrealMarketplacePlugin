//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "TestFramework/PlayFabTestRunner.h"

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

FString IPlayFabTestRunner::GenerateTestSummary()
{
    auto& SuiteTests = GetSuiteTests();
    auto& OutputSummary = GetCachedSummary();

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

    auto& SuiteTests = GetSuiteTests();
    InTestCase->GetTests(SuiteTests);
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

    auto& SuiteTests = GetSuiteTests();
    const auto Index = CurrentTestIndex;
    if (Index < SuiteTests.Num())
    {
        auto CurrentTestData = SuiteTests[Index];
        UPlayFabTestCase* CurrentTestCase = CurrentTestData->GetTestCase();

        ManageTestCase(CurrentTestCase);

        if (CurrentTestData->activeState == PlayFabApiTestActiveState::PENDING
            && CurrentTestData->activeState != PlayFabApiTestActiveState::ACTIVE)
        {
            numberOfTests++;

            UE_LOG(LogPlayFabCommon, Log, TEXT("Starting test: %s"), *CurrentTestData->testName);

            CurrentTestCase->SetUp(CurrentTestData);
            CurrentTestData->activeState = PlayFabApiTestActiveState::ACTIVE;

            CurrentTestData->startTime = FDateTime::UtcNow();
            CurrentTestData->testFunc.Execute(CurrentTestData);
        }

        if (CurrentTestData->GetDurationInSeconds() > TEST_TIMEOUT_SECONDS)
        {
            CurrentTestData->EndTest(PlayFabApiTestFinishState::TIMEDOUT, TEXT("Timed Out"));
        }

        if (CurrentTestData->activeState == PlayFabApiTestActiveState::ACTIVE
            && CurrentTestData->activeState != PlayFabApiTestActiveState::COMPLETE)
        {
            CurrentTestCase->Tick(CurrentTestData);
        }
        else
        {
            switch (CurrentTestData->finishState)
            {
            case PlayFabApiTestFinishState::PASSED: passedTests++;
                break;
            case PlayFabApiTestFinishState::FAILED: failedTests++;
                break;
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
