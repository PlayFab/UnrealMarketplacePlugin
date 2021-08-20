//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "PlayFabCommon.h"

#if WITH_EDITOR
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#endif // WITH_EDITOR

#include "PlayFabCommonSettings.h"
#include "PlayFabCommon/Public/PlayFabRuntimeSettings.h"

#define LOCTEXT_NAMESPACE "FPlayFabCommonsModule"

DEFINE_LOG_CATEGORY(LogPlayFabCommon);

class FPlayFabCommonModule : public IPlayFabCommonModuleInterface
{
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    // Settings
    void RegisterSettings();
    void UnregisterSettings();

    FString GetSdkVersion() const override { return PlayFabCommon::PlayFabCommonSettings::sdkVersion; }
    FString GetBuildIdentifier() const override { return PlayFabCommon::PlayFabCommonSettings::buildIdentifier; }
    FString GetVersionString() const override { return PlayFabCommon::PlayFabCommonSettings::versionString; }

    FString GetClientSessionTicket() const override { return PlayFabCommon::PlayFabCommonSettings::clientSessionTicket; }
    FString GetEntityToken() const override { return PlayFabCommon::PlayFabCommonSettings::entityToken; }

    void SetClientSessionTicket(const FString& clientSessionTicket) override { PlayFabCommon::PlayFabCommonSettings::clientSessionTicket = clientSessionTicket; }
    void SetEntityToken(const FString& entityToken) override { PlayFabCommon::PlayFabCommonSettings::entityToken = entityToken; }

    FString GetPhotonRealtimeAppId() const override { return PlayFabCommon::PlayFabCommonSettings::photonRealtimeAppId; }
    void SetPhotonRealtimeAppId(const FString & photonRealtimeAppId) override { PlayFabCommon::PlayFabCommonSettings::photonRealtimeAppId = photonRealtimeAppId; }

    FString GetPhotonTurnbasedAppId() const override { return PlayFabCommon::PlayFabCommonSettings::photonTurnbasedAppId; }
    void SetPhotonTurnbasedAppId(const FString & photonTurnbasedAppId) override { PlayFabCommon::PlayFabCommonSettings::photonTurnbasedAppId = photonTurnbasedAppId; }

    FString GetPhotonChatAppId() const override { return PlayFabCommon::PlayFabCommonSettings::photonChatAppId; }
    void SetPhotonChatAppId(const FString & photonChatAppId) override { PlayFabCommon::PlayFabCommonSettings::photonChatAppId = photonChatAppId; }

    FString GeneratePfUrl(const FString& urlPath) const override { return PlayFabCommon::PlayFabCommonSettings::GeneratePfUrl(urlPath); }
};

void FPlayFabCommonModule::StartupModule()
{
    // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
    RegisterSettings();
}

void FPlayFabCommonModule::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
    UnregisterSettings();
}

void FPlayFabCommonModule::RegisterSettings()
{
#if WITH_EDITOR
    if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    {
        ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project", "Plugins", "PlayFab",
            LOCTEXT("PlayFabSettingsName", "PlayFab"),
            LOCTEXT("PlayFabSettingsDescription", "Configure the PlayFab plugin"),
            GetMutableDefault<UPlayFabRuntimeSettings>()
        );
    }
#endif // WITH_EDITOR
}

void FPlayFabCommonModule::UnregisterSettings()
{
#if WITH_EDITOR
    if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    {
        SettingsModule->UnregisterSettings("Project", "Plugins", "PlayFab");
    }
#endif
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPlayFabCommonModule, PlayFabCommon)
