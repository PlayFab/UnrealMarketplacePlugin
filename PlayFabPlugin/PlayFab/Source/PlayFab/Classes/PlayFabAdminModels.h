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
#include "PlayFabAdminModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Admin API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FAdminBanUsersRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of ban requests to be applied. Maximum 100. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        TArray<UPlayFabJsonObject*> Bans;
};

USTRUCT(BlueprintType)
struct FAdminBanUsersResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information on the bans that were applied */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        TArray<UPlayFabJsonObject*> BanData;
};

USTRUCT(BlueprintType)
struct FAdminDeleteMasterPlayerAccountRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FAdminDeleteMasterPlayerAccountResult
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

USTRUCT(BlueprintType)
struct FAdminDeletePlayerRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FAdminDeletePlayerResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminDeleteTitleRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminDeleteTitleResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminExportMasterPlayerDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FAdminExportMasterPlayerDataResult
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

USTRUCT(BlueprintType)
struct FAdminGetPlayedTitleListRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FAdminGetPlayedTitleListResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of titles the player has played */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString TitleIds;
};

USTRUCT(BlueprintType)
struct FAdminGetPlayerIdFromAuthTokenRequest
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
struct FAdminGetPlayerIdFromAuthTokenResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** The player ID from the token passed in */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FAdminGetPlayerProfileRequest
{
    GENERATED_USTRUCT_BODY()
public:
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
struct FAdminGetPlayerProfileResult
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

USTRUCT(BlueprintType)
struct FAdminLookupUserAccountInfoRequest
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
struct FAdminLookupUserAccountInfoResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** User info for the user matching the request */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        UPlayFabJsonObject* UserInfo = nullptr;
};

USTRUCT(BlueprintType)
struct FAdminGetUserBansRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FAdminGetUserBansResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information about the bans */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        TArray<UPlayFabJsonObject*> BanData;
};

USTRUCT(BlueprintType)
struct FAdminResetPasswordRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The new password for the player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString Password;
    /** The token of the player requesting the password reset. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString Token;
};

USTRUCT(BlueprintType)
struct FAdminResetPasswordResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminRevokeAllBansForUserRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FAdminRevokeAllBansForUserResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information on the bans that were revoked. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        TArray<UPlayFabJsonObject*> BanData;
};

USTRUCT(BlueprintType)
struct FAdminRevokeBansRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ids of the bans to be revoked. Maximum 100. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString BanIds;
};

USTRUCT(BlueprintType)
struct FAdminRevokeBansResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information on the bans that were revoked */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        TArray<UPlayFabJsonObject*> BanData;
};

USTRUCT(BlueprintType)
struct FAdminSendAccountRecoveryEmailRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** User email address attached to their account */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString Email;
    /** The email template id of the account recovery email template to send. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString EmailTemplateId;
};

USTRUCT(BlueprintType)
struct FAdminSendAccountRecoveryEmailResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminUpdateBansRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of bans to be updated. Maximum 100. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        TArray<UPlayFabJsonObject*> Bans;
};

USTRUCT(BlueprintType)
struct FAdminUpdateBansResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information on the bans that were updated */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        TArray<UPlayFabJsonObject*> BanData;
};

USTRUCT(BlueprintType)
struct FAdminUpdateUserTitleDisplayNameRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** New title display name for the user - must be between 3 and 25 characters */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString DisplayName;
    /** PlayFab unique identifier of the user whose title specific display name is to be changed */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FAdminUpdateUserTitleDisplayNameResult
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
struct FAdminCreatePlayerSharedSecretRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Friendly name for this key */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString FriendlyName;
};

USTRUCT(BlueprintType)
struct FAdminCreatePlayerSharedSecretResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** The player shared secret to use when calling Client/GetTitlePublicKey */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString SecretKey;
};

USTRUCT(BlueprintType)
struct FAdminDeletePlayerSharedSecretRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The shared secret key to delete */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString SecretKey;
};

USTRUCT(BlueprintType)
struct FAdminDeletePlayerSharedSecretResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminGetPlayerSharedSecretsRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminGetPlayerSharedSecretsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** The player shared secret to use when calling Client/GetTitlePublicKey */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        TArray<UPlayFabJsonObject*> SharedSecrets;
};

USTRUCT(BlueprintType)
struct FAdminGetPolicyRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The name of the policy to read. Only supported name is 'ApiPolicy'. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString PolicyName;
};

USTRUCT(BlueprintType)
struct FAdminGetPolicyResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** The name of the policy read. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString PolicyName;
    /** The statements in the requested policy. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        TArray<UPlayFabJsonObject*> Statements;
};

USTRUCT(BlueprintType)
struct FAdminSetPlayerSecretRequest
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
struct FAdminSetPlayerSecretResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminUpdatePlayerSharedSecretRequest
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
struct FAdminUpdatePlayerSharedSecretResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminUpdatePolicyRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Whether to overwrite or append to the existing policy. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        bool OverwritePolicy = false;
    /** The name of the policy being updated. Only supported name is 'ApiPolicy' */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        FString PolicyName;
    /** The new statements to include in the policy. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Authentication Models")
        TArray<UPlayFabJsonObject*> Statements;
};

USTRUCT(BlueprintType)
struct FAdminUpdatePolicyResponse
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

USTRUCT(BlueprintType)
struct FAdminResetCharacterStatisticsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Characters Models")
        FString CharacterId;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Characters Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FAdminResetCharacterStatisticsResult
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FAdminBlankResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminDeleteContentRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Key of the content item to be deleted */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Content Models")
        FString Key;
};

USTRUCT(BlueprintType)
struct FAdminGetContentListRequest
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
struct FAdminGetContentListResult
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
struct FAdminGetContentUploadUrlRequest
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
struct FAdminGetContentUploadUrlResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** URL for uploading content via HTTP PUT method. The URL will expire in approximately one hour. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Content Models")
        FString URL;
};


///////////////////////////////////////////////////////
// Custom Server Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FAdminAddServerBuildRequest
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
struct FAdminAddServerBuildResult
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
struct FAdminGetServerBuildInfoRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** unique identifier of the previously uploaded build executable for which information is being requested */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString BuildId;
};

/** Information about a particular server build */
USTRUCT(BlueprintType)
struct FAdminGetServerBuildInfoResult
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
struct FAdminGetServerBuildUploadURLRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** unique identifier of the game server build to upload */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString BuildId;
};

USTRUCT(BlueprintType)
struct FAdminGetServerBuildUploadURLResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** pre-authorized URL for uploading the game server build package */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString URL;
};

USTRUCT(BlueprintType)
struct FAdminListBuildsRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminListBuildsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** array of uploaded game server builds */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        TArray<UPlayFabJsonObject*> Builds;
};

USTRUCT(BlueprintType)
struct FAdminModifyServerBuildRequest
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
struct FAdminModifyServerBuildResult
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
struct FAdminRemoveServerBuildRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** unique identifier of the previously uploaded build executable to be removed */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Custom Server Management Models")
        FString BuildId;
};

USTRUCT(BlueprintType)
struct FAdminRemoveServerBuildResult
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Matchmaking
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FAdminGetMatchmakerGameInfoRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** unique identifier of the lobby for which info is being requested */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Matchmaking Models")
        FString LobbyId;
};

USTRUCT(BlueprintType)
struct FAdminGetMatchmakerGameInfoResult
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
    /** IPV4 address of the game server instance */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Matchmaking Models")
        FString ServerAddress;
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

USTRUCT(BlueprintType)
struct FAdminGetMatchmakerGameModesRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** previously uploaded build version for which game modes are being requested */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Matchmaking Models")
        FString BuildVersion;
};

USTRUCT(BlueprintType)
struct FAdminGetMatchmakerGameModesResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** array of game modes available for the specified build */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Matchmaking Models")
        TArray<UPlayFabJsonObject*> GameModes;
};

USTRUCT(BlueprintType)
struct FAdminModifyMatchmakerGameModesRequest
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
struct FAdminModifyMatchmakerGameModesResult
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Player Data Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FAdminCreatePlayerStatisticDefinitionRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** the aggregation method to use in updating the statistic (defaults to last) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        EStatisticAggregationMethod AggregationMethod;
    /** unique name of the statistic */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString StatisticName;
    /** interval at which the values of the statistic for all players are reset (resets begin at the next interval boundary) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        EStatisticResetIntervalOption VersionChangeInterval;
};

USTRUCT(BlueprintType)
struct FAdminCreatePlayerStatisticDefinitionResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** created statistic definition */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        UPlayFabJsonObject* Statistic = nullptr;
};

USTRUCT(BlueprintType)
struct FAdminGetDataReportRequest
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
struct FAdminGetDataReportResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** The URL where the requested report can be downloaded. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString DownloadUrl;
};

USTRUCT(BlueprintType)
struct FAdminGetPlayerStatisticDefinitionsRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminGetPlayerStatisticDefinitionsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** the player statistic definitions for the title */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        TArray<UPlayFabJsonObject*> Statistics;
};

USTRUCT(BlueprintType)
struct FAdminGetPlayerStatisticVersionsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** unique name of the statistic */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString StatisticName;
};

USTRUCT(BlueprintType)
struct FAdminGetPlayerStatisticVersionsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** version change history of the statistic */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        TArray<UPlayFabJsonObject*> StatisticVersions;
};

USTRUCT(BlueprintType)
struct FAdminGetUserDataRequest
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
struct FAdminGetUserDataResult
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

USTRUCT(BlueprintType)
struct FAdminIncrementPlayerStatisticVersionRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** unique name of the statistic */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString StatisticName;
};

USTRUCT(BlueprintType)
struct FAdminIncrementPlayerStatisticVersionResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** version change history of the statistic */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        UPlayFabJsonObject* StatisticVersion = nullptr;
};

USTRUCT(BlueprintType)
struct FAdminRefundPurchaseRequest
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
struct FAdminRefundPurchaseResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** The order's updated purchase status. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString PurchaseStatus;
};

USTRUCT(BlueprintType)
struct FAdminResetUserStatisticsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FAdminResetUserStatisticsResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminResolvePurchaseDisputeRequest
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
struct FAdminResolvePurchaseDisputeResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** The order's updated purchase status. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        FString PurchaseStatus;
};

USTRUCT(BlueprintType)
struct FAdminUpdatePlayerStatisticDefinitionRequest
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
struct FAdminUpdatePlayerStatisticDefinitionResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** updated statistic definition */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        UPlayFabJsonObject* Statistic = nullptr;
};

USTRUCT(BlueprintType)
struct FAdminUpdateUserDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may
     * not begin with a '!' character or be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        UPlayFabJsonObject* Data;
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
struct FAdminUpdateUserDataResult
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

USTRUCT(BlueprintType)
struct FAdminUpdateUserInternalDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may
     * not begin with a '!' character or be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Data Management Models")
        UPlayFabJsonObject* Data;
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
struct FAdminAddUserVirtualCurrencyRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Amount to be added to the user balance of the specified virtual currency. Maximum VC balance is Int32 (2,147,483,647).
     * Any increase over this value will be discarded.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        int32 Amount = 0;
    /** PlayFab unique identifier of the user whose virtual currency balance is to be increased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        FString PlayFabId;
    /** Name of the virtual currency which is to be incremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        FString VirtualCurrency;
};

USTRUCT(BlueprintType)
struct FAdminModifyUserVirtualCurrencyResult
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

USTRUCT(BlueprintType)
struct FAdminCheckLimitedEditionItemAvailabilityRequest
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
struct FAdminCheckLimitedEditionItemAvailabilityResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** The amount of the specified resource remaining. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        int32 Amount = 0;
};

USTRUCT(BlueprintType)
struct FAdminGetUserInventoryRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FAdminGetUserInventoryResult
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
        UPlayFabJsonObject* VirtualCurrency;
    /** Array of remaining times and timestamps for virtual currencies. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrencyRechargeTimes = nullptr;
};

USTRUCT(BlueprintType)
struct FAdminGrantItemsToUsersRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version from which items are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        FString CatalogVersion;
    /** Array of items to grant and the users to whom the items are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        TArray<UPlayFabJsonObject*> ItemGrants;
};

USTRUCT(BlueprintType)
struct FAdminGrantItemsToUsersResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of items granted to users. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        TArray<UPlayFabJsonObject*> ItemGrantResults;
};

USTRUCT(BlueprintType)
struct FAdminIncrementLimitedEditionItemAvailabilityRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Amount to increase availability by. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        int32 Amount = 0;
    /** Which catalog is being updated. If null, uses the default catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        FString CatalogVersion;
    /** The item which needs more availability. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        FString ItemId;
};

USTRUCT(BlueprintType)
struct FAdminIncrementLimitedEditionItemAvailabilityResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminRevokeInventoryItemRequest
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
struct FAdminRevokeInventoryResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminRevokeInventoryItemsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of player items to revoke, between 1 and 25 items. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        TArray<UPlayFabJsonObject*> Items;
};

USTRUCT(BlueprintType)
struct FAdminRevokeInventoryItemsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Collection of any errors that occurred during processing. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        TArray<UPlayFabJsonObject*> Errors;
};

USTRUCT(BlueprintType)
struct FAdminSubtractUserVirtualCurrencyRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Amount to be subtracted from the user balance of the specified virtual currency. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Player Item Management Models")
        int32 Amount = 0;
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

USTRUCT(BlueprintType)
struct FAdminAddPlayerTagRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        FString PlayFabId;
    /** Unique tag for player profile. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        FString TagName;
};

USTRUCT(BlueprintType)
struct FAdminAddPlayerTagResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminGetAllSegmentsRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminGetAllSegmentsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of segments for this title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        TArray<UPlayFabJsonObject*> Segments;
};

USTRUCT(BlueprintType)
struct FAdminGetPlayerSegmentsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of segments the requested player currently belongs to. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        TArray<UPlayFabJsonObject*> Segments;
};

USTRUCT(BlueprintType)
struct FAdminGetPlayersSegmentsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FAdminGetPlayersInSegmentRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Continuation token if retrieving subsequent pages of results. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        FString ContinuationToken;
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
struct FAdminGetPlayersInSegmentResult
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

USTRUCT(BlueprintType)
struct FAdminGetPlayerTagsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Optional namespace to filter results by */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        FString Namespace;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FAdminGetPlayerTagsResult
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

USTRUCT(BlueprintType)
struct FAdminRemovePlayerTagRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        FString PlayFabId;
    /** Unique tag for player profile. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | PlayStream Models")
        FString TagName;
};

USTRUCT(BlueprintType)
struct FAdminRemovePlayerTagResult
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// ScheduledTask
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FAdminAbortTaskInstanceRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** ID of a task instance that is being aborted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        FString TaskInstanceId;
};

USTRUCT(BlueprintType)
struct FAdminEmptyResponse
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminCreateActionsOnPlayerSegmentTaskRequest
{
    GENERATED_USTRUCT_BODY()
public:
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
struct FAdminCreateTaskResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** ID of the task */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        FString TaskId;
};

USTRUCT(BlueprintType)
struct FAdminCreateCloudScriptTaskRequest
{
    GENERATED_USTRUCT_BODY()
public:
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

USTRUCT(BlueprintType)
struct FAdminDeleteTaskRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Specify either the task ID or the name of task to be deleted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        UPlayFabJsonObject* Identifier = nullptr;
};

USTRUCT(BlueprintType)
struct FAdminGetActionsOnPlayersInSegmentTaskInstanceResult
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

USTRUCT(BlueprintType)
struct FAdminGetTaskInstanceRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** ID of the requested task instance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        FString TaskInstanceId;
};

USTRUCT(BlueprintType)
struct FAdminGetCloudScriptTaskInstanceResult
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

USTRUCT(BlueprintType)
struct FAdminGetTaskInstancesRequest
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
struct FAdminGetTaskInstancesResult
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
struct FAdminGetTasksRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Provide either the task ID or the task name to get a specific task. If not specified, return all defined tasks. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        UPlayFabJsonObject* Identifier = nullptr;
};

USTRUCT(BlueprintType)
struct FAdminGetTasksResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Result tasks. Empty if there is no task found. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        TArray<UPlayFabJsonObject*> Tasks;
};

USTRUCT(BlueprintType)
struct FAdminRunTaskRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Provide either the task ID or the task name to run a task. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | ScheduledTask Models")
        UPlayFabJsonObject* Identifier = nullptr;
};

USTRUCT(BlueprintType)
struct FAdminRunTaskResult
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

USTRUCT(BlueprintType)
struct FAdminUpdateTaskRequest
{
    GENERATED_USTRUCT_BODY()
public:
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
// Server-Side Cloud Script
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FAdminGetCloudScriptRevisionRequest
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
struct FAdminGetCloudScriptRevisionResult
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
struct FAdminGetCloudScriptVersionsRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminGetCloudScriptVersionsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of versions */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Server-Side Cloud Script Models")
        TArray<UPlayFabJsonObject*> Versions;
};

USTRUCT(BlueprintType)
struct FAdminSetPublishedRevisionRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Revision to make the current published revision */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Server-Side Cloud Script Models")
        int32 Revision = 0;
    /** Version number */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Server-Side Cloud Script Models")
        int32 Version = 0;
};

USTRUCT(BlueprintType)
struct FAdminSetPublishedRevisionResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminUpdateCloudScriptRequest
{
    GENERATED_USTRUCT_BODY()
public:
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
struct FAdminUpdateCloudScriptResult
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

USTRUCT(BlueprintType)
struct FAdminSetPublisherDataRequest
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
struct FAdminSetPublisherDataResult
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Title-Wide Data Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FAdminAddNewsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Body text of the news */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString Body;
    /** Time this news was published. If not set, defaults to now. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString Timestamp;
    /** Title (headline) of the news item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString Title;
};

USTRUCT(BlueprintType)
struct FAdminAddNewsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique id of the new news item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString NewsId;
};

USTRUCT(BlueprintType)
struct FAdminAddVirtualCurrencyTypesRequest
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

USTRUCT(BlueprintType)
struct FAdminDeleteStoreRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** catalog version of the store to delete. If null, uses the default catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString CatalogVersion;
    /** unqiue identifier for the store which is to be deleted */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString StoreId;
};

USTRUCT(BlueprintType)
struct FAdminDeleteStoreResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminGetCatalogItemsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Which catalog is being requested. If null, uses the default catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString CatalogVersion;
};

USTRUCT(BlueprintType)
struct FAdminGetCatalogItemsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of items which can be purchased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> Catalog;
};

USTRUCT(BlueprintType)
struct FAdminGetPublisherDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** array of keys to get back data from the Publisher data blob, set by the admin tools */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString Keys;
};

USTRUCT(BlueprintType)
struct FAdminGetPublisherDataResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** a dictionary object of key / value pairs */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        UPlayFabJsonObject* Data;
};

USTRUCT(BlueprintType)
struct FAdminGetRandomResultTablesRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** catalog version to fetch tables from. Use default catalog version if null */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString CatalogVersion;
};

USTRUCT(BlueprintType)
struct FAdminGetRandomResultTablesResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** array of random result tables currently available */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        UPlayFabJsonObject* Tables = nullptr;
};

USTRUCT(BlueprintType)
struct FAdminGetStoreItemsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** catalog version to store items from. Use default catalog version if null */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString CatalogVersion;
    /** Unqiue identifier for the store which is being requested. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString StoreId;
};

USTRUCT(BlueprintType)
struct FAdminGetStoreItemsResult
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

USTRUCT(BlueprintType)
struct FAdminGetTitleDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Specific keys to search for in the title data (leave null to get all keys) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString Keys;
};

USTRUCT(BlueprintType)
struct FAdminGetTitleDataResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** a dictionary object of key / value pairs */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        UPlayFabJsonObject* Data;
};

USTRUCT(BlueprintType)
struct FAdminListVirtualCurrencyTypesRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminListVirtualCurrencyTypesResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of virtual currency names defined for this title */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> VirtualCurrencies;
};

USTRUCT(BlueprintType)
struct FAdminRemoveVirtualCurrencyTypesRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of virtual currencies to delete */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> VirtualCurrencies;
};

USTRUCT(BlueprintType)
struct FAdminUpdateCatalogItemsRequest
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
    /**
     * Should this catalog be set as the default catalog. Defaults to true. If there is currently no default catalog, this will
     * always set it.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        bool SetAsDefaultCatalog = false;
};

USTRUCT(BlueprintType)
struct FAdminUpdateCatalogItemsResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminUpdateStoreItemsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version of the store to update. If null, uses the default catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString CatalogVersion;
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
struct FAdminUpdateStoreItemsResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminSetTitleDataRequest
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
struct FAdminSetTitleDataResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FAdminSetupPushNotificationRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Credential is the Private Key for APNS/APNS_SANDBOX, and the API Key for GCM */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString Credential;
    /** for APNS, this is the PlatformPrincipal (SSL Certificate) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString Key;
    /**
     * name of the application sending the message (application names must be made up of only uppercase and lowercase ASCII
     * letters, numbers, underscores, hyphens, and periods, and must be between 1 and 256 characters long)
     */
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
struct FAdminSetupPushNotificationResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Amazon Resource Name for the created notification topic. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString ARN;
};

USTRUCT(BlueprintType)
struct FAdminUpdateRandomResultTablesRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** which catalog is being updated. If null, update the current default catalog version */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        FString CatalogVersion;
    /**
     * array of random result tables to make available (Note: specifying an existing TableId will result in overwriting that
     * table, while any others will be added to the available set)
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> Tables;
};

USTRUCT(BlueprintType)
struct FAdminUpdateRandomResultTablesResult
{
    GENERATED_USTRUCT_BODY()
public:
};

