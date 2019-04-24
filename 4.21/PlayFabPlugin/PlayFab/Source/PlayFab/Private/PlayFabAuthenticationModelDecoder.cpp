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
// API Keys
//////////////////////////////////////////////////////

FAuthenticationActivateAPIKeyResponse UPlayFabAuthenticationModelDecoder::decodeActivateAPIKeyResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAuthenticationActivateAPIKeyResponse tempStruct;


    return tempStruct;
}

FAuthenticationCreateAPIKeyResponse UPlayFabAuthenticationModelDecoder::decodeCreateAPIKeyResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAuthenticationCreateAPIKeyResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Entity = !(dataObj->HasField("Entity")) ? nullptr : dataObj->GetObjectField("Entity");
    tempStruct.Key = !(dataObj->HasField("Key")) ? nullptr : dataObj->GetObjectField("Key");

    return tempStruct;
}

FAuthenticationDeactivateAPIKeyResponse UPlayFabAuthenticationModelDecoder::decodeDeactivateAPIKeyResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAuthenticationDeactivateAPIKeyResponse tempStruct;


    return tempStruct;
}

FAuthenticationDeleteAPIKeyResponse UPlayFabAuthenticationModelDecoder::decodeDeleteAPIKeyResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAuthenticationDeleteAPIKeyResponse tempStruct;


    return tempStruct;
}

FAuthenticationGetAPIKeysResponse UPlayFabAuthenticationModelDecoder::decodeGetAPIKeysResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAuthenticationGetAPIKeysResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Entity = !(dataObj->HasField("Entity")) ? nullptr : dataObj->GetObjectField("Entity");
    tempStruct.Keys = !(dataObj->HasField("Keys")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Keys");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Authentication
//////////////////////////////////////////////////////

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


