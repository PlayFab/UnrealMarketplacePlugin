//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "PlayFab.h"

#include "PlayFabSettings.h"

// Api's
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabMatchmakerAPI.h"
#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabAuthenticationAPI.h"
#include "Core/PlayFabCloudScriptAPI.h"
#include "Core/PlayFabDataAPI.h"
#include "Core/PlayFabEventsAPI.h"
#include "Core/PlayFabGroupsAPI.h"
#include "Core/PlayFabLocalizationAPI.h"
#include "Core/PlayFabProfilesAPI.h"

DEFINE_LOG_CATEGORY(LogPlayFab);

class FPlayFabModule : public IPlayFabModuleInterface
{
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    FString GetTitleId() const override { return PlayFab::PlayFabSettings::GetTitleId(); };
    
    PlayFabAdminPtr GetAdminAPI() const override { return AdminAPI; };
    PlayFabClientPtr GetClientAPI() const override { return ClientAPI; };
    PlayFabMatchmakerPtr GetMatchmakerAPI() const override { return MatchmakerAPI; };
    PlayFabServerPtr GetServerAPI() const override { return ServerAPI; };
    PlayFabAuthenticationPtr GetAuthenticationAPI() const override { return AuthenticationAPI; };
    PlayFabCloudScriptPtr GetCloudScriptAPI() const override { return CloudScriptAPI; };
    PlayFabDataPtr GetDataAPI() const override { return DataAPI; };
    PlayFabEventsPtr GetEventsAPI() const override { return EventsAPI; };
    PlayFabGroupsPtr GetGroupsAPI() const override { return GroupsAPI; };
    PlayFabLocalizationPtr GetLocalizationAPI() const override { return LocalizationAPI; };
    PlayFabProfilesPtr GetProfilesAPI() const override { return ProfilesAPI; };

    PlayFabAdminPtr AdminAPI;
    PlayFabClientPtr ClientAPI;
    PlayFabMatchmakerPtr MatchmakerAPI;
    PlayFabServerPtr ServerAPI;
    PlayFabAuthenticationPtr AuthenticationAPI;
    PlayFabCloudScriptPtr CloudScriptAPI;
    PlayFabDataPtr DataAPI;
    PlayFabEventsPtr EventsAPI;
    PlayFabGroupsPtr GroupsAPI;
    PlayFabLocalizationPtr LocalizationAPI;
    PlayFabProfilesPtr ProfilesAPI;


};

void FPlayFabModule::StartupModule()
{
    // create the API
	
        AdminAPI = MakeShareable(new PlayFab::UPlayFabAdminAPI());
        ClientAPI = MakeShareable(new PlayFab::UPlayFabClientAPI());
        MatchmakerAPI = MakeShareable(new PlayFab::UPlayFabMatchmakerAPI());
        ServerAPI = MakeShareable(new PlayFab::UPlayFabServerAPI());
        AuthenticationAPI = MakeShareable(new PlayFab::UPlayFabAuthenticationAPI());
        CloudScriptAPI = MakeShareable(new PlayFab::UPlayFabCloudScriptAPI());
        DataAPI = MakeShareable(new PlayFab::UPlayFabDataAPI());
        EventsAPI = MakeShareable(new PlayFab::UPlayFabEventsAPI());
        GroupsAPI = MakeShareable(new PlayFab::UPlayFabGroupsAPI());
        LocalizationAPI = MakeShareable(new PlayFab::UPlayFabLocalizationAPI());
        ProfilesAPI = MakeShareable(new PlayFab::UPlayFabProfilesAPI());
}

void FPlayFabModule::ShutdownModule()
{
    
}

IMPLEMENT_MODULE(FPlayFabModule, PlayFabCpp)
