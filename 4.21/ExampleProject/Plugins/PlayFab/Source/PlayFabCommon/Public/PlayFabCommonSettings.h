//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "CoreMinimal.h"

namespace PlayFabCommon
{
    class PLAYFABCOMMON_API PlayFabCommonSettings
    {
    public:
        static const FString sdkVersion;
        static const FString buildIdentifier;
        static const FString versionString;
        static const FString verticalName;

        static FString serverURL;
        static FString productionEnvironmentURL;
        static FString titleId; // You must set this value for PlayFabSdk to work properly (Found in the Game Manager for your title, at the PlayFab Website)
        static FString clientSessionTicket; // Secret token that represents your session in the Client API. Set by calling any login method in the Client API
        static FString developerSecretKey; // You must set this value for PlayFabSdk to work properly (Found in the Game Manager for your title, at the PlayFab Website)
        static FString entityToken; // Secret token that represents your session in the Entity API. Set by calling GetEntityToken in the Entity API
        static FString advertisingIdType; // Set this to the appropriate AD_TYPE_X constant below
        static FString advertisingIdValue; // Set this to corresponding device value

        // DisableAdvertising is provided for completeness, but changing it is not suggested
        // Disabling this may prevent your advertising-related PlayFab marketplace partners from working correctly
        static bool disableAdvertising;
        static const FString AD_TYPE_IDFA;
        static const FString AD_TYPE_ANDROID_ID;

        static FString playFabApiSecretKey; // PlayFab DeveloperSecretKey
        static FString photonRealtimeAppId;
        static FString photonTurnbasedAppId;
        static FString photonChatAppId;

        static FString getURL(const FString& callPath)
        {
            if (serverURL.Len() == 0)
            {
                serverURL = TEXT("https://") + titleId + (verticalName.IsEmpty() ? "" : "." + verticalName) + productionEnvironmentURL;
            }
            return serverURL + callPath + TEXT("?sdk=") + versionString;
        }
    };
}
