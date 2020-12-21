//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "PlayFabCommonSettings.h"

namespace PlayFabCommon
{
    const FString PlayFabCommonSettings::sdkVersion = "1.51.201218";
    const FString PlayFabCommonSettings::buildIdentifier = "jbuild_unrealmarketplaceplugin_sdk-unrealslave-2_0";
    const FString PlayFabCommonSettings::versionString = "UE4MKPL-1.51.201218";

    FString PlayFabCommonSettings::clientSessionTicket;
    FString PlayFabCommonSettings::entityToken;
    FString PlayFabCommonSettings::advertisingIdType;
    FString PlayFabCommonSettings::advertisingIdValue;

    bool PlayFabCommonSettings::disableAdvertising = false;
    const FString PlayFabCommonSettings::AD_TYPE_IDFA = "Idfa";
    const FString PlayFabCommonSettings::AD_TYPE_ANDROID_ID = "Adid";

    FString PlayFabCommonSettings::photonRealtimeAppId;
    FString PlayFabCommonSettings::photonTurnbasedAppId;
    FString PlayFabCommonSettings::photonChatAppId;
}
