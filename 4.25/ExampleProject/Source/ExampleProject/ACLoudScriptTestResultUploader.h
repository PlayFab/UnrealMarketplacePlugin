//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "GameFramework/Actor.h"

#include "PlayFab.h"
#include "PlayFabCpp/Public/Core/PlayFabClientDataModels.h"
#include "PlayFabCpp/Public/Core/PlayFabError.h"

#include "ACloudScriptTestResultUploader.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTestResults, Log, All);

UCLASS()
class ACloudScriptTestResultUploader : public AActor
{
    GENERATED_BODY()
public:
    void UploadToCloudscript(const TArray<class UPlayFabTestContext*>& SuiteTests);

    bool isComplete{ false };

private:
    void SuccessfulUpload(const PlayFab::ClientModels::FExecuteCloudScriptResult& result);

    void UploadErrored(const PlayFab::FPlayFabCppError& error);
};
