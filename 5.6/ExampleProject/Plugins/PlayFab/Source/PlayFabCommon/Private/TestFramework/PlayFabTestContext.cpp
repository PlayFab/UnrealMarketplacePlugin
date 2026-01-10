//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "TestFramework/PlayFabTestContext.h"

void UPlayFabTestContext::Setup(const FString& InName, UPlayFabTestCase* InTestCase, const FString& InTestFuncName)
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

UPlayFabTestContext* UPlayFabTestContext::CreateTestContext(const FString& InName, UPlayFabTestCase* InTestCase, const FString& InTestFuncName)
{
    auto OutTestContext = NewObject<UPlayFabTestContext>();
    OutTestContext->Setup(InName, InTestCase, InTestFuncName);

    return OutTestContext;
}

void UPlayFabTestContext::EndTest(PlayFabApiTestFinishState InFinishState, const FString& InMessage)
{
    UE_LOG(LogPlayFabCommon, Log, TEXT("Ending Test: %s."), *testName);

    finishState = InFinishState;
    testResultMsg = InMessage;

    endTime = FDateTime::UtcNow();

    activeState = PlayFabApiTestActiveState::COMPLETE;
}

FString UPlayFabTestContext::GenerateTestSummary(FDateTime InNow)
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
