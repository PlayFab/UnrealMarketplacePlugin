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
struct PLAYFAB_API FEventsDeleteDataConnectionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The name of the data connection to delete. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        FString Name;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEventsDeleteDataConnectionResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Indicates whether or not the connection was deleted as part of the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        bool WasDeleted = false;
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
struct PLAYFAB_API FEventsGetDataConnectionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The name of the data connection to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        FString Name;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEventsGetDataConnectionResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The details of the queried Data Connection. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        UPlayFabJsonObject* DataConnection = nullptr;
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
struct PLAYFAB_API FEventsListDataConnectionsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEventsListDataConnectionsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of existing Data Connections. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        TArray<UPlayFabJsonObject*> DataConnections;
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
struct PLAYFAB_API FEventsSetDataConnectionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Settings of the data connection. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        UPlayFabJsonObject* ConnectionSettings = nullptr;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Whether or not the connection is currently active. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        bool IsActive = false;
    /** The name of the data connection to update or create. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        FString Name;
    /** The type of data connection. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        EDataConnectionType Type = StaticCast<EDataConnectionType>(0);
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEventsSetDataConnectionResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The details of the Data Connection to be created or updated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        UPlayFabJsonObject* DataConnection = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEventsSetDataConnectionActiveRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Whether to set the data connection to active (true) or deactivated (false). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        bool Active = false;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The name of the data connection to update. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        FString Name;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEventsSetDataConnectionActiveResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The most current details about the data connection that was to be updated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        UPlayFabJsonObject* DataConnection = nullptr;
    /**
     * Indicates whether or not the data connection was updated. If false, the data connection was already in the desired
     * state.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        bool WasUpdated = false;
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

