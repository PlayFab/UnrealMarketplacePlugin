//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "CoreMinimal.h"
#include "PlayFabSettings.h"
#include "PlayFabRuntimeSettings.h"

/**
* The settings that can be used (optionally) by instance versions of PlayFab APIs.
*/
class PLAYFABCPP_API UPlayFabAPISettings
{
public:
    UPlayFabAPISettings()
    {
    }

    FString GeneratePfUrl(const FString& urlPath)
    {
        const UPlayFabRuntimeSettings* rSettings = GetDefault<UPlayFabRuntimeSettings>();
        if (rSettings->ProductionEnvironmentURL.StartsWith(TEXT("https://")))
        {
            return rSettings->ProductionEnvironmentURL
                + urlPath + TEXT("?sdk=") + PlayFab::PlayFabSettings::sdkVersion;
        }
        else
        {
            return TEXT("https://") + rSettings->TitleId + rSettings->ProductionEnvironmentURL
                + urlPath + TEXT("?sdk=") + PlayFab::PlayFabSettings::sdkVersion;
        }
    }
};
