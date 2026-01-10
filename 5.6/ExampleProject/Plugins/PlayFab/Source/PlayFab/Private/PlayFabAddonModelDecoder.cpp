//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the play fab models
//
// API: Addon
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabAddonModelDecoder.h"
#include "PlayFabPrivate.h"

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Addon API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Addon
//////////////////////////////////////////////////////

FAddonCreateOrUpdateAppleResponse UPlayFabAddonModelDecoder::decodeCreateOrUpdateAppleResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonCreateOrUpdateAppleResponse tempStruct;


    return tempStruct;
}

FAddonCreateOrUpdateFacebookResponse UPlayFabAddonModelDecoder::decodeCreateOrUpdateFacebookResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonCreateOrUpdateFacebookResponse tempStruct;


    return tempStruct;
}

FAddonCreateOrUpdateFacebookInstantGamesResponse UPlayFabAddonModelDecoder::decodeCreateOrUpdateFacebookInstantGamesResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonCreateOrUpdateFacebookInstantGamesResponse tempStruct;


    return tempStruct;
}

FAddonCreateOrUpdateGoogleResponse UPlayFabAddonModelDecoder::decodeCreateOrUpdateGoogleResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonCreateOrUpdateGoogleResponse tempStruct;


    return tempStruct;
}

FAddonCreateOrUpdateKongregateResponse UPlayFabAddonModelDecoder::decodeCreateOrUpdateKongregateResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonCreateOrUpdateKongregateResponse tempStruct;


    return tempStruct;
}

FAddonCreateOrUpdateNintendoResponse UPlayFabAddonModelDecoder::decodeCreateOrUpdateNintendoResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonCreateOrUpdateNintendoResponse tempStruct;


    return tempStruct;
}

FAddonCreateOrUpdatePSNResponse UPlayFabAddonModelDecoder::decodeCreateOrUpdatePSNResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonCreateOrUpdatePSNResponse tempStruct;


    return tempStruct;
}

FAddonCreateOrUpdateSteamResponse UPlayFabAddonModelDecoder::decodeCreateOrUpdateSteamResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonCreateOrUpdateSteamResponse tempStruct;


    return tempStruct;
}

FAddonCreateOrUpdateToxModResponse UPlayFabAddonModelDecoder::decodeCreateOrUpdateToxModResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonCreateOrUpdateToxModResponse tempStruct;


    return tempStruct;
}

FAddonCreateOrUpdateTwitchResponse UPlayFabAddonModelDecoder::decodeCreateOrUpdateTwitchResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonCreateOrUpdateTwitchResponse tempStruct;


    return tempStruct;
}

FAddonDeleteAppleResponse UPlayFabAddonModelDecoder::decodeDeleteAppleResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonDeleteAppleResponse tempStruct;


    return tempStruct;
}

FAddonDeleteFacebookResponse UPlayFabAddonModelDecoder::decodeDeleteFacebookResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonDeleteFacebookResponse tempStruct;


    return tempStruct;
}

FAddonDeleteFacebookInstantGamesResponse UPlayFabAddonModelDecoder::decodeDeleteFacebookInstantGamesResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonDeleteFacebookInstantGamesResponse tempStruct;


    return tempStruct;
}

FAddonDeleteGoogleResponse UPlayFabAddonModelDecoder::decodeDeleteGoogleResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonDeleteGoogleResponse tempStruct;


    return tempStruct;
}

FAddonDeleteKongregateResponse UPlayFabAddonModelDecoder::decodeDeleteKongregateResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonDeleteKongregateResponse tempStruct;


    return tempStruct;
}

FAddonDeleteNintendoResponse UPlayFabAddonModelDecoder::decodeDeleteNintendoResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonDeleteNintendoResponse tempStruct;


    return tempStruct;
}

FAddonDeletePSNResponse UPlayFabAddonModelDecoder::decodeDeletePSNResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonDeletePSNResponse tempStruct;


    return tempStruct;
}

FAddonDeleteSteamResponse UPlayFabAddonModelDecoder::decodeDeleteSteamResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonDeleteSteamResponse tempStruct;


    return tempStruct;
}

FAddonDeleteToxModResponse UPlayFabAddonModelDecoder::decodeDeleteToxModResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonDeleteToxModResponse tempStruct;


    return tempStruct;
}

FAddonDeleteTwitchResponse UPlayFabAddonModelDecoder::decodeDeleteTwitchResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonDeleteTwitchResponse tempStruct;


    return tempStruct;
}

FAddonGetAppleResponse UPlayFabAddonModelDecoder::decodeGetAppleResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonGetAppleResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.AppBundleId = !(dataObj->HasField("AppBundleId")) ? TEXT("") : dataObj->GetStringField("AppBundleId");
    tempStruct.Created = !(dataObj->HasField("Created")) ? false : dataObj->GetBoolField("Created");
    tempStruct.IgnoreExpirationDate = !(dataObj->HasField("IgnoreExpirationDate")) ? false : dataObj->GetBoolField("IgnoreExpirationDate");
    tempStruct.RequireSecureAuthentication = !(dataObj->HasField("RequireSecureAuthentication")) ? false : dataObj->GetBoolField("RequireSecureAuthentication");

    return tempStruct;
}

FAddonGetFacebookResponse UPlayFabAddonModelDecoder::decodeGetFacebookResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonGetFacebookResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.AppID = !(dataObj->HasField("AppID")) ? TEXT("") : dataObj->GetStringField("AppID");
    tempStruct.Created = !(dataObj->HasField("Created")) ? false : dataObj->GetBoolField("Created");
    tempStruct.NotificationEmail = !(dataObj->HasField("NotificationEmail")) ? TEXT("") : dataObj->GetStringField("NotificationEmail");

    return tempStruct;
}

FAddonGetFacebookInstantGamesResponse UPlayFabAddonModelDecoder::decodeGetFacebookInstantGamesResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonGetFacebookInstantGamesResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.AppID = !(dataObj->HasField("AppID")) ? TEXT("") : dataObj->GetStringField("AppID");
    tempStruct.Created = !(dataObj->HasField("Created")) ? false : dataObj->GetBoolField("Created");

    return tempStruct;
}

FAddonGetGoogleResponse UPlayFabAddonModelDecoder::decodeGetGoogleResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonGetGoogleResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.AppPackageID = !(dataObj->HasField("AppPackageID")) ? TEXT("") : dataObj->GetStringField("AppPackageID");
    tempStruct.Created = !(dataObj->HasField("Created")) ? false : dataObj->GetBoolField("Created");
    tempStruct.OAuthClientID = !(dataObj->HasField("OAuthClientID")) ? TEXT("") : dataObj->GetStringField("OAuthClientID");
    tempStruct.OauthCustomRedirectUri = !(dataObj->HasField("OauthCustomRedirectUri")) ? TEXT("") : dataObj->GetStringField("OauthCustomRedirectUri");

    return tempStruct;
}

FAddonGetKongregateResponse UPlayFabAddonModelDecoder::decodeGetKongregateResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonGetKongregateResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Created = !(dataObj->HasField("Created")) ? false : dataObj->GetBoolField("Created");

    return tempStruct;
}

FAddonGetNintendoResponse UPlayFabAddonModelDecoder::decodeGetNintendoResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonGetNintendoResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ApplicationID = !(dataObj->HasField("ApplicationID")) ? TEXT("") : dataObj->GetStringField("ApplicationID");
    tempStruct.Created = !(dataObj->HasField("Created")) ? false : dataObj->GetBoolField("Created");
    tempStruct.Environments = !(dataObj->HasField("Environments")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Environments");

    return tempStruct;
}

FAddonGetPSNResponse UPlayFabAddonModelDecoder::decodeGetPSNResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonGetPSNResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ClientID = !(dataObj->HasField("ClientID")) ? TEXT("") : dataObj->GetStringField("ClientID");
    tempStruct.Created = !(dataObj->HasField("Created")) ? false : dataObj->GetBoolField("Created");
    tempStruct.NextGenClientID = !(dataObj->HasField("NextGenClientID")) ? TEXT("") : dataObj->GetStringField("NextGenClientID");

    return tempStruct;
}

FAddonGetSteamResponse UPlayFabAddonModelDecoder::decodeGetSteamResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonGetSteamResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ApplicationId = !(dataObj->HasField("ApplicationId")) ? TEXT("") : dataObj->GetStringField("ApplicationId");
    tempStruct.Created = !(dataObj->HasField("Created")) ? false : dataObj->GetBoolField("Created");
    tempStruct.EnforceServiceSpecificTickets = !(dataObj->HasField("EnforceServiceSpecificTickets")) ? false : dataObj->GetBoolField("EnforceServiceSpecificTickets");
    tempStruct.UseSandbox = !(dataObj->HasField("UseSandbox")) ? false : dataObj->GetBoolField("UseSandbox");

    return tempStruct;
}

FAddonGetToxModResponse UPlayFabAddonModelDecoder::decodeGetToxModResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonGetToxModResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.AccountId = !(dataObj->HasField("AccountId")) ? TEXT("") : dataObj->GetStringField("AccountId");
    tempStruct.AccountKey = !(dataObj->HasField("AccountKey")) ? TEXT("") : dataObj->GetStringField("AccountKey");
    tempStruct.Created = !(dataObj->HasField("Created")) ? false : dataObj->GetBoolField("Created");
    tempStruct.Enabled = !(dataObj->HasField("Enabled")) ? false : dataObj->GetBoolField("Enabled");

    return tempStruct;
}

FAddonGetTwitchResponse UPlayFabAddonModelDecoder::decodeGetTwitchResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAddonGetTwitchResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ClientID = !(dataObj->HasField("ClientID")) ? TEXT("") : dataObj->GetStringField("ClientID");
    tempStruct.Created = !(dataObj->HasField("Created")) ? false : dataObj->GetBoolField("Created");

    return tempStruct;
}


