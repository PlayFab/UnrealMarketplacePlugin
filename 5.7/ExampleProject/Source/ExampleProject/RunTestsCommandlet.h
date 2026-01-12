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

class UPlayFabCppTests;
class UPlayFabBlueprintTests;
class UTestTitleDataLoader;

UCLASS()
class URunTestsCommandlet : public UCommandlet, public IPlayFabTestRunner
{
    GENERATED_BODY()

private:
    UPROPERTY()
    TArray<UPlayFabTestContext*> suiteTests;
    UPROPERTY()
    UPlayFabTestCase* activeTestCase;
    UPROPERTY()
    UTestTitleDataLoader* ttdLoader;
    UPROPERTY()
    FString outputSummary;
    UPROPERTY()
    ACloudScriptTestResultUploader* pUploader;
    UPROPERTY()
    UPlayFabCppTests* pCppTests;
    UPROPERTY()
    UPlayFabBlueprintTests* pBpTests;

protected:
    virtual TArray<UPlayFabTestContext*>& GetSuiteTests();
    virtual UPlayFabTestCase* GetActiveTest();
    virtual UTestTitleDataLoader& GetCachedTitleData();
    virtual void SetActiveTest(UPlayFabTestCase* newTestCase);
    virtual FString& GetCachedSummary();

public:
    // Default CTor
    URunTestsCommandlet();

    /** UCommandlet interface implementation */
    virtual int32 Main(const FString& Params) override;
};
