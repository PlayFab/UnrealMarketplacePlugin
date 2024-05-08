//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated header file for the UE4 PlayFab plugin.
// This header file contains the function definitions.
//
// API: Economy
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Http.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "PlayFabBaseModel.h"
#include "PlayFabEconomyModels.h"
#include "PlayFabEconomyAPI.generated.h"

class UPlayFabAuthenticationContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPlayFabEconomyRequestCompleted, FPlayFabBaseModel, response, UObject*, customData, bool, successful);

UCLASS(Blueprintable, BlueprintType)
class PLAYFAB_API UPlayFabEconomyAPI : public UOnlineBlueprintCallProxyBase
{
    GENERATED_UCLASS_BODY()

public:
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnFailurePlayFabError, FPlayFabError, error, UObject*, customData);

    UPROPERTY(BlueprintAssignable)
        FOnPlayFabEconomyRequestCompleted OnPlayFabResponse;

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
    // Generated PlayFab Economy API Functions
    //////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////
    // Catalog
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateDraftItem, FEconomyCreateDraftItemResponse, result, UObject*, customData);

    /** Creates a new item in the working catalog using provided metadata. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* CreateDraftItem(FEconomyCreateDraftItemRequest request,
            FDelegateOnSuccessCreateDraftItem onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateDraftItem(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateUploadUrls, FEconomyCreateUploadUrlsResponse, result, UObject*, customData);

    /**
     * Creates one or more upload URLs which can be used by the client to upload raw file data. Content URls and uploaded
     * content will be garbage collected after 24 hours if not attached to a draft or published item. Detailed pricing info
     * around uploading content can be found here:
     * https://learn.microsoft.com/en-us/gaming/playfab/features/pricing/meters/catalog-meters
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* CreateUploadUrls(FEconomyCreateUploadUrlsRequest request,
            FDelegateOnSuccessCreateUploadUrls onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateUploadUrls(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteEntityItemReviews, FEconomyDeleteEntityItemReviewsResponse, result, UObject*, customData);

    /** Deletes all reviews, helpfulness votes, and ratings submitted by the entity specified. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* DeleteEntityItemReviews(FEconomyDeleteEntityItemReviewsRequest request,
            FDelegateOnSuccessDeleteEntityItemReviews onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteEntityItemReviews(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteItem, FEconomyDeleteItemResponse, result, UObject*, customData);

    /** Removes an item from working catalog and all published versions from the public catalog. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* DeleteItem(FEconomyDeleteItemRequest request,
            FDelegateOnSuccessDeleteItem onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteItem(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetCatalogConfig, FEconomyGetCatalogConfigResponse, result, UObject*, customData);

    /**
     * Gets the configuration for the catalog. Only Title Entities can call this API. There is a limit of 100 requests in 10
     * seconds for this API. More information about the Catalog Config can be found here:
     * https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/settings
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetCatalogConfig(FEconomyGetCatalogConfigRequest request,
            FDelegateOnSuccessGetCatalogConfig onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetCatalogConfig(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetDraftItem, FEconomyGetDraftItemResponse, result, UObject*, customData);

    /**
     * Retrieves an item from the working catalog. This item represents the current working state of the item. GetDraftItem
     * does not work off a cache of the Catalog and should be used when trying to get recent item updates. However, please note
     * that item references data is cached and may take a few moments for changes to propagate.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetDraftItem(FEconomyGetDraftItemRequest request,
            FDelegateOnSuccessGetDraftItem onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetDraftItem(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetDraftItems, FEconomyGetDraftItemsResponse, result, UObject*, customData);

    /**
     * Retrieves a paginated list of the items from the draft catalog. Up to 50 IDs can be retrieved in a single request.
     * GetDraftItems does not work off a cache of the Catalog and should be used when trying to get recent item updates.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetDraftItems(FEconomyGetDraftItemsRequest request,
            FDelegateOnSuccessGetDraftItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetDraftItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetEntityDraftItems, FEconomyGetEntityDraftItemsResponse, result, UObject*, customData);

    /**
     * Retrieves a paginated list of the items from the draft catalog created by the Entity. Up to 50 items can be returned at
     * once. You can use continuation tokens to paginate through results that return greater than the limit.
     * GetEntityDraftItems does not work off a cache of the Catalog and should be used when trying to get recent item updates.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetEntityDraftItems(FEconomyGetEntityDraftItemsRequest request,
            FDelegateOnSuccessGetEntityDraftItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetEntityDraftItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetEntityItemReview, FEconomyGetEntityItemReviewResponse, result, UObject*, customData);

    /**
     * Gets the submitted review for the specified item by the authenticated entity. Individual ratings and reviews data update
     * in near real time with delays within a few seconds.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetEntityItemReview(FEconomyGetEntityItemReviewRequest request,
            FDelegateOnSuccessGetEntityItemReview onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetEntityItemReview(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetItem, FEconomyGetItemResponse, result, UObject*, customData);

    /**
     * Retrieves an item from the public catalog. GetItem does not work off a cache of the Catalog and should be used when
     * trying to get recent item updates. However, please note that item references data is cached and may take a few moments
     * for changes to propagate.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetItem(FEconomyGetItemRequest request,
            FDelegateOnSuccessGetItem onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetItem(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetItemContainers, FEconomyGetItemContainersResponse, result, UObject*, customData);

    /**
     * Search for a given item and return a set of bundles and stores containing the item. Up to 50 items can be returned at
     * once. You can use continuation tokens to paginate through results that return greater than the limit. This API is
     * intended for tooling/automation scenarios and has a reduced RPS with Player Entities limited to 30 requests in 300
     * seconds and Title Entities limited to 100 requests in 10 seconds.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetItemContainers(FEconomyGetItemContainersRequest request,
            FDelegateOnSuccessGetItemContainers onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetItemContainers(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetItemModerationState, FEconomyGetItemModerationStateResponse, result, UObject*, customData);

    /**
     * Gets the moderation state for an item, including the concern category and string reason. More information about
     * moderation states can be found here: https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/ugc/moderation
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetItemModerationState(FEconomyGetItemModerationStateRequest request,
            FDelegateOnSuccessGetItemModerationState onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetItemModerationState(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetItemPublishStatus, FEconomyGetItemPublishStatusResponse, result, UObject*, customData);

    /** Gets the status of a publish of an item. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetItemPublishStatus(FEconomyGetItemPublishStatusRequest request,
            FDelegateOnSuccessGetItemPublishStatus onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetItemPublishStatus(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetItemReviews, FEconomyGetItemReviewsResponse, result, UObject*, customData);

    /**
     * Get a paginated set of reviews associated with the specified item. Individual ratings and reviews data update in near
     * real time with delays within a few seconds.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetItemReviews(FEconomyGetItemReviewsRequest request,
            FDelegateOnSuccessGetItemReviews onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetItemReviews(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetItemReviewSummary, FEconomyGetItemReviewSummaryResponse, result, UObject*, customData);

    /**
     * Get a summary of all ratings and reviews associated with the specified item. Summary ratings data is cached with update
     * data coming within 15 minutes.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetItemReviewSummary(FEconomyGetItemReviewSummaryRequest request,
            FDelegateOnSuccessGetItemReviewSummary onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetItemReviewSummary(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetItems, FEconomyGetItemsResponse, result, UObject*, customData);

    /**
     * Retrieves items from the public catalog. Up to 50 items can be returned at once. GetItems does not work off a cache of
     * the Catalog and should be used when trying to get recent item updates. However, please note that item references data is
     * cached and may take a few moments for changes to propagate.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetItems(FEconomyGetItemsRequest request,
            FDelegateOnSuccessGetItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessPublishDraftItem, FEconomyPublishDraftItemResponse, result, UObject*, customData);

    /**
     * Initiates a publish of an item from the working catalog to the public catalog. You can use the GetItemPublishStatus API
     * to track the state of the item publish.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* PublishDraftItem(FEconomyPublishDraftItemRequest request,
            FDelegateOnSuccessPublishDraftItem onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperPublishDraftItem(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessReportItem, FEconomyReportItemResponse, result, UObject*, customData);

    /** Submit a report for an item, indicating in what way the item is inappropriate. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* ReportItem(FEconomyReportItemRequest request,
            FDelegateOnSuccessReportItem onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperReportItem(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessReportItemReview, FEconomyReportItemReviewResponse, result, UObject*, customData);

    /** Submit a report for a review */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* ReportItemReview(FEconomyReportItemReviewRequest request,
            FDelegateOnSuccessReportItemReview onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperReportItemReview(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessReviewItem, FEconomyReviewItemResponse, result, UObject*, customData);

    /**
     * Creates or updates a review for the specified item. More information around the caching surrounding item ratings and
     * reviews can be found here:
     * https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/catalog/ratings#ratings-design-and-caching
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* ReviewItem(FEconomyReviewItemRequest request,
            FDelegateOnSuccessReviewItem onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperReviewItem(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSearchItems, FEconomySearchItemsResponse, result, UObject*, customData);

    /**
     * Executes a search against the public catalog using the provided search parameters and returns a set of paginated
     * results. SearchItems uses a cache of the catalog with item updates taking up to a few minutes to propagate. You should
     * use the GetItem API for when trying to immediately get recent item updates. More information about the Search API can be
     * found here: https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/catalog/search
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* SearchItems(FEconomySearchItemsRequest request,
            FDelegateOnSuccessSearchItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSearchItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetItemModerationState, FEconomySetItemModerationStateResponse, result, UObject*, customData);

    /**
     * Sets the moderation state for an item, including the concern category and string reason. More information about
     * moderation states can be found here: https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/ugc/moderation
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* SetItemModerationState(FEconomySetItemModerationStateRequest request,
            FDelegateOnSuccessSetItemModerationState onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetItemModerationState(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSubmitItemReviewVote, FEconomySubmitItemReviewVoteResponse, result, UObject*, customData);

    /** Submit a vote for a review, indicating whether the review was helpful or unhelpful. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* SubmitItemReviewVote(FEconomySubmitItemReviewVoteRequest request,
            FDelegateOnSuccessSubmitItemReviewVote onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSubmitItemReviewVote(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessTakedownItemReviews, FEconomyTakedownItemReviewsResponse, result, UObject*, customData);

    /** Submit a request to takedown one or more reviews. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* TakedownItemReviews(FEconomyTakedownItemReviewsRequest request,
            FDelegateOnSuccessTakedownItemReviews onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperTakedownItemReviews(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateCatalogConfig, FEconomyUpdateCatalogConfigResponse, result, UObject*, customData);

    /**
     * Updates the configuration for the catalog. Only Title Entities can call this API. There is a limit of 10 requests in 10
     * seconds for this API. More information about the Catalog Config can be found here:
     * https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/settings
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* UpdateCatalogConfig(FEconomyUpdateCatalogConfigRequest request,
            FDelegateOnSuccessUpdateCatalogConfig onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateCatalogConfig(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateDraftItem, FEconomyUpdateDraftItemResponse, result, UObject*, customData);

    /** Update the metadata for an item in the working catalog. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* UpdateDraftItem(FEconomyUpdateDraftItemRequest request,
            FDelegateOnSuccessUpdateDraftItem onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateDraftItem(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Inventory
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAddInventoryItems, FEconomyAddInventoryItemsResponse, result, UObject*, customData);

    /** Add inventory items. Up to 3500 stacks of items can be added to a single inventory collection. Stack size is uncapped. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* AddInventoryItems(FEconomyAddInventoryItemsRequest request,
            FDelegateOnSuccessAddInventoryItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAddInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteInventoryCollection, FEconomyDeleteInventoryCollectionResponse, result, UObject*, customData);

    /**
     * Delete an Inventory Collection. More information about Inventory Collections can be found here:
     * https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/inventory/collections
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* DeleteInventoryCollection(FEconomyDeleteInventoryCollectionRequest request,
            FDelegateOnSuccessDeleteInventoryCollection onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteInventoryCollection(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteInventoryItems, FEconomyDeleteInventoryItemsResponse, result, UObject*, customData);

    /** Delete inventory items */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* DeleteInventoryItems(FEconomyDeleteInventoryItemsRequest request,
            FDelegateOnSuccessDeleteInventoryItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessExecuteInventoryOperations, FEconomyExecuteInventoryOperationsResponse, result, UObject*, customData);

    /**
     * Execute a list of Inventory Operations. A maximum list of 10 operations can be performed by a single request. There is
     * also a limit to 250 items that can be modified/added in a single request. For example, adding a bundle with 50 items
     * counts as 50 items modified. All operations must be done within a single inventory collection. This API has a reduced
     * RPS compared to an individual inventory operation with Player Entities limited to 15 requests in 90 seconds and Title
     * Entities limited to 500 requests in 10 seconds.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* ExecuteInventoryOperations(FEconomyExecuteInventoryOperationsRequest request,
            FDelegateOnSuccessExecuteInventoryOperations onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperExecuteInventoryOperations(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessExecuteTransferOperations, FEconomyExecuteTransferOperationsResponse, result, UObject*, customData);

    /**
     * Transfer a list of inventory items. A maximum list of 50 operations can be performed by a single request. When the
     * response code is 202, one or more operations did not complete within the timeframe of the request. You can identify the
     * pending operations by looking for OperationStatus = 'InProgress'. You can check on the operation status at anytime
     * within 1 day of the request by passing the TransactionToken to the GetInventoryOperationStatus API.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* ExecuteTransferOperations(FEconomyExecuteTransferOperationsRequest request,
            FDelegateOnSuccessExecuteTransferOperations onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperExecuteTransferOperations(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetInventoryCollectionIds, FEconomyGetInventoryCollectionIdsResponse, result, UObject*, customData);

    /**
     * Get Inventory Collection Ids. Up to 50 Ids can be returned at once. You can use continuation tokens to paginate through
     * results that return greater than the limit. It can take a few seconds for new collection Ids to show up.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetInventoryCollectionIds(FEconomyGetInventoryCollectionIdsRequest request,
            FDelegateOnSuccessGetInventoryCollectionIds onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetInventoryCollectionIds(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetInventoryItems, FEconomyGetInventoryItemsResponse, result, UObject*, customData);

    /** Get current inventory items. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetInventoryItems(FEconomyGetInventoryItemsRequest request,
            FDelegateOnSuccessGetInventoryItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetInventoryOperationStatus, FEconomyGetInventoryOperationStatusResponse, result, UObject*, customData);

    /**
     * Get the status of an inventory operation using an OperationToken. You can check on the operation status at anytime
     * within 1 day of the request by passing the TransactionToken to the this API.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetInventoryOperationStatus(FEconomyGetInventoryOperationStatusRequest request,
            FDelegateOnSuccessGetInventoryOperationStatus onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetInventoryOperationStatus(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetMicrosoftStoreAccessTokens, FEconomyGetMicrosoftStoreAccessTokensResponse, result, UObject*, customData);

    /** Gets the access tokens. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetMicrosoftStoreAccessTokens(FEconomyGetMicrosoftStoreAccessTokensRequest request,
            FDelegateOnSuccessGetMicrosoftStoreAccessTokens onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetMicrosoftStoreAccessTokens(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetTransactionHistory, FEconomyGetTransactionHistoryResponse, result, UObject*, customData);

    /**
     * Get transaction history for a player. Up to 50 Events can be returned at once. You can use continuation tokens to
     * paginate through results that return greater than the limit. Getting transaction history has a lower RPS limit than
     * getting a Player's inventory with Player Entities having a limit of 30 requests in 300 seconds and Title Entities having
     * a limit of 100 requests in 10 seconds.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetTransactionHistory(FEconomyGetTransactionHistoryRequest request,
            FDelegateOnSuccessGetTransactionHistory onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetTransactionHistory(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessPurchaseInventoryItems, FEconomyPurchaseInventoryItemsResponse, result, UObject*, customData);

    /**
     * Purchase an item or bundle. Up to 3500 stacks of items can be added to a single inventory collection. Stack size is
     * uncapped.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* PurchaseInventoryItems(FEconomyPurchaseInventoryItemsRequest request,
            FDelegateOnSuccessPurchaseInventoryItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperPurchaseInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRedeemAppleAppStoreInventoryItems, FEconomyRedeemAppleAppStoreInventoryItemsResponse, result, UObject*, customData);

    /** Redeem items. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* RedeemAppleAppStoreInventoryItems(FEconomyRedeemAppleAppStoreInventoryItemsRequest request,
            FDelegateOnSuccessRedeemAppleAppStoreInventoryItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRedeemAppleAppStoreInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRedeemGooglePlayInventoryItems, FEconomyRedeemGooglePlayInventoryItemsResponse, result, UObject*, customData);

    /** Redeem items. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* RedeemGooglePlayInventoryItems(FEconomyRedeemGooglePlayInventoryItemsRequest request,
            FDelegateOnSuccessRedeemGooglePlayInventoryItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRedeemGooglePlayInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRedeemMicrosoftStoreInventoryItems, FEconomyRedeemMicrosoftStoreInventoryItemsResponse, result, UObject*, customData);

    /** Redeem items. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* RedeemMicrosoftStoreInventoryItems(FEconomyRedeemMicrosoftStoreInventoryItemsRequest request,
            FDelegateOnSuccessRedeemMicrosoftStoreInventoryItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRedeemMicrosoftStoreInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRedeemNintendoEShopInventoryItems, FEconomyRedeemNintendoEShopInventoryItemsResponse, result, UObject*, customData);

    /** Redeem items. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* RedeemNintendoEShopInventoryItems(FEconomyRedeemNintendoEShopInventoryItemsRequest request,
            FDelegateOnSuccessRedeemNintendoEShopInventoryItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRedeemNintendoEShopInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRedeemPlayStationStoreInventoryItems, FEconomyRedeemPlayStationStoreInventoryItemsResponse, result, UObject*, customData);

    /** Redeem items. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* RedeemPlayStationStoreInventoryItems(FEconomyRedeemPlayStationStoreInventoryItemsRequest request,
            FDelegateOnSuccessRedeemPlayStationStoreInventoryItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRedeemPlayStationStoreInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRedeemSteamInventoryItems, FEconomyRedeemSteamInventoryItemsResponse, result, UObject*, customData);

    /** Redeem items. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* RedeemSteamInventoryItems(FEconomyRedeemSteamInventoryItemsRequest request,
            FDelegateOnSuccessRedeemSteamInventoryItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRedeemSteamInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSubtractInventoryItems, FEconomySubtractInventoryItemsResponse, result, UObject*, customData);

    /** Subtract inventory items. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* SubtractInventoryItems(FEconomySubtractInventoryItemsRequest request,
            FDelegateOnSuccessSubtractInventoryItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSubtractInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessTransferInventoryItems, FEconomyTransferInventoryItemsResponse, result, UObject*, customData);

    /**
     * Transfer inventory items. When transferring across collections, a 202 response indicates that the transfer did not
     * complete within the timeframe of the request. You can identify the pending operations by looking for OperationStatus =
     * 'InProgress'. You can check on the operation status at anytime within 1 day of the request by passing the
     * TransactionToken to the GetInventoryOperationStatus API. More information about item transfer scenarios can be found
     * here:
     * https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/inventory/?tabs=inventory-game-manager#transfer-inventory-items
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* TransferInventoryItems(FEconomyTransferInventoryItemsRequest request,
            FDelegateOnSuccessTransferInventoryItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperTransferInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateInventoryItems, FEconomyUpdateInventoryItemsResponse, result, UObject*, customData);

    /** Update inventory items */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* UpdateInventoryItems(FEconomyUpdateInventoryItemsRequest request,
            FDelegateOnSuccessUpdateInventoryItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful);



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
    FDelegateOnSuccessCreateDraftItem OnSuccessCreateDraftItem;
    FDelegateOnSuccessCreateUploadUrls OnSuccessCreateUploadUrls;
    FDelegateOnSuccessDeleteEntityItemReviews OnSuccessDeleteEntityItemReviews;
    FDelegateOnSuccessDeleteItem OnSuccessDeleteItem;
    FDelegateOnSuccessGetCatalogConfig OnSuccessGetCatalogConfig;
    FDelegateOnSuccessGetDraftItem OnSuccessGetDraftItem;
    FDelegateOnSuccessGetDraftItems OnSuccessGetDraftItems;
    FDelegateOnSuccessGetEntityDraftItems OnSuccessGetEntityDraftItems;
    FDelegateOnSuccessGetEntityItemReview OnSuccessGetEntityItemReview;
    FDelegateOnSuccessGetItem OnSuccessGetItem;
    FDelegateOnSuccessGetItemContainers OnSuccessGetItemContainers;
    FDelegateOnSuccessGetItemModerationState OnSuccessGetItemModerationState;
    FDelegateOnSuccessGetItemPublishStatus OnSuccessGetItemPublishStatus;
    FDelegateOnSuccessGetItemReviews OnSuccessGetItemReviews;
    FDelegateOnSuccessGetItemReviewSummary OnSuccessGetItemReviewSummary;
    FDelegateOnSuccessGetItems OnSuccessGetItems;
    FDelegateOnSuccessPublishDraftItem OnSuccessPublishDraftItem;
    FDelegateOnSuccessReportItem OnSuccessReportItem;
    FDelegateOnSuccessReportItemReview OnSuccessReportItemReview;
    FDelegateOnSuccessReviewItem OnSuccessReviewItem;
    FDelegateOnSuccessSearchItems OnSuccessSearchItems;
    FDelegateOnSuccessSetItemModerationState OnSuccessSetItemModerationState;
    FDelegateOnSuccessSubmitItemReviewVote OnSuccessSubmitItemReviewVote;
    FDelegateOnSuccessTakedownItemReviews OnSuccessTakedownItemReviews;
    FDelegateOnSuccessUpdateCatalogConfig OnSuccessUpdateCatalogConfig;
    FDelegateOnSuccessUpdateDraftItem OnSuccessUpdateDraftItem;
    FDelegateOnSuccessAddInventoryItems OnSuccessAddInventoryItems;
    FDelegateOnSuccessDeleteInventoryCollection OnSuccessDeleteInventoryCollection;
    FDelegateOnSuccessDeleteInventoryItems OnSuccessDeleteInventoryItems;
    FDelegateOnSuccessExecuteInventoryOperations OnSuccessExecuteInventoryOperations;
    FDelegateOnSuccessExecuteTransferOperations OnSuccessExecuteTransferOperations;
    FDelegateOnSuccessGetInventoryCollectionIds OnSuccessGetInventoryCollectionIds;
    FDelegateOnSuccessGetInventoryItems OnSuccessGetInventoryItems;
    FDelegateOnSuccessGetInventoryOperationStatus OnSuccessGetInventoryOperationStatus;
    FDelegateOnSuccessGetMicrosoftStoreAccessTokens OnSuccessGetMicrosoftStoreAccessTokens;
    FDelegateOnSuccessGetTransactionHistory OnSuccessGetTransactionHistory;
    FDelegateOnSuccessPurchaseInventoryItems OnSuccessPurchaseInventoryItems;
    FDelegateOnSuccessRedeemAppleAppStoreInventoryItems OnSuccessRedeemAppleAppStoreInventoryItems;
    FDelegateOnSuccessRedeemGooglePlayInventoryItems OnSuccessRedeemGooglePlayInventoryItems;
    FDelegateOnSuccessRedeemMicrosoftStoreInventoryItems OnSuccessRedeemMicrosoftStoreInventoryItems;
    FDelegateOnSuccessRedeemNintendoEShopInventoryItems OnSuccessRedeemNintendoEShopInventoryItems;
    FDelegateOnSuccessRedeemPlayStationStoreInventoryItems OnSuccessRedeemPlayStationStoreInventoryItems;
    FDelegateOnSuccessRedeemSteamInventoryItems OnSuccessRedeemSteamInventoryItems;
    FDelegateOnSuccessSubtractInventoryItems OnSuccessSubtractInventoryItems;
    FDelegateOnSuccessTransferInventoryItems OnSuccessTransferInventoryItems;
    FDelegateOnSuccessUpdateInventoryItems OnSuccessUpdateInventoryItems;

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
