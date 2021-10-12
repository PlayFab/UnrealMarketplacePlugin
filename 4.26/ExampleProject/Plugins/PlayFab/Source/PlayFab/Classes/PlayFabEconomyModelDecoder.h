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



};
