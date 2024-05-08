//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the play fab models
//
// API: Authentication
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabAuthenticationModelDecoder.h"
#include "PlayFabPrivate.h"

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Authentication API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Authentication
//////////////////////////////////////////////////////

FAuthenticationAuthenticateCustomIdResult UPlayFabAuthenticationModelDecoder::decodeAuthenticateCustomIdResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAuthenticationAuthenticateCustomIdResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.EntityToken = !(dataObj->HasField("EntityToken")) ? nullptr : dataObj->GetObjectField("EntityToken");
    tempStruct.NewlyCreated = !(dataObj->HasField("NewlyCreated")) ? false : dataObj->GetBoolField("NewlyCreated");

    return tempStruct;
}

FAuthenticationEmptyResponse UPlayFabAuthenticationModelDecoder::decodeEmptyResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAuthenticationEmptyResponse tempStruct;


    return tempStruct;
}

FAuthenticationGetEntityTokenResponse UPlayFabAuthenticationModelDecoder::decodeGetEntityTokenResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAuthenticationGetEntityTokenResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Entity = !(dataObj->HasField("Entity")) ? nullptr : dataObj->GetObjectField("Entity");
    tempStruct.EntityToken = !(dataObj->HasField("EntityToken")) ? TEXT("") : dataObj->GetStringField("EntityToken");
    tempStruct.TokenExpiration = !(dataObj->HasField("TokenExpiration")) ? TEXT("") : dataObj->GetStringField("TokenExpiration");

    return tempStruct;
}

FAuthenticationValidateEntityTokenResponse UPlayFabAuthenticationModelDecoder::decodeValidateEntityTokenResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAuthenticationValidateEntityTokenResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Entity = !(dataObj->HasField("Entity")) ? nullptr : dataObj->GetObjectField("Entity");
    GetEnumValueFromString<EIdentifiedDeviceType>(TEXT("EIdentifiedDeviceType"), dataObj->GetStringField("IdentifiedDeviceType"), tempStruct.IdentifiedDeviceType);
    GetEnumValueFromString<ELoginIdentityProvider>(TEXT("ELoginIdentityProvider"), dataObj->GetStringField("IdentityProvider"), tempStruct.IdentityProvider);
    tempStruct.IdentityProviderIssuedId = !(dataObj->HasField("IdentityProviderIssuedId")) ? TEXT("") : dataObj->GetStringField("IdentityProviderIssuedId");
    tempStruct.Lineage = !(dataObj->HasField("Lineage")) ? nullptr : dataObj->GetObjectField("Lineage");

    return tempStruct;
}


