//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "CoreMinimal.h"
#include "PlayFabCommon/Public/PlayFabRuntimeSettings.h"

namespace PlayFabCommon
{
    // Runtime static shared variables for PlayFab
    class PLAYFABCOMMON_API PlayFabCommonSettings
    {
    public:
        static const FString sdkVersion;
        static const FString buildIdentifier;
        static const FString versionString;

        static FString clientSessionTicket; // Secret token that represents your session in the Client API. Set by calling any login method in the Client API
        static FString entityToken; // Secret token that represents your session in the Entity API. Set by calling GetEntityToken in the Entity API

        static FString photonRealtimeAppId;
        static FString photonTurnbasedAppId;
        static FString photonChatAppId;

        static FString GeneratePfUrl(const FString& urlPath)
        {
            const UPlayFabRuntimeSettings* rSettings = GetDefault<UPlayFabRuntimeSettings>();
            if (rSettings->ProductionEnvironmentURL.StartsWith(TEXT("https://")))
            {
                return rSettings->ProductionEnvironmentURL
                    + urlPath + TEXT("?sdk=") + versionString;
            }
            else
            {
                return TEXT("https://") + rSettings->TitleId + rSettings->ProductionEnvironmentURL
                    + urlPath + TEXT("?sdk=") + versionString;
            }
        }
    };
}
