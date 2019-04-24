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

USTRUCT(BlueprintType)
struct PLAYFAB_API FAuthenticationActivateAPIKeyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the entity API key to activate. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | API Keys Models")
        FString APIKeyId;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | API Keys Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAuthenticationActivateAPIKeyResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAuthenticationCreateAPIKeyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | API Keys Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAuthenticationCreateAPIKeyResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The entity id and type. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | API Keys Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The created API key */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | API Keys Models")
        UPlayFabJsonObject* Key = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAuthenticationDeactivateAPIKeyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the entity API key to activate. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | API Keys Models")
        FString APIKeyId;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | API Keys Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAuthenticationDeactivateAPIKeyResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAuthenticationDeleteAPIKeyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the entity API key to delete. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | API Keys Models")
        FString APIKeyId;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | API Keys Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAuthenticationDeleteAPIKeyResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAuthenticationGetAPIKeysRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | API Keys Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAuthenticationGetAPIKeysResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The entity id and type. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | API Keys Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The API keys associated with the given entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Authentication | API Keys Models")
        TArray<UPlayFabJsonObject*> Keys;
};


///////////////////////////////////////////////////////
// Authentication
//////////////////////////////////////////////////////

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
    /** The entity to perform this action on. */
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

