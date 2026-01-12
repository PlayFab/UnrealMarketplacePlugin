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
#include "PlayFabInsightsModels.h"
#include "PlayFabInsightsModelDecoder.generated.h"

class UPlayFabJsonObject;

UCLASS()
class PLAYFAB_API UPlayFabInsightsModelDecoder : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    //////////////////////////////////////////////////////////////////////////
    // Generated PlayFab Insights API Functions
    //////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////
    // Analytics
    //////////////////////////////////////////////////////

    /** Decode the InsightsGetDetailsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Insights | Analytics Models")
        static FInsightsInsightsGetDetailsResponse decodeInsightsGetDetailsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the InsightsGetLimitsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Insights | Analytics Models")
        static FInsightsInsightsGetLimitsResponse decodeInsightsGetLimitsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the InsightsGetOperationStatusResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Insights | Analytics Models")
        static FInsightsInsightsGetOperationStatusResponse decodeInsightsGetOperationStatusResponseResponse(UPlayFabJsonObject* response);

    /** Decode the InsightsGetPendingOperationsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Insights | Analytics Models")
        static FInsightsInsightsGetPendingOperationsResponse decodeInsightsGetPendingOperationsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the InsightsOperationResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Insights | Analytics Models")
        static FInsightsInsightsOperationResponse decodeInsightsOperationResponseResponse(UPlayFabJsonObject* response);



};
