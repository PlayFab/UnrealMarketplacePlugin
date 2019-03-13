//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "PlayFabTests.h"

#include "TestFramework/PlayFabTestCase.h"
#include "TestFramework/PlayFabTestEnums.h"

#include "PlayFabTestContext.generated.h"

// Represent a running Test, with every information about it's execution.
UCLASS(Blueprintable, BlueprintType)
class PLAYFABTESTS_API UPlayFabTestContext : public UObject
{
    GENERATED_BODY()

public:
    DECLARE_DYNAMIC_DELEGATE_OneParam(FApiTestCase, class UPlayFabTestContext*, error);

    // The Test's name.
    UPROPERTY()
    FString testName;

    // Current state of this Test.
    UPROPERTY()
    PlayFabApiTestActiveState activeState;

    // Final state of this Test.
    UPROPERTY()
    PlayFabApiTestFinishState finishState;

    // Result message.
    UPROPERTY()
    FString testResultMsg;

    // Test function callback.
    UPROPERTY()
    FApiTestCase testFunc;

    // Time at which this Test started.
    UPROPERTY()
    FDateTime startTime;

    // Time at which this Test ended.
    UPROPERTY()
    FDateTime endTime;

    UPROPERTY() UPlayFabTestCase* TestCase;

    UFUNCTION() UPlayFabTestCase* GetTestCase() const { return TestCase; }


    /**
     * Initializes this Test.
     * @param InName This Test's name.
     * @param InTestFunc This Test's function.
     */
    UFUNCTION()
    void Setup(FString InName, UPlayFabTestCase* InTestCase, FString InTestFuncName)
    {
        testName = InName;
        activeState = PlayFabApiTestActiveState::PENDING;
        finishState = PlayFabApiTestFinishState::TIMEDOUT;
        testResultMsg = "";
        startTime = 0;
        endTime = 0;

        TestCase = InTestCase;

        UPlayFabTestContext::FApiTestCase TestDelegate;
        TestDelegate.BindUFunction(TestCase, *InTestFuncName);

        UE_LOG(LogTemp, Log, TEXT("Binding %s: %s"), *InName, *InTestFuncName);

        testFunc = TestDelegate;
    };

    UFUNCTION()
    static UPlayFabTestContext* CreateTestContext(FString InName, UPlayFabTestCase* InTestCase, FString InTestFuncName)
    {
        auto OutTestContext = NewObject<UPlayFabTestContext>();
        OutTestContext->Setup(InName, InTestCase, InTestFuncName);

        return OutTestContext;
    }

    /**
     * Returns the time this Test took to complete, as a Timespan.
     * @returns The time this Test tool to complete, as a Timespan.
     */
    UFUNCTION(BlueprintPure)
    FORCEINLINE FTimespan GetDuration() const
    {
        FDateTime now = FDateTime::UtcNow();
        FDateTime tempEndTime = (activeState == PlayFabApiTestActiveState::COMPLETE) ? endTime : now;
        FDateTime tempStartTime = (startTime != 0) ? startTime : now;

        return (tempEndTime - tempStartTime);
    }

    /**
     * Returns the time this Test took to complete, in seconds.
     * @returns The time this Test tool to complete, in seconds.
     */
    UFUNCTION(BlueprintPure)
    FORCEINLINE float GetDurationInSeconds() const { return GetDuration().GetTotalSeconds(); }

    /**
     * Returns the time this Test took to complete, in milliseconds.
     * @returns The time this Test took to complete, in milliseconds.
     */
    UFUNCTION(BlueprintPure)
    FORCEINLINE float GetDurationInMilliseconds() const { return GetDuration().GetTotalMilliseconds(); }

    UFUNCTION()
    void EndTest(PlayFabApiTestFinishState InFinishState = PlayFabApiTestFinishState::PASSED, FString InMessage = "")
    {
        UE_LOG(LogPlayFabTests, Log, TEXT("Ending Test: %s."), *testName);

        finishState = InFinishState;
        testResultMsg = InMessage;

        endTime = FDateTime::UtcNow();

        activeState = PlayFabApiTestActiveState::COMPLETE;
    }

    /**
     * Generates this Test's summary, and returns it as a FString.
     * @param InNow The current time
     * @returns This Test's Summary
     */
    UFUNCTION()
    FString GenerateTestSummary(FDateTime InNow)
    {
        FString temp;
        temp = FString::FromInt(GetDurationInMilliseconds());
        while (temp.Len() < 12)
            temp = " " + temp;
        temp += " ms, ";
        switch (finishState)
        {
        case PlayFabApiTestFinishState::PASSED: temp += "pass: ";
            break;
        case PlayFabApiTestFinishState::FAILED: temp += "FAILED: ";
            break;
        case PlayFabApiTestFinishState::SKIPPED: temp += "SKIPPED: ";
            break;
        case PlayFabApiTestFinishState::TIMEDOUT: temp += "TIMED OUT: ";
            break;
        }
        temp += testName;
        if (testResultMsg.Len() > 0)
        {
            temp += " - ";
            temp += testResultMsg;
        }
        return temp;
    }
};
