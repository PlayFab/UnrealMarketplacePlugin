//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Profiles
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabRequestCommon.h"
#include "PlayFabLoginResultCommon.h"
#include "PlayFabProfilesModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Profiles API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////

/**
 * Retrieves the title access policy that is used before the profile's policy is inspected during a request. If never
 * customized this will return the default starter policy built by PlayFab.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FProfilesGetGlobalPolicyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProfilesGetGlobalPolicyResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The permissions that govern access to all entities under this title or namespace. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        TArray<UPlayFabJsonObject*> Permissions;
};

/**
 * Given an entity type and entity identifier will retrieve the profile from the entity store. If the profile being
 * retrieved is the caller's, then the read operation is consistent, if not it is an inconsistent read. An inconsistent
 * read means that we do not guarantee all committed writes have occurred before reading the profile, allowing for a stale
 * read. If consistency is important the Version Number on the result can be used to compare which version of the profile
 * any reader has.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FProfilesGetEntityProfileRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Determines whether the objects will be returned as an escaped JSON string or as a un-escaped JSON object. Default is
     * JSON string.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        bool DataAsObject = false;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProfilesGetEntityProfileResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Entity profile */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        UPlayFabJsonObject* Profile = nullptr;
};

/**
 * Given a set of entity types and entity identifiers will retrieve all readable profiles properties for the caller.
 * Profiles that the caller is not allowed to read will silently not be included in the results.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FProfilesGetEntityProfilesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Determines whether the objects will be returned as an escaped JSON string or as a un-escaped JSON object. Default is
     * JSON string.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        bool DataAsObject = false;
    /** Entity keys of the profiles to load. Must be between 1 and 25 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        TArray<UPlayFabJsonObject*> Entities;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProfilesGetEntityProfilesResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Entity profiles */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        TArray<UPlayFabJsonObject*> Profiles;
};

/** Given a master player account id (PlayFab ID), returns all title player accounts associated with it. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Master player account ids. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        FString MasterPlayerAccountIds;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Optional id of title to get players from, required if calling using a master_player_account. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        FString TitleId;
    /** Dictionary of master player ids mapped to title player entity keys and id pairs */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        UPlayFabJsonObject* TitlePlayerAccounts = nullptr;
};

/**
 * Updates the title access policy that is used before the profile's policy is inspected during a request. Policies are
 * compiled and cached for several minutes so an update here may not be reflected in behavior for a short time.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FProfilesSetGlobalPolicyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The permissions that govern access to all entities under this title or namespace. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        TArray<UPlayFabJsonObject*> Permissions;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProfilesSetGlobalPolicyResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * Given an entity profile, will update its language to the one passed in if the profile's version is equal to the one
 * passed in.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FProfilesSetProfileLanguageRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The expected version of a profile to perform this update on */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        int32 ExpectedVersion = 0;
    /** The language to set on the given entity. Deletes the profile's language if passed in a null string. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        FString Language;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProfilesSetProfileLanguageResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The type of operation that occured on the profile's language */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        EOperationTypes OperationResult;
    /** The updated version of the profile after the language update */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        int32 VersionNumber = 0;
};

/**
 * This will set the access policy statements on the given entity profile. This is not additive, any existing statements
 * will be replaced with the statements in this request.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FProfilesSetEntityProfilePolicyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The statements to include in the access policy. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        TArray<UPlayFabJsonObject*> Statements;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProfilesSetEntityProfilePolicyResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * The permissions that govern access to this entity profile and its properties. Only includes permissions set on this
     * profile, not global statements from titles and namespaces.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        TArray<UPlayFabJsonObject*> Permissions;
};

