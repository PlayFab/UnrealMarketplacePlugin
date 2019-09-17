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
        static FString verticalName;

        static bool GetUseDevelopmentEnvironment();
        static FString GetServerURL();
        static FString GetDevelopmentEnvironmentURL();
        static FString GetProductionEnvironmentURL();
        static FString GetTitleId();
        static FString GetClientSessionTicket();
        static FString GetDeveloperSecretKey();
        static FString GetEntityToken();
        static FString GetAdvertisingIdType();
        static FString GetAdvertisingIdValue();
        static bool GetDisableAdvertising();
        static FString GetVerticalName();
        static FString GetLocalApiServer();


        static void SetUseDevelopmentEnvironment(bool useDevelopmentEnvironment);
        static void SetServerURL(const FString& serverURL);
        static void SetDevelopmentEnvironmentURL(const FString& developmentEnvironmentURL);
        static void SetProductionEnvironmentURL(const FString& productionEnvironmentURL);
        static void SetTitleId(const FString& titleId);
        static void SetClientSessionTicket(const FString& clientSessionTicket);
        static void SetDeveloperSecretKey(const FString& developerSecretKey);
        static void SetEntityToken(const FString& entityToken);
        static void SetAdvertisingIdType(const FString& advertisingIdType);
        static void SetAdvertisingIdValue(const FString& advertisingIdValue);
        static void SetDisableAdvertising(bool disableAdvertising);
        static void SetVerticalName(const FString& verticalName);

        static FString AD_TYPE_IDFA;
        static FString AD_TYPE_ANDROID_ID;

        static FString GetUrl(const FString& callPath);
    };
}
