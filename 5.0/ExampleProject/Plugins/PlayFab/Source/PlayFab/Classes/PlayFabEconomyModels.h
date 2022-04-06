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
    /** Whether the item should be published immediately. */
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
    /** Number of items to retrieve. Maximum page size is 10. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        int32 Count = 0;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Entity = nullptr;
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
        EPublishResult Result;
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
    /** Number of items to retrieve. Maximum page size is 200. If not specified, defaults to 10. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        int32 Count = 0;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The unique ID of the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Id;
    /** An OData orderBy used to order the results of the query. */
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
        EConcernCategory ConcernCategory;
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
        EConcernCategory ConcernCategory;
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
    /** Number of items to retrieve. Maximum page size is 225. Default value is 10. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        int32 Count = 0;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** An OData filter used to refine the search query. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Economy | Catalog Models")
        FString Filter;
    /** An OData orderBy used to order the results of the search query. */
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
        EModerationStatus Status;
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
        EHelpfulnessVote Vote;
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
    /** Whether the item should be published immediately. */
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

