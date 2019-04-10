//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "RunTestsCommandlet.h"
#include "ExampleProject.h"

#include "CppTests/PlayFabCppTests.h"
#include "Tests/PlayFabBlueprintTests.h"

#include "IPlayFab.h"
#include "PlayFabCppBaseModel.h"
#include "PlayFabError.h"
#include "Core/PlayFabClientAPI.h"

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

    bool bSentToCloud = false;
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
            if (!bSentToCloud)
            {
                bSentToCloud = UploadResultToCloud();
            }
            else if (!bPrintedTestSummary)
            {
                UE_LOG(LogPlayFabExampleProject, Log, TEXT("Test Summary:\n%s"), *GenerateTestSummary());
                bPrintedTestSummary = true;
            }
        }

        FPlatformProcess::Sleep(0);
    }

    GIsRunning = false;

    return failedTests == 0 ? 0 : 1;
}

bool URunTestsCommandlet::UploadResultToCloud()
{
    if (!ClientAPI.IsValid())
    {
        ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
        return false;
    }

    TArray<TSharedPtr<FJsonValue>> TestReport;
    for (auto SuiteTest : SuiteTests)
    {
        FString finishStateStr;
        switch (SuiteTest->finishState)
        {
        case PlayFabApiTestFinishState::PASSED: finishStateStr = TEXT("PASSED");
            break;
        case PlayFabApiTestFinishState::FAILED: finishStateStr = TEXT("FAILED");
            break;
        case PlayFabApiTestFinishState::SKIPPED: finishStateStr = TEXT("SKIPPED");
            break;
        case PlayFabApiTestFinishState::TIMEDOUT: finishStateStr = TEXT("TIMEDOUT");
            break;
        default: finishStateStr = TEXT("");
            break;
        }

        TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
        JsonObject->SetStringField(TEXT("classname"), IPlayFab::Get().getBuildIdentifier());
        JsonObject->SetStringField(TEXT("name"), SuiteTest->testName); // This test's name.
        JsonObject->SetNumberField(TEXT("time"), SuiteTest->GetDurationInSeconds()); // End time is invalid here... so cheating a bit.
        JsonObject->SetStringField(TEXT("message"), SuiteTest->testResultMsg);
        JsonObject->SetStringField(TEXT("failureText"), finishStateStr); // Those two should match.
        JsonObject->SetStringField(TEXT("finishState"), finishStateStr); //
        JsonObject->SetObjectField(TEXT("stacktrace"), nullptr);

        TestReport.Add(MakeShareable(new FJsonValueObject(JsonObject)));
    }

    TSharedPtr<FJsonObject> finalJson = MakeShareable(new FJsonObject());
    finalJson->SetStringField(TEXT("customId"), ClientAPI->GetBuildIdentifier());
    finalJson->SetArrayField(TEXT("testReport"), TestReport);

    auto functionParameter = PlayFab::FJsonKeeper();
    functionParameter.readFromValue(MakeShareable(new FJsonValueObject(finalJson)));

    PlayFab::ClientModels::FExecuteCloudScriptRequest request;
    request.FunctionName = TEXT("SaveTestData");
    request.FunctionParameter = functionParameter;
    request.GeneratePlayStreamEvent = true;

    UE_LOG(LogPlayFabExampleProject, Log, TEXT("Request: \n%s"), *request.toJSONString());

    return ClientAPI->ExecuteCloudScript(
        request,
        PlayFab::UPlayFabClientAPI::FExecuteCloudScriptDelegate::CreateUObject(this, &URunTestsCommandlet::OnCloudUploadSuccess),
        PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &URunTestsCommandlet::OnCloudUploadError)
    );
}

void URunTestsCommandlet::OnCloudUploadSuccess(const PlayFab::ClientModels::FExecuteCloudScriptResult& result) const
{
    UE_LOG(LogPlayFabExampleProject, Log, TEXT("Cloud Upload Success: \n%s"), *result.toJSONString());

    GIsRequestingExit = true;
}

void URunTestsCommandlet::OnCloudUploadError(const PlayFab::FPlayFabCppError& error) const
{
    UE_LOG(LogPlayFabExampleProject, Error, TEXT("Cloud Upload Error: \n%s"), *error.GenerateErrorReport());

    GIsRequestingExit = true;
}
