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

    // Getters
    FString PlayFabSettings::GetClientSessionTicket()
    {
        return IPlayFabCommonModuleInterface::Get().GetClientSessionTicket();
    }
    FString PlayFabSettings::GetEntityToken()
    {
        return IPlayFabCommonModuleInterface::Get().GetEntityToken();
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
}
