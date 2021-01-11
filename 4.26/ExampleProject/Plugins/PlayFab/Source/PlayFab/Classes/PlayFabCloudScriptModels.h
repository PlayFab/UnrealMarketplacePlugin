//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: CloudScript
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabRequestCommon.h"
#include "PlayFabLoginResultCommon.h"
#include "PlayFabCloudScriptModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab CloudScript API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Server-Side Cloud Script
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FCloudScriptExecuteCloudScriptResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Number of PlayFab API requests issued by the CloudScript function */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        int32 APIRequestsIssued = 0;
    /** Information about the error, if any, that occurred during execution */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* Error = nullptr;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        int32 ExecutionTimeSeconds = 0;
    /** The name of the function that executed */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        FString FunctionName;
    /** The object returned from the CloudScript function, if any */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* FunctionResult = nullptr;
    /**
     * Flag indicating if the FunctionResult was too large and was subsequently dropped from this event. This only occurs if
     * the total event size is larger than 350KB.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        bool FunctionResultTooLarge = false;
    /** Number of external HTTP requests issued by the CloudScript function */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        int32 HttpRequestsIssued = 0;
    /**
     * Entries logged during the function execution. These include both entries logged in the function code using log.info()
     * and log.error() and error entries for API and HTTP request failures.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        TArray<UPlayFabJsonObject*> Logs;
    /**
     * Flag indicating if the logs were too large and were subsequently dropped from this event. This only occurs if the total
     * event size is larger than 350KB after the FunctionResult was removed.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        bool LogsTooLarge = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        int32 MemoryConsumedBytes = 0;
    /**
     * Processor time consumed while executing the function. This does not include time spent waiting on API calls or HTTP
     * requests.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        int32 ProcessorTimeSeconds = 0;
    /** The revision of the CloudScript that executed */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        int32 Revision = 0;
};

/** Executes CloudScript with the entity profile that is defined in the request. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FCloudScriptExecuteEntityCloudScriptRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The name of the CloudScript function to execute */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        FString FunctionName;
    /** Object that is passed in to the function as the first argument */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* FunctionParameter = nullptr;
    /**
     * Generate a 'entity_executed_cloudscript' PlayStream event containing the results of the function execution and other
     * contextual information. This event will show up in the PlayStream debugger console for the player in Game Manager.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        bool GeneratePlayStreamEvent = false;
    /**
     * Option for which revision of the CloudScript to execute. 'Latest' executes the most recently created revision, 'Live'
     * executes the current live, published revision, and 'Specific' executes the specified revision. The default value is
     * 'Specific', if the SpecificRevision parameter is specified, otherwise it is 'Live'.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        ECloudScriptRevisionOption RevisionSelection;
    /** The specific revision to execute, when RevisionSelection is set to 'Specific' */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        int32 SpecificRevision = 0;
};

/** Executes an Azure Function with the profile of the entity that is defined in the request. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FCloudScriptExecuteFunctionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The name of the CloudScript function to execute */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        FString FunctionName;
    /** Object that is passed in to the function as the FunctionArgument field of the FunctionExecutionContext data structure */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* FunctionParameter = nullptr;
    /**
     * Generate a 'entity_executed_cloudscript_function' PlayStream event containing the results of the function execution and
     * other contextual information. This event will show up in the PlayStream debugger console for the player in Game Manager.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        bool GeneratePlayStreamEvent = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FCloudScriptExecuteFunctionResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Error from the CloudScript Azure Function. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* Error = nullptr;
    /** The amount of time the function took to execute */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        int32 ExecutionTimeMilliseconds = 0;
    /** The name of the function that executed */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        FString FunctionName;
    /** The object returned from the function, if any */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* FunctionResult = nullptr;
    /** Flag indicating if the FunctionResult was too large and was subsequently dropped from this event. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        bool FunctionResultTooLarge = false;
};

/**
 * A title can have many functions, ListHttpFunctions will return a list of all the currently registered HTTP triggered
 * functions for a given title.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FCloudScriptListFunctionsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FCloudScriptListFunctionsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of functions that are currently registered for the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        TArray<UPlayFabJsonObject*> Functions;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FCloudScriptListHttpFunctionsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of HTTP triggered functions that are currently registered for the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        TArray<UPlayFabJsonObject*> Functions;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FCloudScriptListQueuedFunctionsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of Queue triggered functions that are currently registered for the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        TArray<UPlayFabJsonObject*> Functions;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FCloudScriptEmptyResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FCloudScriptPostFunctionResultForEntityTriggeredActionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The result of the function execution. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* FunctionResult = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FCloudScriptPostFunctionResultForFunctionExecutionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The result of the function execution. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* FunctionResult = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FCloudScriptPostFunctionResultForPlayerTriggeredActionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The result of the function execution. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* FunctionResult = nullptr;
    /** The player profile the function was invoked with. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* PlayerProfile = nullptr;
    /** The triggering PlayStream event, if any, that caused the function to be invoked. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* PlayStreamEventEnvelope = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FCloudScriptPostFunctionResultForScheduledTaskRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The result of the function execution */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* FunctionResult = nullptr;
    /** The id of the scheduled task that invoked the function. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* ScheduledTaskId = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FCloudScriptRegisterHttpFunctionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The name of the function to register */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        FString FunctionName;
    /** Full URL for Azure Function that implements the function. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        FString FunctionUrl;
};

/**
 * A title can have many functions, RegisterQueuedFunction associates a function name with a queue name and connection
 * string.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FCloudScriptRegisterQueuedFunctionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** A connection string for the storage account that hosts the queue for the Azure Function. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        FString ConnectionString;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The name of the function to register */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        FString FunctionName;
    /** The name of the queue for the Azure Function. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        FString QueueName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FCloudScriptUnregisterFunctionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The name of the function to unregister */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        FString FunctionName;
};

