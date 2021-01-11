//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "PlayFabSettings.h"
#include "PlayFabCommon.h"
#include "PlayFabCommonUtils.h"

namespace PlayFab
{
    FString PlayFabSettings::sdkVersion;
    FString PlayFabSettings::buildIdentifier;
    FString PlayFabSettings::versionString;

    FString PlayFabSettings::AD_TYPE_IDFA;
    FString PlayFabSettings::AD_TYPE_ANDROID_ID;

    // Getters
    FString PlayFabSettings::GetClientSessionTicket()
    {
        return IPlayFabCommonModuleInterface::Get().GetClientSessionTicket();
    }
    FString PlayFabSettings::GetEntityToken()
    {
        return IPlayFabCommonModuleInterface::Get().GetEntityToken();
    }
    FString PlayFabSettings::GetAdvertisingIdType()
    {
        return IPlayFabCommonModuleInterface::Get().GetAdvertisingIdType();
    }
    FString PlayFabSettings::GetAdvertisingIdValue()
    {
        return IPlayFabCommonModuleInterface::Get().GetAdvertisingIdValue();
    }
    bool PlayFabSettings::GetDisableAdvertising()
    {
        return IPlayFabCommonModuleInterface::Get().GetDisableAdvertising();
    }
    FString PlayFabSettings::GeneratePfUrl(const FString& urlPath)
    {
        return IPlayFabCommonModuleInterface::Get().GeneratePfUrl(urlPath);
    }
    FString PlayFabSettings::GetLocalApiServer()
    {
        return PlayFabCommon::PlayFabCommonUtils::GetLocalSettingsFileProperty(TEXT("LocalApiServer"));
    }

    // Setters
    void PlayFabSettings::SetClientSessionTicket(const FString&  clientSessionTicket)
    {
        IPlayFabCommonModuleInterface::Get().SetClientSessionTicket(clientSessionTicket);
    }
    void PlayFabSettings::SetEntityToken(const FString&  entityToken)
    {
        IPlayFabCommonModuleInterface::Get().SetEntityToken(entityToken);
    }
    void PlayFabSettings::SetAdvertisingIdType(const FString&  advertisingIdType)
    {
        IPlayFabCommonModuleInterface::Get().SetAdvertisingIdType(advertisingIdType);
    }
    void PlayFabSettings::SetAdvertisingIdValue(const FString&  advertisingIdValue)
    {
        IPlayFabCommonModuleInterface::Get().SetAdvertisingIdValue(advertisingIdValue);
    }
    void PlayFabSettings::SetDisableAdvertising(bool disableAdvertising)
    {
        IPlayFabCommonModuleInterface::Get().SetDisableAdvertising(disableAdvertising);
    }
}
