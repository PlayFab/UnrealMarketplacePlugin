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
#include "PlayFabRequestCommon.h"
#include "PlayFabLoginResultCommon.h"
#include "PlayFabServerModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Server API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerAddGenericIDRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Generic service identifier to add to the player account. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* GenericId = nullptr;
    /** PlayFabId of the user to link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerEmptyResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * The existence of each user will not be verified. When banning by IP or MAC address, multiple players may be affected, so
 * use this feature with caution. Returns information about the new bans.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerBanUsersRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of ban requests to be applied. Maximum 100. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> Bans;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerBanUsersResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information on the bans that were applied */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> BanData;
};

/**
 * Deletes all data associated with the player, including statistics, custom data, inventory, purchases, virtual currency
 * balances, characters and shared group memberships. Removes the player from all leaderboards and player search indexes.
 * Does not delete PlayStream event history associated with the player. Does not delete the publisher user account that
 * created the player in the title nor associated data such as username, password, email address, account linkages, or
 * friends list. Note, this API queues the player for deletion and returns immediately. It may take several minutes or more
 * before all player data is fully deleted. Until the player data is fully deleted, attempts to recreate the player with
 * the same user account in the same title will fail with the 'AccountDeleted' error. This API must be enabled for use as
 * an option in the game manager website. It is disabled by default.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerDeletePlayerRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerDeletePlayerResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/** Represents the request to delete a push notification template. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerDeletePushNotificationTemplateRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Id of the push notification template to be deleted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PushNotificationTemplateId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerDeletePushNotificationTemplateResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * This API allows for access to details regarding a user in the PlayFab service, usually for purposes of customer support.
 * Note that data returned may be Personally Identifying Information (PII), such as email address, and so care should be
 * taken in how this data is stored and managed. Since this call will always return the relevant information for users who
 * have accessed the title, the recommendation is to not store this data locally.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayerProfileRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
struct PLAYFAB_API FServerGetPlayerProfileResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FServerGetPlayFabIDsFromFacebookIDsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Facebook identifiers for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString FacebookIDs;
};

/** For Facebook identifiers which have not been linked to PlayFab accounts, null will be returned. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayFabIDsFromFacebookIDsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Facebook identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayFabIDsFromFacebookInstantGamesIdsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Facebook Instant Games identifiers for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString FacebookInstantGamesIds;
};

/** For Facebook Instant Games identifiers which have not been linked to PlayFab accounts, null will be returned. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayFabIDsFromFacebookInstantGamesIdsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Facebook Instant Games identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayFabIDsFromGenericIDsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Array of unique generic service identifiers for which the title needs to get PlayFab identifiers. Currently limited to a
     * maximum of 10 in a single request.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> GenericIDs;
};

/** For generic service identifiers which have not been linked to PlayFab accounts, null will be returned. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayFabIDsFromGenericIDsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of generic service identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Nintendo Switch Device identifiers for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString NintendoSwitchDeviceIds;
};

/** For Nintendo Switch Device identifiers which have not been linked to PlayFab accounts, null will be returned. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayFabIDsFromNintendoSwitchDeviceIdsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Nintendo Switch Device identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayFabIDsFromPSNAccountIDsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Id of the PSN issuer environment. If null, defaults to production environment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        int32 IssuerId = 0;
    /** Array of unique PlayStation Network identifiers for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PSNAccountIDs;
};

/** For PlayStation Network identifiers which have not been linked to PlayFab accounts, null will be returned. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayFabIDsFromPSNAccountIDsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of PlayStation Network identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayFabIDsFromSteamIDsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Steam identifiers (Steam profile IDs) for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString SteamStringIDs;
};

/** For Steam identifiers which have not been linked to PlayFab accounts, null will be returned. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayFabIDsFromSteamIDsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Steam identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayFabIDsFromXboxLiveIDsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The ID of Xbox Live sandbox. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString Sandbox;
    /** Array of unique Xbox Live account identifiers for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString XboxLiveAccountIDs;
};

/** For XboxLive identifiers which have not been linked to PlayFab accounts, null will be returned. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayFabIDsFromXboxLiveIDsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of PlayStation Network identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetServerCustomIDsFromPlayFabIDsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Array of unique PlayFab player identifiers for which the title needs to get server custom identifiers. Cannot contain
     * more than 25 identifiers.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabIDs;
};

/** For a PlayFab account that isn't associated with a server custom identity, ServerCustomId will be null. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetServerCustomIDsFromPlayFabIDsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of server custom player identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

/**
 * This API allows for access to details regarding a user in the PlayFab service, usually for purposes of customer support.
 * Note that data returned may be Personally Identifying Information (PII), such as email address, and so care should be
 * taken in how this data is stored and managed. Since this call will always return the relevant information for users who
 * have accessed the title, the recommendation is to not store this data locally.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetUserAccountInfoRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetUserAccountInfoResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Account details for the user whose information was requested. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* UserInfo = nullptr;
};

/** Get all bans for a user, including inactive and expired bans. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetUserBansRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetUserBansResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information about the bans */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> BanData;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerLinkPSNAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Authentication code provided by the PlayStation Network. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString AuthCode;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** If another user is already linked to the account, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        bool ForceLink = false;
    /** Id of the PSN issuer environment. If null, defaults to production environment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        int32 IssuerId = 0;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
    /** Redirect URI supplied to PSN when requesting an auth code */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString RedirectUri;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerLinkPSNAccountResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerLinkServerCustomIdRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** If another user is already linked to the custom ID, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        bool ForceLink = false;
    /** Unique PlayFab identifier. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
    /** Unique server custom identifier for this player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString ServerCustomId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerLinkServerCustomIdResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerLinkXboxAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** If another user is already linked to the account, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        bool ForceLink = false;
    /** Unique PlayFab identifier for a user, or null if no PlayFab account is linked to the Xbox Live identifier. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
    /** Token provided by the Xbox Live SDK/XDK method GetTokenAndSignatureAsync("POST", "https://playfabapi.com/", ""). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString XboxToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerLinkXboxAccountResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRemoveGenericIDRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Generic service identifier to be removed from the player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* GenericId = nullptr;
    /** PlayFabId of the user to remove. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
};

/**
 * Setting the active state of all non-expired bans for a user to Inactive. Expired bans with an Active state will be
 * ignored, however. Returns information about applied updates only.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRevokeAllBansForUserRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRevokeAllBansForUserResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information on the bans that were revoked. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> BanData;
};

/**
 * Setting the active state of all bans requested to Inactive regardless of whether that ban has already expired. BanIds
 * that do not exist will be skipped. Returns information about applied updates only.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRevokeBansRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ids of the bans to be revoked. Maximum 100. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString BanIds;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRevokeBansResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information on the bans that were revoked */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> BanData;
};

/** Represents the save push notification template request. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSavePushNotificationTemplateRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Android JSON for the notification template. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString AndroidPayload;
    /** Id of the push notification template. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString Id;
    /** IOS JSON for the notification template. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString IOSPayload;
    /** Dictionary of localized push notification templates with the language as the key. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* LocalizedPushNotificationTemplates = nullptr;
    /** Name of the push notification template. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString Name;
};

/** Represents the save push notification template result. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSavePushNotificationTemplateResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Id of the push notification template that was saved. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PushNotificationTemplateId;
};

/**
 * PlayFab accounts which have valid email address or username will be able to receive a password reset email using this
 * API.The email sent must be an account recovery email template. The username or email can be passed in to send the email
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSendCustomAccountRecoveryEmailRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
struct PLAYFAB_API FServerSendCustomAccountRecoveryEmailResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * Sends an email for only players that have contact emails associated with them. Takes in an email template ID
 * specifyingthe email template to send.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSendEmailFromTemplateRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The email template id of the email template to send. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString EmailTemplateId;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSendEmailFromTemplateResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSendPushNotificationRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Allows you to provide precisely formatted json to target devices. This is an advanced feature, allowing you to deliver
     * to custom plugin logic, fields, or functionality not natively supported by PlayFab.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> AdvancedPlatformDelivery;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
struct PLAYFAB_API FServerSendPushNotificationResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/** Represents the request for sending a push notification template to a recipient. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSendPushNotificationFromTemplateRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Id of the push notification template. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PushNotificationTemplateId;
    /** PlayFabId of the push notification recipient. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString Recipient;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUnlinkPSNAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUnlinkPSNAccountResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUnlinkServerCustomIdRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique PlayFab identifier. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
    /** Unique server custom identifier for this player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString ServerCustomId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUnlinkServerCustomIdResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUnlinkXboxAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique PlayFab identifier for a user, or null if no PlayFab account is linked to the Xbox Live identifier. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUnlinkXboxAccountResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerEmptyResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdateAvatarUrlRequest : public FPlayFabRequestCommon
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

/**
 * For each ban, only updates the values that are set. Leave any value to null for no change. If a ban could not be found,
 * the rest are still applied. Returns information about applied updates only.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdateBansRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of bans to be updated. Maximum 100. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> Bans;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdateBansResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FServerWriteEventResponse : public FPlayFabResultCommon
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

/**
 * This API is designed to write a multitude of different event types into PlayStream. It supports a flexible JSON schema,
 * which allowsfor arbitrary key-value pairs to describe any character-based event. The created event will be locked to the
 * authenticated title.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerWriteServerCharacterEventRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Custom event properties. Each property consists of a name (string) and a value (JSON object). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        UPlayFabJsonObject* Body = nullptr;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString CharacterId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * The name of the event, within the namespace scoped to the title. The naming convention is up to the caller, but it
     * commonly follows the subject_verb_object pattern (e.g. player_logged_in).
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString EventName;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString PlayFabId;
    /** The time (in UTC) associated with this event. The value defaults to the current time. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString Timestamp;
};

/**
 * This API is designed to write a multitude of different event types into PlayStream. It supports a flexible JSON schema,
 * which allowsfor arbitrary key-value pairs to describe any player-based event. The created event will be locked to the
 * authenticated title.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerWriteServerPlayerEventRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Custom data properties associated with the event. Each property consists of a name (string) and a value (JSON object). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        UPlayFabJsonObject* Body = nullptr;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * The name of the event, within the namespace scoped to the title. The naming convention is up to the caller, but it
     * commonly follows the subject_verb_object pattern (e.g. player_logged_in).
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString EventName;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString PlayFabId;
    /** The time (in UTC) associated with this event. The value defaults to the current time. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString Timestamp;
};

/**
 * This API is designed to write a multitude of different event types into PlayStream. It supports a flexible JSON schema,
 * which allowsfor arbitrary key-value pairs to describe any title-based event. The created event will be locked to the
 * authenticated title.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerWriteTitleEventRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Custom event properties. Each property consists of a name (string) and a value (JSON object). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        UPlayFabJsonObject* Body = nullptr;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * The name of the event, within the namespace scoped to the title. The naming convention is up to the caller, but it
     * commonly follows the subject_verb_object pattern (e.g. player_logged_in).
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString EventName;
    /** The time (in UTC) associated with this event. The value defaults to the current time. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString Timestamp;
};


///////////////////////////////////////////////////////
// Authentication
//////////////////////////////////////////////////////

/**
 * Note that data returned may be Personally Identifying Information (PII), such as email address, and so care should be
 * taken in how this data is stored and managed. Since this call will always return the relevant information for users who
 * have accessed the title, the recommendation is to not store this data locally.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerAuthenticateSessionTicketRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Session ticket as issued by a PlayFab client login API. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        FString SessionTicket;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerAuthenticateSessionTicketResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Indicates if token was expired at request time. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        bool IsSessionTicketExpired = false;
    /** Account info for the user whose session ticket was supplied. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        UPlayFabJsonObject* UserInfo = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerLoginWithServerCustomIdRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        bool CreateAccount = false;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        FString PlayerSecret;
    /** The backend server identifier for this player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        FString ServerCustomId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerServerLoginResult : public FPlayFabLoginResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * If LoginTitlePlayerAccountEntity flag is set on the login request the title_player_account will also be logged in and
     * returned.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        UPlayFabJsonObject* EntityToken = nullptr;
    /** Results for requested info. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        UPlayFabJsonObject* InfoResultPayload = nullptr;
    /** The time of this user's previous login. If there was no previous login, then it's DateTime.MinValue */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        FString LastLoginTime;
    /** True if the account was newly created on this login. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        bool NewlyCreated = false;
    /** Player's unique PlayFabId. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        FString PlayFabId;
    /** Unique token authorizing the user and game at the server level, for the current session. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        FString SessionTicket;
    /** Settings specific to this user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        UPlayFabJsonObject* SettingsForUser = nullptr;
    /** The experimentation treatments for this user at the time of login. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        UPlayFabJsonObject* TreatmentAssignment = nullptr;
};

/**
 * If this is the first time a user has signed in with the Steam ID and CreateAccount is set to true, a new PlayFab account
 * will be created and linked to the Steam account. In this case, no email or username will be associated with the PlayFab
 * account. Otherwise, if no PlayFab account is linked to the Steam account, an error indicating this will be returned, so
 * that the title can guide the user through creation of a PlayFab account. Steam users that are not logged into the Steam
 * Client app will only have their Steam username synced, other data, such as currency and country will not be available
 * until they login while the Client is open.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerLoginWithSteamIdRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        bool CreateAccount = false;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Unique Steam identifier for a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        FString SteamId;
};

/**
 * If this is the first time a user has signed in with the Xbox Live account and CreateAccount is set to true, a new
 * PlayFab account will be created and linked to the Xbox Live account. In this case, no email or username will be
 * associated with the PlayFab account. Otherwise, if no PlayFab account is linked to the Xbox Live account, an error
 * indicating this will be returned, so that the title can guide the user through creation of a PlayFab account.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerLoginWithXboxRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        bool CreateAccount = false;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Token provided by the Xbox Live SDK/XDK method GetTokenAndSignatureAsync("POST", "https://playfabapi.com/", ""). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        FString XboxToken;
};

/**
 * If this is the first time a user has signed in with the Xbox ID and CreateAccount is set to true, a new PlayFab account
 * will be created and linked to the Xbox Live account. In this case, no email or username will be associated with the
 * PlayFab account. Otherwise, if no PlayFab account is linked to the Xbox Live account, an error indicating this will be
 * returned, so that the title can guide the user through creation of a PlayFab account.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerLoginWithXboxIdRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        bool CreateAccount = false;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** The id of Xbox Live sandbox. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        FString Sandbox;
    /** Unique Xbox identifier for a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        FString XboxId;
};

/**
 * APIs that require signatures require that the player have a configured Player Secret Key that is used to sign all
 * requests. Players that don't have a secret will be blocked from making API calls until it is configured. To create a
 * signature header add a SHA256 hashed string containing UTF8 encoded JSON body as it will be sent to the server, the
 * current time in UTC formatted to ISO 8601, and the players secret formatted as 'body.date.secret'. Place the resulting
 * hash into the header X-PlayFab-Signature, along with a header X-PlayFab-Timestamp of the same UTC timestamp used in the
 * signature.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSetPlayerSecretRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FServerSetPlayerSecretResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Character Data
//////////////////////////////////////////////////////

/**
 * Data is stored as JSON key-value pairs. If the Keys parameter is provided, the data object returned will only contain
 * the data specific to the indicated Keys. Otherwise, the full set of custom user data will be returned.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetCharacterDataRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FServerGetCharacterDataResult : public FPlayFabResultCommon
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

/**
 * This function performs an additive update of the arbitrary JSON object containing the custom data for the user. In
 * updating the custom data object, keys which already exist in the object will have their values overwritten, while keys
 * with null values will be removed. No other key-value pairs will be changed apart from those specified in the call.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdateCharacterDataRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString CharacterId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may
     * not begin with a '!' character or be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        UPlayFabJsonObject* Data = nullptr;
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
struct PLAYFAB_API FServerUpdateCharacterDataResult : public FPlayFabResultCommon
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

/**
 * This function will delete the specified character from the list allowed by the user, and will also delete any inventory
 * or VC currently held by that character. It will NOT delete any statistics associated for this character, in order to
 * preserve leaderboard integrity.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerDeleteCharacterFromUserRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
struct PLAYFAB_API FServerDeleteCharacterFromUserResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/** Returns a list of every character that currently belongs to a user. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerListUsersCharactersRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerListUsersCharactersResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The requested list of characters. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        TArray<UPlayFabJsonObject*> Characters;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetCharacterLeaderboardRequest : public FPlayFabRequestCommon
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

/** Note that the Position of the character in the results is for the overall leaderboard. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetCharacterLeaderboardResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ordered list of leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        TArray<UPlayFabJsonObject*> Leaderboard;
};

/**
 * Character statistics are similar to user statistics in that they are numeric values which may only be updated by a
 * server operation, in order to minimize the opportunity for unauthorized changes. In addition to being available for use
 * by the title, the statistics are used for all leaderboard operations in PlayFab.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetCharacterStatisticsRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FServerGetCharacterStatisticsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier of the character for the statistics. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterId;
    /** Character statistics for the requested user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        UPlayFabJsonObject* CharacterStatistics = nullptr;
    /** PlayFab unique identifier of the user whose character statistics are being returned. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetLeaderboardAroundCharacterRequest : public FPlayFabRequestCommon
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

/**
 * Note: When calling 'GetLeaderboardAround...' APIs, the position of the character defaults to 0 when the character does
 * not have the corresponding statistic.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetLeaderboardAroundCharacterResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ordered list of leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        TArray<UPlayFabJsonObject*> Leaderboard;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetLeaderboardForUsersCharactersRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;
    /** Unique identifier for the title-specific statistic for the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString StatisticName;
};

/**
 * NOTE: The position of the character in the results is relative to the other characters for that specific user. This mean
 * the values will always be between 0 and one less than the number of characters returned regardless of the size of the
 * actual leaderboard.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetLeaderboardForUsersCharactersResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ordered list of leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        TArray<UPlayFabJsonObject*> Leaderboard;
};

/** Grants a character to the user of the type and name specified in the request. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGrantCharacterToUserRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Non-unique display name of the character being granted (1-40 characters in length). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterName;
    /** Type of the character being granted; statistics can be sliced based on this value. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterType;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGrantCharacterToUserResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier tagged to this character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterId;
};

/**
 * Character statistics are similar to user statistics in that they are numeric values which may only be updated by a
 * server operation, in order to minimize the opportunity for unauthorized changes. In addition to being available for use
 * by the title, the statistics are used for all leaderboard operations in PlayFab.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdateCharacterStatisticsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterId;
    /** Statistics to be updated with the provided values. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        UPlayFabJsonObject* CharacterStatistics = nullptr;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdateCharacterStatisticsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetContentDownloadUrlRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FServerGetContentDownloadUrlResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FServerAddFriendRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FServerGetFriendsListRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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

/**
 * If any additional services are queried for the user's friends, those friends who also have a PlayFab account registered
 * for the title will be returned in the results. For Facebook, user has to have logged into the title's Facebook app
 * recently, and only friends who also plays this game will be included. For Xbox Live, user has to have logged into the
 * Xbox Live recently, and only friends who also play this game will be included.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetFriendsListResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of friends found. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        TArray<UPlayFabJsonObject*> Friends;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRemoveFriendRequest : public FPlayFabRequestCommon
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

/**
 * This operation is not additive. It will completely replace the tag list for the specified user. Please note that only
 * users in the PlayFab friends list can be assigned tags. Attempting to set a tag on a friend only included in the friends
 * list from a social site integration (such as Facebook or Steam) will return the AccountNotFound error.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSetFriendTagsRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FServerDeregisterGameRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique identifier for the Game Server Instance that is being deregistered. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString LobbyId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerDeregisterGameResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerNotifyMatchmakerPlayerLeftRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique identifier of the Game Instance the user is leaving. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString LobbyId;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerNotifyMatchmakerPlayerLeftResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** State of user leaving the Game Server Instance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        EPlayerConnectionState PlayerState;
};

/**
 * This function is used by a Game Server Instance to validate with the PlayFab service that a user has been registered as
 * connected to the server. The Ticket is provided to the client either as a result of a call to StartGame or Matchmake,
 * each of which return a Ticket specific to the Game Server Instance. This function will fail in any case where the Ticket
 * presented is not valid for the specific Game Server Instance making the call. Note that data returned may be Personally
 * Identifying Information (PII), such as email address, and so care should be taken in how this data is stored and
 * managed. Since this call will always return the relevant information for users who have accessed the title, the
 * recommendation is to not store this data locally.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRedeemMatchmakerTicketRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique identifier of the Game Server Instance that is asking for validation of the authorization ticket. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString LobbyId;
    /** Server authorization ticket passed back from a call to Matchmake or StartGame. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString Ticket;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRedeemMatchmakerTicketResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FServerRefreshGameServerInstanceHeartbeatRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier of the Game Server Instance for which the heartbeat is updated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString LobbyId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRefreshGameServerInstanceHeartbeatResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRegisterGameRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier of the build running on the Game Server Instance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString Build;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
        UPlayFabJsonObject* Tags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRegisterGameResponse : public FPlayFabResultCommon
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
struct PLAYFAB_API FServerSetGameServerInstanceDataRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FServerSetGameServerInstanceDataResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSetGameServerInstanceStateRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FServerSetGameServerInstanceStateResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSetGameServerInstanceTagsRequest : public FPlayFabRequestCommon
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
        UPlayFabJsonObject* Tags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSetGameServerInstanceTagsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Platform Specific Methods
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerAwardSteamAchievementRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of achievements to grant and the users to whom they are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Platform Specific Methods Models")
        TArray<UPlayFabJsonObject*> Achievements;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerAwardSteamAchievementResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FServerGetFriendLeaderboardRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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

/** Note that the Position of the user in the results is for the overall leaderboard. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetLeaderboardResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FServerGetLeaderboardRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
struct PLAYFAB_API FServerGetLeaderboardAroundUserRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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

/**
 * Note: When calling 'GetLeaderboardAround...' APIs, the position of the user defaults to 0 when the user does not have
 * the corresponding statistic.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetLeaderboardAroundUserResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FServerGetPlayerCombinedInfoRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** PlayFabId of the user whose data will be returned */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayerCombinedInfoResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FServerGetPlayerStatisticsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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

/** In addition to being available for use by the title, the statistics are used for all leaderboard operations in PlayFab. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayerStatisticsResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FServerGetPlayerStatisticVersionsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** unique name of the statistic */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString StatisticName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayerStatisticVersionsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** version change history of the statistic */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        TArray<UPlayFabJsonObject*> StatisticVersions;
};

/**
 * Data is stored as JSON key-value pairs. If the Keys parameter is provided, the data object returned will only contain
 * the data specific to the indicated Keys. Otherwise, the full set of custom user data will be returned.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetUserDataRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FServerGetUserDataResult : public FPlayFabResultCommon
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

/**
 * This operation is additive. Statistics not currently defined will be added, while those already defined will be updated
 * with the given values. All other user statistics will remain unchanged.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdatePlayerStatisticsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
struct PLAYFAB_API FServerUpdatePlayerStatisticsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * This function performs an additive update of the arbitrary JSON object containing the custom data for the user. In
 * updating the custom data object, keys which already exist in the object will have their values overwritten, while keys
 * with null values will be removed. No other key-value pairs will be changed apart from those specified in the call.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdateUserDataRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may
     * not begin with a '!' character or be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* Data = nullptr;
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
struct PLAYFAB_API FServerUpdateUserDataResult : public FPlayFabResultCommon
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

/**
 * This function performs an additive update of the arbitrary JSON object containing the custom data for the user. In
 * updating the custom data object, keys which already exist in the object will have their values overwritten, keys with
 * null values will be removed. No other key-value pairs will be changed apart from those specified in the call.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdateUserInternalDataRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may
     * not begin with a '!' character or be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* Data = nullptr;
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
struct PLAYFAB_API FServerAddCharacterVirtualCurrencyRequest : public FPlayFabRequestCommon
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
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** PlayFab unique identifier of the user whose virtual currency balance is to be incremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Name of the virtual currency which is to be incremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString VirtualCurrency;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerModifyCharacterVirtualCurrencyResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FServerAddUserVirtualCurrencyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Amount to be added to the user balance of the specified virtual currency. Maximum VC balance is Int32 (2,147,483,647).
     * Any increase over this value will be discarded.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 Amount = 0;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** PlayFab unique identifier of the user whose virtual currency balance is to be increased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Name of the virtual currency which is to be incremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString VirtualCurrency;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerModifyUserVirtualCurrencyResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FServerConsumeItemRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** Number of uses to consume from the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 ConsumeCount = 0;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique instance identifier of the item to be consumed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerConsumeItemResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FServerEvaluateRandomResultTableRequest : public FPlayFabRequestCommon
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

/**
 * Note that if the Random Result Table contains no entries, or does not exist for the catalog specified (the Primary
 * catalog if one is not specified), an InvalidDropTable error will be returned.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerEvaluateRandomResultTableResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the item returned from the Random Result Table evaluation, for the given catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ResultItemId;
};

/**
 * All items currently in the character inventory will be returned, irrespective of how they were acquired (via purchasing,
 * grants, coupons, etc.). Items that are expired, fully consumed, or are no longer valid are not considered to be in the
 * user's current inventory, and so will not be not included. Also returns their virtual currency balances.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetCharacterInventoryRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Used to limit results to only those from a specific catalog version. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetCharacterInventoryResult : public FPlayFabResultCommon
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
        UPlayFabJsonObject* VirtualCurrency = nullptr;
    /** Array of remaining times and timestamps for virtual currencies. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrencyRechargeTimes = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetRandomResultTablesRequest : public FPlayFabRequestCommon
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

/**
 * Note that if a specified Random Result Table contains no entries, or does not exist in the catalog, an InvalidDropTable
 * error will be returned.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetRandomResultTablesResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** array of random result tables currently available */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* Tables = nullptr;
};

/**
 * All items currently in the user inventory will be returned, irrespective of how they were acquired (via purchasing,
 * grants, coupons, etc.). Items that are expired, fully consumed, or are no longer valid are not considered to be in the
 * user's current inventory, and so will not be not included.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetUserInventoryRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetUserInventoryResult : public FPlayFabResultCommon
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
        UPlayFabJsonObject* VirtualCurrency = nullptr;
    /** Array of remaining times and timestamps for virtual currencies. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrencyRechargeTimes = nullptr;
};

/**
 * This function directly adds inventory items to the character's inventories. As a result of this operations, the user
 * will not be charged any transaction fee, regardless of the inventory item catalog definition. Please note that the
 * processing time for inventory grants and purchases increases fractionally the more items are in the inventory, and the
 * more items are in the grant/purchase operation.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGrantItemsToCharacterRequest : public FPlayFabRequestCommon
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
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Array of itemIds to grant to the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemIds;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGrantItemsToCharacterResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of items granted to users. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> ItemGrantResults;
};

/**
 * This function directly adds inventory items to the user's inventories. As a result of this operations, the user will not
 * be charged any transaction fee, regardless of the inventory item catalog definition. Please note that the processing
 * time for inventory grants and purchases increases fractionally the more items are in the inventory, and the more items
 * are in the grant/purchase operation.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGrantItemsToUserRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** String detailing any additional information concerning this operation. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString Annotation;
    /** Catalog version from which items are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Array of itemIds to grant to the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemIds;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
};

/** Please note that the order of the items in the response may not match the order of items in the request. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGrantItemsToUserResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of items granted to users. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> ItemGrantResults;
};

/**
 * This function directly adds inventory items to user inventories. As a result of this operations, the user will not be
 * charged any transaction fee, regardless of the inventory item catalog definition. Please note that the processing time
 * for inventory grants and purchases increases fractionally the more items are in the inventory, and the more items are in
 * the grant/purchase operation.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGrantItemsToUsersRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version from which items are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Array of items to grant and the users to whom the items are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> ItemGrants;
};

/** Please note that the order of the items in the response may not match the order of items in the request. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGrantItemsToUsersResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of items granted to users. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> ItemGrantResults;
};

/**
 * This function can both add and remove uses of an inventory item. If the number of uses drops below zero, the item will
 * be removed from active inventory.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerModifyItemUsesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
struct PLAYFAB_API FServerModifyItemUsesResult : public FPlayFabResultCommon
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

/**
 * Transfers an item from a character to another character that is owned by the same user. This will remove the item from
 * the character's inventory (until and unless it is moved back), and will enable the other character to make use of the
 * item instead.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerMoveItemToCharacterFromCharacterRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FServerMoveItemToCharacterFromCharacterResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * Transfers an item from a user to a character she owns. This will remove the item from the user's inventory (until and
 * unless it is moved back), and will enable the character to make use of the item instead.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerMoveItemToCharacterFromUserRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FServerMoveItemToCharacterFromUserResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * Transfers an item from a character to the owning user. This will remove the item from the character's inventory (until
 * and unless it is moved back), and will enable the user to make use of the item instead.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerMoveItemToUserFromCharacterRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FServerMoveItemToUserFromCharacterResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * Coupon codes can be created for any item, or set of items, in the catalog for the title. This operation causes the
 * coupon to be consumed, and the specific items to be awarded to the user. Attempting to re-use an already consumed code,
 * or a code which has not yet been created in the service, will result in an error.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRedeemCouponRequest : public FPlayFabRequestCommon
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
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRedeemCouponResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Items granted to the player as a result of redeeming the coupon. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> GrantedItems;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerReportPlayerServerRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Optional additional comment by reporting player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString Comment;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique PlayFab identifier of the reported player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ReporteeId;
    /** PlayFabId of the reporting player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ReporterId;
};

/**
 * Players are currently limited to five reports per day. Attempts by a single user account to submit reports beyond five
 * will result in Updated being returned as false.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerReportPlayerServerResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The number of remaining reports which may be filed today by this reporting player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 SubmissionsRemaining = 0;
};

/**
 * In cases where the inventory item in question is a "crate", and the items it contained have already been dispensed, this
 * will not revoke access or otherwise remove the items which were dispensed.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRevokeInventoryItemRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FServerRevokeInventoryResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * In cases where the inventory item in question is a "crate", and the items it contained have already been dispensed, this
 * will not revoke access or otherwise remove the items which were dispensed.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRevokeInventoryItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of player items to revoke, between 1 and 25 items. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> Items;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRevokeInventoryItemsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Collection of any errors that occurred during processing. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> Errors;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSubtractCharacterVirtualCurrencyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Amount to be subtracted from the user balance of the specified virtual currency. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 Amount = 0;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Name of the virtual currency which is to be decremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString VirtualCurrency;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSubtractUserVirtualCurrencyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Amount to be subtracted from the user balance of the specified virtual currency. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 Amount = 0;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** PlayFab unique identifier of the user whose virtual currency balance is to be decreased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Name of the virtual currency which is to be decremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString VirtualCurrency;
};

/** Specify the container and optionally the catalogVersion for the container to open */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUnlockContainerInstanceRequest : public FPlayFabRequestCommon
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
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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

/** The items and vc found within the container. These will be added and stacked in your inventory as appropriate. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUnlockContainerItemResult : public FPlayFabResultCommon
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
        UPlayFabJsonObject* VirtualCurrency = nullptr;
};

/** Specify the type of container to open and optionally the catalogVersion for the container to open */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUnlockContainerItemRequest : public FPlayFabRequestCommon
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
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
};

/**
 * This function performs an additive update of the arbitrary JSON object containing the custom data for the item instance
 * which belongs to the specified user. In updating the custom data object, keys which already exist in the object will
 * have their values overwritten, while keys with null values will be removed. No other key-value pairs will be changed
 * apart from those specified in the call.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdateUserInventoryItemDataRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may
     * not begin with a '!' character or be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* Data = nullptr;
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

/**
 * This API will trigger a player_tag_added event and add a tag with the given TagName and PlayFabID to the corresponding
 * player profile. TagName can be used for segmentation and it is limited to 256 characters. Also there is a limit on the
 * number of tags a title can have.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerAddPlayerTagRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString PlayFabId;
    /** Unique tag for player profile. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString TagName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerAddPlayerTagResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/** Request has no paramaters. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetAllSegmentsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetAllSegmentsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of segments for this title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        TArray<UPlayFabJsonObject*> Segments;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayerSegmentsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of segments the requested player currently belongs to. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        TArray<UPlayFabJsonObject*> Segments;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayersSegmentsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString PlayFabId;
};

/**
 * Initial request must contain at least a Segment ID. Subsequent requests must contain the Segment ID as well as the
 * Continuation Token. Failure to send the Continuation Token will result in a new player segment list being generated.
 * Each time the Continuation Token is passed in the length of the Total Seconds to Live is refreshed. If too much time
 * passes between requests to the point that a subsequent request is past the Total Seconds to Live an error will be
 * returned and paging will be terminated. This API is resource intensive and should not be used in scenarios which might
 * generate high request volumes. Only one request to this API at a time should be made per title. Concurrent requests to
 * the API may be rejected with the APIConcurrentRequestLimitExceeded error.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayersInSegmentRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Continuation token if retrieving subsequent pages of results. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString ContinuationToken;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
struct PLAYFAB_API FServerGetPlayersInSegmentResult : public FPlayFabResultCommon
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

/**
 * This API will return a list of canonical tags which includes both namespace and tag's name. If namespace is not
 * provided, the result is a list of all canonical tags. TagName can be used for segmentation and Namespace is limited to
 * 128 characters.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayerTagsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Optional namespace to filter results by */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString Namespace;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPlayerTagsResult : public FPlayFabResultCommon
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

/**
 * This API will trigger a player_tag_removed event and remove a tag with the given TagName and PlayFabID from the
 * corresponding player profile. TagName can be used for segmentation and it is limited to 256 characters
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRemovePlayerTagRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString PlayFabId;
    /** Unique tag for player profile. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString TagName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerRemovePlayerTagResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Server-Side Cloud Script
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerExecuteCloudScriptResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FServerExecuteCloudScriptServerRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
struct PLAYFAB_API FServerAddSharedGroupMembersRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FServerAddSharedGroupMembersResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * If SharedGroupId is specified, the service will attempt to create a group with that identifier, and will return an error
 * if it is already in use. If no SharedGroupId is specified, a random identifier will be assigned.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerCreateSharedGroupRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the shared group (a random identifier will be assigned, if one is not specified). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString SharedGroupId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerCreateSharedGroupResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString SharedGroupId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerDeleteSharedGroupRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString SharedGroupId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetSharedGroupDataRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FServerGetSharedGroupDataResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FServerRemoveSharedGroupMembersRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FServerRemoveSharedGroupMembersResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * Note that in the case of multiple calls to write to the same shared group data keys, the last write received by the
 * PlayFab service will determine the value available to subsequent read operations. For scenarios requiring coordination
 * of data updates, it is recommended that titles make use of user data with read permission set to public, or a
 * combination of user data and shared group data.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerUpdateSharedGroupDataRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may
     * not begin with a '!' character or be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        UPlayFabJsonObject* Data = nullptr;
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
struct PLAYFAB_API FServerUpdateSharedGroupDataResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Title-Wide Data Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetCatalogItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Which catalog is being requested. If null, uses the default catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString CatalogVersion;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetCatalogItemsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of items which can be purchased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> Catalog;
};

/**
 * This API is designed to return publisher-specific values which can be read, but not written to, by the client. This data
 * is shared across all titles assigned to a particular publisher, and can be used for cross-game coordination. Only titles
 * assigned to a publisher can use this API. For more information email helloplayfab@microsoft.com. Note that there may up
 * to a minute delay in between updating title data and this API call returning the newest value.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPublisherDataRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** array of keys to get back data from the Publisher data blob, set by the admin tools */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString Keys;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetPublisherDataResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** a dictionary object of key / value pairs */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        UPlayFabJsonObject* Data = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetStoreItemsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The base catalog that this store is a part of. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString CatalogVersion;
    /** Additional data about the store. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        UPlayFabJsonObject* MarketingData = nullptr;
    /** How the store was last updated (Admin or a third party). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        EPfSourceType Source;
    /** Array of items which can be purchased from this store. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> Store;
    /** The ID of this store. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString StoreId;
};

/**
 * A store contains an array of references to items defined in one or more catalog versions of the game, along with the
 * prices for the item, in both real world and virtual currencies. These prices act as an override to any prices defined in
 * the catalog. In this way, the base definitions of the items may be defined in the catalog, with all associated
 * properties, while the pricing can be set for each store, as needed. This allows for subsets of goods to be defined for
 * different purposes (in order to simplify showing some, but not all catalog items to users, based upon different
 * characteristics), along with unique prices. Note that all prices defined in the catalog and store definitions for the
 * item are considered valid, and that a compromised client can be made to send a request for an item based upon any of
 * these definitions. If no price is specified in the store for an item, the price set in the catalog should be displayed
 * to the user.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetStoreItemsServerRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version to store items from. Use default catalog version if null */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString CatalogVersion;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Optional identifier for the player to use in requesting the store information - if used, segment overrides will be
     * applied
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString PlayFabId;
    /** Unqiue identifier for the store which is being requested */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString StoreId;
};

/**
 * This query retrieves the current time from one of the servers in PlayFab. Please note that due to clock drift between
 * servers, there is a potential variance of up to 5 seconds.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetTimeRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/** Time is always returned as Coordinated Universal Time (UTC). */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetTimeResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Current server time when the request was received, in UTC */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString Time;
};

/**
 * This API is designed to return title specific values which can be read, but not written to, by the client. For example,
 * a developer could choose to store values which modify the user experience, such as enemy spawn rates, weapon strengths,
 * movement speeds, etc. This allows a developer to update the title without the need to create, test, and ship a new
 * build. If an override label is specified in the request, the overrides are applied automatically and returned with the
 * title data. Note that there may up to a minute delay in between updating title data and this API call returning the
 * newest value.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetTitleDataRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Specific keys to search for in the title data (leave null to get all keys) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString Keys;
    /**
     * Optional field that specifies the name of an override. This value is ignored when used by the game client; otherwise,
     * the overrides are applied automatically to the title data.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString OverrideLabel;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetTitleDataResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** a dictionary object of key / value pairs */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        UPlayFabJsonObject* Data = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetTitleNewsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Limits the results to the last n entries. Defaults to 10 if not set. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        int32 Count = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FServerGetTitleNewsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of localized news items. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> News;
};

/**
 * This API is designed to store publisher-specific values which can be read, but not written to, by the client. This data
 * is shared across all titles assigned to a particular publisher, and can be used for cross-game coordination. Only titles
 * assigned to a publisher can use this API. This operation is additive. If a Key does not exist in the current dataset, it
 * will be added with the specified Value. If it already exists, the Value for that key will be overwritten with the new
 * Value. For more information email helloplayfab@microsoft.com
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSetPublisherDataRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FServerSetPublisherDataResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * This API is designed to store title specific values which can be read, but not written to, by the client. For example, a
 * developer could choose to store values which modify the user experience, such as enemy spawn rates, weapon strengths,
 * movement speeds, etc. This allows a developer to update the title without the need to create, test, and ship a new
 * build. This operation is additive. If a Key does not exist in the current dataset, it will be added with the specified
 * Value. If it already exists, the Value for that key will be overwritten with the new Value.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FServerSetTitleDataRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FServerSetTitleDataResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

