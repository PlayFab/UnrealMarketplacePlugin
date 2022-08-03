//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Authentication
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabRequestCommon.h"
#include "PlayFabLoginResultCommon.h"
#include "PlayFabAuthenticationModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Authentication API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// API Keys
//////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Authentication
//////////////////////////////////////////////////////

/**
 * Delete a game_server entity. The caller can be the game_server entity attempting to delete itself. Or a title entity
 * attempting to delete game_server entities for this title.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAuthenticationDeleteRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The game_server entity to be removed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | Authentication Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAuthenticationEmptyResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * This API must be called with X-SecretKey, X-Authentication or X-EntityToken headers. An optional EntityKey may be
 * included to attempt to set the resulting EntityToken to a specific entity, however the entity must be a relation of the
 * caller, such as the master_player_account of a character. If sending X-EntityToken the account will be marked as freshly
 * logged in and will issue a new token. If using X-Authentication or X-EntityToken the header must still be valid and
 * cannot be expired or revoked.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAuthenticationGetEntityTokenRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | Authentication Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAuthenticationGetEntityTokenResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The entity id and type. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | Authentication Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The token used to set X-EntityToken for all entity based API calls. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | Authentication Models")
        FString EntityToken;
    /** The time the token will expire, if it is an expiring token, in UTC. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | Authentication Models")
        FString TokenExpiration;
};

/** Given an entity token, validates that it hasn't expired or been revoked and will return details of the owner. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAuthenticationValidateEntityTokenRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Client EntityToken */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | Authentication Models")
        FString EntityToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAuthenticationValidateEntityTokenResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The entity id and type. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | Authentication Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The authenticated device for this entity, for the given login */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | Authentication Models")
        EIdentifiedDeviceType IdentifiedDeviceType = StaticCast<EIdentifiedDeviceType>(0);
    /** The identity provider for this entity, for the given login */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | Authentication Models")
        ELoginIdentityProvider IdentityProvider = StaticCast<ELoginIdentityProvider>(0);
    /** The ID issued by the identity provider, e.g. a XUID on Xbox Live */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | Authentication Models")
        FString IdentityProviderIssuedId;
    /** The lineage of this profile. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | Authentication Models")
        UPlayFabJsonObject* Lineage = nullptr;
};

