//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the play fab models
//
// API: Leaderboards
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabLeaderboardsModelDecoder.h"
#include "PlayFabPrivate.h"

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Leaderboards API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Leaderboards
//////////////////////////////////////////////////////

FLeaderboardsEmptyResponse UPlayFabLeaderboardsModelDecoder::decodeEmptyResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FLeaderboardsEmptyResponse tempStruct;


    return tempStruct;
}

FLeaderboardsGetLeaderboardDefinitionResponse UPlayFabLeaderboardsModelDecoder::decodeGetLeaderboardDefinitionResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FLeaderboardsGetLeaderboardDefinitionResponse tempStruct;
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

FLeaderboardsIncrementLeaderboardVersionResponse UPlayFabLeaderboardsModelDecoder::decodeIncrementLeaderboardVersionResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FLeaderboardsIncrementLeaderboardVersionResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Version = !(dataObj->HasField("Version")) ? 0 : int(dataObj->GetNumberField("Version"));

    return tempStruct;
}

FLeaderboardsListLeaderboardDefinitionsResponse UPlayFabLeaderboardsModelDecoder::decodeListLeaderboardDefinitionsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FLeaderboardsListLeaderboardDefinitionsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.LeaderboardDefinitions = !(dataObj->HasField("LeaderboardDefinitions")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("LeaderboardDefinitions");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Statistics and Leaderboards
//////////////////////////////////////////////////////

FLeaderboardsDeleteStatisticsResponse UPlayFabLeaderboardsModelDecoder::decodeDeleteStatisticsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FLeaderboardsDeleteStatisticsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Entity = !(dataObj->HasField("Entity")) ? nullptr : dataObj->GetObjectField("Entity");

    return tempStruct;
}

FLeaderboardsGetEntityLeaderboardResponse UPlayFabLeaderboardsModelDecoder::decodeGetEntityLeaderboardResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FLeaderboardsGetEntityLeaderboardResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Columns = !(dataObj->HasField("Columns")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Columns");
    tempStruct.Rankings = !(dataObj->HasField("Rankings")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Rankings");
    tempStruct.Version = !(dataObj->HasField("Version")) ? 0 : int(dataObj->GetNumberField("Version"));

    return tempStruct;
}

FLeaderboardsGetStatisticDefinitionResponse UPlayFabLeaderboardsModelDecoder::decodeGetStatisticDefinitionResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FLeaderboardsGetStatisticDefinitionResponse tempStruct;
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

FLeaderboardsGetStatisticDefinitionsResponse UPlayFabLeaderboardsModelDecoder::decodeGetStatisticDefinitionsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FLeaderboardsGetStatisticDefinitionsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.StatisticDefinitions = !(dataObj->HasField("StatisticDefinitions")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("StatisticDefinitions");

    return tempStruct;
}

FLeaderboardsGetStatisticsResponse UPlayFabLeaderboardsModelDecoder::decodeGetStatisticsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FLeaderboardsGetStatisticsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ColumnDetails = !(dataObj->HasField("ColumnDetails")) ? nullptr : dataObj->GetObjectField("ColumnDetails");
    tempStruct.Entity = !(dataObj->HasField("Entity")) ? nullptr : dataObj->GetObjectField("Entity");
    tempStruct.Statistics = !(dataObj->HasField("Statistics")) ? nullptr : dataObj->GetObjectField("Statistics");

    return tempStruct;
}

FLeaderboardsGetStatisticsForEntitiesResponse UPlayFabLeaderboardsModelDecoder::decodeGetStatisticsForEntitiesResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FLeaderboardsGetStatisticsForEntitiesResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ColumnDetails = !(dataObj->HasField("ColumnDetails")) ? nullptr : dataObj->GetObjectField("ColumnDetails");
    tempStruct.EntitiesStatistics = !(dataObj->HasField("EntitiesStatistics")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("EntitiesStatistics");

    return tempStruct;
}

FLeaderboardsIncrementStatisticVersionResponse UPlayFabLeaderboardsModelDecoder::decodeIncrementStatisticVersionResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FLeaderboardsIncrementStatisticVersionResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Version = !(dataObj->HasField("Version")) ? 0 : int(dataObj->GetNumberField("Version"));

    return tempStruct;
}

FLeaderboardsListStatisticDefinitionsResponse UPlayFabLeaderboardsModelDecoder::decodeListStatisticDefinitionsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FLeaderboardsListStatisticDefinitionsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.CustomTags = !(dataObj->HasField("CustomTags")) ? nullptr : dataObj->GetObjectField("CustomTags");
    tempStruct.StatisticDefinitions = !(dataObj->HasField("StatisticDefinitions")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("StatisticDefinitions");

    return tempStruct;
}

FLeaderboardsUpdateStatisticsResponse UPlayFabLeaderboardsModelDecoder::decodeUpdateStatisticsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FLeaderboardsUpdateStatisticsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ColumnDetails = !(dataObj->HasField("ColumnDetails")) ? nullptr : dataObj->GetObjectField("ColumnDetails");
    tempStruct.Entity = !(dataObj->HasField("Entity")) ? nullptr : dataObj->GetObjectField("Entity");
    tempStruct.Statistics = !(dataObj->HasField("Statistics")) ? nullptr : dataObj->GetObjectField("Statistics");

    return tempStruct;
}


