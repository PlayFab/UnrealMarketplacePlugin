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

FEventsDeleteDataConnectionResponse UPlayFabEventsModelDecoder::decodeDeleteDataConnectionResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEventsDeleteDataConnectionResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.WasDeleted = !(dataObj->HasField("WasDeleted")) ? false : dataObj->GetBoolField("WasDeleted");

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

FEventsGetDataConnectionResponse UPlayFabEventsModelDecoder::decodeGetDataConnectionResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEventsGetDataConnectionResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.DataConnection = !(dataObj->HasField("DataConnection")) ? nullptr : dataObj->GetObjectField("DataConnection");

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

FEventsListDataConnectionsResponse UPlayFabEventsModelDecoder::decodeListDataConnectionsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEventsListDataConnectionsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.DataConnections = !(dataObj->HasField("DataConnections")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("DataConnections");

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

FEventsSetDataConnectionResponse UPlayFabEventsModelDecoder::decodeSetDataConnectionResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEventsSetDataConnectionResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.DataConnection = !(dataObj->HasField("DataConnection")) ? nullptr : dataObj->GetObjectField("DataConnection");

    return tempStruct;
}

FEventsSetDataConnectionActiveResponse UPlayFabEventsModelDecoder::decodeSetDataConnectionActiveResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FEventsSetDataConnectionActiveResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.DataConnection = !(dataObj->HasField("DataConnection")) ? nullptr : dataObj->GetObjectField("DataConnection");
    tempStruct.WasUpdated = !(dataObj->HasField("WasUpdated")) ? false : dataObj->GetBoolField("WasUpdated");

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


