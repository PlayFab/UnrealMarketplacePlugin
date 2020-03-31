//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "UObject/Interface.h"

#include "TestFramework/PlayFabTestCase.h"
#include "TestFramework/PlayFabTestEnums.h"

#include "PlayFabTestRunner.generated.h"

/* must have BlueprintType as a specifier to have this interface exposed to blueprints
   with this line you can easily add this interface to any blueprint class */
UINTERFACE(BlueprintType, Meta = (CannotImplementInterfaceInBlueprint))
class PLAYFABCOMMON_API UPlayFabTestRunner : public UInterface
{
    GENERATED_UINTERFACE_BODY()
};

class UPlayFabTestCase;

class PLAYFABCOMMON_API IPlayFabTestRunner
{
    GENERATED_IINTERFACE_BODY()

protected:
    // Current State of the test runner.
    PlayFabApiTestActiveState SuiteState;

    virtual TArray<UPlayFabTestContext*>& GetSuiteTests() = 0;
    virtual UPlayFabTestCase* GetActiveTest() = 0;
    virtual void SetActiveTest(UPlayFabTestCase* newTestCase) = 0;
    virtual FString& GetCachedSummary() = 0;

    // Index of the test currently run.
    int CurrentTestIndex;
    // Total number of tests
    int numberOfTests;
    // Number of failed tests
    int failedTests;
    // Number of skipped tests
    int skippedTests;
    // Number of successful tests
    int passedTests;

public:
    // Generates and returns the Tests Summary.
    UFUNCTION(BlueprintCallable)
    virtual FString GenerateTestSummary();

    // Adds a Test case to be run.
    void AddTestCase(UPlayFabTestCase* InTestCase);

    // Manage the switch between different test cases.
    void ManageTestCase(UPlayFabTestCase* nextTestCase);

    // Run the Tests.
    void Run(const float InDeltaTime);
};
