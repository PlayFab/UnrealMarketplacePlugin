//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "CoreMinimal.h"
#include "PlayFabCommonSettings.h"
#include "PlayFabAuthenticationContext.generated.h"

/**
* Container for PlayFab authentication credentials data.
*/
UCLASS(BlueprintType)
class PLAYFABCOMMON_API UPlayFabAuthenticationContext : public UObject
{
    GENERATED_BODY()
public:
    UPlayFabAuthenticationContext()
    {
#ifndef DISABLE_PLAYFABCLIENT_API
        ClientSessionTicket = PlayFabCommon::PlayFabCommonSettings::clientSessionTicket;
#endif
#ifndef DISABLE_PLAYFABENTITY_API
        EntityToken = PlayFabCommon::PlayFabCommonSettings::entityToken;
#endif
#if defined(ENABLE_PLAYFABSERVER_API) || defined(ENABLE_PLAYFABADMIN_API)
        DeveloperSecretKey = PlayFabCommon::PlayFabCommonSettings::developerSecretKey;
#endif
    }

    // Get the client session ticket that is used as an authentication token in many PlayFab API methods.
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "PlayFab | Core")
        FString& GetClientSessionTicket()
    {
#ifdef DISABLE_PLAYFABCLIENT_API
        checkf(false, TEXT("ClientSessionTicket is disabled because DISABLE_PLAYFABCLIENT_API is set."));
#endif
        return ClientSessionTicket;
    }

    // Get the client session ticket that is used as an authentication token in many PlayFab API methods.
    const FString& GetClientSessionTicket() const
    {
#ifdef DISABLE_PLAYFABCLIENT_API
        checkf(false, TEXT("ClientSessionTicket is disabled because DISABLE_PLAYFABCLIENT_API is set."));
#endif
        return ClientSessionTicket;
    }

    // Set the client session ticket that is used as an authentication token in many PlayFab API methods.
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Core")
        void SetClientSessionTicket(FString InTicket)
    {
#ifdef DISABLE_PLAYFABCLIENT_API
        checkf(false, TEXT("ClientSessionTicket is disabled because DISABLE_PLAYFABCLIENT_API is set."));
#endif
        ClientSessionTicket = InTicket;
    }

    // Get the user's entity token. Entity tokens are required by all Entity API methods.
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "PlayFab | Core")
        FString& GetEntityToken()
    {
#ifdef DISABLE_PLAYFABENTITY_API
        checkf(false, TEXT("EntityToken is disabled because DISABLE_PLAYFABENTITY_API is set."));
#endif
        return EntityToken;
    }

    // Get the user's entity token. Entity tokens are required by all Entity API methods.
    const FString& GetEntityToken() const
    {
#ifdef DISABLE_PLAYFABENTITY_API
        checkf(false, TEXT("EntityToken is disabled because DISABLE_PLAYFABENTITY_API is set."));
#endif
        return EntityToken;
    }

    // Set the user's entity token. Entity tokens are required by all Entity API methods.
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Core")
        void SetEntityToken(FString InToken)
    {
#ifdef DISABLE_PLAYFABENTITY_API
        checkf(false, TEXT("EntityToken is disabled because DISABLE_PLAYFABENTITY_API is set."));
#endif
        EntityToken = InToken;
    }

    // Get the developer secret key. These keys can be used in development environments.
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "PlayFab | Core")
        FString& GetDeveloperSecretKey()
    {
#if defined(ENABLE_PLAYFABSERVER_API) || defined(ENABLE_PLAYFABADMIN_API)
        return DeveloperSecretKey;
#endif

        checkf(false, TEXT("Cannot call GetDeveloperSecretKey in a non-developer build!"));
        return DeveloperSecretKey;
    }

    // Get the developer secret key. These keys can be used in development environments.
    const FString& GetDeveloperSecretKey() const
    {
#if defined(ENABLE_PLAYFABSERVER_API) || defined(ENABLE_PLAYFABADMIN_API)
        return DeveloperSecretKey;
#endif

        checkf(false, TEXT("Cannot call GetDeveloperSecretKey in a non-developer build!"));
        return DeveloperSecretKey;
    }

    // Set the developer secret key. These keys can be used in development environments.
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Core")
        void SetDeveloperSecretKey(FString InKey)
    { 
#if defined(ENABLE_PLAYFABSERVER_API) || defined(ENABLE_PLAYFABADMIN_API)
        DeveloperSecretKey = MoveTemp(InKey);
        return;
#endif

        checkf(false, TEXT("Cannot call SetDeveloperSecretKey in a non-developer build!"));
    }

    // Get the player's unique PlayFabId.
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "PlayFab | Core")
        FString& GetPlayFabId()
    {
        return PlayFabId;
    }

    // Get the player's unique PlayFabId.
    const FString& GetPlayFabId() const
    {
        return PlayFabId;
    }

    // Set the player's unique PlayFabId.
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Core")
        void SetPlayFabId(FString InKey)
    {
        PlayFabId = InKey;
    }

    // Reset all fields
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Core")
        void ForgetAllCredentials()
    {
        ClientSessionTicket.Empty();
        EntityToken.Empty();
        DeveloperSecretKey.Empty();
        PlayFabId.Empty();
    }

private: 
    // Client session ticket that is used as an authentication token in many PlayFab API methods.
    UPROPERTY()
    FString ClientSessionTicket;

    // User's entity token. Entity tokens are required by all Entity API methods.
    UPROPERTY()
    FString EntityToken;

    // Developer secret key. These keys can be used in development environments.
    UPROPERTY()
    FString DeveloperSecretKey;

    // The player's unique PlayFabId.
    UPROPERTY()
    FString PlayFabId;
};
