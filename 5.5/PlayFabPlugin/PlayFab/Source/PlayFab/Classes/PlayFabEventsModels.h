//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Events
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabRequestCommon.h"
#include "PlayFabLoginResultCommon.h"
#include "PlayFabEventsModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Events API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// PlayStream
//////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// PlayStream Events
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FEventsCreateTelemetryKeyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The name of the new key. Telemetry key names must be unique within the scope of the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        FString KeyName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEventsCreateTelemetryKeyResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Details about the newly created telemetry key. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        UPlayFabJsonObject* NewKeyDetails = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEventsDeleteTelemetryKeyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The name of the key to delete. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        FString KeyName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEventsDeleteTelemetryKeyResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Indicates whether or not the key was deleted. If false, no key with that name existed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        bool WasKeyDeleted = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEventsGetTelemetryKeyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The name of the key to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        FString KeyName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEventsGetTelemetryKeyResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Details about the requested telemetry key. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        UPlayFabJsonObject* KeyDetails = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEventsListTelemetryKeysRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEventsListTelemetryKeysResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The telemetry keys configured for the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        TArray<UPlayFabJsonObject*> KeyDetails;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEventsSetTelemetryKeyActiveRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Whether to set the key to active (true) or deactivated (false). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        bool Active = false;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The name of the key to update. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        FString KeyName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEventsSetTelemetryKeyActiveResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The most current details about the telemetry key that was to be updated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        UPlayFabJsonObject* KeyDetails = nullptr;
    /** Indicates whether or not the key was updated. If false, the key was already in the desired state. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        bool WasKeyUpdated = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEventsWriteEventsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The collection of events to write. Up to 200 events can be written per request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        TArray<UPlayFabJsonObject*> Events;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEventsWriteEventsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * The unique identifiers assigned by the server to the events, in the same order as the events in the request. Only
     * returned if FlushToPlayStream option is true.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        FString AssignedEventIds;
};

