//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Leaderboards
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabLeaderboardsModels.h"
#include "PlayFabLeaderboardsModelDecoder.generated.h"

class UPlayFabJsonObject;

UCLASS()
class PLAYFAB_API UPlayFabLeaderboardsModelDecoder : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    //////////////////////////////////////////////////////////////////////////
    // Generated PlayFab Leaderboards API Functions
    //////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////
    // Leaderboards
    //////////////////////////////////////////////////////

    /** Decode the EmptyResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Leaderboards Models")
        static FLeaderboardsEmptyResponse decodeEmptyResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetLeaderboardDefinitionResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Leaderboards Models")
        static FLeaderboardsGetLeaderboardDefinitionResponse decodeGetLeaderboardDefinitionResponseResponse(UPlayFabJsonObject* response);

    /** Decode the IncrementLeaderboardVersionResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Leaderboards Models")
        static FLeaderboardsIncrementLeaderboardVersionResponse decodeIncrementLeaderboardVersionResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListLeaderboardDefinitionsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Leaderboards Models")
        static FLeaderboardsListLeaderboardDefinitionsResponse decodeListLeaderboardDefinitionsResponseResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Statistics and Leaderboards
    //////////////////////////////////////////////////////

    /** Decode the DeleteStatisticsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards Models")
        static FLeaderboardsDeleteStatisticsResponse decodeDeleteStatisticsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetEntityLeaderboardResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards Models")
        static FLeaderboardsGetEntityLeaderboardResponse decodeGetEntityLeaderboardResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetStatisticDefinitionResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards Models")
        static FLeaderboardsGetStatisticDefinitionResponse decodeGetStatisticDefinitionResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetStatisticDefinitionsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards Models")
        static FLeaderboardsGetStatisticDefinitionsResponse decodeGetStatisticDefinitionsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetStatisticsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards Models")
        static FLeaderboardsGetStatisticsResponse decodeGetStatisticsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetStatisticsForEntitiesResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards Models")
        static FLeaderboardsGetStatisticsForEntitiesResponse decodeGetStatisticsForEntitiesResponseResponse(UPlayFabJsonObject* response);

    /** Decode the IncrementStatisticVersionResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards Models")
        static FLeaderboardsIncrementStatisticVersionResponse decodeIncrementStatisticVersionResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListStatisticDefinitionsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards Models")
        static FLeaderboardsListStatisticDefinitionsResponse decodeListStatisticDefinitionsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the UpdateStatisticsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards Models")
        static FLeaderboardsUpdateStatisticsResponse decodeUpdateStatisticsResponseResponse(UPlayFabJsonObject* response);



};
