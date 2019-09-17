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
#if ENGINE_MINOR_VERSION > 19
    ShowProgress = true;
#endif
    ShowErrorCount = true;
}

int32 URunTestsCommandlet::Main(const FString& Params)
{
    GIsRequestingExit = false; // Global used by Unreal to indicate that the commandlet should exit.

    if (IsValid(GEngine))
    {
        GIsRunning = true;
    }
    else
    {
        UE_LOG(LogPlayFabExampleProject, Error, TEXT("Invalid Engine instance."));

        GIsRequestingExit = true;
        GIsRunning = false;
    }

    AddTestCase(NewObject<UPlayFabCppTests>());
    AddTestCase(NewObject<UPlayFabBlueprintTests>());

    bool bPrintedTestSummary = false;

    while (GIsRunning && !GIsRequestingExit)
    {
        GEngine->UpdateTimeAndHandleMaxTickRate();
        GEngine->Tick(FApp::GetDeltaTime(), false);

        // Required for FTimerManager to function - as it blocks ticks, if the frame counter doesn't change
        GFrameCounter++;

        const float DeltaTime = FApp::GetDeltaTime();
        FTicker::GetCoreTicker().Tick(DeltaTime);

        Run(DeltaTime);
        const bool bIsComplete = SuiteState == PlayFabApiTestActiveState::COMPLETE;
        if (bIsComplete)
        {
            if (!bPrintedTestSummary)
            {
                UE_LOG(LogPlayFabExampleProject, Log, TEXT("Test Summary:\n%s"), *GenerateTestSummary());
                bPrintedTestSummary = true;
                pUploader = NewObject<ACloudScriptTestResultUploader>();
                pUploader->UploadToCloudscript(SuiteTests);
            }
        }

        FPlatformProcess::Sleep(0);
    }

    GIsRunning = false;

    return failedTests == 0 ? 0 : 1;
}
