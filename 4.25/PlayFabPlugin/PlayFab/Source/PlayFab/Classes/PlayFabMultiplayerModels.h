//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Multiplayer
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabRequestCommon.h"
#include "PlayFabLoginResultCommon.h"
#include "PlayFabMultiplayerModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Multiplayer API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Lobby
//////////////////////////////////////////////////////

/** Request to create a lobby. A Server or client can create a lobby. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateLobbyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * The policy indicating who is allowed to join the lobby, and the visibility to queries. May be 'Public', 'Friends' or
     * 'Private'. Public means the lobby is both visible in queries and any player may join, including invited players. Friends
     * means that users who are bidirectional friends of members in the lobby may search to find friend lobbies, to retrieve
     * its connection string. Private means the lobby is not visible in queries, and a player must receive an invitation to
     * join. Defaults to 'Public' on creation. Can only be changed by the lobby owner.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        EAccessPolicy AccessPolicy = StaticCast<EAccessPolicy>(0);
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * The private key-value pairs which are visible to all entities in the lobby. At most 30 key-value pairs may be stored
     * here, keys are limited to 30 characters and values to 1000. The total size of all lobbyData values may not exceed 4096
     * bytes. Keys are case sensitive.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* LobbyData = nullptr;
    /** The maximum number of players allowed in the lobby. The value must be between 2 and 128. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        int32 MaxPlayers = 0;
    /**
     * The member initially added to the lobby. Client must specify exactly one member, which is the creator's entity and
     * member data. Member PubSubConnectionHandle must be null or empty. Game servers must not specify any members.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        TArray<UPlayFabJsonObject*> Members;
    /** The lobby owner. Must be the calling entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* Owner = nullptr;
    /**
     * The policy for how a new owner is chosen. May be 'Automatic', 'Manual' or 'None'. Can only be specified by clients. If
     * client-owned and 'Automatic' - The Lobby service will automatically assign another connected owner when the current
     * owner leaves or disconnects. The useConnections property must be true. If client - owned and 'Manual' - Ownership is
     * protected as long as the current owner is connected. If the current owner leaves or disconnects any member may set
     * themselves as the current owner. The useConnections property must be true. If client-owned and 'None' - Any member can
     * set ownership. The useConnections property can be either true or false.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        EOwnerMigrationPolicy OwnerMigrationPolicy = StaticCast<EOwnerMigrationPolicy>(0);
    /**
     * The public key-value pairs which allow queries to differentiate between lobbies. Queries will refer to these key-value
     * pairs in their filter and order by clauses to retrieve lobbies fitting the specified criteria. At most 30 key-value
     * pairs may be stored here. Keys are of the format string_key1, string_key2 ... string_key30 for string values, or
     * number_key1, number_key2, ... number_key30 for numeric values.Numeric values are floats. Values can be at most 256
     * characters long. The total size of all searchData values may not exceed 1024 bytes.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* SearchData = nullptr;
    /**
     * A setting to control whether connections are used. Defaults to true. When true, notifications are sent to subscribed
     * players, disconnect detection removes connectionHandles, only owner migration policies using connections are allowed,
     * and lobbies must have at least one connected member to be searchable or be a server hosted lobby with a connected
     * server. If false, then notifications are not sent, connections are not allowed, and lobbies do not need connections to
     * be searchable.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        bool UseConnections = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateLobbyResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** A field which indicates which lobby the user will be joining. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString ConnectionString;
    /** Id to uniquely identify a lobby. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString LobbyId;
};

/** Request to delete a lobby. Only servers can delete lobbies. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerDeleteLobbyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The id of the lobby. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString LobbyId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerLobbyEmptyResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/** Request to find friends lobbies. Only a client can find friend lobbies. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerFindFriendLobbiesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Indicates which other platforms' friends this query should link to. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        EExternalFriendSources ExternalPlatformFriends = StaticCast<EExternalFriendSources>(0);
    /**
     * OData style string that contains one or more filters. Only the following operators are supported: "and" (logical and),
     * "eq" (equal), "ne" (not equals), "ge" (greater than or equal), "gt" (greater than), "le" (less than or equal), and "lt"
     * (less than). The left-hand side of each OData logical expression should be either a search property key (e.g.
     * string_key1, number_key3, etc) or one of the pre-defined search keys all of which must be prefixed by "lobby/":
     * lobby/memberCount (number of players in a lobby), lobby/maxMemberCount (maximum number of players allowed in a lobby),
     * lobby/memberCountRemaining (remaining number of players who can be allowed in a lobby), lobby/membershipLock (must equal
     * 'Unlocked' or 'Locked'), lobby/amOwner (required to equal "true"), lobby/amMember (required to equal "true").
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString Filter;
    /**
     * OData style string that contains sorting for this query in either ascending ("asc") or descending ("desc") order.
     * OrderBy clauses are of the form "number_key1 asc" or the pre-defined search key "lobby/memberCount asc",
     * "lobby/memberCountRemaining desc" and "lobby/maxMemberCount desc". To sort by closest, a moniker `distance{number_key1 =
     * 5}` can be used to sort by distance from the given number. This field only supports either one sort clause or one
     * distance clause.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString OrderBy;
    /** Request pagination information. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* Pagination = nullptr;
    /** Xbox token if Xbox friends should be included. Requires Xbox be configured on PlayFab. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString XboxToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerFindFriendLobbiesResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of lobbies found that matched FindFriendLobbies request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        TArray<UPlayFabJsonObject*> Lobbies;
    /** Pagination response for FindFriendLobbies request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* Pagination = nullptr;
};

/** Request to find lobbies. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerFindLobbiesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * OData style string that contains one or more filters. Only the following operators are supported: "and" (logical and),
     * "eq" (equal), "ne" (not equals), "ge" (greater than or equal), "gt" (greater than), "le" (less than or equal), and "lt"
     * (less than). The left-hand side of each OData logical expression should be either a search property key (e.g.
     * string_key1, number_key3, etc) or one of the pre-defined search keys all of which must be prefixed by "lobby/":
     * lobby/memberCount (number of players in a lobby), lobby/maxMemberCount (maximum number of players allowed in a lobby),
     * lobby/memberCountRemaining (remaining number of players who can be allowed in a lobby), lobby/membershipLock (must equal
     * 'Unlocked' or 'Locked'), lobby/amOwner (required to equal "true"), lobby/amMember (required to equal "true").
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString Filter;
    /**
     * OData style string that contains sorting for this query in either ascending ("asc") or descending ("desc") order.
     * OrderBy clauses are of the form "number_key1 asc" or the pre-defined search key "lobby/memberCount asc",
     * "lobby/memberCountRemaining desc" and "lobby/maxMemberCount desc". To sort by closest, a moniker `distance{number_key1 =
     * 5}` can be used to sort by distance from the given number. This field only supports either one sort clause or one
     * distance clause.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString OrderBy;
    /** Request pagination information. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* Pagination = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerFindLobbiesResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of lobbies found that matched FindLobbies request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        TArray<UPlayFabJsonObject*> Lobbies;
    /** Pagination response for FindLobbies request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* Pagination = nullptr;
};

/** Request to get a lobby. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetLobbyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The id of the lobby. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString LobbyId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetLobbyResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The information pertaining to the requested lobby. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* Lobby = nullptr;
};

/**
 * Request to invite a player to a lobby the caller is already a member of. Only a client can invite another player to a
 * lobby.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerInviteToLobbyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity invited to the lobby. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* InviteeEntity = nullptr;
    /** The id of the lobby. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString LobbyId;
    /** The member entity sending the invite. Must be a member of the lobby. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* MemberEntity = nullptr;
};

/** Request to join an arranged lobby. Only a client can join an arranged lobby. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerJoinArrangedLobbyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * The policy indicating who is allowed to join the lobby, and the visibility to queries. May be 'Public', 'Friends' or
     * 'Private'. Public means the lobby is both visible in queries and any player may join, including invited players. Friends
     * means that users who are bidirectional friends of members in the lobby may search to find friend lobbies, to retrieve
     * its connection string. Private means the lobby is not visible in queries, and a player must receive an invitation to
     * join. Defaults to 'Public' on creation. Can only be changed by the lobby owner.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        EAccessPolicy AccessPolicy = StaticCast<EAccessPolicy>(0);
    /**
     * A field which indicates which lobby the user will be joining. This field is opaque to everyone except the Lobby service
     * and the creator of the arrangementString (Matchmaking). This string defines a unique identifier for the arranged lobby
     * as well as the title and member the string is valid for. Arrangement strings have an expiration.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString ArrangementString;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The maximum number of players allowed in the lobby. The value must be between 2 and 128. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        int32 MaxPlayers = 0;
    /**
     * The private key-value pairs used by the member to communicate information to other members and the owner. Visible to all
     * entities in the lobby. At most 30 key-value pairs may be stored here, keys are limited to 30 characters and values to
     * 1000. The total size of all memberData values may not exceed 4096 bytes. Keys are case sensitive.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* MemberData = nullptr;
    /** The member entity who is joining the lobby. The first member to join will be the lobby owner. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* MemberEntity = nullptr;
    /**
     * The policy for how a new owner is chosen. May be 'Automatic', 'Manual' or 'None'. Can only be specified by clients. If
     * client-owned and 'Automatic' - The Lobby service will automatically assign another connected owner when the current
     * owner leaves or disconnects. The useConnections property must be true. If client - owned and 'Manual' - Ownership is
     * protected as long as the current owner is connected. If the current owner leaves or disconnects any member may set
     * themselves as the current owner. The useConnections property must be true. If client-owned and 'None' - Any member can
     * set ownership. The useConnections property can be either true or false.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        EOwnerMigrationPolicy OwnerMigrationPolicy = StaticCast<EOwnerMigrationPolicy>(0);
    /**
     * A setting to control whether connections are used. Defaults to true. When true, notifications are sent to subscribed
     * players, disconnect detection removes connectionHandles, only owner migration policies using connections are allowed,
     * and lobbies must have at least one connected member to be searchable or be a server hosted lobby with a connected
     * server. If false, then notifications are not sent, connections are not allowed, and lobbies do not need connections to
     * be searchable.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        bool UseConnections = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerJoinLobbyResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Successfully joined lobby's id. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString LobbyId;
};

/** Request to join a lobby. Only a client can join a lobby. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerJoinLobbyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** A field which indicates which lobby the user will be joining. This field is opaque to everyone except the Lobby service. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString ConnectionString;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * The private key-value pairs used by the member to communicate information to other members and the owner. Visible to all
     * entities in the lobby. At most 30 key-value pairs may be stored here, keys are limited to 30 characters and values to
     * 1000. The total size of all memberData values may not exceed 4096 bytes.Keys are case sensitive.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* MemberData = nullptr;
    /** The member entity who is joining the lobby. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* MemberEntity = nullptr;
};

/**
 * Preview: Request to join a lobby as a server. Only callable by a game_server entity and this is restricted to client
 * owned lobbies which are using connections.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerJoinLobbyAsServerRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * A field which indicates which lobby the game_server will be joining. This field is opaque to everyone except the Lobby
     * service.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString ConnectionString;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * The private key-value pairs which are visible to all entities in the lobby but can only be modified by the joined
     * server.At most 30 key - value pairs may be stored here, keys are limited to 30 characters and values to 1000.The total
     * size of all serverData values may not exceed 4096 bytes.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* ServerData = nullptr;
    /**
     * The game_server entity which is joining the Lobby. If a different game_server entity has already joined the request will
     * fail unless the joined entity is disconnected, in which case the incoming game_server entity will replace the
     * disconnected entity.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* ServerEntity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerJoinLobbyAsServerResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Successfully joined lobby's id. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString LobbyId;
};

/** Request to leave a lobby. Only a client can leave a lobby. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerLeaveLobbyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The id of the lobby. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString LobbyId;
    /** The member entity leaving the lobby. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* MemberEntity = nullptr;
};

/**
 * Preview: Request for server to leave a lobby. Only a game_server entity can leave and this is restricted to client owned
 * lobbies which are using connections.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerLeaveLobbyAsServerRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The id of the lobby. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString LobbyId;
    /**
     * The game_server entity leaving the lobby. If the game_server was subscribed to notifications, it will be unsubscribed.
     * If a the given game_server entity is not in the lobby, it will fail.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* ServerEntity = nullptr;
};

/**
 * Request to remove a member from a lobby. Owners may remove other members from a lobby. Members cannot remove themselves
 * (use LeaveLobby instead).
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerRemoveMemberFromLobbyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The id of the lobby. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString LobbyId;
    /** The member entity to be removed from the lobby. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* MemberEntity = nullptr;
    /** If true, removed member can never rejoin this lobby. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        bool PreventRejoin = false;
};

/** Request to subscribe to lobby resource notifications. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerSubscribeToLobbyResourceRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity performing the subscription. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* EntityKey = nullptr;
    /** Opaque string, given to a client upon creating a connection with PubSub. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString PubSubConnectionHandle;
    /** The name of the resource to subscribe to. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString ResourceId;
    /** Version number for the subscription of this resource. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        int32 SubscriptionVersion = 0;
    /** Subscription type. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        ESubscriptionType Type = StaticCast<ESubscriptionType>(0);
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerSubscribeToLobbyResourceResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Topic will be returned in all notifications that are the result of this subscription. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString Topic;
};

/** Request to unsubscribe from lobby notifications. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerUnsubscribeFromLobbyResourceRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity which performed the subscription. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* EntityKey = nullptr;
    /** Opaque string, given to a client upon creating a connection with PubSub. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString PubSubConnectionHandle;
    /** The name of the resource to unsubscribe from. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString ResourceId;
    /** Version number passed for the subscription of this resource. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        int32 SubscriptionVersion = 0;
    /** Subscription type. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        ESubscriptionType Type = StaticCast<ESubscriptionType>(0);
};

/** Request to update a lobby. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerUpdateLobbyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * The policy indicating who is allowed to join the lobby, and the visibility to queries. May be 'Public', 'Friends' or
     * 'Private'. Public means the lobby is both visible in queries and any player may join, including invited players. Friends
     * means that users who are bidirectional friends of members in the lobby may search to find friend lobbies, to retrieve
     * its connection string. Private means the lobby is not visible in queries, and a player must receive an invitation to
     * join. Defaults to 'Public' on creation. Can only be changed by the lobby owner.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        EAccessPolicy AccessPolicy = StaticCast<EAccessPolicy>(0);
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * The private key-value pairs which are visible to all entities in the lobby. Optional. Sets or updates key-value pairs on
     * the lobby. Only the current lobby owner can set lobby data. Keys may be an arbitrary string of at most 30 characters.
     * The total size of all lobbyData values may not exceed 4096 bytes. Values are not individually limited. There can be up
     * to 30 key-value pairs stored here. Keys are case sensitive.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* LobbyData = nullptr;
    /** The keys to delete from the lobby LobbyData. Optional. Behaves similar to searchDataToDelete, but applies to lobbyData. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString LobbyDataToDelete;
    /** The id of the lobby. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString LobbyId;
    /**
     * The maximum number of players allowed in the lobby. Updates the maximum allowed number of players in the lobby. Only the
     * current lobby owner can set this. If set, the value must be greater than or equal to the number of members currently in
     * the lobby.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        int32 MaxPlayers = 0;
    /**
     * The private key-value pairs used by the member to communicate information to other members and the owner. Optional. Sets
     * or updates new key-value pairs on the caller's member data. New keys will be added with their values and existing keys
     * will be updated with the new values. Visible to all entities in the lobby. At most 30 key-value pairs may be stored
     * here, keys are limited to 30 characters and values to 1000. The total size of all memberData values may not exceed 4096
     * bytes. Keys are case sensitive. Servers cannot specifiy this.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* MemberData = nullptr;
    /**
     * The keys to delete from the lobby MemberData. Optional. Deletes key-value pairs on the caller's member data. All the
     * specified keys will be removed from the caller's member data. Keys that do not exist are a no-op. If the key to delete
     * exists in the memberData (same request) it will result in a bad request. Servers cannot specifiy this.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString MemberDataToDelete;
    /** The member entity whose data is being modified. Servers cannot specify this. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* MemberEntity = nullptr;
    /**
     * A setting indicating whether the lobby is locked. May be 'Unlocked' or 'Locked'. When Locked new members are not allowed
     * to join. Defaults to 'Unlocked' on creation. Can only be changed by the lobby owner.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        EMembershipLock MembershipLock = StaticCast<EMembershipLock>(0);
    /**
     * The lobby owner. Optional. Set to transfer ownership of the lobby. If client - owned and 'Automatic' - The Lobby service
     * will automatically assign another connected owner when the current owner leaves or disconnects. useConnections must be
     * true. If client - owned and 'Manual' - Ownership is protected as long as the current owner is connected. If the current
     * owner leaves or disconnects any member may set themselves as the current owner. The useConnections property must be
     * true. If client-owned and 'None' - Any member can set ownership. The useConnections property can be either true or
     * false. For all client-owned lobbies when the owner leaves and a new owner can not be automatically selected - The owner
     * field is set to null. For all client-owned lobbies when the owner disconnects and a new owner can not be automatically
     * selected - The owner field remains unchanged and the current owner retains all owner abilities for the lobby. If
     * server-owned (must be 'Server') - Any server can set ownership. The useConnections property must be true.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* Owner = nullptr;
    /**
     * The public key-value pairs which allow queries to differentiate between lobbies. Optional. Sets or updates key-value
     * pairs on the lobby for use with queries. Only the current lobby owner can set search data. New keys will be added with
     * their values and existing keys will be updated with the new values. There can be up to 30 key-value pairs stored here.
     * Keys are of the format string_key1, string_key2... string_key30 for string values, or number_key1, number_key2, ...
     * number_key30 for numeric values. Numeric values are floats. Values can be at most 256 characters long. The total size of
     * all searchData values may not exceed 1024 bytes.Keys are case sensitive.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* SearchData = nullptr;
    /**
     * The keys to delete from the lobby SearchData. Optional. Deletes key-value pairs on the lobby. Only the current lobby
     * owner can delete search data. All the specified keys will be removed from the search data. Keys that do not exist in the
     * lobby are a no-op.If the key to delete exists in the searchData (same request) it will result in a bad request.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString SearchDataToDelete;
};

/**
 * Preview: Request to update the serverData and serverEntity in case of migration. Only a game_server entity can update
 * this information and this is restricted to client owned lobbies which are using connections.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerUpdateLobbyAsServerRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The id of the lobby. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString LobbyId;
    /**
     * The private key-value pairs which are visible to all entities in the lobby and modifiable by the joined server.
     * Optional. Sets or updates key-value pairs on the lobby. Only the current lobby lobby server can set serverData. Keys may
     * be an arbitrary string of at most 30 characters. The total size of all serverData values may not exceed 4096 bytes.
     * Values are not individually limited. There can be up to 30 key-value pairs stored here. Keys are case sensitive.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* ServerData = nullptr;
    /**
     * The keys to delete from the lobby serverData. Optional. Optional. Deletes key-value pairs on the lobby. Only the current
     * joined lobby server can delete serverData. All the specified keys will be removed from the serverData. Keys that do not
     * exist in the lobby are a no-op. If the key to delete exists in the serverData (same request) it will result in a bad
     * request.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        FString ServerDataToDelete;
    /**
     * The lobby server. Optional. Set a different server as the joined server of the lobby (there can only be 1 joined
     * server). When changing the server the previous server will automatically be unsubscribed.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Lobby Models")
        UPlayFabJsonObject* ServerEntity = nullptr;
};


///////////////////////////////////////////////////////
// Matchmaking
//////////////////////////////////////////////////////

/**
 * Cancels all tickets of which the player is a member in a given queue that are not cancelled or matched. This API is
 * useful if you lose track of what tickets the player is a member of (if the title crashes for instance) and want to
 * "reset". The Entity field is optional if the caller is a player and defaults to that player. Players may not cancel
 * tickets for other people. The Entity field is required if the caller is a server (authenticated as the title).
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCancelAllMatchmakingTicketsForPlayerRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity key of the player whose tickets should be canceled. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The name of the queue from which a player's tickets should be canceled. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString QueueName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCancelAllMatchmakingTicketsForPlayerResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * Cancels all backfill tickets of which the player is a member in a given queue that are not cancelled or matched. This
 * API is useful if you lose track of what tickets the player is a member of (if the server crashes for instance) and want
 * to "reset".
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCancelAllServerBackfillTicketsForPlayerRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity key of the player whose backfill tickets should be canceled. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The name of the queue from which a player's backfill tickets should be canceled. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString QueueName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCancelAllServerBackfillTicketsForPlayerResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * Only servers and ticket members can cancel a ticket. The ticket can be in five different states when it is cancelled. 1:
 * the ticket is waiting for members to join it, and it has not started matching. If the ticket is cancelled at this stage,
 * it will never match. 2: the ticket is matching. If the ticket is cancelled, it will stop matching. 3: the ticket is
 * matched. A matched ticket cannot be cancelled. 4: the ticket is already cancelled and nothing happens. 5: the ticket is
 * waiting for a server. If the ticket is cancelled, server allocation will be stopped. A server may still be allocated due
 * to a race condition, but that will not be reflected in the ticket. There may be race conditions between the ticket
 * getting matched and the client making a cancellation request. The client must handle the possibility that the cancel
 * request fails if a match is found before the cancellation request is processed. We do not allow resubmitting a cancelled
 * ticket because players must consent to enter matchmaking again. Create a new ticket instead.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCancelMatchmakingTicketRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The name of the queue the ticket is in. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString QueueName;
    /** The Id of the ticket to find a match for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString TicketId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCancelMatchmakingTicketResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * Only servers can cancel a backfill ticket. The ticket can be in three different states when it is cancelled. 1: the
 * ticket is matching. If the ticket is cancelled, it will stop matching. 2: the ticket is matched. A matched ticket cannot
 * be cancelled. 3: the ticket is already cancelled and nothing happens. There may be race conditions between the ticket
 * getting matched and the server making a cancellation request. The server must handle the possibility that the cancel
 * request fails if a match is found before the cancellation request is processed. We do not allow resubmitting a cancelled
 * ticket. Create a new ticket instead.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCancelServerBackfillTicketRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The name of the queue the ticket is in. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString QueueName;
    /** The Id of the ticket to find a match for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString TicketId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCancelServerBackfillTicketResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/** The client specifies the creator's attributes and optionally a list of other users to match with. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateMatchmakingTicketRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The User who created this ticket. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* Creator = nullptr;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** How long to attempt matching this ticket in seconds. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        int32 GiveUpAfterSeconds = 0;
    /** A list of Entity Keys of other users to match with. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        TArray<UPlayFabJsonObject*> MembersToMatchWith;
    /** The Id of a match queue. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString QueueName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateMatchmakingTicketResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The Id of the ticket to find a match for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString TicketId;
};

/** The server specifies all the members, their teams and their attributes, and the server details if applicable. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateServerBackfillTicketRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** How long to attempt matching this ticket in seconds. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        int32 GiveUpAfterSeconds = 0;
    /** The users who will be part of this ticket, along with their team assignments. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        TArray<UPlayFabJsonObject*> Members;
    /** The Id of a match queue. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString QueueName;
    /** The details of the server the members are connected to. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* ServerDetails = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateServerBackfillTicketResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The Id of the ticket to find a match for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString TicketId;
};

/** The server specifies all the members and their attributes. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateServerMatchmakingTicketRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** How long to attempt matching this ticket in seconds. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        int32 GiveUpAfterSeconds = 0;
    /** The users who will be part of this ticket. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        TArray<UPlayFabJsonObject*> Members;
    /** The Id of a match queue. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString QueueName;
};

/**
 * When matchmaking has successfully matched together a collection of tickets, it produces a 'match' with an Id. The match
 * contains all of the players that were matched together, and their team assigments. Only servers and ticket members can
 * get the match.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetMatchRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Determines whether the matchmaking attributes will be returned as an escaped JSON string or as an un-escaped JSON
     * object.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        bool EscapeObject = false;
    /** The Id of a match. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString MatchId;
    /** The name of the queue to join. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString QueueName;
    /** Determines whether the matchmaking attributes for each user should be returned in the response for match request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        bool ReturnMemberAttributes = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetMatchResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** A string that is used by players that are matched together to join an arranged lobby. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString ArrangementString;
    /** The Id of a match. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString MatchId;
    /** A list of Users that are matched together, along with their team assignments. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        TArray<UPlayFabJsonObject*> Members;
    /**
     * A list of regions that the match could be played in sorted by preference. This value is only set if the queue has a
     * region selection rule.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString RegionPreferences;
    /** The details of the server that the match has been allocated to. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* ServerDetails = nullptr;
};

/**
 * The ticket includes the invited players, their attributes if they have joined, the ticket status, the match Id when
 * applicable, etc. Only servers, the ticket creator and the invited players can get the ticket.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetMatchmakingTicketRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Determines whether the matchmaking attributes will be returned as an escaped JSON string or as an un-escaped JSON
     * object.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        bool EscapeObject = false;
    /** The name of the queue to find a match for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString QueueName;
    /** The Id of the ticket to find a match for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString TicketId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetMatchmakingTicketResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * The reason why the current ticket was canceled. This field is only set if the ticket is in canceled state. Please retry
     * if CancellationReason is RetryRequired.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString CancellationReasonString;
    /** Change number used for differentiating older matchmaking status updates from newer ones. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        int32 ChangeNumber = 0;
    /** The server date and time at which ticket was created. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString Created;
    /** The Creator's entity key. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* Creator = nullptr;
    /** How long to attempt matching this ticket in seconds. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        int32 GiveUpAfterSeconds = 0;
    /** The Id of a match. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString MatchId;
    /** A list of Users that have joined this ticket. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        TArray<UPlayFabJsonObject*> Members;
    /** A list of PlayFab Ids of Users to match with. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        TArray<UPlayFabJsonObject*> MembersToMatchWith;
    /** The Id of a match queue. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString QueueName;
    /**
     * The current ticket status. Possible values are: WaitingForPlayers, WaitingForMatch, WaitingForServer, Canceled and
     * Matched.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString Status;
    /** The Id of the ticket to find a match for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString TicketId;
};

/**
 * Returns the matchmaking statistics for a queue. These include the number of players matching and the statistics related
 * to the time to match statistics in seconds (average and percentiles). Statistics are refreshed once every 5 minutes.
 * Servers can access all statistics no matter what the ClientStatisticsVisibility is configured to. Clients can access
 * statistics according to the ClientStatisticsVisibility. Client requests are forbidden if all visibility fields are
 * false.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetQueueStatisticsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The name of the queue. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString QueueName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetQueueStatisticsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The current number of players in the matchmaking queue, who are waiting to be matched. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        int32 NumberOfPlayersMatching = 0;
    /** Statistics representing the time (in seconds) it takes for tickets to find a match. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* TimeToMatchStatisticsInSeconds = nullptr;
};

/**
 * The ticket includes the players, their attributes, their teams, the ticket status, the match Id and the server details
 * when applicable, etc. Only servers can get the ticket.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetServerBackfillTicketRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Determines whether the matchmaking attributes will be returned as an escaped JSON string or as an un-escaped JSON
     * object.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        bool EscapeObject = false;
    /** The name of the queue to find a match for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString QueueName;
    /** The Id of the ticket to find a match for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString TicketId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetServerBackfillTicketResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The reason why the current ticket was canceled. This field is only set if the ticket is in canceled state. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString CancellationReasonString;
    /** The server date and time at which ticket was created. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString Created;
    /** How long to attempt matching this ticket in seconds. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        int32 GiveUpAfterSeconds = 0;
    /** The Id of a match. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString MatchId;
    /** A list of Users that are part of this ticket, along with their team assignments. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        TArray<UPlayFabJsonObject*> Members;
    /** The Id of a match queue. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString QueueName;
    /** The details of the server the members are connected to. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* ServerDetails = nullptr;
    /** The current ticket status. Possible values are: WaitingForMatch, Canceled and Matched. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString Status;
    /** The Id of the ticket to find a match for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString TicketId;
};

/**
 * Add the player to a matchmaking ticket and specify all of its matchmaking attributes. Players can join a ticket if and
 * only if their EntityKeys are already listed in the ticket's Members list. The matchmaking service automatically starts
 * matching the ticket against other matchmaking tickets once all players have joined the ticket. It is not possible to
 * join a ticket once it has started matching.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerJoinMatchmakingTicketRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The User who wants to join the ticket. Their Id must be listed in PlayFabIdsToMatchWith. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* Member = nullptr;
    /** The name of the queue to join. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString QueueName;
    /** The Id of the ticket to find a match for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString TicketId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerJoinMatchmakingTicketResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * If the caller is a title, the EntityKey in the request is required. If the caller is a player, then it is optional. If
 * it is provided it must match the caller's entity.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListMatchmakingTicketsForPlayerRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity key for which to find the ticket Ids. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The name of the queue to find a match for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString QueueName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListMatchmakingTicketsForPlayerResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of ticket Ids the user is a member of. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString TicketIds;
};

/** List all server backfill ticket Ids the user is a member of. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListServerBackfillTicketsForPlayerRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity key for which to find the ticket Ids. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The name of the queue the tickets are in. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString QueueName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListServerBackfillTicketsForPlayerResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of backfill ticket Ids the user is a member of. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | Matchmaking Models")
        FString TicketIds;
};


///////////////////////////////////////////////////////
// Matchmaking Admin
//////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// MultiplayerServer
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerBuildAliasDetailsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string alias Id of the alias to be created or updated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString AliasId;
    /** The alias name. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString AliasName;
    /** Array of build selection criteria. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> BuildSelectionCriteria;
};

/** Creates a multiplayer server build alias and returns the created alias. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateBuildAliasRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The alias name. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString AliasName;
    /** Array of build selection criteria. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> BuildSelectionCriteria;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

/** Creates a multiplayer server build with a custom container and returns information about the build creation request. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateBuildWithCustomContainerRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * When true, assets will not be copied for each server inside the VM. All serverswill run from the same set of assets, or
     * will have the same assets mounted in the container.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        bool AreAssetsReadonly = false;
    /** The build name. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildName;
    /** The flavor of container to create a build from. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EContainerFlavor ContainerFlavor = StaticCast<EContainerFlavor>(0);
    /** The container reference, consisting of the image name and tag. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* ContainerImageReference = nullptr;
    /** The container command to run when the multiplayer server has been allocated, including any arguments. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ContainerRunCommand;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The list of game assets related to the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> GameAssetReferences;
    /** The game certificates for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> GameCertificateReferences;
    /** The Linux instrumentation configuration for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* LinuxInstrumentationConfiguration = nullptr;
    /**
     * Metadata to tag the build. The keys are case insensitive. The build metadata is made available to the server through
     * Game Server SDK (GSDK).Constraints: Maximum number of keys: 30, Maximum key length: 50, Maximum value length: 100
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* Metadata = nullptr;
    /** The configuration for the monitoring application on the build */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* MonitoringApplicationConfiguration = nullptr;
    /** The number of multiplayer servers to host on a single VM. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 MultiplayerServerCountPerVm = 0;
    /** The ports to map the build on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> Ports;
    /** The region configurations for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> RegionConfigurations;
    /** The resource constraints to apply to each server on the VM (EXPERIMENTAL API) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* ServerResourceConstraints = nullptr;
    /** The VM size to create the build on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EAzureVmSize VmSize = StaticCast<EAzureVmSize>(0);
    /** The configuration for the VmStartupScript for the build */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* VmStartupScriptConfiguration = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateBuildWithCustomContainerResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * When true, assets will not be copied for each server inside the VM. All serverswill run from the same set of assets, or
     * will have the same assets mounted in the container.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        bool AreAssetsReadonly = false;
    /** The guid string build ID. Must be unique for every build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The build name. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildName;
    /** The flavor of container of the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EContainerFlavor ContainerFlavor = StaticCast<EContainerFlavor>(0);
    /** The container command to run when the multiplayer server has been allocated, including any arguments. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ContainerRunCommand;
    /** The time the build was created in UTC. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString CreationTime;
    /** The custom game container image reference information. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomGameContainerImage = nullptr;
    /** The game assets for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> GameAssetReferences;
    /** The game certificates for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> GameCertificateReferences;
    /** The Linux instrumentation configuration for this build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* LinuxInstrumentationConfiguration = nullptr;
    /** The metadata of the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* Metadata = nullptr;
    /** The configuration for the monitoring application for the build */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* MonitoringApplicationConfiguration = nullptr;
    /** The number of multiplayer servers to host on a single VM of the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 MultiplayerServerCountPerVm = 0;
    /** The OS platform used for running the game process. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString OsPlatform;
    /** The ports the build is mapped on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> Ports;
    /** The region configuration for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> RegionConfigurations;
    /** The resource constraints to apply to each server on the VM (EXPERIMENTAL API) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* ServerResourceConstraints = nullptr;
    /** The type of game server being hosted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ServerType;
    /**
     * When true, assets will be downloaded and uncompressed in memory, without the compressedversion being written first to
     * disc.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        bool UseStreamingForAssetDownloads = false;
    /** The VM size the build was created on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EAzureVmSize VmSize = StaticCast<EAzureVmSize>(0);
    /** The configuration for the VmStartupScript feature for the build */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* VmStartupScriptConfiguration = nullptr;
};

/** Creates a multiplayer server build with a managed container and returns information about the build creation request. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateBuildWithManagedContainerRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * When true, assets will not be copied for each server inside the VM. All serverswill run from the same set of assets, or
     * will have the same assets mounted in the container.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        bool AreAssetsReadonly = false;
    /** The build name. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildName;
    /** The flavor of container to create a build from. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EContainerFlavor ContainerFlavor = StaticCast<EContainerFlavor>(0);
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The list of game assets related to the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> GameAssetReferences;
    /** The game certificates for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> GameCertificateReferences;
    /**
     * The directory containing the game executable. This would be the start path of the game assets that contain the main game
     * server executable. If not provided, a best effort will be made to extract it from the start game command.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString GameWorkingDirectory;
    /** The instrumentation configuration for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* InstrumentationConfiguration = nullptr;
    /**
     * Metadata to tag the build. The keys are case insensitive. The build metadata is made available to the server through
     * Game Server SDK (GSDK).Constraints: Maximum number of keys: 30, Maximum key length: 50, Maximum value length: 100
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* Metadata = nullptr;
    /** The configuration for the monitoring application on the build */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* MonitoringApplicationConfiguration = nullptr;
    /** The number of multiplayer servers to host on a single VM. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 MultiplayerServerCountPerVm = 0;
    /** The ports to map the build on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> Ports;
    /** The region configurations for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> RegionConfigurations;
    /** The resource constraints to apply to each server on the VM (EXPERIMENTAL API) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* ServerResourceConstraints = nullptr;
    /** The command to run when the multiplayer server is started, including any arguments. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString StartMultiplayerServerCommand;
    /** The VM size to create the build on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EAzureVmSize VmSize = StaticCast<EAzureVmSize>(0);
    /** The configuration for the VmStartupScript for the build */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* VmStartupScriptConfiguration = nullptr;
    /** The crash dump configuration for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* WindowsCrashDumpConfiguration = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateBuildWithManagedContainerResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * When true, assets will not be copied for each server inside the VM. All serverswill run from the same set of assets, or
     * will have the same assets mounted in the container.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        bool AreAssetsReadonly = false;
    /** The guid string build ID. Must be unique for every build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The build name. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildName;
    /** The flavor of container of the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EContainerFlavor ContainerFlavor = StaticCast<EContainerFlavor>(0);
    /** The time the build was created in UTC. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString CreationTime;
    /** The game assets for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> GameAssetReferences;
    /** The game certificates for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> GameCertificateReferences;
    /**
     * The directory containing the game executable. This would be the start path of the game assets that contain the main game
     * server executable. If not provided, a best effort will be made to extract it from the start game command.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString GameWorkingDirectory;
    /** The instrumentation configuration for this build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* InstrumentationConfiguration = nullptr;
    /** The metadata of the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* Metadata = nullptr;
    /** The configuration for the monitoring application for the build */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* MonitoringApplicationConfiguration = nullptr;
    /** The number of multiplayer servers to host on a single VM of the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 MultiplayerServerCountPerVm = 0;
    /** The OS platform used for running the game process. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString OsPlatform;
    /** The ports the build is mapped on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> Ports;
    /** The region configuration for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> RegionConfigurations;
    /** The resource constraints to apply to each server on the VM (EXPERIMENTAL API) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* ServerResourceConstraints = nullptr;
    /** The type of game server being hosted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ServerType;
    /** The command to run when the multiplayer server has been allocated, including any arguments. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString StartMultiplayerServerCommand;
    /**
     * When true, assets will be downloaded and uncompressed in memory, without the compressedversion being written first to
     * disc.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        bool UseStreamingForAssetDownloads = false;
    /** The VM size the build was created on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EAzureVmSize VmSize = StaticCast<EAzureVmSize>(0);
    /** The configuration for the VmStartupScript feature for the build */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* VmStartupScriptConfiguration = nullptr;
};

/**
 * Creates a multiplayer server build with the game server running as a process and returns information about the build
 * creation request.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateBuildWithProcessBasedServerRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * When true, assets will not be copied for each server inside the VM. All serverswill run from the same set of assets, or
     * will have the same assets mounted in the container.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        bool AreAssetsReadonly = false;
    /** The build name. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildName;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The list of game assets related to the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> GameAssetReferences;
    /** The game certificates for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> GameCertificateReferences;
    /**
     * The working directory for the game process. If this is not provided, the working directory will be set based on the
     * mount path of the game server executable.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString GameWorkingDirectory;
    /** The instrumentation configuration for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* InstrumentationConfiguration = nullptr;
    /**
     * Indicates whether this build will be created using the OS Preview versionPreview OS is recommended for dev builds to
     * detect any breaking changes before they are released to retail. Retail builds should set this value to false.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        bool IsOSPreview = false;
    /**
     * Metadata to tag the build. The keys are case insensitive. The build metadata is made available to the server through
     * Game Server SDK (GSDK).Constraints: Maximum number of keys: 30, Maximum key length: 50, Maximum value length: 100
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* Metadata = nullptr;
    /** The configuration for the monitoring application on the build */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* MonitoringApplicationConfiguration = nullptr;
    /** The number of multiplayer servers to host on a single VM. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 MultiplayerServerCountPerVm = 0;
    /** The OS platform used for running the game process. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString OsPlatform;
    /** The ports to map the build on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> Ports;
    /** The region configurations for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> RegionConfigurations;
    /**
     * The command to run when the multiplayer server is started, including any arguments. The path to any executable should be
     * relative to the root asset folder when unzipped.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString StartMultiplayerServerCommand;
    /** The VM size to create the build on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EAzureVmSize VmSize = StaticCast<EAzureVmSize>(0);
    /** The configuration for the VmStartupScript for the build */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* VmStartupScriptConfiguration = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateBuildWithProcessBasedServerResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * When true, assets will not be copied for each server inside the VM. All serverswill run from the same set of assets, or
     * will have the same assets mounted in the container.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        bool AreAssetsReadonly = false;
    /** The guid string build ID. Must be unique for every build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The build name. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildName;
    /** The flavor of container of the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EContainerFlavor ContainerFlavor = StaticCast<EContainerFlavor>(0);
    /** The time the build was created in UTC. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString CreationTime;
    /** The game assets for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> GameAssetReferences;
    /** The game certificates for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> GameCertificateReferences;
    /**
     * The working directory for the game process. If this is not provided, the working directory will be set based on the
     * mount path of the game server executable.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString GameWorkingDirectory;
    /** The instrumentation configuration for this build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* InstrumentationConfiguration = nullptr;
    /**
     * Indicates whether this build will be created using the OS Preview versionPreview OS is recommended for dev builds to
     * detect any breaking changes before they are released to retail. Retail builds should set this value to false.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        bool IsOSPreview = false;
    /** The metadata of the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* Metadata = nullptr;
    /** The configuration for the monitoring application for the build */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* MonitoringApplicationConfiguration = nullptr;
    /** The number of multiplayer servers to host on a single VM of the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 MultiplayerServerCountPerVm = 0;
    /** The OS platform used for running the game process. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString OsPlatform;
    /** The ports the build is mapped on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> Ports;
    /** The region configuration for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> RegionConfigurations;
    /** The type of game server being hosted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ServerType;
    /**
     * The command to run when the multiplayer server is started, including any arguments. The path to any executable is
     * relative to the root asset folder when unzipped.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString StartMultiplayerServerCommand;
    /**
     * When true, assets will be downloaded and uncompressed in memory, without the compressedversion being written first to
     * disc.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        bool UseStreamingForAssetDownloads = false;
    /** The VM size the build was created on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EAzureVmSize VmSize = StaticCast<EAzureVmSize>(0);
    /** The configuration for the VmStartupScript feature for the build */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* VmStartupScriptConfiguration = nullptr;
};

/**
 * Creates a remote user to log on to a VM for a multiplayer server build in a specific region. Returns user credential
 * information necessary to log on.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateRemoteUserRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string build ID of to create the remote user for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The expiration time for the remote user created. Defaults to expiring in one day if not specified. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ExpirationTime;
    /** The region of virtual machine to create the remote user for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Region;
    /** The username to create the remote user with. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Username;
    /** The virtual machine ID the multiplayer server is located on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString VmId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateRemoteUserResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The expiration time for the remote user created. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ExpirationTime;
    /** The generated password for the remote user that was created. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Password;
    /** The username for the remote user that was created. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Username;
};

/** Creates a request to change a title's multiplayer server quotas. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateTitleMultiplayerServersQuotaChangeRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** A brief description of the requested changes. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ChangeDescription;
    /** Changes to make to the titles cores quota. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> Changes;
    /** Email to be contacted by our team about this request. Only required when a request is not approved. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ContactEmail;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Additional information about this request that our team can use to better understand the requirements. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Notes;
    /** When these changes would need to be in effect. Only required when a request is not approved. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString StartDate;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateTitleMultiplayerServersQuotaChangeResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Id of the change request that was created. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString RequestId;
    /** Determines if the request was approved or not. When false, our team is reviewing and may respond within 2 business days. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        bool WasApproved = false;
};

/** Deletes a multiplayer server game asset for a title. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerDeleteAssetRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The filename of the asset to delete. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString FileName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerEmptyResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/** Deletes a multiplayer server build. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerDeleteBuildRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string build ID of the build to delete. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

/** Deletes a multiplayer server build alias. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerDeleteBuildAliasRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string alias ID of the alias to perform the action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString AliasId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

/** Removes a multiplayer server build's region. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerDeleteBuildRegionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string ID of the build we want to update regions for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The build region to delete. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Region;
};

/** Deletes a multiplayer server game certificate. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerDeleteCertificateRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The name of the certificate. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Name;
};

/**
 * Removes the specified container image repository. After this operation, a 'docker pull' will fail for all the tags of
 * the specified image. Morever, ListContainerImages will not return the specified image.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerDeleteContainerImageRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The container image repository we want to delete. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ImageName;
};

/**
 * Deletes a remote user to log on to a VM for a multiplayer server build in a specific region. Returns user credential
 * information necessary to log on.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerDeleteRemoteUserRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string build ID of the multiplayer server where the remote user is to delete. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The region of the multiplayer server where the remote user is to delete. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Region;
    /** The username of the remote user to delete. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Username;
    /** The virtual machine ID the multiplayer server is located on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString VmId;
};

/**
 * Enables the multiplayer server feature for a title and returns the enabled status. The enabled status can be
 * Initializing, Enabled, and Disabled. It can up to 20 minutes or more for the title to be enabled for the feature. On
 * average, it can take up to 20 minutes for the title to be enabled for the feature.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerEnableMultiplayerServersForTitleRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerEnableMultiplayerServersForTitleResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The enabled status for the multiplayer server features for the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        ETitleMultiplayerServerEnabledStatus Status = StaticCast<ETitleMultiplayerServerEnabledStatus>(0);
};

/** Gets a URL that can be used to download the specified asset. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetAssetDownloadUrlRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The asset's file name to get the download URL for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString FileName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetAssetDownloadUrlResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The asset's download URL. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString AssetDownloadUrl;
    /** The asset's file name to get the download URL for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString FileName;
};

/** Gets the URL to upload assets to. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetAssetUploadUrlRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The asset's file name to get the upload URL for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString FileName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetAssetUploadUrlResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The asset's upload URL. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString AssetUploadUrl;
    /** The asset's file name to get the upload URL for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString FileName;
};

/** Returns the details about a multiplayer server build. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetBuildRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string build ID of the build to get. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetBuildResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * When true, assets will not be copied for each server inside the VM. All serverswill run from the same set of assets, or
     * will have the same assets mounted in the container.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        bool AreAssetsReadonly = false;
    /** The guid string build ID of the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The build name. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildName;
    /** The current build status. Valid values are - Deploying, Deployed, DeletingRegion, Unhealthy. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildStatus;
    /** The flavor of container of he build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EContainerFlavor ContainerFlavor = StaticCast<EContainerFlavor>(0);
    /**
     * The container command to run when the multiplayer server has been allocated, including any arguments. This only applies
     * to custom builds. If the build is a managed build, this field will be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ContainerRunCommand;
    /** The time the build was created in UTC. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString CreationTime;
    /** The custom game container image for a custom build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomGameContainerImage = nullptr;
    /** The game assets for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> GameAssetReferences;
    /** The game certificates for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> GameCertificateReferences;
    /** The instrumentation configuration of the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* InstrumentationConfiguration = nullptr;
    /**
     * Metadata of the build. The keys are case insensitive. The build metadata is made available to the server through Game
     * Server SDK (GSDK).
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* Metadata = nullptr;
    /** The number of multiplayer servers to hosted on a single VM of the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 MultiplayerServerCountPerVm = 0;
    /** The OS platform used for running the game process. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString OsPlatform;
    /** The ports the build is mapped on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> Ports;
    /** The region configuration for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> RegionConfigurations;
    /** The resource constraints to apply to each server on the VM. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* ServerResourceConstraints = nullptr;
    /** The type of game server being hosted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ServerType;
    /**
     * The command to run when the multiplayer server has been allocated, including any arguments. This only applies to managed
     * builds. If the build is a custom build, this field will be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString StartMultiplayerServerCommand;
    /** The VM size the build was created on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EAzureVmSize VmSize = StaticCast<EAzureVmSize>(0);
    /** The configuration for the VmStartupScript feature for the build */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* VmStartupScriptConfiguration = nullptr;
};

/** Returns the details about a multiplayer server build alias. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetBuildAliasRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string alias ID of the alias to perform the action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString AliasId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

/**
 * Gets credentials to the container registry where game developers can upload custom container images to before creating a
 * new build.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetContainerRegistryCredentialsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetContainerRegistryCredentialsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The url of the container registry. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString DnsName;
    /** The password for accessing the container registry. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Password;
    /** The username for accessing the container registry. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Username;
};

/** Gets multiplayer server session details for a build in a specific region. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetMultiplayerServerDetailsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * The title generated guid string session ID of the multiplayer server to get details for. This is to keep track of
     * multiplayer server sessions.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SessionId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetMultiplayerServerDetailsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The identity of the build in which the server was allocated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The connected players in the multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> ConnectedPlayers;
    /** The fully qualified domain name of the virtual machine that is hosting this multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString FQDN;
    /** The public IPv4 address of the virtual machine that is hosting this multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString IPV4Address;
    /** The time (UTC) at which a change in the multiplayer server state was observed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString LastStateTransitionTime;
    /** The ports the multiplayer server uses. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> Ports;
    /** The list of public Ipv4 addresses associated with the server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> PublicIPV4Addresses;
    /** The region the multiplayer server is located in. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Region;
    /** The string server ID of the multiplayer server generated by PlayFab. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ServerId;
    /** The guid string session ID of the multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SessionId;
    /** The state of the multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString State;
    /** The virtual machine ID that the multiplayer server is located on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString VmId;
};

/**
 * Gets multiplayer server logs for a specific server id in a region. The logs are available only after a server has
 * terminated.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetMultiplayerServerLogsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The server ID of multiplayer server to get logs for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ServerId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetMultiplayerServerLogsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** URL for logs download. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString LogDownloadUrl;
};

/**
 * Gets multiplayer server logs for a specific server id in a region. The logs are available only after a server has
 * terminated.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetMultiplayerSessionLogsBySessionIdRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The server ID of multiplayer server to get logs for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SessionId;
};

/** Gets a remote login endpoint to a VM that is hosting a multiplayer server build in a specific region. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetRemoteLoginEndpointRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string build ID of the multiplayer server to get remote login information for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The region of the multiplayer server to get remote login information for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Region;
    /** The virtual machine ID the multiplayer server is located on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString VmId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetRemoteLoginEndpointResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The remote login IPV4 address of multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString IPV4Address;
    /** The remote login port of multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 Port = 0;
};

/**
 * Gets the status of whether a title is enabled for the multiplayer server feature. The enabled status can be
 * Initializing, Enabled, and Disabled.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetTitleEnabledForMultiplayerServersStatusRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetTitleEnabledForMultiplayerServersStatusResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The enabled status for the multiplayer server features for the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        ETitleMultiplayerServerEnabledStatus Status = StaticCast<ETitleMultiplayerServerEnabledStatus>(0);
};

/** Gets a title's server quota change request. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetTitleMultiplayerServersQuotaChangeRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Id of the change request to get. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString RequestId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetTitleMultiplayerServersQuotaChangeResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The change request for this title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* Change = nullptr;
};

/** Gets the quotas for a title in relation to multiplayer servers. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetTitleMultiplayerServersQuotasRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetTitleMultiplayerServersQuotasResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The various quotas for multiplayer servers for the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* Quotas = nullptr;
};

/** Returns a list of multiplayer servers for a build in a specific region. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListMultiplayerServersRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string build ID of the multiplayer servers to list. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The page size for the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The region the multiplayer servers to list. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Region;
    /** The skip token for the paged request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListMultiplayerServersResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of multiplayer server summary details. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> MultiplayerServerSummaries;
    /** The page size on the response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The skip token for the paged response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

/** Returns a list of multiplayer server game asset summaries for a title. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListAssetSummariesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The page size for the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The skip token for the paged request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListAssetSummariesResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of asset summaries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> AssetSummaries;
    /** The page size on the response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The skip token for the paged response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

/** Returns a list of summarized details of all multiplayer server builds for a title. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListBuildAliasesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The page size for the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The skip token for the paged request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListBuildAliasesResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of build aliases for the title */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> BuildAliases;
    /** The page size on the response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The skip token for the paged response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

/** Returns a list of summarized details of all multiplayer server builds for a title. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListBuildSummariesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The page size for the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The skip token for the paged request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListBuildSummariesResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of build summaries for a title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> BuildSummaries;
    /** The page size on the response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The skip token for the paged response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

/** Returns a list of multiplayer server game certificates for a title. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListCertificateSummariesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The page size for the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The skip token for the paged request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListCertificateSummariesResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of game certificates. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> CertificateSummaries;
    /** The page size on the response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The skip token for the paged response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

/** Returns a list of the container images that have been uploaded to the container registry for a title. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListContainerImagesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The page size for the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The skip token for the paged request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListContainerImagesResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of container images. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Images;
    /** The page size on the response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The skip token for the paged response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

/** Returns a list of the tags for a particular container image that exists in the container registry for a title. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListContainerImageTagsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The container images we want to list tags for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ImageName;
    /** The page size for the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The skip token for the paged request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListContainerImageTagsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The page size on the response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The skip token for the paged response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
    /** The list of tags for a particular container image. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Tags;
};

/** Returns a list of quality of service servers for party. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListPartyQosServersRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListPartyQosServersResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The page size on the response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The list of QoS servers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> QosServers;
    /** The skip token for the paged response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

/** Returns a list of quality of service servers for a title. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListQosServersForTitleRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Indicates that the response should contain Qos servers for all regions, including those where there are no builds
     * deployed for the title.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        bool IncludeAllRegions = false;
    /** Indicates the Routing Preference used by the Qos servers. The default Routing Preference is Microsoft */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString RoutingPreference;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListQosServersForTitleResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The page size on the response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The list of QoS servers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> QosServers;
    /** The skip token for the paged response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

/** List all server quota change requests for a title. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListTitleMultiplayerServersQuotaChangesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListTitleMultiplayerServersQuotaChangesResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** All change requests for this title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> Changes;
};

/** Returns a list of virtual machines for a title. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListVirtualMachineSummariesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string build ID of the virtual machines to list. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The page size for the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The region of the virtual machines to list. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Region;
    /** The skip token for the paged request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListVirtualMachineSummariesResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The page size on the response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The skip token for the paged response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
    /** The list of virtual machine summaries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> VirtualMachines;
};

/** Requests a multiplayer server session from a particular build in any of the given preferred regions. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerRequestMultiplayerServerRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The identifiers of the build alias to use for the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* BuildAliasParams = nullptr;
    /** The guid string build ID of the multiplayer server to request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Initial list of players (potentially matchmade) allowed to connect to the game. This list is passed to the game server
     * when requested (via GSDK) and can be used to validate players connecting to it.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString InitialPlayers;
    /**
     * The preferred regions to request a multiplayer server from. The Multiplayer Service will iterate through the regions in
     * the specified order and allocate a server from the first one that has servers available.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString PreferredRegions;
    /**
     * Data encoded as a string that is passed to the game server when requested. This can be used to to communicate
     * information such as game mode or map through the request flow.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SessionCookie;
    /** A guid string session ID created track the multiplayer server session over its life. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SessionId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerRequestMultiplayerServerResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The identity of the build in which the server was allocated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The connected players in the multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> ConnectedPlayers;
    /** The fully qualified domain name of the virtual machine that is hosting this multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString FQDN;
    /** The public IPv4 address of the virtual machine that is hosting this multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString IPV4Address;
    /** The time (UTC) at which a change in the multiplayer server state was observed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString LastStateTransitionTime;
    /** The ports the multiplayer server uses. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> Ports;
    /** The list of public Ipv4 addresses associated with the server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> PublicIPV4Addresses;
    /** The region the multiplayer server is located in. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Region;
    /** The string server ID of the multiplayer server generated by PlayFab. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ServerId;
    /** The guid string session ID of the multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SessionId;
    /** The state of the multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString State;
    /** The virtual machine ID that the multiplayer server is located on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString VmId;
};

/**
 * Requests a party session from a particular set of builds if build alias params is provided, in any of the given
 * preferred regions.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerRequestPartyServiceRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The network configuration for this request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* NetworkConfiguration = nullptr;
    /** A guid string party ID created track the party session over its life. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString PartyId;
    /**
     * The preferred regions to request a party session from. The party service will iterate through the regions in the
     * specified order and allocate a party session from the first one that is available.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString PreferredRegions;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerRequestPartyServiceResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * The invitation identifier supplied in the PartyInvitationConfiguration, or the PlayFab-generated guid if none was
     * supplied.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString InvitationId;
    /** The guid string party ID of the party session. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString PartyId;
    /** A base-64 encoded string containing the serialized network descriptor for this party. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SerializedNetworkDescriptor;
};

/**
 * Gets new credentials to the container registry where game developers can upload custom container images to before
 * creating a new build.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerRolloverContainerRegistryCredentialsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerRolloverContainerRegistryCredentialsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The url of the container registry. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString DnsName;
    /** The password for accessing the container registry. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Password;
    /** The username for accessing the container registry. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Username;
};

/**
 * Executes the shutdown callback from the GSDK and terminates the multiplayer server session. The callback in the GSDK
 * will allow for graceful shutdown with a 15 minute timeoutIf graceful shutdown has not been completed before 15 minutes
 * have elapsed, the multiplayer server session will be forcefully terminated on it's own.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerShutdownMultiplayerServerRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** A guid string session ID of the multiplayer server to shut down. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SessionId;
};

/**
 * Removes the specified tag from the image. After this operation, a 'docker pull' will fail for the specified image and
 * tag combination. Morever, ListContainerImageTags will not return the specified tag.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerUntagContainerImageRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The container image which tag we want to remove. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ImageName;
    /** The tag we want to remove. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Tag;
};

/** Creates a multiplayer server build alias and returns the created alias. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerUpdateBuildAliasRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string alias Id of the alias to be updated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString AliasId;
    /** The alias name. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString AliasName;
    /** Array of build selection criteria. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> BuildSelectionCriteria;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

/** Updates a multiplayer server build's name. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerUpdateBuildNameRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string ID of the build we want to update the name of. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The build name. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildName;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

/** Updates a multiplayer server build's region. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerUpdateBuildRegionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string ID of the build we want to update regions for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The updated region configuration that should be applied to the specified build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* BuildRegion = nullptr;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

/** Updates a multiplayer server build's regions. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerUpdateBuildRegionsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string ID of the build we want to update regions for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The updated region configuration that should be applied to the specified build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> BuildRegions;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

/** Uploads a multiplayer server game certificate. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerUploadCertificateRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Forces the certificate renewal if the certificate already exists. Default is false */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        bool ForceUpdate = false;
    /** The game certificate to upload. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* GameCertificate = nullptr;
};


///////////////////////////////////////////////////////
// TrueSkill
//////////////////////////////////////////////////////

