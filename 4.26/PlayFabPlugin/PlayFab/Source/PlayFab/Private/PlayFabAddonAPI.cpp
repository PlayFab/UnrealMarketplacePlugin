//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
//
// API: Addon
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabAddonAPI.h"
#include "PlayFabAddonModels.h"
#include "PlayFabAddonModelDecoder.h"
#include "PlayFabPrivate.h"
#include "PlayFabEnums.h"
#include "PlayFabCommon/Public/PlayFabAuthenticationContext.h"
#include "PlayFabCommon/Public/PlayFabCommonUtils.h"

UPlayFabAddonAPI::UPlayFabAddonAPI(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , CallAuthenticationContext(nullptr)
{
}

void UPlayFabAddonAPI::SetCallAuthenticationContext(UPlayFabAuthenticationContext* InAuthenticationContext)
{
    CallAuthenticationContext = InAuthenticationContext;
}

void UPlayFabAddonAPI::SetRequestObject(UPlayFabJsonObject* JsonObject)
{
    RequestJsonObj = JsonObject;
}

UPlayFabJsonObject* UPlayFabAddonAPI::GetResponseObject()
{
    return ResponseJsonObj;
}

FString UPlayFabAddonAPI::PercentEncode(const FString& Text)
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
// Generated PlayFab Addon API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Addon
//////////////////////////////////////////////////////
/** Creates the Apple addon on a title, or updates it if it already exists. */
UPlayFabAddonAPI* UPlayFabAddonAPI::CreateOrUpdateApple(FAddonCreateOrUpdateAppleRequest request,
    FDelegateOnSuccessCreateOrUpdateApple onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateOrUpdateApple = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperCreateOrUpdateApple);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/CreateOrUpdateApple";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    OutRestJsonObj->SetBoolField(TEXT("AllowProduction"), request.AllowProduction);
    OutRestJsonObj->SetBoolField(TEXT("AllowSandbox"), request.AllowSandbox);
    if (request.AppBundleId.IsEmpty() || request.AppBundleId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AppBundleId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AppBundleId"), request.AppBundleId);
    }
    if (request.AppId.IsEmpty() || request.AppId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AppId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AppId"), request.AppId);
    }
    if (request.AppSharedSecret.IsEmpty() || request.AppSharedSecret == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AppSharedSecret"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AppSharedSecret"), request.AppSharedSecret);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    OutRestJsonObj->SetBoolField(TEXT("ErrorIfExists"), request.ErrorIfExists);
    OutRestJsonObj->SetBoolField(TEXT("IgnoreExpirationDate"), request.IgnoreExpirationDate);
    if (request.IssuerId.IsEmpty() || request.IssuerId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("IssuerId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("IssuerId"), request.IssuerId);
    }
    if (request.KeyId.IsEmpty() || request.KeyId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KeyId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("KeyId"), request.KeyId);
    }
    if (request.PrivateKey.IsEmpty() || request.PrivateKey == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PrivateKey"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PrivateKey"), request.PrivateKey);
    }
    OutRestJsonObj->SetBoolField(TEXT("RequireSecureAuthentication"), request.RequireSecureAuthentication);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperCreateOrUpdateApple(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateOrUpdateApple.IsBound())
    {
        FAddonCreateOrUpdateAppleResponse ResultStruct = UPlayFabAddonModelDecoder::decodeCreateOrUpdateAppleResponseResponse(response.responseData);
        OnSuccessCreateOrUpdateApple.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Creates the Facebook addon on a title, or updates it if it already exists. */
UPlayFabAddonAPI* UPlayFabAddonAPI::CreateOrUpdateFacebook(FAddonCreateOrUpdateFacebookRequest request,
    FDelegateOnSuccessCreateOrUpdateFacebook onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateOrUpdateFacebook = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperCreateOrUpdateFacebook);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/CreateOrUpdateFacebook";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.AppID.IsEmpty() || request.AppID == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AppID"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AppID"), request.AppID);
    }
    if (request.AppSecret.IsEmpty() || request.AppSecret == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AppSecret"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AppSecret"), request.AppSecret);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    OutRestJsonObj->SetBoolField(TEXT("ErrorIfExists"), request.ErrorIfExists);
    if (request.NotificationEmail.IsEmpty() || request.NotificationEmail == "") {
        OutRestJsonObj->SetFieldNull(TEXT("NotificationEmail"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("NotificationEmail"), request.NotificationEmail);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperCreateOrUpdateFacebook(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateOrUpdateFacebook.IsBound())
    {
        FAddonCreateOrUpdateFacebookResponse ResultStruct = UPlayFabAddonModelDecoder::decodeCreateOrUpdateFacebookResponseResponse(response.responseData);
        OnSuccessCreateOrUpdateFacebook.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Creates the Facebook Instant Games addon on a title, or updates it if it already exists. */
UPlayFabAddonAPI* UPlayFabAddonAPI::CreateOrUpdateFacebookInstantGames(FAddonCreateOrUpdateFacebookInstantGamesRequest request,
    FDelegateOnSuccessCreateOrUpdateFacebookInstantGames onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateOrUpdateFacebookInstantGames = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperCreateOrUpdateFacebookInstantGames);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/CreateOrUpdateFacebookInstantGames";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.AppID.IsEmpty() || request.AppID == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AppID"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AppID"), request.AppID);
    }
    if (request.AppSecret.IsEmpty() || request.AppSecret == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AppSecret"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AppSecret"), request.AppSecret);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    OutRestJsonObj->SetBoolField(TEXT("ErrorIfExists"), request.ErrorIfExists);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperCreateOrUpdateFacebookInstantGames(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateOrUpdateFacebookInstantGames.IsBound())
    {
        FAddonCreateOrUpdateFacebookInstantGamesResponse ResultStruct = UPlayFabAddonModelDecoder::decodeCreateOrUpdateFacebookInstantGamesResponseResponse(response.responseData);
        OnSuccessCreateOrUpdateFacebookInstantGames.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Creates the Google addon on a title, or updates it if it already exists. */
UPlayFabAddonAPI* UPlayFabAddonAPI::CreateOrUpdateGoogle(FAddonCreateOrUpdateGoogleRequest request,
    FDelegateOnSuccessCreateOrUpdateGoogle onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateOrUpdateGoogle = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperCreateOrUpdateGoogle);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/CreateOrUpdateGoogle";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.AppLicenseKey.IsEmpty() || request.AppLicenseKey == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AppLicenseKey"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AppLicenseKey"), request.AppLicenseKey);
    }
    if (request.AppPackageID.IsEmpty() || request.AppPackageID == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AppPackageID"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AppPackageID"), request.AppPackageID);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    OutRestJsonObj->SetBoolField(TEXT("ErrorIfExists"), request.ErrorIfExists);
    if (request.OAuthClientID.IsEmpty() || request.OAuthClientID == "") {
        OutRestJsonObj->SetFieldNull(TEXT("OAuthClientID"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("OAuthClientID"), request.OAuthClientID);
    }
    if (request.OAuthClientSecret.IsEmpty() || request.OAuthClientSecret == "") {
        OutRestJsonObj->SetFieldNull(TEXT("OAuthClientSecret"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("OAuthClientSecret"), request.OAuthClientSecret);
    }
    if (request.OAuthCustomRedirectUri.IsEmpty() || request.OAuthCustomRedirectUri == "") {
        OutRestJsonObj->SetFieldNull(TEXT("OAuthCustomRedirectUri"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("OAuthCustomRedirectUri"), request.OAuthCustomRedirectUri);
    }
    if (request.ServiceAccountKey.IsEmpty() || request.ServiceAccountKey == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ServiceAccountKey"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ServiceAccountKey"), request.ServiceAccountKey);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperCreateOrUpdateGoogle(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateOrUpdateGoogle.IsBound())
    {
        FAddonCreateOrUpdateGoogleResponse ResultStruct = UPlayFabAddonModelDecoder::decodeCreateOrUpdateGoogleResponseResponse(response.responseData);
        OnSuccessCreateOrUpdateGoogle.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Creates the Kongregate addon on a title, or updates it if it already exists. */
UPlayFabAddonAPI* UPlayFabAddonAPI::CreateOrUpdateKongregate(FAddonCreateOrUpdateKongregateRequest request,
    FDelegateOnSuccessCreateOrUpdateKongregate onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateOrUpdateKongregate = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperCreateOrUpdateKongregate);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/CreateOrUpdateKongregate";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    OutRestJsonObj->SetBoolField(TEXT("ErrorIfExists"), request.ErrorIfExists);
    if (request.SecretAPIKey.IsEmpty() || request.SecretAPIKey == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SecretAPIKey"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SecretAPIKey"), request.SecretAPIKey);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperCreateOrUpdateKongregate(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateOrUpdateKongregate.IsBound())
    {
        FAddonCreateOrUpdateKongregateResponse ResultStruct = UPlayFabAddonModelDecoder::decodeCreateOrUpdateKongregateResponseResponse(response.responseData);
        OnSuccessCreateOrUpdateKongregate.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Creates the Nintendo addon on a title, or updates it if it already exists. */
UPlayFabAddonAPI* UPlayFabAddonAPI::CreateOrUpdateNintendo(FAddonCreateOrUpdateNintendoRequest request,
    FDelegateOnSuccessCreateOrUpdateNintendo onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateOrUpdateNintendo = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperCreateOrUpdateNintendo);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/CreateOrUpdateNintendo";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.ApplicationID.IsEmpty() || request.ApplicationID == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ApplicationID"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ApplicationID"), request.ApplicationID);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.Environments.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Environments"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Environments"), request.Environments);
    }
    OutRestJsonObj->SetBoolField(TEXT("ErrorIfExists"), request.ErrorIfExists);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperCreateOrUpdateNintendo(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateOrUpdateNintendo.IsBound())
    {
        FAddonCreateOrUpdateNintendoResponse ResultStruct = UPlayFabAddonModelDecoder::decodeCreateOrUpdateNintendoResponseResponse(response.responseData);
        OnSuccessCreateOrUpdateNintendo.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Creates the PSN addon on a title, or updates it if it already exists. */
UPlayFabAddonAPI* UPlayFabAddonAPI::CreateOrUpdatePSN(FAddonCreateOrUpdatePSNRequest request,
    FDelegateOnSuccessCreateOrUpdatePSN onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateOrUpdatePSN = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperCreateOrUpdatePSN);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/CreateOrUpdatePSN";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.ClientID.IsEmpty() || request.ClientID == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ClientID"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ClientID"), request.ClientID);
    }
    if (request.ClientSecret.IsEmpty() || request.ClientSecret == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ClientSecret"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ClientSecret"), request.ClientSecret);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    OutRestJsonObj->SetBoolField(TEXT("ErrorIfExists"), request.ErrorIfExists);
    if (request.NextGenClientID.IsEmpty() || request.NextGenClientID == "") {
        OutRestJsonObj->SetFieldNull(TEXT("NextGenClientID"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("NextGenClientID"), request.NextGenClientID);
    }
    if (request.NextGenClientSecret.IsEmpty() || request.NextGenClientSecret == "") {
        OutRestJsonObj->SetFieldNull(TEXT("NextGenClientSecret"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("NextGenClientSecret"), request.NextGenClientSecret);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperCreateOrUpdatePSN(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateOrUpdatePSN.IsBound())
    {
        FAddonCreateOrUpdatePSNResponse ResultStruct = UPlayFabAddonModelDecoder::decodeCreateOrUpdatePSNResponseResponse(response.responseData);
        OnSuccessCreateOrUpdatePSN.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Creates the Steam addon on a title, or updates it if it already exists. */
UPlayFabAddonAPI* UPlayFabAddonAPI::CreateOrUpdateSteam(FAddonCreateOrUpdateSteamRequest request,
    FDelegateOnSuccessCreateOrUpdateSteam onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateOrUpdateSteam = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperCreateOrUpdateSteam);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/CreateOrUpdateSteam";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.ApplicationId.IsEmpty() || request.ApplicationId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ApplicationId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ApplicationId"), request.ApplicationId);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    OutRestJsonObj->SetBoolField(TEXT("EnforceServiceSpecificTickets"), request.EnforceServiceSpecificTickets);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    OutRestJsonObj->SetBoolField(TEXT("ErrorIfExists"), request.ErrorIfExists);
    if (request.SecretKey.IsEmpty() || request.SecretKey == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SecretKey"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SecretKey"), request.SecretKey);
    }
    OutRestJsonObj->SetBoolField(TEXT("UseSandbox"), request.UseSandbox);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperCreateOrUpdateSteam(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateOrUpdateSteam.IsBound())
    {
        FAddonCreateOrUpdateSteamResponse ResultStruct = UPlayFabAddonModelDecoder::decodeCreateOrUpdateSteamResponseResponse(response.responseData);
        OnSuccessCreateOrUpdateSteam.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Creates the ToxMod addon on a title, or updates it if it already exists. */
UPlayFabAddonAPI* UPlayFabAddonAPI::CreateOrUpdateToxMod(FAddonCreateOrUpdateToxModRequest request,
    FDelegateOnSuccessCreateOrUpdateToxMod onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateOrUpdateToxMod = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperCreateOrUpdateToxMod);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/CreateOrUpdateToxMod";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.AccountId.IsEmpty() || request.AccountId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AccountId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AccountId"), request.AccountId);
    }
    if (request.AccountKey.IsEmpty() || request.AccountKey == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AccountKey"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AccountKey"), request.AccountKey);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    OutRestJsonObj->SetBoolField(TEXT("Enabled"), request.Enabled);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    OutRestJsonObj->SetBoolField(TEXT("ErrorIfExists"), request.ErrorIfExists);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperCreateOrUpdateToxMod(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateOrUpdateToxMod.IsBound())
    {
        FAddonCreateOrUpdateToxModResponse ResultStruct = UPlayFabAddonModelDecoder::decodeCreateOrUpdateToxModResponseResponse(response.responseData);
        OnSuccessCreateOrUpdateToxMod.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Creates the Twitch addon on a title, or updates it if it already exists. */
UPlayFabAddonAPI* UPlayFabAddonAPI::CreateOrUpdateTwitch(FAddonCreateOrUpdateTwitchRequest request,
    FDelegateOnSuccessCreateOrUpdateTwitch onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateOrUpdateTwitch = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperCreateOrUpdateTwitch);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/CreateOrUpdateTwitch";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.ClientID.IsEmpty() || request.ClientID == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ClientID"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ClientID"), request.ClientID);
    }
    if (request.ClientSecret.IsEmpty() || request.ClientSecret == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ClientSecret"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ClientSecret"), request.ClientSecret);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    OutRestJsonObj->SetBoolField(TEXT("ErrorIfExists"), request.ErrorIfExists);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperCreateOrUpdateTwitch(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateOrUpdateTwitch.IsBound())
    {
        FAddonCreateOrUpdateTwitchResponse ResultStruct = UPlayFabAddonModelDecoder::decodeCreateOrUpdateTwitchResponseResponse(response.responseData);
        OnSuccessCreateOrUpdateTwitch.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes the Apple addon on a title. */
UPlayFabAddonAPI* UPlayFabAddonAPI::DeleteApple(FAddonDeleteAppleRequest request,
    FDelegateOnSuccessDeleteApple onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteApple = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperDeleteApple);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/DeleteApple";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperDeleteApple(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteApple.IsBound())
    {
        FAddonDeleteAppleResponse ResultStruct = UPlayFabAddonModelDecoder::decodeDeleteAppleResponseResponse(response.responseData);
        OnSuccessDeleteApple.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes the Facebook addon on a title. */
UPlayFabAddonAPI* UPlayFabAddonAPI::DeleteFacebook(FAddonDeleteFacebookRequest request,
    FDelegateOnSuccessDeleteFacebook onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteFacebook = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperDeleteFacebook);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/DeleteFacebook";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperDeleteFacebook(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteFacebook.IsBound())
    {
        FAddonDeleteFacebookResponse ResultStruct = UPlayFabAddonModelDecoder::decodeDeleteFacebookResponseResponse(response.responseData);
        OnSuccessDeleteFacebook.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes the Facebook addon on a title. */
UPlayFabAddonAPI* UPlayFabAddonAPI::DeleteFacebookInstantGames(FAddonDeleteFacebookInstantGamesRequest request,
    FDelegateOnSuccessDeleteFacebookInstantGames onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteFacebookInstantGames = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperDeleteFacebookInstantGames);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/DeleteFacebookInstantGames";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperDeleteFacebookInstantGames(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteFacebookInstantGames.IsBound())
    {
        FAddonDeleteFacebookInstantGamesResponse ResultStruct = UPlayFabAddonModelDecoder::decodeDeleteFacebookInstantGamesResponseResponse(response.responseData);
        OnSuccessDeleteFacebookInstantGames.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes the Google addon on a title. */
UPlayFabAddonAPI* UPlayFabAddonAPI::DeleteGoogle(FAddonDeleteGoogleRequest request,
    FDelegateOnSuccessDeleteGoogle onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteGoogle = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperDeleteGoogle);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/DeleteGoogle";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperDeleteGoogle(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteGoogle.IsBound())
    {
        FAddonDeleteGoogleResponse ResultStruct = UPlayFabAddonModelDecoder::decodeDeleteGoogleResponseResponse(response.responseData);
        OnSuccessDeleteGoogle.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes the Kongregate addon on a title. */
UPlayFabAddonAPI* UPlayFabAddonAPI::DeleteKongregate(FAddonDeleteKongregateRequest request,
    FDelegateOnSuccessDeleteKongregate onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteKongregate = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperDeleteKongregate);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/DeleteKongregate";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperDeleteKongregate(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteKongregate.IsBound())
    {
        FAddonDeleteKongregateResponse ResultStruct = UPlayFabAddonModelDecoder::decodeDeleteKongregateResponseResponse(response.responseData);
        OnSuccessDeleteKongregate.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes the Nintendo addon on a title. */
UPlayFabAddonAPI* UPlayFabAddonAPI::DeleteNintendo(FAddonDeleteNintendoRequest request,
    FDelegateOnSuccessDeleteNintendo onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteNintendo = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperDeleteNintendo);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/DeleteNintendo";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperDeleteNintendo(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteNintendo.IsBound())
    {
        FAddonDeleteNintendoResponse ResultStruct = UPlayFabAddonModelDecoder::decodeDeleteNintendoResponseResponse(response.responseData);
        OnSuccessDeleteNintendo.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes the PSN addon on a title. */
UPlayFabAddonAPI* UPlayFabAddonAPI::DeletePSN(FAddonDeletePSNRequest request,
    FDelegateOnSuccessDeletePSN onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeletePSN = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperDeletePSN);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/DeletePSN";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperDeletePSN(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeletePSN.IsBound())
    {
        FAddonDeletePSNResponse ResultStruct = UPlayFabAddonModelDecoder::decodeDeletePSNResponseResponse(response.responseData);
        OnSuccessDeletePSN.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes the Steam addon on a title. */
UPlayFabAddonAPI* UPlayFabAddonAPI::DeleteSteam(FAddonDeleteSteamRequest request,
    FDelegateOnSuccessDeleteSteam onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteSteam = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperDeleteSteam);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/DeleteSteam";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperDeleteSteam(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteSteam.IsBound())
    {
        FAddonDeleteSteamResponse ResultStruct = UPlayFabAddonModelDecoder::decodeDeleteSteamResponseResponse(response.responseData);
        OnSuccessDeleteSteam.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes the ToxMod addon on a title. */
UPlayFabAddonAPI* UPlayFabAddonAPI::DeleteToxMod(FAddonDeleteToxModRequest request,
    FDelegateOnSuccessDeleteToxMod onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteToxMod = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperDeleteToxMod);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/DeleteToxMod";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperDeleteToxMod(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteToxMod.IsBound())
    {
        FAddonDeleteToxModResponse ResultStruct = UPlayFabAddonModelDecoder::decodeDeleteToxModResponseResponse(response.responseData);
        OnSuccessDeleteToxMod.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes the Twitch addon on a title. */
UPlayFabAddonAPI* UPlayFabAddonAPI::DeleteTwitch(FAddonDeleteTwitchRequest request,
    FDelegateOnSuccessDeleteTwitch onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteTwitch = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperDeleteTwitch);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/DeleteTwitch";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperDeleteTwitch(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteTwitch.IsBound())
    {
        FAddonDeleteTwitchResponse ResultStruct = UPlayFabAddonModelDecoder::decodeDeleteTwitchResponseResponse(response.responseData);
        OnSuccessDeleteTwitch.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets information of the Apple addon on a title, omits secrets. */
UPlayFabAddonAPI* UPlayFabAddonAPI::GetApple(FAddonGetAppleRequest request,
    FDelegateOnSuccessGetApple onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetApple = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperGetApple);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/GetApple";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperGetApple(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetApple.IsBound())
    {
        FAddonGetAppleResponse ResultStruct = UPlayFabAddonModelDecoder::decodeGetAppleResponseResponse(response.responseData);
        OnSuccessGetApple.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets information of the Facebook addon on a title, omits secrets. */
UPlayFabAddonAPI* UPlayFabAddonAPI::GetFacebook(FAddonGetFacebookRequest request,
    FDelegateOnSuccessGetFacebook onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetFacebook = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperGetFacebook);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/GetFacebook";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperGetFacebook(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetFacebook.IsBound())
    {
        FAddonGetFacebookResponse ResultStruct = UPlayFabAddonModelDecoder::decodeGetFacebookResponseResponse(response.responseData);
        OnSuccessGetFacebook.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets information of the Facebook Instant Games addon on a title, omits secrets. */
UPlayFabAddonAPI* UPlayFabAddonAPI::GetFacebookInstantGames(FAddonGetFacebookInstantGamesRequest request,
    FDelegateOnSuccessGetFacebookInstantGames onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetFacebookInstantGames = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperGetFacebookInstantGames);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/GetFacebookInstantGames";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperGetFacebookInstantGames(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetFacebookInstantGames.IsBound())
    {
        FAddonGetFacebookInstantGamesResponse ResultStruct = UPlayFabAddonModelDecoder::decodeGetFacebookInstantGamesResponseResponse(response.responseData);
        OnSuccessGetFacebookInstantGames.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets information of the Google addon on a title, omits secrets. */
UPlayFabAddonAPI* UPlayFabAddonAPI::GetGoogle(FAddonGetGoogleRequest request,
    FDelegateOnSuccessGetGoogle onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetGoogle = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperGetGoogle);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/GetGoogle";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperGetGoogle(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetGoogle.IsBound())
    {
        FAddonGetGoogleResponse ResultStruct = UPlayFabAddonModelDecoder::decodeGetGoogleResponseResponse(response.responseData);
        OnSuccessGetGoogle.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets information of the Kongregate addon on a title, omits secrets. */
UPlayFabAddonAPI* UPlayFabAddonAPI::GetKongregate(FAddonGetKongregateRequest request,
    FDelegateOnSuccessGetKongregate onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetKongregate = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperGetKongregate);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/GetKongregate";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperGetKongregate(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetKongregate.IsBound())
    {
        FAddonGetKongregateResponse ResultStruct = UPlayFabAddonModelDecoder::decodeGetKongregateResponseResponse(response.responseData);
        OnSuccessGetKongregate.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets information of the Nintendo addon on a title, omits secrets. */
UPlayFabAddonAPI* UPlayFabAddonAPI::GetNintendo(FAddonGetNintendoRequest request,
    FDelegateOnSuccessGetNintendo onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetNintendo = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperGetNintendo);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/GetNintendo";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperGetNintendo(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetNintendo.IsBound())
    {
        FAddonGetNintendoResponse ResultStruct = UPlayFabAddonModelDecoder::decodeGetNintendoResponseResponse(response.responseData);
        OnSuccessGetNintendo.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets information of the PSN addon on a title, omits secrets. */
UPlayFabAddonAPI* UPlayFabAddonAPI::GetPSN(FAddonGetPSNRequest request,
    FDelegateOnSuccessGetPSN onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPSN = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperGetPSN);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/GetPSN";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperGetPSN(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetPSN.IsBound())
    {
        FAddonGetPSNResponse ResultStruct = UPlayFabAddonModelDecoder::decodeGetPSNResponseResponse(response.responseData);
        OnSuccessGetPSN.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets information of the Steam addon on a title, omits secrets. */
UPlayFabAddonAPI* UPlayFabAddonAPI::GetSteam(FAddonGetSteamRequest request,
    FDelegateOnSuccessGetSteam onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetSteam = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperGetSteam);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/GetSteam";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperGetSteam(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetSteam.IsBound())
    {
        FAddonGetSteamResponse ResultStruct = UPlayFabAddonModelDecoder::decodeGetSteamResponseResponse(response.responseData);
        OnSuccessGetSteam.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets information of the ToxMod addon on a title, omits secrets. */
UPlayFabAddonAPI* UPlayFabAddonAPI::GetToxMod(FAddonGetToxModRequest request,
    FDelegateOnSuccessGetToxMod onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetToxMod = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperGetToxMod);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/GetToxMod";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperGetToxMod(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetToxMod.IsBound())
    {
        FAddonGetToxModResponse ResultStruct = UPlayFabAddonModelDecoder::decodeGetToxModResponseResponse(response.responseData);
        OnSuccessGetToxMod.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets information of the Twitch addon on a title, omits secrets. */
UPlayFabAddonAPI* UPlayFabAddonAPI::GetTwitch(FAddonGetTwitchRequest request,
    FDelegateOnSuccessGetTwitch onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAddonAPI* manager = NewObject<UPlayFabAddonAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetTwitch = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAddonAPI::HelperGetTwitch);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Addon/GetTwitch";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAddonRequestCompleted
void UPlayFabAddonAPI::HelperGetTwitch(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetTwitch.IsBound())
    {
        FAddonGetTwitchResponse ResultStruct = UPlayFabAddonModelDecoder::decodeGetTwitchResponseResponse(response.responseData);
        OnSuccessGetTwitch.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}



void UPlayFabAddonAPI::OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
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

void UPlayFabAddonAPI::Activate()
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
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UPlayFabAddonAPI::OnProcessRequestComplete);

    // Execute the request
    pfSettings->ModifyPendingCallCount(1);
    HttpRequest->ProcessRequest();
}

void UPlayFabAddonAPI::ResetResponseData()
{
    if (ResponseJsonObj != nullptr)
        ResponseJsonObj->Reset();
    else
        ResponseJsonObj = NewObject<UPlayFabJsonObject>();
    bIsValidJsonResponse = false;
}
