//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "PlayFabCommonSettings.h"
#include "Misc/EngineVersion.h"

namespace PlayFabCommon
{
    const FString PlayFabCommonSettings::sdkVersion = "1.137.240119";
    const FString PlayFabCommonSettings::buildIdentifier = "adobuild_unrealmarketplaceplugin_215";
    const FString PlayFabCommonSettings::versionString = "UE4MKPL-1.137.240119";
    const FString PlayFabCommonSettings::engineVersion = FEngineVersion::Current().ToString();

    FString PlayFabCommonSettings::clientSessionTicket;
    FString PlayFabCommonSettings::entityToken;
    FString PlayFabCommonSettings::photonRealtimeAppId;
    FString PlayFabCommonSettings::photonTurnbasedAppId;
    FString PlayFabCommonSettings::photonChatAppId;
}
