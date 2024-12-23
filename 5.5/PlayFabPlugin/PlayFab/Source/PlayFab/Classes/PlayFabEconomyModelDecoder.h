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
#include "PlayFabEconomyModels.h"
#include "PlayFabEconomyModelDecoder.generated.h"

class UPlayFabJsonObject;

UCLASS()
class PLAYFAB_API UPlayFabEconomyModelDecoder : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    //////////////////////////////////////////////////////////////////////////
    // Generated PlayFab Economy API Functions
    //////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////
    // Catalog
    //////////////////////////////////////////////////////

    /** Decode the CreateDraftItemResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomyCreateDraftItemResponse decodeCreateDraftItemResponseResponse(UPlayFabJsonObject* response);

    /** Decode the CreateUploadUrlsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomyCreateUploadUrlsResponse decodeCreateUploadUrlsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the DeleteEntityItemReviewsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomyDeleteEntityItemReviewsResponse decodeDeleteEntityItemReviewsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the DeleteItemResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomyDeleteItemResponse decodeDeleteItemResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetCatalogConfigResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomyGetCatalogConfigResponse decodeGetCatalogConfigResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetDraftItemResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomyGetDraftItemResponse decodeGetDraftItemResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetDraftItemsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomyGetDraftItemsResponse decodeGetDraftItemsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetEntityDraftItemsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomyGetEntityDraftItemsResponse decodeGetEntityDraftItemsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetEntityItemReviewResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomyGetEntityItemReviewResponse decodeGetEntityItemReviewResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetItemResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomyGetItemResponse decodeGetItemResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetItemContainersResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomyGetItemContainersResponse decodeGetItemContainersResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetItemModerationStateResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomyGetItemModerationStateResponse decodeGetItemModerationStateResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetItemPublishStatusResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomyGetItemPublishStatusResponse decodeGetItemPublishStatusResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetItemReviewsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomyGetItemReviewsResponse decodeGetItemReviewsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetItemReviewSummaryResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomyGetItemReviewSummaryResponse decodeGetItemReviewSummaryResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetItemsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomyGetItemsResponse decodeGetItemsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the PublishDraftItemResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomyPublishDraftItemResponse decodePublishDraftItemResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ReportItemResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomyReportItemResponse decodeReportItemResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ReportItemReviewResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomyReportItemReviewResponse decodeReportItemReviewResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ReviewItemResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomyReviewItemResponse decodeReviewItemResponseResponse(UPlayFabJsonObject* response);

    /** Decode the SearchItemsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomySearchItemsResponse decodeSearchItemsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the SetItemModerationStateResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomySetItemModerationStateResponse decodeSetItemModerationStateResponseResponse(UPlayFabJsonObject* response);

    /** Decode the SubmitItemReviewVoteResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomySubmitItemReviewVoteResponse decodeSubmitItemReviewVoteResponseResponse(UPlayFabJsonObject* response);

    /** Decode the TakedownItemReviewsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomyTakedownItemReviewsResponse decodeTakedownItemReviewsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the UpdateCatalogConfigResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomyUpdateCatalogConfigResponse decodeUpdateCatalogConfigResponseResponse(UPlayFabJsonObject* response);

    /** Decode the UpdateDraftItemResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Catalog Models")
        static FEconomyUpdateDraftItemResponse decodeUpdateDraftItemResponseResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Inventory
    //////////////////////////////////////////////////////

    /** Decode the AddInventoryItemsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory Models")
        static FEconomyAddInventoryItemsResponse decodeAddInventoryItemsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the DeleteInventoryCollectionResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory Models")
        static FEconomyDeleteInventoryCollectionResponse decodeDeleteInventoryCollectionResponseResponse(UPlayFabJsonObject* response);

    /** Decode the DeleteInventoryItemsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory Models")
        static FEconomyDeleteInventoryItemsResponse decodeDeleteInventoryItemsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ExecuteInventoryOperationsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory Models")
        static FEconomyExecuteInventoryOperationsResponse decodeExecuteInventoryOperationsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ExecuteTransferOperationsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory Models")
        static FEconomyExecuteTransferOperationsResponse decodeExecuteTransferOperationsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetInventoryCollectionIdsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory Models")
        static FEconomyGetInventoryCollectionIdsResponse decodeGetInventoryCollectionIdsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetInventoryItemsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory Models")
        static FEconomyGetInventoryItemsResponse decodeGetInventoryItemsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetInventoryOperationStatusResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory Models")
        static FEconomyGetInventoryOperationStatusResponse decodeGetInventoryOperationStatusResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetMicrosoftStoreAccessTokensResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory Models")
        static FEconomyGetMicrosoftStoreAccessTokensResponse decodeGetMicrosoftStoreAccessTokensResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetTransactionHistoryResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory Models")
        static FEconomyGetTransactionHistoryResponse decodeGetTransactionHistoryResponseResponse(UPlayFabJsonObject* response);

    /** Decode the PurchaseInventoryItemsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory Models")
        static FEconomyPurchaseInventoryItemsResponse decodePurchaseInventoryItemsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the RedeemAppleAppStoreInventoryItemsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory Models")
        static FEconomyRedeemAppleAppStoreInventoryItemsResponse decodeRedeemAppleAppStoreInventoryItemsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the RedeemGooglePlayInventoryItemsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory Models")
        static FEconomyRedeemGooglePlayInventoryItemsResponse decodeRedeemGooglePlayInventoryItemsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the RedeemMicrosoftStoreInventoryItemsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory Models")
        static FEconomyRedeemMicrosoftStoreInventoryItemsResponse decodeRedeemMicrosoftStoreInventoryItemsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the RedeemNintendoEShopInventoryItemsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory Models")
        static FEconomyRedeemNintendoEShopInventoryItemsResponse decodeRedeemNintendoEShopInventoryItemsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the RedeemPlayStationStoreInventoryItemsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory Models")
        static FEconomyRedeemPlayStationStoreInventoryItemsResponse decodeRedeemPlayStationStoreInventoryItemsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the RedeemSteamInventoryItemsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory Models")
        static FEconomyRedeemSteamInventoryItemsResponse decodeRedeemSteamInventoryItemsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the SubtractInventoryItemsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory Models")
        static FEconomySubtractInventoryItemsResponse decodeSubtractInventoryItemsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the TransferInventoryItemsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory Models")
        static FEconomyTransferInventoryItemsResponse decodeTransferInventoryItemsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the UpdateInventoryItemsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Economy | Inventory Models")
        static FEconomyUpdateInventoryItemsResponse decodeUpdateInventoryItemsResponseResponse(UPlayFabJsonObject* response);



};
