
#include "TestFramework/PlayFabTestContext.h"

UFUNCTION()
void UPlayFabTestContext::EndTest(PlayFabApiTestFinishState InFinishState, FString InMessage)
{
    UE_LOG(LogPlayFabCommon, Log, TEXT("Ending Test: %s."), *testName);

    finishState = InFinishState;
    testResultMsg = InMessage;

    endTime = FDateTime::UtcNow();

    activeState = PlayFabApiTestActiveState::COMPLETE;
}