//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the play fab models
//
// API: Economy
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabEconomyModelDecoder.h"
#include "PlayFabPrivate.h"

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Economy API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Catalog
//////////////////////////////////////////////////////

FEconomyCreateDraftItemResponse UPlayFabEconomyModelDecoder::decodeCreateDraftItemResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyCreateDraftItemResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Item = !(dataObj->HasField("Item")) ? nullptr : dataObj->GetObjectField("Item");

    return tempStruct;
}

FEconomyCreateUploadUrlsResponse UPlayFabEconomyModelDecoder::decodeCreateUploadUrlsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyCreateUploadUrlsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.UploadUrls = !(dataObj->HasField("UploadUrls")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("UploadUrls");

    return tempStruct;
}

FEconomyDeleteEntityItemReviewsResponse UPlayFabEconomyModelDecoder::decodeDeleteEntityItemReviewsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyDeleteEntityItemReviewsResponse tempStruct;


    return tempStruct;
}

FEconomyDeleteItemResponse UPlayFabEconomyModelDecoder::decodeDeleteItemResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyDeleteItemResponse tempStruct;


    return tempStruct;
}

FEconomyGetCatalogConfigResponse UPlayFabEconomyModelDecoder::decodeGetCatalogConfigResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyGetCatalogConfigResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Config = !(dataObj->HasField("Config")) ? nullptr : dataObj->GetObjectField("Config");

    return tempStruct;
}

FEconomyGetDraftItemResponse UPlayFabEconomyModelDecoder::decodeGetDraftItemResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyGetDraftItemResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Item = !(dataObj->HasField("Item")) ? nullptr : dataObj->GetObjectField("Item");

    return tempStruct;
}

FEconomyGetDraftItemsResponse UPlayFabEconomyModelDecoder::decodeGetDraftItemsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyGetDraftItemsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ContinuationToken = !(dataObj->HasField("ContinuationToken")) ? TEXT("") : dataObj->GetStringField("ContinuationToken");
    tempStruct.Items = !(dataObj->HasField("Items")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Items");

    return tempStruct;
}

FEconomyGetEntityDraftItemsResponse UPlayFabEconomyModelDecoder::decodeGetEntityDraftItemsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyGetEntityDraftItemsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ContinuationToken = !(dataObj->HasField("ContinuationToken")) ? TEXT("") : dataObj->GetStringField("ContinuationToken");
    tempStruct.Items = !(dataObj->HasField("Items")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Items");

    return tempStruct;
}

FEconomyGetEntityItemReviewResponse UPlayFabEconomyModelDecoder::decodeGetEntityItemReviewResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyGetEntityItemReviewResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Review = !(dataObj->HasField("Review")) ? nullptr : dataObj->GetObjectField("Review");

    return tempStruct;
}

FEconomyGetItemResponse UPlayFabEconomyModelDecoder::decodeGetItemResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyGetItemResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Item = !(dataObj->HasField("Item")) ? nullptr : dataObj->GetObjectField("Item");

    return tempStruct;
}

FEconomyGetItemContainersResponse UPlayFabEconomyModelDecoder::decodeGetItemContainersResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyGetItemContainersResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Containers = !(dataObj->HasField("Containers")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Containers");
    tempStruct.ContinuationToken = !(dataObj->HasField("ContinuationToken")) ? TEXT("") : dataObj->GetStringField("ContinuationToken");

    return tempStruct;
}

FEconomyGetItemModerationStateResponse UPlayFabEconomyModelDecoder::decodeGetItemModerationStateResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyGetItemModerationStateResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.State = !(dataObj->HasField("State")) ? nullptr : dataObj->GetObjectField("State");

    return tempStruct;
}

FEconomyGetItemPublishStatusResponse UPlayFabEconomyModelDecoder::decodeGetItemPublishStatusResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyGetItemPublishStatusResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    GetEnumValueFromString<EPublishResult>(TEXT("EPublishResult"), dataObj->GetStringField("Result"), tempStruct.Result);
    tempStruct.StatusMessage = !(dataObj->HasField("StatusMessage")) ? TEXT("") : dataObj->GetStringField("StatusMessage");

    return tempStruct;
}

FEconomyGetItemReviewsResponse UPlayFabEconomyModelDecoder::decodeGetItemReviewsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyGetItemReviewsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ContinuationToken = !(dataObj->HasField("ContinuationToken")) ? TEXT("") : dataObj->GetStringField("ContinuationToken");
    tempStruct.Reviews = !(dataObj->HasField("Reviews")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Reviews");

    return tempStruct;
}

FEconomyGetItemReviewSummaryResponse UPlayFabEconomyModelDecoder::decodeGetItemReviewSummaryResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyGetItemReviewSummaryResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.LeastFavorableReview = !(dataObj->HasField("LeastFavorableReview")) ? nullptr : dataObj->GetObjectField("LeastFavorableReview");
    tempStruct.MostFavorableReview = !(dataObj->HasField("MostFavorableReview")) ? nullptr : dataObj->GetObjectField("MostFavorableReview");
    tempStruct.Rating = !(dataObj->HasField("Rating")) ? nullptr : dataObj->GetObjectField("Rating");
    tempStruct.ReviewsCount = !(dataObj->HasField("ReviewsCount")) ? 0 : int(dataObj->GetNumberField("ReviewsCount"));

    return tempStruct;
}

FEconomyGetItemsResponse UPlayFabEconomyModelDecoder::decodeGetItemsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyGetItemsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Items = !(dataObj->HasField("Items")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Items");

    return tempStruct;
}

FEconomyPublishDraftItemResponse UPlayFabEconomyModelDecoder::decodePublishDraftItemResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyPublishDraftItemResponse tempStruct;


    return tempStruct;
}

FEconomyReportItemResponse UPlayFabEconomyModelDecoder::decodeReportItemResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyReportItemResponse tempStruct;


    return tempStruct;
}

FEconomyReportItemReviewResponse UPlayFabEconomyModelDecoder::decodeReportItemReviewResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyReportItemReviewResponse tempStruct;


    return tempStruct;
}

FEconomyReviewItemResponse UPlayFabEconomyModelDecoder::decodeReviewItemResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyReviewItemResponse tempStruct;


    return tempStruct;
}

FEconomySearchItemsResponse UPlayFabEconomyModelDecoder::decodeSearchItemsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomySearchItemsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ContinuationToken = !(dataObj->HasField("ContinuationToken")) ? TEXT("") : dataObj->GetStringField("ContinuationToken");
    tempStruct.Items = !(dataObj->HasField("Items")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Items");

    return tempStruct;
}

FEconomySetItemModerationStateResponse UPlayFabEconomyModelDecoder::decodeSetItemModerationStateResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomySetItemModerationStateResponse tempStruct;


    return tempStruct;
}

FEconomySubmitItemReviewVoteResponse UPlayFabEconomyModelDecoder::decodeSubmitItemReviewVoteResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomySubmitItemReviewVoteResponse tempStruct;


    return tempStruct;
}

FEconomyTakedownItemReviewsResponse UPlayFabEconomyModelDecoder::decodeTakedownItemReviewsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyTakedownItemReviewsResponse tempStruct;


    return tempStruct;
}

FEconomyUpdateCatalogConfigResponse UPlayFabEconomyModelDecoder::decodeUpdateCatalogConfigResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyUpdateCatalogConfigResponse tempStruct;


    return tempStruct;
}

FEconomyUpdateDraftItemResponse UPlayFabEconomyModelDecoder::decodeUpdateDraftItemResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyUpdateDraftItemResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Item = !(dataObj->HasField("Item")) ? nullptr : dataObj->GetObjectField("Item");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Inventory
//////////////////////////////////////////////////////

FEconomyAddInventoryItemsResponse UPlayFabEconomyModelDecoder::decodeAddInventoryItemsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyAddInventoryItemsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ETag = !(dataObj->HasField("ETag")) ? TEXT("") : dataObj->GetStringField("ETag");
    tempStruct.IdempotencyId = !(dataObj->HasField("IdempotencyId")) ? TEXT("") : dataObj->GetStringField("IdempotencyId");
    tempStruct.TransactionIds = !(dataObj->HasField("TransactionIds")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("TransactionIds"), TEXT(","));

    return tempStruct;
}

FEconomyDeleteInventoryCollectionResponse UPlayFabEconomyModelDecoder::decodeDeleteInventoryCollectionResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyDeleteInventoryCollectionResponse tempStruct;


    return tempStruct;
}

FEconomyDeleteInventoryItemsResponse UPlayFabEconomyModelDecoder::decodeDeleteInventoryItemsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyDeleteInventoryItemsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ETag = !(dataObj->HasField("ETag")) ? TEXT("") : dataObj->GetStringField("ETag");
    tempStruct.IdempotencyId = !(dataObj->HasField("IdempotencyId")) ? TEXT("") : dataObj->GetStringField("IdempotencyId");
    tempStruct.TransactionIds = !(dataObj->HasField("TransactionIds")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("TransactionIds"), TEXT(","));

    return tempStruct;
}

FEconomyExecuteInventoryOperationsResponse UPlayFabEconomyModelDecoder::decodeExecuteInventoryOperationsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyExecuteInventoryOperationsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ETag = !(dataObj->HasField("ETag")) ? TEXT("") : dataObj->GetStringField("ETag");
    tempStruct.IdempotencyId = !(dataObj->HasField("IdempotencyId")) ? TEXT("") : dataObj->GetStringField("IdempotencyId");
    tempStruct.TransactionIds = !(dataObj->HasField("TransactionIds")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("TransactionIds"), TEXT(","));

    return tempStruct;
}

FEconomyExecuteTransferOperationsResponse UPlayFabEconomyModelDecoder::decodeExecuteTransferOperationsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyExecuteTransferOperationsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.GivingETag = !(dataObj->HasField("GivingETag")) ? TEXT("") : dataObj->GetStringField("GivingETag");
    tempStruct.GivingTransactionIds = !(dataObj->HasField("GivingTransactionIds")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("GivingTransactionIds"), TEXT(","));
    tempStruct.IdempotencyId = !(dataObj->HasField("IdempotencyId")) ? TEXT("") : dataObj->GetStringField("IdempotencyId");
    tempStruct.OperationStatus = !(dataObj->HasField("OperationStatus")) ? TEXT("") : dataObj->GetStringField("OperationStatus");
    tempStruct.OperationToken = !(dataObj->HasField("OperationToken")) ? TEXT("") : dataObj->GetStringField("OperationToken");
    tempStruct.ReceivingETag = !(dataObj->HasField("ReceivingETag")) ? TEXT("") : dataObj->GetStringField("ReceivingETag");
    tempStruct.ReceivingTransactionIds = !(dataObj->HasField("ReceivingTransactionIds")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("ReceivingTransactionIds"), TEXT(","));

    return tempStruct;
}

FEconomyGetInventoryCollectionIdsResponse UPlayFabEconomyModelDecoder::decodeGetInventoryCollectionIdsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyGetInventoryCollectionIdsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.CollectionIds = !(dataObj->HasField("CollectionIds")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("CollectionIds"), TEXT(","));
    tempStruct.ContinuationToken = !(dataObj->HasField("ContinuationToken")) ? TEXT("") : dataObj->GetStringField("ContinuationToken");

    return tempStruct;
}

FEconomyGetInventoryItemsResponse UPlayFabEconomyModelDecoder::decodeGetInventoryItemsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyGetInventoryItemsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ContinuationToken = !(dataObj->HasField("ContinuationToken")) ? TEXT("") : dataObj->GetStringField("ContinuationToken");
    tempStruct.ETag = !(dataObj->HasField("ETag")) ? TEXT("") : dataObj->GetStringField("ETag");
    tempStruct.Items = !(dataObj->HasField("Items")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Items");

    return tempStruct;
}

FEconomyGetInventoryOperationStatusResponse UPlayFabEconomyModelDecoder::decodeGetInventoryOperationStatusResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyGetInventoryOperationStatusResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.OperationStatus = !(dataObj->HasField("OperationStatus")) ? TEXT("") : dataObj->GetStringField("OperationStatus");

    return tempStruct;
}

FEconomyGetMicrosoftStoreAccessTokensResponse UPlayFabEconomyModelDecoder::decodeGetMicrosoftStoreAccessTokensResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyGetMicrosoftStoreAccessTokensResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.CollectionsAccessToken = !(dataObj->HasField("CollectionsAccessToken")) ? TEXT("") : dataObj->GetStringField("CollectionsAccessToken");
    tempStruct.CollectionsAccessTokenExpirationDate = !(dataObj->HasField("CollectionsAccessTokenExpirationDate")) ? TEXT("") : dataObj->GetStringField("CollectionsAccessTokenExpirationDate");

    return tempStruct;
}

FEconomyGetTransactionHistoryResponse UPlayFabEconomyModelDecoder::decodeGetTransactionHistoryResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyGetTransactionHistoryResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ContinuationToken = !(dataObj->HasField("ContinuationToken")) ? TEXT("") : dataObj->GetStringField("ContinuationToken");
    tempStruct.Transactions = !(dataObj->HasField("Transactions")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Transactions");

    return tempStruct;
}

FEconomyPurchaseInventoryItemsResponse UPlayFabEconomyModelDecoder::decodePurchaseInventoryItemsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyPurchaseInventoryItemsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ETag = !(dataObj->HasField("ETag")) ? TEXT("") : dataObj->GetStringField("ETag");
    tempStruct.IdempotencyId = !(dataObj->HasField("IdempotencyId")) ? TEXT("") : dataObj->GetStringField("IdempotencyId");
    tempStruct.TransactionIds = !(dataObj->HasField("TransactionIds")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("TransactionIds"), TEXT(","));

    return tempStruct;
}

FEconomyRedeemAppleAppStoreInventoryItemsResponse UPlayFabEconomyModelDecoder::decodeRedeemAppleAppStoreInventoryItemsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyRedeemAppleAppStoreInventoryItemsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Failed = !(dataObj->HasField("Failed")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Failed");
    tempStruct.Succeeded = !(dataObj->HasField("Succeeded")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Succeeded");
    tempStruct.TransactionIds = !(dataObj->HasField("TransactionIds")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("TransactionIds"), TEXT(","));

    return tempStruct;
}

FEconomyRedeemGooglePlayInventoryItemsResponse UPlayFabEconomyModelDecoder::decodeRedeemGooglePlayInventoryItemsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyRedeemGooglePlayInventoryItemsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Failed = !(dataObj->HasField("Failed")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Failed");
    tempStruct.Succeeded = !(dataObj->HasField("Succeeded")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Succeeded");
    tempStruct.TransactionIds = !(dataObj->HasField("TransactionIds")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("TransactionIds"), TEXT(","));

    return tempStruct;
}

FEconomyRedeemMicrosoftStoreInventoryItemsResponse UPlayFabEconomyModelDecoder::decodeRedeemMicrosoftStoreInventoryItemsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyRedeemMicrosoftStoreInventoryItemsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Failed = !(dataObj->HasField("Failed")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Failed");
    tempStruct.Succeeded = !(dataObj->HasField("Succeeded")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Succeeded");
    tempStruct.TransactionIds = !(dataObj->HasField("TransactionIds")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("TransactionIds"), TEXT(","));

    return tempStruct;
}

FEconomyRedeemNintendoEShopInventoryItemsResponse UPlayFabEconomyModelDecoder::decodeRedeemNintendoEShopInventoryItemsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyRedeemNintendoEShopInventoryItemsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Failed = !(dataObj->HasField("Failed")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Failed");
    tempStruct.Succeeded = !(dataObj->HasField("Succeeded")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Succeeded");
    tempStruct.TransactionIds = !(dataObj->HasField("TransactionIds")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("TransactionIds"), TEXT(","));

    return tempStruct;
}

FEconomyRedeemPlayStationStoreInventoryItemsResponse UPlayFabEconomyModelDecoder::decodeRedeemPlayStationStoreInventoryItemsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyRedeemPlayStationStoreInventoryItemsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Failed = !(dataObj->HasField("Failed")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Failed");
    tempStruct.Succeeded = !(dataObj->HasField("Succeeded")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Succeeded");
    tempStruct.TransactionIds = !(dataObj->HasField("TransactionIds")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("TransactionIds"), TEXT(","));

    return tempStruct;
}

FEconomyRedeemSteamInventoryItemsResponse UPlayFabEconomyModelDecoder::decodeRedeemSteamInventoryItemsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyRedeemSteamInventoryItemsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Failed = !(dataObj->HasField("Failed")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Failed");
    tempStruct.Succeeded = !(dataObj->HasField("Succeeded")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Succeeded");
    tempStruct.TransactionIds = !(dataObj->HasField("TransactionIds")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("TransactionIds"), TEXT(","));

    return tempStruct;
}

FEconomySubtractInventoryItemsResponse UPlayFabEconomyModelDecoder::decodeSubtractInventoryItemsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomySubtractInventoryItemsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ETag = !(dataObj->HasField("ETag")) ? TEXT("") : dataObj->GetStringField("ETag");
    tempStruct.IdempotencyId = !(dataObj->HasField("IdempotencyId")) ? TEXT("") : dataObj->GetStringField("IdempotencyId");
    tempStruct.TransactionIds = !(dataObj->HasField("TransactionIds")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("TransactionIds"), TEXT(","));

    return tempStruct;
}

FEconomyTransferInventoryItemsResponse UPlayFabEconomyModelDecoder::decodeTransferInventoryItemsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyTransferInventoryItemsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.GivingETag = !(dataObj->HasField("GivingETag")) ? TEXT("") : dataObj->GetStringField("GivingETag");
    tempStruct.GivingTransactionIds = !(dataObj->HasField("GivingTransactionIds")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("GivingTransactionIds"), TEXT(","));
    tempStruct.IdempotencyId = !(dataObj->HasField("IdempotencyId")) ? TEXT("") : dataObj->GetStringField("IdempotencyId");
    tempStruct.OperationStatus = !(dataObj->HasField("OperationStatus")) ? TEXT("") : dataObj->GetStringField("OperationStatus");
    tempStruct.OperationToken = !(dataObj->HasField("OperationToken")) ? TEXT("") : dataObj->GetStringField("OperationToken");
    tempStruct.ReceivingTransactionIds = !(dataObj->HasField("ReceivingTransactionIds")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("ReceivingTransactionIds"), TEXT(","));

    return tempStruct;
}

FEconomyUpdateInventoryItemsResponse UPlayFabEconomyModelDecoder::decodeUpdateInventoryItemsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEconomyUpdateInventoryItemsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ETag = !(dataObj->HasField("ETag")) ? TEXT("") : dataObj->GetStringField("ETag");
    tempStruct.IdempotencyId = !(dataObj->HasField("IdempotencyId")) ? TEXT("") : dataObj->GetStringField("IdempotencyId");
    tempStruct.TransactionIds = !(dataObj->HasField("TransactionIds")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("TransactionIds"), TEXT(","));

    return tempStruct;
}


