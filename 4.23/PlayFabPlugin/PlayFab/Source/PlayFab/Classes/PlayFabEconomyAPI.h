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

    /** Creates one or more upload URLs which can be used by the client to upload raw file data. */
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

    /** Gets the configuration for the catalog. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetCatalogConfig(FEconomyGetCatalogConfigRequest request,
            FDelegateOnSuccessGetCatalogConfig onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetCatalogConfig(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetDraftItem, FEconomyGetDraftItemResponse, result, UObject*, customData);

    /** Retrieves an item from the working catalog. This item represents the current working state of the item. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetDraftItem(FEconomyGetDraftItemRequest request,
            FDelegateOnSuccessGetDraftItem onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetDraftItem(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetDraftItems, FEconomyGetDraftItemsResponse, result, UObject*, customData);

    /** Retrieves a paginated list of the items from the draft catalog. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetDraftItems(FEconomyGetDraftItemsRequest request,
            FDelegateOnSuccessGetDraftItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetDraftItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetEntityDraftItems, FEconomyGetEntityDraftItemsResponse, result, UObject*, customData);

    /** Retrieves a paginated list of the items from the draft catalog created by the Entity. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetEntityDraftItems(FEconomyGetEntityDraftItemsRequest request,
            FDelegateOnSuccessGetEntityDraftItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetEntityDraftItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetEntityItemReview, FEconomyGetEntityItemReviewResponse, result, UObject*, customData);

    /** Gets the submitted review for the specified item by the authenticated entity. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetEntityItemReview(FEconomyGetEntityItemReviewRequest request,
            FDelegateOnSuccessGetEntityItemReview onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetEntityItemReview(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetItem, FEconomyGetItemResponse, result, UObject*, customData);

    /** Retrieves an item from the public catalog. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetItem(FEconomyGetItemRequest request,
            FDelegateOnSuccessGetItem onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetItem(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetItemModerationState, FEconomyGetItemModerationStateResponse, result, UObject*, customData);

    /** Gets the moderation state for an item, including the concern category and string reason. */
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

    /** Get a paginated set of reviews associated with the specified item. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetItemReviews(FEconomyGetItemReviewsRequest request,
            FDelegateOnSuccessGetItemReviews onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetItemReviews(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetItemReviewSummary, FEconomyGetItemReviewSummaryResponse, result, UObject*, customData);

    /** Get a summary of all reviews associated with the specified item. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEconomyAPI* GetItemReviewSummary(FEconomyGetItemReviewSummaryRequest request,
            FDelegateOnSuccessGetItemReviewSummary onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEconomyRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetItemReviewSummary(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessPublishDraftItem, FEconomyPublishDraftItemResponse, result, UObject*, customData);

    /** Initiates a publish of an item from the working catalog to the public catalog. */
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

    /** Creates or updates a review for the specified item. */
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
     * results.
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

    /** Sets the moderation state for an item, including the concern category and string reason. */
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

    /** Updates the configuration for the catalog. */
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
    FDelegateOnSuccessGetItemModerationState OnSuccessGetItemModerationState;
    FDelegateOnSuccessGetItemPublishStatus OnSuccessGetItemPublishStatus;
    FDelegateOnSuccessGetItemReviews OnSuccessGetItemReviews;
    FDelegateOnSuccessGetItemReviewSummary OnSuccessGetItemReviewSummary;
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
