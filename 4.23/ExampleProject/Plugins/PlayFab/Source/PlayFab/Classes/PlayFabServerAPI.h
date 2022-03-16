//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated header file for the UE4 PlayFab plugin.
// This header file contains the function definitions.
//
// API: Server
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Http.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "PlayFabBaseModel.h"
#include "PlayFabServerModels.h"
#include "PlayFabServerAPI.generated.h"

class UPlayFabAuthenticationContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPlayFabServerRequestCompleted, FPlayFabBaseModel, response, UObject*, customData, bool, successful);

UCLASS(Blueprintable, BlueprintType)
class PLAYFAB_API UPlayFabServerAPI : public UOnlineBlueprintCallProxyBase
{
    GENERATED_UCLASS_BODY()

public:
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnFailurePlayFabError, FPlayFabError, error, UObject*, customData);

    UPROPERTY(BlueprintAssignable)
        FOnPlayFabServerRequestCompleted OnPlayFabResponse;

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
    // Generated PlayFab Server API Functions
    //////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////
    // Account Management
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAddGenericID, FServerEmptyResult, result, UObject*, customData);

    /**
     * Adds the specified generic service identifier to the player's PlayFab account. This is designed to allow for a PlayFab
     * ID lookup of any arbitrary service identifier a title wants to add. This identifier should never be used as
     * authentication credentials, as the intent is that it is easily accessible by other players.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* AddGenericID(FServerAddGenericIDRequest request,
            FDelegateOnSuccessAddGenericID onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAddGenericID(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessBanUsers, FServerBanUsersResult, result, UObject*, customData);

    /** Bans users by PlayFab ID with optional IP address, or MAC address for the provided game. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* BanUsers(FServerBanUsersRequest request,
            FDelegateOnSuccessBanUsers onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperBanUsers(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeletePlayer, FServerDeletePlayerResult, result, UObject*, customData);

    /** Removes a user's player account from a title and deletes all associated data */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* DeletePlayer(FServerDeletePlayerRequest request,
            FDelegateOnSuccessDeletePlayer onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeletePlayer(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeletePushNotificationTemplate, FServerDeletePushNotificationTemplateResult, result, UObject*, customData);

    /** Deletes push notification template for title */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* DeletePushNotificationTemplate(FServerDeletePushNotificationTemplateRequest request,
            FDelegateOnSuccessDeletePushNotificationTemplate onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeletePushNotificationTemplate(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayerProfile, FServerGetPlayerProfileResult, result, UObject*, customData);

    /** Retrieves the player's profile */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetPlayerProfile(FServerGetPlayerProfileRequest request,
            FDelegateOnSuccessGetPlayerProfile onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayerProfile(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayFabIDsFromFacebookIDs, FServerGetPlayFabIDsFromFacebookIDsResult, result, UObject*, customData);

    /** Retrieves the unique PlayFab identifiers for the given set of Facebook identifiers. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetPlayFabIDsFromFacebookIDs(FServerGetPlayFabIDsFromFacebookIDsRequest request,
            FDelegateOnSuccessGetPlayFabIDsFromFacebookIDs onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayFabIDsFromFacebookIDs(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayFabIDsFromFacebookInstantGamesIds, FServerGetPlayFabIDsFromFacebookInstantGamesIdsResult, result, UObject*, customData);

    /** Retrieves the unique PlayFab identifiers for the given set of Facebook Instant Games identifiers. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetPlayFabIDsFromFacebookInstantGamesIds(FServerGetPlayFabIDsFromFacebookInstantGamesIdsRequest request,
            FDelegateOnSuccessGetPlayFabIDsFromFacebookInstantGamesIds onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayFabIDsFromFacebookInstantGamesIds(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayFabIDsFromGenericIDs, FServerGetPlayFabIDsFromGenericIDsResult, result, UObject*, customData);

    /**
     * Retrieves the unique PlayFab identifiers for the given set of generic service identifiers. A generic identifier is the
     * service name plus the service-specific ID for the player, as specified by the title when the generic identifier was
     * added to the player account.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetPlayFabIDsFromGenericIDs(FServerGetPlayFabIDsFromGenericIDsRequest request,
            FDelegateOnSuccessGetPlayFabIDsFromGenericIDs onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayFabIDsFromGenericIDs(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayFabIDsFromNintendoSwitchDeviceIds, FServerGetPlayFabIDsFromNintendoSwitchDeviceIdsResult, result, UObject*, customData);

    /** Retrieves the unique PlayFab identifiers for the given set of Nintendo Switch Device identifiers. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetPlayFabIDsFromNintendoSwitchDeviceIds(FServerGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest request,
            FDelegateOnSuccessGetPlayFabIDsFromNintendoSwitchDeviceIds onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayFabIDsFromNintendoSwitchDeviceIds(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayFabIDsFromPSNAccountIDs, FServerGetPlayFabIDsFromPSNAccountIDsResult, result, UObject*, customData);

    /** Retrieves the unique PlayFab identifiers for the given set of PlayStation Network identifiers. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetPlayFabIDsFromPSNAccountIDs(FServerGetPlayFabIDsFromPSNAccountIDsRequest request,
            FDelegateOnSuccessGetPlayFabIDsFromPSNAccountIDs onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayFabIDsFromPSNAccountIDs(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayFabIDsFromSteamIDs, FServerGetPlayFabIDsFromSteamIDsResult, result, UObject*, customData);

    /**
     * Retrieves the unique PlayFab identifiers for the given set of Steam identifiers. The Steam identifiers are the profile
     * IDs for the user accounts, available as SteamId in the Steamworks Community API calls.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetPlayFabIDsFromSteamIDs(FServerGetPlayFabIDsFromSteamIDsRequest request,
            FDelegateOnSuccessGetPlayFabIDsFromSteamIDs onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayFabIDsFromSteamIDs(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayFabIDsFromXboxLiveIDs, FServerGetPlayFabIDsFromXboxLiveIDsResult, result, UObject*, customData);

    /** Retrieves the unique PlayFab identifiers for the given set of XboxLive identifiers. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetPlayFabIDsFromXboxLiveIDs(FServerGetPlayFabIDsFromXboxLiveIDsRequest request,
            FDelegateOnSuccessGetPlayFabIDsFromXboxLiveIDs onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayFabIDsFromXboxLiveIDs(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetServerCustomIDsFromPlayFabIDs, FServerGetServerCustomIDsFromPlayFabIDsResult, result, UObject*, customData);

    /** Retrieves the associated PlayFab account identifiers for the given set of server custom identifiers. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetServerCustomIDsFromPlayFabIDs(FServerGetServerCustomIDsFromPlayFabIDsRequest request,
            FDelegateOnSuccessGetServerCustomIDsFromPlayFabIDs onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetServerCustomIDsFromPlayFabIDs(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetUserAccountInfo, FServerGetUserAccountInfoResult, result, UObject*, customData);

    /** Retrieves the relevant details for a specified user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetUserAccountInfo(FServerGetUserAccountInfoRequest request,
            FDelegateOnSuccessGetUserAccountInfo onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetUserAccountInfo(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetUserBans, FServerGetUserBansResult, result, UObject*, customData);

    /** Gets all bans for a user. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetUserBans(FServerGetUserBansRequest request,
            FDelegateOnSuccessGetUserBans onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetUserBans(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLinkPSNAccount, FServerLinkPSNAccountResult, result, UObject*, customData);

    /** Links the PlayStation Network account associated with the provided access code to the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* LinkPSNAccount(FServerLinkPSNAccountRequest request,
            FDelegateOnSuccessLinkPSNAccount onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLinkPSNAccount(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLinkServerCustomId, FServerLinkServerCustomIdResult, result, UObject*, customData);

    /** Links the custom server identifier, generated by the title, to the user's PlayFab account. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* LinkServerCustomId(FServerLinkServerCustomIdRequest request,
            FDelegateOnSuccessLinkServerCustomId onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLinkServerCustomId(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLinkXboxAccount, FServerLinkXboxAccountResult, result, UObject*, customData);

    /** Links the Xbox Live account associated with the provided access code to the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* LinkXboxAccount(FServerLinkXboxAccountRequest request,
            FDelegateOnSuccessLinkXboxAccount onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLinkXboxAccount(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRemoveGenericID, FServerEmptyResult, result, UObject*, customData);

    /** Removes the specified generic service identifier from the player's PlayFab account. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* RemoveGenericID(FServerRemoveGenericIDRequest request,
            FDelegateOnSuccessRemoveGenericID onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRemoveGenericID(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRevokeAllBansForUser, FServerRevokeAllBansForUserResult, result, UObject*, customData);

    /** Revoke all active bans for a user. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* RevokeAllBansForUser(FServerRevokeAllBansForUserRequest request,
            FDelegateOnSuccessRevokeAllBansForUser onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRevokeAllBansForUser(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRevokeBans, FServerRevokeBansResult, result, UObject*, customData);

    /** Revoke all active bans specified with BanId. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* RevokeBans(FServerRevokeBansRequest request,
            FDelegateOnSuccessRevokeBans onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRevokeBans(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSavePushNotificationTemplate, FServerSavePushNotificationTemplateResult, result, UObject*, customData);

    /** Saves push notification template for title */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* SavePushNotificationTemplate(FServerSavePushNotificationTemplateRequest request,
            FDelegateOnSuccessSavePushNotificationTemplate onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSavePushNotificationTemplate(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSendCustomAccountRecoveryEmail, FServerSendCustomAccountRecoveryEmailResult, result, UObject*, customData);

    /**
     * Forces an email to be sent to the registered contact email address for the user's account based on an account recovery
     * email template
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* SendCustomAccountRecoveryEmail(FServerSendCustomAccountRecoveryEmailRequest request,
            FDelegateOnSuccessSendCustomAccountRecoveryEmail onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSendCustomAccountRecoveryEmail(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSendEmailFromTemplate, FServerSendEmailFromTemplateResult, result, UObject*, customData);

    /** Sends an email based on an email template to a player's contact email */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* SendEmailFromTemplate(FServerSendEmailFromTemplateRequest request,
            FDelegateOnSuccessSendEmailFromTemplate onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSendEmailFromTemplate(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSendPushNotification, FServerSendPushNotificationResult, result, UObject*, customData);

    /**
     * Sends an iOS/Android Push Notification to a specific user, if that user's device has been configured for Push
     * Notifications in PlayFab. If a user has linked both Android and iOS devices, both will be notified.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* SendPushNotification(FServerSendPushNotificationRequest request,
            FDelegateOnSuccessSendPushNotification onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSendPushNotification(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSendPushNotificationFromTemplate, FServerSendPushNotificationResult, result, UObject*, customData);

    /**
     * Sends an iOS/Android Push Notification template to a specific user, if that user's device has been configured for Push
     * Notifications in PlayFab. If a user has linked both Android and iOS devices, both will be notified.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* SendPushNotificationFromTemplate(FServerSendPushNotificationFromTemplateRequest request,
            FDelegateOnSuccessSendPushNotificationFromTemplate onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSendPushNotificationFromTemplate(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlinkPSNAccount, FServerUnlinkPSNAccountResult, result, UObject*, customData);

    /** Unlinks the related PSN account from the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UnlinkPSNAccount(FServerUnlinkPSNAccountRequest request,
            FDelegateOnSuccessUnlinkPSNAccount onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlinkPSNAccount(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlinkServerCustomId, FServerUnlinkServerCustomIdResult, result, UObject*, customData);

    /** Unlinks the custom server identifier from the user's PlayFab account. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UnlinkServerCustomId(FServerUnlinkServerCustomIdRequest request,
            FDelegateOnSuccessUnlinkServerCustomId onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlinkServerCustomId(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlinkXboxAccount, FServerUnlinkXboxAccountResult, result, UObject*, customData);

    /** Unlinks the related Xbox Live account from the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UnlinkXboxAccount(FServerUnlinkXboxAccountRequest request,
            FDelegateOnSuccessUnlinkXboxAccount onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlinkXboxAccount(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateAvatarUrl, FServerEmptyResponse, result, UObject*, customData);

    /** Update the avatar URL of the specified player */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateAvatarUrl(FServerUpdateAvatarUrlRequest request,
            FDelegateOnSuccessUpdateAvatarUrl onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateAvatarUrl(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateBans, FServerUpdateBansResult, result, UObject*, customData);

    /** Updates information of a list of existing bans specified with Ban Ids. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateBans(FServerUpdateBansRequest request,
            FDelegateOnSuccessUpdateBans onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateBans(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Analytics
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessWriteCharacterEvent, FServerWriteEventResponse, result, UObject*, customData);

    /** Writes a character-based event into PlayStream. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* WriteCharacterEvent(FServerWriteServerCharacterEventRequest request,
            FDelegateOnSuccessWriteCharacterEvent onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperWriteCharacterEvent(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessWritePlayerEvent, FServerWriteEventResponse, result, UObject*, customData);

    /** Writes a player-based event into PlayStream. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* WritePlayerEvent(FServerWriteServerPlayerEventRequest request,
            FDelegateOnSuccessWritePlayerEvent onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperWritePlayerEvent(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessWriteTitleEvent, FServerWriteEventResponse, result, UObject*, customData);

    /** Writes a title-based event into PlayStream. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* WriteTitleEvent(FServerWriteTitleEventRequest request,
            FDelegateOnSuccessWriteTitleEvent onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperWriteTitleEvent(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Authentication
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAuthenticateSessionTicket, FServerAuthenticateSessionTicketResult, result, UObject*, customData);

    /** Validated a client's session ticket, and if successful, returns details for that user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* AuthenticateSessionTicket(FServerAuthenticateSessionTicketRequest request,
            FDelegateOnSuccessAuthenticateSessionTicket onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAuthenticateSessionTicket(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLoginWithServerCustomId, FServerServerLoginResult, result, UObject*, customData);

    /**
     * Securely login a game client from an external server backend using a custom identifier for that player. Server Custom ID
     * and Client Custom ID are mutually exclusive and cannot be used to retrieve the same player account.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* LoginWithServerCustomId(FServerLoginWithServerCustomIdRequest request,
            FDelegateOnSuccessLoginWithServerCustomId onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLoginWithServerCustomId(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLoginWithSteamId, FServerServerLoginResult, result, UObject*, customData);

    /**
     * Signs the user in using an Steam ID, returning a session identifier that can subsequently be used for API calls which
     * require an authenticated user
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* LoginWithSteamId(FServerLoginWithSteamIdRequest request,
            FDelegateOnSuccessLoginWithSteamId onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLoginWithSteamId(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLoginWithXbox, FServerServerLoginResult, result, UObject*, customData);

    /**
     * Signs the user in using a Xbox Live Token from an external server backend, returning a session identifier that can
     * subsequently be used for API calls which require an authenticated user
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* LoginWithXbox(FServerLoginWithXboxRequest request,
            FDelegateOnSuccessLoginWithXbox onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLoginWithXbox(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLoginWithXboxId, FServerServerLoginResult, result, UObject*, customData);

    /**
     * Signs the user in using an Xbox ID and Sandbox ID, returning a session identifier that can subsequently be used for API
     * calls which require an authenticated user
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* LoginWithXboxId(FServerLoginWithXboxIdRequest request,
            FDelegateOnSuccessLoginWithXboxId onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLoginWithXboxId(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetPlayerSecret, FServerSetPlayerSecretResult, result, UObject*, customData);

    /**
     * Sets the player's secret if it is not already set. Player secrets are used to sign API requests. To reset a player's
     * secret use the Admin or Server API method SetPlayerSecret.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* SetPlayerSecret(FServerSetPlayerSecretRequest request,
            FDelegateOnSuccessSetPlayerSecret onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetPlayerSecret(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Character Data
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetCharacterData, FServerGetCharacterDataResult, result, UObject*, customData);

    /** Retrieves the title-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetCharacterData(FServerGetCharacterDataRequest request,
            FDelegateOnSuccessGetCharacterData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetCharacterData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetCharacterInternalData, FServerGetCharacterDataResult, result, UObject*, customData);

    /** Retrieves the title-specific custom data for the user's character which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetCharacterInternalData(FServerGetCharacterDataRequest request,
            FDelegateOnSuccessGetCharacterInternalData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetCharacterInternalData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetCharacterReadOnlyData, FServerGetCharacterDataResult, result, UObject*, customData);

    /** Retrieves the title-specific custom data for the user's character which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetCharacterReadOnlyData(FServerGetCharacterDataRequest request,
            FDelegateOnSuccessGetCharacterReadOnlyData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetCharacterReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateCharacterData, FServerUpdateCharacterDataResult, result, UObject*, customData);

    /** Updates the title-specific custom data for the user's character which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateCharacterData(FServerUpdateCharacterDataRequest request,
            FDelegateOnSuccessUpdateCharacterData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateCharacterData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateCharacterInternalData, FServerUpdateCharacterDataResult, result, UObject*, customData);

    /** Updates the title-specific custom data for the user's character which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateCharacterInternalData(FServerUpdateCharacterDataRequest request,
            FDelegateOnSuccessUpdateCharacterInternalData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateCharacterInternalData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateCharacterReadOnlyData, FServerUpdateCharacterDataResult, result, UObject*, customData);

    /** Updates the title-specific custom data for the user's character which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateCharacterReadOnlyData(FServerUpdateCharacterDataRequest request,
            FDelegateOnSuccessUpdateCharacterReadOnlyData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateCharacterReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Characters
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteCharacterFromUser, FServerDeleteCharacterFromUserResult, result, UObject*, customData);

    /** Deletes the specific character ID from the specified user. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* DeleteCharacterFromUser(FServerDeleteCharacterFromUserRequest request,
            FDelegateOnSuccessDeleteCharacterFromUser onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteCharacterFromUser(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetAllUsersCharacters, FServerListUsersCharactersResult, result, UObject*, customData);

    /**
     * Lists all of the characters that belong to a specific user. CharacterIds are not globally unique; characterId must be
     * evaluated with the parent PlayFabId to guarantee uniqueness.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetAllUsersCharacters(FServerListUsersCharactersRequest request,
            FDelegateOnSuccessGetAllUsersCharacters onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetAllUsersCharacters(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetCharacterLeaderboard, FServerGetCharacterLeaderboardResult, result, UObject*, customData);

    /** Retrieves a list of ranked characters for the given statistic, starting from the indicated point in the leaderboard */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetCharacterLeaderboard(FServerGetCharacterLeaderboardRequest request,
            FDelegateOnSuccessGetCharacterLeaderboard onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetCharacterLeaderboard(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetCharacterStatistics, FServerGetCharacterStatisticsResult, result, UObject*, customData);

    /** Retrieves the details of all title-specific statistics for the specific character */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetCharacterStatistics(FServerGetCharacterStatisticsRequest request,
            FDelegateOnSuccessGetCharacterStatistics onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetCharacterStatistics(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetLeaderboardAroundCharacter, FServerGetLeaderboardAroundCharacterResult, result, UObject*, customData);

    /** Retrieves a list of ranked characters for the given statistic, centered on the requested user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetLeaderboardAroundCharacter(FServerGetLeaderboardAroundCharacterRequest request,
            FDelegateOnSuccessGetLeaderboardAroundCharacter onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetLeaderboardAroundCharacter(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetLeaderboardForUserCharacters, FServerGetLeaderboardForUsersCharactersResult, result, UObject*, customData);

    /** Retrieves a list of all of the user's characters for the given statistic. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetLeaderboardForUserCharacters(FServerGetLeaderboardForUsersCharactersRequest request,
            FDelegateOnSuccessGetLeaderboardForUserCharacters onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetLeaderboardForUserCharacters(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGrantCharacterToUser, FServerGrantCharacterToUserResult, result, UObject*, customData);

    /**
     * Grants the specified character type to the user. CharacterIds are not globally unique; characterId must be evaluated
     * with the parent PlayFabId to guarantee uniqueness.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GrantCharacterToUser(FServerGrantCharacterToUserRequest request,
            FDelegateOnSuccessGrantCharacterToUser onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGrantCharacterToUser(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateCharacterStatistics, FServerUpdateCharacterStatisticsResult, result, UObject*, customData);

    /** Updates the values of the specified title-specific statistics for the specific character */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateCharacterStatistics(FServerUpdateCharacterStatisticsRequest request,
            FDelegateOnSuccessUpdateCharacterStatistics onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateCharacterStatistics(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Content
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetContentDownloadUrl, FServerGetContentDownloadUrlResult, result, UObject*, customData);

    /**
     * This API retrieves a pre-signed URL for accessing a content file for the title. A subsequent HTTP GET to the returned
     * URL will attempt to download the content. A HEAD query to the returned URL will attempt to retrieve the metadata of the
     * content. Note that a successful result does not guarantee the existence of this content - if it has not been uploaded,
     * the query to retrieve the data will fail. See this post for more information:
     * https://community.playfab.com/hc/community/posts/205469488-How-to-upload-files-to-PlayFab-s-Content-Service. Also,
     * please be aware that the Content service is specifically PlayFab's CDN offering, for which standard CDN rates apply.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Content ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetContentDownloadUrl(FServerGetContentDownloadUrlRequest request,
            FDelegateOnSuccessGetContentDownloadUrl onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Content ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetContentDownloadUrl(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Friend List Management
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAddFriend, FServerEmptyResponse, result, UObject*, customData);

    /**
     * Adds the Friend user to the friendlist of the user with PlayFabId. At least one of
     * FriendPlayFabId,FriendUsername,FriendEmail, or FriendTitleDisplayName should be initialized.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Friend List Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* AddFriend(FServerAddFriendRequest request,
            FDelegateOnSuccessAddFriend onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Friend List Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAddFriend(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetFriendsList, FServerGetFriendsListResult, result, UObject*, customData);

    /**
     * Retrieves the current friends for the user with PlayFabId, constrained to users who have PlayFab accounts. Friends from
     * linked accounts (Facebook, Steam) are also included. You may optionally exclude some linked services' friends.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Friend List Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetFriendsList(FServerGetFriendsListRequest request,
            FDelegateOnSuccessGetFriendsList onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Friend List Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetFriendsList(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRemoveFriend, FServerEmptyResponse, result, UObject*, customData);

    /** Removes the specified friend from the the user's friend list */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Friend List Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* RemoveFriend(FServerRemoveFriendRequest request,
            FDelegateOnSuccessRemoveFriend onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Friend List Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRemoveFriend(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetFriendTags, FServerEmptyResponse, result, UObject*, customData);

    /** Updates the tag list for a specified user in the friend list of another user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Friend List Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* SetFriendTags(FServerSetFriendTagsRequest request,
            FDelegateOnSuccessSetFriendTags onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Friend List Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetFriendTags(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Matchmaking
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeregisterGame, FServerDeregisterGameResponse, result, UObject*, customData);

    /** Inform the matchmaker that a Game Server Instance is removed. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* DeregisterGame(FServerDeregisterGameRequest request,
            FDelegateOnSuccessDeregisterGame onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeregisterGame(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessNotifyMatchmakerPlayerLeft, FServerNotifyMatchmakerPlayerLeftResult, result, UObject*, customData);

    /** Informs the PlayFab match-making service that the user specified has left the Game Server Instance */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* NotifyMatchmakerPlayerLeft(FServerNotifyMatchmakerPlayerLeftRequest request,
            FDelegateOnSuccessNotifyMatchmakerPlayerLeft onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperNotifyMatchmakerPlayerLeft(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRedeemMatchmakerTicket, FServerRedeemMatchmakerTicketResult, result, UObject*, customData);

    /** Validates a Game Server session ticket and returns details about the user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* RedeemMatchmakerTicket(FServerRedeemMatchmakerTicketRequest request,
            FDelegateOnSuccessRedeemMatchmakerTicket onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRedeemMatchmakerTicket(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRefreshGameServerInstanceHeartbeat, FServerRefreshGameServerInstanceHeartbeatResult, result, UObject*, customData);

    /** Set the state of the indicated Game Server Instance. Also update the heartbeat for the instance. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* RefreshGameServerInstanceHeartbeat(FServerRefreshGameServerInstanceHeartbeatRequest request,
            FDelegateOnSuccessRefreshGameServerInstanceHeartbeat onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRefreshGameServerInstanceHeartbeat(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRegisterGame, FServerRegisterGameResponse, result, UObject*, customData);

    /** Inform the matchmaker that a new Game Server Instance is added. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* RegisterGame(FServerRegisterGameRequest request,
            FDelegateOnSuccessRegisterGame onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRegisterGame(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetGameServerInstanceData, FServerSetGameServerInstanceDataResult, result, UObject*, customData);

    /** Sets the custom data of the indicated Game Server Instance */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* SetGameServerInstanceData(FServerSetGameServerInstanceDataRequest request,
            FDelegateOnSuccessSetGameServerInstanceData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetGameServerInstanceData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetGameServerInstanceState, FServerSetGameServerInstanceStateResult, result, UObject*, customData);

    /** Set the state of the indicated Game Server Instance. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* SetGameServerInstanceState(FServerSetGameServerInstanceStateRequest request,
            FDelegateOnSuccessSetGameServerInstanceState onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetGameServerInstanceState(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetGameServerInstanceTags, FServerSetGameServerInstanceTagsResult, result, UObject*, customData);

    /** Set custom tags for the specified Game Server Instance */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* SetGameServerInstanceTags(FServerSetGameServerInstanceTagsRequest request,
            FDelegateOnSuccessSetGameServerInstanceTags onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetGameServerInstanceTags(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Platform Specific Methods
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAwardSteamAchievement, FServerAwardSteamAchievementResult, result, UObject*, customData);

    /** Awards the specified users the specified Steam achievements */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* AwardSteamAchievement(FServerAwardSteamAchievementRequest request,
            FDelegateOnSuccessAwardSteamAchievement onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAwardSteamAchievement(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Player Data Management
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetFriendLeaderboard, FServerGetLeaderboardResult, result, UObject*, customData);

    /**
     * Retrieves a list of ranked friends of the given player for the given statistic, starting from the indicated point in the
     * leaderboard
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetFriendLeaderboard(FServerGetFriendLeaderboardRequest request,
            FDelegateOnSuccessGetFriendLeaderboard onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetFriendLeaderboard(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetLeaderboard, FServerGetLeaderboardResult, result, UObject*, customData);

    /** Retrieves a list of ranked users for the given statistic, starting from the indicated point in the leaderboard */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetLeaderboard(FServerGetLeaderboardRequest request,
            FDelegateOnSuccessGetLeaderboard onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetLeaderboard(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetLeaderboardAroundUser, FServerGetLeaderboardAroundUserResult, result, UObject*, customData);

    /** Retrieves a list of ranked users for the given statistic, centered on the currently signed-in user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetLeaderboardAroundUser(FServerGetLeaderboardAroundUserRequest request,
            FDelegateOnSuccessGetLeaderboardAroundUser onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetLeaderboardAroundUser(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayerCombinedInfo, FServerGetPlayerCombinedInfoResult, result, UObject*, customData);

    /**
     * Returns whatever info is requested in the response for the user. Note that PII (like email address, facebook id) may be
     * returned. All parameters default to false.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetPlayerCombinedInfo(FServerGetPlayerCombinedInfoRequest request,
            FDelegateOnSuccessGetPlayerCombinedInfo onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayerCombinedInfo(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayerStatistics, FServerGetPlayerStatisticsResult, result, UObject*, customData);

    /** Retrieves the current version and values for the indicated statistics, for the local player. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetPlayerStatistics(FServerGetPlayerStatisticsRequest request,
            FDelegateOnSuccessGetPlayerStatistics onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayerStatistics(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayerStatisticVersions, FServerGetPlayerStatisticVersionsResult, result, UObject*, customData);

    /** Retrieves the information on the available versions of the specified statistic. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetPlayerStatisticVersions(FServerGetPlayerStatisticVersionsRequest request,
            FDelegateOnSuccessGetPlayerStatisticVersions onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayerStatisticVersions(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetUserData, FServerGetUserDataResult, result, UObject*, customData);

    /** Retrieves the title-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetUserData(FServerGetUserDataRequest request,
            FDelegateOnSuccessGetUserData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetUserData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetUserInternalData, FServerGetUserDataResult, result, UObject*, customData);

    /** Retrieves the title-specific custom data for the user which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetUserInternalData(FServerGetUserDataRequest request,
            FDelegateOnSuccessGetUserInternalData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetUserInternalData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetUserPublisherData, FServerGetUserDataResult, result, UObject*, customData);

    /** Retrieves the publisher-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetUserPublisherData(FServerGetUserDataRequest request,
            FDelegateOnSuccessGetUserPublisherData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetUserPublisherData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetUserPublisherInternalData, FServerGetUserDataResult, result, UObject*, customData);

    /** Retrieves the publisher-specific custom data for the user which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetUserPublisherInternalData(FServerGetUserDataRequest request,
            FDelegateOnSuccessGetUserPublisherInternalData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetUserPublisherInternalData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetUserPublisherReadOnlyData, FServerGetUserDataResult, result, UObject*, customData);

    /** Retrieves the publisher-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetUserPublisherReadOnlyData(FServerGetUserDataRequest request,
            FDelegateOnSuccessGetUserPublisherReadOnlyData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetUserPublisherReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetUserReadOnlyData, FServerGetUserDataResult, result, UObject*, customData);

    /** Retrieves the title-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetUserReadOnlyData(FServerGetUserDataRequest request,
            FDelegateOnSuccessGetUserReadOnlyData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetUserReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdatePlayerStatistics, FServerUpdatePlayerStatisticsResult, result, UObject*, customData);

    /** Updates the values of the specified title-specific statistics for the user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdatePlayerStatistics(FServerUpdatePlayerStatisticsRequest request,
            FDelegateOnSuccessUpdatePlayerStatistics onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdatePlayerStatistics(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateUserData, FServerUpdateUserDataResult, result, UObject*, customData);

    /** Updates the title-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateUserData(FServerUpdateUserDataRequest request,
            FDelegateOnSuccessUpdateUserData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateUserData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateUserInternalData, FServerUpdateUserDataResult, result, UObject*, customData);

    /** Updates the title-specific custom data for the user which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateUserInternalData(FServerUpdateUserInternalDataRequest request,
            FDelegateOnSuccessUpdateUserInternalData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateUserInternalData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateUserPublisherData, FServerUpdateUserDataResult, result, UObject*, customData);

    /** Updates the publisher-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateUserPublisherData(FServerUpdateUserDataRequest request,
            FDelegateOnSuccessUpdateUserPublisherData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateUserPublisherData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateUserPublisherInternalData, FServerUpdateUserDataResult, result, UObject*, customData);

    /** Updates the publisher-specific custom data for the user which cannot be accessed by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateUserPublisherInternalData(FServerUpdateUserInternalDataRequest request,
            FDelegateOnSuccessUpdateUserPublisherInternalData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateUserPublisherInternalData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateUserPublisherReadOnlyData, FServerUpdateUserDataResult, result, UObject*, customData);

    /** Updates the publisher-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateUserPublisherReadOnlyData(FServerUpdateUserDataRequest request,
            FDelegateOnSuccessUpdateUserPublisherReadOnlyData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateUserPublisherReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateUserReadOnlyData, FServerUpdateUserDataResult, result, UObject*, customData);

    /** Updates the title-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateUserReadOnlyData(FServerUpdateUserDataRequest request,
            FDelegateOnSuccessUpdateUserReadOnlyData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateUserReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Player Item Management
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAddCharacterVirtualCurrency, FServerModifyCharacterVirtualCurrencyResult, result, UObject*, customData);

    /** Increments the character's balance of the specified virtual currency by the stated amount */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* AddCharacterVirtualCurrency(FServerAddCharacterVirtualCurrencyRequest request,
            FDelegateOnSuccessAddCharacterVirtualCurrency onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAddCharacterVirtualCurrency(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAddUserVirtualCurrency, FServerModifyUserVirtualCurrencyResult, result, UObject*, customData);

    /** Increments the user's balance of the specified virtual currency by the stated amount */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* AddUserVirtualCurrency(FServerAddUserVirtualCurrencyRequest request,
            FDelegateOnSuccessAddUserVirtualCurrency onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAddUserVirtualCurrency(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessConsumeItem, FServerConsumeItemResult, result, UObject*, customData);

    /** Consume uses of a consumable item. When all uses are consumed, it will be removed from the player's inventory. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* ConsumeItem(FServerConsumeItemRequest request,
            FDelegateOnSuccessConsumeItem onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperConsumeItem(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessEvaluateRandomResultTable, FServerEvaluateRandomResultTableResult, result, UObject*, customData);

    /**
     * Returns the result of an evaluation of a Random Result Table - the ItemId from the game Catalog which would have been
     * added to the player inventory, if the Random Result Table were added via a Bundle or a call to UnlockContainer.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* EvaluateRandomResultTable(FServerEvaluateRandomResultTableRequest request,
            FDelegateOnSuccessEvaluateRandomResultTable onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperEvaluateRandomResultTable(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetCharacterInventory, FServerGetCharacterInventoryResult, result, UObject*, customData);

    /** Retrieves the specified character's current inventory of virtual goods */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetCharacterInventory(FServerGetCharacterInventoryRequest request,
            FDelegateOnSuccessGetCharacterInventory onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetCharacterInventory(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetRandomResultTables, FServerGetRandomResultTablesResult, result, UObject*, customData);

    /**
     * Retrieves the configuration information for the specified random results tables for the title, including all ItemId
     * values and weights
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetRandomResultTables(FServerGetRandomResultTablesRequest request,
            FDelegateOnSuccessGetRandomResultTables onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetRandomResultTables(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetUserInventory, FServerGetUserInventoryResult, result, UObject*, customData);

    /** Retrieves the specified user's current inventory of virtual goods */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetUserInventory(FServerGetUserInventoryRequest request,
            FDelegateOnSuccessGetUserInventory onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetUserInventory(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGrantItemsToCharacter, FServerGrantItemsToCharacterResult, result, UObject*, customData);

    /** Adds the specified items to the specified character's inventory */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GrantItemsToCharacter(FServerGrantItemsToCharacterRequest request,
            FDelegateOnSuccessGrantItemsToCharacter onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGrantItemsToCharacter(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGrantItemsToUser, FServerGrantItemsToUserResult, result, UObject*, customData);

    /** Adds the specified items to the specified user's inventory */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GrantItemsToUser(FServerGrantItemsToUserRequest request,
            FDelegateOnSuccessGrantItemsToUser onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGrantItemsToUser(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGrantItemsToUsers, FServerGrantItemsToUsersResult, result, UObject*, customData);

    /** Adds the specified items to the specified user inventories */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GrantItemsToUsers(FServerGrantItemsToUsersRequest request,
            FDelegateOnSuccessGrantItemsToUsers onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGrantItemsToUsers(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessModifyItemUses, FServerModifyItemUsesResult, result, UObject*, customData);

    /** Modifies the number of remaining uses of a player's inventory item */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* ModifyItemUses(FServerModifyItemUsesRequest request,
            FDelegateOnSuccessModifyItemUses onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperModifyItemUses(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessMoveItemToCharacterFromCharacter, FServerMoveItemToCharacterFromCharacterResult, result, UObject*, customData);

    /** Moves an item from a character's inventory into another of the users's character's inventory. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* MoveItemToCharacterFromCharacter(FServerMoveItemToCharacterFromCharacterRequest request,
            FDelegateOnSuccessMoveItemToCharacterFromCharacter onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperMoveItemToCharacterFromCharacter(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessMoveItemToCharacterFromUser, FServerMoveItemToCharacterFromUserResult, result, UObject*, customData);

    /** Moves an item from a user's inventory into their character's inventory. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* MoveItemToCharacterFromUser(FServerMoveItemToCharacterFromUserRequest request,
            FDelegateOnSuccessMoveItemToCharacterFromUser onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperMoveItemToCharacterFromUser(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessMoveItemToUserFromCharacter, FServerMoveItemToUserFromCharacterResult, result, UObject*, customData);

    /** Moves an item from a character's inventory into the owning user's inventory. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* MoveItemToUserFromCharacter(FServerMoveItemToUserFromCharacterRequest request,
            FDelegateOnSuccessMoveItemToUserFromCharacter onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperMoveItemToUserFromCharacter(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRedeemCoupon, FServerRedeemCouponResult, result, UObject*, customData);

    /**
     * Adds the virtual goods associated with the coupon to the user's inventory. Coupons can be generated via the
     * Economy->Catalogs tab in the PlayFab Game Manager.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* RedeemCoupon(FServerRedeemCouponRequest request,
            FDelegateOnSuccessRedeemCoupon onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRedeemCoupon(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessReportPlayer, FServerReportPlayerServerResult, result, UObject*, customData);

    /**
     * Submit a report about a player (due to bad bahavior, etc.) on behalf of another player, so that customer service
     * representatives for the title can take action concerning potentially toxic players.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* ReportPlayer(FServerReportPlayerServerRequest request,
            FDelegateOnSuccessReportPlayer onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperReportPlayer(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRevokeInventoryItem, FServerRevokeInventoryResult, result, UObject*, customData);

    /** Revokes access to an item in a user's inventory */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* RevokeInventoryItem(FServerRevokeInventoryItemRequest request,
            FDelegateOnSuccessRevokeInventoryItem onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRevokeInventoryItem(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRevokeInventoryItems, FServerRevokeInventoryItemsResult, result, UObject*, customData);

    /** Revokes access for up to 25 items across multiple users and characters. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* RevokeInventoryItems(FServerRevokeInventoryItemsRequest request,
            FDelegateOnSuccessRevokeInventoryItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRevokeInventoryItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSubtractCharacterVirtualCurrency, FServerModifyCharacterVirtualCurrencyResult, result, UObject*, customData);

    /**
     * Decrements the character's balance of the specified virtual currency by the stated amount. It is possible to make a VC
     * balance negative with this API.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* SubtractCharacterVirtualCurrency(FServerSubtractCharacterVirtualCurrencyRequest request,
            FDelegateOnSuccessSubtractCharacterVirtualCurrency onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSubtractCharacterVirtualCurrency(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSubtractUserVirtualCurrency, FServerModifyUserVirtualCurrencyResult, result, UObject*, customData);

    /**
     * Decrements the user's balance of the specified virtual currency by the stated amount. It is possible to make a VC
     * balance negative with this API.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* SubtractUserVirtualCurrency(FServerSubtractUserVirtualCurrencyRequest request,
            FDelegateOnSuccessSubtractUserVirtualCurrency onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSubtractUserVirtualCurrency(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlockContainerInstance, FServerUnlockContainerItemResult, result, UObject*, customData);

    /**
     * Opens a specific container (ContainerItemInstanceId), with a specific key (KeyItemInstanceId, when required), and
     * returns the contents of the opened container. If the container (and key when relevant) are consumable (RemainingUses >
     * 0), their RemainingUses will be decremented, consistent with the operation of ConsumeItem.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UnlockContainerInstance(FServerUnlockContainerInstanceRequest request,
            FDelegateOnSuccessUnlockContainerInstance onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlockContainerInstance(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlockContainerItem, FServerUnlockContainerItemResult, result, UObject*, customData);

    /**
     * Searches Player or Character inventory for any ItemInstance matching the given CatalogItemId, if necessary unlocks it
     * using any appropriate key, and returns the contents of the opened container. If the container (and key when relevant)
     * are consumable (RemainingUses > 0), their RemainingUses will be decremented, consistent with the operation of
     * ConsumeItem.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UnlockContainerItem(FServerUnlockContainerItemRequest request,
            FDelegateOnSuccessUnlockContainerItem onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlockContainerItem(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateUserInventoryItemCustomData, FServerEmptyResponse, result, UObject*, customData);

    /** Updates the key-value pair data tagged to the specified item, which is read-only from the client. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateUserInventoryItemCustomData(FServerUpdateUserInventoryItemDataRequest request,
            FDelegateOnSuccessUpdateUserInventoryItemCustomData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateUserInventoryItemCustomData(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // PlayStream
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAddPlayerTag, FServerAddPlayerTagResult, result, UObject*, customData);

    /** Adds a given tag to a player profile. The tag's namespace is automatically generated based on the source of the tag. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* AddPlayerTag(FServerAddPlayerTagRequest request,
            FDelegateOnSuccessAddPlayerTag onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAddPlayerTag(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetAllSegments, FServerGetAllSegmentsResult, result, UObject*, customData);

    /**
     * Retrieves an array of player segment definitions. Results from this can be used in subsequent API calls such as
     * GetPlayersInSegment which requires a Segment ID. While segment names can change the ID for that segment will not change.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetAllSegments(FServerGetAllSegmentsRequest request,
            FDelegateOnSuccessGetAllSegments onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetAllSegments(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayerSegments, FServerGetPlayerSegmentsResult, result, UObject*, customData);

    /** List all segments that a player currently belongs to at this moment in time. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetPlayerSegments(FServerGetPlayersSegmentsRequest request,
            FDelegateOnSuccessGetPlayerSegments onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayerSegments(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayersInSegment, FServerGetPlayersInSegmentResult, result, UObject*, customData);

    /**
     * Allows for paging through all players in a given segment. This API creates a snapshot of all player profiles that match
     * the segment definition at the time of its creation and lives through the Total Seconds to Live, refreshing its life span
     * on each subsequent use of the Continuation Token. Profiles that change during the course of paging will not be reflected
     * in the results. AB Test segments are currently not supported by this operation. NOTE: This API is limited to being
     * called 30 times in one minute. You will be returned an error if you exceed this threshold.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetPlayersInSegment(FServerGetPlayersInSegmentRequest request,
            FDelegateOnSuccessGetPlayersInSegment onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayersInSegment(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayerTags, FServerGetPlayerTagsResult, result, UObject*, customData);

    /** Get all tags with a given Namespace (optional) from a player profile. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetPlayerTags(FServerGetPlayerTagsRequest request,
            FDelegateOnSuccessGetPlayerTags onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayerTags(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRemovePlayerTag, FServerRemovePlayerTagResult, result, UObject*, customData);

    /** Remove a given tag from a player profile. The tag's namespace is automatically generated based on the source of the tag. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* RemovePlayerTag(FServerRemovePlayerTagRequest request,
            FDelegateOnSuccessRemovePlayerTag onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRemovePlayerTag(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Server-Side Cloud Script
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessExecuteCloudScript, FServerExecuteCloudScriptResult, result, UObject*, customData);

    /** Executes a CloudScript function, with the 'currentPlayerId' variable set to the specified PlayFabId parameter value. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* ExecuteCloudScript(FServerExecuteCloudScriptServerRequest request,
            FDelegateOnSuccessExecuteCloudScript onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperExecuteCloudScript(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Shared Group Data
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAddSharedGroupMembers, FServerAddSharedGroupMembersResult, result, UObject*, customData);

    /**
     * Adds users to the set of those able to update both the shared data, as well as the set of users in the group. Only users
     * in the group (and the server) can add new members. Shared Groups are designed for sharing data between a very small
     * number of players, please see our guide:
     * https://docs.microsoft.com/gaming/playfab/features/social/groups/using-shared-group-data
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* AddSharedGroupMembers(FServerAddSharedGroupMembersRequest request,
            FDelegateOnSuccessAddSharedGroupMembers onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAddSharedGroupMembers(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateSharedGroup, FServerCreateSharedGroupResult, result, UObject*, customData);

    /**
     * Requests the creation of a shared group object, containing key/value pairs which may be updated by all members of the
     * group. When created by a server, the group will initially have no members. Shared Groups are designed for sharing data
     * between a very small number of players, please see our guide:
     * https://docs.microsoft.com/gaming/playfab/features/social/groups/using-shared-group-data
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* CreateSharedGroup(FServerCreateSharedGroupRequest request,
            FDelegateOnSuccessCreateSharedGroup onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateSharedGroup(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteSharedGroup, FServerEmptyResponse, result, UObject*, customData);

    /**
     * Deletes a shared group, freeing up the shared group ID to be reused for a new group. Shared Groups are designed for
     * sharing data between a very small number of players, please see our guide:
     * https://docs.microsoft.com/gaming/playfab/features/social/groups/using-shared-group-data
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* DeleteSharedGroup(FServerDeleteSharedGroupRequest request,
            FDelegateOnSuccessDeleteSharedGroup onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteSharedGroup(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetSharedGroupData, FServerGetSharedGroupDataResult, result, UObject*, customData);

    /**
     * Retrieves data stored in a shared group object, as well as the list of members in the group. The server can access all
     * public and private group data. Shared Groups are designed for sharing data between a very small number of players,
     * please see our guide: https://docs.microsoft.com/gaming/playfab/features/social/groups/using-shared-group-data
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetSharedGroupData(FServerGetSharedGroupDataRequest request,
            FDelegateOnSuccessGetSharedGroupData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetSharedGroupData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRemoveSharedGroupMembers, FServerRemoveSharedGroupMembersResult, result, UObject*, customData);

    /**
     * Removes users from the set of those able to update the shared data and the set of users in the group. Only users in the
     * group can remove members. If as a result of the call, zero users remain with access, the group and its associated data
     * will be deleted. Shared Groups are designed for sharing data between a very small number of players, please see our
     * guide: https://docs.microsoft.com/gaming/playfab/features/social/groups/using-shared-group-data
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* RemoveSharedGroupMembers(FServerRemoveSharedGroupMembersRequest request,
            FDelegateOnSuccessRemoveSharedGroupMembers onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRemoveSharedGroupMembers(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateSharedGroupData, FServerUpdateSharedGroupDataResult, result, UObject*, customData);

    /**
     * Adds, updates, and removes data keys for a shared group object. If the permission is set to Public, all fields updated
     * or added in this call will be readable by users not in the group. By default, data permissions are set to Private.
     * Regardless of the permission setting, only members of the group (and the server) can update the data. Shared Groups are
     * designed for sharing data between a very small number of players, please see our guide:
     * https://docs.microsoft.com/gaming/playfab/features/social/groups/using-shared-group-data
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* UpdateSharedGroupData(FServerUpdateSharedGroupDataRequest request,
            FDelegateOnSuccessUpdateSharedGroupData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateSharedGroupData(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Title-Wide Data Management
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetCatalogItems, FServerGetCatalogItemsResult, result, UObject*, customData);

    /** Retrieves the specified version of the title's catalog of virtual goods, including all defined properties */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetCatalogItems(FServerGetCatalogItemsRequest request,
            FDelegateOnSuccessGetCatalogItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetCatalogItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPublisherData, FServerGetPublisherDataResult, result, UObject*, customData);

    /** Retrieves the key-value store of custom publisher settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetPublisherData(FServerGetPublisherDataRequest request,
            FDelegateOnSuccessGetPublisherData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPublisherData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetStoreItems, FServerGetStoreItemsResult, result, UObject*, customData);

    /** Retrieves the set of items defined for the specified store, including all prices defined, for the specified player */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetStoreItems(FServerGetStoreItemsServerRequest request,
            FDelegateOnSuccessGetStoreItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetStoreItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetTime, FServerGetTimeResult, result, UObject*, customData);

    /** Retrieves the current server time */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetTime(FServerGetTimeRequest request,
            FDelegateOnSuccessGetTime onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetTime(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetTitleData, FServerGetTitleDataResult, result, UObject*, customData);

    /** Retrieves the key-value store of custom title settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetTitleData(FServerGetTitleDataRequest request,
            FDelegateOnSuccessGetTitleData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetTitleData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetTitleInternalData, FServerGetTitleDataResult, result, UObject*, customData);

    /** Retrieves the key-value store of custom internal title settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetTitleInternalData(FServerGetTitleDataRequest request,
            FDelegateOnSuccessGetTitleInternalData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetTitleInternalData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetTitleNews, FServerGetTitleNewsResult, result, UObject*, customData);

    /** Retrieves the title news feed, as configured in the developer portal */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* GetTitleNews(FServerGetTitleNewsRequest request,
            FDelegateOnSuccessGetTitleNews onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetTitleNews(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetPublisherData, FServerSetPublisherDataResult, result, UObject*, customData);

    /** Updates the key-value store of custom publisher settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* SetPublisherData(FServerSetPublisherDataRequest request,
            FDelegateOnSuccessSetPublisherData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetPublisherData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetTitleData, FServerSetTitleDataResult, result, UObject*, customData);

    /** Updates the key-value store of custom title settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* SetTitleData(FServerSetTitleDataRequest request,
            FDelegateOnSuccessSetTitleData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetTitleData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetTitleInternalData, FServerSetTitleDataResult, result, UObject*, customData);

    /** Updates the key-value store of custom title settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabServerAPI* SetTitleInternalData(FServerSetTitleDataRequest request,
            FDelegateOnSuccessSetTitleInternalData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabServerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetTitleInternalData(FPlayFabBaseModel response, UObject* customData, bool successful);



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
    FDelegateOnSuccessAddGenericID OnSuccessAddGenericID;
    FDelegateOnSuccessBanUsers OnSuccessBanUsers;
    FDelegateOnSuccessDeletePlayer OnSuccessDeletePlayer;
    FDelegateOnSuccessDeletePushNotificationTemplate OnSuccessDeletePushNotificationTemplate;
    FDelegateOnSuccessGetPlayerProfile OnSuccessGetPlayerProfile;
    FDelegateOnSuccessGetPlayFabIDsFromFacebookIDs OnSuccessGetPlayFabIDsFromFacebookIDs;
    FDelegateOnSuccessGetPlayFabIDsFromFacebookInstantGamesIds OnSuccessGetPlayFabIDsFromFacebookInstantGamesIds;
    FDelegateOnSuccessGetPlayFabIDsFromGenericIDs OnSuccessGetPlayFabIDsFromGenericIDs;
    FDelegateOnSuccessGetPlayFabIDsFromNintendoSwitchDeviceIds OnSuccessGetPlayFabIDsFromNintendoSwitchDeviceIds;
    FDelegateOnSuccessGetPlayFabIDsFromPSNAccountIDs OnSuccessGetPlayFabIDsFromPSNAccountIDs;
    FDelegateOnSuccessGetPlayFabIDsFromSteamIDs OnSuccessGetPlayFabIDsFromSteamIDs;
    FDelegateOnSuccessGetPlayFabIDsFromXboxLiveIDs OnSuccessGetPlayFabIDsFromXboxLiveIDs;
    FDelegateOnSuccessGetServerCustomIDsFromPlayFabIDs OnSuccessGetServerCustomIDsFromPlayFabIDs;
    FDelegateOnSuccessGetUserAccountInfo OnSuccessGetUserAccountInfo;
    FDelegateOnSuccessGetUserBans OnSuccessGetUserBans;
    FDelegateOnSuccessLinkPSNAccount OnSuccessLinkPSNAccount;
    FDelegateOnSuccessLinkServerCustomId OnSuccessLinkServerCustomId;
    FDelegateOnSuccessLinkXboxAccount OnSuccessLinkXboxAccount;
    FDelegateOnSuccessRemoveGenericID OnSuccessRemoveGenericID;
    FDelegateOnSuccessRevokeAllBansForUser OnSuccessRevokeAllBansForUser;
    FDelegateOnSuccessRevokeBans OnSuccessRevokeBans;
    FDelegateOnSuccessSavePushNotificationTemplate OnSuccessSavePushNotificationTemplate;
    FDelegateOnSuccessSendCustomAccountRecoveryEmail OnSuccessSendCustomAccountRecoveryEmail;
    FDelegateOnSuccessSendEmailFromTemplate OnSuccessSendEmailFromTemplate;
    FDelegateOnSuccessSendPushNotification OnSuccessSendPushNotification;
    FDelegateOnSuccessSendPushNotificationFromTemplate OnSuccessSendPushNotificationFromTemplate;
    FDelegateOnSuccessUnlinkPSNAccount OnSuccessUnlinkPSNAccount;
    FDelegateOnSuccessUnlinkServerCustomId OnSuccessUnlinkServerCustomId;
    FDelegateOnSuccessUnlinkXboxAccount OnSuccessUnlinkXboxAccount;
    FDelegateOnSuccessUpdateAvatarUrl OnSuccessUpdateAvatarUrl;
    FDelegateOnSuccessUpdateBans OnSuccessUpdateBans;
    FDelegateOnSuccessWriteCharacterEvent OnSuccessWriteCharacterEvent;
    FDelegateOnSuccessWritePlayerEvent OnSuccessWritePlayerEvent;
    FDelegateOnSuccessWriteTitleEvent OnSuccessWriteTitleEvent;
    FDelegateOnSuccessAuthenticateSessionTicket OnSuccessAuthenticateSessionTicket;
    FDelegateOnSuccessLoginWithServerCustomId OnSuccessLoginWithServerCustomId;
    FDelegateOnSuccessLoginWithSteamId OnSuccessLoginWithSteamId;
    FDelegateOnSuccessLoginWithXbox OnSuccessLoginWithXbox;
    FDelegateOnSuccessLoginWithXboxId OnSuccessLoginWithXboxId;
    FDelegateOnSuccessSetPlayerSecret OnSuccessSetPlayerSecret;
    FDelegateOnSuccessGetCharacterData OnSuccessGetCharacterData;
    FDelegateOnSuccessGetCharacterInternalData OnSuccessGetCharacterInternalData;
    FDelegateOnSuccessGetCharacterReadOnlyData OnSuccessGetCharacterReadOnlyData;
    FDelegateOnSuccessUpdateCharacterData OnSuccessUpdateCharacterData;
    FDelegateOnSuccessUpdateCharacterInternalData OnSuccessUpdateCharacterInternalData;
    FDelegateOnSuccessUpdateCharacterReadOnlyData OnSuccessUpdateCharacterReadOnlyData;
    FDelegateOnSuccessDeleteCharacterFromUser OnSuccessDeleteCharacterFromUser;
    FDelegateOnSuccessGetAllUsersCharacters OnSuccessGetAllUsersCharacters;
    FDelegateOnSuccessGetCharacterLeaderboard OnSuccessGetCharacterLeaderboard;
    FDelegateOnSuccessGetCharacterStatistics OnSuccessGetCharacterStatistics;
    FDelegateOnSuccessGetLeaderboardAroundCharacter OnSuccessGetLeaderboardAroundCharacter;
    FDelegateOnSuccessGetLeaderboardForUserCharacters OnSuccessGetLeaderboardForUserCharacters;
    FDelegateOnSuccessGrantCharacterToUser OnSuccessGrantCharacterToUser;
    FDelegateOnSuccessUpdateCharacterStatistics OnSuccessUpdateCharacterStatistics;
    FDelegateOnSuccessGetContentDownloadUrl OnSuccessGetContentDownloadUrl;
    FDelegateOnSuccessAddFriend OnSuccessAddFriend;
    FDelegateOnSuccessGetFriendsList OnSuccessGetFriendsList;
    FDelegateOnSuccessRemoveFriend OnSuccessRemoveFriend;
    FDelegateOnSuccessSetFriendTags OnSuccessSetFriendTags;
    FDelegateOnSuccessDeregisterGame OnSuccessDeregisterGame;
    FDelegateOnSuccessNotifyMatchmakerPlayerLeft OnSuccessNotifyMatchmakerPlayerLeft;
    FDelegateOnSuccessRedeemMatchmakerTicket OnSuccessRedeemMatchmakerTicket;
    FDelegateOnSuccessRefreshGameServerInstanceHeartbeat OnSuccessRefreshGameServerInstanceHeartbeat;
    FDelegateOnSuccessRegisterGame OnSuccessRegisterGame;
    FDelegateOnSuccessSetGameServerInstanceData OnSuccessSetGameServerInstanceData;
    FDelegateOnSuccessSetGameServerInstanceState OnSuccessSetGameServerInstanceState;
    FDelegateOnSuccessSetGameServerInstanceTags OnSuccessSetGameServerInstanceTags;
    FDelegateOnSuccessAwardSteamAchievement OnSuccessAwardSteamAchievement;
    FDelegateOnSuccessGetFriendLeaderboard OnSuccessGetFriendLeaderboard;
    FDelegateOnSuccessGetLeaderboard OnSuccessGetLeaderboard;
    FDelegateOnSuccessGetLeaderboardAroundUser OnSuccessGetLeaderboardAroundUser;
    FDelegateOnSuccessGetPlayerCombinedInfo OnSuccessGetPlayerCombinedInfo;
    FDelegateOnSuccessGetPlayerStatistics OnSuccessGetPlayerStatistics;
    FDelegateOnSuccessGetPlayerStatisticVersions OnSuccessGetPlayerStatisticVersions;
    FDelegateOnSuccessGetUserData OnSuccessGetUserData;
    FDelegateOnSuccessGetUserInternalData OnSuccessGetUserInternalData;
    FDelegateOnSuccessGetUserPublisherData OnSuccessGetUserPublisherData;
    FDelegateOnSuccessGetUserPublisherInternalData OnSuccessGetUserPublisherInternalData;
    FDelegateOnSuccessGetUserPublisherReadOnlyData OnSuccessGetUserPublisherReadOnlyData;
    FDelegateOnSuccessGetUserReadOnlyData OnSuccessGetUserReadOnlyData;
    FDelegateOnSuccessUpdatePlayerStatistics OnSuccessUpdatePlayerStatistics;
    FDelegateOnSuccessUpdateUserData OnSuccessUpdateUserData;
    FDelegateOnSuccessUpdateUserInternalData OnSuccessUpdateUserInternalData;
    FDelegateOnSuccessUpdateUserPublisherData OnSuccessUpdateUserPublisherData;
    FDelegateOnSuccessUpdateUserPublisherInternalData OnSuccessUpdateUserPublisherInternalData;
    FDelegateOnSuccessUpdateUserPublisherReadOnlyData OnSuccessUpdateUserPublisherReadOnlyData;
    FDelegateOnSuccessUpdateUserReadOnlyData OnSuccessUpdateUserReadOnlyData;
    FDelegateOnSuccessAddCharacterVirtualCurrency OnSuccessAddCharacterVirtualCurrency;
    FDelegateOnSuccessAddUserVirtualCurrency OnSuccessAddUserVirtualCurrency;
    FDelegateOnSuccessConsumeItem OnSuccessConsumeItem;
    FDelegateOnSuccessEvaluateRandomResultTable OnSuccessEvaluateRandomResultTable;
    FDelegateOnSuccessGetCharacterInventory OnSuccessGetCharacterInventory;
    FDelegateOnSuccessGetRandomResultTables OnSuccessGetRandomResultTables;
    FDelegateOnSuccessGetUserInventory OnSuccessGetUserInventory;
    FDelegateOnSuccessGrantItemsToCharacter OnSuccessGrantItemsToCharacter;
    FDelegateOnSuccessGrantItemsToUser OnSuccessGrantItemsToUser;
    FDelegateOnSuccessGrantItemsToUsers OnSuccessGrantItemsToUsers;
    FDelegateOnSuccessModifyItemUses OnSuccessModifyItemUses;
    FDelegateOnSuccessMoveItemToCharacterFromCharacter OnSuccessMoveItemToCharacterFromCharacter;
    FDelegateOnSuccessMoveItemToCharacterFromUser OnSuccessMoveItemToCharacterFromUser;
    FDelegateOnSuccessMoveItemToUserFromCharacter OnSuccessMoveItemToUserFromCharacter;
    FDelegateOnSuccessRedeemCoupon OnSuccessRedeemCoupon;
    FDelegateOnSuccessReportPlayer OnSuccessReportPlayer;
    FDelegateOnSuccessRevokeInventoryItem OnSuccessRevokeInventoryItem;
    FDelegateOnSuccessRevokeInventoryItems OnSuccessRevokeInventoryItems;
    FDelegateOnSuccessSubtractCharacterVirtualCurrency OnSuccessSubtractCharacterVirtualCurrency;
    FDelegateOnSuccessSubtractUserVirtualCurrency OnSuccessSubtractUserVirtualCurrency;
    FDelegateOnSuccessUnlockContainerInstance OnSuccessUnlockContainerInstance;
    FDelegateOnSuccessUnlockContainerItem OnSuccessUnlockContainerItem;
    FDelegateOnSuccessUpdateUserInventoryItemCustomData OnSuccessUpdateUserInventoryItemCustomData;
    FDelegateOnSuccessAddPlayerTag OnSuccessAddPlayerTag;
    FDelegateOnSuccessGetAllSegments OnSuccessGetAllSegments;
    FDelegateOnSuccessGetPlayerSegments OnSuccessGetPlayerSegments;
    FDelegateOnSuccessGetPlayersInSegment OnSuccessGetPlayersInSegment;
    FDelegateOnSuccessGetPlayerTags OnSuccessGetPlayerTags;
    FDelegateOnSuccessRemovePlayerTag OnSuccessRemovePlayerTag;
    FDelegateOnSuccessExecuteCloudScript OnSuccessExecuteCloudScript;
    FDelegateOnSuccessAddSharedGroupMembers OnSuccessAddSharedGroupMembers;
    FDelegateOnSuccessCreateSharedGroup OnSuccessCreateSharedGroup;
    FDelegateOnSuccessDeleteSharedGroup OnSuccessDeleteSharedGroup;
    FDelegateOnSuccessGetSharedGroupData OnSuccessGetSharedGroupData;
    FDelegateOnSuccessRemoveSharedGroupMembers OnSuccessRemoveSharedGroupMembers;
    FDelegateOnSuccessUpdateSharedGroupData OnSuccessUpdateSharedGroupData;
    FDelegateOnSuccessGetCatalogItems OnSuccessGetCatalogItems;
    FDelegateOnSuccessGetPublisherData OnSuccessGetPublisherData;
    FDelegateOnSuccessGetStoreItems OnSuccessGetStoreItems;
    FDelegateOnSuccessGetTime OnSuccessGetTime;
    FDelegateOnSuccessGetTitleData OnSuccessGetTitleData;
    FDelegateOnSuccessGetTitleInternalData OnSuccessGetTitleInternalData;
    FDelegateOnSuccessGetTitleNews OnSuccessGetTitleNews;
    FDelegateOnSuccessSetPublisherData OnSuccessSetPublisherData;
    FDelegateOnSuccessSetTitleData OnSuccessSetTitleData;
    FDelegateOnSuccessSetTitleInternalData OnSuccessSetTitleInternalData;

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
