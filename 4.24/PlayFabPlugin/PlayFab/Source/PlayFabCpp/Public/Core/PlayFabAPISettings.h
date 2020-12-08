//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "CoreMinimal.h"
#include "PlayFabSettings.h"

/**
* The settings that can be used (optionally) by instance versions of PlayFab APIs.
*/
class PLAYFABCPP_API UPlayFabAPISettings
{
public:
    UPlayFabAPISettings() :
        AdvertisingIdType(PlayFab::PlayFabSettings::GetAdvertisingIdType())
        , AdvertisingIdValue(PlayFab::PlayFabSettings::GetAdvertisingIdValue())
        , DisableAdvertising(PlayFab::PlayFabSettings::GetDisableAdvertising())
    {
    }

    FString& GetAdvertisingIdType()
    {
        return AdvertisingIdType;
    }

    const FString& GetAdvertisingIdType() const
    {
        return AdvertisingIdType;
    }

    void SetAdvertisingIdType(FString InAdvertisingIdType)
    {
        AdvertisingIdType = InAdvertisingIdType;
    }

    FString& GetAdvertisingIdValue()
    {
        return AdvertisingIdValue;
    }

    const FString& GetAdvertisingIdValue() const
    {
        return AdvertisingIdValue;
    }

    void SetAdvertisingIdValue(FString InAdvertisingIdValue)
    {
        AdvertisingIdValue = InAdvertisingIdValue;
    }

    bool GetDisableAdvertising() const
    {
        return DisableAdvertising;
    }

    void SetDisableAdvertising(bool InDisableAdvertising)
    {
        DisableAdvertising = InDisableAdvertising;
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

private:
    // Set this to the appropriate AD_TYPE_X constant (defined in PlayFabSettings)
    FString AdvertisingIdType; 
    // Set this to corresponding device value
    FString AdvertisingIdValue; 

    // DisableAdvertising is provided for completeness, but changing it is not suggested.
    //  Disabling this may prevent your advertising-related PlayFab marketplace partners from working correctly
    bool DisableAdvertising = false;
};
