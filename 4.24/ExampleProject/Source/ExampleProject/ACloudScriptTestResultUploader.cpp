//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "ACloudScriptTestResultUploader.h"

#include "IPlayFab.h"
#include "PlayFabCppBaseModel.h"
#include "PlayFabError.h"
#include "Core/PlayFabClientAPI.h"
#include "TestFramework/PlayFabTestContext.h"

#include "Runtime/Core/Public/GenericPlatform/GenericPlatformMisc.h"
#include "Runtime/Engine/Classes/Engine/World.h"

DEFINE_LOG_CATEGORY(LogTestResults);

void ACloudScriptTestResultUploader::UploadToCloudscript(const TArray<class UPlayFabTestContext*>& SuiteTests)
{
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    float totalTime = 0;
    int totalTests = 0, totalPassed = 0, totalFailures = 0, totalSkipped = 0, totalTimedout = 0;
    FString buildIdLc = ClientAPI->GetBuildIdentifier().ToLower();

    TArray<TSharedPtr<FJsonValue>> TestReportList;
    for (auto SuiteTest : SuiteTests)
    {
        totalTests++;
        totalTime += SuiteTest->GetDurationInSeconds();

        FString finishStateStr;
        switch (SuiteTest->finishState)
        {
        case PlayFabApiTestFinishState::PASSED:
            finishStateStr = TEXT("PASSED");
            totalPassed++;
            break;
        case PlayFabApiTestFinishState::FAILED:
            finishStateStr = TEXT("FAILED");
            totalFailures++;
            break;
        case PlayFabApiTestFinishState::SKIPPED:
            finishStateStr = TEXT("SKIPPED");
            totalSkipped++;
            break;
        case PlayFabApiTestFinishState::TIMEDOUT:
            finishStateStr = TEXT("TIMEDOUT");
            totalTimedout++;
            break;
        default: finishStateStr = TEXT("");
            break;
        }

        TSharedPtr<FJsonObject> eachTest = MakeShareable(new FJsonObject());
        eachTest->SetStringField(TEXT("classname"), buildIdLc);
        eachTest->SetStringField(TEXT("name"), SuiteTest->testName); // This test's name.
        eachTest->SetNumberField(TEXT("time"), SuiteTest->GetDurationInSeconds());
        eachTest->SetStringField(TEXT("message"), SuiteTest->testResultMsg);
        eachTest->SetStringField(TEXT("failureText"), finishStateStr);
        eachTest->SetStringField(TEXT("finishState"), finishStateStr);
        eachTest->SetObjectField(TEXT("stacktrace"), nullptr);

        TestReportList.Add(MakeShareable(new FJsonValueObject(eachTest)));
    }

    TSharedPtr<FJsonObject> suiteJson = MakeShareable(new FJsonObject());
    // suiteJson->SetStringField(TEXT("name"), buildIdLc);
    // suiteJson->SetNumberField(TEXT("time"), totalTime);
    suiteJson->SetNumberField(TEXT("tests"), totalTests);
    // suiteJson->SetNumberField(TEXT("errors"), totalTimedout);
    suiteJson->SetNumberField(TEXT("failures"), totalFailures);
    suiteJson->SetNumberField(TEXT("skipped"), totalSkipped);
    suiteJson->SetNumberField(TEXT("passed"), totalPassed);
    suiteJson->SetArrayField(TEXT("testResults"), TestReportList);

    TArray<TSharedPtr<FJsonValue>> TestSuiteList;
    TestSuiteList.Add(MakeShareable(new FJsonValueObject(suiteJson)));
    TSharedPtr<FJsonObject> outerWrapper = MakeShareable(new FJsonObject());
    outerWrapper->SetArrayField(TEXT("testReport"), TestSuiteList);

    auto functionParameter = PlayFab::FJsonKeeper();
    functionParameter.readFromValue(MakeShareable(new FJsonValueObject(outerWrapper)));

    PlayFab::ClientModels::FExecuteCloudScriptRequest request;
    request.FunctionName = TEXT("SaveTestData");
    request.FunctionParameter = functionParameter;
    request.GeneratePlayStreamEvent = true;

    UE_LOG(LogTestResults, Log, TEXT("Cloud Save Request: \n%s"), *request.toJSONString());

    ClientAPI->ExecuteCloudScript(
        request,
        PlayFab::UPlayFabClientAPI::FExecuteCloudScriptDelegate::CreateUObject(this, &ACloudScriptTestResultUploader::SuccessfulUpload),
        PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ACloudScriptTestResultUploader::UploadErrored)
    );
}

void ACloudScriptTestResultUploader::SuccessfulUpload(const PlayFab::ClientModels::FExecuteCloudScriptResult& result)
{
    UE_LOG(LogTestResults, Log, TEXT("Cloud Upload Success: \n%s"), *result.toJSONString());
    isComplete = true;
}

void ACloudScriptTestResultUploader::UploadErrored(const PlayFab::FPlayFabCppError& error)
{
    UE_LOG(LogTestResults, Error, TEXT("Cloud Upload Error: \n%s"), *error.GenerateErrorReport());
    isComplete = true;
}
