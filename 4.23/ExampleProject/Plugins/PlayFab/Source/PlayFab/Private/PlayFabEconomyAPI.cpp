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

/** Creates one or more upload URLs which can be used by the client to upload raw file data. Content URls and uploaded content will be garbage collected after 24 hours if not attached to a draft or published item. Detailed pricing info around uploading content can be found here: https://learn.microsoft.com/en-us/gaming/playfab/features/pricing/meters/catalog-meters */
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

/** Gets the configuration for the catalog. Only Title Entities can call this API. There is a limit of 100 requests in 10 seconds for this API. More information about the Catalog Config can be found here: https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/settings */
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

/** Retrieves an item from the working catalog. This item represents the current working state of the item. GetDraftItem does not work off a cache of the Catalog and should be used when trying to get recent item updates. However, please note that item references data is cached and may take a few moments for changes to propagate. */
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

/** Retrieves a paginated list of the items from the draft catalog. Up to 50 IDs can be retrieved in a single request. GetDraftItems does not work off a cache of the Catalog and should be used when trying to get recent item updates. */
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

/** Retrieves a paginated list of the items from the draft catalog created by the Entity. Up to 50 items can be returned at once. You can use continuation tokens to paginate through results that return greater than the limit. GetEntityDraftItems does not work off a cache of the Catalog and should be used when trying to get recent item updates. */
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
    if (request.Filter.IsEmpty() || request.Filter == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Filter"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Filter"), request.Filter);
    }

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

/** Gets the submitted review for the specified item by the authenticated entity. Individual ratings and reviews data update in near real time with delays within a few seconds. */
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

/** Retrieves an item from the public catalog. GetItem does not work off a cache of the Catalog and should be used when trying to get recent item updates. However, please note that item references data is cached and may take a few moments for changes to propagate. */
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

/** Search for a given item and return a set of bundles and stores containing the item. Up to 50 items can be returned at once. You can use continuation tokens to paginate through results that return greater than the limit. This API is intended for tooling/automation scenarios and has a reduced RPS with Player Entities limited to 30 requests in 300 seconds and Title Entities limited to 100 requests in 10 seconds. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::GetItemContainers(FEconomyGetItemContainersRequest request,
    FDelegateOnSuccessGetItemContainers onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetItemContainers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperGetItemContainers);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Catalog/GetItemContainers";
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
void UPlayFabEconomyAPI::HelperGetItemContainers(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetItemContainers.IsBound())
    {
        FEconomyGetItemContainersResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeGetItemContainersResponseResponse(response.responseData);
        OnSuccessGetItemContainers.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets the moderation state for an item, including the concern category and string reason. More information about moderation states can be found here: https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/ugc/moderation */
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

/** Get a paginated set of reviews associated with the specified item. Individual ratings and reviews data update in near real time with delays within a few seconds. */
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

/** Get a summary of all ratings and reviews associated with the specified item. Summary ratings data is cached with update data coming within 15 minutes. */
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

/** Retrieves items from the public catalog. Up to 50 items can be returned at once. GetItems does not work off a cache of the Catalog and should be used when trying to get recent item updates. However, please note that item references data is cached and may take a few moments for changes to propagate. */
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

/** Initiates a publish of an item from the working catalog to the public catalog. You can use the GetItemPublishStatus API to track the state of the item publish. */
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

/** Creates or updates a review for the specified item. More information around the caching surrounding item ratings and reviews can be found here: https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/catalog/ratings#ratings-design-and-caching */
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

/** Executes a search against the public catalog using the provided search parameters and returns a set of paginated results. SearchItems uses a cache of the catalog with item updates taking up to a few minutes to propagate. You should use the GetItem API for when trying to immediately get recent item updates. More information about the Search API can be found here: https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/catalog/search */
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
    if (request.Language.IsEmpty() || request.Language == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Language"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Language"), request.Language);
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
    if (request.Store != nullptr) OutRestJsonObj->SetObjectField(TEXT("Store"), request.Store);

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

/** Sets the moderation state for an item, including the concern category and string reason. More information about moderation states can be found here: https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/ugc/moderation */
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

/** Updates the configuration for the catalog. Only Title Entities can call this API. There is a limit of 10 requests in 10 seconds for this API. More information about the Catalog Config can be found here: https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/settings */
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
/** Add inventory items. Up to 3500 stacks of items can be added to a single inventory collection. Stack size is uncapped. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::AddInventoryItems(FEconomyAddInventoryItemsRequest request,
    FDelegateOnSuccessAddInventoryItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAddInventoryItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperAddInventoryItems);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Inventory/AddInventoryItems";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    OutRestJsonObj->SetNumberField(TEXT("Amount"), request.Amount);
    if (request.CollectionId.IsEmpty() || request.CollectionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CollectionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CollectionId"), request.CollectionId);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    OutRestJsonObj->SetNumberField(TEXT("DurationInSeconds"), request.DurationInSeconds);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.ETag.IsEmpty() || request.ETag == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ETag"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ETag"), request.ETag);
    }
    if (request.IdempotencyId.IsEmpty() || request.IdempotencyId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("IdempotencyId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("IdempotencyId"), request.IdempotencyId);
    }
    if (request.Item != nullptr) OutRestJsonObj->SetObjectField(TEXT("Item"), request.Item);
    if (request.NewStackValues != nullptr) OutRestJsonObj->SetObjectField(TEXT("NewStackValues"), request.NewStackValues);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperAddInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessAddInventoryItems.IsBound())
    {
        FEconomyAddInventoryItemsResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeAddInventoryItemsResponseResponse(response.responseData);
        OnSuccessAddInventoryItems.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Delete an Inventory Collection. More information about Inventory Collections can be found here: https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/inventory/collections */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::DeleteInventoryCollection(FEconomyDeleteInventoryCollectionRequest request,
    FDelegateOnSuccessDeleteInventoryCollection onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteInventoryCollection = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperDeleteInventoryCollection);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Inventory/DeleteInventoryCollection";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CollectionId.IsEmpty() || request.CollectionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CollectionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CollectionId"), request.CollectionId);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.ETag.IsEmpty() || request.ETag == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ETag"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ETag"), request.ETag);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperDeleteInventoryCollection(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteInventoryCollection.IsBound())
    {
        FEconomyDeleteInventoryCollectionResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeDeleteInventoryCollectionResponseResponse(response.responseData);
        OnSuccessDeleteInventoryCollection.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Delete inventory items */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::DeleteInventoryItems(FEconomyDeleteInventoryItemsRequest request,
    FDelegateOnSuccessDeleteInventoryItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteInventoryItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperDeleteInventoryItems);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Inventory/DeleteInventoryItems";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CollectionId.IsEmpty() || request.CollectionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CollectionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CollectionId"), request.CollectionId);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.ETag.IsEmpty() || request.ETag == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ETag"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ETag"), request.ETag);
    }
    if (request.IdempotencyId.IsEmpty() || request.IdempotencyId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("IdempotencyId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("IdempotencyId"), request.IdempotencyId);
    }
    if (request.Item != nullptr) OutRestJsonObj->SetObjectField(TEXT("Item"), request.Item);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperDeleteInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteInventoryItems.IsBound())
    {
        FEconomyDeleteInventoryItemsResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeDeleteInventoryItemsResponseResponse(response.responseData);
        OnSuccessDeleteInventoryItems.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Execute a list of Inventory Operations. A maximum list of 10 operations can be performed by a single request. There is also a limit to 250 items that can be modified/added in a single request. For example, adding a bundle with 50 items counts as 50 items modified. All operations must be done within a single inventory collection. This API has a reduced RPS compared to an individual inventory operation with Player Entities limited to 15 requests in 90 seconds and Title Entities limited to 500 requests in 10 seconds. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::ExecuteInventoryOperations(FEconomyExecuteInventoryOperationsRequest request,
    FDelegateOnSuccessExecuteInventoryOperations onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessExecuteInventoryOperations = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperExecuteInventoryOperations);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Inventory/ExecuteInventoryOperations";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CollectionId.IsEmpty() || request.CollectionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CollectionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CollectionId"), request.CollectionId);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.ETag.IsEmpty() || request.ETag == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ETag"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ETag"), request.ETag);
    }
    if (request.IdempotencyId.IsEmpty() || request.IdempotencyId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("IdempotencyId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("IdempotencyId"), request.IdempotencyId);
    }
    if (request.Operations.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Operations"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Operations"), request.Operations);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperExecuteInventoryOperations(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessExecuteInventoryOperations.IsBound())
    {
        FEconomyExecuteInventoryOperationsResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeExecuteInventoryOperationsResponseResponse(response.responseData);
        OnSuccessExecuteInventoryOperations.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Transfer a list of inventory items. A maximum list of 50 operations can be performed by a single request. When the response code is 202, one or more operations did not complete within the timeframe of the request. You can identify the pending operations by looking for OperationStatus = 'InProgress'. You can check on the operation status at anytime within 1 day of the request by passing the TransactionToken to the GetInventoryOperationStatus API. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::ExecuteTransferOperations(FEconomyExecuteTransferOperationsRequest request,
    FDelegateOnSuccessExecuteTransferOperations onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessExecuteTransferOperations = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperExecuteTransferOperations);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Inventory/ExecuteTransferOperations";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.GivingCollectionId.IsEmpty() || request.GivingCollectionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("GivingCollectionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("GivingCollectionId"), request.GivingCollectionId);
    }
    if (request.GivingEntity != nullptr) OutRestJsonObj->SetObjectField(TEXT("GivingEntity"), request.GivingEntity);
    if (request.GivingETag.IsEmpty() || request.GivingETag == "") {
        OutRestJsonObj->SetFieldNull(TEXT("GivingETag"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("GivingETag"), request.GivingETag);
    }
    if (request.IdempotencyId.IsEmpty() || request.IdempotencyId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("IdempotencyId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("IdempotencyId"), request.IdempotencyId);
    }
    if (request.Operations.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Operations"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Operations"), request.Operations);
    }
    if (request.ReceivingCollectionId.IsEmpty() || request.ReceivingCollectionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ReceivingCollectionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ReceivingCollectionId"), request.ReceivingCollectionId);
    }
    if (request.ReceivingEntity != nullptr) OutRestJsonObj->SetObjectField(TEXT("ReceivingEntity"), request.ReceivingEntity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperExecuteTransferOperations(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessExecuteTransferOperations.IsBound())
    {
        FEconomyExecuteTransferOperationsResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeExecuteTransferOperationsResponseResponse(response.responseData);
        OnSuccessExecuteTransferOperations.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Get Inventory Collection Ids. Up to 50 Ids can be returned at once. You can use continuation tokens to paginate through results that return greater than the limit. It can take a few seconds for new collection Ids to show up. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::GetInventoryCollectionIds(FEconomyGetInventoryCollectionIdsRequest request,
    FDelegateOnSuccessGetInventoryCollectionIds onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetInventoryCollectionIds = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperGetInventoryCollectionIds);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Inventory/GetInventoryCollectionIds";
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
void UPlayFabEconomyAPI::HelperGetInventoryCollectionIds(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetInventoryCollectionIds.IsBound())
    {
        FEconomyGetInventoryCollectionIdsResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeGetInventoryCollectionIdsResponseResponse(response.responseData);
        OnSuccessGetInventoryCollectionIds.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Get current inventory items. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::GetInventoryItems(FEconomyGetInventoryItemsRequest request,
    FDelegateOnSuccessGetInventoryItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetInventoryItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperGetInventoryItems);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Inventory/GetInventoryItems";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CollectionId.IsEmpty() || request.CollectionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CollectionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CollectionId"), request.CollectionId);
    }
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

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperGetInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetInventoryItems.IsBound())
    {
        FEconomyGetInventoryItemsResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeGetInventoryItemsResponseResponse(response.responseData);
        OnSuccessGetInventoryItems.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Get the status of an inventory operation using an OperationToken. You can check on the operation status at anytime within 1 day of the request by passing the TransactionToken to the this API. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::GetInventoryOperationStatus(FEconomyGetInventoryOperationStatusRequest request,
    FDelegateOnSuccessGetInventoryOperationStatus onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetInventoryOperationStatus = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperGetInventoryOperationStatus);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Inventory/GetInventoryOperationStatus";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CollectionId.IsEmpty() || request.CollectionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CollectionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CollectionId"), request.CollectionId);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperGetInventoryOperationStatus(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetInventoryOperationStatus.IsBound())
    {
        FEconomyGetInventoryOperationStatusResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeGetInventoryOperationStatusResponseResponse(response.responseData);
        OnSuccessGetInventoryOperationStatus.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets the access tokens. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::GetMicrosoftStoreAccessTokens(FEconomyGetMicrosoftStoreAccessTokensRequest request,
    FDelegateOnSuccessGetMicrosoftStoreAccessTokens onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetMicrosoftStoreAccessTokens = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperGetMicrosoftStoreAccessTokens);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Inventory/GetMicrosoftStoreAccessTokens";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperGetMicrosoftStoreAccessTokens(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetMicrosoftStoreAccessTokens.IsBound())
    {
        FEconomyGetMicrosoftStoreAccessTokensResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeGetMicrosoftStoreAccessTokensResponseResponse(response.responseData);
        OnSuccessGetMicrosoftStoreAccessTokens.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Get transaction history for a player. Up to 50 Events can be returned at once. You can use continuation tokens to paginate through results that return greater than the limit. Getting transaction history has a lower RPS limit than getting a Player's inventory with Player Entities having a limit of 30 requests in 300 seconds and Title Entities having a limit of 100 requests in 10 seconds. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::GetTransactionHistory(FEconomyGetTransactionHistoryRequest request,
    FDelegateOnSuccessGetTransactionHistory onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetTransactionHistory = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperGetTransactionHistory);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Inventory/GetTransactionHistory";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CollectionId.IsEmpty() || request.CollectionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CollectionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CollectionId"), request.CollectionId);
    }
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

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperGetTransactionHistory(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetTransactionHistory.IsBound())
    {
        FEconomyGetTransactionHistoryResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeGetTransactionHistoryResponseResponse(response.responseData);
        OnSuccessGetTransactionHistory.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Purchase an item or bundle. Up to 3500 stacks of items can be added to a single inventory collection. Stack size is uncapped. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::PurchaseInventoryItems(FEconomyPurchaseInventoryItemsRequest request,
    FDelegateOnSuccessPurchaseInventoryItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessPurchaseInventoryItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperPurchaseInventoryItems);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Inventory/PurchaseInventoryItems";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    OutRestJsonObj->SetNumberField(TEXT("Amount"), request.Amount);
    if (request.CollectionId.IsEmpty() || request.CollectionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CollectionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CollectionId"), request.CollectionId);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    OutRestJsonObj->SetBoolField(TEXT("DeleteEmptyStacks"), request.DeleteEmptyStacks);
    OutRestJsonObj->SetNumberField(TEXT("DurationInSeconds"), request.DurationInSeconds);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.ETag.IsEmpty() || request.ETag == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ETag"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ETag"), request.ETag);
    }
    if (request.IdempotencyId.IsEmpty() || request.IdempotencyId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("IdempotencyId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("IdempotencyId"), request.IdempotencyId);
    }
    if (request.Item != nullptr) OutRestJsonObj->SetObjectField(TEXT("Item"), request.Item);
    if (request.NewStackValues != nullptr) OutRestJsonObj->SetObjectField(TEXT("NewStackValues"), request.NewStackValues);
    if (request.PriceAmounts.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("PriceAmounts"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("PriceAmounts"), request.PriceAmounts);
    }
    if (request.StoreId.IsEmpty() || request.StoreId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StoreId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StoreId"), request.StoreId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperPurchaseInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessPurchaseInventoryItems.IsBound())
    {
        FEconomyPurchaseInventoryItemsResponse ResultStruct = UPlayFabEconomyModelDecoder::decodePurchaseInventoryItemsResponseResponse(response.responseData);
        OnSuccessPurchaseInventoryItems.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Redeem items. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::RedeemAppleAppStoreInventoryItems(FEconomyRedeemAppleAppStoreInventoryItemsRequest request,
    FDelegateOnSuccessRedeemAppleAppStoreInventoryItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRedeemAppleAppStoreInventoryItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperRedeemAppleAppStoreInventoryItems);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Inventory/RedeemAppleAppStoreInventoryItems";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CollectionId.IsEmpty() || request.CollectionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CollectionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CollectionId"), request.CollectionId);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.Receipt.IsEmpty() || request.Receipt == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Receipt"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Receipt"), request.Receipt);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperRedeemAppleAppStoreInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessRedeemAppleAppStoreInventoryItems.IsBound())
    {
        FEconomyRedeemAppleAppStoreInventoryItemsResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeRedeemAppleAppStoreInventoryItemsResponseResponse(response.responseData);
        OnSuccessRedeemAppleAppStoreInventoryItems.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Redeem items. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::RedeemGooglePlayInventoryItems(FEconomyRedeemGooglePlayInventoryItemsRequest request,
    FDelegateOnSuccessRedeemGooglePlayInventoryItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRedeemGooglePlayInventoryItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperRedeemGooglePlayInventoryItems);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Inventory/RedeemGooglePlayInventoryItems";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CollectionId.IsEmpty() || request.CollectionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CollectionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CollectionId"), request.CollectionId);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.Purchases.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Purchases"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Purchases"), request.Purchases);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperRedeemGooglePlayInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessRedeemGooglePlayInventoryItems.IsBound())
    {
        FEconomyRedeemGooglePlayInventoryItemsResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeRedeemGooglePlayInventoryItemsResponseResponse(response.responseData);
        OnSuccessRedeemGooglePlayInventoryItems.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Redeem items. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::RedeemMicrosoftStoreInventoryItems(FEconomyRedeemMicrosoftStoreInventoryItemsRequest request,
    FDelegateOnSuccessRedeemMicrosoftStoreInventoryItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRedeemMicrosoftStoreInventoryItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperRedeemMicrosoftStoreInventoryItems);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Inventory/RedeemMicrosoftStoreInventoryItems";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CollectionId.IsEmpty() || request.CollectionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CollectionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CollectionId"), request.CollectionId);
    }
    if (request.CollectionsIdKey.IsEmpty() || request.CollectionsIdKey == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CollectionsIdKey"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CollectionsIdKey"), request.CollectionsIdKey);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.XboxToken.IsEmpty() || request.XboxToken == "") {
        OutRestJsonObj->SetFieldNull(TEXT("XboxToken"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("XboxToken"), request.XboxToken);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperRedeemMicrosoftStoreInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessRedeemMicrosoftStoreInventoryItems.IsBound())
    {
        FEconomyRedeemMicrosoftStoreInventoryItemsResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeRedeemMicrosoftStoreInventoryItemsResponseResponse(response.responseData);
        OnSuccessRedeemMicrosoftStoreInventoryItems.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Redeem items. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::RedeemNintendoEShopInventoryItems(FEconomyRedeemNintendoEShopInventoryItemsRequest request,
    FDelegateOnSuccessRedeemNintendoEShopInventoryItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRedeemNintendoEShopInventoryItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperRedeemNintendoEShopInventoryItems);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Inventory/RedeemNintendoEShopInventoryItems";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CollectionId.IsEmpty() || request.CollectionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CollectionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CollectionId"), request.CollectionId);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.NintendoServiceAccountIdToken.IsEmpty() || request.NintendoServiceAccountIdToken == "") {
        OutRestJsonObj->SetFieldNull(TEXT("NintendoServiceAccountIdToken"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("NintendoServiceAccountIdToken"), request.NintendoServiceAccountIdToken);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperRedeemNintendoEShopInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessRedeemNintendoEShopInventoryItems.IsBound())
    {
        FEconomyRedeemNintendoEShopInventoryItemsResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeRedeemNintendoEShopInventoryItemsResponseResponse(response.responseData);
        OnSuccessRedeemNintendoEShopInventoryItems.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Redeem items. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::RedeemPlayStationStoreInventoryItems(FEconomyRedeemPlayStationStoreInventoryItemsRequest request,
    FDelegateOnSuccessRedeemPlayStationStoreInventoryItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRedeemPlayStationStoreInventoryItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperRedeemPlayStationStoreInventoryItems);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Inventory/RedeemPlayStationStoreInventoryItems";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.AuthorizationCode.IsEmpty() || request.AuthorizationCode == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AuthorizationCode"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AuthorizationCode"), request.AuthorizationCode);
    }
    if (request.CollectionId.IsEmpty() || request.CollectionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CollectionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CollectionId"), request.CollectionId);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.RedirectUri.IsEmpty() || request.RedirectUri == "") {
        OutRestJsonObj->SetFieldNull(TEXT("RedirectUri"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("RedirectUri"), request.RedirectUri);
    }
    if (request.ServiceLabel.IsEmpty() || request.ServiceLabel == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ServiceLabel"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ServiceLabel"), request.ServiceLabel);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperRedeemPlayStationStoreInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessRedeemPlayStationStoreInventoryItems.IsBound())
    {
        FEconomyRedeemPlayStationStoreInventoryItemsResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeRedeemPlayStationStoreInventoryItemsResponseResponse(response.responseData);
        OnSuccessRedeemPlayStationStoreInventoryItems.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Redeem items. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::RedeemSteamInventoryItems(FEconomyRedeemSteamInventoryItemsRequest request,
    FDelegateOnSuccessRedeemSteamInventoryItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRedeemSteamInventoryItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperRedeemSteamInventoryItems);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Inventory/RedeemSteamInventoryItems";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CollectionId.IsEmpty() || request.CollectionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CollectionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CollectionId"), request.CollectionId);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperRedeemSteamInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessRedeemSteamInventoryItems.IsBound())
    {
        FEconomyRedeemSteamInventoryItemsResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeRedeemSteamInventoryItemsResponseResponse(response.responseData);
        OnSuccessRedeemSteamInventoryItems.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Subtract inventory items. */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::SubtractInventoryItems(FEconomySubtractInventoryItemsRequest request,
    FDelegateOnSuccessSubtractInventoryItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSubtractInventoryItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperSubtractInventoryItems);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Inventory/SubtractInventoryItems";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    OutRestJsonObj->SetNumberField(TEXT("Amount"), request.Amount);
    if (request.CollectionId.IsEmpty() || request.CollectionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CollectionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CollectionId"), request.CollectionId);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    OutRestJsonObj->SetBoolField(TEXT("DeleteEmptyStacks"), request.DeleteEmptyStacks);
    OutRestJsonObj->SetNumberField(TEXT("DurationInSeconds"), request.DurationInSeconds);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.ETag.IsEmpty() || request.ETag == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ETag"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ETag"), request.ETag);
    }
    if (request.IdempotencyId.IsEmpty() || request.IdempotencyId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("IdempotencyId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("IdempotencyId"), request.IdempotencyId);
    }
    if (request.Item != nullptr) OutRestJsonObj->SetObjectField(TEXT("Item"), request.Item);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperSubtractInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessSubtractInventoryItems.IsBound())
    {
        FEconomySubtractInventoryItemsResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeSubtractInventoryItemsResponseResponse(response.responseData);
        OnSuccessSubtractInventoryItems.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Transfer inventory items. When transferring across collections, a 202 response indicates that the transfer did not complete within the timeframe of the request. You can identify the pending operations by looking for OperationStatus = 'InProgress'. You can check on the operation status at anytime within 1 day of the request by passing the TransactionToken to the GetInventoryOperationStatus API. More information about item transfer scenarios can be found here: https://learn.microsoft.com/en-us/gaming/playfab/features/economy-v2/inventory/?tabs=inventory-game-manager#transfer-inventory-items */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::TransferInventoryItems(FEconomyTransferInventoryItemsRequest request,
    FDelegateOnSuccessTransferInventoryItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessTransferInventoryItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperTransferInventoryItems);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Inventory/TransferInventoryItems";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    OutRestJsonObj->SetNumberField(TEXT("Amount"), request.Amount);
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    OutRestJsonObj->SetBoolField(TEXT("DeleteEmptyStacks"), request.DeleteEmptyStacks);
    if (request.GivingCollectionId.IsEmpty() || request.GivingCollectionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("GivingCollectionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("GivingCollectionId"), request.GivingCollectionId);
    }
    if (request.GivingEntity != nullptr) OutRestJsonObj->SetObjectField(TEXT("GivingEntity"), request.GivingEntity);
    if (request.GivingETag.IsEmpty() || request.GivingETag == "") {
        OutRestJsonObj->SetFieldNull(TEXT("GivingETag"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("GivingETag"), request.GivingETag);
    }
    if (request.GivingItem != nullptr) OutRestJsonObj->SetObjectField(TEXT("GivingItem"), request.GivingItem);
    if (request.IdempotencyId.IsEmpty() || request.IdempotencyId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("IdempotencyId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("IdempotencyId"), request.IdempotencyId);
    }
    if (request.NewStackValues != nullptr) OutRestJsonObj->SetObjectField(TEXT("NewStackValues"), request.NewStackValues);
    if (request.ReceivingCollectionId.IsEmpty() || request.ReceivingCollectionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ReceivingCollectionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ReceivingCollectionId"), request.ReceivingCollectionId);
    }
    if (request.ReceivingEntity != nullptr) OutRestJsonObj->SetObjectField(TEXT("ReceivingEntity"), request.ReceivingEntity);
    if (request.ReceivingItem != nullptr) OutRestJsonObj->SetObjectField(TEXT("ReceivingItem"), request.ReceivingItem);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperTransferInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessTransferInventoryItems.IsBound())
    {
        FEconomyTransferInventoryItemsResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeTransferInventoryItemsResponseResponse(response.responseData);
        OnSuccessTransferInventoryItems.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Update inventory items */
UPlayFabEconomyAPI* UPlayFabEconomyAPI::UpdateInventoryItems(FEconomyUpdateInventoryItemsRequest request,
    FDelegateOnSuccessUpdateInventoryItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEconomyAPI* manager = NewObject<UPlayFabEconomyAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateInventoryItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEconomyAPI::HelperUpdateInventoryItems);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Inventory/UpdateInventoryItems";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CollectionId.IsEmpty() || request.CollectionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CollectionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CollectionId"), request.CollectionId);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.ETag.IsEmpty() || request.ETag == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ETag"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ETag"), request.ETag);
    }
    if (request.IdempotencyId.IsEmpty() || request.IdempotencyId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("IdempotencyId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("IdempotencyId"), request.IdempotencyId);
    }
    if (request.Item != nullptr) OutRestJsonObj->SetObjectField(TEXT("Item"), request.Item);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEconomyRequestCompleted
void UPlayFabEconomyAPI::HelperUpdateInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdateInventoryItems.IsBound())
    {
        FEconomyUpdateInventoryItemsResponse ResultStruct = UPlayFabEconomyModelDecoder::decodeUpdateInventoryItemsResponseResponse(response.responseData);
        OnSuccessUpdateInventoryItems.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}



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


    TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
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
