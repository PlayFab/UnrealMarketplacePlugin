//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
//
// API: Economy
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabEconomyAPI.h"
#include "PlayFabEconomyModels.h"
#include "PlayFabEconomyModelDecoder.h"
#include "PlayFabPrivate.h"
#include "PlayFabEnums.h"
#include "PlayFabCommon/Public/PlayFabAuthenticationContext.h"
#include "PlayFabCommon/Public/PlayFabCommonUtils.h"

UPlayFabEconomyAPI::UPlayFabEconomyAPI(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , CallAuthenticationContext(nullptr)
{
}

void UPlayFabEconomyAPI::SetCallAuthenticationContext(UPlayFabAuthenticationContext* InAuthenticationContext)
{
    CallAuthenticationContext = InAuthenticationContext;
}

void UPlayFabEconomyAPI::SetRequestObject(UPlayFabJsonObject* JsonObject)
{
    RequestJsonObj = JsonObject;
}

UPlayFabJsonObject* UPlayFabEconomyAPI::GetResponseObject()
{
    return ResponseJsonObj;
}

FString UPlayFabEconomyAPI::PercentEncode(const FString& Text)
{
    FString OutText = Text;

    OutText = OutText.Replace(TEXT("!"), TEXT("%21"));
    OutText = OutText.Replace(TEXT("\""), TEXT("%22"));
    OutText = OutText.Replace(TEXT("#"), TEXT("%23"));
    OutText = OutText.Replace(TEXT("$"), TEXT("%24"));
    //OutText = OutText.Replace(TEXT("&"), TEXT("%26"));
    OutText = OutText.Replace(TEXT("'"), TEXT("%27"));
    OutText = OutText.Replace(TEXT("("), TEXT("%28"));
    OutText = OutText.Replace(TEXT(")"), TEXT("%29"));
    OutText = OutText.Replace(TEXT("*"), TEXT("%2A"));
    OutText = OutText.Replace(TEXT("+"), TEXT("%2B"));
    OutText = OutText.Replace(TEXT(","), TEXT("%2C"));
    //OutText = OutText.Replace(TEXT("/"), TEXT("%2F"));
    OutText = OutText.Replace(TEXT(":"), TEXT("%3A"));
    OutText = OutText.Replace(TEXT(";"), TEXT("%3B"));
    OutText = OutText.Replace(TEXT("="), TEXT("%3D"));
    //OutText = OutText.Replace(TEXT("?"), TEXT("%3F"));
    OutText = OutText.Replace(TEXT("@"), TEXT("%40"));
    OutText = OutText.Replace(TEXT("["), TEXT("%5B"));
    OutText = OutText.Replace(TEXT("]"), TEXT("%5D"));
    OutText = OutText.Replace(TEXT("{"), TEXT("%7B"));
    OutText = OutText.Replace(TEXT("}"), TEXT("%7D"));

    return OutText;
}

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Economy API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Catalog
//////////////////////////////////////////////////////
/** Creates a new item in the working catalog using provided metadata. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::CreateDraftItem(FEconomyCreateDraftItemRequest request,
    FDelegateOnSuccessCreateDraftItem onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateDraftItem = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperCreateDraftItem);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/CreateDraftItem";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Item != nullptr) OutRestJsonObj->SetObjectField(TEXT("Item"), request.Item);
    OutRestJsonObj->SetBoolField(TEXT("Publish"), request.Publish);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperCreateDraftItem(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateDraftItem.IsBound())
    {
        FEconomyCreateDraftItemResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeCreateDraftItemResponseResponse(response.responseData);
        OnSuccessCreateDraftItem.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Creates one or more upload URLs which can be used by the client to upload raw file data. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::CreateUploadUrls(FEconomyCreateUploadUrlsRequest request,
    FDelegateOnSuccessCreateUploadUrls onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateUploadUrls = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperCreateUploadUrls);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/CreateUploadUrls";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Files.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Files"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Files"), request.Files);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperCreateUploadUrls(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateUploadUrls.IsBound())
    {
        FEconomyCreateUploadUrlsResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeCreateUploadUrlsResponseResponse(response.responseData);
        OnSuccessCreateUploadUrls.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes all reviews, helpfulness votes, and ratings submitted by the entity specified. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::DeleteEntityItemReviews(FEconomyDeleteEntityItemReviewsRequest request,
    FDelegateOnSuccessDeleteEntityItemReviews onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteEntityItemReviews = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperDeleteEntityItemReviews);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/DeleteEntityItemReviews";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperDeleteEntityItemReviews(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteEntityItemReviews.IsBound())
    {
        FEconomyDeleteEntityItemReviewsResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeDeleteEntityItemReviewsResponseResponse(response.responseData);
        OnSuccessDeleteEntityItemReviews.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Removes an item from working catalog and all published versions from the public catalog. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::DeleteItem(FEconomyDeleteItemRequest request,
    FDelegateOnSuccessDeleteItem onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteItem = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperDeleteItem);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/DeleteItem";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.AlternateId != nullptr) OutRestJsonObj->SetObjectField(TEXT("AlternateId"), request.AlternateId);
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.Id.IsEmpty() || request.Id == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Id"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Id"), request.Id);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperDeleteItem(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteItem.IsBound())
    {
        FEconomyDeleteItemResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeDeleteItemResponseResponse(response.responseData);
        OnSuccessDeleteItem.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets the configuration for the catalog. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::GetCatalogConfig(FEconomyGetCatalogConfigRequest request,
    FDelegateOnSuccessGetCatalogConfig onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetCatalogConfig = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperGetCatalogConfig);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/GetCatalogConfig";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperGetCatalogConfig(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetCatalogConfig.IsBound())
    {
        FEconomyGetCatalogConfigResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeGetCatalogConfigResponseResponse(response.responseData);
        OnSuccessGetCatalogConfig.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves an item from the working catalog. This item represents the current working state of the item. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::GetDraftItem(FEconomyGetDraftItemRequest request,
    FDelegateOnSuccessGetDraftItem onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetDraftItem = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperGetDraftItem);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/GetDraftItem";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.AlternateId != nullptr) OutRestJsonObj->SetObjectField(TEXT("AlternateId"), request.AlternateId);
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.Id.IsEmpty() || request.Id == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Id"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Id"), request.Id);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperGetDraftItem(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetDraftItem.IsBound())
    {
        FEconomyGetDraftItemResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeGetDraftItemResponseResponse(response.responseData);
        OnSuccessGetDraftItem.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves a paginated list of the items from the draft catalog. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::GetDraftItems(FEconomyGetDraftItemsRequest request,
    FDelegateOnSuccessGetDraftItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetDraftItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperGetDraftItems);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/GetDraftItems";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.AlternateIds.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("AlternateIds"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("AlternateIds"), request.AlternateIds);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    // Check to see if string is empty
    if (request.Ids.IsEmpty() || request.Ids == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Ids"));
    } else {
        TArray<FString> IdsArray;
        FString(request.Ids).ParseIntoArray(IdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Ids"), IdsArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperGetDraftItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetDraftItems.IsBound())
    {
        FEconomyGetDraftItemsResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeGetDraftItemsResponseResponse(response.responseData);
        OnSuccessGetDraftItems.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves a paginated list of the items from the draft catalog created by the Entity. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::GetEntityDraftItems(FEconomyGetEntityDraftItemsRequest request,
    FDelegateOnSuccessGetEntityDraftItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetEntityDraftItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperGetEntityDraftItems);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/GetEntityDraftItems";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.ContinuationToken.IsEmpty() || request.ContinuationToken == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ContinuationToken"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ContinuationToken"), request.ContinuationToken);
    }
    OutRestJsonObj->SetNumberField(TEXT("Count"), request.Count);
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperGetEntityDraftItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetEntityDraftItems.IsBound())
    {
        FEconomyGetEntityDraftItemsResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeGetEntityDraftItemsResponseResponse(response.responseData);
        OnSuccessGetEntityDraftItems.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets the submitted review for the specified item by the authenticated entity. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::GetEntityItemReview(FEconomyGetEntityItemReviewRequest request,
    FDelegateOnSuccessGetEntityItemReview onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetEntityItemReview = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperGetEntityItemReview);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/GetEntityItemReview";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.AlternateId != nullptr) OutRestJsonObj->SetObjectField(TEXT("AlternateId"), request.AlternateId);
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.Id.IsEmpty() || request.Id == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Id"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Id"), request.Id);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperGetEntityItemReview(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetEntityItemReview.IsBound())
    {
        FEconomyGetEntityItemReviewResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeGetEntityItemReviewResponseResponse(response.responseData);
        OnSuccessGetEntityItemReview.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves an item from the public catalog. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::GetItem(FEconomyGetItemRequest request,
    FDelegateOnSuccessGetItem onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetItem = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperGetItem);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/GetItem";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.AlternateId != nullptr) OutRestJsonObj->SetObjectField(TEXT("AlternateId"), request.AlternateId);
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.Id.IsEmpty() || request.Id == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Id"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Id"), request.Id);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperGetItem(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetItem.IsBound())
    {
        FEconomyGetItemResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeGetItemResponseResponse(response.responseData);
        OnSuccessGetItem.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets the moderation state for an item, including the concern category and string reason. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::GetItemModerationState(FEconomyGetItemModerationStateRequest request,
    FDelegateOnSuccessGetItemModerationState onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetItemModerationState = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperGetItemModerationState);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/GetItemModerationState";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.AlternateId != nullptr) OutRestJsonObj->SetObjectField(TEXT("AlternateId"), request.AlternateId);
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Id.IsEmpty() || request.Id == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Id"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Id"), request.Id);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperGetItemModerationState(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetItemModerationState.IsBound())
    {
        FEconomyGetItemModerationStateResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeGetItemModerationStateResponseResponse(response.responseData);
        OnSuccessGetItemModerationState.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets the status of a publish of an item. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::GetItemPublishStatus(FEconomyGetItemPublishStatusRequest request,
    FDelegateOnSuccessGetItemPublishStatus onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetItemPublishStatus = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperGetItemPublishStatus);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/GetItemPublishStatus";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.AlternateId != nullptr) OutRestJsonObj->SetObjectField(TEXT("AlternateId"), request.AlternateId);
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.Id.IsEmpty() || request.Id == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Id"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Id"), request.Id);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperGetItemPublishStatus(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetItemPublishStatus.IsBound())
    {
        FEconomyGetItemPublishStatusResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeGetItemPublishStatusResponseResponse(response.responseData);
        OnSuccessGetItemPublishStatus.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Get a paginated set of reviews associated with the specified item. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::GetItemReviews(FEconomyGetItemReviewsRequest request,
    FDelegateOnSuccessGetItemReviews onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetItemReviews = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperGetItemReviews);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/GetItemReviews";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.AlternateId != nullptr) OutRestJsonObj->SetObjectField(TEXT("AlternateId"), request.AlternateId);
    if (request.ContinuationToken.IsEmpty() || request.ContinuationToken == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ContinuationToken"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ContinuationToken"), request.ContinuationToken);
    }
    OutRestJsonObj->SetNumberField(TEXT("Count"), request.Count);
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Id.IsEmpty() || request.Id == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Id"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Id"), request.Id);
    }
    if (request.OrderBy.IsEmpty() || request.OrderBy == "") {
        OutRestJsonObj->SetFieldNull(TEXT("OrderBy"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("OrderBy"), request.OrderBy);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperGetItemReviews(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetItemReviews.IsBound())
    {
        FEconomyGetItemReviewsResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeGetItemReviewsResponseResponse(response.responseData);
        OnSuccessGetItemReviews.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Get a summary of all reviews associated with the specified item. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::GetItemReviewSummary(FEconomyGetItemReviewSummaryRequest request,
    FDelegateOnSuccessGetItemReviewSummary onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetItemReviewSummary = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperGetItemReviewSummary);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/GetItemReviewSummary";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.AlternateId != nullptr) OutRestJsonObj->SetObjectField(TEXT("AlternateId"), request.AlternateId);
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Id.IsEmpty() || request.Id == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Id"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Id"), request.Id);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperGetItemReviewSummary(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetItemReviewSummary.IsBound())
    {
        FEconomyGetItemReviewSummaryResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeGetItemReviewSummaryResponseResponse(response.responseData);
        OnSuccessGetItemReviewSummary.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves items from the public catalog. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::GetItems(FEconomyGetItemsRequest request,
    FDelegateOnSuccessGetItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperGetItems);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/GetItems";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.AlternateIds.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("AlternateIds"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("AlternateIds"), request.AlternateIds);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    // Check to see if string is empty
    if (request.Ids.IsEmpty() || request.Ids == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Ids"));
    } else {
        TArray<FString> IdsArray;
        FString(request.Ids).ParseIntoArray(IdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Ids"), IdsArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperGetItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetItems.IsBound())
    {
        FEconomyGetItemsResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeGetItemsResponseResponse(response.responseData);
        OnSuccessGetItems.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Initiates a publish of an item from the working catalog to the public catalog. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::PublishDraftItem(FEconomyPublishDraftItemRequest request,
    FDelegateOnSuccessPublishDraftItem onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessPublishDraftItem = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperPublishDraftItem);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/PublishDraftItem";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.AlternateId != nullptr) OutRestJsonObj->SetObjectField(TEXT("AlternateId"), request.AlternateId);
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.ETag.IsEmpty() || request.ETag == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ETag"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ETag"), request.ETag);
    }
    if (request.Id.IsEmpty() || request.Id == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Id"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Id"), request.Id);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperPublishDraftItem(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessPublishDraftItem.IsBound())
    {
        FEconomyPublishDraftItemResponse ResultStruct = UPlayFabEconomyModelDecoder::decodePublishDraftItemResponseResponse(response.responseData);
        OnSuccessPublishDraftItem.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Submit a report for an item, indicating in what way the item is inappropriate. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::ReportItem(FEconomyReportItemRequest request,
    FDelegateOnSuccessReportItem onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessReportItem = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperReportItem);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/ReportItem";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.AlternateId != nullptr) OutRestJsonObj->SetObjectField(TEXT("AlternateId"), request.AlternateId);
    FString temp_ConcernCategory;
    if (GetEnumValueToString<EConcernCategory>(TEXT("EConcernCategory"), request.ConcernCategory, temp_ConcernCategory))
        OutRestJsonObj->SetStringField(TEXT("ConcernCategory"), temp_ConcernCategory);
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.Id.IsEmpty() || request.Id == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Id"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Id"), request.Id);
    }
    if (request.Reason.IsEmpty() || request.Reason == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Reason"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Reason"), request.Reason);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperReportItem(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessReportItem.IsBound())
    {
        FEconomyReportItemResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeReportItemResponseResponse(response.responseData);
        OnSuccessReportItem.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Submit a report for a review */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::ReportItemReview(FEconomyReportItemReviewRequest request,
    FDelegateOnSuccessReportItemReview onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessReportItemReview = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperReportItemReview);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/ReportItemReview";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.AlternateId != nullptr) OutRestJsonObj->SetObjectField(TEXT("AlternateId"), request.AlternateId);
    FString temp_ConcernCategory;
    if (GetEnumValueToString<EConcernCategory>(TEXT("EConcernCategory"), request.ConcernCategory, temp_ConcernCategory))
        OutRestJsonObj->SetStringField(TEXT("ConcernCategory"), temp_ConcernCategory);
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.ItemId.IsEmpty() || request.ItemId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ItemId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ItemId"), request.ItemId);
    }
    if (request.Reason.IsEmpty() || request.Reason == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Reason"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Reason"), request.Reason);
    }
    if (request.ReviewId.IsEmpty() || request.ReviewId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ReviewId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ReviewId"), request.ReviewId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperReportItemReview(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessReportItemReview.IsBound())
    {
        FEconomyReportItemReviewResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeReportItemReviewResponseResponse(response.responseData);
        OnSuccessReportItemReview.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Creates or updates a review for the specified item. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::ReviewItem(FEconomyReviewItemRequest request,
    FDelegateOnSuccessReviewItem onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessReviewItem = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperReviewItem);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/ReviewItem";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.AlternateId != nullptr) OutRestJsonObj->SetObjectField(TEXT("AlternateId"), request.AlternateId);
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.Id.IsEmpty() || request.Id == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Id"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Id"), request.Id);
    }
    if (request.Review != nullptr) OutRestJsonObj->SetObjectField(TEXT("Review"), request.Review);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperReviewItem(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessReviewItem.IsBound())
    {
        FEconomyReviewItemResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeReviewItemResponseResponse(response.responseData);
        OnSuccessReviewItem.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Executes a search against the public catalog using the provided search parameters and returns a set of paginated results. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::SearchItems(FEconomySearchItemsRequest request,
    FDelegateOnSuccessSearchItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSearchItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperSearchItems);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/SearchItems";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.ContinuationToken.IsEmpty() || request.ContinuationToken == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ContinuationToken"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ContinuationToken"), request.ContinuationToken);
    }
    OutRestJsonObj->SetNumberField(TEXT("Count"), request.Count);
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.Filter.IsEmpty() || request.Filter == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Filter"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Filter"), request.Filter);
    }
    if (request.OrderBy.IsEmpty() || request.OrderBy == "") {
        OutRestJsonObj->SetFieldNull(TEXT("OrderBy"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("OrderBy"), request.OrderBy);
    }
    if (request.Search.IsEmpty() || request.Search == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Search"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Search"), request.Search);
    }
    if (request.Select.IsEmpty() || request.Select == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Select"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Select"), request.Select);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperSearchItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessSearchItems.IsBound())
    {
        FEconomySearchItemsResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeSearchItemsResponseResponse(response.responseData);
        OnSuccessSearchItems.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Sets the moderation state for an item, including the concern category and string reason. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::SetItemModerationState(FEconomySetItemModerationStateRequest request,
    FDelegateOnSuccessSetItemModerationState onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetItemModerationState = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperSetItemModerationState);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/SetItemModerationState";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.AlternateId != nullptr) OutRestJsonObj->SetObjectField(TEXT("AlternateId"), request.AlternateId);
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Id.IsEmpty() || request.Id == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Id"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Id"), request.Id);
    }
    if (request.Reason.IsEmpty() || request.Reason == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Reason"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Reason"), request.Reason);
    }
    FString temp_Status;
    if (GetEnumValueToString<EModerationStatus>(TEXT("EModerationStatus"), request.Status, temp_Status))
        OutRestJsonObj->SetStringField(TEXT("Status"), temp_Status);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperSetItemModerationState(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessSetItemModerationState.IsBound())
    {
        FEconomySetItemModerationStateResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeSetItemModerationStateResponseResponse(response.responseData);
        OnSuccessSetItemModerationState.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Submit a vote for a review, indicating whether the review was helpful or unhelpful. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::SubmitItemReviewVote(FEconomySubmitItemReviewVoteRequest request,
    FDelegateOnSuccessSubmitItemReviewVote onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSubmitItemReviewVote = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperSubmitItemReviewVote);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/SubmitItemReviewVote";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.AlternateId != nullptr) OutRestJsonObj->SetObjectField(TEXT("AlternateId"), request.AlternateId);
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.ItemId.IsEmpty() || request.ItemId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ItemId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ItemId"), request.ItemId);
    }
    if (request.ReviewId.IsEmpty() || request.ReviewId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ReviewId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ReviewId"), request.ReviewId);
    }
    FString temp_Vote;
    if (GetEnumValueToString<EHelpfulnessVote>(TEXT("EHelpfulnessVote"), request.Vote, temp_Vote))
        OutRestJsonObj->SetStringField(TEXT("Vote"), temp_Vote);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperSubmitItemReviewVote(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessSubmitItemReviewVote.IsBound())
    {
        FEconomySubmitItemReviewVoteResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeSubmitItemReviewVoteResponseResponse(response.responseData);
        OnSuccessSubmitItemReviewVote.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Submit a request to takedown one or more reviews. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::TakedownItemReviews(FEconomyTakedownItemReviewsRequest request,
    FDelegateOnSuccessTakedownItemReviews onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessTakedownItemReviews = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperTakedownItemReviews);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/TakedownItemReviews";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Reviews.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Reviews"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Reviews"), request.Reviews);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperTakedownItemReviews(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessTakedownItemReviews.IsBound())
    {
        FEconomyTakedownItemReviewsResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeTakedownItemReviewsResponseResponse(response.responseData);
        OnSuccessTakedownItemReviews.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Updates the configuration for the catalog. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::UpdateCatalogConfig(FEconomyUpdateCatalogConfigRequest request,
    FDelegateOnSuccessUpdateCatalogConfig onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateCatalogConfig = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperUpdateCatalogConfig);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/UpdateCatalogConfig";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.Config != nullptr) OutRestJsonObj->SetObjectField(TEXT("Config"), request.Config);
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperUpdateCatalogConfig(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdateCatalogConfig.IsBound())
    {
        FEconomyUpdateCatalogConfigResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeUpdateCatalogConfigResponseResponse(response.responseData);
        OnSuccessUpdateCatalogConfig.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Update the metadata for an item in the working catalog. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::UpdateDraftItem(FEconomyUpdateDraftItemRequest request,
    FDelegateOnSuccessUpdateDraftItem onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateDraftItem = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperUpdateDraftItem);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/UpdateDraftItem";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Item != nullptr) OutRestJsonObj->SetObjectField(TEXT("Item"), request.Item);
    OutRestJsonObj->SetBoolField(TEXT("Publish"), request.Publish);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperUpdateDraftItem(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdateDraftItem.IsBound())
    {
        FEconomyUpdateDraftItemResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeUpdateDraftItemResponseResponse(response.responseData);
        OnSuccessUpdateDraftItem.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}


///////////////////////////////////////////////////////
// Inventory
//////////////////////////////////////////////////////


void UPlayFabEconomyAPI::OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    // Be sure that we have no data from previous response
    ResetResponseData();

    if (!IsValidLowLevel())
    {
        UE_LOG(LogPlayFab, Error, TEXT("The request object is invalid during OnProcessRequestComplete."));
        return;
    }
    if (!OnPlayFabResponse.IsBound())
    {
        UE_LOG(LogPlayFab, Error, TEXT("OnPlayFabResponse has come un-bound during OnProcessRequestComplete."));
        return;
    }

    FPlayFabBaseModel myResponse;

    // Check we have result to process further
    if (!bWasSuccessful)
    {
        UE_LOG(LogPlayFab, Error, TEXT("Request failed: %s"), *Request->GetURL());

        // Broadcast the result event
        myResponse.responseError.hasError = true;
        myResponse.responseError.ErrorCode = 503;
        myResponse.responseError.ErrorName = "Unable to contact server";
        myResponse.responseError.ErrorMessage = "Unable to contact server";

        OnPlayFabResponse.Broadcast(myResponse, mCustomData, false);

        return;
    }

    // Save response data as a string
    ResponseContent = Response->GetContentAsString();

    // Save response code as int32
    ResponseCode = Response->GetResponseCode();

    // Try to deserialize data to JSON
    TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(ResponseContent);
    FJsonSerializer::Deserialize(JsonReader, ResponseJsonObj->GetRootObject());

    // Decide whether the request was successful
    bIsValidJsonResponse = bWasSuccessful && ResponseJsonObj->GetRootObject().IsValid();

    // Log errors
    if (!bIsValidJsonResponse)
        UE_LOG(LogPlayFab, Warning, TEXT("JSON could not be decoded!"));

    // Log response state
    UE_LOG(LogPlayFab, Log, TEXT("Response : %s"), *ResponseContent);

    myResponse.responseError.decodeError(ResponseJsonObj);
    myResponse.responseData = ResponseJsonObj;
    IPlayFab* pfSettings = &(IPlayFab::Get());

    if (returnsEntityToken)
    {
        CallAuthenticationContext = NewObject<UPlayFabAuthenticationContext>();
        FString NewEntityToken = myResponse.responseData->GetObjectField("data")->GetStringField("EntityToken");
        pfSettings->setEntityToken(NewEntityToken);
        CallAuthenticationContext->SetEntityToken(MoveTemp(NewEntityToken));
    }

    // Broadcast the result event
    OnPlayFabResponse.Broadcast(myResponse, mCustomData, !myResponse.responseError.hasError);
    pfSettings->ModifyPendingCallCount(-1);
}

void UPlayFabEconomyAPI::Activate()
{
    IPlayFab* pfSettings = &(IPlayFab::Get());

    FString RequestUrl;
    RequestUrl = pfSettings->GeneratePfUrl(PlayFabRequestURL);


    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
    HttpRequest->SetURL(RequestUrl);
    HttpRequest->SetVerb(TEXT("POST"));

    // Headers
    // Only set one of the potential authentication headers.
    bool AuthSet = false;

    if (useEntityToken && !AuthSet)
    {
        FString AuthValue =
        CallAuthenticationContext != nullptr ? CallAuthenticationContext->GetEntityToken() : pfSettings->getEntityToken();
        if (!AuthValue.IsEmpty())
        {
            HttpRequest->SetHeader(TEXT("X-EntityToken"), AuthValue);
            AuthSet = true;
        }
    }

    if (useSessionTicket && !AuthSet)
    {
        FString AuthValue = CallAuthenticationContext != nullptr ? CallAuthenticationContext->GetClientSessionTicket()
                                                                 : pfSettings->getSessionTicket();
        if (!AuthValue.IsEmpty())
        {
            HttpRequest->SetHeader(TEXT("X-Authorization"), AuthValue);
            AuthSet = true;
        }
    }

    if (useSecretKey && !AuthSet)
    {
        FString AuthValue = CallAuthenticationContext != nullptr ? CallAuthenticationContext->GetDeveloperSecretKey()
                                                                 : GetDefault<UPlayFabRuntimeSettings>()->DeveloperSecretKey;
        if (!AuthValue.IsEmpty())
        {
            HttpRequest->SetHeader(TEXT("X-SecretKey"), AuthValue);
            AuthSet = true;
        }
    }

    HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
    HttpRequest->SetHeader(TEXT("X-PlayFabSDK"), pfSettings->getVersionString());
    HttpRequest->SetHeader(TEXT("X-ReportErrorAsSuccess"), TEXT("true")); // FHttpResponsePtr doesn't provide sufficient information when an error code is returned
    for (TMap<FString, FString>::TConstIterator It(RequestHeaders); It; ++It)
        HttpRequest->SetHeader(It.Key(), It.Value());

    // Serialize data to json string
    FString OutputString;
    TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
    FJsonSerializer::Serialize(RequestJsonObj->GetRootObject().ToSharedRef(), Writer);

    // Set Json content
    HttpRequest->SetContentAsString(OutputString);

    UE_LOG(LogPlayFab, Log, TEXT("Request: %s"), *OutputString);

    // Bind event
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UPlayFabEconomyAPI::OnProcessRequestComplete);

    // Execute the request
    pfSettings->ModifyPendingCallCount(1);
    HttpRequest->ProcessRequest();
}

void UPlayFabEconomyAPI::ResetResponseData()
{
    if (ResponseJsonObj != nullptr)
        ResponseJsonObj->Reset();
    else
        ResponseJsonObj = NewObject<UPlayFabJsonObject>();
    bIsValidJsonResponse = false;
}
