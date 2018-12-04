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
#include "PlayFabCloudScriptModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab CloudScript API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Server-Side Cloud Script
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FCloudScriptExecuteCloudScriptResult
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
struct PLAYFAB_API FCloudScriptExecuteEntityCloudScriptRequest
{
    GENERATED_USTRUCT_BODY()
public:
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

