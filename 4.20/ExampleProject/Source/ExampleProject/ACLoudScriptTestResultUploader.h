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

private:
    void SuccessfulUpload(const PlayFab::ClientModels::FExecuteCloudScriptResult& result) const;

    void UploadErrored(const PlayFab::FPlayFabCppError& error) const;

    bool ShouldQuitOnCompletion() const;
};

