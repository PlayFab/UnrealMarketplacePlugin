//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "PfTestActor.h"

#include "Tests/PlayFabCppTests.h"
#include "Tests/PlayFabBlueprintTests.h"

#include "Runtime/Engine/Classes/Engine/World.h"

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

ACloudScriptTestResultUploader* SpawnUploader(UWorld* world) {
    FActorSpawnParameters spawnParams;
    FVector loc(0, 0, 0);
    FRotator rot(0, 0, 0);
    return world->SpawnActor<ACloudScriptTestResultUploader>(loc, rot, spawnParams);
}

void APfTestActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    Run(DeltaTime);

    if (TestsAreComplete() && !_submitCloudScript)
    {
        auto pUploader = SpawnUploader(GetWorld());
        _submitCloudScript = true;
        pUploader->UploadToCloudscript(SuiteTests);
    }
}

void APfTestActor::EndPlay(const EEndPlayReason::Type reason)
{
    Super::EndPlay(reason);
}

bool APfTestActor::TestsAreComplete() const {
    return SuiteState == PlayFabApiTestActiveState::COMPLETE;
}
