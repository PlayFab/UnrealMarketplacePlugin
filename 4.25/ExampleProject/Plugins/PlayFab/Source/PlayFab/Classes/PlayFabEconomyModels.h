//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Economy
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabRequestCommon.h"
#include "PlayFabLoginResultCommon.h"
#include "PlayFabEconomyModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Economy API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Catalog
//////////////////////////////////////////////////////

/** The item will not be published to the public catalog until the PublishItem API is called for the item. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyCreateDraftItemRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Metadata describing the new catalog item to be created. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Item = nullptr;
    /** Whether the item should be published immediately. This value is optional, defaults to false. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        bool Publish = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyCreateDraftItemResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Updated metadata describing the catalog item just created. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Item = nullptr;
};

/**
 * Upload URLs point to Azure Blobs; clients must follow the Microsoft Azure Storage Blob Service REST API pattern for
 * uploading content. The response contains upload URLs and IDs for each file. The IDs and URLs returned must be added to
 * the item metadata and committed using the CreateDraftItem or UpdateDraftItem Item APIs.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyCreateUploadUrlsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Description of the files to be uploaded by the client. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        TArray<UPlayFabJsonObject*> Files;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyCreateUploadUrlsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of URLs metadata for the files to be uploaded by the client. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        TArray<UPlayFabJsonObject*> UploadUrls;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyDeleteEntityItemReviewsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyDeleteEntityItemReviewsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyDeleteItemRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** An alternate ID associated with this item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* AlternateId = nullptr;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The unique ID of the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Id;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyDeleteItemResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetCatalogConfigRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetCatalogConfigResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The catalog configuration. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Config = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetDraftItemRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** An alternate ID associated with this item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* AlternateId = nullptr;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The unique ID of the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Id;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetDraftItemResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Full metadata of the catalog item requested. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Item = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetDraftItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of item alternate IDs. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        TArray<UPlayFabJsonObject*> AlternateIds;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** List of Item Ids. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Ids;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetDraftItemsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** An opaque token used to retrieve the next page of items, if any are available. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString ContinuationToken;
    /** A set of items created by the entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        TArray<UPlayFabJsonObject*> Items;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetEntityDraftItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * An opaque token used to retrieve the next page of items created by the caller, if any are available. Should be null on
     * initial request.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString ContinuationToken;
    /** Number of items to retrieve. This value is optional. Default value is 10. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        int32 Count = 0;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Entity = nullptr;
    /**
     * OData Filter to refine the items returned. CatalogItem properties 'type' can be used in the filter. For example: "type
     * eq 'ugc'"
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Filter;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetEntityDraftItemsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** An opaque token used to retrieve the next page of items, if any are available. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString ContinuationToken;
    /** A set of items created by the entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        TArray<UPlayFabJsonObject*> Items;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetEntityItemReviewRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** An alternate ID associated with this item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* AlternateId = nullptr;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The unique ID of the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Id;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetEntityItemReviewResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The review the entity submitted for the requested item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Review = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetItemRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** An alternate ID associated with this item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* AlternateId = nullptr;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The unique ID of the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Id;
};

/** Get item result. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetItemResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The item result. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Item = nullptr;
};

/** Given an item, return a set of bundles and stores containing the item. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetItemContainersRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** An alternate ID associated with this item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* AlternateId = nullptr;
    /**
     * An opaque token used to retrieve the next page of items in the inventory, if any are available. Should be null on
     * initial request.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString ContinuationToken;
    /** Number of items to retrieve. This value is optional. Default value is 10. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        int32 Count = 0;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The unique ID of the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Id;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetItemContainersResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of Bundles and Stores containing the requested items. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        TArray<UPlayFabJsonObject*> Containers;
    /** An opaque token used to retrieve the next page of items, if any are available. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString ContinuationToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetItemModerationStateRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** An alternate ID associated with this item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* AlternateId = nullptr;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The unique ID of the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Id;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetItemModerationStateResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The current moderation state for the requested item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* State = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetItemPublishStatusRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** An alternate ID associated with this item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* AlternateId = nullptr;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The unique ID of the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Id;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetItemPublishStatusResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** High level status of the published item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        EPublishResult Result = StaticCast<EPublishResult>(0);
    /** Descriptive message about the current status of the publish. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString StatusMessage;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetItemReviewsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** An alternate ID associated with this item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* AlternateId = nullptr;
    /** An opaque token used to retrieve the next page of items, if any are available. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString ContinuationToken;
    /** Number of items to retrieve. This value is optional. Default value is 10. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        int32 Count = 0;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The unique ID of the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Id;
    /**
     * An OData orderBy used to order the results of the query. Possible values are Helpfulness, Rating, and Submitted (For
     * example: "Submitted desc")
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString OrderBy;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetItemReviewsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** An opaque token used to retrieve the next page of items, if any are available. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString ContinuationToken;
    /** The paginated set of results. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        TArray<UPlayFabJsonObject*> Reviews;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetItemReviewSummaryRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** An alternate ID associated with this item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* AlternateId = nullptr;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The unique ID of the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Id;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetItemReviewSummaryResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The least favorable review for this item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* LeastFavorableReview = nullptr;
    /** The most favorable review for this item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* MostFavorableReview = nullptr;
    /** The summary of ratings associated with this item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Rating = nullptr;
    /** The total number of reviews associated with this item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        int32 ReviewsCount = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of item alternate IDs. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        TArray<UPlayFabJsonObject*> AlternateIds;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** List of Item Ids. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Ids;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetItemsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Metadata of set of items. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        TArray<UPlayFabJsonObject*> Items;
};

/**
 * The call kicks off a workflow to publish the item to the public catalog. The Publish Status API should be used to
 * monitor the publish job.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyPublishDraftItemRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** An alternate ID associated with this item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* AlternateId = nullptr;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Entity = nullptr;
    /**
     * ETag of the catalog item to published from the working catalog to the public catalog. Used for optimistic concurrency.
     * If the provided ETag does not match the ETag in the current working catalog, the request will be rejected. If not
     * provided, the current version of the document in the working catalog will be published.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString ETag;
    /** The unique ID of the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Id;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyPublishDraftItemResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyReportItemRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** An alternate ID associated with this item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* AlternateId = nullptr;
    /** Category of concern for this report. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        EConcernCategory ConcernCategory = StaticCast<EConcernCategory>(0);
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The unique ID of the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Id;
    /** The string reason for this report. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Reason;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyReportItemResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/** Submit a report for an inappropriate review, allowing the submitting user to specify their concern. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyReportItemReviewRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** An alternate ID of the item associated with the review. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* AlternateId = nullptr;
    /** The reason this review is being reported. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        EConcernCategory ConcernCategory = StaticCast<EConcernCategory>(0);
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The string ID of the item associated with the review. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString ItemId;
    /** The string reason for this report. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Reason;
    /** The ID of the review to submit a report for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString ReviewId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyReportItemReviewResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyReviewItemRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** An alternate ID associated with this item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* AlternateId = nullptr;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The unique ID of the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Id;
    /** The review to submit. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Review = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyReviewItemResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomySearchItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** An opaque token used to retrieve the next page of items, if any are available. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString ContinuationToken;
    /** Number of items to retrieve. This value is optional. Maximum page size is 50. Default value is 10. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        int32 Count = 0;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Entity = nullptr;
    /**
     * An OData filter used to refine the search query (For example: "type eq 'ugc'"). More info about Filter Complexity limits
     * can be found here: https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/catalog/search#limits
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Filter;
    /** The locale to be returned in the result. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Language;
    /** An OData orderBy used to order the results of the search query. For example: "rating/average asc" */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString OrderBy;
    /** The text to search for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Search;
    /**
     * An OData select query option used to augment the search results. If not defined, the default search result metadata will
     * be returned.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Select;
    /** The store to restrict the search request to. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Store = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomySearchItemsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** An opaque token used to retrieve the next page of items, if any are available. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString ContinuationToken;
    /** The paginated set of results for the search query. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        TArray<UPlayFabJsonObject*> Items;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomySetItemModerationStateRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** An alternate ID associated with this item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* AlternateId = nullptr;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The unique ID of the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Id;
    /** The reason for the moderation state change for the associated item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Reason;
    /** The status to set for the associated item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        EModerationStatus Status = StaticCast<EModerationStatus>(0);
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomySetItemModerationStateResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomySubmitItemReviewVoteRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** An alternate ID of the item associated with the review. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* AlternateId = nullptr;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The string ID of the item associated with the review. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString ItemId;
    /** The ID of the review to submit a helpfulness vote for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString ReviewId;
    /** The helpfulness vote of the review. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        EHelpfulnessVote Vote = StaticCast<EHelpfulnessVote>(0);
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomySubmitItemReviewVoteResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * Submit a request to takedown one or more reviews, removing them from public view. Authors will still be able to see
 * their reviews after being taken down.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyTakedownItemReviewsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The set of reviews to take down. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        TArray<UPlayFabJsonObject*> Reviews;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyTakedownItemReviewsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyUpdateCatalogConfigRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The updated catalog configuration. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Config = nullptr;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyUpdateCatalogConfigResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyUpdateDraftItemRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Updated metadata describing the catalog item to be updated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Item = nullptr;
    /** Whether the item should be published immediately. This value is optional, defaults to false. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        bool Publish = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyUpdateDraftItemResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Updated metadata describing the catalog item just updated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Item = nullptr;
};


///////////////////////////////////////////////////////
// Inventory
//////////////////////////////////////////////////////

/** Given an entity type, entity identifier and container details, will add the specified inventory items. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyAddInventoryItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The amount to add for the current item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        int32 Amount = 0;
    /**
     * The id of the entity's collection to perform this action on. (Default="default"). The number of inventory collections is
     * unlimited.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString CollectionId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The duration to add to the current item expiration date. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        int32 DurationInSeconds = 0;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* Entity = nullptr;
    /**
     * ETags are used for concurrency checking when updating resources. More information about using ETags can be found here:
     * https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/catalog/etags
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ETag;
    /**
     * The Idempotency ID for this request. Idempotency IDs can be used to prevent operation replay in the medium term but will
     * be garbage collected eventually.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString IdempotencyId;
    /** The inventory item the request applies to. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* Item = nullptr;
    /** The values to apply to a stack newly created by this request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* NewStackValues = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyAddInventoryItemsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * ETags are used for concurrency checking when updating resources. More information about using ETags can be found here:
     * https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/catalog/etags
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ETag;
    /** The idempotency id used in the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString IdempotencyId;
    /** The ids of transactions that occurred as a result of the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString TransactionIds;
};

/** Delete an Inventory Collection by the specified Id for an Entity */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyDeleteInventoryCollectionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The inventory collection id the request applies to. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString CollectionId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity the request is about. Set to the caller by default. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* Entity = nullptr;
    /**
     * ETags are used for concurrency checking when updating resources. More information about using ETags can be found here:
     * https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/catalog/etags
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ETag;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyDeleteInventoryCollectionResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/** Given an entity type, entity identifier and container details, will delete the entity's inventory items */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyDeleteInventoryItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * The id of the entity's collection to perform this action on. (Default="default"). The number of inventory collections is
     * unlimited.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString CollectionId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* Entity = nullptr;
    /**
     * ETags are used for concurrency checking when updating resources. More information about using ETags can be found here:
     * https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/catalog/etags
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ETag;
    /**
     * The Idempotency ID for this request. Idempotency IDs can be used to prevent operation replay in the medium term but will
     * be garbage collected eventually.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString IdempotencyId;
    /** The inventory item the request applies to. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* Item = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyDeleteInventoryItemsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** ETags are used for concurrency checking when updating resources. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ETag;
    /** The idempotency id used in the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString IdempotencyId;
    /** The ids of transactions that occurred as a result of the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString TransactionIds;
};

/** Execute a list of Inventory Operations for an Entity */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyExecuteInventoryOperationsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * The id of the entity's collection to perform this action on. (Default="default"). The number of inventory collections is
     * unlimited.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString CollectionId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* Entity = nullptr;
    /**
     * ETags are used for concurrency checking when updating resources. More information about using ETags can be found here:
     * https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/catalog/etags
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ETag;
    /**
     * The Idempotency ID for this request. Idempotency IDs can be used to prevent operation replay in the medium term but will
     * be garbage collected eventually.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString IdempotencyId;
    /**
     * The operations to run transactionally. The operations will be executed in-order sequentially and will succeed or fail as
     * a batch. Up to 10 operations can be added.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        TArray<UPlayFabJsonObject*> Operations;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyExecuteInventoryOperationsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * ETags are used for concurrency checking when updating resources. More information about using ETags can be found here:
     * https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/catalog/etags
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ETag;
    /** The idempotency id used in the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString IdempotencyId;
    /** The ids of the transactions that occurred as a result of the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString TransactionIds;
};

/** Transfer the specified list of inventory items of an entity's container Id to another entity's container Id. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyExecuteTransferOperationsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The inventory collection id the request is transferring from. (Default="default") */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString GivingCollectionId;
    /** The entity the request is transferring from. Set to the caller by default. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* GivingEntity = nullptr;
    /**
     * ETags are used for concurrency checking when updating resources. More information about using ETags can be found here:
     * https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/catalog/etags
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString GivingETag;
    /** The idempotency id for the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString IdempotencyId;
    /**
     * The transfer operations to run transactionally. The operations will be executed in-order sequentially and will succeed
     * or fail as a batch. Up to 50 operations can be added.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        TArray<UPlayFabJsonObject*> Operations;
    /** The inventory collection id the request is transferring to. (Default="default") */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ReceivingCollectionId;
    /** The entity the request is transferring to. Set to the caller by default. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* ReceivingEntity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyExecuteTransferOperationsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * ETags are used for concurrency checking when updating resources (before transferring from). This value will be empty if
     * the operation has not completed yet. More information about using ETags can be found here:
     * https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/catalog/etags
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString GivingETag;
    /** The ids of transactions that occurred as a result of the request's giving action. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString GivingTransactionIds;
    /** The Idempotency ID for this request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString IdempotencyId;
    /**
     * The transfer operation status. Possible values are 'InProgress' or 'Completed'. If the operation has completed, the
     * response code will be 200. Otherwise, it will be 202.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString OperationStatus;
    /**
     * The token that can be used to get the status of the transfer operation. This will only have a value if OperationStatus
     * is 'InProgress'.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString OperationToken;
    /**
     * ETags are used for concurrency checking when updating resources (before transferring to). This value will be empty if
     * the operation has not completed yet.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ReceivingETag;
    /** The ids of transactions that occurred as a result of the request's receiving action. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ReceivingTransactionIds;
};

/** Get a list of Inventory Collection Ids for the specified Entity */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetInventoryCollectionIdsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** An opaque token used to retrieve the next page of collection ids, if any are available. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ContinuationToken;
    /** Number of items to retrieve. This value is optional. The default value is 10 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        int32 Count = 0;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity the request is about. Set to the caller by default. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetInventoryCollectionIdsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The requested inventory collection ids. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString CollectionIds;
    /** An opaque token used to retrieve the next page of collection ids, if any are available. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ContinuationToken;
};

/** Given an entity type, entity identifier and container details, will get the entity's inventory items. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetInventoryItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The id of the entity's collection to perform this action on. (Default="default") */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString CollectionId;
    /**
     * An opaque token used to retrieve the next page of items in the inventory, if any are available. Should be null on
     * initial request.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ContinuationToken;
    /** Number of items to retrieve. This value is optional. Maximum page size is 50. The default value is 10 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        int32 Count = 0;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* Entity = nullptr;
    /**
     * OData Filter to refine the items returned. InventoryItem properties 'type', 'id', and 'stackId' can be used in the
     * filter. For example: "type eq 'currency'"
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString Filter;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetInventoryItemsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** An opaque token used to retrieve the next page of items, if any are available. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ContinuationToken;
    /**
     * ETags are used for concurrency checking when updating resources. More information about using ETags can be found here:
     * https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/catalog/etags
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ETag;
    /** The requested inventory items. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        TArray<UPlayFabJsonObject*> Items;
};

/** Get the status of an Inventory Operation using an OperationToken. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetInventoryOperationStatusRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The id of the entity's collection to perform this action on. (Default="default") */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString CollectionId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetInventoryOperationStatusResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The inventory operation status. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString OperationStatus;
};

/** Gets the access tokens for Microsoft Store authentication. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetMicrosoftStoreAccessTokensRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetMicrosoftStoreAccessTokensResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * The collections access token for calling https://onestore.microsoft.com/b2b/keys/create/collections to obtain a
     * CollectionsIdKey for the user
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString CollectionsAccessToken;
    /** The date the collections access token expires */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString CollectionsAccessTokenExpirationDate;
};

/** Get transaction history for specified entity and collection. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetTransactionHistoryRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The id of the entity's collection to perform this action on. (Default="default") */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString CollectionId;
    /** An opaque token used to retrieve the next page of items, if any are available. Should be null on initial request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ContinuationToken;
    /** Number of items to retrieve. This value is optional. The default value is 10 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        int32 Count = 0;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* Entity = nullptr;
    /**
     * An OData filter used to refine the TransactionHistory. Transaction properties 'timestamp', 'transactionid', 'apiname'
     * and 'operationtype' can be used in the filter. Properties 'transactionid', 'apiname', and 'operationtype' cannot be used
     * together in a single request. The 'timestamp' property can be combined with 'apiname' or 'operationtype' in a single
     * request. For example: "timestamp ge 2023-06-20T23:30Z" or "transactionid eq '10'" or "(timestamp ge 2023-06-20T23:30Z)
     * and (apiname eq 'AddInventoryItems')". By default, a 6 month timespan from the current date is used.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString Filter;
    /**
     * An OData orderby to order TransactionHistory results. The only supported values are 'timestamp asc' or 'timestamp desc'.
     * Default orderby is 'timestamp asc'
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString OrderBy;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyGetTransactionHistoryResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** An opaque token used to retrieve the next page of items, if any are available. Should be null on initial request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ContinuationToken;
    /** The requested inventory transactions. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        TArray<UPlayFabJsonObject*> Transactions;
};

/** Purchase a single item or bundle, paying the associated price. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyPurchaseInventoryItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The amount to purchase. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        int32 Amount = 0;
    /**
     * The id of the entity's collection to perform this action on. (Default="default"). The number of inventory collections is
     * unlimited.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString CollectionId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Indicates whether stacks reduced to an amount of 0 during the request should be deleted from the inventory.
     * (Default=false)
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        bool DeleteEmptyStacks = false;
    /** The duration to purchase. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        int32 DurationInSeconds = 0;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* Entity = nullptr;
    /**
     * ETags are used for concurrency checking when updating resources. More information about using ETags can be found here:
     * https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/catalog/etags
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ETag;
    /**
     * The Idempotency ID for this request. Idempotency IDs can be used to prevent operation replay in the medium term but will
     * be garbage collected eventually.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString IdempotencyId;
    /** The inventory item the request applies to. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* Item = nullptr;
    /** The values to apply to a stack newly created by this request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* NewStackValues = nullptr;
    /**
     * The per-item price the item is expected to be purchased at. This must match a value configured in the Catalog or
     * specified Store.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        TArray<UPlayFabJsonObject*> PriceAmounts;
    /** The id of the Store to purchase the item from. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString StoreId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyPurchaseInventoryItemsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * ETags are used for concurrency checking when updating resources. More information about using ETags can be found here:
     * https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/catalog/etags
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ETag;
    /** The idempotency id used in the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString IdempotencyId;
    /** The ids of transactions that occurred as a result of the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString TransactionIds;
};

/** Redeem items from the Apple App Store. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyRedeemAppleAppStoreInventoryItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The id of the entity's collection to perform this action on. (Default="default") */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString CollectionId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The receipt provided by the Apple marketplace upon successful purchase. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString Receipt;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyRedeemAppleAppStoreInventoryItemsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of failed redemptions from the external marketplace. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        TArray<UPlayFabJsonObject*> Failed;
    /** The list of successful redemptions from the external marketplace. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        TArray<UPlayFabJsonObject*> Succeeded;
    /** The Transaction IDs associated with the inventory modifications */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString TransactionIds;
};

/** Redeem items from the Google Play Store. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyRedeemGooglePlayInventoryItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The id of the entity's collection to perform this action on. (Default="default") */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString CollectionId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The list of purchases to redeem */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        TArray<UPlayFabJsonObject*> Purchases;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyRedeemGooglePlayInventoryItemsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of failed redemptions from the external marketplace. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        TArray<UPlayFabJsonObject*> Failed;
    /** The list of successful redemptions from the external marketplace. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        TArray<UPlayFabJsonObject*> Succeeded;
    /** The Transaction IDs associated with the inventory modifications */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString TransactionIds;
};

/** Redeem items from the Microsoft Store. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyRedeemMicrosoftStoreInventoryItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The id of the entity's collection to perform this action on. (Default="default") */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString CollectionId;
    /** The OneStore Collections Id Key used for AAD authentication. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString CollectionsIdKey;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* Entity = nullptr;
    /**
     * Xbox Token used for delegated business partner authentication. Token provided by the Xbox Live SDK method
     * GetTokenAndSignatureAsync("POST", "https://playfabapi.com/", "").
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString XboxToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyRedeemMicrosoftStoreInventoryItemsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of failed redemptions from the external marketplace. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        TArray<UPlayFabJsonObject*> Failed;
    /** The list of successful redemptions from the external marketplace. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        TArray<UPlayFabJsonObject*> Succeeded;
    /** The Transaction IDs associated with the inventory modifications */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString TransactionIds;
};

/** Redeem items from the Nintendo EShop. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyRedeemNintendoEShopInventoryItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The id of the entity's collection to perform this action on. (Default="default") */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString CollectionId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The Nintendo provided token authorizing redemption */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString NintendoServiceAccountIdToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyRedeemNintendoEShopInventoryItemsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of failed redemptions from the external marketplace. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        TArray<UPlayFabJsonObject*> Failed;
    /** The list of successful redemptions from the external marketplace. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        TArray<UPlayFabJsonObject*> Succeeded;
    /** The Transaction IDs associated with the inventory modifications */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString TransactionIds;
};

/** Redeem items from the PlayStation Store. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyRedeemPlayStationStoreInventoryItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Auth code returned by PlayStation :tm: Network OAuth system. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString AuthorizationCode;
    /** The id of the entity's collection to perform this action on. (Default="default") */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString CollectionId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** Redirect URI supplied to PlayStation :tm: Network when requesting an auth code */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString RedirectUri;
    /** Optional Service Label to pass into the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ServiceLabel;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyRedeemPlayStationStoreInventoryItemsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of failed redemptions from the external marketplace. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        TArray<UPlayFabJsonObject*> Failed;
    /** The list of successful redemptions from the external marketplace. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        TArray<UPlayFabJsonObject*> Succeeded;
    /** The Transaction IDs associated with the inventory modifications */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString TransactionIds;
};

/** Redeem inventory items from Steam. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyRedeemSteamInventoryItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The id of the entity's collection to perform this action on. (Default="default") */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString CollectionId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyRedeemSteamInventoryItemsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of failed redemptions from the external marketplace. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        TArray<UPlayFabJsonObject*> Failed;
    /** The list of successful redemptions from the external marketplace. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        TArray<UPlayFabJsonObject*> Succeeded;
    /** The Transaction IDs associated with the inventory modifications */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString TransactionIds;
};

/** Given an entity type, entity identifier and container details, will subtract the specified inventory items. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomySubtractInventoryItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The amount to subtract for the current item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        int32 Amount = 0;
    /**
     * The id of the entity's collection to perform this action on. (Default="default"). The number of inventory collections is
     * unlimited.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString CollectionId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Indicates whether stacks reduced to an amount of 0 during the request should be deleted from the inventory.
     * (Default=false)
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        bool DeleteEmptyStacks = false;
    /** The duration to subtract from the current item expiration date. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        int32 DurationInSeconds = 0;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* Entity = nullptr;
    /**
     * ETags are used for concurrency checking when updating resources. More information about using ETags can be found here:
     * https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/catalog/etags
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ETag;
    /**
     * The Idempotency ID for this request. Idempotency IDs can be used to prevent operation replay in the medium term but will
     * be garbage collected eventually.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString IdempotencyId;
    /** The inventory item the request applies to. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* Item = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomySubtractInventoryItemsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * ETags are used for concurrency checking when updating resources. More information about using ETags can be found here:
     * https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/catalog/etags
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ETag;
    /** The idempotency id used in the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString IdempotencyId;
    /** The ids of transactions that occurred as a result of the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString TransactionIds;
};

/** Transfer the specified inventory items of an entity's container Id to another entity's container Id. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyTransferInventoryItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The amount to transfer . */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        int32 Amount = 0;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Indicates whether stacks reduced to an amount of 0 during the request should be deleted from the inventory. (Default =
     * false)
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        bool DeleteEmptyStacks = false;
    /** The inventory collection id the request is transferring from. (Default="default") */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString GivingCollectionId;
    /** The entity the request is transferring from. Set to the caller by default. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* GivingEntity = nullptr;
    /**
     * ETags are used for concurrency checking when updating resources (before transferring from). More information about using
     * ETags can be found here: https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/catalog/etags
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString GivingETag;
    /** The inventory item the request is transferring from. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* GivingItem = nullptr;
    /** The idempotency id for the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString IdempotencyId;
    /** The values to apply to a stack newly created by this request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* NewStackValues = nullptr;
    /** The inventory collection id the request is transferring to. (Default="default") */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ReceivingCollectionId;
    /** The entity the request is transferring to. Set to the caller by default. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* ReceivingEntity = nullptr;
    /** The inventory item the request is transferring to. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* ReceivingItem = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyTransferInventoryItemsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * ETags are used for concurrency checking when updating resources (after transferring from). More information about using
     * ETags can be found here: https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/catalog/etags
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString GivingETag;
    /** The ids of transactions that occurred as a result of the request's giving action. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString GivingTransactionIds;
    /** The idempotency id for the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString IdempotencyId;
    /**
     * The transfer operation status. Possible values are 'InProgress' or 'Completed'. If the operation has completed, the
     * response code will be 200. Otherwise, it will be 202.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString OperationStatus;
    /**
     * The token that can be used to get the status of the transfer operation. This will only have a value if OperationStatus
     * is 'InProgress'.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString OperationToken;
    /** The ids of transactions that occurred as a result of the request's receiving action. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ReceivingTransactionIds;
};

/** Given an entity type, entity identifier and container details, will update the entity's inventory items */
USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyUpdateInventoryItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * The id of the entity's collection to perform this action on. (Default="default"). The number of inventory collections is
     * unlimited.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString CollectionId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* Entity = nullptr;
    /**
     * ETags are used for concurrency checking when updating resources. More information about using ETags can be found here:
     * https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/catalog/etags
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ETag;
    /**
     * The Idempotency ID for this request. Idempotency IDs can be used to prevent operation replay in the medium term but will
     * be garbage collected eventually.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString IdempotencyId;
    /** The inventory item to update with the specified values. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        UPlayFabJsonObject* Item = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEconomyUpdateInventoryItemsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * ETags are used for concurrency checking when updating resources. More information about using ETags can be found here:
     * https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/catalog/etags
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString ETag;
    /** The idempotency id used in the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString IdempotencyId;
    /** The ids of transactions that occurred as a result of the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Inventory Models")
        FString TransactionIds;
};

