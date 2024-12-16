//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the play fab models
//
// API: Events
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabEventsModelDecoder.h"
#include "PlayFabPrivate.h"

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Events API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// PlayStream
//////////////////////////////////////////////////////



///////////////////////////////////////////////////////
// PlayStream Events
//////////////////////////////////////////////////////

FEventsCreateTelemetryKeyResponse UPlayFabEventsModelDecoder::decodeCreateTelemetryKeyResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEventsCreateTelemetryKeyResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.NewKeyDetails = !(dataObj->HasField("NewKeyDetails")) ? nullptr : dataObj->GetObjectField("NewKeyDetails");

    return tempStruct;
}

FEventsDeleteTelemetryKeyResponse UPlayFabEventsModelDecoder::decodeDeleteTelemetryKeyResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEventsDeleteTelemetryKeyResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.WasKeyDeleted = !(dataObj->HasField("WasKeyDeleted")) ? false : dataObj->GetBoolField("WasKeyDeleted");

    return tempStruct;
}

FEventsGetTelemetryKeyResponse UPlayFabEventsModelDecoder::decodeGetTelemetryKeyResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEventsGetTelemetryKeyResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.KeyDetails = !(dataObj->HasField("KeyDetails")) ? nullptr : dataObj->GetObjectField("KeyDetails");

    return tempStruct;
}

FEventsListTelemetryKeysResponse UPlayFabEventsModelDecoder::decodeListTelemetryKeysResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEventsListTelemetryKeysResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.KeyDetails = !(dataObj->HasField("KeyDetails")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("KeyDetails");

    return tempStruct;
}

FEventsSetTelemetryKeyActiveResponse UPlayFabEventsModelDecoder::decodeSetTelemetryKeyActiveResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEventsSetTelemetryKeyActiveResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.KeyDetails = !(dataObj->HasField("KeyDetails")) ? nullptr : dataObj->GetObjectField("KeyDetails");
    tempStruct.WasKeyUpdated = !(dataObj->HasField("WasKeyUpdated")) ? false : dataObj->GetBoolField("WasKeyUpdated");

    return tempStruct;
}

FEventsWriteEventsResponse UPlayFabEventsModelDecoder::decodeWriteEventsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEventsWriteEventsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.AssignedEventIds = !(dataObj->HasField("AssignedEventIds")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("AssignedEventIds"), TEXT(","));

    return tempStruct;
}


