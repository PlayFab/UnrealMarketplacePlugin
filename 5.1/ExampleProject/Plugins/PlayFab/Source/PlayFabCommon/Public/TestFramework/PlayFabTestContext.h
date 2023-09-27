//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "TestFramework/PlayFabTestCase.h"
#include "TestFramework/PlayFabTestEnums.h"
#include "PlayFabCommon.h"

#include "PlayFabTestContext.generated.h"

class UPlayFabTestCase;

// Represent a running Test, with every information about it's execution.
UCLASS(Blueprintable, BlueprintType)
class PLAYFABCOMMON_API UPlayFabTestContext : public UObject
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

    UPROPERTY()
    UPlayFabTestCase* TestCase;

    FORCEINLINE UPlayFabTestCase* GetTestCase() const { return TestCase; }

    /**
     * Initializes this Test.
     * @param InName This Test's name.
     * @param InTestFunc This Test's function.
     */
    void Setup(const FString& InName, UPlayFabTestCase* InTestCase, const FString& InTestFuncName);

    static UPlayFabTestContext* CreateTestContext(const FString& InName, UPlayFabTestCase* InTestCase, const FString& InTestFuncName);

    /**
     * Returns the time this Test took to complete, as a Timespan.
     * @returns The time this Test tool to complete, as a Timespan.
     */
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
    FORCEINLINE float GetDurationInSeconds() const { return GetDuration().GetTotalSeconds(); }

    /**
     * Returns the time this Test took to complete, in milliseconds.
     * @returns The time this Test took to complete, in milliseconds.
     */
    FORCEINLINE float GetDurationInMilliseconds() const { return GetDuration().GetTotalMilliseconds(); }

    void EndTest(PlayFabApiTestFinishState InFinishState = PlayFabApiTestFinishState::PASSED, const FString& InMessage = "");

    /**
     * Generates this Test's summary, and returns it as a FString.
     * @param InNow The current time
     * @returns This Test's Summary
     */
    FString GenerateTestSummary(FDateTime InNow);
};
