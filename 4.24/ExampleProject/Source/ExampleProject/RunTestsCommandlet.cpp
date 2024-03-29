//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "RunTestsCommandlet.h"
#include "ExampleProject.h"

#include "Tests/PlayFabCppTests.h"
#include "Tests/PlayFabBlueprintTests.h"

#include "Engine/Engine.h"

URunTestsCommandlet::URunTestsCommandlet()
{
    IsClient = false;
    IsEditor = false;
    IsServer = false;
    LogToConsole = true;
#if ENGINE_MINOR_VERSION > 19 && ENGINE_MAJOR_VERSION < 5
    ShowProgress = true;
#endif
    ShowErrorCount = true;
}

TArray<UPlayFabTestContext*>& URunTestsCommandlet::GetSuiteTests()
{
    return suiteTests;
}

UPlayFabTestCase* URunTestsCommandlet::GetActiveTest()
{
    return activeTestCase;
}

UTestTitleDataLoader& URunTestsCommandlet::GetCachedTitleData()
{
    if (ttdLoader == nullptr)
        ttdLoader = NewObject<UTestTitleDataLoader>();
    return *ttdLoader;
}

void URunTestsCommandlet::SetActiveTest(UPlayFabTestCase* newTestCase)
{
    activeTestCase = newTestCase;
}

FString& URunTestsCommandlet::GetCachedSummary()
{
    return outputSummary;
}

int32 URunTestsCommandlet::Main(const FString& Params)
{
#if ENGINE_MINOR_VERSION < 24 && ENGINE_MAJOR_VERSION < 5
    GIsRequestingExit = false; // Global used by Unreal to indicate that the commandlet should exit.
#endif

    if (IsValid(GEngine))
    {
        GIsRunning = true;
    }
    else
    {
        UE_LOG(LogPlayFabExampleProject, Error, TEXT("Invalid Engine instance."));
        return 1;
    }

    pCppTests = NewObject<UPlayFabCppTests>();
    pBpTests = NewObject<UPlayFabBlueprintTests>();

    AddTestCase(pCppTests);
    AddTestCase(pBpTests);

    bool bPrintedTestSummary = false;
    pUploader = NewObject<ACloudScriptTestResultUploader>();

    while (!pUploader->isComplete)
    {
        GEngine->UpdateTimeAndHandleMaxTickRate();
        GEngine->Tick(FApp::GetDeltaTime(), false);

        // Required for FTimerManager to function - as it blocks ticks, if the frame counter doesn't change
        GFrameCounter++;

        const float DeltaTime = FApp::GetDeltaTime();
#if ENGINE_MAJOR_VERSION < 5
        FTicker::GetCoreTicker().Tick(DeltaTime);
#else
        FTSTicker::GetCoreTicker().Tick(DeltaTime);
#endif 

        Run(DeltaTime);
        if (SuiteState == PlayFabApiTestActiveState::COMPLETE)
        {
            if (!bPrintedTestSummary)
            {
                UE_LOG(LogPlayFabExampleProject, Log, TEXT("Test Summary:\n%s"), *GenerateTestSummary());
                bPrintedTestSummary = true;
                pUploader->UploadToCloudscript(GetSuiteTests());
            }
        }

        FPlatformProcess::Sleep(0);
    }

    return failedTests == 0 ? 0 : 1;
}
