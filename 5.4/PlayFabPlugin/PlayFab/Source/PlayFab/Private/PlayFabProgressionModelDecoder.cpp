//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the play fab models
//
// API: Progression
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabProgressionModelDecoder.h"
#include "PlayFabPrivate.h"

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Progression API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Leaderboards
//////////////////////////////////////////////////////

FProgressionEmptyResponse UPlayFabProgressionModelDecoder::decodeEmptyResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FProgressionEmptyResponse tempStruct;


    return tempStruct;
}

FProgressionGetEntityLeaderboardResponse UPlayFabProgressionModelDecoder::decodeGetEntityLeaderboardResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FProgressionGetEntityLeaderboardResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Columns = !(dataObj->HasField("Columns")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Columns");
    tempStruct.Rankings = !(dataObj->HasField("Rankings")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Rankings");
    tempStruct.Version = !(dataObj->HasField("Version")) ? 0 : int(dataObj->GetNumberField("Version"));

    return tempStruct;
}

FProgressionGetLeaderboardDefinitionResponse UPlayFabProgressionModelDecoder::decodeGetLeaderboardDefinitionResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FProgressionGetLeaderboardDefinitionResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Columns = !(dataObj->HasField("Columns")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Columns");
    tempStruct.Created = !(dataObj->HasField("Created")) ? TEXT("") : dataObj->GetStringField("Created");
    tempStruct.EntityType = !(dataObj->HasField("EntityType")) ? TEXT("") : dataObj->GetStringField("EntityType");
    tempStruct.LastResetTime = !(dataObj->HasField("LastResetTime")) ? TEXT("") : dataObj->GetStringField("LastResetTime");
    tempStruct.Name = !(dataObj->HasField("Name")) ? TEXT("") : dataObj->GetStringField("Name");
    tempStruct.SizeLimit = !(dataObj->HasField("SizeLimit")) ? 0 : int(dataObj->GetNumberField("SizeLimit"));
    tempStruct.Version = !(dataObj->HasField("Version")) ? 0 : int(dataObj->GetNumberField("Version"));
    tempStruct.VersionConfiguration = !(dataObj->HasField("VersionConfiguration")) ? nullptr : dataObj->GetObjectField("VersionConfiguration");

    return tempStruct;
}

FProgressionIncrementLeaderboardVersionResponse UPlayFabProgressionModelDecoder::decodeIncrementLeaderboardVersionResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FProgressionIncrementLeaderboardVersionResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Version = !(dataObj->HasField("Version")) ? 0 : int(dataObj->GetNumberField("Version"));

    return tempStruct;
}

FProgressionListLeaderboardDefinitionsResponse UPlayFabProgressionModelDecoder::decodeListLeaderboardDefinitionsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FProgressionListLeaderboardDefinitionsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.LeaderboardDefinitions = !(dataObj->HasField("LeaderboardDefinitions")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("LeaderboardDefinitions");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Statistics
//////////////////////////////////////////////////////

FProgressionDeleteStatisticsResponse UPlayFabProgressionModelDecoder::decodeDeleteStatisticsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FProgressionDeleteStatisticsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Entity = !(dataObj->HasField("Entity")) ? nullptr : dataObj->GetObjectField("Entity");

    return tempStruct;
}

FProgressionGetStatisticDefinitionResponse UPlayFabProgressionModelDecoder::decodeGetStatisticDefinitionResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FProgressionGetStatisticDefinitionResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Columns = !(dataObj->HasField("Columns")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Columns");
    tempStruct.Created = !(dataObj->HasField("Created")) ? TEXT("") : dataObj->GetStringField("Created");
    tempStruct.EntityType = !(dataObj->HasField("EntityType")) ? TEXT("") : dataObj->GetStringField("EntityType");
    tempStruct.LastResetTime = !(dataObj->HasField("LastResetTime")) ? TEXT("") : dataObj->GetStringField("LastResetTime");
    tempStruct.LinkedLeaderboardNames = !(dataObj->HasField("LinkedLeaderboardNames")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("LinkedLeaderboardNames"), TEXT(","));
    tempStruct.Name = !(dataObj->HasField("Name")) ? TEXT("") : dataObj->GetStringField("Name");
    tempStruct.Version = !(dataObj->HasField("Version")) ? 0 : int(dataObj->GetNumberField("Version"));
    tempStruct.VersionConfiguration = !(dataObj->HasField("VersionConfiguration")) ? nullptr : dataObj->GetObjectField("VersionConfiguration");

    return tempStruct;
}

FProgressionGetStatisticDefinitionsResponse UPlayFabProgressionModelDecoder::decodeGetStatisticDefinitionsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FProgressionGetStatisticDefinitionsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.StatisticDefinitions = !(dataObj->HasField("StatisticDefinitions")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("StatisticDefinitions");

    return tempStruct;
}

FProgressionGetStatisticsResponse UPlayFabProgressionModelDecoder::decodeGetStatisticsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FProgressionGetStatisticsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ColumnDetails = !(dataObj->HasField("ColumnDetails")) ? nullptr : dataObj->GetObjectField("ColumnDetails");
    tempStruct.Entity = !(dataObj->HasField("Entity")) ? nullptr : dataObj->GetObjectField("Entity");
    tempStruct.Statistics = !(dataObj->HasField("Statistics")) ? nullptr : dataObj->GetObjectField("Statistics");

    return tempStruct;
}

FProgressionGetStatisticsForEntitiesResponse UPlayFabProgressionModelDecoder::decodeGetStatisticsForEntitiesResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FProgressionGetStatisticsForEntitiesResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ColumnDetails = !(dataObj->HasField("ColumnDetails")) ? nullptr : dataObj->GetObjectField("ColumnDetails");
    tempStruct.EntitiesStatistics = !(dataObj->HasField("EntitiesStatistics")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("EntitiesStatistics");

    return tempStruct;
}

FProgressionIncrementStatisticVersionResponse UPlayFabProgressionModelDecoder::decodeIncrementStatisticVersionResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FProgressionIncrementStatisticVersionResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Version = !(dataObj->HasField("Version")) ? 0 : int(dataObj->GetNumberField("Version"));

    return tempStruct;
}

FProgressionListStatisticDefinitionsResponse UPlayFabProgressionModelDecoder::decodeListStatisticDefinitionsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FProgressionListStatisticDefinitionsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.CustomTags = !(dataObj->HasField("CustomTags")) ? nullptr : dataObj->GetObjectField("CustomTags");
    tempStruct.StatisticDefinitions = !(dataObj->HasField("StatisticDefinitions")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("StatisticDefinitions");

    return tempStruct;
}

FProgressionUpdateStatisticsResponse UPlayFabProgressionModelDecoder::decodeUpdateStatisticsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FProgressionUpdateStatisticsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ColumnDetails = !(dataObj->HasField("ColumnDetails")) ? nullptr : dataObj->GetObjectField("ColumnDetails");
    tempStruct.Entity = !(dataObj->HasField("Entity")) ? nullptr : dataObj->GetObjectField("Entity");
    tempStruct.Statistics = !(dataObj->HasField("Statistics")) ? nullptr : dataObj->GetObjectField("Statistics");

    return tempStruct;
}


