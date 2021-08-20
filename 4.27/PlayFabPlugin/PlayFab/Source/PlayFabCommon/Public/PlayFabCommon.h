//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogPlayFabCommon, Log, All);

class IPlayFabCommonModuleInterface : public IModuleInterface
{
public:

    /**
    * Singleton-like access to this module's interface.  This is just for convenience!
    * Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
    *
    * @return Returns singleton instance, loading the module on demand if needed
    */
    static inline IPlayFabCommonModuleInterface& Get()
    {
        if (IsAvailable())
        {
            return FModuleManager::GetModuleChecked<IPlayFabCommonModuleInterface>("PlayFabCommon");
        }
        return FModuleManager::LoadModuleChecked<IPlayFabCommonModuleInterface>("PlayFabCommon");
    }

    /**
    * Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
    *
    * @return True if the module is loaded and ready to use
    */
    static inline bool IsAvailable()
    {
        return FModuleManager::Get().IsModuleLoaded("PlayFabCommon");
    }

    virtual FString GetSdkVersion() const = 0;
    virtual FString GetBuildIdentifier() const = 0;
    virtual FString GetVersionString() const = 0;

    virtual FString GetClientSessionTicket() const = 0;
    virtual FString GetEntityToken() const = 0;

    virtual void SetClientSessionTicket(const FString& clientSessionTicket) = 0;
    virtual void SetEntityToken(const FString& entityToken) = 0;

    virtual FString GetPhotonRealtimeAppId() const = 0;
    virtual void SetPhotonRealtimeAppId(const FString & photonRealtimeAppId) = 0;

    virtual FString GetPhotonTurnbasedAppId() const = 0;
    virtual void SetPhotonTurnbasedAppId(const FString & photonTurnbasedAppId) = 0;

    virtual FString GetPhotonChatAppId() const = 0;
    virtual void SetPhotonChatAppId(const FString & photonChatAppId) = 0;

    virtual FString GeneratePfUrl(const FString& urlPath) const = 0;
};
