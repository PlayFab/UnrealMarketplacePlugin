//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Server
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabServerModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Server API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerBanUsersRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of ban requests to be applied. Maximum 100. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> Bans;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerBanUsersResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information on the bans that were applied */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> BanData;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerDeletePlayerRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerDeletePlayerResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayerProfileRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
    /**
     * If non-null, this determines which properties of the resulting player profiles to return. For API calls from the client,
     * only the allowed client profile properties for the title may be requested. These allowed properties are configured in
     * the Game Manager "Client Profile Options" tab in the "Settings" section.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* ProfileConstraints = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayerProfileResult
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * The profile of the player. This profile is not guaranteed to be up-to-date. For a new player, this profile will not
     * exist.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* PlayerProfile = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayFabIDsFromFacebookIDsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Facebook identifiers for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString FacebookIDs;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayFabIDsFromFacebookIDsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Facebook identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayFabIDsFromFacebookInstantGamesIdsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Facebook Instant Games identifiers for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString FacebookInstantGamesIds;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayFabIDsFromFacebookInstantGamesIdsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Facebook Instant Games identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Nintendo Switch Device identifiers for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString NintendoSwitchDeviceIds;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayFabIDsFromNintendoSwitchDeviceIdsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Nintendo Switch Device identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayFabIDsFromSteamIDsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Steam identifiers (Steam profile IDs) for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString SteamStringIDs;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayFabIDsFromSteamIDsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Steam identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetUserAccountInfoRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetUserAccountInfoResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Account details for the user whose information was requested. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* UserInfo = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetUserBansRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetUserBansResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information about the bans */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> BanData;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRevokeAllBansForUserRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRevokeAllBansForUserResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information on the bans that were revoked. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> BanData;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRevokeBansRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ids of the bans to be revoked. Maximum 100. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString BanIds;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRevokeBansResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information on the bans that were revoked */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> BanData;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSendCustomAccountRecoveryEmailRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** User email address attached to their account */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString Email;
    /** The email template id of the account recovery email template to send. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString EmailTemplateId;
    /** The user's username requesting an account recovery. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString Username;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSendCustomAccountRecoveryEmailResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSendEmailFromTemplateRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The email template id of the email template to send. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString EmailTemplateId;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSendEmailFromTemplateResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSendPushNotificationRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Allows you to provide precisely formatted json to target devices. This is an advanced feature, allowing you to deliver
     * to custom plugin logic, fields, or functionality not natively supported by PlayFab.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> AdvancedPlatformDelivery;
    /** Text of message to send. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString Message;
    /**
     * Defines all possible push attributes like message, title, icon, etc. Some parameters are device specific - please see
     * the PushNotificationPackage documentation for details.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* Package = nullptr;
    /** PlayFabId of the recipient of the push notification. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString Recipient;
    /** Subject of message to send (may not be displayed in all platforms) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString Subject;
    /** Target Platforms that should receive the Message or Package. If omitted, we will send to all available platforms. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString TargetPlatforms;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSendPushNotificationResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerEmptyResponse
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdateAvatarUrlRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** URL of the avatar image. If empty, it removes the existing avatar URL. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString ImageUrl;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdateBansRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of bans to be updated. Maximum 100. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> Bans;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdateBansResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information on the bans that were updated */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> BanData;
};


///////////////////////////////////////////////////////
// Analytics
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerWriteEventResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * The unique identifier of the event. The values of this identifier consist of ASCII characters and are not constrained to
     * any particular format.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString EventId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerWriteServerCharacterEventRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Custom event properties. Each property consists of a name (string) and a value (JSON object). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        UPlayFabJsonObject* Body = nullptr;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString CharacterId;
    /**
     * The name of the event, within the namespace scoped to the title. The naming convention is up to the caller, but it
     * commonly follows the subject_verb_object pattern (e.g. player_logged_in).
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString EventName;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString PlayFabId;
    /** The time (in UTC) associated with this event. The value dafaults to the current time. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString Timestamp;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerWriteServerPlayerEventRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Custom data properties associated with the event. Each property consists of a name (string) and a value (JSON object). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        UPlayFabJsonObject* Body = nullptr;
    /**
     * The name of the event, within the namespace scoped to the title. The naming convention is up to the caller, but it
     * commonly follows the subject_verb_object pattern (e.g. player_logged_in).
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString EventName;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString PlayFabId;
    /** The time (in UTC) associated with this event. The value dafaults to the current time. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString Timestamp;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerWriteTitleEventRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Custom event properties. Each property consists of a name (string) and a value (JSON object). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        UPlayFabJsonObject* Body = nullptr;
    /**
     * The name of the event, within the namespace scoped to the title. The naming convention is up to the caller, but it
     * commonly follows the subject_verb_object pattern (e.g. player_logged_in).
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString EventName;
    /** The time (in UTC) associated with this event. The value dafaults to the current time. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString Timestamp;
};


///////////////////////////////////////////////////////
// Authentication
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerAuthenticateSessionTicketRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Session ticket as issued by a PlayFab client login API. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        FString SessionTicket;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerAuthenticateSessionTicketResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Account info for the user whose session ticket was supplied. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        UPlayFabJsonObject* UserInfo = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSetPlayerSecretRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        FString PlayerSecret;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSetPlayerSecretResult
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Character Data
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetCharacterDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString CharacterId;
    /**
     * The version that currently exists according to the caller. The call will return the data for all of the keys if the
     * version in the system is greater than this.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        int32 IfChangedFromDataVersion = 0;
    /** Specific keys to search for in the custom user data. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString Keys;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetCharacterDataResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString CharacterId;
    /** User specific data for this title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        UPlayFabJsonObject* Data = nullptr;
    /**
     * Indicates the current version of the data that has been set. This is incremented with every set call for that type of
     * data (read-only, internal, etc). This version can be provided in Get calls to find updated data.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        int32 DataVersion = 0;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdateCharacterDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString CharacterId;
    /**
     * Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may
     * not begin with a '!' character or be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        UPlayFabJsonObject* Data;
    /**
     * Optional list of Data-keys to remove from UserData. Some SDKs cannot insert null-values into Data due to language
     * constraints. Use this to delete the keys directly.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString KeysToRemove;
    /** Permission to be applied to all user data keys written in this request. Defaults to "private" if not set. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        EUserDataPermission Permission;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdateCharacterDataResult
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Indicates the current version of the data that has been set. This is incremented with every set call for that type of
     * data (read-only, internal, etc). This version can be provided in Get calls to find updated data.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        int32 DataVersion = 0;
};


///////////////////////////////////////////////////////
// Characters
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerDeleteCharacterFromUserRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterId;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;
    /**
     * If true, the character's inventory will be transferred up to the owning user; otherwise, this request will purge those
     * items.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        bool SaveCharacterInventory = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerDeleteCharacterFromUserResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerListUsersCharactersRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerListUsersCharactersResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** The requested list of characters. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        TArray<UPlayFabJsonObject*> Characters;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetCharacterLeaderboardRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Optional character type on which to filter the leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterType;
    /** Maximum number of entries to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        int32 MaxResultsCount = 0;
    /** First entry in the leaderboard to be retrieved. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        int32 StartPosition = 0;
    /** Unique identifier for the title-specific statistic for the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString StatisticName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetCharacterLeaderboardResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ordered list of leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        TArray<UPlayFabJsonObject*> Leaderboard;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetCharacterStatisticsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterId;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetCharacterStatisticsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier of the character for the statistics. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterId;
    /** Character statistics for the requested user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        UPlayFabJsonObject* CharacterStatistics;
    /** PlayFab unique identifier of the user whose character statistics are being returned. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetLeaderboardAroundCharacterRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterId;
    /** Optional character type on which to filter the leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterType;
    /** Maximum number of entries to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        int32 MaxResultsCount = 0;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;
    /** Unique identifier for the title-specific statistic for the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString StatisticName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetLeaderboardAroundCharacterResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ordered list of leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        TArray<UPlayFabJsonObject*> Leaderboard;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetLeaderboardForUsersCharactersRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Maximum number of entries to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        int32 MaxResultsCount = 0;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;
    /** Unique identifier for the title-specific statistic for the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString StatisticName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetLeaderboardForUsersCharactersResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ordered list of leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        TArray<UPlayFabJsonObject*> Leaderboard;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGrantCharacterToUserRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Non-unique display name of the character being granted (1-20 characters in length). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterName;
    /** Type of the character being granted; statistics can be sliced based on this value. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterType;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGrantCharacterToUserResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier tagged to this character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdateCharacterStatisticsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterId;
    /** Statistics to be updated with the provided values. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        UPlayFabJsonObject* CharacterStatistics;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdateCharacterStatisticsResult
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetContentDownloadUrlRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** HTTP method to fetch item - GET or HEAD. Use HEAD when only fetching metadata. Default is GET. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Content Models")
        FString HttpMethod;
    /** Key of the content item to fetch, usually formatted as a path, e.g. images/a.png */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Content Models")
        FString Key;
    /**
     * True to download through CDN. CDN provides higher download bandwidth and lower latency. However, if you want the latest,
     * non-cached version of the content during development, set this to false. Default is true.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Content Models")
        bool ThruCDN = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetContentDownloadUrlResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** URL for downloading content via HTTP GET or HEAD method. The URL will expire in approximately one hour. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Content Models")
        FString URL;
};


///////////////////////////////////////////////////////
// Friend List Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerAddFriendRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Email address of the user being added. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        FString FriendEmail;
    /** The PlayFab identifier of the user being added. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        FString FriendPlayFabId;
    /** Title-specific display name of the user to being added. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        FString FriendTitleDisplayName;
    /** The PlayFab username of the user being added */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        FString FriendUsername;
    /** PlayFab identifier of the player to add a new friend. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetFriendsListRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Indicates whether Facebook friends should be included in the response. Default is true. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        bool IncludeFacebookFriends = false;
    /** Indicates whether Steam service friends should be included in the response. Default is true. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        bool IncludeSteamFriends = false;
    /** PlayFab identifier of the player whose friend list to get. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        FString PlayFabId;
    /**
     * If non-null, this determines which properties of the resulting player profiles to return. For API calls from the client,
     * only the allowed client profile properties for the title may be requested. These allowed properties are configured in
     * the Game Manager "Client Profile Options" tab in the "Settings" section.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        UPlayFabJsonObject* ProfileConstraints = nullptr;
    /** Xbox token if Xbox friends should be included. Requires Xbox be configured on PlayFab. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        FString XboxToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetFriendsListResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of friends found. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        TArray<UPlayFabJsonObject*> Friends;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRemoveFriendRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** PlayFab identifier of the friend account which is to be removed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        FString FriendPlayFabId;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSetFriendTagsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** PlayFab identifier of the friend account to which the tag(s) should be applied. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        FString FriendPlayFabId;
    /** PlayFab identifier of the player whose friend is to be updated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        FString PlayFabId;
    /** Array of tags to set on the friend account. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        FString Tags;
};


///////////////////////////////////////////////////////
// Matchmaking
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerDeregisterGameRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the Game Server Instance that is being deregistered. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString LobbyId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerDeregisterGameResponse
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerNotifyMatchmakerPlayerLeftRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier of the Game Instance the user is leaving. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString LobbyId;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerNotifyMatchmakerPlayerLeftResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** State of user leaving the Game Server Instance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        EPlayerConnectionState PlayerState;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRedeemMatchmakerTicketRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier of the Game Server Instance that is asking for validation of the authorization ticket. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString LobbyId;
    /** Server authorization ticket passed back from a call to Matchmake or StartGame. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString Ticket;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRedeemMatchmakerTicketResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Error value if the ticket was not validated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString Error;
    /** Boolean indicating whether the ticket was validated by the PlayFab service. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        bool TicketIsValid = false;
    /** User account information for the user validated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        UPlayFabJsonObject* UserInfo = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRefreshGameServerInstanceHeartbeatRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier of the Game Server Instance for which the heartbeat is updated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString LobbyId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRefreshGameServerInstanceHeartbeatResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRegisterGameRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier of the build running on the Game Server Instance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString Build;
    /**
     * Game Mode the Game Server instance is running. Note that this must be defined in the Game Modes tab in the PlayFab Game
     * Manager, along with the Build ID (the same Game Mode can be defined for multiple Build IDs).
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString GameMode;
    /** Previous lobby id if re-registering an existing game. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString LobbyId;
    /**
     * Region in which the Game Server Instance is running. For matchmaking using non-AWS region names, set this to any AWS
     * region and use Tags (below) to specify your custom region.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        ERegion Region;
    /** IPV4 address of the Game Server Instance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString ServerHost;
    /** IPV4 address of the game server instance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString ServerIPV4Address;
    /** IPV6 address (if any) of the game server instance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString ServerIPV6Address;
    /** Port number for communication with the Game Server Instance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString ServerPort;
    /** Public DNS name (if any) of the server */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString ServerPublicDNSName;
    /** Tags for the Game Server Instance */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        UPlayFabJsonObject* Tags;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRegisterGameResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Unique identifier generated for the Game Server Instance that is registered. If LobbyId is specified in request and the
     * game still exists in PlayFab, the LobbyId in request is returned. Otherwise a new lobby id will be returned.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString LobbyId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSetGameServerInstanceDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Custom data to set for the specified game server instance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString GameServerData;
    /** Unique identifier of the Game Instance to be updated, in decimal format. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString LobbyId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSetGameServerInstanceDataResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSetGameServerInstanceStateRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier of the Game Instance to be updated, in decimal format. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString LobbyId;
    /** State to set for the specified game server instance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        EGameInstanceState State;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSetGameServerInstanceStateResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSetGameServerInstanceTagsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier of the Game Server Instance to be updated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString LobbyId;
    /**
     * Tags to set for the specified Game Server Instance. Note that this is the complete list of tags to be associated with
     * the Game Server Instance.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        UPlayFabJsonObject* Tags;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSetGameServerInstanceTagsResult
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Platform Specific Methods
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerAwardSteamAchievementRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of achievements to grant and the users to whom they are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Platform Specific Methods Models")
        TArray<UPlayFabJsonObject*> Achievements;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerAwardSteamAchievementResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of achievements granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Platform Specific Methods Models")
        TArray<UPlayFabJsonObject*> AchievementResults;
};


///////////////////////////////////////////////////////
// Player Data Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerDeleteUsersRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** An array of unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabIds;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerDeleteUsersResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetFriendLeaderboardRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Indicates whether Facebook friends should be included in the response. Default is true. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        bool IncludeFacebookFriends = false;
    /** Indicates whether Steam service friends should be included in the response. Default is true. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        bool IncludeSteamFriends = false;
    /** Maximum number of entries to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 MaxResultsCount = 0;
    /** The player whose friend leaderboard to get */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;
    /**
     * If non-null, this determines which properties of the resulting player profiles to return. For API calls from the client,
     * only the allowed client profile properties for the title may be requested. These allowed properties are configured in
     * the Game Manager "Client Profile Options" tab in the "Settings" section.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* ProfileConstraints = nullptr;
    /** Position in the leaderboard to start this listing (defaults to the first entry). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 StartPosition = 0;
    /** Statistic used to rank friends for this leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString StatisticName;
    /** If set to false, Version is considered null. If true, uses the specified Version */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        bool UseSpecificVersion = false;
    /** The version of the leaderboard to get. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 Version = 0;
    /** Xbox token if Xbox friends should be included. Requires Xbox be configured on PlayFab. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString XboxToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetLeaderboardResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ordered listing of users and their positions in the requested leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        TArray<UPlayFabJsonObject*> Leaderboard;
    /** The time the next scheduled reset will occur. Null if the leaderboard does not reset on a schedule. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString NextReset;
    /** The version of the leaderboard returned. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 Version = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetLeaderboardRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Maximum number of entries to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 MaxResultsCount = 0;
    /**
     * If non-null, this determines which properties of the resulting player profiles to return. For API calls from the client,
     * only the allowed client profile properties for the title may be requested. These allowed properties are configured in
     * the Game Manager "Client Profile Options" tab in the "Settings" section.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* ProfileConstraints = nullptr;
    /** First entry in the leaderboard to be retrieved. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 StartPosition = 0;
    /** Unique identifier for the title-specific statistic for the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString StatisticName;
    /** If set to false, Version is considered null. If true, uses the specified Version */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        bool UseSpecificVersion = false;
    /** The version of the leaderboard to get. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 Version = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetLeaderboardAroundUserRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Maximum number of entries to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 MaxResultsCount = 0;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;
    /**
     * If non-null, this determines which properties of the resulting player profiles to return. For API calls from the client,
     * only the allowed client profile properties for the title may be requested. These allowed properties are configured in
     * the Game Manager "Client Profile Options" tab in the "Settings" section.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* ProfileConstraints = nullptr;
    /** Unique identifier for the title-specific statistic for the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString StatisticName;
    /** If set to false, Version is considered null. If true, uses the specified Version */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        bool UseSpecificVersion = false;
    /** The version of the leaderboard to get. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 Version = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetLeaderboardAroundUserResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ordered listing of users and their positions in the requested leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        TArray<UPlayFabJsonObject*> Leaderboard;
    /** The time the next scheduled reset will occur. Null if the leaderboard does not reset on a schedule. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString NextReset;
    /** The version of the leaderboard returned. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 Version = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayerCombinedInfoRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** PlayFabId of the user whose data will be returned */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayerCombinedInfoResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Results for requested info. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* InfoResultPayload = nullptr;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayerStatisticsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** user for whom statistics are being requested */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;
    /** statistics to return */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString StatisticNames;
    /**
     * statistics to return, if StatisticNames is not set (only statistics which have a version matching that provided will be
     * returned)
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        TArray<UPlayFabJsonObject*> StatisticNameVersions;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayerStatisticsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** PlayFab unique identifier of the user whose statistics are being returned */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;
    /** User statistics for the requested user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        TArray<UPlayFabJsonObject*> Statistics;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayerStatisticVersionsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** unique name of the statistic */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString StatisticName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayerStatisticVersionsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** version change history of the statistic */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        TArray<UPlayFabJsonObject*> StatisticVersions;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetUserDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * The version that currently exists according to the caller. The call will return the data for all of the keys if the
     * version in the system is greater than this.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 IfChangedFromDataVersion = 0;
    /** Specific keys to search for in the custom user data. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString Keys;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetUserDataResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** User specific data for this title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* Data = nullptr;
    /**
     * Indicates the current version of the data that has been set. This is incremented with every set call for that type of
     * data (read-only, internal, etc). This version can be provided in Get calls to find updated data.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 DataVersion = 0;
    /** PlayFab unique identifier of the user whose custom data is being returned. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdatePlayerStatisticsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Indicates whether the statistics provided should be set, regardless of the aggregation method set on the statistic.
     * Default is false.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        bool ForceUpdate = false;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;
    /** Statistics to be updated with the provided values */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        TArray<UPlayFabJsonObject*> Statistics;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdatePlayerStatisticsResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdateUserDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may
     * not begin with a '!' character or be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* Data;
    /**
     * Optional list of Data-keys to remove from UserData. Some SDKs cannot insert null-values into Data due to language
     * constraints. Use this to delete the keys directly.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString KeysToRemove;
    /** Permission to be applied to all user data keys written in this request. Defaults to "private" if not set. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        EUserDataPermission Permission;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdateUserDataResult
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Indicates the current version of the data that has been set. This is incremented with every set call for that type of
     * data (read-only, internal, etc). This version can be provided in Get calls to find updated data.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 DataVersion = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdateUserInternalDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may
     * not begin with a '!' character or be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* Data;
    /**
     * Optional list of Data-keys to remove from UserData. Some SDKs cannot insert null-values into Data due to language
     * constraints. Use this to delete the keys directly.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString KeysToRemove;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;
};


///////////////////////////////////////////////////////
// Player Item Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerAddCharacterVirtualCurrencyRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Amount to be added to the character balance of the specified virtual currency. Maximum VC balance is Int32
     * (2,147,483,647). Any increase over this value will be discarded.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 Amount = 0;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** PlayFab unique identifier of the user whose virtual currency balance is to be incremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Name of the virtual currency which is to be incremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString VirtualCurrency;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerModifyCharacterVirtualCurrencyResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Balance of the virtual currency after modification. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 Balance = 0;
    /** Name of the virtual currency which was modified. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString VirtualCurrency;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerAddUserVirtualCurrencyRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Amount to be added to the user balance of the specified virtual currency. Maximum VC balance is Int32 (2,147,483,647).
     * Any increase over this value will be discarded.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 Amount = 0;
    /** PlayFab unique identifier of the user whose virtual currency balance is to be increased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Name of the virtual currency which is to be incremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString VirtualCurrency;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerModifyUserVirtualCurrencyResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Balance of the virtual currency after modification. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 Balance = 0;
    /**
     * Amount added or subtracted from the user's virtual currency. Maximum VC balance is Int32 (2,147,483,647). Any increase
     * over this value will be discarded.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 BalanceChange = 0;
    /** User currency was subtracted from. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Name of the virtual currency which was modified. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString VirtualCurrency;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerConsumeItemRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** Number of uses to consume from the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 ConsumeCount = 0;
    /** Unique instance identifier of the item to be consumed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerConsumeItemResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique instance identifier of the item with uses consumed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;
    /** Number of uses remaining on the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 RemainingUses = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerEvaluateRandomResultTableRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Specifies the catalog version that should be used to evaluate the Random Result Table. If unspecified, uses
     * default/primary catalog.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;
    /** The unique identifier of the Random Result Table to use. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString TableId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerEvaluateRandomResultTableResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the item returned from the Random Result Table evaluation, for the given catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ResultItemId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetCharacterInventoryRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Used to limit results to only those from a specific catalog version. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetCharacterInventoryResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier of the character for this inventory. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** Array of inventory items belonging to the character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> Inventory;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Array of virtual currency balance(s) belonging to the character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrency;
    /** Array of remaining times and timestamps for virtual currencies. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrencyRechargeTimes = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetRandomResultTablesRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Specifies the catalog version that should be used to retrieve the Random Result Tables. If unspecified, uses
     * default/primary catalog.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;
    /** The unique identifier of the Random Result Table to use. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString TableIDs;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetRandomResultTablesResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** array of random result tables currently available */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* Tables = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetUserInventoryRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetUserInventoryResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of inventory items belonging to the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> Inventory;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Array of virtual currency balance(s) belonging to the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrency;
    /** Array of remaining times and timestamps for virtual currencies. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrencyRechargeTimes = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGrantItemsToCharacterRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** String detailing any additional information concerning this operation. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString Annotation;
    /** Catalog version from which items are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** Array of itemIds to grant to the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemIds;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGrantItemsToCharacterResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of items granted to users. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> ItemGrantResults;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGrantItemsToUserRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** String detailing any additional information concerning this operation. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString Annotation;
    /** Catalog version from which items are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;
    /** Array of itemIds to grant to the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemIds;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGrantItemsToUserResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of items granted to users. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> ItemGrantResults;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGrantItemsToUsersRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version from which items are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;
    /** Array of items to grant and the users to whom the items are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> ItemGrants;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGrantItemsToUsersResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of items granted to users. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> ItemGrantResults;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerModifyItemUsesRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique instance identifier of the item to be modified. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;
    /** PlayFab unique identifier of the user whose item is being modified. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Number of uses to add to the item. Can be negative to remove uses. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 UsesToAdd = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerModifyItemUsesResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique instance identifier of the item with uses consumed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;
    /** Number of uses remaining on the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 RemainingUses = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerMoveItemToCharacterFromCharacterRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier of the character that currently has the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString GivingCharacterId;
    /** Unique PlayFab assigned instance identifier of the item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Unique identifier of the character that will be receiving the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ReceivingCharacterId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerMoveItemToCharacterFromCharacterResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerMoveItemToCharacterFromUserRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** Unique PlayFab assigned instance identifier of the item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerMoveItemToCharacterFromUserResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerMoveItemToUserFromCharacterRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** Unique PlayFab assigned instance identifier of the item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerMoveItemToUserFromCharacterResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRedeemCouponRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version of the coupon. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;
    /** Optional identifier for the Character that should receive the item. If null, item is added to the player */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** Generated coupon code to redeem. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CouponCode;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRedeemCouponResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Items granted to the player as a result of redeeming the coupon. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> GrantedItems;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerReportPlayerServerRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Optional additional comment by reporting player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString Comment;
    /** Unique PlayFab identifier of the reported player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ReporteeId;
    /** PlayFabId of the reporting player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ReporterId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerReportPlayerServerResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** The number of remaining reports which may be filed today by this reporting player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 SubmissionsRemaining = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRevokeInventoryItemRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** Unique PlayFab assigned instance identifier of the item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRevokeInventoryResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRevokeInventoryItemsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of player items to revoke, between 1 and 25 items. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> Items;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRevokeInventoryItemsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Collection of any errors that occurred during processing. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> Errors;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSubtractCharacterVirtualCurrencyRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Amount to be subtracted from the user balance of the specified virtual currency. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 Amount = 0;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Name of the virtual currency which is to be decremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString VirtualCurrency;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSubtractUserVirtualCurrencyRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Amount to be subtracted from the user balance of the specified virtual currency. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 Amount = 0;
    /** PlayFab unique identifier of the user whose virtual currency balance is to be decreased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Name of the virtual currency which is to be decremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString VirtualCurrency;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUnlockContainerInstanceRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Specifies the catalog version that should be used to determine container contents. If unspecified, uses catalog
     * associated with the item instance.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** ItemInstanceId of the container to unlock. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ContainerItemInstanceId;
    /**
     * ItemInstanceId of the key that will be consumed by unlocking this container. If the container requires a key, this
     * parameter is required.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString KeyItemInstanceId;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUnlockContainerItemResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Items granted to the player as a result of unlocking the container. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> GrantedItems;
    /** Unique instance identifier of the container unlocked. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString UnlockedItemInstanceId;
    /** Unique instance identifier of the key used to unlock the container, if applicable. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString UnlockedWithItemInstanceId;
    /** Virtual currency granted to the player as a result of unlocking the container. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrency;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUnlockContainerItemRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Specifies the catalog version that should be used to determine container contents. If unspecified, uses default/primary
     * catalog.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** Catalog ItemId of the container type to unlock. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ContainerItemId;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdateUserInventoryItemDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /**
     * Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may
     * not begin with a '!' character or be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* Data;
    /** Unique PlayFab assigned instance identifier of the item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;
    /**
     * Optional list of Data-keys to remove from UserData. Some SDKs cannot insert null-values into Data due to language
     * constraints. Use this to delete the keys directly.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString KeysToRemove;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
};


///////////////////////////////////////////////////////
// PlayStream
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerAddPlayerTagRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString PlayFabId;
    /** Unique tag for player profile. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString TagName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerAddPlayerTagResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetAllSegmentsRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetAllSegmentsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of segments for this title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        TArray<UPlayFabJsonObject*> Segments;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayerSegmentsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of segments the requested player currently belongs to. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        TArray<UPlayFabJsonObject*> Segments;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayersSegmentsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayersInSegmentRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Continuation token if retrieving subsequent pages of results. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString ContinuationToken;
    /** Maximum number of profiles to load. Default is 1,000. Maximum is 10,000. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        int32 MaxBatchSize = 0;
    /**
     * Number of seconds to keep the continuation token active. After token expiration it is not possible to continue paging
     * results. Default is 300 (5 minutes). Maximum is 1,800 (30 minutes).
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        int32 SecondsToLive = 0;
    /** Unique identifier for this segment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString SegmentId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayersInSegmentResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Continuation token to use to retrieve subsequent pages of results. If token returns null there are no more results. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString ContinuationToken;
    /** Array of player profiles in this segment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        TArray<UPlayFabJsonObject*> PlayerProfiles;
    /** Count of profiles matching this segment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        int32 ProfilesInSegment = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayerTagsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Optional namespace to filter results by */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString Namespace;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayerTagsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString PlayFabId;
    /** Canonical tags (including namespace and tag's name) for the requested user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString Tags;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRemovePlayerTagRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString PlayFabId;
    /** Unique tag for player profile. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString TagName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRemovePlayerTagResult
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Server-Side Cloud Script
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerExecuteCloudScriptResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Number of PlayFab API requests issued by the CloudScript function */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        int32 APIRequestsIssued = 0;
    /** Information about the error, if any, that occurred during execution */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        UPlayFabJsonObject* Error = nullptr;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        int32 ExecutionTimeSeconds = 0;
    /** The name of the function that executed */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        FString FunctionName;
    /** The object returned from the CloudScript function, if any */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        UPlayFabJsonObject* FunctionResult = nullptr;
    /**
     * Flag indicating if the FunctionResult was too large and was subsequently dropped from this event. This only occurs if
     * the total event size is larger than 350KB.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        bool FunctionResultTooLarge = false;
    /** Number of external HTTP requests issued by the CloudScript function */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        int32 HttpRequestsIssued = 0;
    /**
     * Entries logged during the function execution. These include both entries logged in the function code using log.info()
     * and log.error() and error entries for API and HTTP request failures.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        TArray<UPlayFabJsonObject*> Logs;
    /**
     * Flag indicating if the logs were too large and were subsequently dropped from this event. This only occurs if the total
     * event size is larger than 350KB after the FunctionResult was removed.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        bool LogsTooLarge = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        int32 MemoryConsumedBytes = 0;
    /**
     * Processor time consumed while executing the function. This does not include time spent waiting on API calls or HTTP
     * requests.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        int32 ProcessorTimeSeconds = 0;
    /** The revision of the CloudScript that executed */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        int32 Revision = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerExecuteCloudScriptServerRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The name of the CloudScript function to execute */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        FString FunctionName;
    /** Object that is passed in to the function as the first argument */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        UPlayFabJsonObject* FunctionParameter = nullptr;
    /**
     * Generate a 'player_executed_cloudscript' PlayStream event containing the results of the function execution and other
     * contextual information. This event will show up in the PlayStream debugger console for the player in Game Manager.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        bool GeneratePlayStreamEvent = false;
    /** The unique user identifier for the player on whose behalf the script is being run */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        FString PlayFabId;
    /**
     * Option for which revision of the CloudScript to execute. 'Latest' executes the most recently created revision, 'Live'
     * executes the current live, published revision, and 'Specific' executes the specified revision. The default value is
     * 'Specific', if the SpeificRevision parameter is specified, otherwise it is 'Live'.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        ECloudScriptRevisionOption RevisionSelection;
    /** The specivic revision to execute, when RevisionSelection is set to 'Specific' */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        int32 SpecificRevision = 0;
};


///////////////////////////////////////////////////////
// Shared Group Data
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerAddSharedGroupMembersRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** An array of unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString PlayFabIds;
    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString SharedGroupId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerAddSharedGroupMembersResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerCreateSharedGroupRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the shared group (a random identifier will be assigned, if one is not specified). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString SharedGroupId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerCreateSharedGroupResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString SharedGroupId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerDeleteSharedGroupRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString SharedGroupId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetSharedGroupDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** If true, return the list of all members of the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        bool GetMembers = false;
    /**
     * Specific keys to retrieve from the shared group (if not specified, all keys will be returned, while an empty array
     * indicates that no keys should be returned).
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString Keys;
    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString SharedGroupId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetSharedGroupDataResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Data for the requested keys. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        UPlayFabJsonObject* Data = nullptr;
    /** List of PlayFabId identifiers for the members of this group, if requested. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString Members;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRemoveSharedGroupMembersRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** An array of unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString PlayFabIds;
    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString SharedGroupId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRemoveSharedGroupMembersResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdateSharedGroupDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may
     * not begin with a '!' character or be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        UPlayFabJsonObject* Data;
    /**
     * Optional list of Data-keys to remove from UserData. Some SDKs cannot insert null-values into Data due to language
     * constraints. Use this to delete the keys directly.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString KeysToRemove;
    /** Permission to be applied to all user data keys in this request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        EUserDataPermission Permission;
    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString SharedGroupId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdateSharedGroupDataResult
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Title-Wide Data Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetCatalogItemsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Which catalog is being requested. If null, uses the default catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString CatalogVersion;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetCatalogItemsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of items which can be purchased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> Catalog;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPublisherDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** array of keys to get back data from the Publisher data blob, set by the admin tools */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString Keys;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPublisherDataResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** a dictionary object of key / value pairs */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        UPlayFabJsonObject* Data;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetTimeRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetTimeResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Current server time when the request was received, in UTC */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString Time;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetTitleDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Specific keys to search for in the title data (leave null to get all keys) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString Keys;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetTitleDataResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** a dictionary object of key / value pairs */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        UPlayFabJsonObject* Data;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetTitleNewsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Limits the results to the last n entries. Defaults to 10 if not set. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        int32 Count = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetTitleNewsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of news items. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> News;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSetPublisherDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * key we want to set a value on (note, this is additive - will only replace an existing key's value if they are the same
     * name.) Keys are trimmed of whitespace. Keys may not begin with the '!' character.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString Key;
    /** new value to set. Set to null to remove a value */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString Value;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSetPublisherDataResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSetTitleDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * key we want to set a value on (note, this is additive - will only replace an existing key's value if they are the same
     * name.) Keys are trimmed of whitespace. Keys may not begin with the '!' character.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString Key;
    /** new value to set. Set to null to remove a value */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString Value;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSetTitleDataResult
{
    GENERATED_USTRUCT_BODY()
public:
};

