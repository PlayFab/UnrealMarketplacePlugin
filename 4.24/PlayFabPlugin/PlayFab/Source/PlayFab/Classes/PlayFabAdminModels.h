//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Admin
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabRequestCommon.h"
#include "PlayFabLoginResultCommon.h"
#include "PlayFabAdminModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Admin API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////

/**
 * The existence of each user will not be verified. When banning by IP or MAC address, multiple players may be affected, so
 * use this feature with caution. Returns information about the new bans.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminBanUsersRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of ban requests to be applied. Maximum 100. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        TArray<UPlayFabJsonObject*> Bans;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminBanUsersResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information on the bans that were applied */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        TArray<UPlayFabJsonObject*> BanData;
};

/**
 * Deletes all data associated with the master player account, including data from all titles the player has played, such
 * as statistics, custom data, inventory, purchases, virtual currency balances, characters, group memberships, publisher
 * data, credential data, account linkages, friends list and PlayStream event history. Removes the player from all
 * leaderboards and player search indexes. Note, this API queues the player for deletion and returns a receipt immediately.
 * Record the receipt ID for future reference. It may take some time before all player data is fully deleted. Upon
 * completion of the deletion, an email will be sent to the notification email address configured for the title confirming
 * the deletion. Until the player data is fully deleted, attempts to recreate the player with the same user account in the
 * same title will fail with the 'AccountDeleted' error. It is highly recommended to know the impact of the deletion by
 * calling GetPlayedTitleList, before calling this API.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminDeleteMasterPlayerAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Developer created string to identify a user without PlayFab ID */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString MetaData;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminDeleteMasterPlayerAccountResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * A notification email with this job receipt Id will be sent to the title notification email address when deletion is
     * complete.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString JobReceiptId;
    /** List of titles from which the player's data will be deleted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString TitleIds;
};

/**
 * Deletes all data associated with the player, including statistics, custom data, inventory, purchases, virtual currency
 * balances, characters and shared group memberships. Removes the player from all leaderboards and player search indexes.
 * Does not delete PlayStream event history associated with the player. Does not delete the publisher user account that
 * created the player in the title nor associated data such as username, password, email address, account linkages, or
 * friends list. Note, this API queues the player for deletion and returns immediately. It may take several minutes or more
 * before all player data is fully deleted. Until the player data is fully deleted, attempts to recreate the player with
 * the same user account in the same title will fail with the 'AccountDeleted' error.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminDeletePlayerRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminDeletePlayerResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * Deletes all data associated with the title, including catalog, virtual currencies, leaderboard statistics, Cloud Script
 * revisions, segment definitions, event rules, tasks, add-ons, secret keys, data encryption keys, and permission policies.
 * Removes the title from its studio and removes all associated developer roles and permissions. Does not delete PlayStream
 * event history associated with the title. Note, this API queues the title for deletion and returns immediately. It may
 * take several hours or more before all title data is fully deleted. All player accounts in the title must be deleted
 * before deleting the title. If any player accounts exist, the API will return a 'TitleContainsUserAccounts' error. Until
 * the title data is fully deleted, attempts to call APIs with the title will fail with the 'TitleDeleted' error.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminDeleteTitleRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminDeleteTitleResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * Exports all data associated with the master player account, including data from all titles the player has played, such
 * as statistics, custom data, inventory, purchases, virtual currency balances, characters, group memberships, publisher
 * data, credential data, account linkages, friends list and PlayStream event history. Note, this API queues the player for
 * export and returns a receipt immediately. Record the receipt ID for future reference. It may take some time before the
 * export is available for download. Upon completion of the export, an email containing the URL to download the export dump
 * will be sent to the notification email address configured for the title.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminExportMasterPlayerDataRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminExportMasterPlayerDataResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * An email with this job receipt Id containing the export download link will be sent to the title notification email
     * address when the export is complete.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString JobReceiptId;
};

/** Useful for identifying titles of which the player's data will be deleted by DeleteMasterPlayer. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetPlayedTitleListRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetPlayedTitleListResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of titles the player has played */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString TitleIds;
};

/**
 * Gets a player ID from an auth token. The token expires after 30 minutes and cannot be used to look up a player when
 * expired.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetPlayerIdFromAuthTokenRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The auth token of the player requesting the password reset. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString Token;
    /** The type of auth token of the player requesting the password reset. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        EAuthTokenType TokenType;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetPlayerIdFromAuthTokenResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The player ID from the token passed in */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString PlayFabId;
};

/**
 * This API allows for access to details regarding a user in the PlayFab service, usually for purposes of customer support.
 * Note that data returned may be Personally Identifying Information (PII), such as email address, and so care should be
 * taken in how this data is stored and managed. Since this call will always return the relevant information for users who
 * have accessed the title, the recommendation is to not store this data locally.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetPlayerProfileRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString PlayFabId;
    /**
     * If non-null, this determines which properties of the resulting player profiles to return. For API calls from the client,
     * only the allowed client profile properties for the title may be requested. These allowed properties are configured in
     * the Game Manager "Client Profile Options" tab in the "Settings" section.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        UPlayFabJsonObject* ProfileConstraints = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetPlayerProfileResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * The profile of the player. This profile is not guaranteed to be up-to-date. For a new player, this profile will not
     * exist.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        UPlayFabJsonObject* PlayerProfile = nullptr;
};

/**
 * This API allows for access to details regarding a user in the PlayFab service, usually for purposes of customer support.
 * Note that data returned may be Personally Identifying Information (PII), such as email address, and so care should be
 * taken in how this data is stored and managed. Since this call will always return the relevant information for users who
 * have accessed the title, the recommendation is to not store this data locally.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminLookupUserAccountInfoRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** User email address attached to their account */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString Email;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString PlayFabId;
    /** Title specific username to match against existing user accounts */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString TitleDisplayName;
    /** PlayFab username for the account (3-20 characters) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString Username;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminLookupUserAccountInfoResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** User info for the user matching the request */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        UPlayFabJsonObject* UserInfo = nullptr;
};

/** Get all bans for a user, including inactive and expired bans. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetUserBansRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetUserBansResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information about the bans */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        TArray<UPlayFabJsonObject*> BanData;
};

/**
 * Resets a player's password taking in a new password based and validating the user based off of a token sent to the
 * playerto their email. The token expires after 30 minutes.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminResetPasswordRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The new password for the player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString Password;
    /** The token of the player requesting the password reset. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString Token;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminResetPasswordResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * Setting the active state of all non-expired bans for a user to Inactive. Expired bans with an Active state will be
 * ignored, however. Returns information about applied updates only.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminRevokeAllBansForUserRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminRevokeAllBansForUserResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information on the bans that were revoked. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        TArray<UPlayFabJsonObject*> BanData;
};

/**
 * Setting the active state of all bans requested to Inactive regardless of whether that ban has already expired. BanIds
 * that do not exist will be skipped. Returns information about applied updates only.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminRevokeBansRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ids of the bans to be revoked. Maximum 100. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString BanIds;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminRevokeBansResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information on the bans that were revoked */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        TArray<UPlayFabJsonObject*> BanData;
};

/**
 * If the account in question is a "temporary" account (for example, one that was created via a call to
 * LoginFromIOSDeviceID), thisfunction will have no effect. Only PlayFab accounts which have valid email addresses will be
 * able to receive a password reset email using this API.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminSendAccountRecoveryEmailRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** User email address attached to their account */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString Email;
    /** The email template id of the account recovery email template to send. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString EmailTemplateId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminSendAccountRecoveryEmailResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * For each ban, only updates the values that are set. Leave any value to null for no change. If a ban could not be found,
 * the rest are still applied. Returns information about applied updates only.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdateBansRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of bans to be updated. Maximum 100. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        TArray<UPlayFabJsonObject*> Bans;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdateBansResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information on the bans that were updated */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        TArray<UPlayFabJsonObject*> BanData;
};

/**
 * In addition to the PlayFab username, titles can make use of a DisplayName which is also a unique identifier, but
 * specific to the title. This allows for unique names which more closely match the theme or genre of a title, for example.
 * This API enables changing that name, whether due to a customer request, an offensive name choice, etc.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdateUserTitleDisplayNameRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** New title display name for the user - must be between 3 and 25 characters */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString DisplayName;
    /** PlayFab unique identifier of the user whose title specific display name is to be changed */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdateUserTitleDisplayNameResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** current title display name for the user (this will be the original display name if the rename attempt failed) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString DisplayName;
};


///////////////////////////////////////////////////////
// Authentication
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminCreateOpenIdConnectionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The client ID given by the ID provider. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString ClientId;
    /** The client secret given by the ID provider. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString ClientSecret;
    /** A name for the connection that identifies it within the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString ConnectionId;
    /** Ignore 'nonce' claim in identity tokens. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        bool IgnoreNonce = false;
    /**
     * The discovery document URL to read issuer information from. This must be the absolute URL to the JSON OpenId
     * Configuration document and must be accessible from the internet. If you don't know it, try your issuer URL followed by
     * "/.well-known/openid-configuration". For example, if the issuer is https://example.com, try
     * https://example.com/.well-known/openid-configuration
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString IssuerDiscoveryUrl;
    /** Manually specified information for an OpenID Connect issuer. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        UPlayFabJsonObject* IssuerInformation = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminEmptyResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * Player Shared Secret Keys are used for the call to Client/GetTitlePublicKey, which exchanges the shared secret for an
 * RSA CSP blob to be used to encrypt the payload of account creation requests when that API requires a signature header.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminCreatePlayerSharedSecretRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Friendly name for this key */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString FriendlyName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminCreatePlayerSharedSecretResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The player shared secret to use when calling Client/GetTitlePublicKey */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString SecretKey;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminDeleteOpenIdConnectionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** unique name of the connection */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString ConnectionId;
};

/**
 * Player Shared Secret Keys are used for the call to Client/GetTitlePublicKey, which exchanges the shared secret for an
 * RSA CSP blob to be used to encrypt the payload of account creation requests when that API requires a signature header.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminDeletePlayerSharedSecretRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The shared secret key to delete */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString SecretKey;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminDeletePlayerSharedSecretResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * Player Shared Secret Keys are used for the call to Client/GetTitlePublicKey, which exchanges the shared secret for an
 * RSA CSP blob to be used to encrypt the payload of account creation requests when that API requires a signature header.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetPlayerSharedSecretsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetPlayerSharedSecretsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The player shared secret to use when calling Client/GetTitlePublicKey */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        TArray<UPlayFabJsonObject*> SharedSecrets;
};

/** Views the requested policy. Today, the only supported policy is 'ApiPolicy'. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetPolicyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The name of the policy to read. Only supported name is 'ApiPolicy'. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString PolicyName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetPolicyResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The name of the policy read. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString PolicyName;
    /** Policy version. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        int32 PolicyVersion = 0;
    /** The statements in the requested policy. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        TArray<UPlayFabJsonObject*> Statements;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminListOpenIdConnectionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminListOpenIdConnectionResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of Open ID Connections */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        TArray<UPlayFabJsonObject*> Connections;
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
struct PLAYFAB_API FAdminSetPlayerSecretRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString PlayerSecret;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminSetPlayerSecretResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdateOpenIdConnectionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The client ID given by the ID provider. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString ClientId;
    /** The client secret given by the ID provider. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString ClientSecret;
    /** A name for the connection that identifies it within the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString ConnectionId;
    /** The issuer URL or discovery document URL to read issuer information from */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString IssuerDiscoveryUrl;
    /** Manually specified information for an OpenID Connect issuer. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        UPlayFabJsonObject* IssuerInformation = nullptr;
};

/**
 * Player Shared Secret Keys are used for the call to Client/GetTitlePublicKey, which exchanges the shared secret for an
 * RSA CSP blob to be used to encrypt the payload of account creation requests when that API requires a signature header.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdatePlayerSharedSecretRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Disable or Enable this key */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        bool Disabled = false;
    /** Friendly name for this key */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString FriendlyName;
    /** The shared secret key to update */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString SecretKey;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdatePlayerSharedSecretResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * Updates permissions for your title. Policies affect what is allowed to happen on your title. Your policy is a collection
 * of statements that, together, govern particular area for your title. Today, the only allowed policy is called
 * 'ApiPolicy' and it governs what API calls are allowed. To verify that you have the latest version always download the
 * current policy from GetPolicy before uploading a new policy. PlayFab updates the base policy periodically and will
 * automatically apply it to the uploaded policy. Overwriting the combined policy blindly may result in unexpected API
 * errors.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdatePolicyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Whether to overwrite or append to the existing policy. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        bool OverwritePolicy = false;
    /** The name of the policy being updated. Only supported name is 'ApiPolicy' */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString PolicyName;
    /** Version of the policy to update. Must be the latest (as returned by GetPolicy). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        int32 PolicyVersion = 0;
    /** The new statements to include in the policy. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        TArray<UPlayFabJsonObject*> Statements;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdatePolicyResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The name of the policy that was updated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString PolicyName;
    /** The statements included in the new version of the policy. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        TArray<UPlayFabJsonObject*> Statements;
};


///////////////////////////////////////////////////////
// Characters
//////////////////////////////////////////////////////

/**
 * Note that this action cannot be un-done. All statistics for this character will be deleted, removing the user from all
 * leaderboards for the game.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminResetCharacterStatisticsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Characters Models")
        FString CharacterId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Characters Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Characters Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminResetCharacterStatisticsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminBlankResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminDeleteContentRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Key of the content item to be deleted */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Content Models")
        FString Key;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetContentListRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Limits the response to keys that begin with the specified prefix. You can use prefixes to list contents under a folder,
     * or for a specified version, etc.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Content Models")
        FString Prefix;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetContentListResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of content items. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Content Models")
        TArray<UPlayFabJsonObject*> Contents;
    /** Number of content items returned. We currently have a maximum of 1000 items limit. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Content Models")
        int32 ItemCount = 0;
    /** The total size of listed contents in bytes. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Content Models")
        int32 TotalSize = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetContentUploadUrlRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * A standard MIME type describing the format of the contents. The same MIME type has to be set in the header when
     * uploading the content. If not specified, the MIME type is 'binary/octet-stream' by default.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Content Models")
        FString ContentType;
    /** Key of the content item to upload, usually formatted as a path, e.g. images/a.png */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Content Models")
        FString Key;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetContentUploadUrlResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * URL for uploading content via HTTP PUT method. The URL requires the 'x-ms-blob-type' header to have the value
     * 'BlockBlob'. The URL will expire in approximately one hour.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Content Models")
        FString URL;
};


///////////////////////////////////////////////////////
// Custom Server Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminAddServerBuildRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** server host regions in which this build should be running and available */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString ActiveRegions;
    /** unique identifier for the build executable */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString BuildId;
    /** appended to the end of the command line when starting game servers */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString CommandLineTemplate;
    /** developer comment(s) for this build */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString Comment;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** path to the game server executable. Defaults to gameserver.exe */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString ExecutablePath;
    /** maximum number of game server instances that can run on a single host machine */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        int32 MaxGamesPerHost = 0;
    /**
     * minimum capacity of additional game server instances that can be started before the autoscaling service starts new host
     * machines (given the number of current running host machines and game server instances)
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        int32 MinFreeGameSlots = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminAddServerBuildResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** array of regions where this build can used, when it is active */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString ActiveRegions;
    /** unique identifier for this build executable */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString BuildId;
    /** appended to the end of the command line when starting game servers */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString CommandLineTemplate;
    /** developer comment(s) for this build */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString Comment;
    /** path to the game server executable. Defaults to gameserver.exe */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString ExecutablePath;
    /** maximum number of game server instances that can run on a single host machine */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        int32 MaxGamesPerHost = 0;
    /**
     * minimum capacity of additional game server instances that can be started before the autoscaling service starts new host
     * machines (given the number of current running host machines and game server instances)
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        int32 MinFreeGameSlots = 0;
    /** the current status of the build validation and processing steps */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        EGameBuildStatus Status;
    /** time this build was last modified (or uploaded, if this build has never been modified) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString Timestamp;
    /**
     * Unique identifier for the title, found in the Settings > Game Properties section of the PlayFab developer site when a
     * title has been selected.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString TitleId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetServerBuildInfoRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** unique identifier of the previously uploaded build executable for which information is being requested */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString BuildId;
};

/** Information about a particular server build */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetServerBuildInfoResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** array of regions where this build can used, when it is active */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString ActiveRegions;
    /** unique identifier for this build executable */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString BuildId;
    /** developer comment(s) for this build */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString Comment;
    /** error message, if any, about this build */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString ErrorMessage;
    /** maximum number of game server instances that can run on a single host machine */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        int32 MaxGamesPerHost = 0;
    /**
     * minimum capacity of additional game server instances that can be started before the autoscaling service starts new host
     * machines (given the number of current running host machines and game server instances)
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        int32 MinFreeGameSlots = 0;
    /** the current status of the build validation and processing steps */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        EGameBuildStatus Status;
    /** time this build was last modified (or uploaded, if this build has never been modified) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString Timestamp;
    /**
     * Unique identifier for the title, found in the Settings > Game Properties section of the PlayFab developer site when a
     * title has been selected.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString TitleId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetServerBuildUploadURLRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** unique identifier of the game server build to upload */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString BuildId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetServerBuildUploadURLResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** pre-authorized URL for uploading the game server build package */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString URL;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminListBuildsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminListBuildsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** array of uploaded game server builds */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        TArray<UPlayFabJsonObject*> Builds;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminModifyServerBuildRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** array of regions where this build can used, when it is active */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString ActiveRegions;
    /** unique identifier of the previously uploaded build executable to be updated */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString BuildId;
    /** appended to the end of the command line when starting game servers */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString CommandLineTemplate;
    /** developer comment(s) for this build */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString Comment;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** path to the game server executable. Defaults to gameserver.exe */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString ExecutablePath;
    /** maximum number of game server instances that can run on a single host machine */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        int32 MaxGamesPerHost = 0;
    /**
     * minimum capacity of additional game server instances that can be started before the autoscaling service starts new host
     * machines (given the number of current running host machines and game server instances)
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        int32 MinFreeGameSlots = 0;
    /** new timestamp */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString Timestamp;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminModifyServerBuildResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** array of regions where this build can used, when it is active */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString ActiveRegions;
    /** unique identifier for this build executable */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString BuildId;
    /** appended to the end of the command line when starting game servers */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString CommandLineTemplate;
    /** developer comment(s) for this build */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString Comment;
    /** path to the game server executable. Defaults to gameserver.exe */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString ExecutablePath;
    /** maximum number of game server instances that can run on a single host machine */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        int32 MaxGamesPerHost = 0;
    /**
     * minimum capacity of additional game server instances that can be started before the autoscaling service starts new host
     * machines (given the number of current running host machines and game server instances)
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        int32 MinFreeGameSlots = 0;
    /** the current status of the build validation and processing steps */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        EGameBuildStatus Status;
    /** time this build was last modified (or uploaded, if this build has never been modified) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString Timestamp;
    /**
     * Unique identifier for the title, found in the Settings > Game Properties section of the PlayFab developer site when a
     * title has been selected.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString TitleId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminRemoveServerBuildRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** unique identifier of the previously uploaded build executable to be removed */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString BuildId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminRemoveServerBuildResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Matchmaking
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetMatchmakerGameInfoRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** unique identifier of the lobby for which info is being requested */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Matchmaking Models")
        FString LobbyId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetMatchmakerGameInfoResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** version identifier of the game server executable binary being run */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Matchmaking Models")
        FString BuildVersion;
    /** time when Game Server Instance is currently scheduled to end */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Matchmaking Models")
        FString EndTime;
    /** unique identifier of the lobby */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Matchmaking Models")
        FString LobbyId;
    /** game mode for this Game Server Instance */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Matchmaking Models")
        FString Mode;
    /** array of unique PlayFab identifiers for users currently connected to this Game Server Instance */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Matchmaking Models")
        FString Players;
    /** region in which the Game Server Instance is running */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Matchmaking Models")
        ERegion Region;
    /** IPV4 address of the server */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Matchmaking Models")
        FString ServerIPV4Address;
    /** IPV6 address of the server */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Matchmaking Models")
        FString ServerIPV6Address;
    /** communication port for this Game Server Instance */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Matchmaking Models")
        int32 ServerPort = 0;
    /** Public DNS name (if any) of the server */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Matchmaking Models")
        FString ServerPublicDNSName;
    /** time when the Game Server Instance was created */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Matchmaking Models")
        FString StartTime;
    /** unique identifier of the Game Server Instance for this lobby */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Matchmaking Models")
        FString TitleId;
};

/**
 * These details are used by the PlayFab matchmaking service to determine if an existing Game Server Instance has room for
 * additional users, and by the PlayFab game server management service to determine when a new Game Server Host should be
 * created in order to prevent excess load on existing Hosts.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetMatchmakerGameModesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** previously uploaded build version for which game modes are being requested */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Matchmaking Models")
        FString BuildVersion;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetMatchmakerGameModesResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** array of game modes available for the specified build */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Matchmaking Models")
        TArray<UPlayFabJsonObject*> GameModes;
};

/**
 * These details are used by the PlayFab matchmaking service to determine if an existing Game Server Instance has room for
 * additional users, and by the PlayFab game server management service to determine when a new Game Server Host should be
 * created in order to prevent excess load on existing Hosts. This operation is not additive. Using it will cause the game
 * mode definition for the game server executable in question to be created from scratch. If there is an existing game
 * server mode definition for the given BuildVersion, it will be deleted and replaced with the data specified in this call.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminModifyMatchmakerGameModesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** previously uploaded build version for which game modes are being specified */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Matchmaking Models")
        FString BuildVersion;
    /** array of game modes (Note: this will replace all game modes for the indicated build version) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Matchmaking Models")
        TArray<UPlayFabJsonObject*> GameModes;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminModifyMatchmakerGameModesResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Player Data Management
//////////////////////////////////////////////////////

/**
 * Statistics are numeric values, with each statistic in the title also generating a leaderboard. The ResetInterval enables
 * automatically resetting leaderboards on a specified interval. Upon reset, the statistic updates to a new version with no
 * values (effectively removing all players from the leaderboard). The previous version's statistic values are also
 * archived for retrieval, if needed (see GetPlayerStatisticVersions). Statistics not created via a call to
 * CreatePlayerStatisticDefinition by default have a VersionChangeInterval of Never, meaning they do not reset on a
 * schedule, but they can be set to do so via a call to UpdatePlayerStatisticDefinition. Once a statistic has been reset
 * (sometimes referred to as versioned or incremented), the now-previous version can still be written to for up a short,
 * pre-defined period (currently 10 seconds), to prevent issues with levels completing around the time of the reset. Also,
 * once reset, the historical statistics for players in the title may be retrieved using the URL specified in the version
 * information (GetPlayerStatisticVersions). The AggregationMethod determines what action is taken when a new statistic
 * value is submitted - always update with the new value (Last), use the highest of the old and new values (Max), use the
 * smallest (Min), or add them together (Sum).
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminCreatePlayerStatisticDefinitionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** the aggregation method to use in updating the statistic (defaults to last) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        EStatisticAggregationMethod AggregationMethod;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** unique name of the statistic */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString StatisticName;
    /** interval at which the values of the statistic for all players are reset (resets begin at the next interval boundary) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        EStatisticResetIntervalOption VersionChangeInterval;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminCreatePlayerStatisticDefinitionResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** created statistic definition */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        UPlayFabJsonObject* Statistic = nullptr;
};

/**
 * Gets the download URL for the requested report data (in CSV form). The reports available through this API call are those
 * available in the Game Manager, in the Analytics->Reports tab.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetDataReportRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Reporting year (UTC) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        int32 Day = 0;
    /** Reporting month (UTC) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        int32 Month = 0;
    /** Report name */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString ReportName;
    /** Reporting year (UTC) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        int32 Year = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetDataReportResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * The URL where the requested report can be downloaded. This can be any PlayFab generated reports. The full list of
     * reports can be found at: https://docs.microsoft.com/en-us/gaming/playfab/features/analytics/reports/quickstart.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString DownloadUrl;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetPlayerStatisticDefinitionsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * Statistics are numeric values, with each statistic in the title also generating a leaderboard. The ResetInterval defines
 * the period of time at which the leaderboard for the statistic will automatically reset. Upon reset, the statistic
 * updates to a new version with no values (effectively removing all players from the leaderboard). The previous version's
 * statistic values are also archived for retrieval, if needed (see GetPlayerStatisticVersions). Statistics not created via
 * a call to CreatePlayerStatisticDefinition by default have a VersionChangeInterval of Never, meaning they do not reset on
 * a schedule, but they can be set to do so via a call to UpdatePlayerStatisticDefinition. Once a statistic has been reset
 * (sometimes referred to as versioned or incremented), the previous version can still be written to for up a short,
 * pre-defined period (currently 10 seconds), to prevent issues with levels completing around the time of the reset. Also,
 * once reset, the historical statistics for players in the title may be retrieved using the URL specified in the version
 * information (GetPlayerStatisticVersions). The AggregationMethod defines what action is taken when a new statistic value
 * is submitted - always update with the new value (Last), use the highest of the old and new values (Max), use the
 * smallest (Min), or add them together (Sum).
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetPlayerStatisticDefinitionsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** the player statistic definitions for the title */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        TArray<UPlayFabJsonObject*> Statistics;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetPlayerStatisticVersionsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** unique name of the statistic */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString StatisticName;
};

/**
 * Statistics are numeric values, with each statistic in the title also generating a leaderboard. The information returned
 * in the results defines the state of a specific version of a statistic, including when it was or will become the
 * currently active version, when it will (or did) become a previous version, and its archival state if it is no longer the
 * active version. For a statistic which has been reset, once the archival status is Complete, the full set of statistics
 * for all players in the leaderboard for that version may be retrieved via the ArchiveDownloadUrl. Statistics which have
 * not been reset (incremented/versioned) will only have a single version which is not scheduled to reset.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetPlayerStatisticVersionsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** version change history of the statistic */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        TArray<UPlayFabJsonObject*> StatisticVersions;
};

/**
 * Data is stored as JSON key-value pairs. If the Keys parameter is provided, the data object returned will only contain
 * the data specific to the indicated Keys. Otherwise, the full set of custom user data will be returned.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetUserDataRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * The version that currently exists according to the caller. The call will return the data for all of the keys if the
     * version in the system is greater than this.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        int32 IfChangedFromDataVersion = 0;
    /** Specific keys to search for in the custom user data. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString Keys;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetUserDataResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** User specific data for this title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        UPlayFabJsonObject* Data = nullptr;
    /**
     * Indicates the current version of the data that has been set. This is incremented with every set call for that type of
     * data (read-only, internal, etc). This version can be provided in Get calls to find updated data.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        int32 DataVersion = 0;
    /** PlayFab unique identifier of the user whose custom data is being returned. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString PlayFabId;
};

/**
 * Statistics are numeric values, with each statistic in the title also generating a leaderboard. When this call is made on
 * a given statistic, this forces a reset of that statistic. Upon reset, the statistic updates to a new version with no
 * values (effectively removing all players from the leaderboard). The previous version's statistic values are also
 * archived for retrieval, if needed (see GetPlayerStatisticVersions). Statistics not created via a call to
 * CreatePlayerStatisticDefinition by default have a VersionChangeInterval of Never, meaning they do not reset on a
 * schedule, but they can be set to do so via a call to UpdatePlayerStatisticDefinition. Once a statistic has been reset
 * (sometimes referred to as versioned or incremented), the now-previous version can still be written to for up a short,
 * pre-defined period (currently 10 seconds), to prevent issues with levels completing around the time of the reset. Also,
 * once reset, the historical statistics for players in the title may be retrieved using the URL specified in the version
 * information (GetPlayerStatisticVersions).
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminIncrementPlayerStatisticVersionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** unique name of the statistic */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString StatisticName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminIncrementPlayerStatisticVersionResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** version change history of the statistic */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        UPlayFabJsonObject* StatisticVersion = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminRefundPurchaseRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique order ID for the purchase in question. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString OrderId;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString PlayFabId;
    /**
     * The Reason parameter should correspond with the payment providers reason field, if they require one such as Facebook. In
     * the case of Facebook this must match one of their refund or dispute resolution enums (See:
     * https://developers.facebook.com/docs/payments/implementation-guide/handling-disputes-refunds)
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString Reason;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminRefundPurchaseResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The order's updated purchase status. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString PurchaseStatus;
};

/**
 * Note that this action cannot be un-done. All statistics for this user will be deleted, removing the user from all
 * leaderboards for the game.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminResetUserStatisticsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminResetUserStatisticsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminResolvePurchaseDisputeRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique order ID for the purchase in question. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString OrderId;
    /**
     * Enum for the desired purchase result state after notifying the payment provider. Valid values are Revoke, Reinstate and
     * Manual. Manual will cause no change to the order state.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        EResolutionOutcome Outcome;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString PlayFabId;
    /**
     * The Reason parameter should correspond with the payment providers reason field, if they require one such as Facebook. In
     * the case of Facebook this must match one of their refund or dispute resolution enums (See:
     * https://developers.facebook.com/docs/payments/implementation-guide/handling-disputes-refunds)
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString Reason;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminResolvePurchaseDisputeResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The order's updated purchase status. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString PurchaseStatus;
};

/**
 * Statistics are numeric values, with each statistic in the title also generating a leaderboard. The ResetInterval enables
 * automatically resetting leaderboards on a specified interval. Upon reset, the statistic updates to a new version with no
 * values (effectively removing all players from the leaderboard). The previous version's statistic values are also
 * archived for retrieval, if needed (see GetPlayerStatisticVersions). Statistics not created via a call to
 * CreatePlayerStatisticDefinition by default have a VersionChangeInterval of Never, meaning they do not reset on a
 * schedule, but they can be set to do so via a call to UpdatePlayerStatisticDefinition. Once a statistic has been reset
 * (sometimes referred to as versioned or incremented), the now-previous version can still be written to for up a short,
 * pre-defined period (currently 10 seconds), to prevent issues with levels completing around the time of the reset. Also,
 * once reset, the historical statistics for players in the title may be retrieved using the URL specified in the version
 * information (GetPlayerStatisticVersions). The AggregationMethod determines what action is taken when a new statistic
 * value is submitted - always update with the new value (Last), use the highest of the old and new values (Max), use the
 * smallest (Min), or add them together (Sum).
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdatePlayerStatisticDefinitionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** the aggregation method to use in updating the statistic (defaults to last) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        EStatisticAggregationMethod AggregationMethod;
    /** unique name of the statistic */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString StatisticName;
    /**
     * interval at which the values of the statistic for all players are reset (changes are effective at the next occurance of
     * the new interval boundary)
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        EStatisticResetIntervalOption VersionChangeInterval;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdatePlayerStatisticDefinitionResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** updated statistic definition */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        UPlayFabJsonObject* Statistic = nullptr;
};

/**
 * This function performs an additive update of the arbitrary JSON object containing the custom data for the user. In
 * updating the custom data object, keys which already exist in the object will have their values overwritten, while keys
 * with null values will be removed. No other key-value pairs will be changed apart from those specified in the call.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdateUserDataRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may
     * not begin with a '!' character or be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        UPlayFabJsonObject* Data = nullptr;
    /**
     * Optional list of Data-keys to remove from UserData. Some SDKs cannot insert null-values into Data due to language
     * constraints. Use this to delete the keys directly.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString KeysToRemove;
    /** Permission to be applied to all user data keys written in this request. Defaults to "private" if not set. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        EUserDataPermission Permission;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdateUserDataResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Indicates the current version of the data that has been set. This is incremented with every set call for that type of
     * data (read-only, internal, etc). This version can be provided in Get calls to find updated data.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        int32 DataVersion = 0;
};

/**
 * This function performs an additive update of the arbitrary JSON object containing the custom data for the user. In
 * updating the custom data object, keys which already exist in the object will have their values overwritten, keys with
 * null values will be removed. No other key-value pairs will be changed apart from those specified in the call.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdateUserInternalDataRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may
     * not begin with a '!' character or be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        UPlayFabJsonObject* Data = nullptr;
    /**
     * Optional list of Data-keys to remove from UserData. Some SDKs cannot insert null-values into Data due to language
     * constraints. Use this to delete the keys directly.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString KeysToRemove;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString PlayFabId;
};


///////////////////////////////////////////////////////
// Player Item Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminAddUserVirtualCurrencyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Amount to be added to the user balance of the specified virtual currency. Maximum VC balance is Int32 (2,147,483,647).
     * Any increase over this value will be discarded.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        int32 Amount = 0;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** PlayFab unique identifier of the user whose virtual currency balance is to be increased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        FString PlayFabId;
    /** Name of the virtual currency which is to be incremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        FString VirtualCurrency;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminModifyUserVirtualCurrencyResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Balance of the virtual currency after modification. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        int32 Balance = 0;
    /**
     * Amount added or subtracted from the user's virtual currency. Maximum VC balance is Int32 (2,147,483,647). Any increase
     * over this value will be discarded.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        int32 BalanceChange = 0;
    /** User currency was subtracted from. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        FString PlayFabId;
    /** Name of the virtual currency which was modified. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        FString VirtualCurrency;
};

/** This returns the total number of these items available. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminCheckLimitedEditionItemAvailabilityRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Which catalog is being updated. If null, uses the default catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        FString CatalogVersion;
    /** The item to check for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        FString ItemId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminCheckLimitedEditionItemAvailabilityResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The amount of the specified resource remaining. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        int32 Amount = 0;
};

/**
 * All items currently in the user inventory will be returned, irrespective of how they were acquired (via purchasing,
 * grants, coupons, etc.). Items that are expired, fully consumed, or are no longer valid are not considered to be in the
 * user's current inventory, and so will not be not included.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetUserInventoryRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetUserInventoryResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of inventory items belonging to the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        TArray<UPlayFabJsonObject*> Inventory;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        FString PlayFabId;
    /** Array of virtual currency balance(s) belonging to the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrency = nullptr;
    /** Array of remaining times and timestamps for virtual currencies. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrencyRechargeTimes = nullptr;
};

/**
 * This function directly adds inventory items to user inventories. As a result of this operations, the user will not be
 * charged any transaction fee, regardless of the inventory item catalog definition. Please note that the processing time
 * for inventory grants and purchases increases fractionally the more items are in the inventory, and the more items are in
 * the grant/purchase operation.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGrantItemsToUsersRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version from which items are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        FString CatalogVersion;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Array of items to grant and the users to whom the items are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        TArray<UPlayFabJsonObject*> ItemGrants;
};

/** Please note that the order of the items in the response may not match the order of items in the request. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGrantItemsToUsersResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of items granted to users. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        TArray<UPlayFabJsonObject*> ItemGrantResults;
};

/**
 * This operation will increment the global counter for the number of these items available. This number cannot be
 * decremented, except by actual grants.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminIncrementLimitedEditionItemAvailabilityRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Amount to increase availability by. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        int32 Amount = 0;
    /** Which catalog is being updated. If null, uses the default catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        FString CatalogVersion;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The item which needs more availability. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        FString ItemId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminIncrementLimitedEditionItemAvailabilityResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * In cases where the inventory item in question is a "crate", and the items it contained have already been dispensed, this
 * will not revoke access or otherwise remove the items which were dispensed.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminRevokeInventoryItemRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        FString CharacterId;
    /** Unique PlayFab assigned instance identifier of the item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        FString ItemInstanceId;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminRevokeInventoryResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * In cases where the inventory item in question is a "crate", and the items it contained have already been dispensed, this
 * will not revoke access or otherwise remove the items which were dispensed.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminRevokeInventoryItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of player items to revoke, between 1 and 25 items. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        TArray<UPlayFabJsonObject*> Items;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminRevokeInventoryItemsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Collection of any errors that occurred during processing. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        TArray<UPlayFabJsonObject*> Errors;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminSubtractUserVirtualCurrencyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Amount to be subtracted from the user balance of the specified virtual currency. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        int32 Amount = 0;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** PlayFab unique identifier of the user whose virtual currency balance is to be decreased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        FString PlayFabId;
    /** Name of the virtual currency which is to be decremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        FString VirtualCurrency;
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
struct PLAYFAB_API FAdminAddPlayerTagRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        FString PlayFabId;
    /** Unique tag for player profile. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        FString TagName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminAddPlayerTagResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/** Request has no paramaters. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetAllSegmentsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetAllSegmentsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of segments for this title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        TArray<UPlayFabJsonObject*> Segments;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetPlayerSegmentsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of segments the requested player currently belongs to. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        TArray<UPlayFabJsonObject*> Segments;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetPlayersSegmentsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
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
struct PLAYFAB_API FAdminGetPlayersInSegmentRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Continuation token if retrieving subsequent pages of results. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        FString ContinuationToken;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Maximum number of profiles to load. Default is 1,000. Maximum is 10,000. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        int32 MaxBatchSize = 0;
    /**
     * Number of seconds to keep the continuation token active. After token expiration it is not possible to continue paging
     * results. Default is 300 (5 minutes). Maximum is 1,800 (30 minutes).
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        int32 SecondsToLive = 0;
    /** Unique identifier for this segment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        FString SegmentId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetPlayersInSegmentResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Continuation token to use to retrieve subsequent pages of results. If token returns null there are no more results. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        FString ContinuationToken;
    /** Array of player profiles in this segment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        TArray<UPlayFabJsonObject*> PlayerProfiles;
    /** Count of profiles matching this segment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        int32 ProfilesInSegment = 0;
};

/**
 * This API will return a list of canonical tags which includes both namespace and tag's name. If namespace is not
 * provided, the result is a list of all canonical tags. TagName can be used for segmentation and Namespace is limited to
 * 128 characters.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetPlayerTagsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Optional namespace to filter results by */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        FString Namespace;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetPlayerTagsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        FString PlayFabId;
    /** Canonical tags (including namespace and tag's name) for the requested user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        FString Tags;
};

/**
 * This API will trigger a player_tag_removed event and remove a tag with the given TagName and PlayFabID from the
 * corresponding player profile. TagName can be used for segmentation and it is limited to 256 characters
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminRemovePlayerTagRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        FString PlayFabId;
    /** Unique tag for player profile. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        FString TagName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminRemovePlayerTagResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// ScheduledTask
//////////////////////////////////////////////////////

/** If the task instance has already completed, there will be no-op. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminAbortTaskInstanceRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** ID of a task instance that is being aborted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        FString TaskInstanceId;
};

/**
 * Task name is unique within a title. Using a task name that's already taken will cause a name conflict error. Too many
 * create-task requests within a short time will cause a create conflict error.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminCreateActionsOnPlayerSegmentTaskRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Description the task */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        FString Description;
    /** Whether the schedule is active. Inactive schedule will not trigger task execution. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        bool IsActive = false;
    /** Name of the task. This is a unique identifier for tasks in the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        FString Name;
    /** Task details related to segment and action */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        UPlayFabJsonObject* Parameter = nullptr;
    /** Cron expression for the run schedule of the task. The expression should be in UTC. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        FString Schedule;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminCreateTaskResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** ID of the task */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        FString TaskId;
};

/**
 * Task name is unique within a title. Using a task name that's already taken will cause a name conflict error. Too many
 * create-task requests within a short time will cause a create conflict error.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminCreateCloudScriptTaskRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Description the task */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        FString Description;
    /** Whether the schedule is active. Inactive schedule will not trigger task execution. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        bool IsActive = false;
    /** Name of the task. This is a unique identifier for tasks in the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        FString Name;
    /** Task details related to CloudScript */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        UPlayFabJsonObject* Parameter = nullptr;
    /** Cron expression for the run schedule of the task. The expression should be in UTC. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        FString Schedule;
};

/**
 * Task name is unique within a title. Using a task name that's already taken will cause a name conflict error. Too many
 * create-task requests within a short time will cause a create conflict error.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminCreateInsightsScheduledScalingTaskRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Description the task */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        FString Description;
    /** Whether the schedule is active. Inactive schedule will not trigger task execution. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        bool IsActive = false;
    /** Name of the task. This is a unique identifier for tasks in the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        FString Name;
    /** Task details related to Insights Scaling */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        UPlayFabJsonObject* Parameter = nullptr;
    /** Cron expression for the run schedule of the task. The expression should be in UTC. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        FString Schedule;
};

/**
 * After a task is deleted, for tracking purposes, the task instances belonging to this task will still remain. They will
 * become orphaned and does not belongs to any task. Executions of any in-progress task instances will continue. If the
 * task specified does not exist, the deletion is considered a success.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminDeleteTaskRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Specify either the task ID or the name of task to be deleted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        UPlayFabJsonObject* Identifier = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetActionsOnPlayersInSegmentTaskInstanceResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Parameter of this task instance */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        UPlayFabJsonObject* Parameter = nullptr;
    /** Status summary of the actions-on-players-in-segment task instance */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        UPlayFabJsonObject* Summary = nullptr;
};

/**
 * The result includes detail information that's specific to a CloudScript task. Only CloudScript tasks configured as "Run
 * Cloud Script function once" will be retrieved. To get a list of task instances by task, status, or time range, use
 * GetTaskInstances.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetTaskInstanceRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** ID of the requested task instance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        FString TaskInstanceId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetCloudScriptTaskInstanceResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Parameter of this task instance */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        UPlayFabJsonObject* Parameter = nullptr;
    /** Status summary of the CloudScript task instance */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        UPlayFabJsonObject* Summary = nullptr;
};

/**
 * Only the most recent 100 task instances are returned, ordered by start time descending. The results are generic basic
 * information for task instances. To get detail information specific to each task type, use Get*TaskInstance based on its
 * corresponding task type.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetTaskInstancesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Optional range-from filter for task instances' StartedAt timestamp. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        FString StartedAtRangeFrom;
    /** Optional range-to filter for task instances' StartedAt timestamp. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        FString StartedAtRangeTo;
    /** Optional filter for task instances that are of a specific status. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        ETaskInstanceStatus StatusFilter;
    /**
     * Name or ID of the task whose instances are being queried. If not specified, return all task instances that satisfy
     * conditions set by other filters.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        UPlayFabJsonObject* TaskIdentifier = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetTaskInstancesResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Basic status summaries of the queried task instances. Empty If no task instances meets the filter criteria. To get
     * detailed status summary, use Get*TaskInstance API according to task type (e.g.
     * GetActionsOnPlayersInSegmentTaskInstance).
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        TArray<UPlayFabJsonObject*> Summaries;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetTasksRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Provide either the task ID or the task name to get a specific task. If not specified, return all defined tasks. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        UPlayFabJsonObject* Identifier = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetTasksResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Result tasks. Empty if there is no task found. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        TArray<UPlayFabJsonObject*> Tasks;
};

/** The returned task instance ID can be used to query for task execution status. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminRunTaskRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Provide either the task ID or the task name to run a task. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        UPlayFabJsonObject* Identifier = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminRunTaskResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * ID of the task instance that is started. This can be used in Get*TaskInstance (e.g. GetCloudScriptTaskInstance) API call
     * to retrieve status for the task instance.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        FString TaskInstanceId;
};

/**
 * Note that when calling this API, all properties of the task have to be provided, including properties that you do not
 * want to change. Parameters not specified would be set to default value. If the task name in the update request is new, a
 * task rename operation will be executed before updating other fields of the task. WARNING: Renaming of a task may break
 * logics where the task name is used as an identifier.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdateTaskRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Description the task */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        FString Description;
    /** Specify either the task ID or the name of the task to be updated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        UPlayFabJsonObject* Identifier = nullptr;
    /** Whether the schedule is active. Inactive schedule will not trigger task execution. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        bool IsActive = false;
    /** Name of the task. This is a unique identifier for tasks in the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        FString Name;
    /** Parameter object specific to the task type. See each task type's create API documentation for details. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        UPlayFabJsonObject* Parameter = nullptr;
    /** Cron expression for the run schedule of the task. The expression should be in UTC. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        FString Schedule;
    /** Task type. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        EScheduledTaskType Type;
};


///////////////////////////////////////////////////////
// Segments
//////////////////////////////////////////////////////

/** Send all the segment details part of CreateSegmentRequest */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminCreateSegmentRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Segment model with all of the segment properties data. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Segments Models")
        UPlayFabJsonObject* SegmentModel = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminCreateSegmentResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Error message. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Segments Models")
        FString ErrorMessage;
    /** Segment id. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Segments Models")
        FString SegmentId;
};

/** Send segment id planning to delete part of DeleteSegmentRequest object */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminDeleteSegmentRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Segment id. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Segments Models")
        FString SegmentId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminDeleteSegmentsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Error message. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Segments Models")
        FString ErrorMessage;
};

/** Given input segment ids, return list of segments. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetSegmentsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Segment ids to filter title segments. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Segments Models")
        FString SegmentIds;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetSegmentsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Error message. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Segments Models")
        FString ErrorMessage;
    /** List of title segments. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Segments Models")
        TArray<UPlayFabJsonObject*> Segments;
};

/** Update segment properties data which are planning to update */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdateSegmentRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Segment model with all of the segment properties data. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Segments Models")
        UPlayFabJsonObject* SegmentModel = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdateSegmentResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Error message. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Segments Models")
        FString ErrorMessage;
    /** Segment id. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Segments Models")
        FString SegmentId;
};


///////////////////////////////////////////////////////
// Server-Side Cloud Script
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetCloudScriptRevisionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Revision number. If left null, defaults to the latest revision */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Server-Side Cloud Script Models")
        int32 Revision = 0;
    /** Version number. If left null, defaults to the latest version */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Server-Side Cloud Script Models")
        int32 Version = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetCloudScriptRevisionResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Time this revision was created */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Server-Side Cloud Script Models")
        FString CreatedAt;
    /** List of Cloud Script files in this revision. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Server-Side Cloud Script Models")
        TArray<UPlayFabJsonObject*> Files;
    /** True if this is the currently published revision */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Server-Side Cloud Script Models")
        bool IsPublished = false;
    /** Revision number. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Server-Side Cloud Script Models")
        int32 Revision = 0;
    /** Version number. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Server-Side Cloud Script Models")
        int32 Version = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetCloudScriptVersionsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetCloudScriptVersionsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of versions */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Server-Side Cloud Script Models")
        TArray<UPlayFabJsonObject*> Versions;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminSetPublishedRevisionRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Server-Side Cloud Script Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Revision to make the current published revision */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Server-Side Cloud Script Models")
        int32 Revision = 0;
    /** Version number */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Server-Side Cloud Script Models")
        int32 Version = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminSetPublishedRevisionResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdateCloudScriptRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Server-Side Cloud Script Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** PlayFab user ID of the developer initiating the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Server-Side Cloud Script Models")
        FString DeveloperPlayFabId;
    /** List of Cloud Script files to upload to create the new revision. Must have at least one file. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Server-Side Cloud Script Models")
        TArray<UPlayFabJsonObject*> Files;
    /** Immediately publish the new revision */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Server-Side Cloud Script Models")
        bool Publish = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdateCloudScriptResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** New revision number created */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Server-Side Cloud Script Models")
        int32 Revision = 0;
    /** Cloud Script version updated */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Server-Side Cloud Script Models")
        int32 Version = 0;
};


///////////////////////////////////////////////////////
// Shared Group Data
//////////////////////////////////////////////////////

/**
 * This API is designed to store publisher-specific values which can be read, but not written to, by the client. This data
 * is shared across all titles assigned to a particular publisher, and can be used for cross-game coordination. Only titles
 * assigned to a publisher can use this API. This operation is additive. If a Key does not exist in the current dataset, it
 * will be added with the specified Value. If it already exists, the Value for that key will be overwritten with the new
 * Value. For more information email helloplayfab@microsoft.com
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminSetPublisherDataRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * key we want to set a value on (note, this is additive - will only replace an existing key's value if they are the same
     * name.) Keys are trimmed of whitespace. Keys may not begin with the '!' character.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Shared Group Data Models")
        FString Key;
    /** new value to set. Set to null to remove a value */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Shared Group Data Models")
        FString Value;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminSetPublisherDataResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Title-Wide Data Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminAddLocalizedNewsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Localized body text of the news. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString Body;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Language of the news item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString Language;
    /** Unique id of the updated news item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString NewsId;
    /** Localized title (headline) of the news item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString Title;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminAddLocalizedNewsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminAddNewsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Default body text of the news. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString Body;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Time this news was published. If not set, defaults to now. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString Timestamp;
    /** Default title (headline) of the news item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString Title;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminAddNewsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique id of the new news item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString NewsId;
};

/**
 * This operation is additive. Any new currencies defined in the array will be added to the set of those available for the
 * title, while any CurrencyCode identifiers matching existing ones in the game will be overwritten with the new values.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminAddVirtualCurrencyTypesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * List of virtual currencies and their initial deposits (the amount a user is granted when signing in for the first time)
     * to the title
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> VirtualCurrencies;
};

/** This non-reversible operation will permanently delete the requested store. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminDeleteStoreRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** catalog version of the store to delete. If null, uses the default catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString CatalogVersion;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** unqiue identifier for the store which is to be deleted */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString StoreId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminDeleteStoreResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/** Will delete all the title data associated with the given override label. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminDeleteTitleDataOverrideRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Name of the override. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString OverrideLabel;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminDeleteTitleDataOverrideResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetCatalogItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Which catalog is being requested. If null, uses the default catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString CatalogVersion;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetCatalogItemsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of items which can be purchased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> Catalog;
};

/**
 * This API is designed to return publisher-specific values which can be read, but not written to, by the client. This data
 * is shared across all titles assigned to a particular publisher, and can be used for cross-game coordination. Only titles
 * assigned to a publisher can use this API. For more information email helloplayfab@microsoft.com. This AdminAPI call for
 * getting title data guarantees no delay in between update and retrieval of newly set data.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetPublisherDataRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** array of keys to get back data from the Publisher data blob, set by the admin tools */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString Keys;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetPublisherDataResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** a dictionary object of key / value pairs */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        UPlayFabJsonObject* Data = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetRandomResultTablesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** catalog version to fetch tables from. Use default catalog version if null */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString CatalogVersion;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetRandomResultTablesResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** array of random result tables currently available */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        UPlayFabJsonObject* Tables = nullptr;
};

/**
 * A store contains an array of references to items defined in the catalog, along with the prices for the item, in both
 * real world and virtual currencies. These prices act as an override to any prices defined in the catalog. In this way,
 * the base definitions of the items may be defined in the catalog, with all associated properties, while the pricing can
 * be set for each store, as needed. This allows for subsets of goods to be defined for different purposes (in order to
 * simplify showing some, but not all catalog items to users, based upon different characteristics), along with unique
 * prices. Note that all prices defined in the catalog and store definitions for the item are considered valid, and that a
 * compromised client can be made to send a request for an item based upon any of these definitions. If no price is
 * specified in the store for an item, the price set in the catalog should be displayed to the user.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetStoreItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version to store items from. Use default catalog version if null */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString CatalogVersion;
    /** Unqiue identifier for the store which is being requested. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString StoreId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetStoreItemsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The base catalog that this store is a part of. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString CatalogVersion;
    /** Additional data about the store. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        UPlayFabJsonObject* MarketingData = nullptr;
    /** How the store was last updated (Admin or a third party). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        EPfSourceType Source;
    /** Array of items which can be purchased from this store. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> Store;
    /** The ID of this store. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString StoreId;
};

/**
 * This API method is designed to return title specific values which can be read by the client. For example, a developer
 * could choose to store values which modify the user experience, such as enemy spawn rates, weapon strengths, movement
 * speeds, etc. This allows a developer to update the title without the need to create, test, and ship a new build. If an
 * override label is specified in the request, the overrides are applied automatically and returned with the title data.
 * Note that due to caching, there may up to a minute delay in between updating title data and a query returning the newest
 * value.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetTitleDataRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Specific keys to search for in the title data (leave null to get all keys) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString Keys;
    /**
     * Optional field that specifies the name of an override. This value is ignored when used by the game client; otherwise,
     * the overrides are applied automatically to the title data.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString OverrideLabel;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminGetTitleDataResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** a dictionary object of key / value pairs */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        UPlayFabJsonObject* Data = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminListVirtualCurrencyTypesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminListVirtualCurrencyTypesResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of virtual currency names defined for this title */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> VirtualCurrencies;
};

/**
 * Virtual currencies to be removed cannot have entries in any catalog nor store for the title. Note that this operation
 * will not remove player balances for the removed currencies; if a deleted currency is recreated at any point, user
 * balances will be in an undefined state.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminRemoveVirtualCurrencyTypesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of virtual currencies to delete */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> VirtualCurrencies;
};

/**
 * This operation is not additive. Using it will cause the indicated catalog version to be created from scratch. If there
 * is an existing catalog with the version number in question, it will be deleted and replaced with only the items
 * specified in this call.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdateCatalogItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Array of catalog items to be submitted. Note that while CatalogItem has a parameter for CatalogVersion, it is not
     * required and ignored in this call.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> Catalog;
    /** Which catalog is being updated. If null, uses the default catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString CatalogVersion;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Should this catalog be set as the default catalog. Defaults to true. If there is currently no default catalog, this will
     * always set it.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        bool SetAsDefaultCatalog = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdateCatalogItemsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * This operation is not additive. Using it will cause the indicated virtual store to be created from scratch. If there is
 * an existing store with the same storeId, it will be deleted and replaced with only the items specified in this call. A
 * store contains an array of references to items defined inthe catalog, along with the prices for the item, in both real
 * world and virtual currencies. These prices act as an override to any prices defined in the catalog. In this way, the
 * base definitions of the items may be defined in the catalog, with all associated properties, while the pricing can be
 * set for each store, as needed. This allows for subsets of goods to be defined for different purposes (in order to
 * simplify showing some, but not all catalog items to users, based upon different characteristics), along with unique
 * prices. Note that all prices defined in the catalog and store definitions for the item are considered valid, and that a
 * compromised client can be made to send a request for an item based upon any of these definitions. If no price is
 * specified in the store for an item, the price set in the catalog should be displayed to the user.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdateStoreItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version of the store to update. If null, uses the default catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString CatalogVersion;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Additional data about the store */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        UPlayFabJsonObject* MarketingData = nullptr;
    /** Array of store items - references to catalog items, with specific pricing - to be added */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> Store;
    /** Unique identifier for the store which is to be updated */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString StoreId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdateStoreItemsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * This API method is designed to store title specific values which can be read by the client. For example, a developer
 * could choose to store values which modify the user experience, such as enemy spawn rates, weapon strengths, movement
 * speeds, etc. This allows a developer to update the title without the need to create, test, and ship a new build. This
 * operation is additive. If a Key does not exist in the current dataset, it will be added with the specified Value. If it
 * already exists, the Value for that key will be overwritten with the new Value.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminSetTitleDataRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * key we want to set a value on (note, this is additive - will only replace an existing key's value if they are the same
     * name.) Keys are trimmed of whitespace. Keys may not begin with the '!' character.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString Key;
    /** new value to set. Set to null to remove a value */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString Value;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminSetTitleDataResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * Will set the given key values in the specified override or the primary title data based on whether the label is provided
 * or not.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminSetTitleDataAndOverridesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * List of titleData key-value pairs to set/delete. Use an empty value to delete an existing key; use a non-empty value to
     * create/update a key.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> KeyValues;
    /** Name of the override. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString OverrideLabel;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminSetTitleDataAndOverridesResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * When using the Apple Push Notification service (APNS) or the development version (APNS_SANDBOX), the APNS Private Key
 * should be used as the Credential in this call. With Google Cloud Messaging (GCM), the Android API Key should be used.
 * The current ARN (if one exists) can be overwritten by setting the OverwriteOldARN boolean to true.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminSetupPushNotificationRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Credential is the Private Key for APNS/APNS_SANDBOX, and the API Key for GCM */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString Credential;
    /** for APNS, this is the PlatformPrincipal (SSL Certificate) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString Key;
    /** This field is deprecated and any usage of this will cause the API to fail. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString Name;
    /**
     * replace any existing ARN with the newly generated one. If this is set to false, an error will be returned if
     * notifications have already setup for this platform.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        bool OverwriteOldARN = false;
    /**
     * supported notification platforms are Apple Push Notification Service (APNS and APNS_SANDBOX) for iOS and Google Cloud
     * Messaging (GCM) for Android
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        EPushSetupPlatform Platform;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminSetupPushNotificationResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Amazon Resource Name for the created notification topic. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString ARN;
};

/**
 * This operation is additive. Tables with TableId values not currently defined will be added, while those with TableId
 * values matching Tables currently in the catalog will be overwritten with the given values.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdateRandomResultTablesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** which catalog is being updated. If null, update the current default catalog version */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString CatalogVersion;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * array of random result tables to make available (Note: specifying an existing TableId will result in overwriting that
     * table, while any others will be added to the available set)
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> Tables;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAdminUpdateRandomResultTablesResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

