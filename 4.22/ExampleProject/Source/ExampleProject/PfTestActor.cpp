//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "PfTestActor.h"

#include "Tests/PlayFabCppTests.h"
#include "Tests/PlayFabBlueprintTests.h"

// Sets default values
APfTestActor::APfTestActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APfTestActor::BeginPlay()
{
    Super::BeginPlay();

    AddTestCase(NewObject<UPlayFabCppTests>());
    AddTestCase(NewObject<UPlayFabBlueprintTests>());
    _submitCloudScript = false;
}

// Called every frame
void APfTestActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    Run(DeltaTime);

    if (TestsAreComplete() && !_submitCloudScript)
    {
        _submitCloudScript = true;
        pUploader = NewObject<ACloudScriptTestResultUploader>();
        pUploader->UploadToCloudscript(SuiteTests);
    }
}

void APfTestActor::EndPlay(const EEndPlayReason::Type reason)
{
    Super::EndPlay(reason);
    if(pUploader != nullptr)
    {
        delete pUploader;
    }
}

bool APfTestActor::TestsAreComplete() const {
    return SuiteState == PlayFabApiTestActiveState::COMPLETE;
}
