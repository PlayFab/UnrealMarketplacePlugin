//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Insights
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabRequestCommon.h"
#include "PlayFabLoginResultCommon.h"
#include "PlayFabInsightsModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Insights API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Analytics
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FInsightsInsightsEmptyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FInsightsInsightsGetDetailsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Amount of data (in MB) currently used by Insights. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        int32 DataUsageMb = 0;
    /** Details of any error that occurred while retrieving Insights details. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        FString ErrorMessage;
    /** Allowed range of values for performance level and data storage retention. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        UPlayFabJsonObject* Limits = nullptr;
    /** List of pending Insights operations for the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        TArray<UPlayFabJsonObject*> PendingOperations;
    /** Current Insights performance level setting. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        int32 PerformanceLevel = 0;
    /** Current Insights data storage retention value in days. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        int32 RetentionDays = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FInsightsInsightsGetLimitsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Default Insights performance level. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        int32 DefaultPerformanceLevel = 0;
    /** Default Insights data storage retention days. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        int32 DefaultStorageRetentionDays = 0;
    /** Maximum allowed data storage retention days. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        int32 StorageMaxRetentionDays = 0;
    /** Minimum allowed data storage retention days. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        int32 StorageMinRetentionDays = 0;
    /** List of Insights submeter limits for the allowed performance levels. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        TArray<UPlayFabJsonObject*> SubMeters;
};

/** Returns the current status for the requested operation id. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FInsightsInsightsGetOperationStatusRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Id of the Insights operation. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        FString OperationId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FInsightsInsightsGetOperationStatusResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Optional message related to the operation details. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        FString Message;
    /** Time the operation was completed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        FString OperationCompletedTime;
    /** Id of the Insights operation. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        FString OperationId;
    /** Time the operation status was last updated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        FString OperationLastUpdated;
    /** Time the operation started. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        FString OperationStartedTime;
    /** The type of operation, SetPerformance or SetStorageRetention. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        FString OperationType;
    /** The value requested for the operation. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        int32 OperationValue = 0;
    /** Current status of the operation. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        FString Status;
};

/** Returns a list of operations that are in the pending state for the requested operation type. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FInsightsInsightsGetPendingOperationsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The type of pending operations requested, or blank for all operation types. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        FString OperationType;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FInsightsInsightsGetPendingOperationsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of pending Insights operations. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        TArray<UPlayFabJsonObject*> PendingOperations;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FInsightsInsightsOperationResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Optional message related to the operation details. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        FString Message;
    /** Id of the Insights operation. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        FString OperationId;
    /** The type of operation, SetPerformance or SetStorageRetention. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        FString OperationType;
};

/** Sets the performance level to the requested value. Use the GetLimits method to get the allowed values. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FInsightsInsightsSetPerformanceRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The Insights performance level to apply to the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        int32 PerformanceLevel = 0;
};

/** Sets the data storage retention to the requested value. Use the GetLimits method to get the range of allowed values. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FInsightsInsightsSetStorageRetentionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The Insights data storage retention value (in days) to apply to the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Insights | Analytics Models")
        int32 RetentionDays = 0;
};

