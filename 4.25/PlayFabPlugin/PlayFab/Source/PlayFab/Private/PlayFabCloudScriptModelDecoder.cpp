//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the play fab models
//
// API: CloudScript
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabCloudScriptModelDecoder.h"
#include "PlayFabPrivate.h"

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab CloudScript API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Server-Side Cloud Script
//////////////////////////////////////////////////////

FCloudScriptExecuteCloudScriptResult UPlayFabCloudScriptModelDecoder::decodeExecuteCloudScriptResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FCloudScriptExecuteCloudScriptResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.APIRequestsIssued = !(dataObj->HasField("APIRequestsIssued")) ? 0 : int(dataObj->GetNumberField("APIRequestsIssued"));
    tempStruct.Error = !(dataObj->HasField("Error")) ? nullptr : dataObj->GetObjectField("Error");
    tempStruct.ExecutionTimeSeconds = !(dataObj->HasField("ExecutionTimeSeconds")) ? 0 : int(dataObj->GetNumberField("ExecutionTimeSeconds"));
    tempStruct.FunctionName = !(dataObj->HasField("FunctionName")) ? TEXT("") : dataObj->GetStringField("FunctionName");
    tempStruct.FunctionResult = !(dataObj->HasField("FunctionResult")) ? nullptr : dataObj->GetObjectField("FunctionResult");
    tempStruct.FunctionResultTooLarge = !(dataObj->HasField("FunctionResultTooLarge")) ? false : dataObj->GetBoolField("FunctionResultTooLarge");
    tempStruct.HttpRequestsIssued = !(dataObj->HasField("HttpRequestsIssued")) ? 0 : int(dataObj->GetNumberField("HttpRequestsIssued"));
    tempStruct.Logs = !(dataObj->HasField("Logs")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Logs");
    tempStruct.LogsTooLarge = !(dataObj->HasField("LogsTooLarge")) ? false : dataObj->GetBoolField("LogsTooLarge");
    tempStruct.MemoryConsumedBytes = !(dataObj->HasField("MemoryConsumedBytes")) ? 0 : int(dataObj->GetNumberField("MemoryConsumedBytes"));
    tempStruct.ProcessorTimeSeconds = !(dataObj->HasField("ProcessorTimeSeconds")) ? 0 : int(dataObj->GetNumberField("ProcessorTimeSeconds"));
    tempStruct.Revision = !(dataObj->HasField("Revision")) ? 0 : int(dataObj->GetNumberField("Revision"));

    return tempStruct;
}

FCloudScriptExecuteFunctionResult UPlayFabCloudScriptModelDecoder::decodeExecuteFunctionResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FCloudScriptExecuteFunctionResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Error = !(dataObj->HasField("Error")) ? nullptr : dataObj->GetObjectField("Error");
    tempStruct.ExecutionTimeMilliseconds = !(dataObj->HasField("ExecutionTimeMilliseconds")) ? 0 : int(dataObj->GetNumberField("ExecutionTimeMilliseconds"));
    tempStruct.FunctionName = !(dataObj->HasField("FunctionName")) ? TEXT("") : dataObj->GetStringField("FunctionName");
    tempStruct.FunctionResult = !(dataObj->HasField("FunctionResult")) ? nullptr : dataObj->GetObjectField("FunctionResult");
    tempStruct.FunctionResultTooLarge = !(dataObj->HasField("FunctionResultTooLarge")) ? false : dataObj->GetBoolField("FunctionResultTooLarge");

    return tempStruct;
}

FCloudScriptListFunctionsResult UPlayFabCloudScriptModelDecoder::decodeListFunctionsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FCloudScriptListFunctionsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Functions = !(dataObj->HasField("Functions")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Functions");

    return tempStruct;
}

FCloudScriptListHttpFunctionsResult UPlayFabCloudScriptModelDecoder::decodeListHttpFunctionsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FCloudScriptListHttpFunctionsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Functions = !(dataObj->HasField("Functions")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Functions");

    return tempStruct;
}

FCloudScriptListQueuedFunctionsResult UPlayFabCloudScriptModelDecoder::decodeListQueuedFunctionsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FCloudScriptListQueuedFunctionsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Functions = !(dataObj->HasField("Functions")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Functions");

    return tempStruct;
}

FCloudScriptEmptyResult UPlayFabCloudScriptModelDecoder::decodeEmptyResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FCloudScriptEmptyResult tempStruct;


    return tempStruct;
}


