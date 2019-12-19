//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "Commandlets/Commandlet.h"
#include "PlayFab.h"

#include "TestFramework/PlayFabTestRunner.h"

#include "ACloudScriptTestResultUploader.h"

#include "RunTestsCommandlet.generated.h"

namespace PlayFab
{
    struct FPlayFabCppError;

    namespace ClientModels
    {
        struct FExecuteCloudScriptResult;
        struct FLoginResult;
    }
}

UCLASS()
class URunTestsCommandlet : public UCommandlet, public IPlayFabTestRunner
{
    GENERATED_BODY()

private:
    UPROPERTY()
    ACloudScriptTestResultUploader* pUploader;

public:
    // Default CTor
    URunTestsCommandlet();

    /** UCommandlet interface implementation */
    virtual int32 Main(const FString& Params) override;
};
