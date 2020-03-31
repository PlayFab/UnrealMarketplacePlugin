//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "GameFramework/Actor.h"
#include "TestFramework/PlayFabTestRunner.h"

#include "ACloudScriptTestResultUploader.h"

#include "PfTestActor.generated.h"

class UPlayFabCppTests;
class UPlayFabBlueprintTests;

UCLASS()
class APfTestActor : public AActor, public IPlayFabTestRunner
{
    GENERATED_BODY()

public:
    APfTestActor(); // Sets default values for this actor's properties

    virtual void BeginPlay() override; // Called when the game starts or when spawned
    virtual void Tick(float DeltaTime) override; // Called every frame
    virtual void EndPlay(const EEndPlayReason::Type reason) override;

protected:
    virtual TArray<UPlayFabTestContext*>& GetSuiteTests();
    virtual UPlayFabTestCase* GetActiveTest();
    virtual void SetActiveTest(UPlayFabTestCase* newTestCase);
    virtual FString& GetCachedSummary();

private:
    bool _submitCloudScript;

    UPROPERTY()
    TArray<UPlayFabTestContext*> suiteTests;
    UPROPERTY()
    UPlayFabTestCase* activeTestCase;
    UPROPERTY()
    FString outputSummary;
    UPROPERTY()
    UPlayFabCppTests* pCppTests;
    UPROPERTY()
    UPlayFabBlueprintTests* pBpTests;

    bool TestsAreComplete() const;
};
