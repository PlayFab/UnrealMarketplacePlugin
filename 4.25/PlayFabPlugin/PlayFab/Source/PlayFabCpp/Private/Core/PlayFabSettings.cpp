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
    FString PlayFabSettings::GetServerURL()
    {
        return IPlayFabCommonModuleInterface::Get().GetServerURL();
    }
    FString PlayFabSettings::GetProductionEnvironmentURL()
    {
        return IPlayFabCommonModuleInterface::Get().GetProductionEnvironmentURL();
    }
    FString PlayFabSettings::GetTitleId()
    {
        return IPlayFabCommonModuleInterface::Get().GetTitleId();
    }
    FString PlayFabSettings::GetClientSessionTicket()
    {
        return IPlayFabCommonModuleInterface::Get().GetClientSessionTicket();
    }
    FString PlayFabSettings::GetDeveloperSecretKey()
    {
        return IPlayFabCommonModuleInterface::Get().GetDeveloperSecretKey();
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
    FString PlayFabSettings::GetVerticalName()
    {
        return IPlayFabCommonModuleInterface::Get().GetVerticalName();
    }
    FString PlayFabSettings::GetUrl(const FString& callPath)
    {
        return IPlayFabCommonModuleInterface::Get().GetUrl(callPath);
    }
    FString PlayFabSettings::GetLocalApiServer()
    {
        return PlayFabCommon::PlayFabCommonUtils::GetLocalSettingsFileProperty(TEXT("LocalApiServer"));
    }

    // Setters
    void PlayFabSettings::SetServerURL(const FString&  serverURL)
    {
        IPlayFabCommonModuleInterface::Get().SetServerURL(serverURL);
    }
    void PlayFabSettings::SetProductionEnvironmentURL(const FString&  productionEnvironmentURL)
    {
        IPlayFabCommonModuleInterface::Get().SetProductionEnvironmentURL(productionEnvironmentURL);
    }
    void PlayFabSettings::SetTitleId(const FString&  titleId)
    {
        IPlayFabCommonModuleInterface::Get().SetTitleId(titleId);
    }
    void PlayFabSettings::SetClientSessionTicket(const FString&  clientSessionTicket)
    {
        IPlayFabCommonModuleInterface::Get().SetClientSessionTicket(clientSessionTicket);
    }
    void PlayFabSettings::SetDeveloperSecretKey(const FString&  developerSecretKey)
    {
        IPlayFabCommonModuleInterface::Get().SetDeveloperSecretKey(developerSecretKey);
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
