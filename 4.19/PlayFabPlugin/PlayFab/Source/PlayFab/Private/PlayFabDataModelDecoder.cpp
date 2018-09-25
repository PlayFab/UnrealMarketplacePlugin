//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the play fab models
//
// API: Data
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabDataModelDecoder.h"
#include "PlayFabPrivate.h"

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Data API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// File
//////////////////////////////////////////////////////

FDataAbortFileUploadsResponse UPlayFabDataModelDecoder::decodeAbortFileUploadsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FDataAbortFileUploadsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Entity = !(dataObj->HasField("Entity")) ? nullptr : dataObj->GetObjectField("Entity");
    tempStruct.ProfileVersion = !(dataObj->HasField("ProfileVersion")) ? 0 : int(dataObj->GetNumberField("ProfileVersion"));

    return tempStruct;
}

FDataDeleteFilesResponse UPlayFabDataModelDecoder::decodeDeleteFilesResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FDataDeleteFilesResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Entity = !(dataObj->HasField("Entity")) ? nullptr : dataObj->GetObjectField("Entity");
    tempStruct.ProfileVersion = !(dataObj->HasField("ProfileVersion")) ? 0 : int(dataObj->GetNumberField("ProfileVersion"));

    return tempStruct;
}

FDataFinalizeFileUploadsResponse UPlayFabDataModelDecoder::decodeFinalizeFileUploadsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FDataFinalizeFileUploadsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Entity = !(dataObj->HasField("Entity")) ? nullptr : dataObj->GetObjectField("Entity");
    tempStruct.Metadata = !(dataObj->HasField("Metadata")) ? nullptr : dataObj->GetObjectField("Metadata");
    tempStruct.ProfileVersion = !(dataObj->HasField("ProfileVersion")) ? 0 : int(dataObj->GetNumberField("ProfileVersion"));

    return tempStruct;
}

FDataGetFilesResponse UPlayFabDataModelDecoder::decodeGetFilesResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FDataGetFilesResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Entity = !(dataObj->HasField("Entity")) ? nullptr : dataObj->GetObjectField("Entity");
    tempStruct.Metadata = !(dataObj->HasField("Metadata")) ? nullptr : dataObj->GetObjectField("Metadata");
    tempStruct.ProfileVersion = !(dataObj->HasField("ProfileVersion")) ? 0 : int(dataObj->GetNumberField("ProfileVersion"));

    return tempStruct;
}

FDataInitiateFileUploadsResponse UPlayFabDataModelDecoder::decodeInitiateFileUploadsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FDataInitiateFileUploadsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Entity = !(dataObj->HasField("Entity")) ? nullptr : dataObj->GetObjectField("Entity");
    tempStruct.ProfileVersion = !(dataObj->HasField("ProfileVersion")) ? 0 : int(dataObj->GetNumberField("ProfileVersion"));
    tempStruct.UploadDetails = !(dataObj->HasField("UploadDetails")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("UploadDetails");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Object
//////////////////////////////////////////////////////

FDataGetObjectsResponse UPlayFabDataModelDecoder::decodeGetObjectsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FDataGetObjectsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Entity = !(dataObj->HasField("Entity")) ? nullptr : dataObj->GetObjectField("Entity");
    tempStruct.Objects = !(dataObj->HasField("Objects")) ? nullptr : dataObj->GetObjectField("Objects");
    tempStruct.ProfileVersion = !(dataObj->HasField("ProfileVersion")) ? 0 : int(dataObj->GetNumberField("ProfileVersion"));

    return tempStruct;
}

FDataSetObjectsResponse UPlayFabDataModelDecoder::decodeSetObjectsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FDataSetObjectsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ProfileVersion = !(dataObj->HasField("ProfileVersion")) ? 0 : int(dataObj->GetNumberField("ProfileVersion"));
    tempStruct.SetResults = !(dataObj->HasField("SetResults")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("SetResults");

    return tempStruct;
}


