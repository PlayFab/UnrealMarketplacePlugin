//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Client
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabClientModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Client API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FClientAddGenericIDRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Generic service identifier to add to the player account. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* GenericId = nullptr;
};

USTRUCT(BlueprintType)
struct FClientAddGenericIDResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientAddOrUpdateContactEmailRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The new contact email to associate with the player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString EmailAddress;
};

USTRUCT(BlueprintType)
struct FClientAddOrUpdateContactEmailResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientAddUsernamePasswordRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** User email address attached to their account */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString Email;
    /** Password for the PlayFab account (6-100 characters) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString Password;
    /** PlayFab username for the account (3-20 characters) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString Username;
};

USTRUCT(BlueprintType)
struct FClientAddUsernamePasswordResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** PlayFab unique user name. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString Username;
};

USTRUCT(BlueprintType)
struct FClientGetAccountInfoRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** User email address for the account to find (if no Username is specified). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString Email;
    /**
     * Unique PlayFab identifier of the user whose info is being requested. Optional, defaults to the authenticated user if no
     * other lookup identifier set.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString PlayFabId;
    /**
     * Title-specific username for the account to find (if no Email is set). Note that if the non-unique Title Display Names
     * option is enabled for the title, attempts to look up users by Title Display Name will always return AccountNotFound.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString TitleDisplayName;
    /** PlayFab Username for the account to find (if no PlayFabId is specified). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString Username;
};

USTRUCT(BlueprintType)
struct FClientGetAccountInfoResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Account information for the local user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* AccountInfo = nullptr;
};

USTRUCT(BlueprintType)
struct FClientGetPlayerCombinedInfoRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** PlayFabId of the user whose data will be returned. If not filled included, we return the data for the calling player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FClientGetPlayerCombinedInfoResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Results for requested info. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* InfoResultPayload = nullptr;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FClientGetPlayerProfileRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString PlayFabId;
    /**
     * If non-null, this determines which properties of the resulting player profiles to return. For API calls from the client,
     * only the allowed client profile properties for the title may be requested. These allowed properties are configured in
     * the Game Manager "Client Profile Options" tab in the "Settings" section.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* ProfileConstraints = nullptr;
};

USTRUCT(BlueprintType)
struct FClientGetPlayerProfileResult
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * The profile of the player. This profile is not guaranteed to be up-to-date. For a new player, this profile will not
     * exist.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* PlayerProfile = nullptr;
};

USTRUCT(BlueprintType)
struct FClientGetPlayFabIDsFromFacebookIDsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Facebook identifiers for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString FacebookIDs;
};

USTRUCT(BlueprintType)
struct FClientGetPlayFabIDsFromFacebookIDsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Facebook identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct FClientGetPlayFabIDsFromFacebookInstantGamesIdsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Facebook Instant Games identifiers for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString FacebookInstantGamesIds;
};

USTRUCT(BlueprintType)
struct FClientGetPlayFabIDsFromFacebookInstantGamesIdsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Facebook Instant Games identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct FClientGetPlayFabIDsFromGameCenterIDsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Game Center identifiers (the Player Identifier) for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString GameCenterIDs;
};

USTRUCT(BlueprintType)
struct FClientGetPlayFabIDsFromGameCenterIDsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Game Center identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct FClientGetPlayFabIDsFromGenericIDsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Array of unique generic service identifiers for which the title needs to get PlayFab identifiers. Currently limited to a
     * maximum of 10 in a single request.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        TArray<UPlayFabJsonObject*> GenericIDs;
};

USTRUCT(BlueprintType)
struct FClientGetPlayFabIDsFromGenericIDsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of generic service identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct FClientGetPlayFabIDsFromGoogleIDsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Google identifiers (Google+ user IDs) for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString GoogleIDs;
};

USTRUCT(BlueprintType)
struct FClientGetPlayFabIDsFromGoogleIDsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Google identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct FClientGetPlayFabIDsFromKongregateIDsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Kongregate identifiers (Kongregate's user_id) for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString KongregateIDs;
};

USTRUCT(BlueprintType)
struct FClientGetPlayFabIDsFromKongregateIDsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Kongregate identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct FClientGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Nintendo Switch Device identifiers for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString NintendoSwitchDeviceIds;
};

USTRUCT(BlueprintType)
struct FClientGetPlayFabIDsFromNintendoSwitchDeviceIdsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Nintendo Switch Device identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct FClientGetPlayFabIDsFromSteamIDsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Steam identifiers (Steam profile IDs) for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString SteamStringIDs;
};

USTRUCT(BlueprintType)
struct FClientGetPlayFabIDsFromSteamIDsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Steam identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct FClientGetPlayFabIDsFromTwitchIDsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Twitch identifiers (Twitch's _id) for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString TwitchIds;
};

USTRUCT(BlueprintType)
struct FClientGetPlayFabIDsFromTwitchIDsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Twitch identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct FClientLinkAndroidDeviceIDRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Specific model of the user's device. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString AndroidDevice;
    /** Android device identifier for the user's device. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString AndroidDeviceId;
    /** If another user is already linked to the device, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
    /** Specific Operating System version for the user's device. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString OS;
};

USTRUCT(BlueprintType)
struct FClientLinkAndroidDeviceIDResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientLinkCustomIDRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Custom unique identifier for the user, generated by the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString CustomId;
    /** If another user is already linked to the custom ID, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
};

USTRUCT(BlueprintType)
struct FClientLinkCustomIDResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientLinkFacebookAccountRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier from Facebook for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString AccessToken;
    /** If another user is already linked to the account, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
};

USTRUCT(BlueprintType)
struct FClientLinkFacebookAccountResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientLinkFacebookInstantGamesIdRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Facebook Instant Games signature for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString FacebookInstantGamesSignature;
    /** If another user is already linked to the Facebook Instant Games ID, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
};

USTRUCT(BlueprintType)
struct FClientLinkFacebookInstantGamesIdResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientLinkGameCenterAccountRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** If another user is already linked to the account, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
    /** Game Center identifier for the player account to be linked. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString GameCenterId;
};

USTRUCT(BlueprintType)
struct FClientLinkGameCenterAccountResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientLinkGoogleAccountRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** If another user is already linked to the account, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
    /**
     * Server authentication code obtained on the client by calling getServerAuthCode()
     * (https://developers.google.com/identity/sign-in/android/offline-access) from Google Play for the user.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString ServerAuthCode;
};

USTRUCT(BlueprintType)
struct FClientLinkGoogleAccountResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientLinkIOSDeviceIDRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Vendor-specific iOS identifier for the user's device. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString DeviceId;
    /** Specific model of the user's device. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString DeviceModel;
    /** If another user is already linked to the device, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
    /** Specific Operating System version for the user's device. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString OS;
};

USTRUCT(BlueprintType)
struct FClientLinkIOSDeviceIDResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientLinkKongregateAccountRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Valid session auth ticket issued by Kongregate */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString AuthTicket;
    /** If another user is already linked to the account, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
    /** Numeric user ID assigned by Kongregate */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString KongregateId;
};

USTRUCT(BlueprintType)
struct FClientLinkKongregateAccountResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientLinkNintendoSwitchDeviceIdRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** If another user is already linked to the Nintendo Switch Device ID, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
    /** Nintendo Switch unique identifier for the user's device. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString NintendoSwitchDeviceId;
};

USTRUCT(BlueprintType)
struct FClientLinkNintendoSwitchDeviceIdResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientLinkSteamAccountRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** If another user is already linked to the account, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
    /**
     * Authentication token for the user, returned as a byte array from Steam, and converted to a string (for example, the byte
     * 0x08 should become "08").
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString SteamTicket;
};

USTRUCT(BlueprintType)
struct FClientLinkSteamAccountResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientLinkTwitchAccountRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Valid token issued by Twitch */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString AccessToken;
    /** If another user is already linked to the account, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
};

USTRUCT(BlueprintType)
struct FClientLinkTwitchAccountResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientLinkWindowsHelloAccountRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Device name. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString DeviceName;
    /** If another user is already linked to the account, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
    /** PublicKey generated by Windows Hello. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString PublicKey;
    /** Player's user named used by Windows Hello. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString UserName;
};

USTRUCT(BlueprintType)
struct FClientLinkWindowsHelloAccountResponse
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientLinkXboxAccountRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** If another user is already linked to the account, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
    /** Token provided by the Xbox Live SDK/XDK method GetTokenAndSignatureAsync("POST", "https://playfabapi.com", ""). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString XboxToken;
};

USTRUCT(BlueprintType)
struct FClientLinkXboxAccountResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientRemoveContactEmailRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientRemoveContactEmailResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientRemoveGenericIDRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Generic service identifier to be removed from the player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* GenericId = nullptr;
};

USTRUCT(BlueprintType)
struct FClientRemoveGenericIDResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientReportPlayerClientRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Optional additional comment by reporting player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString Comment;
    /** Unique PlayFab identifier of the reported player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString ReporteeId;
};

USTRUCT(BlueprintType)
struct FClientReportPlayerClientResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** The number of remaining reports which may be filed today. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        int32 SubmissionsRemaining = 0;
};

USTRUCT(BlueprintType)
struct FClientSendAccountRecoveryEmailRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** User email address attached to their account */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString Email;
    /** The email template id of the account recovery email template to send. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString EmailTemplateId;
};

USTRUCT(BlueprintType)
struct FClientSendAccountRecoveryEmailResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientUnlinkAndroidDeviceIDRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Android device identifier for the user's device. If not specified, the most recently signed in Android Device ID will be
     * used.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString AndroidDeviceId;
};

USTRUCT(BlueprintType)
struct FClientUnlinkAndroidDeviceIDResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientUnlinkCustomIDRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Custom unique identifier for the user, generated by the title. If not specified, the most recently signed in Custom ID
     * will be used.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString CustomId;
};

USTRUCT(BlueprintType)
struct FClientUnlinkCustomIDResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientUnlinkFacebookAccountRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientUnlinkFacebookAccountResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientUnlinkFacebookInstantGamesIdRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Facebook Instant Games identifier for the user. If not specified, the most recently signed in ID will be used. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString FacebookInstantGamesId;
};

USTRUCT(BlueprintType)
struct FClientUnlinkFacebookInstantGamesIdResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientUnlinkGameCenterAccountRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientUnlinkGameCenterAccountResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientUnlinkGoogleAccountRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientUnlinkGoogleAccountResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientUnlinkIOSDeviceIDRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Vendor-specific iOS identifier for the user's device. If not specified, the most recently signed in iOS Device ID will
     * be used.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString DeviceId;
};

USTRUCT(BlueprintType)
struct FClientUnlinkIOSDeviceIDResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientUnlinkKongregateAccountRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientUnlinkKongregateAccountResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientUnlinkNintendoSwitchDeviceIdRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Nintendo Switch Device identifier for the user. If not specified, the most recently signed in device ID will be used. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString NintendoSwitchDeviceId;
};

USTRUCT(BlueprintType)
struct FClientUnlinkNintendoSwitchDeviceIdResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientUnlinkSteamAccountRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientUnlinkSteamAccountResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientUnlinkTwitchAccountRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientUnlinkTwitchAccountResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientUnlinkWindowsHelloAccountRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** SHA256 hash of the PublicKey generated by Windows Hello. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString PublicKeyHint;
};

USTRUCT(BlueprintType)
struct FClientUnlinkWindowsHelloAccountResponse
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientUnlinkXboxAccountRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Token provided by the Xbox Live SDK/XDK method GetTokenAndSignatureAsync("POST", "https://playfabapi.com", ""). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString XboxToken;
};

USTRUCT(BlueprintType)
struct FClientUnlinkXboxAccountResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientEmptyResponse
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientUpdateAvatarUrlRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** URL of the avatar image. If empty, it removes the existing avatar URL. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString ImageUrl;
};

USTRUCT(BlueprintType)
struct FClientUpdateUserTitleDisplayNameRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** New title display name for the user - must be between 3 and 25 characters. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString DisplayName;
};

USTRUCT(BlueprintType)
struct FClientUpdateUserTitleDisplayNameResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Current title display name for the user (this will be the original display name if the rename attempt failed). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString DisplayName;
};


///////////////////////////////////////////////////////
// Advertising
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FClientAttributeInstallRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The adid for this device. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Advertising Models")
        FString Adid;
    /** The IdentifierForAdvertisers for iOS Devices. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Advertising Models")
        FString Idfa;
};

USTRUCT(BlueprintType)
struct FClientAttributeInstallResult
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Analytics
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FClientDeviceInfoRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information posted to the PlayStream Event. Currently arbitrary, and specific to the environment sending it. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        UPlayFabJsonObject* Info = nullptr;
};

USTRUCT(BlueprintType)
struct FClientWriteClientCharacterEventRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Custom event properties. Each property consists of a name (string) and a value (JSON object). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        UPlayFabJsonObject* Body = nullptr;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        FString CharacterId;
    /**
     * The name of the event, within the namespace scoped to the title. The naming convention is up to the caller, but it
     * commonly follows the subject_verb_object pattern (e.g. player_logged_in).
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        FString EventName;
    /** The time (in UTC) associated with this event. The value dafaults to the current time. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        FString Timestamp;
};

USTRUCT(BlueprintType)
struct FClientWriteEventResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * The unique identifier of the event. The values of this identifier consist of ASCII characters and are not constrained to
     * any particular format.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        FString EventId;
};

USTRUCT(BlueprintType)
struct FClientWriteClientPlayerEventRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Custom data properties associated with the event. Each property consists of a name (string) and a value (JSON object). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        UPlayFabJsonObject* Body = nullptr;
    /**
     * The name of the event, within the namespace scoped to the title. The naming convention is up to the caller, but it
     * commonly follows the subject_verb_object pattern (e.g. player_logged_in).
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        FString EventName;
    /** The time (in UTC) associated with this event. The value dafaults to the current time. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        FString Timestamp;
};

USTRUCT(BlueprintType)
struct FClientWriteTitleEventRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Custom event properties. Each property consists of a name (string) and a value (JSON object). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        UPlayFabJsonObject* Body = nullptr;
    /**
     * The name of the event, within the namespace scoped to the title. The naming convention is up to the caller, but it
     * commonly follows the subject_verb_object pattern (e.g. player_logged_in).
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        FString EventName;
    /** The time (in UTC) associated with this event. The value dafaults to the current time. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        FString Timestamp;
};


///////////////////////////////////////////////////////
// Authentication
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FClientGetPhotonAuthenticationTokenRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The Photon applicationId for the game you wish to log into. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PhotonApplicationId;
};

USTRUCT(BlueprintType)
struct FClientGetPhotonAuthenticationTokenResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** The Photon authentication token for this game-session. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PhotonCustomAuthenticationToken;
};

USTRUCT(BlueprintType)
struct FClientGetTitlePublicKeyRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The shared secret key for this title */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString TitleSharedSecret;
};

USTRUCT(BlueprintType)
struct FClientGetTitlePublicKeyResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Base64 encoded RSA CSP byte array blob containing the title's public RSA key */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString RSAPublicKey;
};

USTRUCT(BlueprintType)
struct FClientGetWindowsHelloChallengeRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** SHA256 hash of the PublicKey generated by Windows Hello. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PublicKeyHint;
};

USTRUCT(BlueprintType)
struct FClientGetWindowsHelloChallengeResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** Server generated challenge to be signed by the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString Challenge;
};

USTRUCT(BlueprintType)
struct FClientLoginResult
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * If LoginTitlePlayerAccountEntity flag is set on the login request the title_player_account will also be logged in and
     * returned.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* EntityToken = nullptr;
    /** Results for requested info. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoResultPayload = nullptr;
    /** The time of this user's previous login. If there was no previous login, then it's DateTime.MinValue */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString LastLoginTime;
    /** True if the account was newly created on this login. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool NewlyCreated = false;
    /** Player's unique PlayFabId. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayFabId;
    /** Unique token authorizing the user and game at the server level, for the current session. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString SessionTicket;
    /** Settings specific to this user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* SettingsForUser = nullptr;
};

USTRUCT(BlueprintType)
struct FClientLoginWithAndroidDeviceIDRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Specific model of the user's device. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString AndroidDevice;
    /** Android device identifier for the user's device. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString AndroidDeviceId;
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Formerly triggered an Entity login with a normal client login. This is now automatic, and always-on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool LoginTitlePlayerAccountEntity = false;
    /** Specific Operating System version for the user's device. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString OS;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
};

USTRUCT(BlueprintType)
struct FClientLoginWithCustomIDRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** Custom unique identifier for the user, generated by the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString CustomId;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Formerly triggered an Entity login with a normal client login. This is now automatic, and always-on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool LoginTitlePlayerAccountEntity = false;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
};

USTRUCT(BlueprintType)
struct FClientLoginWithEmailAddressRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Email address for the account. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString Email;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Formerly triggered an Entity login with a normal client login. This is now automatic, and always-on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool LoginTitlePlayerAccountEntity = false;
    /** Password for the PlayFab account (6-100 characters) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString Password;
};

USTRUCT(BlueprintType)
struct FClientLoginWithFacebookRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier from Facebook for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString AccessToken;
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Formerly triggered an Entity login with a normal client login. This is now automatic, and always-on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool LoginTitlePlayerAccountEntity = false;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
};

USTRUCT(BlueprintType)
struct FClientLoginWithFacebookInstantGamesIdRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Facebook Instant Games signature for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString FacebookInstantGamesSignature;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Formerly triggered an Entity login with a normal client login. This is now automatic, and always-on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool LoginTitlePlayerAccountEntity = false;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
};

USTRUCT(BlueprintType)
struct FClientLoginWithGameCenterRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Formerly triggered an Entity login with a normal client login. This is now automatic, and always-on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool LoginTitlePlayerAccountEntity = false;
    /** Unique Game Center player id. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerId;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
};

USTRUCT(BlueprintType)
struct FClientLoginWithGoogleAccountRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Formerly triggered an Entity login with a normal client login. This is now automatic, and always-on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool LoginTitlePlayerAccountEntity = false;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
    /**
     * OAuth 2.0 server authentication code obtained on the client by calling the getServerAuthCode()
     * (https://developers.google.com/identity/sign-in/android/offline-access) Google client API.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString ServerAuthCode;
};

USTRUCT(BlueprintType)
struct FClientLoginWithIOSDeviceIDRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** Vendor-specific iOS identifier for the user's device. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString DeviceId;
    /** Specific model of the user's device. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString DeviceModel;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Formerly triggered an Entity login with a normal client login. This is now automatic, and always-on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool LoginTitlePlayerAccountEntity = false;
    /** Specific Operating System version for the user's device. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString OS;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
};

USTRUCT(BlueprintType)
struct FClientLoginWithKongregateRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Token issued by Kongregate's client API for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString AuthTicket;
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Numeric user ID assigned by Kongregate */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString KongregateId;
    /** Formerly triggered an Entity login with a normal client login. This is now automatic, and always-on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool LoginTitlePlayerAccountEntity = false;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
};

USTRUCT(BlueprintType)
struct FClientLoginWithNintendoSwitchDeviceIdRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Formerly triggered an Entity login with a normal client login. This is now automatic, and always-on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool LoginTitlePlayerAccountEntity = false;
    /** Nintendo Switch unique identifier for the user's device. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString NintendoSwitchDeviceId;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
};

USTRUCT(BlueprintType)
struct FClientLoginWithPlayFabRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Formerly triggered an Entity login with a normal client login. This is now automatic, and always-on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool LoginTitlePlayerAccountEntity = false;
    /** Password for the PlayFab account (6-100 characters) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString Password;
    /** PlayFab username for the account. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString Username;
};

USTRUCT(BlueprintType)
struct FClientLoginWithSteamRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Formerly triggered an Entity login with a normal client login. This is now automatic, and always-on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool LoginTitlePlayerAccountEntity = false;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
    /**
     * Authentication token for the user, returned as a byte array from Steam, and converted to a string (for example, the byte
     * 0x08 should become "08").
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString SteamTicket;
};

USTRUCT(BlueprintType)
struct FClientLoginWithTwitchRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Token issued by Twitch's API for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString AccessToken;
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Formerly triggered an Entity login with a normal client login. This is now automatic, and always-on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool LoginTitlePlayerAccountEntity = false;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
};

USTRUCT(BlueprintType)
struct FClientLoginWithWindowsHelloRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The signed response from the user for the Challenge. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString ChallengeSignature;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Formerly triggered an Entity login with a normal client login. This is now automatic, and always-on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool LoginTitlePlayerAccountEntity = false;
    /** SHA256 hash of the PublicKey generated by Windows Hello. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PublicKeyHint;
};

USTRUCT(BlueprintType)
struct FClientLoginWithXboxRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Formerly triggered an Entity login with a normal client login. This is now automatic, and always-on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool LoginTitlePlayerAccountEntity = false;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
    /** Token provided by the Xbox Live SDK/XDK method GetTokenAndSignatureAsync("POST", "https://playfabapi.com", ""). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString XboxToken;
};

USTRUCT(BlueprintType)
struct FClientRegisterPlayFabUserRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** An optional parameter for setting the display name for this title (3-25 characters). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString DisplayName;
    /** User email address attached to their account */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString Email;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Formerly triggered an Entity login with a normal client login. This is now automatic, and always-on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool LoginTitlePlayerAccountEntity = false;
    /** Password for the PlayFab account (6-100 characters) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString Password;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
    /**
     * An optional parameter that specifies whether both the username and email parameters are required. If true, both
     * parameters are required; if false, the user must supply either the username or email parameter. The default value is
     * true.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool RequireBothUsernameAndEmail = false;
    /** PlayFab username for the account (3-20 characters) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString Username;
};

USTRUCT(BlueprintType)
struct FClientRegisterPlayFabUserResult
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * If LoginTitlePlayerAccountEntity flag is set on the login request the title_player_account will also be logged in and
     * returned.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* EntityToken = nullptr;
    /** PlayFab unique identifier for this newly created account. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayFabId;
    /** Unique token identifying the user and game at the server level, for the current session. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString SessionTicket;
    /** Settings specific to this user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* SettingsForUser = nullptr;
    /** PlayFab unique user name. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString Username;
};

USTRUCT(BlueprintType)
struct FClientRegisterWithWindowsHelloRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Device name. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString DeviceName;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Formerly triggered an Entity login with a normal client login. This is now automatic, and always-on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool LoginTitlePlayerAccountEntity = false;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
    /** PublicKey generated by Windows Hello. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PublicKey;
    /** Player's user name used by Windows Hello. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString UserName;
};

USTRUCT(BlueprintType)
struct FClientSetPlayerSecretRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
};

USTRUCT(BlueprintType)
struct FClientSetPlayerSecretResult
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Character Data
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FClientGetCharacterDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Character Data Models")
        FString CharacterId;
    /**
     * The version that currently exists according to the caller. The call will return the data for all of the keys if the
     * version in the system is greater than this.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Character Data Models")
        int32 IfChangedFromDataVersion = 0;
    /** Specific keys to search for in the custom user data. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Character Data Models")
        FString Keys;
    /** Unique PlayFab identifier of the user to load data for. Optional, defaults to yourself if not set. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Character Data Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FClientGetCharacterDataResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Character Data Models")
        FString CharacterId;
    /** User specific data for this title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Character Data Models")
        UPlayFabJsonObject* Data = nullptr;
    /**
     * Indicates the current version of the data that has been set. This is incremented with every set call for that type of
     * data (read-only, internal, etc). This version can be provided in Get calls to find updated data.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Character Data Models")
        int32 DataVersion = 0;
};

USTRUCT(BlueprintType)
struct FClientUpdateCharacterDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Character Data Models")
        FString CharacterId;
    /**
     * Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may
     * not begin with a '!' character or be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Character Data Models")
        UPlayFabJsonObject* Data;
    /**
     * Optional list of Data-keys to remove from UserData. Some SDKs cannot insert null-values into Data due to language
     * constraints. Use this to delete the keys directly.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Character Data Models")
        FString KeysToRemove;
    /** Permission to be applied to all user data keys written in this request. Defaults to "private" if not set. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Character Data Models")
        EUserDataPermission Permission;
};

USTRUCT(BlueprintType)
struct FClientUpdateCharacterDataResult
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Indicates the current version of the data that has been set. This is incremented with every set call for that type of
     * data (read-only, internal, etc). This version can be provided in Get calls to find updated data.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Character Data Models")
        int32 DataVersion = 0;
};


///////////////////////////////////////////////////////
// Characters
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FClientListUsersCharactersRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FClientListUsersCharactersResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** The requested list of characters. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        TArray<UPlayFabJsonObject*> Characters;
};

USTRUCT(BlueprintType)
struct FClientGetCharacterLeaderboardRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Optional character type on which to filter the leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        FString CharacterType;
    /** Maximum number of entries to retrieve. Default 10, maximum 100. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        int32 MaxResultsCount = 0;
    /** First entry in the leaderboard to be retrieved. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        int32 StartPosition = 0;
    /** Unique identifier for the title-specific statistic for the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        FString StatisticName;
};

USTRUCT(BlueprintType)
struct FClientGetCharacterLeaderboardResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ordered list of leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        TArray<UPlayFabJsonObject*> Leaderboard;
};

USTRUCT(BlueprintType)
struct FClientGetCharacterStatisticsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        FString CharacterId;
};

USTRUCT(BlueprintType)
struct FClientGetCharacterStatisticsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** The requested character statistics. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        UPlayFabJsonObject* CharacterStatistics;
};

USTRUCT(BlueprintType)
struct FClientGetLeaderboardAroundCharacterRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character on which to center the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        FString CharacterId;
    /** Optional character type on which to filter the leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        FString CharacterType;
    /** Maximum number of entries to retrieve. Default 10, maximum 100. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        int32 MaxResultsCount = 0;
    /** Unique identifier for the title-specific statistic for the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        FString StatisticName;
};

USTRUCT(BlueprintType)
struct FClientGetLeaderboardAroundCharacterResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ordered list of leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        TArray<UPlayFabJsonObject*> Leaderboard;
};

USTRUCT(BlueprintType)
struct FClientGetLeaderboardForUsersCharactersRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Maximum number of entries to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        int32 MaxResultsCount = 0;
    /** Unique identifier for the title-specific statistic for the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        FString StatisticName;
};

USTRUCT(BlueprintType)
struct FClientGetLeaderboardForUsersCharactersResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ordered list of leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        TArray<UPlayFabJsonObject*> Leaderboard;
};

USTRUCT(BlueprintType)
struct FClientGrantCharacterToUserRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version from which items are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        FString CatalogVersion;
    /** Non-unique display name of the character being granted (1-20 characters in length). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        FString CharacterName;
    /**
     * Catalog item identifier of the item in the user's inventory that corresponds to the character in the catalog to be
     * created.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        FString ItemId;
};

USTRUCT(BlueprintType)
struct FClientGrantCharacterToUserResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier tagged to this character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        FString CharacterId;
    /** Type of character that was created. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        FString CharacterType;
    /** Indicates whether this character was created successfully. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        bool Result = false;
};

USTRUCT(BlueprintType)
struct FClientUpdateCharacterStatisticsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        FString CharacterId;
    /** Statistics to be updated with the provided values. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        UPlayFabJsonObject* CharacterStatistics;
};

USTRUCT(BlueprintType)
struct FClientUpdateCharacterStatisticsResult
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FClientGetContentDownloadUrlRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** HTTP method to fetch item - GET or HEAD. Use HEAD when only fetching metadata. Default is GET. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Content Models")
        FString HttpMethod;
    /** Key of the content item to fetch, usually formatted as a path, e.g. images/a.png */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Content Models")
        FString Key;
    /**
     * True to download through CDN. CDN provides higher download bandwidth and lower latency. However, if you want the latest,
     * non-cached version of the content during development, set this to false. Default is true.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Content Models")
        bool ThruCDN = false;
};

USTRUCT(BlueprintType)
struct FClientGetContentDownloadUrlResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** URL for downloading content via HTTP GET or HEAD method. The URL will expire in approximately one hour. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Content Models")
        FString URL;
};


///////////////////////////////////////////////////////
// Friend List Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FClientAddFriendRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Email address of the user to attempt to add to the local user's friend list. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Friend List Management Models")
        FString FriendEmail;
    /** PlayFab identifier of the user to attempt to add to the local user's friend list. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Friend List Management Models")
        FString FriendPlayFabId;
    /** Title-specific display name of the user to attempt to add to the local user's friend list. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Friend List Management Models")
        FString FriendTitleDisplayName;
    /** PlayFab username of the user to attempt to add to the local user's friend list. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Friend List Management Models")
        FString FriendUsername;
};

USTRUCT(BlueprintType)
struct FClientAddFriendResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** True if the friend request was processed successfully. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Friend List Management Models")
        bool Created = false;
};

USTRUCT(BlueprintType)
struct FClientGetFriendsListRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Indicates whether Facebook friends should be included in the response. Default is true. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Friend List Management Models")
        bool IncludeFacebookFriends = false;
    /** Indicates whether Steam service friends should be included in the response. Default is true. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Friend List Management Models")
        bool IncludeSteamFriends = false;
    /**
     * If non-null, this determines which properties of the resulting player profiles to return. For API calls from the client,
     * only the allowed client profile properties for the title may be requested. These allowed properties are configured in
     * the Game Manager "Client Profile Options" tab in the "Settings" section.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Friend List Management Models")
        UPlayFabJsonObject* ProfileConstraints = nullptr;
    /** Xbox token if Xbox friends should be included. Requires Xbox be configured on PlayFab. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Friend List Management Models")
        FString XboxToken;
};

USTRUCT(BlueprintType)
struct FClientGetFriendsListResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of friends found. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Friend List Management Models")
        TArray<UPlayFabJsonObject*> Friends;
};

USTRUCT(BlueprintType)
struct FClientRemoveFriendRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** PlayFab identifier of the friend account which is to be removed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Friend List Management Models")
        FString FriendPlayFabId;
};

USTRUCT(BlueprintType)
struct FClientRemoveFriendResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientSetFriendTagsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** PlayFab identifier of the friend account to which the tag(s) should be applied. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Friend List Management Models")
        FString FriendPlayFabId;
    /** Array of tags to set on the friend account. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Friend List Management Models")
        FString Tags;
};

USTRUCT(BlueprintType)
struct FClientSetFriendTagsResult
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Matchmaking
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FClientCurrentGamesRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Build to match against. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString BuildVersion;
    /** Game mode to look for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString GameMode;
    /** Region to check for Game Server Instances. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        ERegion Region;
    /** Statistic name to find statistic-based matches. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString StatisticName;
    /** Filter to include and/or exclude Game Server Instances associated with certain tags. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        UPlayFabJsonObject* TagFilter = nullptr;
};

USTRUCT(BlueprintType)
struct FClientCurrentGamesResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** number of games running */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        int32 GameCount = 0;
    /** array of games found */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        TArray<UPlayFabJsonObject*> Games;
    /** total number of players across all servers */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        int32 PlayerCount = 0;
};

USTRUCT(BlueprintType)
struct FClientGameServerRegionsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** version of game server for which stats are being requested */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString BuildVersion;
};

USTRUCT(BlueprintType)
struct FClientGameServerRegionsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** array of regions found matching the request parameters */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        TArray<UPlayFabJsonObject*> Regions;
};

USTRUCT(BlueprintType)
struct FClientMatchmakeRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Build version to match against. [Note: Required if LobbyId is not specified] */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString BuildVersion;
    /** Character to use for stats based matching. Leave null to use account stats. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString CharacterId;
    /** Game mode to match make against. [Note: Required if LobbyId is not specified] */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString GameMode;
    /** Lobby identifier to match make against. This is used to select a specific Game Server Instance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString LobbyId;
    /** Region to match make against. [Note: Required if LobbyId is not specified] */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        ERegion Region;
    /** Start a game session if one with an open slot is not found. Defaults to true. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        bool StartNewIfNoneFound = false;
    /** Player statistic to use in finding a match. May be null for no stat-based matching. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString StatisticName;
    /** Filter to include and/or exclude Game Server Instances associated with certain Tags */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        UPlayFabJsonObject* TagFilter = nullptr;
};

USTRUCT(BlueprintType)
struct FClientMatchmakeResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** timestamp for when the server will expire, if applicable */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString Expires;
    /** unique lobby identifier of the server matched */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString LobbyID;
    /** time in milliseconds the application is configured to wait on matchmaking results */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        int32 PollWaitTimeMS = 0;
    /** IPV4 address of the server */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString ServerHostname;
    /** IPV4 address of the server */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString ServerIPV4Address;
    /** IPV6 address of the server */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString ServerIPV6Address;
    /** port number to use for non-http communications with the server */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        int32 ServerPort = 0;
    /** Public DNS name (if any) of the server */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString ServerPublicDNSName;
    /** result of match making process */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        EMatchmakeStatus Status;
    /** server authorization ticket (used by RedeemMatchmakerTicket to validate user insertion into the game) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString Ticket;
};

USTRUCT(BlueprintType)
struct FClientStartGameRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** version information for the build of the game server which is to be started */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString BuildVersion;
    /** character to use for stats based matching. Leave null to use account stats */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString CharacterId;
    /** custom command line argument when starting game server process */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString CustomCommandLineData;
    /** the title-defined game mode this server is to be running (defaults to 0 if there is only one mode) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString GameMode;
    /** the region to associate this server with for match filtering */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        ERegion Region;
    /** player statistic for others to use in finding this game. May be null for no stat-based matching */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString StatisticName;
};

USTRUCT(BlueprintType)
struct FClientStartGameResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** timestamp for when the server should expire, if applicable */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString Expires;
    /** unique identifier for the lobby of the server started */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString LobbyID;
    /** password required to log into the server */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString Password;
    /** server IPV4 address */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString ServerHostname;
    /** server IPV4 address */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString ServerIPV4Address;
    /** server IPV6 address */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString ServerIPV6Address;
    /** port on the server to be used for communication */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        int32 ServerPort = 0;
    /** server public DNS name */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString ServerPublicDNSName;
    /** unique identifier for the server */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString Ticket;
};


///////////////////////////////////////////////////////
// Platform Specific Methods
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FClientAndroidDevicePushNotificationRegistrationRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Message to display when confirming push notification. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString ConfirmationMessage;
    /**
     * Registration ID provided by the Google Cloud Messaging service when the title registered to receive push notifications
     * (see the GCM documentation, here: http://developer.android.com/google/gcm/client.html).
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString DeviceToken;
    /** If true, send a test push message immediately after sucessful registration. Defaults to false. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        bool SendPushNotificationConfirmation = false;
};

USTRUCT(BlueprintType)
struct FClientAndroidDevicePushNotificationRegistrationResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientConsumeXboxEntitlementsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version to use */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString CatalogVersion;
    /** Token provided by the Xbox Live SDK/XDK method GetTokenAndSignatureAsync("POST", "https://playfabapi.com", ""). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString XboxToken;
};

USTRUCT(BlueprintType)
struct FClientConsumeXboxEntitlementsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Details for the items purchased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        TArray<UPlayFabJsonObject*> Items;
};

USTRUCT(BlueprintType)
struct FClientRegisterForIOSPushNotificationRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Message to display when confirming push notification. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString ConfirmationMessage;
    /** Unique token generated by the Apple Push Notification service when the title registered to receive push notifications. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString DeviceToken;
    /** If true, send a test push message immediately after sucessful registration. Defaults to false. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        bool SendPushNotificationConfirmation = false;
};

USTRUCT(BlueprintType)
struct FClientRegisterForIOSPushNotificationResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientRestoreIOSPurchasesRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Base64 encoded receipt data, passed back by the App Store as a result of a successful purchase. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString ReceiptData;
};

USTRUCT(BlueprintType)
struct FClientRestoreIOSPurchasesResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientValidateAmazonReceiptRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version to use when granting receipt item. If null, defaults to primary catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString CatalogVersion;
    /** Currency used for the purchase. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString CurrencyCode;
    /** Amount of the stated currency paid for the object. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        int32 PurchasePrice = 0;
    /** ReceiptId returned by the Amazon App Store in-app purchase API */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString ReceiptId;
    /** AmazonId of the user making the purchase as returned by the Amazon App Store in-app purchase API */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString UserId;
};

USTRUCT(BlueprintType)
struct FClientValidateAmazonReceiptResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientValidateGooglePlayPurchaseRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Currency used for the purchase. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString CurrencyCode;
    /** Amount of the stated currency paid for the object. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        int32 PurchasePrice = 0;
    /** Original JSON string returned by the Google Play IAB API. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString ReceiptJson;
    /** Signature returned by the Google Play IAB API. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString Signature;
};

USTRUCT(BlueprintType)
struct FClientValidateGooglePlayPurchaseResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientValidateIOSReceiptRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Currency used for the purchase. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString CurrencyCode;
    /** Amount of the stated currency paid for the object. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        int32 PurchasePrice = 0;
    /** Base64 encoded receipt data, passed back by the App Store as a result of a successful purchase. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString ReceiptData;
};

USTRUCT(BlueprintType)
struct FClientValidateIOSReceiptResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientValidateWindowsReceiptRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version to use when granting receipt item. If null, defaults to primary catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString CatalogVersion;
    /** Currency used for the purchase. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString CurrencyCode;
    /** Amount of the stated currency paid for the object. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        int32 PurchasePrice = 0;
    /** XML Receipt returned by the Windows App Store in-app purchase API */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString Receipt;
};

USTRUCT(BlueprintType)
struct FClientValidateWindowsReceiptResult
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Player Data Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FClientGetFriendLeaderboardRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Indicates whether Facebook friends should be included in the response. Default is true. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        bool IncludeFacebookFriends = false;
    /** Indicates whether Steam service friends should be included in the response. Default is true. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        bool IncludeSteamFriends = false;
    /** Maximum number of entries to retrieve. Default 10, maximum 100. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        int32 MaxResultsCount = 0;
    /**
     * If non-null, this determines which properties of the resulting player profiles to return. For API calls from the client,
     * only the allowed client profile properties for the title may be requested. These allowed properties are configured in
     * the Game Manager "Client Profile Options" tab in the "Settings" section.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        UPlayFabJsonObject* ProfileConstraints = nullptr;
    /** Position in the leaderboard to start this listing (defaults to the first entry). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        int32 StartPosition = 0;
    /** Statistic used to rank friends for this leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        FString StatisticName;
    /** If set to false, Version is considered null. If true, uses the specified Version */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        bool UseSpecificVersion = false;
    /** The version of the leaderboard to get. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        int32 Version = 0;
    /** Xbox token if Xbox friends should be included. Requires Xbox be configured on PlayFab. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        FString XboxToken;
};

USTRUCT(BlueprintType)
struct FClientGetLeaderboardResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ordered listing of users and their positions in the requested leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        TArray<UPlayFabJsonObject*> Leaderboard;
    /** The time the next scheduled reset will occur. Null if the leaderboard does not reset on a schedule. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        FString NextReset;
    /** The version of the leaderboard returned. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        int32 Version = 0;
};

USTRUCT(BlueprintType)
struct FClientGetFriendLeaderboardAroundPlayerRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Indicates whether Facebook friends should be included in the response. Default is true. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        bool IncludeFacebookFriends = false;
    /** Indicates whether Steam service friends should be included in the response. Default is true. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        bool IncludeSteamFriends = false;
    /** Maximum number of entries to retrieve. Default 10, maximum 100. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        int32 MaxResultsCount = 0;
    /** PlayFab unique identifier of the user to center the leaderboard around. If null will center on the logged in user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        FString PlayFabId;
    /**
     * If non-null, this determines which properties of the resulting player profiles to return. For API calls from the client,
     * only the allowed client profile properties for the title may be requested. These allowed properties are configured in
     * the Game Manager "Client Profile Options" tab in the "Settings" section.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        UPlayFabJsonObject* ProfileConstraints = nullptr;
    /** Statistic used to rank players for this leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        FString StatisticName;
    /** If set to false, Version is considered null. If true, uses the specified Version */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        bool UseSpecificVersion = false;
    /** The version of the leaderboard to get. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        int32 Version = 0;
    /** Xbox token if Xbox friends should be included. Requires Xbox be configured on PlayFab. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        FString XboxToken;
};

USTRUCT(BlueprintType)
struct FClientGetFriendLeaderboardAroundPlayerResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ordered listing of users and their positions in the requested leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        TArray<UPlayFabJsonObject*> Leaderboard;
    /** The time the next scheduled reset will occur. Null if the leaderboard does not reset on a schedule. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        FString NextReset;
    /** The version of the leaderboard returned. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        int32 Version = 0;
};

USTRUCT(BlueprintType)
struct FClientGetLeaderboardRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Maximum number of entries to retrieve. Default 10, maximum 100. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        int32 MaxResultsCount = 0;
    /**
     * If non-null, this determines which properties of the resulting player profiles to return. For API calls from the client,
     * only the allowed client profile properties for the title may be requested. These allowed properties are configured in
     * the Game Manager "Client Profile Options" tab in the "Settings" section.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        UPlayFabJsonObject* ProfileConstraints = nullptr;
    /** Position in the leaderboard to start this listing (defaults to the first entry). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        int32 StartPosition = 0;
    /** Statistic used to rank players for this leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        FString StatisticName;
    /** If set to false, Version is considered null. If true, uses the specified Version */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        bool UseSpecificVersion = false;
    /** The version of the leaderboard to get. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        int32 Version = 0;
};

USTRUCT(BlueprintType)
struct FClientGetLeaderboardAroundPlayerRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Maximum number of entries to retrieve. Default 10, maximum 100. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        int32 MaxResultsCount = 0;
    /** PlayFab unique identifier of the user to center the leaderboard around. If null will center on the logged in user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        FString PlayFabId;
    /**
     * If non-null, this determines which properties of the resulting player profiles to return. For API calls from the client,
     * only the allowed client profile properties for the title may be requested. These allowed properties are configured in
     * the Game Manager "Client Profile Options" tab in the "Settings" section.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        UPlayFabJsonObject* ProfileConstraints = nullptr;
    /** Statistic used to rank players for this leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        FString StatisticName;
    /** If set to false, Version is considered null. If true, uses the specified Version */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        bool UseSpecificVersion = false;
    /** The version of the leaderboard to get. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        int32 Version = 0;
};

USTRUCT(BlueprintType)
struct FClientGetLeaderboardAroundPlayerResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ordered listing of users and their positions in the requested leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        TArray<UPlayFabJsonObject*> Leaderboard;
    /** The time the next scheduled reset will occur. Null if the leaderboard does not reset on a schedule. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        FString NextReset;
    /** The version of the leaderboard returned. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        int32 Version = 0;
};

USTRUCT(BlueprintType)
struct FClientGetPlayerStatisticsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** statistics to return (current version will be returned for each) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        FString StatisticNames;
    /**
     * statistics to return, if StatisticNames is not set (only statistics which have a version matching that provided will be
     * returned)
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        TArray<UPlayFabJsonObject*> StatisticNameVersions;
};

USTRUCT(BlueprintType)
struct FClientGetPlayerStatisticsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** User statistics for the requested user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        TArray<UPlayFabJsonObject*> Statistics;
};

USTRUCT(BlueprintType)
struct FClientGetPlayerStatisticVersionsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** unique name of the statistic */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        FString StatisticName;
};

USTRUCT(BlueprintType)
struct FClientGetPlayerStatisticVersionsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** version change history of the statistic */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        TArray<UPlayFabJsonObject*> StatisticVersions;
};

USTRUCT(BlueprintType)
struct FClientGetUserDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * The version that currently exists according to the caller. The call will return the data for all of the keys if the
     * version in the system is greater than this.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        int32 IfChangedFromDataVersion = 0;
    /** List of unique keys to load from. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        FString Keys;
    /**
     * Unique PlayFab identifier of the user to load data for. Optional, defaults to yourself if not set. When specified to a
     * PlayFab id of another player, then this will only return public keys for that account.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FClientGetUserDataResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** User specific data for this title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        UPlayFabJsonObject* Data = nullptr;
    /**
     * Indicates the current version of the data that has been set. This is incremented with every set call for that type of
     * data (read-only, internal, etc). This version can be provided in Get calls to find updated data.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        int32 DataVersion = 0;
};

USTRUCT(BlueprintType)
struct FClientUpdatePlayerStatisticsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Statistics to be updated with the provided values */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        TArray<UPlayFabJsonObject*> Statistics;
};

USTRUCT(BlueprintType)
struct FClientUpdatePlayerStatisticsResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientUpdateUserDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may
     * not begin with a '!' character or be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        UPlayFabJsonObject* Data;
    /**
     * Optional list of Data-keys to remove from UserData. Some SDKs cannot insert null-values into Data due to language
     * constraints. Use this to delete the keys directly.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        FString KeysToRemove;
    /**
     * Permission to be applied to all user data keys written in this request. Defaults to "private" if not set. This is used
     * for requests by one player for information about another player; those requests will only return Public keys.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        EUserDataPermission Permission;
};

USTRUCT(BlueprintType)
struct FClientUpdateUserDataResult
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Indicates the current version of the data that has been set. This is incremented with every set call for that type of
     * data (read-only, internal, etc). This version can be provided in Get calls to find updated data.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        int32 DataVersion = 0;
};


///////////////////////////////////////////////////////
// Player Item Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FClientAddUserVirtualCurrencyRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Amount to be added to the user balance of the specified virtual currency. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        int32 Amount = 0;
    /** Name of the virtual currency which is to be incremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString VirtualCurrency;
};

USTRUCT(BlueprintType)
struct FClientModifyUserVirtualCurrencyResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Balance of the virtual currency after modification. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        int32 Balance = 0;
    /**
     * Amount added or subtracted from the user's virtual currency. Maximum VC balance is Int32 (2,147,483,647). Any increase
     * over this value will be discarded.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        int32 BalanceChange = 0;
    /** User currency was subtracted from. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString PlayFabId;
    /** Name of the virtual currency which was modified. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString VirtualCurrency;
};

USTRUCT(BlueprintType)
struct FClientConfirmPurchaseRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Purchase order identifier returned from StartPurchase. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString OrderId;
};

USTRUCT(BlueprintType)
struct FClientConfirmPurchaseResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of items purchased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        TArray<UPlayFabJsonObject*> Items;
    /** Purchase order identifier. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString OrderId;
    /** Date and time of the purchase. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString PurchaseDate;
};

USTRUCT(BlueprintType)
struct FClientConsumeItemRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString CharacterId;
    /** Number of uses to consume from the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        int32 ConsumeCount = 0;
    /** Unique instance identifier of the item to be consumed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString ItemInstanceId;
};

USTRUCT(BlueprintType)
struct FClientConsumeItemResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique instance identifier of the item with uses consumed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString ItemInstanceId;
    /** Number of uses remaining on the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        int32 RemainingUses = 0;
};

USTRUCT(BlueprintType)
struct FClientGetCharacterInventoryRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Used to limit results to only those from a specific catalog version. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString CatalogVersion;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString CharacterId;
};

USTRUCT(BlueprintType)
struct FClientGetCharacterInventoryResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier of the character for this inventory. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString CharacterId;
    /** Array of inventory items belonging to the character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        TArray<UPlayFabJsonObject*> Inventory;
    /** Array of virtual currency balance(s) belonging to the character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrency;
    /** Array of remaining times and timestamps for virtual currencies. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrencyRechargeTimes = nullptr;
};

USTRUCT(BlueprintType)
struct FClientGetPaymentTokenRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The name of service to provide the payment token. Allowed Values are: xsolla */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString TokenProvider;
};

USTRUCT(BlueprintType)
struct FClientGetPaymentTokenResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** PlayFab's purchase order identifier. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString OrderId;
    /** The token from provider. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString ProviderToken;
};

USTRUCT(BlueprintType)
struct FClientGetPurchaseRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Purchase order identifier. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString OrderId;
};

USTRUCT(BlueprintType)
struct FClientGetPurchaseResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Purchase order identifier. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString OrderId;
    /** Payment provider used for transaction (If not VC) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString PaymentProvider;
    /** Date and time of the purchase. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString PurchaseDate;
    /** Provider transaction ID (If not VC) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString TransactionId;
    /** PlayFab transaction status */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString TransactionStatus;
};

USTRUCT(BlueprintType)
struct FClientGetUserInventoryRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientGetUserInventoryResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of inventory items belonging to the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        TArray<UPlayFabJsonObject*> Inventory;
    /** Array of virtual currency balance(s) belonging to the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrency;
    /** Array of remaining times and timestamps for virtual currencies. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrencyRechargeTimes = nullptr;
};

USTRUCT(BlueprintType)
struct FClientPayForPurchaseRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Currency to use to fund the purchase. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString Currency;
    /** Purchase order identifier returned from StartPurchase. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString OrderId;
    /** Payment provider to use to fund the purchase. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString ProviderName;
    /** Payment provider transaction identifier. Required for Facebook Payments. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString ProviderTransactionId;
};

USTRUCT(BlueprintType)
struct FClientPayForPurchaseResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Local credit applied to the transaction (provider specific). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        int32 CreditApplied = 0;
    /** Purchase order identifier. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString OrderId;
    /** Provider used for the transaction. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString ProviderData;
    /** A token generated by the provider to authenticate the request (provider-specific). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString ProviderToken;
    /** URL to the purchase provider page that details the purchase. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString PurchaseConfirmationPageURL;
    /** Currency for the transaction, may be a virtual currency or real money. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString PurchaseCurrency;
    /** Cost of the transaction. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        int32 PurchasePrice = 0;
    /** Status of the transaction. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        ETransactionStatus Status;
    /** Virtual currencies granted by the transaction, if any. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        UPlayFabJsonObject* VCAmount;
    /** Current virtual currency balances for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrency;
};

USTRUCT(BlueprintType)
struct FClientPurchaseItemRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version for the items to be purchased (defaults to most recent version. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString CatalogVersion;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString CharacterId;
    /** Unique identifier of the item to purchase. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString ItemId;
    /** Price the client expects to pay for the item (in case a new catalog or store was uploaded, with new prices). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        int32 Price = 0;
    /** Store to buy this item through. If not set, prices default to those in the catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString StoreId;
    /** Virtual currency to use to purchase the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString VirtualCurrency;
};

USTRUCT(BlueprintType)
struct FClientPurchaseItemResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Details for the items purchased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        TArray<UPlayFabJsonObject*> Items;
};

USTRUCT(BlueprintType)
struct FClientRedeemCouponRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version of the coupon. If null, uses the default catalog */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString CatalogVersion;
    /** Optional identifier for the Character that should receive the item. If null, item is added to the player */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString CharacterId;
    /** Generated coupon code to redeem. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString CouponCode;
};

USTRUCT(BlueprintType)
struct FClientRedeemCouponResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Items granted to the player as a result of redeeming the coupon. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        TArray<UPlayFabJsonObject*> GrantedItems;
};

USTRUCT(BlueprintType)
struct FClientStartPurchaseRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version for the items to be purchased. Defaults to most recent catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString CatalogVersion;
    /** Array of items to purchase. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        TArray<UPlayFabJsonObject*> Items;
    /** Store through which to purchase items. If not set, prices will be pulled from the catalog itself. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString StoreId;
};

USTRUCT(BlueprintType)
struct FClientStartPurchaseResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Cart items to be purchased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        TArray<UPlayFabJsonObject*> Contents;
    /** Purchase order identifier. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString OrderId;
    /** Available methods by which the user can pay. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        TArray<UPlayFabJsonObject*> PaymentOptions;
    /** Current virtual currency totals for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrencyBalances;
};

USTRUCT(BlueprintType)
struct FClientSubtractUserVirtualCurrencyRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Amount to be subtracted from the user balance of the specified virtual currency. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        int32 Amount = 0;
    /** Name of the virtual currency which is to be decremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString VirtualCurrency;
};

USTRUCT(BlueprintType)
struct FClientUnlockContainerInstanceRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Specifies the catalog version that should be used to determine container contents. If unspecified, uses catalog
     * associated with the item instance.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString CatalogVersion;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString CharacterId;
    /** ItemInstanceId of the container to unlock. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString ContainerItemInstanceId;
    /**
     * ItemInstanceId of the key that will be consumed by unlocking this container. If the container requires a key, this
     * parameter is required.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString KeyItemInstanceId;
};

USTRUCT(BlueprintType)
struct FClientUnlockContainerItemResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Items granted to the player as a result of unlocking the container. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        TArray<UPlayFabJsonObject*> GrantedItems;
    /** Unique instance identifier of the container unlocked. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString UnlockedItemInstanceId;
    /** Unique instance identifier of the key used to unlock the container, if applicable. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString UnlockedWithItemInstanceId;
    /** Virtual currency granted to the player as a result of unlocking the container. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrency;
};

USTRUCT(BlueprintType)
struct FClientUnlockContainerItemRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Specifies the catalog version that should be used to determine container contents. If unspecified, uses default/primary
     * catalog.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString CatalogVersion;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString CharacterId;
    /** Catalog ItemId of the container type to unlock. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString ContainerItemId;
};


///////////////////////////////////////////////////////
// PlayStream
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FClientGetPlayerSegmentsRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientGetPlayerSegmentsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of segments the requested player currently belongs to. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | PlayStream Models")
        TArray<UPlayFabJsonObject*> Segments;
};

USTRUCT(BlueprintType)
struct FClientGetPlayerTagsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Optional namespace to filter results by */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | PlayStream Models")
        FString Namespace;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | PlayStream Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FClientGetPlayerTagsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | PlayStream Models")
        FString PlayFabId;
    /** Canonical tags (including namespace and tag's name) for the requested user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | PlayStream Models")
        FString Tags;
};


///////////////////////////////////////////////////////
// Server-Side Cloud Script
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FClientExecuteCloudScriptRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The name of the CloudScript function to execute */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Server-Side Cloud Script Models")
        FString FunctionName;
    /** Object that is passed in to the function as the first argument */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Server-Side Cloud Script Models")
        UPlayFabJsonObject* FunctionParameter = nullptr;
    /**
     * Generate a 'player_executed_cloudscript' PlayStream event containing the results of the function execution and other
     * contextual information. This event will show up in the PlayStream debugger console for the player in Game Manager.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Server-Side Cloud Script Models")
        bool GeneratePlayStreamEvent = false;
    /**
     * Option for which revision of the CloudScript to execute. 'Latest' executes the most recently created revision, 'Live'
     * executes the current live, published revision, and 'Specific' executes the specified revision. The default value is
     * 'Specific', if the SpeificRevision parameter is specified, otherwise it is 'Live'.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Server-Side Cloud Script Models")
        ECloudScriptRevisionOption RevisionSelection;
    /** The specivic revision to execute, when RevisionSelection is set to 'Specific' */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Server-Side Cloud Script Models")
        int32 SpecificRevision = 0;
};

USTRUCT(BlueprintType)
struct FClientExecuteCloudScriptResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Number of PlayFab API requests issued by the CloudScript function */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Server-Side Cloud Script Models")
        int32 APIRequestsIssued = 0;
    /** Information about the error, if any, that occurred during execution */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Server-Side Cloud Script Models")
        UPlayFabJsonObject* Error = nullptr;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Server-Side Cloud Script Models")
        int32 ExecutionTimeSeconds = 0;
    /** The name of the function that executed */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Server-Side Cloud Script Models")
        FString FunctionName;
    /** The object returned from the CloudScript function, if any */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Server-Side Cloud Script Models")
        UPlayFabJsonObject* FunctionResult = nullptr;
    /**
     * Flag indicating if the FunctionResult was too large and was subsequently dropped from this event. This only occurs if
     * the total event size is larger than 350KB.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Server-Side Cloud Script Models")
        bool FunctionResultTooLarge = false;
    /** Number of external HTTP requests issued by the CloudScript function */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Server-Side Cloud Script Models")
        int32 HttpRequestsIssued = 0;
    /**
     * Entries logged during the function execution. These include both entries logged in the function code using log.info()
     * and log.error() and error entries for API and HTTP request failures.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Server-Side Cloud Script Models")
        TArray<UPlayFabJsonObject*> Logs;
    /**
     * Flag indicating if the logs were too large and were subsequently dropped from this event. This only occurs if the total
     * event size is larger than 350KB after the FunctionResult was removed.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Server-Side Cloud Script Models")
        bool LogsTooLarge = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Server-Side Cloud Script Models")
        int32 MemoryConsumedBytes = 0;
    /**
     * Processor time consumed while executing the function. This does not include time spent waiting on API calls or HTTP
     * requests.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Server-Side Cloud Script Models")
        int32 ProcessorTimeSeconds = 0;
    /** The revision of the CloudScript that executed */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Server-Side Cloud Script Models")
        int32 Revision = 0;
};


///////////////////////////////////////////////////////
// Shared Group Data
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FClientAddSharedGroupMembersRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** An array of unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Shared Group Data Models")
        FString PlayFabIds;
    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Shared Group Data Models")
        FString SharedGroupId;
};

USTRUCT(BlueprintType)
struct FClientAddSharedGroupMembersResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientCreateSharedGroupRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the shared group (a random identifier will be assigned, if one is not specified). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Shared Group Data Models")
        FString SharedGroupId;
};

USTRUCT(BlueprintType)
struct FClientCreateSharedGroupResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Shared Group Data Models")
        FString SharedGroupId;
};

USTRUCT(BlueprintType)
struct FClientGetSharedGroupDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** If true, return the list of all members of the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Shared Group Data Models")
        bool GetMembers = false;
    /**
     * Specific keys to retrieve from the shared group (if not specified, all keys will be returned, while an empty array
     * indicates that no keys should be returned).
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Shared Group Data Models")
        FString Keys;
    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Shared Group Data Models")
        FString SharedGroupId;
};

USTRUCT(BlueprintType)
struct FClientGetSharedGroupDataResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Data for the requested keys. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Shared Group Data Models")
        UPlayFabJsonObject* Data = nullptr;
    /** List of PlayFabId identifiers for the members of this group, if requested. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Shared Group Data Models")
        FString Members;
};

USTRUCT(BlueprintType)
struct FClientRemoveSharedGroupMembersRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** An array of unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Shared Group Data Models")
        FString PlayFabIds;
    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Shared Group Data Models")
        FString SharedGroupId;
};

USTRUCT(BlueprintType)
struct FClientRemoveSharedGroupMembersResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientUpdateSharedGroupDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may
     * not begin with a '!' character or be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Shared Group Data Models")
        UPlayFabJsonObject* Data;
    /**
     * Optional list of Data-keys to remove from UserData. Some SDKs cannot insert null-values into Data due to language
     * constraints. Use this to delete the keys directly.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Shared Group Data Models")
        FString KeysToRemove;
    /** Permission to be applied to all user data keys in this request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Shared Group Data Models")
        EUserDataPermission Permission;
    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Shared Group Data Models")
        FString SharedGroupId;
};

USTRUCT(BlueprintType)
struct FClientUpdateSharedGroupDataResult
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Title-Wide Data Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FClientGetCatalogItemsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Which catalog is being requested. If null, uses the default catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        FString CatalogVersion;
};

USTRUCT(BlueprintType)
struct FClientGetCatalogItemsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of items which can be purchased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> Catalog;
};

USTRUCT(BlueprintType)
struct FClientGetPublisherDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** array of keys to get back data from the Publisher data blob, set by the admin tools */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        FString Keys;
};

USTRUCT(BlueprintType)
struct FClientGetPublisherDataResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** a dictionary object of key / value pairs */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        UPlayFabJsonObject* Data;
};

USTRUCT(BlueprintType)
struct FClientGetStoreItemsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** catalog version to store items from. Use default catalog version if null */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        FString CatalogVersion;
    /** Unqiue identifier for the store which is being requested. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        FString StoreId;
};

USTRUCT(BlueprintType)
struct FClientGetStoreItemsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** The base catalog that this store is a part of. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        FString CatalogVersion;
    /** Additional data about the store. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        UPlayFabJsonObject* MarketingData = nullptr;
    /** How the store was last updated (Admin or a third party). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        EPfSourceType Source;
    /** Array of items which can be purchased from this store. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> Store;
    /** The ID of this store. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        FString StoreId;
};

USTRUCT(BlueprintType)
struct FClientGetTimeRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FClientGetTimeResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Current server time when the request was received, in UTC */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        FString Time;
};

USTRUCT(BlueprintType)
struct FClientGetTitleDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Specific keys to search for in the title data (leave null to get all keys) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        FString Keys;
};

USTRUCT(BlueprintType)
struct FClientGetTitleDataResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** a dictionary object of key / value pairs */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        UPlayFabJsonObject* Data;
};

USTRUCT(BlueprintType)
struct FClientGetTitleNewsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Limits the results to the last n entries. Defaults to 10 if not set. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        int32 Count = 0;
};

USTRUCT(BlueprintType)
struct FClientGetTitleNewsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of news items. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> News;
};


///////////////////////////////////////////////////////
// Trading
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FClientAcceptTradeRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Items from the accepting player's inventory in exchange for the offered items in the trade. In the case of a gift, this
     * will be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Trading Models")
        FString AcceptedInventoryInstanceIds;
    /** Player who opened the trade. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Trading Models")
        FString OfferingPlayerId;
    /** Trade identifier. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Trading Models")
        FString TradeId;
};

USTRUCT(BlueprintType)
struct FClientAcceptTradeResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** Details about trade which was just accepted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Trading Models")
        UPlayFabJsonObject* Trade = nullptr;
};

USTRUCT(BlueprintType)
struct FClientCancelTradeRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Trade identifier. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Trading Models")
        FString TradeId;
};

USTRUCT(BlueprintType)
struct FClientCancelTradeResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** Details about trade which was just canceled. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Trading Models")
        UPlayFabJsonObject* Trade = nullptr;
};

USTRUCT(BlueprintType)
struct FClientGetPlayerTradesRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Returns only trades with the given status. If null, returns all trades. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Trading Models")
        ETradeStatus StatusFilter;
};

USTRUCT(BlueprintType)
struct FClientGetPlayerTradesResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** History of trades which this player has accepted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Trading Models")
        TArray<UPlayFabJsonObject*> AcceptedTrades;
    /** The trades for this player which are currently available to be accepted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Trading Models")
        TArray<UPlayFabJsonObject*> OpenedTrades;
};

USTRUCT(BlueprintType)
struct FClientGetTradeStatusRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Player who opened trade. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Trading Models")
        FString OfferingPlayerId;
    /** Trade identifier as returned by OpenTradeOffer. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Trading Models")
        FString TradeId;
};

USTRUCT(BlueprintType)
struct FClientGetTradeStatusResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information about the requested trade. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Trading Models")
        UPlayFabJsonObject* Trade = nullptr;
};

USTRUCT(BlueprintType)
struct FClientOpenTradeRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Players who are allowed to accept the trade. If null, the trade may be accepted by any player. If empty, the trade may
     * not be accepted by any player.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Trading Models")
        FString AllowedPlayerIds;
    /** Player inventory items offered for trade. If not set, the trade is effectively a gift request */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Trading Models")
        FString OfferedInventoryInstanceIds;
    /** Catalog items accepted for the trade. If not set, the trade is effectively a gift. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Trading Models")
        FString RequestedCatalogItemIds;
};

USTRUCT(BlueprintType)
struct FClientOpenTradeResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** The information about the trade that was just opened. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Trading Models")
        UPlayFabJsonObject* Trade = nullptr;
};

