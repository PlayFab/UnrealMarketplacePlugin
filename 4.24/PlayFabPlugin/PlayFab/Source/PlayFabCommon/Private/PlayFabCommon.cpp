//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "PlayFabCommon.h"

#if WITH_EDITOR
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#endif // WITH_EDITOR

#include "PlayFabCommonSettings.h"
#include "PlayFabRuntimeSettings.h"

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

    /** Callback for when the settings were saved. */
    bool HandleSettingsSaved();

    FString GetSdkVersion() const override { return PlayFabCommon::PlayFabCommonSettings::sdkVersion; }
    FString GetBuildIdentifier() const override { return PlayFabCommon::PlayFabCommonSettings::buildIdentifier; }
    FString GetVersionString() const override { return PlayFabCommon::PlayFabCommonSettings::versionString; }
    FString GetVerticalName() const override { return PlayFabCommon::PlayFabCommonSettings::verticalName; }

    FString GetAD_TYPE_IDFA() const override { return PlayFabCommon::PlayFabCommonSettings::AD_TYPE_IDFA; }
    FString GetAD_TYPE_ANDROID_ID() const override { return PlayFabCommon::PlayFabCommonSettings::AD_TYPE_ANDROID_ID; }

    FString GetServerURL() const override { return PlayFabCommon::PlayFabCommonSettings::serverURL; }
    FString GetProductionEnvironmentURL() const override { return PlayFabCommon::PlayFabCommonSettings::productionEnvironmentURL; }
    FString GetTitleId() const override { return (PlayFabCommon::PlayFabCommonSettings::titleId.IsEmpty() ? GetDefault<UPlayFabRuntimeSettings>()->TitleId : PlayFabCommon::PlayFabCommonSettings::titleId); }
    FString GetClientSessionTicket() const override { return PlayFabCommon::PlayFabCommonSettings::clientSessionTicket; }
    FString GetDeveloperSecretKey() const override { return (PlayFabCommon::PlayFabCommonSettings::developerSecretKey.IsEmpty() ? GetDefault<UPlayFabRuntimeSettings>()->DeveloperSecretKey : PlayFabCommon::PlayFabCommonSettings::developerSecretKey); }
    FString GetEntityToken() const override { return PlayFabCommon::PlayFabCommonSettings::entityToken; }
    FString GetAdvertisingIdType() const override { return PlayFabCommon::PlayFabCommonSettings::advertisingIdType; }
    FString GetAdvertisingIdValue() const override { return PlayFabCommon::PlayFabCommonSettings::advertisingIdValue; }
    bool GetDisableAdvertising() const override { return PlayFabCommon::PlayFabCommonSettings::disableAdvertising; }

    void SetServerURL(const FString& serverURL) override { PlayFabCommon::PlayFabCommonSettings::serverURL = serverURL; }
    void SetProductionEnvironmentURL(const FString& productionEnvironmentURL) override { PlayFabCommon::PlayFabCommonSettings::productionEnvironmentURL = productionEnvironmentURL; }
    void SetTitleId(const FString& titleId) override { PlayFabCommon::PlayFabCommonSettings::titleId = titleId; }
    void SetClientSessionTicket(const FString& clientSessionTicket) override { PlayFabCommon::PlayFabCommonSettings::clientSessionTicket = clientSessionTicket; }
    void SetDeveloperSecretKey(const FString& developerSecretKey) override { PlayFabCommon::PlayFabCommonSettings::developerSecretKey = developerSecretKey; }
    void SetEntityToken(const FString& entityToken) override { PlayFabCommon::PlayFabCommonSettings::entityToken = entityToken; }
    void SetAdvertisingIdType(const FString& advertisingIdType) override { PlayFabCommon::PlayFabCommonSettings::advertisingIdType = advertisingIdType; }
    void SetAdvertisingIdValue(const FString& advertisingIdValue) override { PlayFabCommon::PlayFabCommonSettings::advertisingIdValue = advertisingIdValue; }
    void SetDisableAdvertising(bool disableAdvertising) override { PlayFabCommon::PlayFabCommonSettings::disableAdvertising = disableAdvertising; }

    FString GetPlayFabApiSecretKey() const override { return PlayFabCommon::PlayFabCommonSettings::playFabApiSecretKey; }
    void SetPlayFabApiSecretKey(const FString & playFabApiSecretKey) override { PlayFabCommon::PlayFabCommonSettings::playFabApiSecretKey = playFabApiSecretKey; }

    FString GetPhotonRealtimeAppId() const override { return PlayFabCommon::PlayFabCommonSettings::photonRealtimeAppId; }
    void SetPhotonRealtimeAppId(const FString & photonRealtimeAppId) override { PlayFabCommon::PlayFabCommonSettings::photonRealtimeAppId = photonRealtimeAppId; }

    FString GetPhotonTurnbasedAppId() const override { return PlayFabCommon::PlayFabCommonSettings::photonTurnbasedAppId; }
    void SetPhotonTurnbasedAppId(const FString & photonTurnbasedAppId) override { PlayFabCommon::PlayFabCommonSettings::photonTurnbasedAppId = photonTurnbasedAppId; }

    FString GetPhotonChatAppId() const override { return PlayFabCommon::PlayFabCommonSettings::photonChatAppId; }
    void SetPhotonChatAppId(const FString & photonChatAppId) override { PlayFabCommon::PlayFabCommonSettings::photonChatAppId = photonChatAppId; }

    FString GetUrl(const FString& callPath) const override { return PlayFabCommon::PlayFabCommonSettings::getURL(callPath); }
};

void FPlayFabCommonModule::StartupModule()
{
    // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
    RegisterSettings();
    HandleSettingsSaved();
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

        if (SettingsSection.IsValid())
        {
            SettingsSection->OnModified().BindRaw(this, &FPlayFabCommonModule::HandleSettingsSaved);
        }
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

bool FPlayFabCommonModule::HandleSettingsSaved()
{
    // copy to the internal structure
    PlayFabCommon::PlayFabCommonSettings::serverURL = FString(); // flush the previous Server URL
    PlayFabCommon::PlayFabCommonSettings::productionEnvironmentURL = GetDefault<UPlayFabRuntimeSettings>()->ProductionEnvironmentURL;
    PlayFabCommon::PlayFabCommonSettings::titleId = GetDefault<UPlayFabRuntimeSettings>()->TitleId;
    PlayFabCommon::PlayFabCommonSettings::developerSecretKey = GetDefault<UPlayFabRuntimeSettings>()->DeveloperSecretKey;

    return true;
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPlayFabCommonModule, PlayFabCommon)
