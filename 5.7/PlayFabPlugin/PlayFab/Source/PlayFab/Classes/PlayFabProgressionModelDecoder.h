//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Progression
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabProgressionModels.h"
#include "PlayFabProgressionModelDecoder.generated.h"

class UPlayFabJsonObject;

UCLASS()
class PLAYFAB_API UPlayFabProgressionModelDecoder : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    //////////////////////////////////////////////////////////////////////////
    // Generated PlayFab Progression API Functions
    //////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////
    // Leaderboards
    //////////////////////////////////////////////////////

    /** Decode the EmptyResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards Models")
        static FProgressionEmptyResponse decodeEmptyResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetEntityLeaderboardResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards Models")
        static FProgressionGetEntityLeaderboardResponse decodeGetEntityLeaderboardResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetLeaderboardDefinitionResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards Models")
        static FProgressionGetLeaderboardDefinitionResponse decodeGetLeaderboardDefinitionResponseResponse(UPlayFabJsonObject* response);

    /** Decode the IncrementLeaderboardVersionResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards Models")
        static FProgressionIncrementLeaderboardVersionResponse decodeIncrementLeaderboardVersionResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListLeaderboardDefinitionsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards Models")
        static FProgressionListLeaderboardDefinitionsResponse decodeListLeaderboardDefinitionsResponseResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Statistics
    //////////////////////////////////////////////////////

    /** Decode the DeleteStatisticsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics Models")
        static FProgressionDeleteStatisticsResponse decodeDeleteStatisticsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetStatisticDefinitionResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics Models")
        static FProgressionGetStatisticDefinitionResponse decodeGetStatisticDefinitionResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetStatisticsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics Models")
        static FProgressionGetStatisticsResponse decodeGetStatisticsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetStatisticsForEntitiesResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics Models")
        static FProgressionGetStatisticsForEntitiesResponse decodeGetStatisticsForEntitiesResponseResponse(UPlayFabJsonObject* response);

    /** Decode the IncrementStatisticVersionResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics Models")
        static FProgressionIncrementStatisticVersionResponse decodeIncrementStatisticVersionResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListStatisticDefinitionsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics Models")
        static FProgressionListStatisticDefinitionsResponse decodeListStatisticDefinitionsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the UpdateStatisticsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics Models")
        static FProgressionUpdateStatisticsResponse decodeUpdateStatisticsResponseResponse(UPlayFabJsonObject* response);



};
