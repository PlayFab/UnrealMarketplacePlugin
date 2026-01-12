//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Data
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabRequestCommon.h"
#include "PlayFabLoginResultCommon.h"
#include "PlayFabDataModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Data API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// File
//////////////////////////////////////////////////////

/** Aborts the pending upload of the requested files. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FDataAbortFileUploadsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** Names of the files to have their pending uploads aborted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        FString FileNames;
    /**
     * The expected version of the profile, if set and doesn't match the current version of the profile the operation will not
     * be performed.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        int32 ProfileVersion = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FDataAbortFileUploadsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The entity id and type. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The current version of the profile, can be used for concurrency control during updates. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        int32 ProfileVersion = 0;
};

/** Deletes the requested files from the entity's profile. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FDataDeleteFilesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** Names of the files to be deleted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        FString FileNames;
    /**
     * The expected version of the profile, if set and doesn't match the current version of the profile the operation will not
     * be performed.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        int32 ProfileVersion = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FDataDeleteFilesResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The entity id and type. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The current version of the profile, can be used for concurrency control during updates. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        int32 ProfileVersion = 0;
};

/**
 * Finalizes the upload of the requested files. Verifies that the files have been successfully uploaded and moves the file
 * pointers from pending to live.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FDataFinalizeFileUploadsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** Names of the files to be finalized. Restricted to a-Z, 0-9, '(', ')', '_', '-' and '.' */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        FString FileNames;
    /** The current version of the profile, can be used for concurrency control during updates. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        int32 ProfileVersion = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FDataFinalizeFileUploadsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The entity id and type. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** Collection of metadata for the entity's files */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        UPlayFabJsonObject* Metadata = nullptr;
    /** The current version of the profile, can be used for concurrency control during updates. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        int32 ProfileVersion = 0;
};

/**
 * Returns URLs that may be used to download the files for a profile for a limited length of time. Only returns files that
 * have been successfully uploaded, files that are still pending will either return the old value, if it exists, or
 * nothing.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FDataGetFilesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FDataGetFilesResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The entity id and type. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** Collection of metadata for the entity's files */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        UPlayFabJsonObject* Metadata = nullptr;
    /** The current version of the profile, can be used for concurrency control during updates. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        int32 ProfileVersion = 0;
};

/**
 * Returns URLs that may be used to upload the files for a profile 5 minutes. After using the upload calls
 * FinalizeFileUploads must be called to move the file status from pending to live.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FDataInitiateFileUploadsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** Names of the files to be set. Restricted to a-Z, 0-9, '(', ')', '_', '-' and '.' */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        FString FileNames;
    /**
     * The expected version of the profile, if set and doesn't match the current version of the profile the operation will not
     * be performed.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        int32 ProfileVersion = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FDataInitiateFileUploadsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The entity id and type. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The current version of the profile, can be used for concurrency control during updates. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        int32 ProfileVersion = 0;
    /** Collection of file names and upload urls */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | File Models")
        TArray<UPlayFabJsonObject*> UploadDetails;
};


///////////////////////////////////////////////////////
// Object
//////////////////////////////////////////////////////

/** Gets JSON objects from an entity profile and returns it. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FDataGetObjectsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | Object Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | Object Models")
        UPlayFabJsonObject* Entity = nullptr;
    /**
     * Determines whether the object will be returned as an escaped JSON string or as a un-escaped JSON object. Default is JSON
     * object.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | Object Models")
        bool EscapeObject = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FDataGetObjectsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The entity id and type. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | Object Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** Requested objects that the calling entity has access to */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | Object Models")
        UPlayFabJsonObject* Objects = nullptr;
    /** The current version of the profile, can be used for concurrency control during updates. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | Object Models")
        int32 ProfileVersion = 0;
};

/**
 * Sets JSON objects on the requested entity profile. May include a version number to be used to perform optimistic
 * concurrency operations during update. If the current version differs from the version in the request the request will be
 * ignored. If no version is set on the request then the value will always be updated if the values differ. Using the
 * version value does not guarantee a write though, ConcurrentEditError may still occur if multiple clients are attempting
 * to update the same profile.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FDataSetObjectsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | Object Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | Object Models")
        UPlayFabJsonObject* Entity = nullptr;
    /**
     * Optional field used for concurrency control. By specifying the previously returned value of ProfileVersion from
     * GetProfile API, you can ensure that the object set will only be performed if the profile has not been updated by any
     * other clients since the version you last loaded.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | Object Models")
        int32 ExpectedProfileVersion = 0;
    /** Collection of objects to set on the profile. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | Object Models")
        TArray<UPlayFabJsonObject*> Objects;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FDataSetObjectsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** New version of the entity profile. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | Object Models")
        int32 ProfileVersion = 0;
    /** New version of the entity profile. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Data | Object Models")
        TArray<UPlayFabJsonObject*> SetResults;
};

