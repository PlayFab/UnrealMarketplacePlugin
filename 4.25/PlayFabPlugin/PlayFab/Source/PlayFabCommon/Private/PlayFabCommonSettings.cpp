//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "PlayFabCommonSettings.h"

namespace PlayFabCommon
{
    const FString PlayFabCommonSettings::sdkVersion = "1.63.210830";
    const FString PlayFabCommonSettings::buildIdentifier = "jbuild_unrealmarketplaceplugin_sdk-unrealslave-6_0";
    const FString PlayFabCommonSettings::versionString = "UE4MKPL-1.63.210830";

    FString PlayFabCommonSettings::clientSessionTicket;
    FString PlayFabCommonSettings::entityToken;

    FString PlayFabCommonSettings::photonRealtimeAppId;
    FString PlayFabCommonSettings::photonTurnbasedAppId;
    FString PlayFabCommonSettings::photonChatAppId;
}
