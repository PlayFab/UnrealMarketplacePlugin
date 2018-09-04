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
#include "PlayFabProfilesModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Profiles API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FProfilesGetGlobalPolicyRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FProfilesGetGlobalPolicyResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** The permissions that govern access to all entities under this title or namespace. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        TArray<UPlayFabJsonObject*> Permissions;
};

USTRUCT(BlueprintType)
struct FProfilesGetEntityProfileRequest
{
    GENERATED_USTRUCT_BODY()
public:
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
struct FProfilesGetEntityProfileResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** Entity profile */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        UPlayFabJsonObject* Profile = nullptr;
};

USTRUCT(BlueprintType)
struct FProfilesGetEntityProfilesRequest
{
    GENERATED_USTRUCT_BODY()
public:
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
struct FProfilesGetEntityProfilesResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** Entity profiles */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        TArray<UPlayFabJsonObject*> Profiles;
};

USTRUCT(BlueprintType)
struct FProfilesSetGlobalPolicyRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The permissions that govern access to all entities under this title or namespace. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        TArray<UPlayFabJsonObject*> Permissions;
};

USTRUCT(BlueprintType)
struct FProfilesSetGlobalPolicyResponse
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FProfilesSetProfileLanguageRequest
{
    GENERATED_USTRUCT_BODY()
public:
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
struct FProfilesSetProfileLanguageResponse
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

USTRUCT(BlueprintType)
struct FProfilesSetEntityProfilePolicyRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The statements to include in the access policy. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Profiles | Account Management Models")
        TArray<UPlayFabJsonObject*> Statements;
};

USTRUCT(BlueprintType)
struct FProfilesSetEntityProfilePolicyResponse
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

