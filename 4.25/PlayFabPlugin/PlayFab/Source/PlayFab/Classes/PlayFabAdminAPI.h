//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated header file for the UE4 PlayFab plugin.
// This header file contains the function definitions.
//
// API: Admin
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Http.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "PlayFabBaseModel.h"
#include "PlayFabAdminModels.h"
#include "PlayFabAdminAPI.generated.h"

class UPlayFabAuthenticationContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPlayFabAdminRequestCompleted, FPlayFabBaseModel, response, UObject*, customData, bool, successful);

UCLASS(Blueprintable, BlueprintType)
class PLAYFAB_API UPlayFabAdminAPI : public UOnlineBlueprintCallProxyBase
{
    GENERATED_UCLASS_BODY()

public:
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnFailurePlayFabError, FPlayFabError, error, UObject*, customData);

    UPROPERTY(BlueprintAssignable)
        FOnPlayFabAdminRequestCompleted OnPlayFabResponse;

    void SetCallAuthenticationContext(UPlayFabAuthenticationContext* InAuthenticationContext);

    /** Set the Request Json object */
    void SetRequestObject(UPlayFabJsonObject* JsonObject);

    /** Get the Response Json object */
    UPlayFabJsonObject* GetResponseObject();

    /** Applies percent-encoding to text */
    static FString PercentEncode(const FString& Text);

    /** Reset saved response data */
    void ResetResponseData();

    /** UOnlineBlueprintCallProxyBase interface */
    virtual void Activate() override;

    //////////////////////////////////////////////////////////////////////////
    // Generated PlayFab Admin API Functions
    //////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////
    // Account Management
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessBanUsers, FAdminBanUsersResult, result, UObject*, customData);

    /** Bans users by PlayFab ID with optional IP address, or MAC address for the provided game. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* BanUsers(FAdminBanUsersRequest request,
            FDelegateOnSuccessBanUsers onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperBanUsers(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteMasterPlayerAccount, FAdminDeleteMasterPlayerAccountResult, result, UObject*, customData);

    /** Removes a master player account entirely from all titles and deletes all associated data */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* DeleteMasterPlayerAccount(FAdminDeleteMasterPlayerAccountRequest request,
            FDelegateOnSuccessDeleteMasterPlayerAccount onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteMasterPlayerAccount(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeletePlayer, FAdminDeletePlayerResult, result, UObject*, customData);

    /** Removes a user's player account from a title and deletes all associated data */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* DeletePlayer(FAdminDeletePlayerRequest request,
            FDelegateOnSuccessDeletePlayer onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeletePlayer(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteTitle, FAdminDeleteTitleResult, result, UObject*, customData);

    /** Permanently deletes a title and all associated configuration */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* DeleteTitle(FAdminDeleteTitleRequest request,
            FDelegateOnSuccessDeleteTitle onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteTitle(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessExportMasterPlayerData, FAdminExportMasterPlayerDataResult, result, UObject*, customData);

    /** Exports all associated data of a master player account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* ExportMasterPlayerData(FAdminExportMasterPlayerDataRequest request,
            FDelegateOnSuccessExportMasterPlayerData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperExportMasterPlayerData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayedTitleList, FAdminGetPlayedTitleListResult, result, UObject*, customData);

    /** Get the list of titles that the player has played */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetPlayedTitleList(FAdminGetPlayedTitleListRequest request,
            FDelegateOnSuccessGetPlayedTitleList onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayedTitleList(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayerIdFromAuthToken, FAdminGetPlayerIdFromAuthTokenResult, result, UObject*, customData);

    /** Gets a player's ID from an auth token. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetPlayerIdFromAuthToken(FAdminGetPlayerIdFromAuthTokenRequest request,
            FDelegateOnSuccessGetPlayerIdFromAuthToken onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayerIdFromAuthToken(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayerProfile, FAdminGetPlayerProfileResult, result, UObject*, customData);

    /** Retrieves the player's profile */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetPlayerProfile(FAdminGetPlayerProfileRequest request,
            FDelegateOnSuccessGetPlayerProfile onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayerProfile(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetUserAccountInfo, FAdminLookupUserAccountInfoResult, result, UObject*, customData);

    /** Retrieves the relevant details for a specified user, based upon a match against a supplied unique identifier */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetUserAccountInfo(FAdminLookupUserAccountInfoRequest request,
            FDelegateOnSuccessGetUserAccountInfo onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetUserAccountInfo(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetUserBans, FAdminGetUserBansResult, result, UObject*, customData);

    /** Gets all bans for a user. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetUserBans(FAdminGetUserBansRequest request,
            FDelegateOnSuccessGetUserBans onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetUserBans(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessResetPassword, FAdminResetPasswordResult, result, UObject*, customData);

    /** Reset a player's password for a given title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* ResetPassword(FAdminResetPasswordRequest request,
            FDelegateOnSuccessResetPassword onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperResetPassword(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRevokeAllBansForUser, FAdminRevokeAllBansForUserResult, result, UObject*, customData);

    /** Revoke all active bans for a user. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* RevokeAllBansForUser(FAdminRevokeAllBansForUserRequest request,
            FDelegateOnSuccessRevokeAllBansForUser onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRevokeAllBansForUser(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRevokeBans, FAdminRevokeBansResult, result, UObject*, customData);

    /** Revoke all active bans specified with BanId. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* RevokeBans(FAdminRevokeBansRequest request,
            FDelegateOnSuccessRevokeBans onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRevokeBans(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSendAccountRecoveryEmail, FAdminSendAccountRecoveryEmailResult, result, UObject*, customData);

    /**
     * Forces an email to be sent to the registered email address for the user's account, with a link allowing the user to
     * change the password.If an account recovery email template ID is provided, an email using the custom email template will
     * be used.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* SendAccountRecoveryEmail(FAdminSendAccountRecoveryEmailRequest request,
            FDelegateOnSuccessSendAccountRecoveryEmail onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSendAccountRecoveryEmail(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateBans, FAdminUpdateBansResult, result, UObject*, customData);

    /** Updates information of a list of existing bans specified with Ban Ids. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateBans(FAdminUpdateBansRequest request,
            FDelegateOnSuccessUpdateBans onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateBans(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateUserTitleDisplayName, FAdminUpdateUserTitleDisplayNameResult, result, UObject*, customData);

    /** Updates the title specific display name for a user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateUserTitleDisplayName(FAdminUpdateUserTitleDisplayNameRequest request,
            FDelegateOnSuccessUpdateUserTitleDisplayName onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateUserTitleDisplayName(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Authentication
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateOpenIdConnection, FAdminEmptyResponse, result, UObject*, customData);

    /** Registers a relationship between a title and an Open ID Connect provider. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* CreateOpenIdConnection(FAdminCreateOpenIdConnectionRequest request,
            FDelegateOnSuccessCreateOpenIdConnection onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateOpenIdConnection(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreatePlayerSharedSecret, FAdminCreatePlayerSharedSecretResult, result, UObject*, customData);

    /**
     * Creates a new Player Shared Secret Key. It may take up to 5 minutes for this key to become generally available after
     * this API returns.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* CreatePlayerSharedSecret(FAdminCreatePlayerSharedSecretRequest request,
            FDelegateOnSuccessCreatePlayerSharedSecret onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreatePlayerSharedSecret(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteOpenIdConnection, FAdminEmptyResponse, result, UObject*, customData);

    /** Removes a relationship between a title and an OpenID Connect provider. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* DeleteOpenIdConnection(FAdminDeleteOpenIdConnectionRequest request,
            FDelegateOnSuccessDeleteOpenIdConnection onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteOpenIdConnection(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeletePlayerSharedSecret, FAdminDeletePlayerSharedSecretResult, result, UObject*, customData);

    /**
     * Deletes an existing Player Shared Secret Key. It may take up to 5 minutes for this delete to be reflected after this API
     * returns.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* DeletePlayerSharedSecret(FAdminDeletePlayerSharedSecretRequest request,
            FDelegateOnSuccessDeletePlayerSharedSecret onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeletePlayerSharedSecret(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayerSharedSecrets, FAdminGetPlayerSharedSecretsResult, result, UObject*, customData);

    /** Returns all Player Shared Secret Keys including disabled and expired. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetPlayerSharedSecrets(FAdminGetPlayerSharedSecretsRequest request,
            FDelegateOnSuccessGetPlayerSharedSecrets onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayerSharedSecrets(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPolicy, FAdminGetPolicyResponse, result, UObject*, customData);

    /** Gets the requested policy. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetPolicy(FAdminGetPolicyRequest request,
            FDelegateOnSuccessGetPolicy onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPolicy(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListOpenIdConnection, FAdminListOpenIdConnectionResponse, result, UObject*, customData);

    /** Retrieves a list of all Open ID Connect providers registered to a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* ListOpenIdConnection(FAdminListOpenIdConnectionRequest request,
            FDelegateOnSuccessListOpenIdConnection onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListOpenIdConnection(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetPlayerSecret, FAdminSetPlayerSecretResult, result, UObject*, customData);

    /** Sets or resets the player's secret. Player secrets are used to sign API requests. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* SetPlayerSecret(FAdminSetPlayerSecretRequest request,
            FDelegateOnSuccessSetPlayerSecret onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetPlayerSecret(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateOpenIdConnection, FAdminEmptyResponse, result, UObject*, customData);

    /** Modifies data and credentials for an existing relationship between a title and an Open ID Connect provider */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateOpenIdConnection(FAdminUpdateOpenIdConnectionRequest request,
            FDelegateOnSuccessUpdateOpenIdConnection onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateOpenIdConnection(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdatePlayerSharedSecret, FAdminUpdatePlayerSharedSecretResult, result, UObject*, customData);

    /**
     * Updates a existing Player Shared Secret Key. It may take up to 5 minutes for this update to become generally available
     * after this API returns.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdatePlayerSharedSecret(FAdminUpdatePlayerSharedSecretRequest request,
            FDelegateOnSuccessUpdatePlayerSharedSecret onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdatePlayerSharedSecret(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdatePolicy, FAdminUpdatePolicyResponse, result, UObject*, customData);

    /** Changes a policy for a title */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdatePolicy(FAdminUpdatePolicyRequest request,
            FDelegateOnSuccessUpdatePolicy onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdatePolicy(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Characters
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessResetCharacterStatistics, FAdminResetCharacterStatisticsResult, result, UObject*, customData);

    /** Completely removes all statistics for the specified character, for the current game */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* ResetCharacterStatistics(FAdminResetCharacterStatisticsRequest request,
            FDelegateOnSuccessResetCharacterStatistics onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperResetCharacterStatistics(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Content
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteContent, FAdminBlankResult, result, UObject*, customData);

    /** Delete a content file from the title. When deleting a file that does not exist, it returns success. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Content ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* DeleteContent(FAdminDeleteContentRequest request,
            FDelegateOnSuccessDeleteContent onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Content ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteContent(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetContentList, FAdminGetContentListResult, result, UObject*, customData);

    /** List all contents of the title and get statistics such as size */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Content ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetContentList(FAdminGetContentListRequest request,
            FDelegateOnSuccessGetContentList onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Content ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetContentList(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetContentUploadUrl, FAdminGetContentUploadUrlResult, result, UObject*, customData);

    /**
     * Retrieves the pre-signed URL for uploading a content file. A subsequent HTTP PUT to the returned URL uploads the
     * content. Also, please be aware that the Content service is specifically PlayFab's CDN offering, for which standard CDN
     * rates apply.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Content ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetContentUploadUrl(FAdminGetContentUploadUrlRequest request,
            FDelegateOnSuccessGetContentUploadUrl onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Content ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetContentUploadUrl(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Custom Server Management
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAddServerBuild, FAdminAddServerBuildResult, result, UObject*, customData);

    /**
     * Adds the game server executable specified (previously uploaded - see GetServerBuildUploadUrl) to the set of those a
     * client is permitted to request in a call to StartGame
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* AddServerBuild(FAdminAddServerBuildRequest request,
            FDelegateOnSuccessAddServerBuild onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAddServerBuild(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetServerBuildInfo, FAdminGetServerBuildInfoResult, result, UObject*, customData);

    /** Retrieves the build details for the specified game server executable */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetServerBuildInfo(FAdminGetServerBuildInfoRequest request,
            FDelegateOnSuccessGetServerBuildInfo onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetServerBuildInfo(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetServerBuildUploadUrl, FAdminGetServerBuildUploadURLResult, result, UObject*, customData);

    /**
     * Retrieves the pre-authorized URL for uploading a game server package containing a build (does not enable the build for
     * use - see AddServerBuild)
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetServerBuildUploadUrl(FAdminGetServerBuildUploadURLRequest request,
            FDelegateOnSuccessGetServerBuildUploadUrl onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetServerBuildUploadUrl(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListServerBuilds, FAdminListBuildsResult, result, UObject*, customData);

    /** Retrieves the build details for all game server executables which are currently defined for the title */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* ListServerBuilds(FAdminListBuildsRequest request,
            FDelegateOnSuccessListServerBuilds onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListServerBuilds(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessModifyServerBuild, FAdminModifyServerBuildResult, result, UObject*, customData);

    /** Updates the build details for the specified game server executable */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* ModifyServerBuild(FAdminModifyServerBuildRequest request,
            FDelegateOnSuccessModifyServerBuild onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperModifyServerBuild(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRemoveServerBuild, FAdminRemoveServerBuildResult, result, UObject*, customData);

    /**
     * Removes the game server executable specified from the set of those a client is permitted to request in a call to
     * StartGame
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* RemoveServerBuild(FAdminRemoveServerBuildRequest request,
            FDelegateOnSuccessRemoveServerBuild onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRemoveServerBuild(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Matchmaking
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetMatchmakerGameInfo, FAdminGetMatchmakerGameInfoResult, result, UObject*, customData);

    /** Retrieves the details for a specific completed session, including links to standard out and standard error logs */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetMatchmakerGameInfo(FAdminGetMatchmakerGameInfoRequest request,
            FDelegateOnSuccessGetMatchmakerGameInfo onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetMatchmakerGameInfo(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetMatchmakerGameModes, FAdminGetMatchmakerGameModesResult, result, UObject*, customData);

    /** Retrieves the details of defined game modes for the specified game server executable */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetMatchmakerGameModes(FAdminGetMatchmakerGameModesRequest request,
            FDelegateOnSuccessGetMatchmakerGameModes onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetMatchmakerGameModes(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessModifyMatchmakerGameModes, FAdminModifyMatchmakerGameModesResult, result, UObject*, customData);

    /** Updates the game server mode details for the specified game server executable */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* ModifyMatchmakerGameModes(FAdminModifyMatchmakerGameModesRequest request,
            FDelegateOnSuccessModifyMatchmakerGameModes onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperModifyMatchmakerGameModes(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Player Data Management
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreatePlayerStatisticDefinition, FAdminCreatePlayerStatisticDefinitionResult, result, UObject*, customData);

    /**
     * Adds a new player statistic configuration to the title, optionally allowing the developer to specify a reset interval
     * and an aggregation method.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* CreatePlayerStatisticDefinition(FAdminCreatePlayerStatisticDefinitionRequest request,
            FDelegateOnSuccessCreatePlayerStatisticDefinition onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreatePlayerStatisticDefinition(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetDataReport, FAdminGetDataReportResult, result, UObject*, customData);

    /** Retrieves a download URL for the requested report */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetDataReport(FAdminGetDataReportRequest request,
            FDelegateOnSuccessGetDataReport onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetDataReport(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayerStatisticDefinitions, FAdminGetPlayerStatisticDefinitionsResult, result, UObject*, customData);

    /**
     * Retrieves the configuration information for all player statistics defined in the title, regardless of whether they have
     * a reset interval.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetPlayerStatisticDefinitions(FAdminGetPlayerStatisticDefinitionsRequest request,
            FDelegateOnSuccessGetPlayerStatisticDefinitions onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayerStatisticDefinitions(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayerStatisticVersions, FAdminGetPlayerStatisticVersionsResult, result, UObject*, customData);

    /** Retrieves the information on the available versions of the specified statistic. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetPlayerStatisticVersions(FAdminGetPlayerStatisticVersionsRequest request,
            FDelegateOnSuccessGetPlayerStatisticVersions onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayerStatisticVersions(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetUserData, FAdminGetUserDataResult, result, UObject*, customData);

    /** Retrieves the title-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetUserData(FAdminGetUserDataRequest request,
            FDelegateOnSuccessGetUserData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetUserData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetUserInternalData, FAdminGetUserDataResult, result, UObject*, customData);

    /** Retrieves the title-specific custom data for the user which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetUserInternalData(FAdminGetUserDataRequest request,
            FDelegateOnSuccessGetUserInternalData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetUserInternalData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetUserPublisherData, FAdminGetUserDataResult, result, UObject*, customData);

    /** Retrieves the publisher-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetUserPublisherData(FAdminGetUserDataRequest request,
            FDelegateOnSuccessGetUserPublisherData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetUserPublisherData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetUserPublisherInternalData, FAdminGetUserDataResult, result, UObject*, customData);

    /** Retrieves the publisher-specific custom data for the user which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetUserPublisherInternalData(FAdminGetUserDataRequest request,
            FDelegateOnSuccessGetUserPublisherInternalData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetUserPublisherInternalData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetUserPublisherReadOnlyData, FAdminGetUserDataResult, result, UObject*, customData);

    /** Retrieves the publisher-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetUserPublisherReadOnlyData(FAdminGetUserDataRequest request,
            FDelegateOnSuccessGetUserPublisherReadOnlyData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetUserPublisherReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetUserReadOnlyData, FAdminGetUserDataResult, result, UObject*, customData);

    /** Retrieves the title-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetUserReadOnlyData(FAdminGetUserDataRequest request,
            FDelegateOnSuccessGetUserReadOnlyData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetUserReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessIncrementPlayerStatisticVersion, FAdminIncrementPlayerStatisticVersionResult, result, UObject*, customData);

    /** Resets the indicated statistic, removing all player entries for it and backing up the old values. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* IncrementPlayerStatisticVersion(FAdminIncrementPlayerStatisticVersionRequest request,
            FDelegateOnSuccessIncrementPlayerStatisticVersion onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperIncrementPlayerStatisticVersion(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRefundPurchase, FAdminRefundPurchaseResponse, result, UObject*, customData);

    /** Attempts to process an order refund through the original real money payment provider. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* RefundPurchase(FAdminRefundPurchaseRequest request,
            FDelegateOnSuccessRefundPurchase onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRefundPurchase(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessResetUserStatistics, FAdminResetUserStatisticsResult, result, UObject*, customData);

    /** Completely removes all statistics for the specified user, for the current game */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* ResetUserStatistics(FAdminResetUserStatisticsRequest request,
            FDelegateOnSuccessResetUserStatistics onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperResetUserStatistics(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessResolvePurchaseDispute, FAdminResolvePurchaseDisputeResponse, result, UObject*, customData);

    /** Attempts to resolve a dispute with the original order's payment provider. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* ResolvePurchaseDispute(FAdminResolvePurchaseDisputeRequest request,
            FDelegateOnSuccessResolvePurchaseDispute onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperResolvePurchaseDispute(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdatePlayerStatisticDefinition, FAdminUpdatePlayerStatisticDefinitionResult, result, UObject*, customData);

    /** Updates a player statistic configuration for the title, optionally allowing the developer to specify a reset interval. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdatePlayerStatisticDefinition(FAdminUpdatePlayerStatisticDefinitionRequest request,
            FDelegateOnSuccessUpdatePlayerStatisticDefinition onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdatePlayerStatisticDefinition(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateUserData, FAdminUpdateUserDataResult, result, UObject*, customData);

    /** Updates the title-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateUserData(FAdminUpdateUserDataRequest request,
            FDelegateOnSuccessUpdateUserData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateUserData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateUserInternalData, FAdminUpdateUserDataResult, result, UObject*, customData);

    /** Updates the title-specific custom data for the user which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateUserInternalData(FAdminUpdateUserInternalDataRequest request,
            FDelegateOnSuccessUpdateUserInternalData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateUserInternalData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateUserPublisherData, FAdminUpdateUserDataResult, result, UObject*, customData);

    /** Updates the publisher-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateUserPublisherData(FAdminUpdateUserDataRequest request,
            FDelegateOnSuccessUpdateUserPublisherData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateUserPublisherData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateUserPublisherInternalData, FAdminUpdateUserDataResult, result, UObject*, customData);

    /** Updates the publisher-specific custom data for the user which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateUserPublisherInternalData(FAdminUpdateUserInternalDataRequest request,
            FDelegateOnSuccessUpdateUserPublisherInternalData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateUserPublisherInternalData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateUserPublisherReadOnlyData, FAdminUpdateUserDataResult, result, UObject*, customData);

    /** Updates the publisher-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateUserPublisherReadOnlyData(FAdminUpdateUserDataRequest request,
            FDelegateOnSuccessUpdateUserPublisherReadOnlyData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateUserPublisherReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateUserReadOnlyData, FAdminUpdateUserDataResult, result, UObject*, customData);

    /** Updates the title-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateUserReadOnlyData(FAdminUpdateUserDataRequest request,
            FDelegateOnSuccessUpdateUserReadOnlyData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateUserReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Player Item Management
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAddUserVirtualCurrency, FAdminModifyUserVirtualCurrencyResult, result, UObject*, customData);

    /** Increments the specified virtual currency by the stated amount */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* AddUserVirtualCurrency(FAdminAddUserVirtualCurrencyRequest request,
            FDelegateOnSuccessAddUserVirtualCurrency onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAddUserVirtualCurrency(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCheckLimitedEditionItemAvailability, FAdminCheckLimitedEditionItemAvailabilityResult, result, UObject*, customData);

    /** Checks the global count for the limited edition item. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* CheckLimitedEditionItemAvailability(FAdminCheckLimitedEditionItemAvailabilityRequest request,
            FDelegateOnSuccessCheckLimitedEditionItemAvailability onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCheckLimitedEditionItemAvailability(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetUserInventory, FAdminGetUserInventoryResult, result, UObject*, customData);

    /** Retrieves the specified user's current inventory of virtual goods */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetUserInventory(FAdminGetUserInventoryRequest request,
            FDelegateOnSuccessGetUserInventory onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetUserInventory(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGrantItemsToUsers, FAdminGrantItemsToUsersResult, result, UObject*, customData);

    /** Adds the specified items to the specified user inventories */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GrantItemsToUsers(FAdminGrantItemsToUsersRequest request,
            FDelegateOnSuccessGrantItemsToUsers onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGrantItemsToUsers(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessIncrementLimitedEditionItemAvailability, FAdminIncrementLimitedEditionItemAvailabilityResult, result, UObject*, customData);

    /** Increases the global count for the given scarce resource. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* IncrementLimitedEditionItemAvailability(FAdminIncrementLimitedEditionItemAvailabilityRequest request,
            FDelegateOnSuccessIncrementLimitedEditionItemAvailability onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperIncrementLimitedEditionItemAvailability(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRevokeInventoryItem, FAdminRevokeInventoryResult, result, UObject*, customData);

    /** Revokes access to an item in a user's inventory */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* RevokeInventoryItem(FAdminRevokeInventoryItemRequest request,
            FDelegateOnSuccessRevokeInventoryItem onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRevokeInventoryItem(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRevokeInventoryItems, FAdminRevokeInventoryItemsResult, result, UObject*, customData);

    /** Revokes access for up to 25 items across multiple users and characters. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* RevokeInventoryItems(FAdminRevokeInventoryItemsRequest request,
            FDelegateOnSuccessRevokeInventoryItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRevokeInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSubtractUserVirtualCurrency, FAdminModifyUserVirtualCurrencyResult, result, UObject*, customData);

    /** Decrements the specified virtual currency by the stated amount */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* SubtractUserVirtualCurrency(FAdminSubtractUserVirtualCurrencyRequest request,
            FDelegateOnSuccessSubtractUserVirtualCurrency onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSubtractUserVirtualCurrency(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // PlayStream
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAddPlayerTag, FAdminAddPlayerTagResult, result, UObject*, customData);

    /** Adds a given tag to a player profile. The tag's namespace is automatically generated based on the source of the tag. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* AddPlayerTag(FAdminAddPlayerTagRequest request,
            FDelegateOnSuccessAddPlayerTag onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAddPlayerTag(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetAllSegments, FAdminGetAllSegmentsResult, result, UObject*, customData);

    /**
     * Retrieves an array of player segment definitions. Results from this can be used in subsequent API calls such as
     * GetPlayersInSegment which requires a Segment ID. While segment names can change the ID for that segment will not change.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetAllSegments(FAdminGetAllSegmentsRequest request,
            FDelegateOnSuccessGetAllSegments onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetAllSegments(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayerSegments, FAdminGetPlayerSegmentsResult, result, UObject*, customData);

    /** List all segments that a player currently belongs to at this moment in time. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetPlayerSegments(FAdminGetPlayersSegmentsRequest request,
            FDelegateOnSuccessGetPlayerSegments onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayerSegments(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayersInSegment, FAdminGetPlayersInSegmentResult, result, UObject*, customData);

    /**
     * Allows for paging through all players in a given segment. This API creates a snapshot of all player profiles that match
     * the segment definition at the time of its creation and lives through the Total Seconds to Live, refreshing its life span
     * on each subsequent use of the Continuation Token. Profiles that change during the course of paging will not be reflected
     * in the results. AB Test segments are currently not supported by this operation. NOTE: This API is limited to being
     * called 30 times in one minute. You will be returned an error if you exceed this threshold.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetPlayersInSegment(FAdminGetPlayersInSegmentRequest request,
            FDelegateOnSuccessGetPlayersInSegment onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayersInSegment(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayerTags, FAdminGetPlayerTagsResult, result, UObject*, customData);

    /** Get all tags with a given Namespace (optional) from a player profile. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetPlayerTags(FAdminGetPlayerTagsRequest request,
            FDelegateOnSuccessGetPlayerTags onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayerTags(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRemovePlayerTag, FAdminRemovePlayerTagResult, result, UObject*, customData);

    /** Remove a given tag from a player profile. The tag's namespace is automatically generated based on the source of the tag. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* RemovePlayerTag(FAdminRemovePlayerTagRequest request,
            FDelegateOnSuccessRemovePlayerTag onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRemovePlayerTag(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // ScheduledTask
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAbortTaskInstance, FAdminEmptyResponse, result, UObject*, customData);

    /** Abort an ongoing task instance. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* AbortTaskInstance(FAdminAbortTaskInstanceRequest request,
            FDelegateOnSuccessAbortTaskInstance onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAbortTaskInstance(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateActionsOnPlayersInSegmentTask, FAdminCreateTaskResult, result, UObject*, customData);

    /** Create an ActionsOnPlayersInSegment task, which iterates through all players in a segment to execute action. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* CreateActionsOnPlayersInSegmentTask(FAdminCreateActionsOnPlayerSegmentTaskRequest request,
            FDelegateOnSuccessCreateActionsOnPlayersInSegmentTask onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateActionsOnPlayersInSegmentTask(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateCloudScriptTask, FAdminCreateTaskResult, result, UObject*, customData);

    /** Create a CloudScript task, which can run a CloudScript on a schedule. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* CreateCloudScriptTask(FAdminCreateCloudScriptTaskRequest request,
            FDelegateOnSuccessCreateCloudScriptTask onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateCloudScriptTask(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateInsightsScheduledScalingTask, FAdminCreateTaskResult, result, UObject*, customData);

    /** Create a Insights Scheduled Scaling task, which can scale Insights Performance Units on a schedule */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* CreateInsightsScheduledScalingTask(FAdminCreateInsightsScheduledScalingTaskRequest request,
            FDelegateOnSuccessCreateInsightsScheduledScalingTask onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateInsightsScheduledScalingTask(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteTask, FAdminEmptyResponse, result, UObject*, customData);

    /** Delete a task. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* DeleteTask(FAdminDeleteTaskRequest request,
            FDelegateOnSuccessDeleteTask onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteTask(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetActionsOnPlayersInSegmentTaskInstance, FAdminGetActionsOnPlayersInSegmentTaskInstanceResult, result, UObject*, customData);

    /** Get information about a ActionsOnPlayersInSegment task instance. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetActionsOnPlayersInSegmentTaskInstance(FAdminGetTaskInstanceRequest request,
            FDelegateOnSuccessGetActionsOnPlayersInSegmentTaskInstance onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetActionsOnPlayersInSegmentTaskInstance(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetCloudScriptTaskInstance, FAdminGetCloudScriptTaskInstanceResult, result, UObject*, customData);

    /** Get detail information about a CloudScript task instance. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetCloudScriptTaskInstance(FAdminGetTaskInstanceRequest request,
            FDelegateOnSuccessGetCloudScriptTaskInstance onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetCloudScriptTaskInstance(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetTaskInstances, FAdminGetTaskInstancesResult, result, UObject*, customData);

    /** Query for task instances by task, status, or time range. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetTaskInstances(FAdminGetTaskInstancesRequest request,
            FDelegateOnSuccessGetTaskInstances onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetTaskInstances(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetTasks, FAdminGetTasksResult, result, UObject*, customData);

    /** Get definition information on a specified task or all tasks within a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetTasks(FAdminGetTasksRequest request,
            FDelegateOnSuccessGetTasks onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetTasks(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRunTask, FAdminRunTaskResult, result, UObject*, customData);

    /** Run a task immediately regardless of its schedule. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* RunTask(FAdminRunTaskRequest request,
            FDelegateOnSuccessRunTask onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRunTask(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateTask, FAdminEmptyResponse, result, UObject*, customData);

    /** Update an existing task. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateTask(FAdminUpdateTaskRequest request,
            FDelegateOnSuccessUpdateTask onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateTask(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Segments
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateSegment, FAdminCreateSegmentResponse, result, UObject*, customData);

    /**
     * Creates a new player segment by defining the conditions on player properties. Also, create actions to target the player
     * segments for a title.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Segments ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* CreateSegment(FAdminCreateSegmentRequest request,
            FDelegateOnSuccessCreateSegment onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Segments ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateSegment(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteSegment, FAdminDeleteSegmentsResponse, result, UObject*, customData);

    /** Deletes an existing player segment and its associated action(s) for a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Segments ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* DeleteSegment(FAdminDeleteSegmentRequest request,
            FDelegateOnSuccessDeleteSegment onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Segments ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteSegment(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetSegments, FAdminGetSegmentsResponse, result, UObject*, customData);

    /** Get detail information of a segment and its associated definition(s) and action(s) for a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Segments ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetSegments(FAdminGetSegmentsRequest request,
            FDelegateOnSuccessGetSegments onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Segments ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetSegments(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateSegment, FAdminUpdateSegmentResponse, result, UObject*, customData);

    /** Updates an existing player segment and its associated definition(s) and action(s) for a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Segments ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateSegment(FAdminUpdateSegmentRequest request,
            FDelegateOnSuccessUpdateSegment onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Segments ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateSegment(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Server-Side Cloud Script
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetCloudScriptRevision, FAdminGetCloudScriptRevisionResult, result, UObject*, customData);

    /** Gets the contents and information of a specific Cloud Script revision. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetCloudScriptRevision(FAdminGetCloudScriptRevisionRequest request,
            FDelegateOnSuccessGetCloudScriptRevision onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetCloudScriptRevision(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetCloudScriptVersions, FAdminGetCloudScriptVersionsResult, result, UObject*, customData);

    /**
     * Lists all the current cloud script versions. For each version, information about the current published and latest
     * revisions is also listed.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetCloudScriptVersions(FAdminGetCloudScriptVersionsRequest request,
            FDelegateOnSuccessGetCloudScriptVersions onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetCloudScriptVersions(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetPublishedRevision, FAdminSetPublishedRevisionResult, result, UObject*, customData);

    /** Sets the currently published revision of a title Cloud Script */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* SetPublishedRevision(FAdminSetPublishedRevisionRequest request,
            FDelegateOnSuccessSetPublishedRevision onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetPublishedRevision(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateCloudScript, FAdminUpdateCloudScriptResult, result, UObject*, customData);

    /**
     * Creates a new Cloud Script revision and uploads source code to it. Note that at this time, only one file should be
     * submitted in the revision.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateCloudScript(FAdminUpdateCloudScriptRequest request,
            FDelegateOnSuccessUpdateCloudScript onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateCloudScript(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Shared Group Data
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetPublisherData, FAdminSetPublisherDataResult, result, UObject*, customData);

    /** Updates the key-value store of custom publisher settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* SetPublisherData(FAdminSetPublisherDataRequest request,
            FDelegateOnSuccessSetPublisherData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetPublisherData(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Title-Wide Data Management
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAddLocalizedNews, FAdminAddLocalizedNewsResult, result, UObject*, customData);

    /** Update news item to include localized version */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* AddLocalizedNews(FAdminAddLocalizedNewsRequest request,
            FDelegateOnSuccessAddLocalizedNews onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAddLocalizedNews(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAddNews, FAdminAddNewsResult, result, UObject*, customData);

    /** Adds a new news item to the title's news feed */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* AddNews(FAdminAddNewsRequest request,
            FDelegateOnSuccessAddNews onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAddNews(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAddVirtualCurrencyTypes, FAdminBlankResult, result, UObject*, customData);

    /**
     * Adds one or more virtual currencies to the set defined for the title. Virtual Currencies have a maximum value of
     * 2,147,483,647 when granted to a player. Any value over that will be discarded.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* AddVirtualCurrencyTypes(FAdminAddVirtualCurrencyTypesRequest request,
            FDelegateOnSuccessAddVirtualCurrencyTypes onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAddVirtualCurrencyTypes(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteStore, FAdminDeleteStoreResult, result, UObject*, customData);

    /** Deletes an existing virtual item store */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* DeleteStore(FAdminDeleteStoreRequest request,
            FDelegateOnSuccessDeleteStore onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteStore(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteTitleDataOverride, FAdminDeleteTitleDataOverrideResult, result, UObject*, customData);

    /** Deletes a specified set of title data overrides. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* DeleteTitleDataOverride(FAdminDeleteTitleDataOverrideRequest request,
            FDelegateOnSuccessDeleteTitleDataOverride onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteTitleDataOverride(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetCatalogItems, FAdminGetCatalogItemsResult, result, UObject*, customData);

    /** Retrieves the specified version of the title's catalog of virtual goods, including all defined properties */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetCatalogItems(FAdminGetCatalogItemsRequest request,
            FDelegateOnSuccessGetCatalogItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetCatalogItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPublisherData, FAdminGetPublisherDataResult, result, UObject*, customData);

    /** Retrieves the key-value store of custom publisher settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetPublisherData(FAdminGetPublisherDataRequest request,
            FDelegateOnSuccessGetPublisherData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPublisherData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetRandomResultTables, FAdminGetRandomResultTablesResult, result, UObject*, customData);

    /** Retrieves the random drop table configuration for the title */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetRandomResultTables(FAdminGetRandomResultTablesRequest request,
            FDelegateOnSuccessGetRandomResultTables onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetRandomResultTables(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetStoreItems, FAdminGetStoreItemsResult, result, UObject*, customData);

    /** Retrieves the set of items defined for the specified store, including all prices defined */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetStoreItems(FAdminGetStoreItemsRequest request,
            FDelegateOnSuccessGetStoreItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetStoreItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetTitleData, FAdminGetTitleDataResult, result, UObject*, customData);

    /** Retrieves the key-value store of custom title settings which can be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetTitleData(FAdminGetTitleDataRequest request,
            FDelegateOnSuccessGetTitleData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetTitleData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetTitleInternalData, FAdminGetTitleDataResult, result, UObject*, customData);

    /** Retrieves the key-value store of custom title settings which cannot be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* GetTitleInternalData(FAdminGetTitleDataRequest request,
            FDelegateOnSuccessGetTitleInternalData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetTitleInternalData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListVirtualCurrencyTypes, FAdminListVirtualCurrencyTypesResult, result, UObject*, customData);

    /** Retuns the list of all defined virtual currencies for the title */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* ListVirtualCurrencyTypes(FAdminListVirtualCurrencyTypesRequest request,
            FDelegateOnSuccessListVirtualCurrencyTypes onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListVirtualCurrencyTypes(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRemoveVirtualCurrencyTypes, FAdminBlankResult, result, UObject*, customData);

    /** Removes one or more virtual currencies from the set defined for the title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* RemoveVirtualCurrencyTypes(FAdminRemoveVirtualCurrencyTypesRequest request,
            FDelegateOnSuccessRemoveVirtualCurrencyTypes onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRemoveVirtualCurrencyTypes(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetCatalogItems, FAdminUpdateCatalogItemsResult, result, UObject*, customData);

    /** Creates the catalog configuration of all virtual goods for the specified catalog version */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* SetCatalogItems(FAdminUpdateCatalogItemsRequest request,
            FDelegateOnSuccessSetCatalogItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetCatalogItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetStoreItems, FAdminUpdateStoreItemsResult, result, UObject*, customData);

    /** Sets all the items in one virtual store */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* SetStoreItems(FAdminUpdateStoreItemsRequest request,
            FDelegateOnSuccessSetStoreItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetStoreItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetTitleData, FAdminSetTitleDataResult, result, UObject*, customData);

    /** Creates and updates the key-value store of custom title settings which can be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* SetTitleData(FAdminSetTitleDataRequest request,
            FDelegateOnSuccessSetTitleData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetTitleData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetTitleDataAndOverrides, FAdminSetTitleDataAndOverridesResult, result, UObject*, customData);

    /** Set and delete key-value pairs in a title data override instance. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* SetTitleDataAndOverrides(FAdminSetTitleDataAndOverridesRequest request,
            FDelegateOnSuccessSetTitleDataAndOverrides onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetTitleDataAndOverrides(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetTitleInternalData, FAdminSetTitleDataResult, result, UObject*, customData);

    /** Updates the key-value store of custom title settings which cannot be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* SetTitleInternalData(FAdminSetTitleDataRequest request,
            FDelegateOnSuccessSetTitleInternalData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetTitleInternalData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetupPushNotification, FAdminSetupPushNotificationResult, result, UObject*, customData);

    /**
     * Sets the Amazon Resource Name (ARN) for iOS and Android push notifications. Documentation on the exact restrictions can
     * be found at: http://docs.aws.amazon.com/sns/latest/api/API_CreatePlatformApplication.html. Currently, Amazon device
     * Messaging is not supported.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* SetupPushNotification(FAdminSetupPushNotificationRequest request,
            FDelegateOnSuccessSetupPushNotification onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetupPushNotification(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateCatalogItems, FAdminUpdateCatalogItemsResult, result, UObject*, customData);

    /** Updates the catalog configuration for virtual goods in the specified catalog version */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateCatalogItems(FAdminUpdateCatalogItemsRequest request,
            FDelegateOnSuccessUpdateCatalogItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateCatalogItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateRandomResultTables, FAdminUpdateRandomResultTablesResult, result, UObject*, customData);

    /** Updates the random drop table configuration for the title */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateRandomResultTables(FAdminUpdateRandomResultTablesRequest request,
            FDelegateOnSuccessUpdateRandomResultTables onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateRandomResultTables(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateStoreItems, FAdminUpdateStoreItemsResult, result, UObject*, customData);

    /** Updates an existing virtual item store with new or modified items */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAdminAPI* UpdateStoreItems(FAdminUpdateStoreItemsRequest request,
            FDelegateOnSuccessUpdateStoreItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAdminRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateStoreItems(FPlayFabBaseModel response, UObject* customData, bool successful);



    /** PlayFab Request Info */
    FString PlayFabRequestURL;

    bool useEntityToken = false;
    bool useSecretKey = false;
    bool useSessionTicket = false;
    bool returnsSessionTicket = false;
    bool returnsEntityToken = false;

    /** Is the response valid JSON? */
    bool bIsValidJsonResponse;
    FString ResponseContent;
    int32 ResponseCode;
    UObject* mCustomData;

    FDelegateOnFailurePlayFabError OnFailure;
    FDelegateOnSuccessBanUsers OnSuccessBanUsers;
    FDelegateOnSuccessDeleteMasterPlayerAccount OnSuccessDeleteMasterPlayerAccount;
    FDelegateOnSuccessDeletePlayer OnSuccessDeletePlayer;
    FDelegateOnSuccessDeleteTitle OnSuccessDeleteTitle;
    FDelegateOnSuccessExportMasterPlayerData OnSuccessExportMasterPlayerData;
    FDelegateOnSuccessGetPlayedTitleList OnSuccessGetPlayedTitleList;
    FDelegateOnSuccessGetPlayerIdFromAuthToken OnSuccessGetPlayerIdFromAuthToken;
    FDelegateOnSuccessGetPlayerProfile OnSuccessGetPlayerProfile;
    FDelegateOnSuccessGetUserAccountInfo OnSuccessGetUserAccountInfo;
    FDelegateOnSuccessGetUserBans OnSuccessGetUserBans;
    FDelegateOnSuccessResetPassword OnSuccessResetPassword;
    FDelegateOnSuccessRevokeAllBansForUser OnSuccessRevokeAllBansForUser;
    FDelegateOnSuccessRevokeBans OnSuccessRevokeBans;
    FDelegateOnSuccessSendAccountRecoveryEmail OnSuccessSendAccountRecoveryEmail;
    FDelegateOnSuccessUpdateBans OnSuccessUpdateBans;
    FDelegateOnSuccessUpdateUserTitleDisplayName OnSuccessUpdateUserTitleDisplayName;
    FDelegateOnSuccessCreateOpenIdConnection OnSuccessCreateOpenIdConnection;
    FDelegateOnSuccessCreatePlayerSharedSecret OnSuccessCreatePlayerSharedSecret;
    FDelegateOnSuccessDeleteOpenIdConnection OnSuccessDeleteOpenIdConnection;
    FDelegateOnSuccessDeletePlayerSharedSecret OnSuccessDeletePlayerSharedSecret;
    FDelegateOnSuccessGetPlayerSharedSecrets OnSuccessGetPlayerSharedSecrets;
    FDelegateOnSuccessGetPolicy OnSuccessGetPolicy;
    FDelegateOnSuccessListOpenIdConnection OnSuccessListOpenIdConnection;
    FDelegateOnSuccessSetPlayerSecret OnSuccessSetPlayerSecret;
    FDelegateOnSuccessUpdateOpenIdConnection OnSuccessUpdateOpenIdConnection;
    FDelegateOnSuccessUpdatePlayerSharedSecret OnSuccessUpdatePlayerSharedSecret;
    FDelegateOnSuccessUpdatePolicy OnSuccessUpdatePolicy;
    FDelegateOnSuccessResetCharacterStatistics OnSuccessResetCharacterStatistics;
    FDelegateOnSuccessDeleteContent OnSuccessDeleteContent;
    FDelegateOnSuccessGetContentList OnSuccessGetContentList;
    FDelegateOnSuccessGetContentUploadUrl OnSuccessGetContentUploadUrl;
    FDelegateOnSuccessAddServerBuild OnSuccessAddServerBuild;
    FDelegateOnSuccessGetServerBuildInfo OnSuccessGetServerBuildInfo;
    FDelegateOnSuccessGetServerBuildUploadUrl OnSuccessGetServerBuildUploadUrl;
    FDelegateOnSuccessListServerBuilds OnSuccessListServerBuilds;
    FDelegateOnSuccessModifyServerBuild OnSuccessModifyServerBuild;
    FDelegateOnSuccessRemoveServerBuild OnSuccessRemoveServerBuild;
    FDelegateOnSuccessGetMatchmakerGameInfo OnSuccessGetMatchmakerGameInfo;
    FDelegateOnSuccessGetMatchmakerGameModes OnSuccessGetMatchmakerGameModes;
    FDelegateOnSuccessModifyMatchmakerGameModes OnSuccessModifyMatchmakerGameModes;
    FDelegateOnSuccessCreatePlayerStatisticDefinition OnSuccessCreatePlayerStatisticDefinition;
    FDelegateOnSuccessGetDataReport OnSuccessGetDataReport;
    FDelegateOnSuccessGetPlayerStatisticDefinitions OnSuccessGetPlayerStatisticDefinitions;
    FDelegateOnSuccessGetPlayerStatisticVersions OnSuccessGetPlayerStatisticVersions;
    FDelegateOnSuccessGetUserData OnSuccessGetUserData;
    FDelegateOnSuccessGetUserInternalData OnSuccessGetUserInternalData;
    FDelegateOnSuccessGetUserPublisherData OnSuccessGetUserPublisherData;
    FDelegateOnSuccessGetUserPublisherInternalData OnSuccessGetUserPublisherInternalData;
    FDelegateOnSuccessGetUserPublisherReadOnlyData OnSuccessGetUserPublisherReadOnlyData;
    FDelegateOnSuccessGetUserReadOnlyData OnSuccessGetUserReadOnlyData;
    FDelegateOnSuccessIncrementPlayerStatisticVersion OnSuccessIncrementPlayerStatisticVersion;
    FDelegateOnSuccessRefundPurchase OnSuccessRefundPurchase;
    FDelegateOnSuccessResetUserStatistics OnSuccessResetUserStatistics;
    FDelegateOnSuccessResolvePurchaseDispute OnSuccessResolvePurchaseDispute;
    FDelegateOnSuccessUpdatePlayerStatisticDefinition OnSuccessUpdatePlayerStatisticDefinition;
    FDelegateOnSuccessUpdateUserData OnSuccessUpdateUserData;
    FDelegateOnSuccessUpdateUserInternalData OnSuccessUpdateUserInternalData;
    FDelegateOnSuccessUpdateUserPublisherData OnSuccessUpdateUserPublisherData;
    FDelegateOnSuccessUpdateUserPublisherInternalData OnSuccessUpdateUserPublisherInternalData;
    FDelegateOnSuccessUpdateUserPublisherReadOnlyData OnSuccessUpdateUserPublisherReadOnlyData;
    FDelegateOnSuccessUpdateUserReadOnlyData OnSuccessUpdateUserReadOnlyData;
    FDelegateOnSuccessAddUserVirtualCurrency OnSuccessAddUserVirtualCurrency;
    FDelegateOnSuccessCheckLimitedEditionItemAvailability OnSuccessCheckLimitedEditionItemAvailability;
    FDelegateOnSuccessGetUserInventory OnSuccessGetUserInventory;
    FDelegateOnSuccessGrantItemsToUsers OnSuccessGrantItemsToUsers;
    FDelegateOnSuccessIncrementLimitedEditionItemAvailability OnSuccessIncrementLimitedEditionItemAvailability;
    FDelegateOnSuccessRevokeInventoryItem OnSuccessRevokeInventoryItem;
    FDelegateOnSuccessRevokeInventoryItems OnSuccessRevokeInventoryItems;
    FDelegateOnSuccessSubtractUserVirtualCurrency OnSuccessSubtractUserVirtualCurrency;
    FDelegateOnSuccessAddPlayerTag OnSuccessAddPlayerTag;
    FDelegateOnSuccessGetAllSegments OnSuccessGetAllSegments;
    FDelegateOnSuccessGetPlayerSegments OnSuccessGetPlayerSegments;
    FDelegateOnSuccessGetPlayersInSegment OnSuccessGetPlayersInSegment;
    FDelegateOnSuccessGetPlayerTags OnSuccessGetPlayerTags;
    FDelegateOnSuccessRemovePlayerTag OnSuccessRemovePlayerTag;
    FDelegateOnSuccessAbortTaskInstance OnSuccessAbortTaskInstance;
    FDelegateOnSuccessCreateActionsOnPlayersInSegmentTask OnSuccessCreateActionsOnPlayersInSegmentTask;
    FDelegateOnSuccessCreateCloudScriptTask OnSuccessCreateCloudScriptTask;
    FDelegateOnSuccessCreateInsightsScheduledScalingTask OnSuccessCreateInsightsScheduledScalingTask;
    FDelegateOnSuccessDeleteTask OnSuccessDeleteTask;
    FDelegateOnSuccessGetActionsOnPlayersInSegmentTaskInstance OnSuccessGetActionsOnPlayersInSegmentTaskInstance;
    FDelegateOnSuccessGetCloudScriptTaskInstance OnSuccessGetCloudScriptTaskInstance;
    FDelegateOnSuccessGetTaskInstances OnSuccessGetTaskInstances;
    FDelegateOnSuccessGetTasks OnSuccessGetTasks;
    FDelegateOnSuccessRunTask OnSuccessRunTask;
    FDelegateOnSuccessUpdateTask OnSuccessUpdateTask;
    FDelegateOnSuccessCreateSegment OnSuccessCreateSegment;
    FDelegateOnSuccessDeleteSegment OnSuccessDeleteSegment;
    FDelegateOnSuccessGetSegments OnSuccessGetSegments;
    FDelegateOnSuccessUpdateSegment OnSuccessUpdateSegment;
    FDelegateOnSuccessGetCloudScriptRevision OnSuccessGetCloudScriptRevision;
    FDelegateOnSuccessGetCloudScriptVersions OnSuccessGetCloudScriptVersions;
    FDelegateOnSuccessSetPublishedRevision OnSuccessSetPublishedRevision;
    FDelegateOnSuccessUpdateCloudScript OnSuccessUpdateCloudScript;
    FDelegateOnSuccessSetPublisherData OnSuccessSetPublisherData;
    FDelegateOnSuccessAddLocalizedNews OnSuccessAddLocalizedNews;
    FDelegateOnSuccessAddNews OnSuccessAddNews;
    FDelegateOnSuccessAddVirtualCurrencyTypes OnSuccessAddVirtualCurrencyTypes;
    FDelegateOnSuccessDeleteStore OnSuccessDeleteStore;
    FDelegateOnSuccessDeleteTitleDataOverride OnSuccessDeleteTitleDataOverride;
    FDelegateOnSuccessGetCatalogItems OnSuccessGetCatalogItems;
    FDelegateOnSuccessGetPublisherData OnSuccessGetPublisherData;
    FDelegateOnSuccessGetRandomResultTables OnSuccessGetRandomResultTables;
    FDelegateOnSuccessGetStoreItems OnSuccessGetStoreItems;
    FDelegateOnSuccessGetTitleData OnSuccessGetTitleData;
    FDelegateOnSuccessGetTitleInternalData OnSuccessGetTitleInternalData;
    FDelegateOnSuccessListVirtualCurrencyTypes OnSuccessListVirtualCurrencyTypes;
    FDelegateOnSuccessRemoveVirtualCurrencyTypes OnSuccessRemoveVirtualCurrencyTypes;
    FDelegateOnSuccessSetCatalogItems OnSuccessSetCatalogItems;
    FDelegateOnSuccessSetStoreItems OnSuccessSetStoreItems;
    FDelegateOnSuccessSetTitleData OnSuccessSetTitleData;
    FDelegateOnSuccessSetTitleDataAndOverrides OnSuccessSetTitleDataAndOverrides;
    FDelegateOnSuccessSetTitleInternalData OnSuccessSetTitleInternalData;
    FDelegateOnSuccessSetupPushNotification OnSuccessSetupPushNotification;
    FDelegateOnSuccessUpdateCatalogItems OnSuccessUpdateCatalogItems;
    FDelegateOnSuccessUpdateRandomResultTables OnSuccessUpdateRandomResultTables;
    FDelegateOnSuccessUpdateStoreItems OnSuccessUpdateStoreItems;

private:
    UPROPERTY()
        UPlayFabAuthenticationContext* CallAuthenticationContext;

    /** Internal bind function for the IHTTPRequest::OnProcessRequestCompleted() event */
    void OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

protected:
    /** Internal request data stored as JSON */
    UPROPERTY()
        UPlayFabJsonObject* RequestJsonObj;

    /** Response data stored as JSON */
    UPROPERTY()
        UPlayFabJsonObject* ResponseJsonObj;

    /** Mapping of header section to values. Used to generate final header string for request */
    TMap<FString, FString> RequestHeaders;
};
