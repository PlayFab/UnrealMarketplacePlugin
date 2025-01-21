//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Progression
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabRequestCommon.h"
#include "PlayFabLoginResultCommon.h"
#include "PlayFabProgressionModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Progression API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Leaderboards
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionCreateLeaderboardDefinitionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Leaderboard columns describing the sort directions, cannot be changed after creation. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        TArray<UPlayFabJsonObject*> Columns;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * The entity type being represented on the leaderboard. If it doesn't correspond to the PlayFab entity types, use
     * 'external' as the type.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        FString EntityType;
    /** A name for the leaderboard, unique per title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        FString Name;
    /** Maximum number of entries on this leaderboard */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        int32 SizeLimit = 0;
    /** The version reset configuration for the leaderboard definition. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        UPlayFabJsonObject* VersionConfiguration = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionEmptyResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionDeleteLeaderboardDefinitionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The name of the leaderboard definition to delete. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        FString Name;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionDeleteLeaderboardEntriesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The unique Ids of the entries to delete from the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        FString EntityIds;
    /** The name of the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        FString Name;
};

/** Leaderboard response */
USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionGetEntityLeaderboardResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Leaderboard columns describing the sort directions. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        TArray<UPlayFabJsonObject*> Columns;
    /** The number of entries on the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        int32 EntryCount = 0;
    /** Individual entity rankings in the leaderboard, in sorted order by rank. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        TArray<UPlayFabJsonObject*> Rankings;
    /** Version of the leaderboard being returned. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        int32 Version = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionGetFriendLeaderboardForEntityRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        UPlayFabJsonObject* Entity = nullptr;
    /**
     * Indicates which other platforms' friends should be included in the response. In HTTP, it is represented as a
     * comma-separated list of platforms.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        EExternalFriendSources ExternalFriendSources = StaticCast<EExternalFriendSources>(0);
    /** Name of the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        FString LeaderboardName;
    /** Optional version of the leaderboard, defaults to current version. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        int32 Version = 0;
    /** Xbox token if Xbox friends should be included. Requires Xbox be configured on PlayFab. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        FString XboxToken;
};

/** Request to load a leaderboard. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionGetEntityLeaderboardRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Name of the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        FString LeaderboardName;
    /** Maximum number of results to return from the leaderboard. Minimum 1, maximum 1,000. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        int32 PageSize = 0;
    /** Index position to start from. 1 is beginning of leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        int32 StartingPosition = 0;
    /** Optional version of the leaderboard, defaults to current version. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        int32 Version = 0;
};

/** Request to load a section of a leaderboard centered on a specific entity. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionGetLeaderboardAroundEntityRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** Name of the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        FString LeaderboardName;
    /**
     * Number of surrounding entries to return (in addition to specified entity). In general, the number of ranks above and
     * below will be split into half. For example, if the specified value is 10, 5 ranks above and 5 ranks below will be
     * retrieved. However, the numbers will get skewed in either direction when the specified entity is towards the top or
     * bottom of the leaderboard. Also, the number of entries returned can be lower than the value specified for entries at the
     * bottom of the leaderboard.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        int32 MaxSurroundingEntries = 0;
    /** Optional version of the leaderboard, defaults to current. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        int32 Version = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionGetLeaderboardDefinitionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The name of the leaderboard to retrieve the definition for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        FString Name;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionGetLeaderboardDefinitionResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Sort direction of the leaderboard columns, cannot be changed after creation. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        TArray<UPlayFabJsonObject*> Columns;
    /** Created time, in UTC */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        FString Created;
    /**
     * The entity type being represented on the leaderboard. If it doesn't correspond to the PlayFab entity types, use
     * 'external' as the type.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        FString EntityType;
    /** Last time, in UTC, leaderboard version was incremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        FString LastResetTime;
    /** A name for the leaderboard, unique per title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        FString Name;
    /** Maximum number of entries on this leaderboard */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        int32 SizeLimit = 0;
    /** Latest Leaderboard version. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        int32 Version = 0;
    /** The version reset configuration for the leaderboard definition. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        UPlayFabJsonObject* VersionConfiguration = nullptr;
};

/** Request a leaderboard limited to a collection of entities. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionGetLeaderboardForEntitiesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Collection of Entity IDs to include in the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        FString EntityIds;
    /** Name of the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        FString LeaderboardName;
    /** Optional version of the leaderboard, defaults to current. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        int32 Version = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionIncrementLeaderboardVersionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The name of the leaderboard to increment the version for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        FString Name;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionIncrementLeaderboardVersionResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** New Leaderboard version. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        int32 Version = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionListLeaderboardDefinitionsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionListLeaderboardDefinitionsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of leaderboard definitions for the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        TArray<UPlayFabJsonObject*> LeaderboardDefinitions;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionUnlinkLeaderboardFromStatisticRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The name of the leaderboard definition to unlink. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        FString Name;
    /** The name of the statistic definition to unlink. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        FString StatisticName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionUpdateLeaderboardEntriesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entries to add or update on the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        TArray<UPlayFabJsonObject*> Entries;
    /** The name of the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Leaderboards Models")
        FString LeaderboardName;
};


///////////////////////////////////////////////////////
// Statistics
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionCreateStatisticDefinitionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The columns for the statistic defining the aggregation method for each column. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        TArray<UPlayFabJsonObject*> Columns;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity type allowed to have score(s) for this statistic. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        FString EntityType;
    /** Name of the statistic. Must be less than 150 characters. Restricted to a-Z, 0-9, '(', ')', '_', '-' and '.'. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        FString Name;
    /** The version reset configuration for the statistic definition. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        UPlayFabJsonObject* VersionConfiguration = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionDeleteStatisticDefinitionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Name of the statistic to delete. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        FString Name;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionDeleteStatisticsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** Collection of statistics to remove from this entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        TArray<UPlayFabJsonObject*> Statistics;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionDeleteStatisticsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The entity id and type. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionGetStatisticDefinitionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Name of the statistic. Must be less than 150 characters. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        FString Name;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionGetStatisticDefinitionResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The columns for the statistic defining the aggregation method for each column. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        TArray<UPlayFabJsonObject*> Columns;
    /** Created time, in UTC */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        FString Created;
    /** The entity type that can have this statistic. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        FString EntityType;
    /** Last time, in UTC, statistic version was incremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        FString LastResetTime;
    /** The list of leaderboards that are linked to this statistic definition. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        FString LinkedLeaderboardNames;
    /** Name of the statistic. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        FString Name;
    /** Statistic version. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        int32 Version = 0;
    /** The version reset configuration for the leaderboard definition. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        UPlayFabJsonObject* VersionConfiguration = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionGetStatisticsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionGetStatisticsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** A mapping of statistic name to the columns defined in the corresponding definition. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        UPlayFabJsonObject* ColumnDetails = nullptr;
    /** The entity id and type. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** List of statistics keyed by Name. Only the latest version of a statistic is returned. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        UPlayFabJsonObject* Statistics = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionGetStatisticsForEntitiesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Collection of Entity IDs to retrieve statistics for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        TArray<UPlayFabJsonObject*> Entities;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionGetStatisticsForEntitiesResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** A mapping of statistic name to the columns defined in the corresponding definition. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        UPlayFabJsonObject* ColumnDetails = nullptr;
    /** List of entities mapped to their statistics. Only the latest version of a statistic is returned. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        TArray<UPlayFabJsonObject*> EntitiesStatistics;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionIncrementStatisticVersionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Name of the statistic to increment the version of. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        FString Name;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionIncrementStatisticVersionResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** New statistic version. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        int32 Version = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionListStatisticDefinitionsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionListStatisticDefinitionsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** List of statistic definitions for the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        TArray<UPlayFabJsonObject*> StatisticDefinitions;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionUpdateStatisticsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** Collection of statistics to update, maximum 50. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        TArray<UPlayFabJsonObject*> Statistics;
    /**
     * Optional transactionId of this update which can be used to ensure idempotence. Using this field is still in testing
     * stage.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        FString TransactionId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FProgressionUpdateStatisticsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** A mapping of statistic name to the columns defined in the corresponding definition. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        UPlayFabJsonObject* ColumnDetails = nullptr;
    /** The entity id and type. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** Updated entity profile statistics. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Progression | Statistics Models")
        UPlayFabJsonObject* Statistics = nullptr;
};

