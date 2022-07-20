//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "CoreMinimal.h"
#include "PlayFabRuntimeSettings.generated.h"

/**
* Implements the settings for the PlayFab plugin in the Unreal GUI
* This ends up being more like "build time constants", as they can't be changed at runtime
*/
UCLASS(config = Engine, defaultconfig)
class PLAYFABCOMMON_API UPlayFabRuntimeSettings : public UObject
{
    GENERATED_BODY()
public:
    UPlayFabRuntimeSettings();

    // URL endpoint of the PlayFab production environment
    UPROPERTY(EditAnywhere, config, Category = Settings)
    FString ProductionEnvironmentURL;

    // Game Title ID
    UPROPERTY(EditAnywhere, config, Category = Settings)
    FString TitleId;

    // Secret Key, Do not add this to the clients!
    UPROPERTY(EditAnywhere, config, Category = Settings)
    FString DeveloperSecretKey;
};
