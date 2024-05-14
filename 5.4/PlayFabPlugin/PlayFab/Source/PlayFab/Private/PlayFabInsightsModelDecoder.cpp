//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the play fab models
//
// API: Insights
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabInsightsModelDecoder.h"
#include "PlayFabPrivate.h"

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Insights API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Analytics
//////////////////////////////////////////////////////

FInsightsInsightsGetDetailsResponse UPlayFabInsightsModelDecoder::decodeInsightsGetDetailsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FInsightsInsightsGetDetailsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.DataUsageMb = !(dataObj->HasField("DataUsageMb")) ? 0 : int(dataObj->GetNumberField("DataUsageMb"));
    tempStruct.ErrorMessage = !(dataObj->HasField("ErrorMessage")) ? TEXT("") : dataObj->GetStringField("ErrorMessage");
    tempStruct.Limits = !(dataObj->HasField("Limits")) ? nullptr : dataObj->GetObjectField("Limits");
    tempStruct.PendingOperations = !(dataObj->HasField("PendingOperations")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("PendingOperations");
    tempStruct.PerformanceLevel = !(dataObj->HasField("PerformanceLevel")) ? 0 : int(dataObj->GetNumberField("PerformanceLevel"));
    tempStruct.RetentionDays = !(dataObj->HasField("RetentionDays")) ? 0 : int(dataObj->GetNumberField("RetentionDays"));

    return tempStruct;
}

FInsightsInsightsGetLimitsResponse UPlayFabInsightsModelDecoder::decodeInsightsGetLimitsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FInsightsInsightsGetLimitsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.DefaultPerformanceLevel = !(dataObj->HasField("DefaultPerformanceLevel")) ? 0 : int(dataObj->GetNumberField("DefaultPerformanceLevel"));
    tempStruct.DefaultStorageRetentionDays = !(dataObj->HasField("DefaultStorageRetentionDays")) ? 0 : int(dataObj->GetNumberField("DefaultStorageRetentionDays"));
    tempStruct.StorageMaxRetentionDays = !(dataObj->HasField("StorageMaxRetentionDays")) ? 0 : int(dataObj->GetNumberField("StorageMaxRetentionDays"));
    tempStruct.StorageMinRetentionDays = !(dataObj->HasField("StorageMinRetentionDays")) ? 0 : int(dataObj->GetNumberField("StorageMinRetentionDays"));
    tempStruct.SubMeters = !(dataObj->HasField("SubMeters")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("SubMeters");

    return tempStruct;
}

FInsightsInsightsGetOperationStatusResponse UPlayFabInsightsModelDecoder::decodeInsightsGetOperationStatusResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FInsightsInsightsGetOperationStatusResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Message = !(dataObj->HasField("Message")) ? TEXT("") : dataObj->GetStringField("Message");
    tempStruct.OperationCompletedTime = !(dataObj->HasField("OperationCompletedTime")) ? TEXT("") : dataObj->GetStringField("OperationCompletedTime");
    tempStruct.OperationId = !(dataObj->HasField("OperationId")) ? TEXT("") : dataObj->GetStringField("OperationId");
    tempStruct.OperationLastUpdated = !(dataObj->HasField("OperationLastUpdated")) ? TEXT("") : dataObj->GetStringField("OperationLastUpdated");
    tempStruct.OperationStartedTime = !(dataObj->HasField("OperationStartedTime")) ? TEXT("") : dataObj->GetStringField("OperationStartedTime");
    tempStruct.OperationType = !(dataObj->HasField("OperationType")) ? TEXT("") : dataObj->GetStringField("OperationType");
    tempStruct.OperationValue = !(dataObj->HasField("OperationValue")) ? 0 : int(dataObj->GetNumberField("OperationValue"));
    tempStruct.Status = !(dataObj->HasField("Status")) ? TEXT("") : dataObj->GetStringField("Status");

    return tempStruct;
}

FInsightsInsightsGetPendingOperationsResponse UPlayFabInsightsModelDecoder::decodeInsightsGetPendingOperationsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FInsightsInsightsGetPendingOperationsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.PendingOperations = !(dataObj->HasField("PendingOperations")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("PendingOperations");

    return tempStruct;
}

FInsightsInsightsOperationResponse UPlayFabInsightsModelDecoder::decodeInsightsOperationResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FInsightsInsightsOperationResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Message = !(dataObj->HasField("Message")) ? TEXT("") : dataObj->GetStringField("Message");
    tempStruct.OperationId = !(dataObj->HasField("OperationId")) ? TEXT("") : dataObj->GetStringField("OperationId");
    tempStruct.OperationType = !(dataObj->HasField("OperationType")) ? TEXT("") : dataObj->GetStringField("OperationType");

    return tempStruct;
}


