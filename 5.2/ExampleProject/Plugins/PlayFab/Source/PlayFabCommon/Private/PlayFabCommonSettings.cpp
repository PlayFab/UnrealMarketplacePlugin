//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "PlayFabCommonSettings.h"
#include "Kismet/GameplayStatics.h"

namespace PlayFabCommon
{
    const FString PlayFabCommonSettings::sdkVersion = "1.142.240412";
    const FString PlayFabCommonSettings::buildIdentifier = "adobuild_unrealmarketplaceplugin_215";
    const FString PlayFabCommonSettings::versionString = "UE4MKPL-1.142.240412";
    const FString PlayFabCommonSettings::engineVersion = "5.2";
#if defined(_XBOX_ONE) || defined(_XBOX) || defined(MICROSOFT_GAME_CORE)
    const FString PlayFabCommonSettings::platformString = "GDK";
#elif PLATFORM_IOS
    const FString PlayFabCommonSettings::platformString = "iOS";
#elif PLATFORM_ANDROID
    const FString PlayFabCommonSettings::platformString = "Android";
#elif PLATFORM_SWITCH
    const FString PlayFabCommonSettings::platformString = "Switch";
#elif PLATFORM_WINDOWS
    const FString PlayFabCommonSettings::platformString = "Windows";
#else
    const FString PlayFabCommonSettings::platformString = UGameplayStatics::GetPlatformName();
#endif

    FString PlayFabCommonSettings::clientSessionTicket;
    FString PlayFabCommonSettings::entityToken;
    FString PlayFabCommonSettings::photonRealtimeAppId;
    FString PlayFabCommonSettings::photonTurnbasedAppId;
    FString PlayFabCommonSettings::photonChatAppId;
}
