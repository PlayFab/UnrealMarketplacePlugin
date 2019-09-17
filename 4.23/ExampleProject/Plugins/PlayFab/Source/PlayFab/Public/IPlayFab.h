//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "Modules/ModuleManager.h"
#include "PlayFabCommon.h"

/**
* The public interface to this module.  In most cases, this interface is only public to sibling modules
* within this plugin.
*/
class IPlayFab : public IModuleInterface
{
public:
    /**
    * Singleton-like access to this module's interface.  This is just for convenience!
    * Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
    *
    * @return Returns singleton instance, loading the module on demand if needed
    */

    static inline IPlayFab& Get()
    {
        if (IsAvailable())
        {
            return FModuleManager::GetModuleChecked< IPlayFab >("PlayFab");
        }
        return FModuleManager::LoadModuleChecked< IPlayFab >("PlayFab");
    }

    /**
    * Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
    *
    * @return True if the module is loaded and ready to use
    */
    static inline bool IsAvailable()
    {
        return FModuleManager::Get().IsModuleLoaded("PlayFab");
    }

    inline FString getGameTitleId() const
    {
        return IPlayFabCommonModuleInterface::Get().GetTitleId();
    }
    inline void setGameTitleId(const FString& NewGameTitleId)
    {
        IPlayFabCommonModuleInterface::Get().SetTitleId(NewGameTitleId);
    }

    inline bool IsClientLoggedIn() const
    {
        return getSessionTicket().Len() > 0;
    }
    inline FString getSessionTicket() const
    {
        return IPlayFabCommonModuleInterface::Get().GetClientSessionTicket();
    }
    inline void setSessionTicket(const FString& NewSessionTicket)
    {
        IPlayFabCommonModuleInterface::Get().SetClientSessionTicket(NewSessionTicket);
    }

    inline FString getEntityToken() const
    {
        return IPlayFabCommonModuleInterface::Get().GetEntityToken();
    }
    inline void setEntityToken(const FString& NewEntityToken)
    {
        IPlayFabCommonModuleInterface::Get().SetEntityToken(NewEntityToken);
    }

    inline FString getSecretApiKey() const
    {
        return IPlayFabCommonModuleInterface::Get().GetPlayFabApiSecretKey();
    }
    inline void setApiSecretKey(const FString& NewSecretApiKey)
    {
        IPlayFabCommonModuleInterface::Get().SetPlayFabApiSecretKey(NewSecretApiKey);
    }

    inline FString getVersionString() const
    {
        return IPlayFabCommonModuleInterface::Get().GetVersionString();
    }

    inline FString getVerticalName() const
    {
        return IPlayFabCommonModuleInterface::Get().GetVerticalName();
    }

    inline FString getBuildIdentifier() const
    {
        return IPlayFabCommonModuleInterface::Get().GetBuildIdentifier();
    }

    inline FString getAD_TYPE_ANDROID_ID() const
    {
        return IPlayFabCommonModuleInterface::Get().GetAD_TYPE_ANDROID_ID();
    }

    inline FString getAD_TYPE_IDFA() const
    {
        return IPlayFabCommonModuleInterface::Get().GetAD_TYPE_IDFA();
    }

    inline FString getAdvertisingIdType() const
    {
        return IPlayFabCommonModuleInterface::Get().GetAdvertisingIdType();
    }

    inline void setAdvertisingIdType(FString advertisingIdType)
    {
        return IPlayFabCommonModuleInterface::Get().SetAdvertisingIdType(advertisingIdType);
    }

    inline FString getAdvertisingIdValue() const
    {
        return IPlayFabCommonModuleInterface::Get().GetAdvertisingIdValue();
    }

    inline void setAdvertisingIdValue(FString advertisingIdValue)
    {
        return IPlayFabCommonModuleInterface::Get().SetAdvertisingIdValue(advertisingIdValue);
    }

    inline FString getPhotonRealtimeAppId() const
    {
        return IPlayFabCommonModuleInterface::Get().GetPhotonRealtimeAppId();
    }

    inline void setPhotonRealtimeAppId(const FString& photonRealtimeAppId)
    {
        IPlayFabCommonModuleInterface::Get().SetPhotonRealtimeAppId(photonRealtimeAppId);
    }

    inline FString getPhotonTurnbasedAppId() const
    {
        return IPlayFabCommonModuleInterface::Get().GetPhotonTurnbasedAppId();
    }

    inline void setPhotonTurnbasedAppId(const FString& photonTurnbasedAppId)
    {
        IPlayFabCommonModuleInterface::Get().SetPhotonTurnbasedAppId(photonTurnbasedAppId);
    }

    inline FString getPhotonChatAppId() const
    {
        return IPlayFabCommonModuleInterface::Get().GetPhotonChatAppId();
    }

    inline void setPhotonChatAppId(const FString& photonChatAppId)
    {
        IPlayFabCommonModuleInterface::Get().SetPhotonChatAppId(photonChatAppId);
    }

    inline bool getDisableAdvertising() const
    {
        return IPlayFabCommonModuleInterface::Get().GetDisableAdvertising();
    }

    inline FString getUrl(const FString& callPath) const
    {
        return IPlayFabCommonModuleInterface::Get().GetUrl(callPath);
    }

    inline int32 GetPendingCallCount()
    {
        int32 output;
        pendingCallLock.Lock();
        output = pendingCalls;
        pendingCallLock.Unlock();
        return output;
    }
    inline void ModifyPendingCallCount(int32 delta)
    {
        pendingCallLock.Lock();
        pendingCalls += delta;
        pendingCallLock.Unlock();
    }

private:
    FCriticalSection pendingCallLock;
    int32 pendingCalls;
};
