//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated header file for the UE4 PlayFab plugin.
// This header file contains the function definitions.
//
// API: Leaderboards
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Http.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "PlayFabBaseModel.h"
#include "PlayFabLeaderboardsModels.h"
#include "PlayFabLeaderboardsAPI.generated.h"

class UPlayFabAuthenticationContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPlayFabLeaderboardsRequestCompleted, FPlayFabBaseModel, response, UObject*, customData, bool, successful);

UCLASS(Blueprintable, BlueprintType)
class PLAYFAB_API UPlayFabLeaderboardsAPI : public UOnlineBlueprintCallProxyBase
{
    GENERATED_UCLASS_BODY()

public:
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnFailurePlayFabError, FPlayFabError, error, UObject*, customData);

    UPROPERTY(BlueprintAssignable)
        FOnPlayFabLeaderboardsRequestCompleted OnPlayFabResponse;

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
    // Generated PlayFab Leaderboards API Functions
    //////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////
    // Leaderboards
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateLeaderboardDefinition, FLeaderboardsEmptyResponse, result, UObject*, customData);

    /** Creates a new leaderboard definition. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabLeaderboardsAPI* CreateLeaderboardDefinition(FLeaderboardsCreateLeaderboardDefinitionRequest request,
            FDelegateOnSuccessCreateLeaderboardDefinition onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabLeaderboardsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateLeaderboardDefinition(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteLeaderboardDefinition, FLeaderboardsEmptyResponse, result, UObject*, customData);

    /** Deletes a leaderboard definition. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabLeaderboardsAPI* DeleteLeaderboardDefinition(FLeaderboardsDeleteLeaderboardDefinitionRequest request,
            FDelegateOnSuccessDeleteLeaderboardDefinition onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabLeaderboardsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteLeaderboardDefinition(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteLeaderboardEntries, FLeaderboardsEmptyResponse, result, UObject*, customData);

    /** Deletes the specified entries from the given leaderboard. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabLeaderboardsAPI* DeleteLeaderboardEntries(FLeaderboardsDeleteLeaderboardEntriesRequest request,
            FDelegateOnSuccessDeleteLeaderboardEntries onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabLeaderboardsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteLeaderboardEntries(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetLeaderboardDefinition, FLeaderboardsGetLeaderboardDefinitionResponse, result, UObject*, customData);

    /** Gets the specified leaderboard definition. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabLeaderboardsAPI* GetLeaderboardDefinition(FLeaderboardsGetLeaderboardDefinitionRequest request,
            FDelegateOnSuccessGetLeaderboardDefinition onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabLeaderboardsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetLeaderboardDefinition(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessIncrementLeaderboardVersion, FLeaderboardsIncrementLeaderboardVersionResponse, result, UObject*, customData);

    /** Increment a leaderboard version. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabLeaderboardsAPI* IncrementLeaderboardVersion(FLeaderboardsIncrementLeaderboardVersionRequest request,
            FDelegateOnSuccessIncrementLeaderboardVersion onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabLeaderboardsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperIncrementLeaderboardVersion(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListLeaderboardDefinitions, FLeaderboardsListLeaderboardDefinitionsResponse, result, UObject*, customData);

    /** Lists the leaderboard definitions defined for the Title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabLeaderboardsAPI* ListLeaderboardDefinitions(FLeaderboardsListLeaderboardDefinitionsRequest request,
            FDelegateOnSuccessListLeaderboardDefinitions onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabLeaderboardsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListLeaderboardDefinitions(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlinkLeaderboardFromStatistic, FLeaderboardsEmptyResponse, result, UObject*, customData);

    /** Unlinks a leaderboard definition from it's linked statistic definition. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabLeaderboardsAPI* UnlinkLeaderboardFromStatistic(FLeaderboardsUnlinkLeaderboardFromStatisticRequest request,
            FDelegateOnSuccessUnlinkLeaderboardFromStatistic onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabLeaderboardsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlinkLeaderboardFromStatistic(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateLeaderboardEntries, FLeaderboardsEmptyResponse, result, UObject*, customData);

    /** Adds or updates entries on the specified leaderboard. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabLeaderboardsAPI* UpdateLeaderboardEntries(FLeaderboardsUpdateLeaderboardEntriesRequest request,
            FDelegateOnSuccessUpdateLeaderboardEntries onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabLeaderboardsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateLeaderboardEntries(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Statistics and Leaderboards
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateStatisticDefinition, FLeaderboardsEmptyResponse, result, UObject*, customData);

    /** Create a new entity statistic definition. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabLeaderboardsAPI* CreateStatisticDefinition(FLeaderboardsCreateStatisticDefinitionRequest request,
            FDelegateOnSuccessCreateStatisticDefinition onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabLeaderboardsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateStatisticDefinition(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteStatisticDefinition, FLeaderboardsEmptyResponse, result, UObject*, customData);

    /** Delete an entity statistic definition. Will delete all statistics on entity profiles and leaderboards. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabLeaderboardsAPI* DeleteStatisticDefinition(FLeaderboardsDeleteStatisticDefinitionRequest request,
            FDelegateOnSuccessDeleteStatisticDefinition onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabLeaderboardsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteStatisticDefinition(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteStatistics, FLeaderboardsDeleteStatisticsResponse, result, UObject*, customData);

    /** Delete statistics on an entity profile. This will remove all rankings from associated leaderboards. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabLeaderboardsAPI* DeleteStatistics(FLeaderboardsDeleteStatisticsRequest request,
            FDelegateOnSuccessDeleteStatistics onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabLeaderboardsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteStatistics(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetFriendLeaderboardForEntity, FLeaderboardsGetEntityLeaderboardResponse, result, UObject*, customData);

    /** Get the friend leaderboard for the specified entity. A maximum of 100 friend entries are listed in the leaderboard. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabLeaderboardsAPI* GetFriendLeaderboardForEntity(FLeaderboardsGetFriendLeaderboardForEntityRequest request,
            FDelegateOnSuccessGetFriendLeaderboardForEntity onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabLeaderboardsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetFriendLeaderboardForEntity(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetLeaderboard, FLeaderboardsGetEntityLeaderboardResponse, result, UObject*, customData);

    /** Get the leaderboard for a specific entity type and statistic. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabLeaderboardsAPI* GetLeaderboard(FLeaderboardsGetEntityLeaderboardRequest request,
            FDelegateOnSuccessGetLeaderboard onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabLeaderboardsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetLeaderboard(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetLeaderboardAroundEntity, FLeaderboardsGetEntityLeaderboardResponse, result, UObject*, customData);

    /** Get the leaderboard around a specific entity. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabLeaderboardsAPI* GetLeaderboardAroundEntity(FLeaderboardsGetLeaderboardAroundEntityRequest request,
            FDelegateOnSuccessGetLeaderboardAroundEntity onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabLeaderboardsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetLeaderboardAroundEntity(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetLeaderboardForEntities, FLeaderboardsGetEntityLeaderboardResponse, result, UObject*, customData);

    /** Get the leaderboard limited to a set of entities. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabLeaderboardsAPI* GetLeaderboardForEntities(FLeaderboardsGetLeaderboardForEntitiesRequest request,
            FDelegateOnSuccessGetLeaderboardForEntities onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabLeaderboardsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetLeaderboardForEntities(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetStatisticDefinition, FLeaderboardsGetStatisticDefinitionResponse, result, UObject*, customData);

    /** Get current statistic definition information */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabLeaderboardsAPI* GetStatisticDefinition(FLeaderboardsGetStatisticDefinitionRequest request,
            FDelegateOnSuccessGetStatisticDefinition onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabLeaderboardsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetStatisticDefinition(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetStatisticDefinitions, FLeaderboardsGetStatisticDefinitionsResponse, result, UObject*, customData);

    /** Get all current statistic definitions information */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabLeaderboardsAPI* GetStatisticDefinitions(FLeaderboardsGetStatisticDefinitionsRequest request,
            FDelegateOnSuccessGetStatisticDefinitions onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabLeaderboardsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetStatisticDefinitions(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetStatistics, FLeaderboardsGetStatisticsResponse, result, UObject*, customData);

    /** Gets statistics for the specified entity. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabLeaderboardsAPI* GetStatistics(FLeaderboardsGetStatisticsRequest request,
            FDelegateOnSuccessGetStatistics onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabLeaderboardsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetStatistics(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetStatisticsForEntities, FLeaderboardsGetStatisticsForEntitiesResponse, result, UObject*, customData);

    /** Gets statistics for the specified collection of entities. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabLeaderboardsAPI* GetStatisticsForEntities(FLeaderboardsGetStatisticsForEntitiesRequest request,
            FDelegateOnSuccessGetStatisticsForEntities onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabLeaderboardsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetStatisticsForEntities(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessIncrementStatisticVersion, FLeaderboardsIncrementStatisticVersionResponse, result, UObject*, customData);

    /** Increment an entity statistic definition version. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabLeaderboardsAPI* IncrementStatisticVersion(FLeaderboardsIncrementStatisticVersionRequest request,
            FDelegateOnSuccessIncrementStatisticVersion onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabLeaderboardsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperIncrementStatisticVersion(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListStatisticDefinitions, FLeaderboardsListStatisticDefinitionsResponse, result, UObject*, customData);

    /** Get all current statistic definitions information */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabLeaderboardsAPI* ListStatisticDefinitions(FLeaderboardsListStatisticDefinitionsRequest request,
            FDelegateOnSuccessListStatisticDefinitions onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabLeaderboardsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListStatisticDefinitions(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateStatistics, FLeaderboardsUpdateStatisticsResponse, result, UObject*, customData);

    /**
     * Update statistics on an entity profile. Depending on the statistic definition, this may result in entity being ranked on
     * various leaderboards.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabLeaderboardsAPI* UpdateStatistics(FLeaderboardsUpdateStatisticsRequest request,
            FDelegateOnSuccessUpdateStatistics onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabLeaderboardsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Leaderboards | Statistics and Leaderboards ", meta = (BlueprintInternalUseOnly = "true"))
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
    FDelegateOnSuccessGetLeaderboardDefinition OnSuccessGetLeaderboardDefinition;
    FDelegateOnSuccessIncrementLeaderboardVersion OnSuccessIncrementLeaderboardVersion;
    FDelegateOnSuccessListLeaderboardDefinitions OnSuccessListLeaderboardDefinitions;
    FDelegateOnSuccessUnlinkLeaderboardFromStatistic OnSuccessUnlinkLeaderboardFromStatistic;
    FDelegateOnSuccessUpdateLeaderboardEntries OnSuccessUpdateLeaderboardEntries;
    FDelegateOnSuccessCreateStatisticDefinition OnSuccessCreateStatisticDefinition;
    FDelegateOnSuccessDeleteStatisticDefinition OnSuccessDeleteStatisticDefinition;
    FDelegateOnSuccessDeleteStatistics OnSuccessDeleteStatistics;
    FDelegateOnSuccessGetFriendLeaderboardForEntity OnSuccessGetFriendLeaderboardForEntity;
    FDelegateOnSuccessGetLeaderboard OnSuccessGetLeaderboard;
    FDelegateOnSuccessGetLeaderboardAroundEntity OnSuccessGetLeaderboardAroundEntity;
    FDelegateOnSuccessGetLeaderboardForEntities OnSuccessGetLeaderboardForEntities;
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
