//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the play fab models
//
// API: Profiles
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabProfilesModelDecoder.h"
#include "PlayFabPrivate.h"

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Profiles API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////

FProfilesGetGlobalPolicyResponse UPlayFabProfilesModelDecoder::decodeGetGlobalPolicyResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FProfilesGetGlobalPolicyResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Permissions = !(dataObj->HasField("Permissions")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Permissions");

    return tempStruct;
}

FProfilesGetEntityProfileResponse UPlayFabProfilesModelDecoder::decodeGetEntityProfileResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FProfilesGetEntityProfileResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Profile = !(dataObj->HasField("Profile")) ? nullptr : dataObj->GetObjectField("Profile");

    return tempStruct;
}

FProfilesGetEntityProfilesResponse UPlayFabProfilesModelDecoder::decodeGetEntityProfilesResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FProfilesGetEntityProfilesResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Profiles = !(dataObj->HasField("Profiles")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Profiles");

    return tempStruct;
}

FProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse UPlayFabProfilesModelDecoder::decodeGetTitlePlayersFromMasterPlayerAccountIdsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.TitleId = !(dataObj->HasField("TitleId")) ? TEXT("") : dataObj->GetStringField("TitleId");
    tempStruct.TitlePlayerAccounts = !(dataObj->HasField("TitlePlayerAccounts")) ? nullptr : dataObj->GetObjectField("TitlePlayerAccounts");

    return tempStruct;
}

FProfilesSetGlobalPolicyResponse UPlayFabProfilesModelDecoder::decodeSetGlobalPolicyResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FProfilesSetGlobalPolicyResponse tempStruct;


    return tempStruct;
}

FProfilesSetProfileLanguageResponse UPlayFabProfilesModelDecoder::decodeSetProfileLanguageResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FProfilesSetProfileLanguageResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    GetEnumValueFromString<EOperationTypes>(TEXT("EOperationTypes"), dataObj->GetStringField("OperationResult"), tempStruct.OperationResult);
    tempStruct.VersionNumber = !(dataObj->HasField("VersionNumber")) ? 0 : int(dataObj->GetNumberField("VersionNumber"));

    return tempStruct;
}

FProfilesSetEntityProfilePolicyResponse UPlayFabProfilesModelDecoder::decodeSetEntityProfilePolicyResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FProfilesSetEntityProfilePolicyResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Permissions = !(dataObj->HasField("Permissions")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Permissions");

    return tempStruct;
}


