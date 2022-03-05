//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the play fab models
//
// API: Matchmaker
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabMatchmakerModelDecoder.h"
#include "PlayFabPrivate.h"

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Matchmaker API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Matchmaking
//////////////////////////////////////////////////////

FMatchmakerAuthUserResponse UPlayFabMatchmakerModelDecoder::decodeAuthUserResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMatchmakerAuthUserResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Authorized = !(dataObj->HasField("Authorized")) ? false : dataObj->GetBoolField("Authorized");
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");

    return tempStruct;
}

FMatchmakerPlayerJoinedResponse UPlayFabMatchmakerModelDecoder::decodePlayerJoinedResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMatchmakerPlayerJoinedResponse tempStruct;


    return tempStruct;
}

FMatchmakerPlayerLeftResponse UPlayFabMatchmakerModelDecoder::decodePlayerLeftResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMatchmakerPlayerLeftResponse tempStruct;


    return tempStruct;
}

FMatchmakerUserInfoResponse UPlayFabMatchmakerModelDecoder::decodeUserInfoResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMatchmakerUserInfoResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Inventory = !(dataObj->HasField("Inventory")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Inventory");
    tempStruct.IsDeveloper = !(dataObj->HasField("IsDeveloper")) ? false : dataObj->GetBoolField("IsDeveloper");
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");
    tempStruct.SteamId = !(dataObj->HasField("SteamId")) ? TEXT("") : dataObj->GetStringField("SteamId");
    tempStruct.TitleDisplayName = !(dataObj->HasField("TitleDisplayName")) ? TEXT("") : dataObj->GetStringField("TitleDisplayName");
    tempStruct.Username = !(dataObj->HasField("Username")) ? TEXT("") : dataObj->GetStringField("Username");
    tempStruct.VirtualCurrency = !(dataObj->HasField("VirtualCurrency")) ? nullptr : dataObj->GetObjectField("VirtualCurrency");
    tempStruct.VirtualCurrencyRechargeTimes = !(dataObj->HasField("VirtualCurrencyRechargeTimes")) ? nullptr : dataObj->GetObjectField("VirtualCurrencyRechargeTimes");

    return tempStruct;
}


