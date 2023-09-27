//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "PlayFabTestEnums.generated.h"

// Active State of a Test.
UENUM(BlueprintType)
enum class PlayFabApiTestActiveState : uint8
{
    // Not started.
    PENDING UMETA(DisplayName = "PENDING"),
    // Currently testung.
    ACTIVE UMETA(DisplayName = "ACTIVE"),
    // An answer is sent by the http thread, but the main thread hasn't finalized the test yet.
    READY UMETA(DisplayName = "READY"),
    // Test is finalized and recorded. 
    COMPLETE UMETA(DisplayName = "COMPLETE"),
    // Test was aborted dur to an error.
    ABORTED UMETA(DisplayName = "ABORTED")
};

// Final state of a Test.
UENUM(BlueprintType)
enum class PlayFabApiTestFinishState : uint8
{
    // The test is Passed
    PASSED UMETA(DisplayName = "PASSED"),
    // The test Failed.
    FAILED UMETA(DisplayName = "FAILED"),
    // The Test was skipped.
    SKIPPED UMETA(DisplayName = "SKIPPED"),
    // The Test timed out.
    TIMEDOUT UMETA(DisplayName = "TIMEDOUT"),
};
