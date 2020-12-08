//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "CoreMinimal.h"
#include "PlayFabError.h"

namespace PlayFab
{
    class PlayFabSettings
    {
    public:
        static FString sdkVersion;
        static FString buildIdentifier;
        static FString versionString;

        static FString GetClientSessionTicket();
        static FString GetEntityToken();
        static FString GetAdvertisingIdType();
        static FString GetAdvertisingIdValue();
        static bool GetDisableAdvertising();
        static FString GetLocalApiServer();

        static void SetClientSessionTicket(const FString& clientSessionTicket);
        static void SetEntityToken(const FString& entityToken);
        static void SetAdvertisingIdType(const FString& advertisingIdType);
        static void SetAdvertisingIdValue(const FString& advertisingIdValue);
        static void SetDisableAdvertising(bool disableAdvertising);

        static FString AD_TYPE_IDFA;
        static FString AD_TYPE_ANDROID_ID;

        static FString GeneratePfUrl(const FString& urlPath);
    };
}
