//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "ACloudScriptTestResultUploader.h"

#include "IPlayFab.h"
#include "PlayFabCppBaseModel.h"
#include "PlayFabError.h"
#include "Core/PlayFabClientAPI.h"
#include "PlayFabTestContext.h"
#include "GenericPlatformMisc.h"
DEFINE_LOG_CATEGORY(LogTestResults);

void ACloudScriptTestResultUploader::UploadToCloudscript(const TArray<class UPlayFabTestContext*>& SuiteTests)
{
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

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

    UE_LOG(LogTestResults, Log, TEXT("Request: \n%s"), *request.toJSONString());

    ClientAPI->ExecuteCloudScript(
        request,
        PlayFab::UPlayFabClientAPI::FExecuteCloudScriptDelegate::CreateUObject(this, &ACloudScriptTestResultUploader::SuccessfulUpload),
        PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ACloudScriptTestResultUploader::UploadErrored)
    );
}

void ACloudScriptTestResultUploader::SuccessfulUpload(const PlayFab::ClientModels::FExecuteCloudScriptResult& result) const
{
    UE_LOG(LogTestResults, Log, TEXT("Cloud Upload Success: \n%s"), *result.toJSONString());
    if(ShouldQuitOnCompletion()) {
        FGenericPlatformMisc::RequestExit(true);
    }
}

void ACloudScriptTestResultUploader::UploadErrored(const PlayFab::FPlayFabCppError& error) const
{
    UE_LOG(LogTestResults, Error, TEXT("Cloud Upload Error: \n%s"), *error.GenerateErrorReport());
}

bool ACloudScriptTestResultUploader::ShouldQuitOnCompletion() const {
    return GetWorld() && !GetWorld()->IsPlayInEditor();
}
