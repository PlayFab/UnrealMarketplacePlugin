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
        VerticalName(PlayFab::PlayFabSettings::GetVerticalName())
        , BaseServiceHost(PlayFab::PlayFabSettings::GetProductionEnvironmentURL())
        , TitleId(PlayFab::PlayFabSettings::GetTitleId())
#ifndef DISABLE_PLAYFABCLIENT_API
        , AdvertisingIdType(PlayFab::PlayFabSettings::GetAdvertisingIdType())
        , AdvertisingIdValue(PlayFab::PlayFabSettings::GetAdvertisingIdValue())
        , DisableAdvertising(PlayFab::PlayFabSettings::GetDisableAdvertising())
#endif
    {
    }

    FString& GetVerticalName()
    {
        return VerticalName;
    }

    const FString& GetVerticalName() const
    {
        return VerticalName;
    }

    void SetVerticalName(FString InVerticalName)
    {
        VerticalName = InVerticalName;
    }

    FString& GetBaseServiceHost()
    {
        return BaseServiceHost;
    }

    const FString& GetBaseServiceHost() const
    {
        return BaseServiceHost;
    }

    void SetBaseServiceHost(FString InBaseServiceHost)
    {
        BaseServiceHost = InBaseServiceHost;
    }

    FString& GetTitleId()
    {
        return TitleId;
    }

    const FString& GetTitleId() const
    {
        return TitleId;
    }

    void SetTitleId(FString InTitleId)
    {
        TitleId = InTitleId;
    }

    FString& GetAdvertisingIdType()
    {
#ifdef DISABLE_PLAYFABCLIENT_API
        checkf(false, TEXT("AdvertisingIdType is disabled because DISABLE_PLAYFABCLIENT_API is set."));
#endif
        return AdvertisingIdType;
    }

    const FString& GetAdvertisingIdType() const
    {
#ifdef DISABLE_PLAYFABCLIENT_API
        checkf(false, TEXT("AdvertisingIdType is disabled because DISABLE_PLAYFABCLIENT_API is set."));
#endif
        return AdvertisingIdType;
    }

    void SetAdvertisingIdType(FString InAdvertisingIdType)
    {
#ifdef DISABLE_PLAYFABCLIENT_API
        checkf(false, TEXT("AdvertisingIdType is disabled because DISABLE_PLAYFABCLIENT_API is set."));
#endif

        AdvertisingIdType = InAdvertisingIdType;
    }

    FString& GetAdvertisingIdValue()
    {
#ifdef DISABLE_PLAYFABCLIENT_API
        checkf(false, TEXT("AdvertisingIdValue is disabled because DISABLE_PLAYFABCLIENT_API is set."));
#endif

        return AdvertisingIdValue;
    }

    const FString& GetAdvertisingIdValue() const
    {
#ifdef DISABLE_PLAYFABCLIENT_API
        checkf(false, TEXT("AdvertisingIdValue is disabled because DISABLE_PLAYFABCLIENT_API is set."));
#endif

        return AdvertisingIdValue;
    }

    void SetAdvertisingIdValue(FString InAdvertisingIdValue)
    {
#ifdef DISABLE_PLAYFABCLIENT_API
        checkf(false, TEXT("AdvertisingIdValue is disabled because DISABLE_PLAYFABCLIENT_API is set."));
#endif

        AdvertisingIdValue = InAdvertisingIdValue;
    }

    bool GetDisableAdvertising() const
    {
#ifdef DISABLE_PLAYFABCLIENT_API
        checkf(false, TEXT("DisableAdvertising is disabled because DISABLE_PLAYFABCLIENT_API is set."));
#endif

        return DisableAdvertising;
    }

    void SetDisableAdvertising(bool InDisableAdvertising)
    {
    
#ifdef DISABLE_PLAYFABCLIENT_API
        checkf(false, TEXT("DisableAdvertising is disabled because DISABLE_PLAYFABCLIENT_API is set."));
#endif
        DisableAdvertising = InDisableAdvertising;
    }

    FString GetUrl(const FString& CallPath)
    {
        return TEXT("https://") + (!VerticalName.IsEmpty() ? VerticalName : TitleId) + BaseServiceHost
         + CallPath + TEXT("?sdk=") + PlayFab::PlayFabSettings::sdkVersion;
    }

private:
    // The name of a PlayFab service vertical
    FString VerticalName; 
    // The base for a PlayFab service host
    FString BaseServiceHost; 
    // You must set this value for PlayFabSdk to work properly (found in the Game Manager for your title, at the PlayFab Website)
    FString TitleId; 
    
    // Set this to the appropriate AD_TYPE_X constant (defined in PlayFabSettings)
    FString AdvertisingIdType; 
    // Set this to corresponding device value
    FString AdvertisingIdValue; 

    // DisableAdvertising is provided for completeness, but changing it is not suggested.
    //  Disabling this may prevent your advertising-related PlayFab marketplace partners from working correctly
    bool DisableAdvertising = false;
};