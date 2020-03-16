//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogPlayFabCpp, Log, All);

// forward declaration of classes
namespace PlayFab
{
    template<typename T>
    TSharedPtr<T> MakeSharedUObject()
    {    
#if WITH_EDITOR
        return TSharedPtr<T>(NewObject<T>((UObject*)GetTransientPackage(), NAME_None, RF_Standalone),
        [](T* Instance)
        {
            // Recommended way of destroying UObjects according to https://udn.unrealengine.com/questions/402414/view.html
            Instance->ClearFlags(RF_Standalone);
        });
#else
        return TSharedPtr<T>(NewObject<T>((UObject*)GetTransientPackage(), NAME_None, RF_StrongRefOnFrame),
        [](T* Instance)
        {
            Instance->ClearFlags(RF_StrongRefOnFrame);
        });
#endif
    }

    class UPlayFabAdminAPI;
    class UPlayFabClientAPI;
    class UPlayFabMatchmakerAPI;
    class UPlayFabServerAPI;
    class UPlayFabAuthenticationAPI;
    class UPlayFabCloudScriptAPI;
    class UPlayFabDataAPI;
    class UPlayFabEventsAPI;
    class UPlayFabGroupsAPI;
    class UPlayFabLocalizationAPI;
    class UPlayFabMultiplayerAPI;
    class UPlayFabProfilesAPI;
}

typedef TSharedPtr<class PlayFab::UPlayFabAdminAPI> PlayFabAdminPtr;
typedef TSharedPtr<class PlayFab::UPlayFabClientAPI> PlayFabClientPtr;
typedef TSharedPtr<class PlayFab::UPlayFabMatchmakerAPI> PlayFabMatchmakerPtr;
typedef TSharedPtr<class PlayFab::UPlayFabServerAPI> PlayFabServerPtr;
typedef TSharedPtr<class PlayFab::UPlayFabAuthenticationAPI> PlayFabAuthenticationPtr;
typedef TSharedPtr<class PlayFab::UPlayFabCloudScriptAPI> PlayFabCloudScriptPtr;
typedef TSharedPtr<class PlayFab::UPlayFabDataAPI> PlayFabDataPtr;
typedef TSharedPtr<class PlayFab::UPlayFabEventsAPI> PlayFabEventsPtr;
typedef TSharedPtr<class PlayFab::UPlayFabGroupsAPI> PlayFabGroupsPtr;
typedef TSharedPtr<class PlayFab::UPlayFabLocalizationAPI> PlayFabLocalizationPtr;
typedef TSharedPtr<class PlayFab::UPlayFabMultiplayerAPI> PlayFabMultiplayerPtr;
typedef TSharedPtr<class PlayFab::UPlayFabProfilesAPI> PlayFabProfilesPtr;

/**
* The public interface to this module.  In most cases, this interface is only public to sibling modules
* within this plugin.
*/
class IPlayFabModuleInterface : public IModuleInterface
{
public:

    /**
    * Singleton-like access to this module's interface.  This is just for convenience!
    * Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
    *
    * @return Returns singleton instance, loading the module on demand if needed
    */
    static inline IPlayFabModuleInterface& Get()
    {
        if (IsAvailable())
        {
            return FModuleManager::GetModuleChecked< IPlayFabModuleInterface >("PlayFabCpp");
        }
        return FModuleManager::LoadModuleChecked< IPlayFabModuleInterface >("PlayFabCpp");
    }

    /**
    * Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
    *
    * @return True if the module is loaded and ready to use
    */
    static inline bool IsAvailable()
    {
        return FModuleManager::Get().IsModuleLoaded("PlayFabCpp");
    }

    virtual FString GetTitleId() const = 0;
        virtual PlayFabAdminPtr GetAdminAPI() const = 0;
    virtual PlayFabClientPtr GetClientAPI() const = 0;
    virtual PlayFabMatchmakerPtr GetMatchmakerAPI() const = 0;
    virtual PlayFabServerPtr GetServerAPI() const = 0;
    virtual PlayFabAuthenticationPtr GetAuthenticationAPI() const = 0;
    virtual PlayFabCloudScriptPtr GetCloudScriptAPI() const = 0;
    virtual PlayFabDataPtr GetDataAPI() const = 0;
    virtual PlayFabEventsPtr GetEventsAPI() const = 0;
    virtual PlayFabGroupsPtr GetGroupsAPI() const = 0;
    virtual PlayFabLocalizationPtr GetLocalizationAPI() const = 0;
    virtual PlayFabMultiplayerPtr GetMultiplayerAPI() const = 0;
    virtual PlayFabProfilesPtr GetProfilesAPI() const = 0;

};
