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
#include "PlayFabCloudScriptModels.h"
#include "PlayFabCloudScriptModelDecoder.generated.h"

class UPlayFabJsonObject;

UCLASS()
class PLAYFAB_API UPlayFabCloudScriptModelDecoder : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    //////////////////////////////////////////////////////////////////////////
    // Generated PlayFab CloudScript API Functions
    //////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////
    // Server-Side Cloud Script
    //////////////////////////////////////////////////////

    /** Decode the ExecuteCloudScriptResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        static FCloudScriptExecuteCloudScriptResult decodeExecuteCloudScriptResultResponse(UPlayFabJsonObject* response);

    /** Decode the ExecuteFunctionResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        static FCloudScriptExecuteFunctionResult decodeExecuteFunctionResultResponse(UPlayFabJsonObject* response);

    /** Decode the ListFunctionsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        static FCloudScriptListFunctionsResult decodeListFunctionsResultResponse(UPlayFabJsonObject* response);

    /** Decode the ListHttpFunctionsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        static FCloudScriptListHttpFunctionsResult decodeListHttpFunctionsResultResponse(UPlayFabJsonObject* response);

    /** Decode the ListQueuedFunctionsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        static FCloudScriptListQueuedFunctionsResult decodeListQueuedFunctionsResultResponse(UPlayFabJsonObject* response);

    /** Decode the EmptyResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script Models")
        static FCloudScriptEmptyResult decodeEmptyResultResponse(UPlayFabJsonObject* response);



};
