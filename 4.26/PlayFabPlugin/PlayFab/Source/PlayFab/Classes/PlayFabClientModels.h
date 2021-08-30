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
#include "PlayFabRequestCommon.h"
#include "PlayFabLoginResultCommon.h"
#include "PlayFabClientModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Client API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientAddGenericIDRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Generic service identifier to add to the player account. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* GenericId = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientAddGenericIDResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * This API adds a contact email to the player's profile. If the player's profile already contains a contact email, it will
 * update the contact email to the email address specified.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientAddOrUpdateContactEmailRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The new contact email to associate with the player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString EmailAddress;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientAddOrUpdateContactEmailResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientAddUsernamePasswordRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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

/**
 * Each account must have a unique username and email address in the PlayFab service. Once created, the account may be
 * associated with additional accounts (Steam, Facebook, Game Center, etc.), allowing for added social network lists and
 * achievements systems. This can also be used to provide a recovery method if the user loses their original means of
 * access.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientAddUsernamePasswordResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** PlayFab unique user name. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString Username;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetAccountInfoRequest : public FPlayFabRequestCommon
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

/**
 * This API retrieves details regarding the player in the PlayFab service. Note that when this call is used to retrieve
 * data about another player (not the one signed into the local client), some data, such as Personally Identifying
 * Information (PII), will be omitted for privacy reasons or to comply with the requirements of the platform belongs to.
 * The user account returned will be based on the identifier provided in priority order: PlayFabId, Username, Email, then
 * TitleDisplayName. If no identifier is specified, the currently signed in user's information will be returned.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetAccountInfoResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Account information for the local user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* AccountInfo = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayerCombinedInfoRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** PlayFabId of the user whose data will be returned. If not filled included, we return the data for the calling player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString PlayFabId;
};

/**
 * Returns whatever info is requested in the response for the user. If no user is explicitly requested this defaults to the
 * authenticated user. If the user is the same as the requester, PII (like email address, facebook id) is returned if
 * available. Otherwise, only public information is returned. All parameters default to false.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayerCombinedInfoResult : public FPlayFabResultCommon
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

/**
 * This API allows for access to details regarding a user in the PlayFab service, usually for purposes of customer support.
 * Note that data returned may be Personally Identifying Information (PII), such as email address, and so care should be
 * taken in how this data is stored and managed. Since this call will always return the relevant information for users who
 * have accessed the title, the recommendation is to not store this data locally.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayerProfileRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
struct PLAYFAB_API FClientGetPlayerProfileResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FClientGetPlayFabIDsFromFacebookIDsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Facebook identifiers for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString FacebookIDs;
};

/** For Facebook identifiers which have not been linked to PlayFab accounts, null will be returned. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayFabIDsFromFacebookIDsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Facebook identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayFabIDsFromFacebookInstantGamesIdsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Facebook Instant Games identifiers for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString FacebookInstantGamesIds;
};

/** For Facebook Instant Game identifiers which have not been linked to PlayFab accounts, null will be returned. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayFabIDsFromFacebookInstantGamesIdsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Facebook Instant Games identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayFabIDsFromGameCenterIDsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Game Center identifiers (the Player Identifier) for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString GameCenterIDs;
};

/** For Game Center identifiers which have not been linked to PlayFab accounts, null will be returned. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayFabIDsFromGameCenterIDsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Game Center identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayFabIDsFromGenericIDsRequest : public FPlayFabRequestCommon
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

/** For generic service identifiers which have not been linked to PlayFab accounts, null will be returned. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayFabIDsFromGenericIDsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of generic service identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayFabIDsFromGoogleIDsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Google identifiers (Google+ user IDs) for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString GoogleIDs;
};

/** For Google identifiers which have not been linked to PlayFab accounts, null will be returned. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayFabIDsFromGoogleIDsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Google identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayFabIDsFromKongregateIDsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Kongregate identifiers (Kongregate's user_id) for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString KongregateIDs;
};

/** For Kongregate identifiers which have not been linked to PlayFab accounts, null will be returned. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayFabIDsFromKongregateIDsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Kongregate identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Nintendo Switch Device identifiers for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString NintendoSwitchDeviceIds;
};

/** For Nintendo Switch identifiers which have not been linked to PlayFab accounts, null will be returned. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayFabIDsFromNintendoSwitchDeviceIdsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Nintendo Switch Device identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayFabIDsFromPSNAccountIDsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Id of the PSN issuer environment. If null, defaults to production environment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        int32 IssuerId = 0;
    /** Array of unique PlayStation Network identifiers for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString PSNAccountIDs;
};

/** For PlayStation Network identifiers which have not been linked to PlayFab accounts, null will be returned. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayFabIDsFromPSNAccountIDsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of PlayStation Network identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayFabIDsFromSteamIDsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Steam identifiers (Steam profile IDs) for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString SteamStringIDs;
};

/** For Steam identifiers which have not been linked to PlayFab accounts, null will be returned. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayFabIDsFromSteamIDsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Steam identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayFabIDsFromTwitchIDsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Twitch identifiers (Twitch's _id) for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString TwitchIds;
};

/** For Twitch identifiers which have not been linked to PlayFab accounts, null will be returned. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayFabIDsFromTwitchIDsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Twitch identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayFabIDsFromXboxLiveIDsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The ID of Xbox Live sandbox. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString Sandbox;
    /** Array of unique Xbox Live account identifiers for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString XboxLiveAccountIDs;
};

/** For XboxLive identifiers which have not been linked to PlayFab accounts, null will be returned. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayFabIDsFromXboxLiveIDsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of PlayStation Network identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkAndroidDeviceIDRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Specific model of the user's device. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString AndroidDevice;
    /** Android device identifier for the user's device. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString AndroidDeviceId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** If another user is already linked to the device, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
    /** Specific Operating System version for the user's device. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString OS;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkAndroidDeviceIDResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientEmptyResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkAppleRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** If another user is already linked to a specific Apple account, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
    /**
     * The JSON Web token (JWT) returned by Apple after login. Represented as the identityToken field in the authorization
     * credential payload. Used to validate the request and find the user ID (Apple subject) to link with.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString IdentityToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkCustomIDRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Custom unique identifier for the user, generated by the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString CustomId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** If another user is already linked to the custom ID, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkCustomIDResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * Facebook sign-in is accomplished using the Facebook User Access Token. More information on the Token can be found in the
 * Facebook developer documentation (https://developers.facebook.com/docs/facebook-login/access-tokens/). In Unity, for
 * example, the Token is available as AccessToken in the Facebook SDK ScriptableObject FB. Note that titles should never
 * re-use the same Facebook applications between PlayFab Title IDs, as Facebook provides unique user IDs per application
 * and doing so can result in issues with the Facebook ID for the user in their PlayFab account information. If you must
 * re-use an application in a new PlayFab Title ID, please be sure to first unlink all accounts from Facebook, or delete
 * all users in the first Title ID.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkFacebookAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier from Facebook for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString AccessToken;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** If another user is already linked to the account, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkFacebookAccountResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkFacebookInstantGamesIdRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Facebook Instant Games signature for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString FacebookInstantGamesSignature;
    /** If another user is already linked to the Facebook Instant Games ID, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkFacebookInstantGamesIdResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkGameCenterAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** If another user is already linked to the account, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
    /** Game Center identifier for the player account to be linked. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString GameCenterId;
    /** The URL for the public encryption key that will be used to verify the signature. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString PublicKeyUrl;
    /** A random value used to compute the hash and keep it randomized. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString Salt;
    /** The verification signature of the authentication payload. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString Signature;
    /**
     * The integer representation of date and time that the signature was created on. PlayFab will reject authentication
     * signatures not within 10 minutes of the server's current time.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString Timestamp;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkGameCenterAccountResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * Google sign-in is accomplished by obtaining a Google OAuth 2.0 credential using the Google sign-in for Android APIs on
 * the device and passing it to this API.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkGoogleAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
struct PLAYFAB_API FClientLinkGoogleAccountResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkIOSDeviceIDRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
struct PLAYFAB_API FClientLinkIOSDeviceIDResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkKongregateAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Valid session auth ticket issued by Kongregate */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString AuthTicket;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** If another user is already linked to the account, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
    /** Numeric user ID assigned by Kongregate */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString KongregateId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkKongregateAccountResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkNintendoServiceAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** If another user is already linked to a specific Nintendo Switch account, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
    /**
     * The JSON Web token (JWT) returned by Nintendo after login. Used to validate the request and find the user ID (Nintendo
     * Switch subject) to link with.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString IdentityToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkNintendoSwitchDeviceIdRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** If another user is already linked to the Nintendo Switch Device ID, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
    /** Nintendo Switch unique identifier for the user's device. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString NintendoSwitchDeviceId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkNintendoSwitchDeviceIdResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkOpenIdConnectRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** A name that identifies which configured OpenID Connect provider relationship to use. Maximum 100 characters. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString ConnectionId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** If another user is already linked to a specific OpenId Connect user, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
    /**
     * The JSON Web token (JWT) returned by the identity provider after login. Represented as the id_token field in the
     * identity provider's response. Used to validate the request and find the user ID (OpenID Connect subject) to link with.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString IdToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkPSNAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Authentication code provided by the PlayStation Network. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString AuthCode;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** If another user is already linked to the account, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
    /** Id of the PSN issuer environment. If null, defaults to production environment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        int32 IssuerId = 0;
    /** Redirect URI supplied to PSN when requesting an auth code */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString RedirectUri;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkPSNAccountResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * Steam authentication is accomplished with the Steam Session Ticket. More information on the Ticket can be found in the
 * Steamworks SDK, here: https://partner.steamgames.com/documentation/auth (requires sign-in). NOTE: For Steam
 * authentication to work, the title must be configured with the Steam Application ID and Publisher Key in the PlayFab Game
 * Manager (under Properties). Information on creating a Publisher Key (referred to as the Secret Key in PlayFab) for your
 * title can be found here: https://partner.steamgames.com/documentation/webapi#publisherkey.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkSteamAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
struct PLAYFAB_API FClientLinkSteamAccountResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkTwitchAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Valid token issued by Twitch */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString AccessToken;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** If another user is already linked to the account, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkTwitchAccountResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkXboxAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** If another user is already linked to the account, unlink the other user and re-link. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        bool ForceLink = false;
    /** Token provided by the Xbox Live SDK/XDK method GetTokenAndSignatureAsync("POST", "https://playfabapi.com/", ""). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString XboxToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLinkXboxAccountResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/** This API removes an existing contact email from the player's profile. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientRemoveContactEmailRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientRemoveContactEmailResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientRemoveGenericIDRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Generic service identifier to be removed from the player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* GenericId = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientRemoveGenericIDResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientReportPlayerClientRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Optional additional comment by reporting player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString Comment;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique PlayFab identifier of the reported player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString ReporteeId;
};

/**
 * Players are currently limited to five reports per day. Attempts by a single user account to submit reports beyond five
 * will result in Updated being returned as false.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientReportPlayerClientResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The number of remaining reports which may be filed today. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        int32 SubmissionsRemaining = 0;
};

/**
 * If the account in question is a "temporary" account (for example, one that was created via a call to
 * LoginFromIOSDeviceID), thisfunction will have no effect. Only PlayFab accounts which have valid email addresses will be
 * able to receive a password reset email using this API.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientSendAccountRecoveryEmailRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** User email address attached to their account */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString Email;
    /** The email template id of the account recovery email template to send. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString EmailTemplateId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientSendAccountRecoveryEmailResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkAndroidDeviceIDRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Android device identifier for the user's device. If not specified, the most recently signed in Android Device ID will be
     * used.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString AndroidDeviceId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkAndroidDeviceIDResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientEmptyResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkAppleRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkCustomIDRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Custom unique identifier for the user, generated by the title. If not specified, the most recently signed in Custom ID
     * will be used.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString CustomId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkCustomIDResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkFacebookAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkFacebookAccountResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkFacebookInstantGamesIdRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Facebook Instant Games identifier for the user. If not specified, the most recently signed in ID will be used. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString FacebookInstantGamesId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkFacebookInstantGamesIdResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkGameCenterAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkGameCenterAccountResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkGoogleAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkGoogleAccountResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkIOSDeviceIDRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Vendor-specific iOS identifier for the user's device. If not specified, the most recently signed in iOS Device ID will
     * be used.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString DeviceId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkIOSDeviceIDResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkKongregateAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkKongregateAccountResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkNintendoServiceAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkNintendoSwitchDeviceIdRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Nintendo Switch Device identifier for the user. If not specified, the most recently signed in device ID will be used. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString NintendoSwitchDeviceId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkNintendoSwitchDeviceIdResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkOpenIdConnectRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** A name that identifies which configured OpenID Connect provider relationship to use. Maximum 100 characters. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString ConnectionId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkPSNAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkPSNAccountResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkSteamAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkSteamAccountResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkTwitchAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Valid token issued by Twitch. Used to specify which twitch account to unlink from the profile. By default it uses the
     * one that is present on the profile.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString AccessToken;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkTwitchAccountResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkXboxAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlinkXboxAccountResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUpdateAvatarUrlRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** URL of the avatar image. If empty, it removes the existing avatar URL. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString ImageUrl;
};

/**
 * In addition to the PlayFab username, titles can make use of a DisplayName which is also a unique identifier, but
 * specific to the title. This allows for unique names which more closely match the theme or genre of a title, for example.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUpdateUserTitleDisplayNameRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** New title display name for the user - must be between 3 and 25 characters. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Account Management Models")
        FString DisplayName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUpdateUserTitleDisplayNameResult : public FPlayFabResultCommon
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

/**
 * If you have an ad attribution partner enabled, this will post an install to their service to track the device. It uses
 * the given device id to match based on clicks on ads.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientAttributeInstallRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FClientAttributeInstallResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/** Using an AppId to return a list of valid ad placements for a player. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetAdPlacementsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The current AppId to use */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Advertising Models")
        FString AppId;
    /** Using the name or unique identifier, filter the result for get a specific placement. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Advertising Models")
        UPlayFabJsonObject* Identifier = nullptr;
};

/** Array of AdPlacementDetails */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetAdPlacementsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of results */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Advertising Models")
        TArray<UPlayFabJsonObject*> AdPlacements;
};

/** Report ad activity */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientReportAdActivityRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Type of activity, may be Opened, Closed, Start or End */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Advertising Models")
        EAdActivity Activity;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Advertising Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique ID of the placement to report for */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Advertising Models")
        FString PlacementId;
    /** Unique ID of the reward the player was offered */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Advertising Models")
        FString RewardId;
};

/** Report ad activity response has no body */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientReportAdActivityResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/** Details on which placement and reward to perform a grant on */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientRewardAdActivityRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Advertising Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Placement unique ID */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Advertising Models")
        FString PlacementId;
    /** Reward unique ID */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Advertising Models")
        FString RewardId;
};

/** Result for rewarding an ad activity */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientRewardAdActivityResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** PlayStream Event ID that was generated by this reward (all subsequent events are associated with this event identifier) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Advertising Models")
        FString AdActivityEventId;
    /** Debug results from the grants */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Advertising Models")
        FString DebugResults;
    /** Id of the placement the reward was for */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Advertising Models")
        FString PlacementId;
    /** Name of the placement the reward was for */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Advertising Models")
        FString PlacementName;
    /** If placement has viewing limits indicates how many views are left */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Advertising Models")
        int32 PlacementViewsRemaining = 0;
    /** If placement has viewing limits indicates when they will next reset */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Advertising Models")
        int32 PlacementViewsResetMinutes = 0;
    /** Reward results */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Advertising Models")
        UPlayFabJsonObject* RewardResults = nullptr;
};


///////////////////////////////////////////////////////
// Analytics
//////////////////////////////////////////////////////

/** Any arbitrary information collected by the device */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientDeviceInfoRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information posted to the PlayStream Event. Currently arbitrary, and specific to the environment sending it. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        UPlayFabJsonObject* Info = nullptr;
};

/**
 * This API is designed to write a multitude of different client-defined events into PlayStream. It supports a flexible
 * JSON schema, which allowsfor arbitrary key-value pairs to describe any character-based event. The created event will be
 * locked to the authenticated title and player.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientWriteClientCharacterEventRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Custom event properties. Each property consists of a name (string) and a value (JSON object). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        UPlayFabJsonObject* Body = nullptr;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        FString CharacterId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * The name of the event, within the namespace scoped to the title. The naming convention is up to the caller, but it
     * commonly follows the subject_verb_object pattern (e.g. player_logged_in).
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        FString EventName;
    /** The time (in UTC) associated with this event. The value defaults to the current time. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        FString Timestamp;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientWriteEventResponse : public FPlayFabResultCommon
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

/**
 * This API is designed to write a multitude of different event types into PlayStream. It supports a flexible JSON schema,
 * which allowsfor arbitrary key-value pairs to describe any player-based event. The created event will be locked to the
 * authenticated title and player.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientWriteClientPlayerEventRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Custom data properties associated with the event. Each property consists of a name (string) and a value (JSON object). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        UPlayFabJsonObject* Body = nullptr;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * The name of the event, within the namespace scoped to the title. The naming convention is up to the caller, but it
     * commonly follows the subject_verb_object pattern (e.g. player_logged_in).
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        FString EventName;
    /** The time (in UTC) associated with this event. The value defaults to the current time. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        FString Timestamp;
};

/**
 * This API is designed to write a multitude of different client-defined events into PlayStream. It supports a flexible
 * JSON schema, which allowsfor arbitrary key-value pairs to describe any title-based event. The created event will be
 * locked to the authenticated title.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientWriteTitleEventRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Custom event properties. Each property consists of a name (string) and a value (JSON object). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        UPlayFabJsonObject* Body = nullptr;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * The name of the event, within the namespace scoped to the title. The naming convention is up to the caller, but it
     * commonly follows the subject_verb_object pattern (e.g. player_logged_in).
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        FString EventName;
    /** The time (in UTC) associated with this event. The value defaults to the current time. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Analytics Models")
        FString Timestamp;
};


///////////////////////////////////////////////////////
// Authentication
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPhotonAuthenticationTokenRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The Photon applicationId for the game you wish to log into. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PhotonApplicationId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPhotonAuthenticationTokenResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The Photon authentication token for this game-session. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PhotonCustomAuthenticationToken;
};

/**
 * An RSA CSP blob to be used to encrypt the payload of account creation requests when that API requires a signature
 * header. For example if Client/LoginWithCustomId requires signature headers but the player does not have an account yet
 * follow these steps: 1) Call Client/GetTitlePublicKey with one of the title's shared secrets. 2) Convert the Base64
 * encoded CSP blob to a byte array and create an RSA signing object. 3) Encrypt the UTF8 encoded JSON body of the
 * registration request and place the Base64 encoded result into the EncryptedRequest and with the TitleId field, all other
 * fields can be left empty when performing the API request. 4) Client receives authentication token as normal. Future
 * requests to LoginWithCustomId will require the X-PlayFab-Signature header.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetTitlePublicKeyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The shared secret key for this title */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString TitleSharedSecret;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetTitlePublicKeyResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Base64 encoded RSA CSP byte array blob containing the title's public RSA key */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString RSAPublicKey;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLoginResult : public FPlayFabLoginResultCommon
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
    /** The experimentation treatments for this user at the time of login. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* TreatmentAssignment = nullptr;
};

/**
 * On Android devices, the recommendation is to use the Settings.Secure.ANDROID_ID as the AndroidDeviceId, as described in
 * this blog post (http://android-developers.blogspot.com/2011/03/identifying-app-installations.html). More information on
 * this identifier can be found in the Android documentation
 * (http://developer.android.com/reference/android/provider/Settings.Secure.html). If this is the first time a user has
 * signed in with the Android device and CreateAccount is set to true, a new PlayFab account will be created and linked to
 * the Android device ID. In this case, no email or username will be associated with the PlayFab account. Otherwise, if no
 * PlayFab account is linked to the Android device, an error indicating this will be returned, so that the title can guide
 * the user through creation of a PlayFab account. Please note that while multiple devices of this type can be linked to a
 * single user account, only the one most recently used to login (or most recently linked) will be reflected in the user's
 * account information. We will be updating to show all linked devices in a future release.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLoginWithAndroidDeviceIDRequest : public FPlayFabRequestCommon
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
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Specific Operating System version for the user's device. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString OS;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLoginWithAppleRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /**
     * The JSON Web token (JWT) returned by Apple after login. Represented as the identityToken field in the authorization
     * credential payload.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString IdentityToken;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
};

/**
 * It is highly recommended that developers ensure that it is extremely unlikely that a customer could generate an ID which
 * is already in use by another customer. If this is the first time a user has signed in with the Custom ID and
 * CreateAccount is set to true, a new PlayFab account will be created and linked to the Custom ID. In this case, no email
 * or username will be associated with the PlayFab account. Otherwise, if no PlayFab account is linked to the Custom ID, an
 * error indicating this will be returned, so that the title can guide the user through creation of a PlayFab account.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLoginWithCustomIDRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** Custom unique identifier for the user, generated by the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString CustomId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
};

/**
 * Email address and password lengths are provided for information purposes. The server will validate that data passed in
 * conforms to the field definition and report errors appropriately. It is recommended that developers not perform this
 * validation locally, so that future updates do not require client updates.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLoginWithEmailAddressRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Email address for the account. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString Email;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Password for the PlayFab account (6-100 characters) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString Password;
};

/**
 * Facebook sign-in is accomplished using the Facebook User Access Token. More information on the Token can be found in the
 * Facebook developer documentation (https://developers.facebook.com/docs/facebook-login/access-tokens/). In Unity, for
 * example, the Token is available as AccessToken in the Facebook SDK ScriptableObject FB. If this is the first time a user
 * has signed in with the Facebook account and CreateAccount is set to true, a new PlayFab account will be created and
 * linked to the provided account's Facebook ID. In this case, no email or username will be associated with the PlayFab
 * account. Otherwise, if no PlayFab account is linked to the Facebook account, an error indicating this will be returned,
 * so that the title can guide the user through creation of a PlayFab account. Note that titles should never re-use the
 * same Facebook applications between PlayFab Title IDs, as Facebook provides unique user IDs per application and doing so
 * can result in issues with the Facebook ID for the user in their PlayFab account information. If you must re-use an
 * application in a new PlayFab Title ID, please be sure to first unlink all accounts from Facebook, or delete all users in
 * the first Title ID.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLoginWithFacebookRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier from Facebook for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString AccessToken;
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLoginWithFacebookInstantGamesIdRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Facebook Instant Games signature for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString FacebookInstantGamesSignature;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
};

/**
 * The Game Center player identifier
 * (https://developer.apple.com/library/ios/documentation/Accounts/Reference/ACAccountClassRef/index.html#//apple_ref/occ/instp/ACAccount/identifier)
 * is a generated string which is stored on the local device. As with device identifiers, care must be taken to never
 * expose a player's Game Center identifier to end users, as that could result in a user's account being compromised. If
 * this is the first time a user has signed in with Game Center and CreateAccount is set to true, a new PlayFab account
 * will be created and linked to the Game Center identifier. In this case, no email or username will be associated with the
 * PlayFab account. Otherwise, if no PlayFab account is linked to the Game Center account, an error indicating this will be
 * returned, so that the title can guide the user through creation of a PlayFab account.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLoginWithGameCenterRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Unique Game Center player id. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerId;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
    /** The URL for the public encryption key that will be used to verify the signature. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PublicKeyUrl;
    /** A random value used to compute the hash and keep it randomized. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString Salt;
    /** The verification signature of the authentication payload. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString Signature;
    /**
     * The integer representation of date and time that the signature was created on. PlayFab will reject authentication
     * signatures not within 10 minutes of the server's current time.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString Timestamp;
};

/**
 * Google sign-in is accomplished by obtaining a Google OAuth 2.0 credential using the Google sign-in for Android APIs on
 * the device and passing it to this API. If this is the first time a user has signed in with the Google account and
 * CreateAccount is set to true, a new PlayFab account will be created and linked to the Google account. Otherwise, if no
 * PlayFab account is linked to the Google account, an error indicating this will be returned, so that the title can guide
 * the user through creation of a PlayFab account. The current (recommended) method for obtaining a Google account
 * credential in an Android application is to call GoogleSignInAccount.getServerAuthCode() and send the auth code as the
 * ServerAuthCode parameter of this API. Before doing this, you must create an OAuth 2.0 web application client ID in the
 * Google API Console and configure its client ID and secret in the PlayFab Game Manager Google Add-on for your title. This
 * method does not require prompting of the user for additional Google account permissions, resulting in a user experience
 * with the least possible friction. For more information about obtaining the server auth code, see
 * https://developers.google.com/identity/sign-in/android/offline-access. The previous (deprecated) method was to obtain an
 * OAuth access token by calling GetAccessToken() on the client and passing it as the AccessToken parameter to this API.
 * for the with the Google OAuth 2.0 Access Token. More information on this change can be found in the Google developer
 * documentation (https://android-developers.googleblog.com/2016/01/play-games-permissions-are-changing-in.html).
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLoginWithGoogleAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
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

/**
 * On iOS devices, the identifierForVendor
 * (https://developer.apple.com/library/ios/documentation/UIKit/Reference/UIDevice_Class/index.html#//apple_ref/occ/instp/UIDevice/identifierForVendor)
 * must be used as the DeviceId, as the UIDevice uniqueIdentifier has been deprecated as of iOS 5, and use of the
 * advertisingIdentifier for this purpose will result in failure of Apple's certification process. If this is the first
 * time a user has signed in with the iOS device and CreateAccount is set to true, a new PlayFab account will be created
 * and linked to the vendor-specific iOS device ID. In this case, no email or username will be associated with the PlayFab
 * account. Otherwise, if no PlayFab account is linked to the iOS device, an error indicating this will be returned, so
 * that the title can guide the user through creation of a PlayFab account. Please note that while multiple devices of this
 * type can be linked to a single user account, only the one most recently used to login (or most recently linked) will be
 * reflected in the user's account information. We will be updating to show all linked devices in a future release.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLoginWithIOSDeviceIDRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
    /** Specific Operating System version for the user's device. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString OS;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
};

/**
 * More details regarding Kongregate and their game authentication system can be found at
 * http://developers.kongregate.com/docs/virtual-goods/authentication. Developers must provide the Kongregate user ID and
 * auth token that are generated using the Kongregate client library. PlayFab will combine these identifiers with the
 * title's unique Kongregate app ID to log the player into the Kongregate system. If CreateAccount is set to true and there
 * is not already a user matched to this Kongregate ID, then PlayFab will create a new account for this user and link the
 * ID. In this case, no email or username will be associated with the PlayFab account. If there is already a different
 * PlayFab user linked with this account, then an error will be returned.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLoginWithKongregateRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Token issued by Kongregate's client API for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString AuthTicket;
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Numeric user ID assigned by Kongregate */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString KongregateId;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLoginWithNintendoServiceAccountRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** The JSON Web token (JWT) returned by Nintendo after login. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString IdentityToken;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLoginWithNintendoSwitchDeviceIdRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Nintendo Switch unique identifier for the user's device. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString NintendoSwitchDeviceId;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLoginWithOpenIdConnectRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** A name that identifies which configured OpenID Connect provider relationship to use. Maximum 100 characters. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString ConnectionId;
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /**
     * The JSON Web token (JWT) returned by the identity provider after login. Represented as the id_token field in the
     * identity provider's response.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString IdToken;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
};

/**
 * Username and password lengths are provided for information purposes. The server will validate that data passed in
 * conforms to the field definition and report errors appropriately. It is recommended that developers not perform this
 * validation locally, so that future updates to the username or password do not require client updates.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLoginWithPlayFabRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Password for the PlayFab account (6-100 characters) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString Password;
    /** PlayFab username for the account. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString Username;
};

/**
 * If this is the first time a user has signed in with the PlayStation Network account and CreateAccount is set to true, a
 * new PlayFab account will be created and linked to the PSN account. In this case, no email or username will be associated
 * with the PlayFab account. Otherwise, if no PlayFab account is linked to the PSN account, an error indicating this will
 * be returned, so that the title can guide the user through creation of a PlayFab account.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLoginWithPSNRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Auth code provided by the PSN OAuth provider. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString AuthCode;
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Id of the PSN issuer environment. If null, defaults to production environment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        int32 IssuerId = 0;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
    /** Redirect URI supplied to PSN when requesting an auth code */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString RedirectUri;
};

/**
 * Steam sign-in is accomplished with the Steam Session Ticket. More information on the Ticket can be found in the
 * Steamworks SDK, here: https://partner.steamgames.com/documentation/auth (requires sign-in). NOTE: For Steam
 * authentication to work, the title must be configured with the Steam Application ID and Web API Key in the PlayFab Game
 * Manager (under Steam in the Add-ons Marketplace). You can obtain a Web API Key from the Permissions page of any Group
 * associated with your App ID in the Steamworks site. If this is the first time a user has signed in with the Steam
 * account and CreateAccount is set to true, a new PlayFab account will be created and linked to the provided account's
 * Steam ID. In this case, no email or username will be associated with the PlayFab account. Otherwise, if no PlayFab
 * account is linked to the Steam account, an error indicating this will be returned, so that the title can guide the user
 * through creation of a PlayFab account.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLoginWithSteamRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
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

/**
 * More details regarding Twitch and their authentication system can be found at
 * https://github.com/justintv/Twitch-API/blob/master/authentication.md. Developers must provide the Twitch access token
 * that is generated using one of the Twitch authentication flows. PlayFab will use the title's unique Twitch Client ID to
 * authenticate the token and log in to the PlayFab system. If CreateAccount is set to true and there is not already a user
 * matched to the Twitch username that generated the token, then PlayFab will create a new account for this user and link
 * the ID. In this case, no email or username will be associated with the PlayFab account. If there is already a different
 * PlayFab user linked with this account, then an error will be returned.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLoginWithTwitchRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Token issued by Twitch's API for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString AccessToken;
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
};

/**
 * If this is the first time a user has signed in with the Xbox Live account and CreateAccount is set to true, a new
 * PlayFab account will be created and linked to the Xbox Live account. In this case, no email or username will be
 * associated with the PlayFab account. Otherwise, if no PlayFab account is linked to the Xbox Live account, an error
 * indicating this will be returned, so that the title can guide the user through creation of a PlayFab account.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientLoginWithXboxRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Automatically create a PlayFab account if one is not currently linked to this ID. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        bool CreateAccount = false;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Base64 encoded body that is encrypted with the Title's public RSA key (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString EncryptedRequest;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString PlayerSecret;
    /** Token provided by the Xbox Live SDK/XDK method GetTokenAndSignatureAsync("POST", "https://playfabapi.com/", ""). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        FString XboxToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientRegisterPlayFabUserRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Authentication Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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

/**
 * Each account must have a unique email address in the PlayFab service. Once created, the account may be associated with
 * additional accounts (Steam, Facebook, Game Center, etc.), allowing for added social network lists and achievements
 * systems.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientRegisterPlayFabUserResult : public FPlayFabResultCommon
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

/**
 * APIs that require signatures require that the player have a configured Player Secret Key that is used to sign all
 * requests. Players that don't have a secret will be blocked from making API calls until it is configured. To create a
 * signature header add a SHA256 hashed string containing UTF8 encoded JSON body as it will be sent to the server, the
 * current time in UTC formatted to ISO 8601, and the players secret formatted as 'body.date.secret'. Place the resulting
 * hash into the header X-PlayFab-Signature, along with a header X-PlayFab-Timestamp of the same UTC timestamp used in the
 * signature.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientSetPlayerSecretRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FClientSetPlayerSecretResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Character Data
//////////////////////////////////////////////////////

/**
 * Data is stored as JSON key-value pairs. If the Keys parameter is provided, the data object returned will only contain
 * the data specific to the indicated Keys. Otherwise, the full set of custom character data will be returned.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetCharacterDataRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FClientGetCharacterDataResult : public FPlayFabResultCommon
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

/**
 * This function performs an additive update of the arbitrary strings containing the custom data for the character. In
 * updating the custom data object, keys which already exist in the object will have their values overwritten, while keys
 * with null values will be removed. New keys will be added, with the given values. No other key-value pairs will be
 * changed apart from those specified in the call.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUpdateCharacterDataRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Character Data Models")
        FString CharacterId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Character Data Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may
     * not begin with a '!' character or be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Character Data Models")
        UPlayFabJsonObject* Data = nullptr;
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
struct PLAYFAB_API FClientUpdateCharacterDataResult : public FPlayFabResultCommon
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

/** Returns a list of every character that currently belongs to a user. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientListUsersCharactersRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientListUsersCharactersResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The requested list of characters. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        TArray<UPlayFabJsonObject*> Characters;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetCharacterLeaderboardRequest : public FPlayFabRequestCommon
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

/** Note that the Position of the character in the results is for the overall leaderboard. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetCharacterLeaderboardResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ordered list of leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        TArray<UPlayFabJsonObject*> Leaderboard;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetCharacterStatisticsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        FString CharacterId;
};

/** In addition to being available for use by the title, the statistics are used for all leaderboard operations in PlayFab. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetCharacterStatisticsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The requested character statistics. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        UPlayFabJsonObject* CharacterStatistics = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetLeaderboardAroundCharacterRequest : public FPlayFabRequestCommon
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

/**
 * Note: When calling 'GetLeaderboardAround...' APIs, the position of the character defaults to 0 when the character does
 * not have the corresponding statistic.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetLeaderboardAroundCharacterResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ordered list of leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        TArray<UPlayFabJsonObject*> Leaderboard;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetLeaderboardForUsersCharactersRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the title-specific statistic for the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        FString StatisticName;
};

/**
 * NOTE: The position of the character in the results is relative to the other characters for that specific user. This mean
 * the values will always be between 0 and one less than the number of characters returned regardless of the size of the
 * actual leaderboard.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetLeaderboardForUsersCharactersResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ordered list of leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        TArray<UPlayFabJsonObject*> Leaderboard;
};

/**
 * Grants a character to the user of the type specified by the item ID. The user must already have an instance of this item
 * in their inventory in order to allow character creation. This item can come from a purchase or grant, which must be done
 * before calling to create the character.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGrantCharacterToUserRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version from which items are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        FString CatalogVersion;
    /** Non-unique display name of the character being granted (1-40 characters in length). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        FString CharacterName;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Catalog item identifier of the item in the user's inventory that corresponds to the character in the catalog to be
     * created.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        FString ItemId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGrantCharacterToUserResult : public FPlayFabResultCommon
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

/**
 * Enable this option with the 'Allow Client to Post Player Statistics' option in PlayFab GameManager for your title.
 * However, this is not best practice, as this data will no longer be safely controlled by the server. This operation is
 * additive. Character Statistics not currently defined will be added, while those already defined will be updated with the
 * given values. All other user statistics will remain unchanged. Character statistics are used by the
 * character-leaderboard apis, and accessible for custom game-logic.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUpdateCharacterStatisticsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        FString CharacterId;
    /** Statistics to be updated with the provided values, in the Key(string), Value(int) pattern. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        UPlayFabJsonObject* CharacterStatistics = nullptr;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Characters Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUpdateCharacterStatisticsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetContentDownloadUrlRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FClientGetContentDownloadUrlResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FClientAddFriendRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FClientAddFriendResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** True if the friend request was processed successfully. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Friend List Management Models")
        bool Created = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetFriendsListRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Friend List Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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

/**
 * If any additional services are queried for the user's friends, those friends who also have a PlayFab account registered
 * for the title will be returned in the results. For Facebook, user has to have logged into the title's Facebook app
 * recently, and only friends who also plays this game will be included. For Xbox Live, user has to have logged into the
 * Xbox Live recently, and only friends who also play this game will be included.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetFriendsListResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of friends found. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Friend List Management Models")
        TArray<UPlayFabJsonObject*> Friends;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientRemoveFriendRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** PlayFab identifier of the friend account which is to be removed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Friend List Management Models")
        FString FriendPlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientRemoveFriendResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * This operation is not additive. It will completely replace the tag list for the specified user. Please note that only
 * users in the PlayFab friends list can be assigned tags. Attempting to set a tag on a friend only included in the friends
 * list from a social site integration (such as Facebook or Steam) will return the AccountNotFound error.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientSetFriendTagsRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FClientSetFriendTagsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Matchmaking
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientCurrentGamesRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FClientCurrentGamesResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FClientGameServerRegionsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** version of game server for which stats are being requested */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString BuildVersion;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGameServerRegionsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** array of regions found matching the request parameters */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        TArray<UPlayFabJsonObject*> Regions;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientMatchmakeRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Build version to match against. [Note: Required if LobbyId is not specified] */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString BuildVersion;
    /** Character to use for stats based matching. Leave null to use account stats. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        FString CharacterId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
struct PLAYFAB_API FClientMatchmakeResult : public FPlayFabResultCommon
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

/** This API must be enabled for use as an option in the game manager website. It is disabled by default. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientStartGameRequest : public FPlayFabRequestCommon
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
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Matchmaking Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
struct PLAYFAB_API FClientStartGameResult : public FPlayFabResultCommon
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

/**
 * More information can be found on configuring your game for the Google Cloud Messaging service in the Google developer
 * documentation, here: http://developer.android.com/google/gcm/client.html. The steps to configure and send Push
 * Notifications is described in the PlayFab tutorials, here:
 * https://docs.microsoft.com/gaming/playfab/features/engagement/push-notifications/quickstart.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientAndroidDevicePushNotificationRegistrationRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FClientAndroidDevicePushNotificationRegistrationResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientConsumeMicrosoftStoreEntitlementsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version to use */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString CatalogVersion;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Marketplace specific payload containing details to fetch in app purchase transactions */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        UPlayFabJsonObject* MarketplaceSpecificData = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientConsumeMicrosoftStoreEntitlementsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Details for the items purchased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        TArray<UPlayFabJsonObject*> Items;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientConsumePS5EntitlementsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version to use */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString CatalogVersion;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Marketplace specific payload containing details to fetch in app purchase transactions */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        UPlayFabJsonObject* MarketplaceSpecificData = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientConsumePS5EntitlementsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Details for the items purchased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        TArray<UPlayFabJsonObject*> Items;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientConsumePSNEntitlementsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Which catalog to match granted entitlements against. If null, defaults to title default catalog */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString CatalogVersion;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Id of the PSN service label to consume entitlements from */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        int32 ServiceLabel = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientConsumePSNEntitlementsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of items granted to the player as a result of consuming entitlements. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        TArray<UPlayFabJsonObject*> ItemsGranted;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientConsumeXboxEntitlementsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version to use */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString CatalogVersion;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Token provided by the Xbox Live SDK/XDK method GetTokenAndSignatureAsync("POST", "https://playfabapi.com/", ""). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString XboxToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientConsumeXboxEntitlementsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Details for the items purchased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        TArray<UPlayFabJsonObject*> Items;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientRefreshPSNAuthTokenRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Auth code returned by PSN OAuth system. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString AuthCode;
    /** Id of the PSN issuer environment. If null, defaults to production environment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        int32 IssuerId = 0;
    /** Redirect URI supplied to PSN when requesting an auth code */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString RedirectUri;
};

/**
 * The steps to configure and send Push Notifications is described in the PlayFab tutorials, here:
 * https://docs.microsoft.com/gaming/playfab/features/engagement/push-notifications/quickstart
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientRegisterForIOSPushNotificationRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FClientRegisterForIOSPushNotificationResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * The title should obtain a refresh receipt via restoreCompletedTransactions in the SKPaymentQueue of the Apple StoreKit
 * and pass that in to this call. The resultant receipt contains new receipt instances for all non-consumable goods
 * previously purchased by the user. This API call iterates through every purchase in the receipt and restores the items if
 * they still exist in the catalog and can be validated.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientRestoreIOSPurchasesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version of the restored items. If null, defaults to primary catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString CatalogVersion;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Base64 encoded receipt data, passed back by the App Store as a result of a successful purchase. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString ReceiptData;
};

/** Once verified, the valid items will be restored into the user's inventory. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientRestoreIOSPurchasesResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Fulfilled inventory items and recorded purchases in fulfillment of the validated receipt transactions. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        TArray<UPlayFabJsonObject*> Fulfillments;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientValidateAmazonReceiptRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version of the fulfilled items. If null, defaults to the primary catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString CatalogVersion;
    /** Currency used to pay for the purchase (ISO 4217 currency code). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString CurrencyCode;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Amount of the stated currency paid, in centesimal units. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        int32 PurchasePrice = 0;
    /** ReceiptId returned by the Amazon App Store in-app purchase API */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString ReceiptId;
    /** AmazonId of the user making the purchase as returned by the Amazon App Store in-app purchase API */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString UserId;
};

/** Once verified, the catalog item matching the Amazon item name will be added to the user's inventory. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientValidateAmazonReceiptResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Fulfilled inventory items and recorded purchases in fulfillment of the validated receipt transactions. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        TArray<UPlayFabJsonObject*> Fulfillments;
};

/**
 * The packageName and productId are defined in the GooglePlay store. The productId must match the ItemId of the inventory
 * item in the PlayFab catalog for the title. This enables the PlayFab service to securely validate that the purchase is
 * for the correct item, in order to prevent uses from passing valid receipts as being for more expensive items (passing a
 * receipt for a 99-cent purchase as being for a $19.99 purchase, for example). Each receipt may be validated only once to
 * avoid granting the same item over and over from a single purchase.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientValidateGooglePlayPurchaseRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version of the fulfilled items. If null, defaults to the primary catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString CatalogVersion;
    /** Currency used to pay for the purchase (ISO 4217 currency code). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString CurrencyCode;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Amount of the stated currency paid, in centesimal units. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        int32 PurchasePrice = 0;
    /** Original JSON string returned by the Google Play IAB API. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString ReceiptJson;
    /** Signature returned by the Google Play IAB API. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString Signature;
};

/**
 * Once verified, the catalog item (ItemId) matching the GooglePlay store item (productId) will be added to the user's
 * inventory.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientValidateGooglePlayPurchaseResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Fulfilled inventory items and recorded purchases in fulfillment of the validated receipt transactions. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        TArray<UPlayFabJsonObject*> Fulfillments;
};

/**
 * The CurrencyCode and PurchasePrice must match the price which was set up for the item in the Apple store. In addition,
 * The ItemId of the inventory in the PlayFab Catalog must match the Product ID as it was set up in the Apple store. This
 * enables the PlayFab service to securely validate that the purchase is for the correct item, in order to prevent uses
 * from passing valid receipts as being for more expensive items (passing a receipt for a 99-cent purchase as being for a
 * $19.99 purchase, for example).
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientValidateIOSReceiptRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version of the fulfilled items. If null, defaults to the primary catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString CatalogVersion;
    /** Currency used to pay for the purchase (ISO 4217 currency code). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString CurrencyCode;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Amount of the stated currency paid, in centesimal units. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        int32 PurchasePrice = 0;
    /** Base64 encoded receipt data, passed back by the App Store as a result of a successful purchase. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString ReceiptData;
};

/** Once verified, the catalog item matching the iTunes item name will be added to the user's inventory. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientValidateIOSReceiptResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Fulfilled inventory items and recorded purchases in fulfillment of the validated receipt transactions. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        TArray<UPlayFabJsonObject*> Fulfillments;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientValidateWindowsReceiptRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version of the fulfilled items. If null, defaults to the primary catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString CatalogVersion;
    /** Currency used to pay for the purchase (ISO 4217 currency code). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString CurrencyCode;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Amount of the stated currency paid, in centesimal units. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        int32 PurchasePrice = 0;
    /** XML Receipt returned by the Windows App Store in-app purchase API */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        FString Receipt;
};

/** Once verified, the catalog item matching the Product name will be added to the user's inventory. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientValidateWindowsReceiptResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Fulfilled inventory items and recorded purchases in fulfillment of the validated receipt transactions. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Platform Specific Methods Models")
        TArray<UPlayFabJsonObject*> Fulfillments;
};


///////////////////////////////////////////////////////
// Player Data Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetFriendLeaderboardRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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

/** Note: the user's Position is relative to the overall leaderboard. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetLeaderboardResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FClientGetFriendLeaderboardAroundPlayerRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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

/**
 * Note: When calling 'GetLeaderboardAround...' APIs, the position of the user defaults to 0 when the user does not have
 * the corresponding statistic.If Facebook friends are included, make sure the access token from previous LoginWithFacebook
 * call is still valid and not expired. If Xbox Live friends are included, make sure the access token from the previous
 * LoginWithXbox call is still valid and not expired.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetFriendLeaderboardAroundPlayerResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FClientGetLeaderboardRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
struct PLAYFAB_API FClientGetLeaderboardAroundPlayerRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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

/**
 * Note: When calling 'GetLeaderboardAround...' APIs, the position of the user defaults to 0 when the user does not have
 * the corresponding statistic.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetLeaderboardAroundPlayerResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FClientGetPlayerStatisticsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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

/** In addition to being available for use by the title, the statistics are used for all leaderboard operations in PlayFab. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayerStatisticsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** User statistics for the requested user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        TArray<UPlayFabJsonObject*> Statistics;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayerStatisticVersionsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** unique name of the statistic */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        FString StatisticName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayerStatisticVersionsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** version change history of the statistic */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        TArray<UPlayFabJsonObject*> StatisticVersions;
};

/**
 * Data is stored as JSON key-value pairs. Every time the data is updated via any source, the version counter is
 * incremented. If the Version parameter is provided, then this call will only return data if the current version on the
 * system is greater than the value provided. If the Keys parameter is provided, the data object returned will only contain
 * the data specific to the indicated Keys. Otherwise, the full set of custom user data will be returned.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetUserDataRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FClientGetUserDataResult : public FPlayFabResultCommon
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

/**
 * Enable this option with the 'Allow Client to Post Player Statistics' option in PlayFab GameManager for your title.
 * However, this is not best practice, as this data will no longer be safely controlled by the server. This operation is
 * additive. Statistics not currently defined will be added, while those already defined will be updated with the given
 * values. All other user statistics will remain unchanged. Note that if the statistic is intended to have a reset period,
 * the UpdatePlayerStatisticDefinition API call can be used to define that reset period. Once a statistic has been
 * versioned (reset), the now-previous version can still be written to for up a short, pre-defined period (currently 10
 * seconds), using the Version parameter in this call.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUpdatePlayerStatisticsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Statistics to be updated with the provided values */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        TArray<UPlayFabJsonObject*> Statistics;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUpdatePlayerStatisticsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * This function performs an additive update of the arbitrary strings containing the custom data for the user. In updating
 * the custom data object, keys which already exist in the object will have their values overwritten, while keys with null
 * values will be removed. New keys will be added, with the given values. No other key-value pairs will be changed apart
 * from those specified in the call.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUpdateUserDataRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may
     * not begin with a '!' character or be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Data Management Models")
        UPlayFabJsonObject* Data = nullptr;
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
struct PLAYFAB_API FClientUpdateUserDataResult : public FPlayFabResultCommon
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

/** This API must be enabled for use as an option in the game manager website. It is disabled by default. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientAddUserVirtualCurrencyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Amount to be added to the user balance of the specified virtual currency. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        int32 Amount = 0;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Name of the virtual currency which is to be incremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString VirtualCurrency;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientModifyUserVirtualCurrencyResult : public FPlayFabResultCommon
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

/**
 * The final step in the purchasing process, this API finalizes the purchase with the payment provider, where applicable,
 * adding virtual goods to the player inventory (including random drop table resolution and recursive addition of bundled
 * items) and adjusting virtual currency balances for funds used or added. Note that this is a pull operation, and should
 * be polled regularly when a purchase is in progress. Please note that the processing time for inventory grants and
 * purchases increases fractionally the more items are in the inventory, and the more items are in the grant/purchase
 * operation.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientConfirmPurchaseRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Purchase order identifier returned from StartPurchase. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString OrderId;
};

/**
 * When the FailedByPaymentProvider error is returned, it's important to check the ProviderErrorCode, ProviderErrorMessage,
 * and ProviderErrorDetails to understand the specific reason the payment was rejected, as in some rare cases, this may
 * mean that the provider hasn't completed some operation required to finalize the purchase.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientConfirmPurchaseResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FClientConsumeItemRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString CharacterId;
    /** Number of uses to consume from the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        int32 ConsumeCount = 0;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Unique instance identifier of the item to be consumed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString ItemInstanceId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientConsumeItemResult : public FPlayFabResultCommon
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

/**
 * All items currently in the character inventory will be returned, irrespective of how they were acquired (via purchasing,
 * grants, coupons, etc.). Items that are expired, fully consumed, or are no longer valid are not considered to be in the
 * user's current inventory, and so will not be not included. Also returns their virtual currency balances.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetCharacterInventoryRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Used to limit results to only those from a specific catalog version. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString CatalogVersion;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString CharacterId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetCharacterInventoryResult : public FPlayFabResultCommon
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
        UPlayFabJsonObject* VirtualCurrency = nullptr;
    /** Array of remaining times and timestamps for virtual currencies. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrencyRechargeTimes = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPaymentTokenRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The name of service to provide the payment token. Allowed Values are: xsolla */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString TokenProvider;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPaymentTokenResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FClientGetPurchaseRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Purchase order identifier. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString OrderId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPurchaseResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FClientGetUserInventoryRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

/**
 * All items currently in the user inventory will be returned, irrespective of how they were acquired (via purchasing,
 * grants, coupons, etc.). Items that are expired, fully consumed, or are no longer valid are not considered to be in the
 * user's current inventory, and so will not be not included.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetUserInventoryResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of inventory items belonging to the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        TArray<UPlayFabJsonObject*> Inventory;
    /** Array of virtual currency balance(s) belonging to the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrency = nullptr;
    /** Array of remaining times and timestamps for virtual currencies. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrencyRechargeTimes = nullptr;
};

/**
 * This is the second step in the purchasing process, initiating the purchase transaction with the payment provider (if
 * applicable). For payment provider scenarios, the title should next present the user with the payment provider'sinterface
 * for payment. Once the player has completed the payment with the provider, the title should call ConfirmPurchase
 * tofinalize the process and add the appropriate items to the player inventory.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientPayForPurchaseRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Currency to use to fund the purchase. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString Currency;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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

/**
 * For web-based payment providers, this operation returns the URL to which the user should be directed inorder to approve
 * the purchase. Items added to the user inventory as a result of this operation will be marked as unconfirmed.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientPayForPurchaseResult : public FPlayFabResultCommon
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
        UPlayFabJsonObject* VCAmount = nullptr;
    /** Current virtual currency balances for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrency = nullptr;
};

/**
 * Please note that the processing time for inventory grants and purchases increases fractionally the more items are in the
 * inventory, and the more items are in the grant/purchase operation (with each item in a bundle being a distinct add).
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientPurchaseItemRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version for the items to be purchased (defaults to most recent version. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString CatalogVersion;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString CharacterId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
struct PLAYFAB_API FClientPurchaseItemResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Details for the items purchased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        TArray<UPlayFabJsonObject*> Items;
};

/**
 * Coupon codes can be created for any item, or set of items, in the catalog for the title. This operation causes the
 * coupon to be consumed, and the specific items to be awarded to the user. Attempting to re-use an already consumed code,
 * or a code which has not yet been created in the service, will result in an error.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientRedeemCouponRequest : public FPlayFabRequestCommon
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
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientRedeemCouponResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Items granted to the player as a result of redeeming the coupon. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        TArray<UPlayFabJsonObject*> GrantedItems;
};

/**
 * This is the first step in the purchasing process. For security purposes, once the order (or "cart") has been created,
 * additional inventory objects may no longer be added. In addition, inventory objects will be locked to the current
 * prices, regardless of any subsequent changes at the catalog level which may occur during the next two steps.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientStartPurchaseRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version for the items to be purchased. Defaults to most recent catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString CatalogVersion;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Array of items to purchase. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        TArray<UPlayFabJsonObject*> Items;
    /** Store through which to purchase items. If not set, prices will be pulled from the catalog itself. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString StoreId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientStartPurchaseResult : public FPlayFabResultCommon
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
        UPlayFabJsonObject* VirtualCurrencyBalances = nullptr;
};

/** This API must be enabled for use as an option in the game manager website. It is disabled by default. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientSubtractUserVirtualCurrencyRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Amount to be subtracted from the user balance of the specified virtual currency. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        int32 Amount = 0;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Name of the virtual currency which is to be decremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString VirtualCurrency;
};

/** Specify the container and optionally the catalogVersion for the container to open */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlockContainerInstanceRequest : public FPlayFabRequestCommon
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
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * ItemInstanceId of the key that will be consumed by unlocking this container. If the container requires a key, this
     * parameter is required.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        FString KeyItemInstanceId;
};

/** The items and vc found within the container. These will be added and stacked in the appropriate inventory. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlockContainerItemResult : public FPlayFabResultCommon
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
        UPlayFabJsonObject* VirtualCurrency = nullptr;
};

/** Specify the type of container to open and optionally the catalogVersion for the container to open */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientUnlockContainerItemRequest : public FPlayFabRequestCommon
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
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Player Item Management Models")
        UPlayFabJsonObject* CustomTags = nullptr;
};


///////////////////////////////////////////////////////
// PlayStream
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayerSegmentsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayerSegmentsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of segments the requested player currently belongs to. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | PlayStream Models")
        TArray<UPlayFabJsonObject*> Segments;
};

/**
 * This API will return a list of canonical tags which includes both namespace and tag's name. If namespace is not
 * provided, the result is a list of all canonical tags. TagName can be used for segmentation and Namespace is limited to
 * 128 characters.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayerTagsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | PlayStream Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Optional namespace to filter results by */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | PlayStream Models")
        FString Namespace;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | PlayStream Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayerTagsResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FClientExecuteCloudScriptRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Server-Side Cloud Script Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
struct PLAYFAB_API FClientExecuteCloudScriptResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FClientAddSharedGroupMembersRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FClientAddSharedGroupMembersResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * If SharedGroupId is specified, the service will attempt to create a group with that identifier, and will return an error
 * if it is already in use. If no SharedGroupId is specified, a random identifier will be assigned.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientCreateSharedGroupRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the shared group (a random identifier will be assigned, if one is not specified). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Shared Group Data Models")
        FString SharedGroupId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientCreateSharedGroupResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Shared Group Data Models")
        FString SharedGroupId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetSharedGroupDataRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FClientGetSharedGroupDataResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FClientRemoveSharedGroupMembersRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FClientRemoveSharedGroupMembersResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FClientUpdateSharedGroupDataRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Shared Group Data Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may
     * not begin with a '!' character or be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Shared Group Data Models")
        UPlayFabJsonObject* Data = nullptr;
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
struct PLAYFAB_API FClientUpdateSharedGroupDataResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Title-Wide Data Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetCatalogItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Which catalog is being requested. If null, uses the default catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        FString CatalogVersion;
};

/**
 * If CatalogVersion is not specified, only inventory items associated with the most recent version of the catalog will be
 * returned.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetCatalogItemsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of items which can be purchased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> Catalog;
};

/**
 * This API is designed to return publisher-specific values which can be read, but not written to, by the client. This data
 * is shared across all titles assigned to a particular publisher, and can be used for cross-game coordination. Only titles
 * assigned to a publisher can use this API. For more information email helloplayfab@microsoft.com. Note that there may up
 * to a minute delay in between updating title data and this API call returning the newest value.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPublisherDataRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** array of keys to get back data from the Publisher data blob, set by the admin tools */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        FString Keys;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPublisherDataResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** a dictionary object of key / value pairs */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        UPlayFabJsonObject* Data = nullptr;
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
struct PLAYFAB_API FClientGetStoreItemsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version to store items from. Use default catalog version if null */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        FString CatalogVersion;
    /** Unqiue identifier for the store which is being requested. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        FString StoreId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetStoreItemsResult : public FPlayFabResultCommon
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

/**
 * This query retrieves the current time from one of the servers in PlayFab. Please note that due to clock drift between
 * servers, there is a potential variance of up to 5 seconds.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetTimeRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/** Time is always returned as Coordinated Universal Time (UTC). */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetTimeResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Current server time when the request was received, in UTC */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        FString Time;
};

/**
 * This API is designed to return title specific values which can be read, but not written to, by the client. For example,
 * a developer could choose to store values which modify the user experience, such as enemy spawn rates, weapon strengths,
 * movement speeds, etc. This allows a developer to update the title without the need to create, test, and ship a new
 * build. If the player belongs to an experiment variant that uses title data overrides, the overrides are applied
 * automatically and returned with the title data. Note that there may up to a minute delay in between updating title data
 * and this API call returning the newest value.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetTitleDataRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Specific keys to search for in the title data (leave null to get all keys) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        FString Keys;
    /**
     * Optional field that specifies the name of an override. This value is ignored when used by the game client; otherwise,
     * the overrides are applied automatically to the title data.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        FString OverrideLabel;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetTitleDataResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** a dictionary object of key / value pairs */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        UPlayFabJsonObject* Data = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetTitleNewsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Limits the results to the last n entries. Defaults to 10 if not set. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Title-Wide Data Management Models")
        int32 Count = 0;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetTitleNewsResult : public FPlayFabResultCommon
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
struct PLAYFAB_API FClientAcceptTradeRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FClientAcceptTradeResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Details about trade which was just accepted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Trading Models")
        UPlayFabJsonObject* Trade = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientCancelTradeRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Trade identifier. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Trading Models")
        FString TradeId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientCancelTradeResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Details about trade which was just canceled. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Trading Models")
        UPlayFabJsonObject* Trade = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayerTradesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Returns only trades with the given status. If null, returns all trades. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Trading Models")
        ETradeStatus StatusFilter;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientGetPlayerTradesResponse : public FPlayFabResultCommon
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
struct PLAYFAB_API FClientGetTradeStatusRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FClientGetTradeStatusResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information about the requested trade. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Trading Models")
        UPlayFabJsonObject* Trade = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FClientOpenTradeRequest : public FPlayFabRequestCommon
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
struct PLAYFAB_API FClientOpenTradeResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The information about the trade that was just opened. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Client | Trading Models")
        UPlayFabJsonObject* Trade = nullptr;
};

