//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "CoreMinimal.h"
#include "PlayFabCommonSettings.h"
#include "PlayFabCommon/Public/PlayFabRuntimeSettings.h"
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
        ClientSessionTicket = PlayFabCommon::PlayFabCommonSettings::clientSessionTicket;
        EntityToken = PlayFabCommon::PlayFabCommonSettings::entityToken;
        DeveloperSecretKey = GetDefault<UPlayFabRuntimeSettings>()->DeveloperSecretKey;
        ClientAdminSecurityCheck();
    }

    // Get the client session ticket that is used as an authentication token in many PlayFab API methods.
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "PlayFab | Core")
        FString& GetClientSessionTicket()
    {
        ClientAdminSecurityCheck();
        return ClientSessionTicket;
    }

    // Get the client session ticket that is used as an authentication token in many PlayFab API methods.
    const FString& GetClientSessionTicket() const
    {
        ClientAdminSecurityCheck();
        return ClientSessionTicket;
    }

    // Set the client session ticket that is used as an authentication token in many PlayFab API methods.
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Core")
        void SetClientSessionTicket(FString InTicket)
    {
        ClientAdminSecurityCheck();
        ClientSessionTicket = InTicket;
    }

    // Get the user's entity token. Entity tokens are required by all Entity API methods.
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "PlayFab | Core")
        FString& GetEntityToken()
    {
        return EntityToken;
    }

    // Get the user's entity token. Entity tokens are required by all Entity API methods.
    const FString& GetEntityToken() const
    {
        return EntityToken;
    }

    // Set the user's entity token. Entity tokens are required by all Entity API methods.
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Core")
        void SetEntityToken(FString InToken)
    {
        EntityToken = InToken;
    }

    // Get the developer secret key. These keys can be used in server environments.
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "PlayFab | Core")
        FString& GetDeveloperSecretKey()
    {
        ClientAdminSecurityCheck();
        return DeveloperSecretKey;
    }

    // Get the developer secret key. These keys can be used in server environments.
    const FString& GetDeveloperSecretKey() const
    {
        ClientAdminSecurityCheck();
        return DeveloperSecretKey;
    }

    // Set the developer secret key. These keys can be used in server environments.
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Core")
        void SetDeveloperSecretKey(FString InKey)
    {
        ClientAdminSecurityCheck();
        DeveloperSecretKey = InKey;
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

    // Check if things are in the correct order
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Core")
    void ClientAdminSecurityCheck() const
    {
        checkf(
            DeveloperSecretKey.Len() == 0 || ClientSessionTicket.Len() == 0, // The condition is true/safe if one or the other is length zero
            TEXT("For title security, you cannot set the DeveloperSecretKey on a process which uses a Client Login")
        );
    }

private: 
    // Client session ticket that is used as an authentication token in many PlayFab API methods.
    UPROPERTY()
    FString ClientSessionTicket;

    // User's entity token. Entity tokens are required by all Entity API methods.
    UPROPERTY()
    FString EntityToken;

    // Developer secret key. These keys can be used in server environments.
    UPROPERTY()
    FString DeveloperSecretKey;

    // The player's unique PlayFabId.
    UPROPERTY()
    FString PlayFabId;
};
