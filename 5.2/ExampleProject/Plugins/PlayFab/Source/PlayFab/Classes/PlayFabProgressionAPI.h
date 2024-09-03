//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated header file for the UE4 PlayFab plugin.
// This header file contains the function definitions.
//
// API: Progression
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Http.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "PlayFabBaseModel.h"
#include "PlayFabProgressionModels.h"
#include "PlayFabProgressionAPI.generated.h"

class UPlayFabAuthenticationContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPlayFabProgressionRequestCompleted, FPlayFabBaseModel, response, UObject*, customData, bool, successful);

UCLASS(Blueprintable, BlueprintType)
class PLAYFAB_API UPlayFabProgressionAPI : public UOnlineBlueprintCallProxyBase
{
    GENERATED_UCLASS_BODY()

public:
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnFailurePlayFabError, FPlayFabError, error, UObject*, customData);

    UPROPERTY(BlueprintAssignable)
        FOnPlayFabProgressionRequestCompleted OnPlayFabResponse;

    void SetCallAuthenticationContext(UPlayFabAuthenticationContext* InAuthenticationContext);

    /** Set the Request Json object */
    void SetRequestObject(UPlayFabJsonObject* JsonObject);

    /** Get the Response Json object */
    UPlayFabJsonObject* GetResponseObject();

    /** Applies percent-encoding to text */
    static FString PercentEncode(const FString& Text);

    /** Reset saved response data */
    void ResetResponseData();

    /** UOnlineBlueprintCallProxyBase interface */
    virtual void Activate() override;

    //////////////////////////////////////////////////////////////////////////
    // Generated PlayFab Progression API Functions
    //////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////
    // Leaderboards
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateLeaderboardDefinition, FProgressionEmptyResponse, result, UObject*, customData);

    /** Creates a new leaderboard definition. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProgressionAPI* CreateLeaderboardDefinition(FProgressionCreateLeaderboardDefinitionRequest request,
            FDelegateOnSuccessCreateLeaderboardDefinition onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProgressionRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateLeaderboardDefinition(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteLeaderboardDefinition, FProgressionEmptyResponse, result, UObject*, customData);

    /** Deletes a leaderboard definition. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProgressionAPI* DeleteLeaderboardDefinition(FProgressionDeleteLeaderboardDefinitionRequest request,
            FDelegateOnSuccessDeleteLeaderboardDefinition onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProgressionRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteLeaderboardDefinition(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteLeaderboardEntries, FProgressionEmptyResponse, result, UObject*, customData);

    /** Deletes the specified entries from the given leaderboard. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProgressionAPI* DeleteLeaderboardEntries(FProgressionDeleteLeaderboardEntriesRequest request,
            FDelegateOnSuccessDeleteLeaderboardEntries onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProgressionRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteLeaderboardEntries(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetFriendLeaderboardForEntity, FProgressionGetEntityLeaderboardResponse, result, UObject*, customData);

    /** Get the friend leaderboard for the specified entity. A maximum of 100 friend entries are listed in the leaderboard. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProgressionAPI* GetFriendLeaderboardForEntity(FProgressionGetFriendLeaderboardForEntityRequest request,
            FDelegateOnSuccessGetFriendLeaderboardForEntity onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProgressionRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetFriendLeaderboardForEntity(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetLeaderboard, FProgressionGetEntityLeaderboardResponse, result, UObject*, customData);

    /** Get the leaderboard for a specific entity type and statistic. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProgressionAPI* GetLeaderboard(FProgressionGetEntityLeaderboardRequest request,
            FDelegateOnSuccessGetLeaderboard onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProgressionRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetLeaderboard(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetLeaderboardAroundEntity, FProgressionGetEntityLeaderboardResponse, result, UObject*, customData);

    /** Get the leaderboard around a specific entity. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProgressionAPI* GetLeaderboardAroundEntity(FProgressionGetLeaderboardAroundEntityRequest request,
            FDelegateOnSuccessGetLeaderboardAroundEntity onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProgressionRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetLeaderboardAroundEntity(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetLeaderboardDefinition, FProgressionGetLeaderboardDefinitionResponse, result, UObject*, customData);

    /** Gets the specified leaderboard definition. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProgressionAPI* GetLeaderboardDefinition(FProgressionGetLeaderboardDefinitionRequest request,
            FDelegateOnSuccessGetLeaderboardDefinition onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProgressionRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetLeaderboardDefinition(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetLeaderboardForEntities, FProgressionGetEntityLeaderboardResponse, result, UObject*, customData);

    /** Get the leaderboard limited to a set of entities. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProgressionAPI* GetLeaderboardForEntities(FProgressionGetLeaderboardForEntitiesRequest request,
            FDelegateOnSuccessGetLeaderboardForEntities onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProgressionRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetLeaderboardForEntities(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessIncrementLeaderboardVersion, FProgressionIncrementLeaderboardVersionResponse, result, UObject*, customData);

    /** Increment a leaderboard version. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProgressionAPI* IncrementLeaderboardVersion(FProgressionIncrementLeaderboardVersionRequest request,
            FDelegateOnSuccessIncrementLeaderboardVersion onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProgressionRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperIncrementLeaderboardVersion(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListLeaderboardDefinitions, FProgressionListLeaderboardDefinitionsResponse, result, UObject*, customData);

    /** Lists the leaderboard definitions defined for the Title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProgressionAPI* ListLeaderboardDefinitions(FProgressionListLeaderboardDefinitionsRequest request,
            FDelegateOnSuccessListLeaderboardDefinitions onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProgressionRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListLeaderboardDefinitions(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlinkLeaderboardFromStatistic, FProgressionEmptyResponse, result, UObject*, customData);

    /** Unlinks a leaderboard definition from it's linked statistic definition. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProgressionAPI* UnlinkLeaderboardFromStatistic(FProgressionUnlinkLeaderboardFromStatisticRequest request,
            FDelegateOnSuccessUnlinkLeaderboardFromStatistic onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProgressionRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlinkLeaderboardFromStatistic(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateLeaderboardEntries, FProgressionEmptyResponse, result, UObject*, customData);

    /** Adds or updates entries on the specified leaderboard. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProgressionAPI* UpdateLeaderboardEntries(FProgressionUpdateLeaderboardEntriesRequest request,
            FDelegateOnSuccessUpdateLeaderboardEntries onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProgressionRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateLeaderboardEntries(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Statistics
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateStatisticDefinition, FProgressionEmptyResponse, result, UObject*, customData);

    /** Create a new entity statistic definition. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProgressionAPI* CreateStatisticDefinition(FProgressionCreateStatisticDefinitionRequest request,
            FDelegateOnSuccessCreateStatisticDefinition onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProgressionRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateStatisticDefinition(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteStatisticDefinition, FProgressionEmptyResponse, result, UObject*, customData);

    /** Delete an entity statistic definition. Will delete all statistics on entity profiles and leaderboards. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProgressionAPI* DeleteStatisticDefinition(FProgressionDeleteStatisticDefinitionRequest request,
            FDelegateOnSuccessDeleteStatisticDefinition onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProgressionRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteStatisticDefinition(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteStatistics, FProgressionDeleteStatisticsResponse, result, UObject*, customData);

    /** Delete statistics on an entity profile. This will remove all rankings from associated leaderboards. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProgressionAPI* DeleteStatistics(FProgressionDeleteStatisticsRequest request,
            FDelegateOnSuccessDeleteStatistics onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProgressionRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteStatistics(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetStatisticDefinition, FProgressionGetStatisticDefinitionResponse, result, UObject*, customData);

    /** Get current statistic definition information */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProgressionAPI* GetStatisticDefinition(FProgressionGetStatisticDefinitionRequest request,
            FDelegateOnSuccessGetStatisticDefinition onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProgressionRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetStatisticDefinition(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetStatisticDefinitions, FProgressionGetStatisticDefinitionsResponse, result, UObject*, customData);

    /** Get all current statistic definitions information */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProgressionAPI* GetStatisticDefinitions(FProgressionGetStatisticDefinitionsRequest request,
            FDelegateOnSuccessGetStatisticDefinitions onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProgressionRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetStatisticDefinitions(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetStatistics, FProgressionGetStatisticsResponse, result, UObject*, customData);

    /** Gets statistics for the specified entity. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProgressionAPI* GetStatistics(FProgressionGetStatisticsRequest request,
            FDelegateOnSuccessGetStatistics onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProgressionRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetStatistics(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetStatisticsForEntities, FProgressionGetStatisticsForEntitiesResponse, result, UObject*, customData);

    /** Gets statistics for the specified collection of entities. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProgressionAPI* GetStatisticsForEntities(FProgressionGetStatisticsForEntitiesRequest request,
            FDelegateOnSuccessGetStatisticsForEntities onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProgressionRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetStatisticsForEntities(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessIncrementStatisticVersion, FProgressionIncrementStatisticVersionResponse, result, UObject*, customData);

    /** Increment an entity statistic definition version. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProgressionAPI* IncrementStatisticVersion(FProgressionIncrementStatisticVersionRequest request,
            FDelegateOnSuccessIncrementStatisticVersion onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProgressionRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperIncrementStatisticVersion(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListStatisticDefinitions, FProgressionListStatisticDefinitionsResponse, result, UObject*, customData);

    /** Get all current statistic definitions information */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProgressionAPI* ListStatisticDefinitions(FProgressionListStatisticDefinitionsRequest request,
            FDelegateOnSuccessListStatisticDefinitions onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProgressionRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListStatisticDefinitions(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateStatistics, FProgressionUpdateStatisticsResponse, result, UObject*, customData);

    /**
     * Update statistics on an entity profile. Depending on the statistic definition, this may result in entity being ranked on
     * various leaderboards.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProgressionAPI* UpdateStatistics(FProgressionUpdateStatisticsRequest request,
            FDelegateOnSuccessUpdateStatistics onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProgressionRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Progression | Statistics ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateStatistics(FPlayFabBaseModel response, UObject* customData, bool successful);



    /** PlayFab Request Info */
    FString PlayFabRequestURL;

    bool useEntityToken = false;
    bool useSecretKey = false;
    bool useSessionTicket = false;
    bool returnsSessionTicket = false;
    bool returnsEntityToken = false;

    /** Is the response valid JSON? */
    bool bIsValidJsonResponse;
    FString ResponseContent;
    int32 ResponseCode;
    UObject* mCustomData;

    FDelegateOnFailurePlayFabError OnFailure;
    FDelegateOnSuccessCreateLeaderboardDefinition OnSuccessCreateLeaderboardDefinition;
    FDelegateOnSuccessDeleteLeaderboardDefinition OnSuccessDeleteLeaderboardDefinition;
    FDelegateOnSuccessDeleteLeaderboardEntries OnSuccessDeleteLeaderboardEntries;
    FDelegateOnSuccessGetFriendLeaderboardForEntity OnSuccessGetFriendLeaderboardForEntity;
    FDelegateOnSuccessGetLeaderboard OnSuccessGetLeaderboard;
    FDelegateOnSuccessGetLeaderboardAroundEntity OnSuccessGetLeaderboardAroundEntity;
    FDelegateOnSuccessGetLeaderboardDefinition OnSuccessGetLeaderboardDefinition;
    FDelegateOnSuccessGetLeaderboardForEntities OnSuccessGetLeaderboardForEntities;
    FDelegateOnSuccessIncrementLeaderboardVersion OnSuccessIncrementLeaderboardVersion;
    FDelegateOnSuccessListLeaderboardDefinitions OnSuccessListLeaderboardDefinitions;
    FDelegateOnSuccessUnlinkLeaderboardFromStatistic OnSuccessUnlinkLeaderboardFromStatistic;
    FDelegateOnSuccessUpdateLeaderboardEntries OnSuccessUpdateLeaderboardEntries;
    FDelegateOnSuccessCreateStatisticDefinition OnSuccessCreateStatisticDefinition;
    FDelegateOnSuccessDeleteStatisticDefinition OnSuccessDeleteStatisticDefinition;
    FDelegateOnSuccessDeleteStatistics OnSuccessDeleteStatistics;
    FDelegateOnSuccessGetStatisticDefinition OnSuccessGetStatisticDefinition;
    FDelegateOnSuccessGetStatisticDefinitions OnSuccessGetStatisticDefinitions;
    FDelegateOnSuccessGetStatistics OnSuccessGetStatistics;
    FDelegateOnSuccessGetStatisticsForEntities OnSuccessGetStatisticsForEntities;
    FDelegateOnSuccessIncrementStatisticVersion OnSuccessIncrementStatisticVersion;
    FDelegateOnSuccessListStatisticDefinitions OnSuccessListStatisticDefinitions;
    FDelegateOnSuccessUpdateStatistics OnSuccessUpdateStatistics;

private:
    UPROPERTY()
        UPlayFabAuthenticationContext* CallAuthenticationContext;

    /** Internal bind function for the IHTTPRequest::OnProcessRequestCompleted() event */
    void OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

protected:
    /** Internal request data stored as JSON */
    UPROPERTY()
        UPlayFabJsonObject* RequestJsonObj;

    /** Response data stored as JSON */
    UPROPERTY()
        UPlayFabJsonObject* ResponseJsonObj;

    /** Mapping of header section to values. Used to generate final header string for request */
    TMap<FString, FString> RequestHeaders;
};
