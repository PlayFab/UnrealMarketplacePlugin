//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated header file for the UE4 PlayFab plugin.
// This header file contains the function definitions.
//
// API: Client
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Http.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "PlayFabBaseModel.h"
#include "PlayFabClientModels.h"
#include "PlayFabClientAPI.generated.h"

class UPlayFabAuthenticationContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPlayFabClientRequestCompleted, FPlayFabBaseModel, response, UObject*, customData, bool, successful);

UCLASS(Blueprintable, BlueprintType)
class PLAYFAB_API UPlayFabClientAPI : public UOnlineBlueprintCallProxyBase
{
    GENERATED_UCLASS_BODY()

public:
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnFailurePlayFabError, FPlayFabError, error, UObject*, customData);

    UPROPERTY(BlueprintAssignable)
        FOnPlayFabClientRequestCompleted OnPlayFabResponse;

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
    // Generated PlayFab Client API Functions
    //////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////
    // Account Management
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAddGenericID, FClientAddGenericIDResult, result, UObject*, customData);

    /**
     * Adds the specified generic service identifier to the player's PlayFab account. This is designed to allow for a PlayFab
     * ID lookup of any arbitrary service identifier a title wants to add. This identifier should never be used as
     * authentication credentials, as the intent is that it is easily accessible by other players.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* AddGenericID(FClientAddGenericIDRequest request,
            FDelegateOnSuccessAddGenericID onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAddGenericID(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAddOrUpdateContactEmail, FClientAddOrUpdateContactEmailResult, result, UObject*, customData);

    /** Adds or updates a contact email to the player's profile. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* AddOrUpdateContactEmail(FClientAddOrUpdateContactEmailRequest request,
            FDelegateOnSuccessAddOrUpdateContactEmail onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAddOrUpdateContactEmail(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAddUsernamePassword, FClientAddUsernamePasswordResult, result, UObject*, customData);

    /**
     * Adds playfab username/password auth to an existing account created via an anonymous auth method, e.g. automatic device
     * ID login.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* AddUsernamePassword(FClientAddUsernamePasswordRequest request,
            FDelegateOnSuccessAddUsernamePassword onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAddUsernamePassword(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetAccountInfo, FClientGetAccountInfoResult, result, UObject*, customData);

    /** Retrieves the user's PlayFab account details */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetAccountInfo(FClientGetAccountInfoRequest request,
            FDelegateOnSuccessGetAccountInfo onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetAccountInfo(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayerCombinedInfo, FClientGetPlayerCombinedInfoResult, result, UObject*, customData);

    /** Retrieves all of the user's different kinds of info. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetPlayerCombinedInfo(FClientGetPlayerCombinedInfoRequest request,
            FDelegateOnSuccessGetPlayerCombinedInfo onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayerCombinedInfo(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayerProfile, FClientGetPlayerProfileResult, result, UObject*, customData);

    /** Retrieves the player's profile */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetPlayerProfile(FClientGetPlayerProfileRequest request,
            FDelegateOnSuccessGetPlayerProfile onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayerProfile(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayFabIDsFromFacebookIDs, FClientGetPlayFabIDsFromFacebookIDsResult, result, UObject*, customData);

    /** Retrieves the unique PlayFab identifiers for the given set of Facebook identifiers. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetPlayFabIDsFromFacebookIDs(FClientGetPlayFabIDsFromFacebookIDsRequest request,
            FDelegateOnSuccessGetPlayFabIDsFromFacebookIDs onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayFabIDsFromFacebookIDs(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayFabIDsFromFacebookInstantGamesIds, FClientGetPlayFabIDsFromFacebookInstantGamesIdsResult, result, UObject*, customData);

    /** Retrieves the unique PlayFab identifiers for the given set of Facebook Instant Game identifiers. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetPlayFabIDsFromFacebookInstantGamesIds(FClientGetPlayFabIDsFromFacebookInstantGamesIdsRequest request,
            FDelegateOnSuccessGetPlayFabIDsFromFacebookInstantGamesIds onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayFabIDsFromFacebookInstantGamesIds(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayFabIDsFromGameCenterIDs, FClientGetPlayFabIDsFromGameCenterIDsResult, result, UObject*, customData);

    /**
     * Retrieves the unique PlayFab identifiers for the given set of Game Center identifiers (referenced in the Game Center
     * Programming Guide as the Player Identifier).
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetPlayFabIDsFromGameCenterIDs(FClientGetPlayFabIDsFromGameCenterIDsRequest request,
            FDelegateOnSuccessGetPlayFabIDsFromGameCenterIDs onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayFabIDsFromGameCenterIDs(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayFabIDsFromGenericIDs, FClientGetPlayFabIDsFromGenericIDsResult, result, UObject*, customData);

    /**
     * Retrieves the unique PlayFab identifiers for the given set of generic service identifiers. A generic identifier is the
     * service name plus the service-specific ID for the player, as specified by the title when the generic identifier was
     * added to the player account.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetPlayFabIDsFromGenericIDs(FClientGetPlayFabIDsFromGenericIDsRequest request,
            FDelegateOnSuccessGetPlayFabIDsFromGenericIDs onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayFabIDsFromGenericIDs(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayFabIDsFromGoogleIDs, FClientGetPlayFabIDsFromGoogleIDsResult, result, UObject*, customData);

    /**
     * Retrieves the unique PlayFab identifiers for the given set of Google identifiers. The Google identifiers are the IDs for
     * the user accounts, available as "id" in the Google+ People API calls.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetPlayFabIDsFromGoogleIDs(FClientGetPlayFabIDsFromGoogleIDsRequest request,
            FDelegateOnSuccessGetPlayFabIDsFromGoogleIDs onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayFabIDsFromGoogleIDs(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayFabIDsFromKongregateIDs, FClientGetPlayFabIDsFromKongregateIDsResult, result, UObject*, customData);

    /**
     * Retrieves the unique PlayFab identifiers for the given set of Kongregate identifiers. The Kongregate identifiers are the
     * IDs for the user accounts, available as "user_id" from the Kongregate API methods(ex:
     * http://developers.kongregate.com/docs/client/getUserId).
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetPlayFabIDsFromKongregateIDs(FClientGetPlayFabIDsFromKongregateIDsRequest request,
            FDelegateOnSuccessGetPlayFabIDsFromKongregateIDs onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayFabIDsFromKongregateIDs(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayFabIDsFromNintendoSwitchDeviceIds, FClientGetPlayFabIDsFromNintendoSwitchDeviceIdsResult, result, UObject*, customData);

    /** Retrieves the unique PlayFab identifiers for the given set of Nintendo Switch identifiers. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetPlayFabIDsFromNintendoSwitchDeviceIds(FClientGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest request,
            FDelegateOnSuccessGetPlayFabIDsFromNintendoSwitchDeviceIds onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayFabIDsFromNintendoSwitchDeviceIds(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayFabIDsFromPSNAccountIDs, FClientGetPlayFabIDsFromPSNAccountIDsResult, result, UObject*, customData);

    /** Retrieves the unique PlayFab identifiers for the given set of PlayStation Network identifiers. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetPlayFabIDsFromPSNAccountIDs(FClientGetPlayFabIDsFromPSNAccountIDsRequest request,
            FDelegateOnSuccessGetPlayFabIDsFromPSNAccountIDs onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayFabIDsFromPSNAccountIDs(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayFabIDsFromSteamIDs, FClientGetPlayFabIDsFromSteamIDsResult, result, UObject*, customData);

    /**
     * Retrieves the unique PlayFab identifiers for the given set of Steam identifiers. The Steam identifiers are the profile
     * IDs for the user accounts, available as SteamId in the Steamworks Community API calls.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetPlayFabIDsFromSteamIDs(FClientGetPlayFabIDsFromSteamIDsRequest request,
            FDelegateOnSuccessGetPlayFabIDsFromSteamIDs onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayFabIDsFromSteamIDs(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayFabIDsFromTwitchIDs, FClientGetPlayFabIDsFromTwitchIDsResult, result, UObject*, customData);

    /**
     * Retrieves the unique PlayFab identifiers for the given set of Twitch identifiers. The Twitch identifiers are the IDs for
     * the user accounts, available as "_id" from the Twitch API methods (ex:
     * https://github.com/justintv/Twitch-API/blob/master/v3_resources/users.md#get-usersuser).
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetPlayFabIDsFromTwitchIDs(FClientGetPlayFabIDsFromTwitchIDsRequest request,
            FDelegateOnSuccessGetPlayFabIDsFromTwitchIDs onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayFabIDsFromTwitchIDs(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayFabIDsFromXboxLiveIDs, FClientGetPlayFabIDsFromXboxLiveIDsResult, result, UObject*, customData);

    /** Retrieves the unique PlayFab identifiers for the given set of XboxLive identifiers. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetPlayFabIDsFromXboxLiveIDs(FClientGetPlayFabIDsFromXboxLiveIDsRequest request,
            FDelegateOnSuccessGetPlayFabIDsFromXboxLiveIDs onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayFabIDsFromXboxLiveIDs(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLinkAndroidDeviceID, FClientLinkAndroidDeviceIDResult, result, UObject*, customData);

    /** Links the Android device identifier to the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LinkAndroidDeviceID(FClientLinkAndroidDeviceIDRequest request,
            FDelegateOnSuccessLinkAndroidDeviceID onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLinkAndroidDeviceID(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLinkApple, FClientEmptyResult, result, UObject*, customData);

    /** Links the Apple account associated with the token to the user's PlayFab account. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LinkApple(FClientLinkAppleRequest request,
            FDelegateOnSuccessLinkApple onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLinkApple(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLinkCustomID, FClientLinkCustomIDResult, result, UObject*, customData);

    /** Links the custom identifier, generated by the title, to the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LinkCustomID(FClientLinkCustomIDRequest request,
            FDelegateOnSuccessLinkCustomID onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLinkCustomID(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLinkFacebookAccount, FClientLinkFacebookAccountResult, result, UObject*, customData);

    /** Links the Facebook account associated with the provided Facebook access token to the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LinkFacebookAccount(FClientLinkFacebookAccountRequest request,
            FDelegateOnSuccessLinkFacebookAccount onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLinkFacebookAccount(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLinkFacebookInstantGamesId, FClientLinkFacebookInstantGamesIdResult, result, UObject*, customData);

    /** Links the Facebook Instant Games Id to the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LinkFacebookInstantGamesId(FClientLinkFacebookInstantGamesIdRequest request,
            FDelegateOnSuccessLinkFacebookInstantGamesId onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLinkFacebookInstantGamesId(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLinkGameCenterAccount, FClientLinkGameCenterAccountResult, result, UObject*, customData);

    /**
     * Links the Game Center account associated with the provided Game Center ID to the user's PlayFab account. Logging in with
     * a Game Center ID is insecure if you do not include the optional PublicKeyUrl, Salt, Signature, and Timestamp parameters
     * in this request. It is recommended you require these parameters on all Game Center calls by going to the Apple Add-ons
     * page in the PlayFab Game Manager and enabling the 'Require secure authentication only for this app' option.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LinkGameCenterAccount(FClientLinkGameCenterAccountRequest request,
            FDelegateOnSuccessLinkGameCenterAccount onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLinkGameCenterAccount(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLinkGoogleAccount, FClientLinkGoogleAccountResult, result, UObject*, customData);

    /** Links the currently signed-in user account to their Google account, using their Google account credentials */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LinkGoogleAccount(FClientLinkGoogleAccountRequest request,
            FDelegateOnSuccessLinkGoogleAccount onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLinkGoogleAccount(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLinkIOSDeviceID, FClientLinkIOSDeviceIDResult, result, UObject*, customData);

    /** Links the vendor-specific iOS device identifier to the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LinkIOSDeviceID(FClientLinkIOSDeviceIDRequest request,
            FDelegateOnSuccessLinkIOSDeviceID onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLinkIOSDeviceID(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLinkKongregate, FClientLinkKongregateAccountResult, result, UObject*, customData);

    /** Links the Kongregate identifier to the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LinkKongregate(FClientLinkKongregateAccountRequest request,
            FDelegateOnSuccessLinkKongregate onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLinkKongregate(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLinkNintendoServiceAccount, FClientEmptyResult, result, UObject*, customData);

    /** Links the Nintendo account associated with the token to the user's PlayFab account. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LinkNintendoServiceAccount(FClientLinkNintendoServiceAccountRequest request,
            FDelegateOnSuccessLinkNintendoServiceAccount onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLinkNintendoServiceAccount(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLinkNintendoSwitchDeviceId, FClientLinkNintendoSwitchDeviceIdResult, result, UObject*, customData);

    /** Links the NintendoSwitchDeviceId to the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LinkNintendoSwitchDeviceId(FClientLinkNintendoSwitchDeviceIdRequest request,
            FDelegateOnSuccessLinkNintendoSwitchDeviceId onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLinkNintendoSwitchDeviceId(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLinkOpenIdConnect, FClientEmptyResult, result, UObject*, customData);

    /**
     * Links an OpenID Connect account to a user's PlayFab account, based on an existing relationship between a title and an
     * Open ID Connect provider and the OpenId Connect JWT from that provider.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LinkOpenIdConnect(FClientLinkOpenIdConnectRequest request,
            FDelegateOnSuccessLinkOpenIdConnect onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLinkOpenIdConnect(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLinkPSNAccount, FClientLinkPSNAccountResult, result, UObject*, customData);

    /** Links the PlayStation Network account associated with the provided access code to the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LinkPSNAccount(FClientLinkPSNAccountRequest request,
            FDelegateOnSuccessLinkPSNAccount onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLinkPSNAccount(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLinkSteamAccount, FClientLinkSteamAccountResult, result, UObject*, customData);

    /** Links the Steam account associated with the provided Steam authentication ticket to the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LinkSteamAccount(FClientLinkSteamAccountRequest request,
            FDelegateOnSuccessLinkSteamAccount onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLinkSteamAccount(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLinkTwitch, FClientLinkTwitchAccountResult, result, UObject*, customData);

    /** Links the Twitch account associated with the token to the user's PlayFab account. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LinkTwitch(FClientLinkTwitchAccountRequest request,
            FDelegateOnSuccessLinkTwitch onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLinkTwitch(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLinkXboxAccount, FClientLinkXboxAccountResult, result, UObject*, customData);

    /** Links the Xbox Live account associated with the provided access code to the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LinkXboxAccount(FClientLinkXboxAccountRequest request,
            FDelegateOnSuccessLinkXboxAccount onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLinkXboxAccount(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRemoveContactEmail, FClientRemoveContactEmailResult, result, UObject*, customData);

    /** Removes a contact email from the player's profile. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* RemoveContactEmail(FClientRemoveContactEmailRequest request,
            FDelegateOnSuccessRemoveContactEmail onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRemoveContactEmail(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRemoveGenericID, FClientRemoveGenericIDResult, result, UObject*, customData);

    /** Removes the specified generic service identifier from the player's PlayFab account. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* RemoveGenericID(FClientRemoveGenericIDRequest request,
            FDelegateOnSuccessRemoveGenericID onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRemoveGenericID(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessReportPlayer, FClientReportPlayerClientResult, result, UObject*, customData);

    /**
     * Submit a report for another player (due to bad bahavior, etc.), so that customer service representatives for the title
     * can take action concerning potentially toxic players.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* ReportPlayer(FClientReportPlayerClientRequest request,
            FDelegateOnSuccessReportPlayer onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperReportPlayer(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSendAccountRecoveryEmail, FClientSendAccountRecoveryEmailResult, result, UObject*, customData);

    /**
     * Forces an email to be sent to the registered email address for the user's account, with a link allowing the user to
     * change the password.If an account recovery email template ID is provided, an email using the custom email template will
     * be used.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* SendAccountRecoveryEmail(FClientSendAccountRecoveryEmailRequest request,
            FDelegateOnSuccessSendAccountRecoveryEmail onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSendAccountRecoveryEmail(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlinkAndroidDeviceID, FClientUnlinkAndroidDeviceIDResult, result, UObject*, customData);

    /** Unlinks the related Android device identifier from the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UnlinkAndroidDeviceID(FClientUnlinkAndroidDeviceIDRequest request,
            FDelegateOnSuccessUnlinkAndroidDeviceID onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlinkAndroidDeviceID(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlinkApple, FClientEmptyResponse, result, UObject*, customData);

    /** Unlinks the related Apple account from the user's PlayFab account. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UnlinkApple(FClientUnlinkAppleRequest request,
            FDelegateOnSuccessUnlinkApple onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlinkApple(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlinkCustomID, FClientUnlinkCustomIDResult, result, UObject*, customData);

    /** Unlinks the related custom identifier from the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UnlinkCustomID(FClientUnlinkCustomIDRequest request,
            FDelegateOnSuccessUnlinkCustomID onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlinkCustomID(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlinkFacebookAccount, FClientUnlinkFacebookAccountResult, result, UObject*, customData);

    /** Unlinks the related Facebook account from the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UnlinkFacebookAccount(FClientUnlinkFacebookAccountRequest request,
            FDelegateOnSuccessUnlinkFacebookAccount onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlinkFacebookAccount(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlinkFacebookInstantGamesId, FClientUnlinkFacebookInstantGamesIdResult, result, UObject*, customData);

    /** Unlinks the related Facebook Instant Game Ids from the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UnlinkFacebookInstantGamesId(FClientUnlinkFacebookInstantGamesIdRequest request,
            FDelegateOnSuccessUnlinkFacebookInstantGamesId onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlinkFacebookInstantGamesId(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlinkGameCenterAccount, FClientUnlinkGameCenterAccountResult, result, UObject*, customData);

    /** Unlinks the related Game Center account from the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UnlinkGameCenterAccount(FClientUnlinkGameCenterAccountRequest request,
            FDelegateOnSuccessUnlinkGameCenterAccount onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlinkGameCenterAccount(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlinkGoogleAccount, FClientUnlinkGoogleAccountResult, result, UObject*, customData);

    /**
     * Unlinks the related Google account from the user's PlayFab account
     * (https://developers.google.com/android/reference/com/google/android/gms/auth/GoogleAuthUtil#public-methods).
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UnlinkGoogleAccount(FClientUnlinkGoogleAccountRequest request,
            FDelegateOnSuccessUnlinkGoogleAccount onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlinkGoogleAccount(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlinkIOSDeviceID, FClientUnlinkIOSDeviceIDResult, result, UObject*, customData);

    /** Unlinks the related iOS device identifier from the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UnlinkIOSDeviceID(FClientUnlinkIOSDeviceIDRequest request,
            FDelegateOnSuccessUnlinkIOSDeviceID onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlinkIOSDeviceID(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlinkKongregate, FClientUnlinkKongregateAccountResult, result, UObject*, customData);

    /** Unlinks the related Kongregate identifier from the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UnlinkKongregate(FClientUnlinkKongregateAccountRequest request,
            FDelegateOnSuccessUnlinkKongregate onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlinkKongregate(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlinkNintendoServiceAccount, FClientEmptyResponse, result, UObject*, customData);

    /** Unlinks the related Nintendo account from the user's PlayFab account. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UnlinkNintendoServiceAccount(FClientUnlinkNintendoServiceAccountRequest request,
            FDelegateOnSuccessUnlinkNintendoServiceAccount onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlinkNintendoServiceAccount(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlinkNintendoSwitchDeviceId, FClientUnlinkNintendoSwitchDeviceIdResult, result, UObject*, customData);

    /** Unlinks the related NintendoSwitchDeviceId from the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UnlinkNintendoSwitchDeviceId(FClientUnlinkNintendoSwitchDeviceIdRequest request,
            FDelegateOnSuccessUnlinkNintendoSwitchDeviceId onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlinkNintendoSwitchDeviceId(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlinkOpenIdConnect, FClientEmptyResponse, result, UObject*, customData);

    /**
     * Unlinks an OpenID Connect account from a user's PlayFab account, based on the connection ID of an existing relationship
     * between a title and an Open ID Connect provider.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UnlinkOpenIdConnect(FClientUnlinkOpenIdConnectRequest request,
            FDelegateOnSuccessUnlinkOpenIdConnect onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlinkOpenIdConnect(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlinkPSNAccount, FClientUnlinkPSNAccountResult, result, UObject*, customData);

    /** Unlinks the related PSN account from the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UnlinkPSNAccount(FClientUnlinkPSNAccountRequest request,
            FDelegateOnSuccessUnlinkPSNAccount onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlinkPSNAccount(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlinkSteamAccount, FClientUnlinkSteamAccountResult, result, UObject*, customData);

    /** Unlinks the related Steam account from the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UnlinkSteamAccount(FClientUnlinkSteamAccountRequest request,
            FDelegateOnSuccessUnlinkSteamAccount onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlinkSteamAccount(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlinkTwitch, FClientUnlinkTwitchAccountResult, result, UObject*, customData);

    /** Unlinks the related Twitch account from the user's PlayFab account. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UnlinkTwitch(FClientUnlinkTwitchAccountRequest request,
            FDelegateOnSuccessUnlinkTwitch onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlinkTwitch(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlinkXboxAccount, FClientUnlinkXboxAccountResult, result, UObject*, customData);

    /** Unlinks the related Xbox Live account from the user's PlayFab account */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UnlinkXboxAccount(FClientUnlinkXboxAccountRequest request,
            FDelegateOnSuccessUnlinkXboxAccount onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlinkXboxAccount(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateAvatarUrl, FClientEmptyResponse, result, UObject*, customData);

    /** Update the avatar URL of the player */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UpdateAvatarUrl(FClientUpdateAvatarUrlRequest request,
            FDelegateOnSuccessUpdateAvatarUrl onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateAvatarUrl(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateUserTitleDisplayName, FClientUpdateUserTitleDisplayNameResult, result, UObject*, customData);

    /** Updates the title specific display name for the user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UpdateUserTitleDisplayName(FClientUpdateUserTitleDisplayNameRequest request,
            FDelegateOnSuccessUpdateUserTitleDisplayName onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateUserTitleDisplayName(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Advertising
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAttributeInstall, FClientAttributeInstallResult, result, UObject*, customData);

    /** Attributes an install for advertisment. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Advertising ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* AttributeInstall(FClientAttributeInstallRequest request,
            FDelegateOnSuccessAttributeInstall onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Advertising ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAttributeInstall(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetAdPlacements, FClientGetAdPlacementsResult, result, UObject*, customData);

    /** Returns a list of ad placements and a reward for each */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Advertising ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetAdPlacements(FClientGetAdPlacementsRequest request,
            FDelegateOnSuccessGetAdPlacements onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Advertising ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetAdPlacements(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessReportAdActivity, FClientReportAdActivityResult, result, UObject*, customData);

    /** Report player's ad activity */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Advertising ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* ReportAdActivity(FClientReportAdActivityRequest request,
            FDelegateOnSuccessReportAdActivity onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Advertising ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperReportAdActivity(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRewardAdActivity, FClientRewardAdActivityResult, result, UObject*, customData);

    /** Reward player's ad activity */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Advertising ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* RewardAdActivity(FClientRewardAdActivityRequest request,
            FDelegateOnSuccessRewardAdActivity onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Advertising ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRewardAdActivity(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Analytics
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessReportDeviceInfo, FClientEmptyResponse, result, UObject*, customData);

    /**
     * Write a PlayStream event to describe the provided player device information. This API method is not designed to be
     * called directly by developers. Each PlayFab client SDK will eventually report this information automatically.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* ReportDeviceInfo(FClientDeviceInfoRequest request,
            FDelegateOnSuccessReportDeviceInfo onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperReportDeviceInfo(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessWriteCharacterEvent, FClientWriteEventResponse, result, UObject*, customData);

    /** Writes a character-based event into PlayStream. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* WriteCharacterEvent(FClientWriteClientCharacterEventRequest request,
            FDelegateOnSuccessWriteCharacterEvent onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperWriteCharacterEvent(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessWritePlayerEvent, FClientWriteEventResponse, result, UObject*, customData);

    /** Writes a player-based event into PlayStream. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* WritePlayerEvent(FClientWriteClientPlayerEventRequest request,
            FDelegateOnSuccessWritePlayerEvent onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperWritePlayerEvent(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessWriteTitleEvent, FClientWriteEventResponse, result, UObject*, customData);

    /** Writes a title-based event into PlayStream. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* WriteTitleEvent(FClientWriteTitleEventRequest request,
            FDelegateOnSuccessWriteTitleEvent onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperWriteTitleEvent(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Authentication
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPhotonAuthenticationToken, FClientGetPhotonAuthenticationTokenResult, result, UObject*, customData);

    /**
     * Gets a Photon custom authentication token that can be used to securely join the player into a Photon room. See
     * https://docs.microsoft.com/gaming/playfab/features/multiplayer/photon/quickstart for more details.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetPhotonAuthenticationToken(FClientGetPhotonAuthenticationTokenRequest request,
            FDelegateOnSuccessGetPhotonAuthenticationToken onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPhotonAuthenticationToken(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetTitlePublicKey, FClientGetTitlePublicKeyResult, result, UObject*, customData);

    /** Returns the title's base 64 encoded RSA CSP blob. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetTitlePublicKey(FClientGetTitlePublicKeyRequest request,
            FDelegateOnSuccessGetTitlePublicKey onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetTitlePublicKey(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLoginWithAndroidDeviceID, FClientLoginResult, result, UObject*, customData);

    /**
     * Signs the user in using the Android device identifier, returning a session identifier that can subsequently be used for
     * API calls which require an authenticated user
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LoginWithAndroidDeviceID(FClientLoginWithAndroidDeviceIDRequest request,
            FDelegateOnSuccessLoginWithAndroidDeviceID onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLoginWithAndroidDeviceID(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLoginWithApple, FClientLoginResult, result, UObject*, customData);

    /** Signs in the user with a Sign in with Apple identity token. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LoginWithApple(FClientLoginWithAppleRequest request,
            FDelegateOnSuccessLoginWithApple onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLoginWithApple(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLoginWithCustomID, FClientLoginResult, result, UObject*, customData);

    /**
     * Signs the user in using a custom unique identifier generated by the title, returning a session identifier that can
     * subsequently be used for API calls which require an authenticated user
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LoginWithCustomID(FClientLoginWithCustomIDRequest request,
            FDelegateOnSuccessLoginWithCustomID onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLoginWithCustomID(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLoginWithEmailAddress, FClientLoginResult, result, UObject*, customData);

    /**
     * Signs the user into the PlayFab account, returning a session identifier that can subsequently be used for API calls
     * which require an authenticated user. Unlike most other login API calls, LoginWithEmailAddress does not permit the
     * creation of new accounts via the CreateAccountFlag. Email addresses may be used to create accounts via
     * RegisterPlayFabUser.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LoginWithEmailAddress(FClientLoginWithEmailAddressRequest request,
            FDelegateOnSuccessLoginWithEmailAddress onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLoginWithEmailAddress(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLoginWithFacebook, FClientLoginResult, result, UObject*, customData);

    /**
     * Signs the user in using a Facebook access token, returning a session identifier that can subsequently be used for API
     * calls which require an authenticated user
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LoginWithFacebook(FClientLoginWithFacebookRequest request,
            FDelegateOnSuccessLoginWithFacebook onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLoginWithFacebook(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLoginWithFacebookInstantGamesId, FClientLoginResult, result, UObject*, customData);

    /**
     * Signs the user in using a Facebook Instant Games ID, returning a session identifier that can subsequently be used for
     * API calls which require an authenticated user. Requires Facebook Instant Games to be configured.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LoginWithFacebookInstantGamesId(FClientLoginWithFacebookInstantGamesIdRequest request,
            FDelegateOnSuccessLoginWithFacebookInstantGamesId onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLoginWithFacebookInstantGamesId(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLoginWithGameCenter, FClientLoginResult, result, UObject*, customData);

    /**
     * Signs the user in using an iOS Game Center player identifier, returning a session identifier that can subsequently be
     * used for API calls which require an authenticated user. Logging in with a Game Center ID is insecure if you do not
     * include the optional PublicKeyUrl, Salt, Signature, and Timestamp parameters in this request. It is recommended you
     * require these parameters on all Game Center calls by going to the Apple Add-ons page in the PlayFab Game Manager and
     * enabling the 'Require secure authentication only for this app' option.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LoginWithGameCenter(FClientLoginWithGameCenterRequest request,
            FDelegateOnSuccessLoginWithGameCenter onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLoginWithGameCenter(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLoginWithGoogleAccount, FClientLoginResult, result, UObject*, customData);

    /** Signs the user in using their Google account credentials */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LoginWithGoogleAccount(FClientLoginWithGoogleAccountRequest request,
            FDelegateOnSuccessLoginWithGoogleAccount onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLoginWithGoogleAccount(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLoginWithIOSDeviceID, FClientLoginResult, result, UObject*, customData);

    /**
     * Signs the user in using the vendor-specific iOS device identifier, returning a session identifier that can subsequently
     * be used for API calls which require an authenticated user
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LoginWithIOSDeviceID(FClientLoginWithIOSDeviceIDRequest request,
            FDelegateOnSuccessLoginWithIOSDeviceID onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLoginWithIOSDeviceID(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLoginWithKongregate, FClientLoginResult, result, UObject*, customData);

    /** Signs the user in using a Kongregate player account. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LoginWithKongregate(FClientLoginWithKongregateRequest request,
            FDelegateOnSuccessLoginWithKongregate onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLoginWithKongregate(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLoginWithNintendoServiceAccount, FClientLoginResult, result, UObject*, customData);

    /** Signs in the user with a Nintendo service account token. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LoginWithNintendoServiceAccount(FClientLoginWithNintendoServiceAccountRequest request,
            FDelegateOnSuccessLoginWithNintendoServiceAccount onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLoginWithNintendoServiceAccount(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLoginWithNintendoSwitchDeviceId, FClientLoginResult, result, UObject*, customData);

    /**
     * Signs the user in using a Nintendo Switch Device ID, returning a session identifier that can subsequently be used for
     * API calls which require an authenticated user
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LoginWithNintendoSwitchDeviceId(FClientLoginWithNintendoSwitchDeviceIdRequest request,
            FDelegateOnSuccessLoginWithNintendoSwitchDeviceId onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLoginWithNintendoSwitchDeviceId(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLoginWithOpenIdConnect, FClientLoginResult, result, UObject*, customData);

    /**
     * Logs in a user with an Open ID Connect JWT created by an existing relationship between a title and an Open ID Connect
     * provider.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LoginWithOpenIdConnect(FClientLoginWithOpenIdConnectRequest request,
            FDelegateOnSuccessLoginWithOpenIdConnect onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLoginWithOpenIdConnect(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLoginWithPlayFab, FClientLoginResult, result, UObject*, customData);

    /**
     * Signs the user into the PlayFab account, returning a session identifier that can subsequently be used for API calls
     * which require an authenticated user. Unlike most other login API calls, LoginWithPlayFab does not permit the creation of
     * new accounts via the CreateAccountFlag. Username/Password credentials may be used to create accounts via
     * RegisterPlayFabUser, or added to existing accounts using AddUsernamePassword.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LoginWithPlayFab(FClientLoginWithPlayFabRequest request,
            FDelegateOnSuccessLoginWithPlayFab onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLoginWithPlayFab(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLoginWithPSN, FClientLoginResult, result, UObject*, customData);

    /**
     * Signs the user in using a PlayStation Network authentication code, returning a session identifier that can subsequently
     * be used for API calls which require an authenticated user
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LoginWithPSN(FClientLoginWithPSNRequest request,
            FDelegateOnSuccessLoginWithPSN onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLoginWithPSN(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLoginWithSteam, FClientLoginResult, result, UObject*, customData);

    /**
     * Signs the user in using a Steam authentication ticket, returning a session identifier that can subsequently be used for
     * API calls which require an authenticated user
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LoginWithSteam(FClientLoginWithSteamRequest request,
            FDelegateOnSuccessLoginWithSteam onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLoginWithSteam(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLoginWithTwitch, FClientLoginResult, result, UObject*, customData);

    /** Signs the user in using a Twitch access token. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LoginWithTwitch(FClientLoginWithTwitchRequest request,
            FDelegateOnSuccessLoginWithTwitch onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLoginWithTwitch(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessLoginWithXbox, FClientLoginResult, result, UObject*, customData);

    /**
     * Signs the user in using a Xbox Live Token, returning a session identifier that can subsequently be used for API calls
     * which require an authenticated user
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* LoginWithXbox(FClientLoginWithXboxRequest request,
            FDelegateOnSuccessLoginWithXbox onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperLoginWithXbox(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRegisterPlayFabUser, FClientRegisterPlayFabUserResult, result, UObject*, customData);

    /**
     * Registers a new Playfab user account, returning a session identifier that can subsequently be used for API calls which
     * require an authenticated user. You must supply either a username or an email address.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* RegisterPlayFabUser(FClientRegisterPlayFabUserRequest request,
            FDelegateOnSuccessRegisterPlayFabUser onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRegisterPlayFabUser(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetPlayerSecret, FClientSetPlayerSecretResult, result, UObject*, customData);

    /**
     * Sets the player's secret if it is not already set. Player secrets are used to sign API requests. To reset a player's
     * secret use the Admin or Server API method SetPlayerSecret.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* SetPlayerSecret(FClientSetPlayerSecretRequest request,
            FDelegateOnSuccessSetPlayerSecret onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetPlayerSecret(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Character Data
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetCharacterData, FClientGetCharacterDataResult, result, UObject*, customData);

    /** Retrieves the title-specific custom data for the character which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetCharacterData(FClientGetCharacterDataRequest request,
            FDelegateOnSuccessGetCharacterData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetCharacterData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetCharacterReadOnlyData, FClientGetCharacterDataResult, result, UObject*, customData);

    /** Retrieves the title-specific custom data for the character which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetCharacterReadOnlyData(FClientGetCharacterDataRequest request,
            FDelegateOnSuccessGetCharacterReadOnlyData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetCharacterReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateCharacterData, FClientUpdateCharacterDataResult, result, UObject*, customData);

    /** Creates and updates the title-specific custom data for the user's character which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UpdateCharacterData(FClientUpdateCharacterDataRequest request,
            FDelegateOnSuccessUpdateCharacterData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Character Data ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateCharacterData(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Characters
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetAllUsersCharacters, FClientListUsersCharactersResult, result, UObject*, customData);

    /**
     * Lists all of the characters that belong to a specific user. CharacterIds are not globally unique; characterId must be
     * evaluated with the parent PlayFabId to guarantee uniqueness.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetAllUsersCharacters(FClientListUsersCharactersRequest request,
            FDelegateOnSuccessGetAllUsersCharacters onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetAllUsersCharacters(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetCharacterLeaderboard, FClientGetCharacterLeaderboardResult, result, UObject*, customData);

    /** Retrieves a list of ranked characters for the given statistic, starting from the indicated point in the leaderboard */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetCharacterLeaderboard(FClientGetCharacterLeaderboardRequest request,
            FDelegateOnSuccessGetCharacterLeaderboard onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetCharacterLeaderboard(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetCharacterStatistics, FClientGetCharacterStatisticsResult, result, UObject*, customData);

    /** Retrieves the details of all title-specific statistics for the user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetCharacterStatistics(FClientGetCharacterStatisticsRequest request,
            FDelegateOnSuccessGetCharacterStatistics onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetCharacterStatistics(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetLeaderboardAroundCharacter, FClientGetLeaderboardAroundCharacterResult, result, UObject*, customData);

    /** Retrieves a list of ranked characters for the given statistic, centered on the requested Character ID */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetLeaderboardAroundCharacter(FClientGetLeaderboardAroundCharacterRequest request,
            FDelegateOnSuccessGetLeaderboardAroundCharacter onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetLeaderboardAroundCharacter(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetLeaderboardForUserCharacters, FClientGetLeaderboardForUsersCharactersResult, result, UObject*, customData);

    /** Retrieves a list of all of the user's characters for the given statistic. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetLeaderboardForUserCharacters(FClientGetLeaderboardForUsersCharactersRequest request,
            FDelegateOnSuccessGetLeaderboardForUserCharacters onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetLeaderboardForUserCharacters(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGrantCharacterToUser, FClientGrantCharacterToUserResult, result, UObject*, customData);

    /**
     * Grants the specified character type to the user. CharacterIds are not globally unique; characterId must be evaluated
     * with the parent PlayFabId to guarantee uniqueness.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GrantCharacterToUser(FClientGrantCharacterToUserRequest request,
            FDelegateOnSuccessGrantCharacterToUser onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGrantCharacterToUser(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateCharacterStatistics, FClientUpdateCharacterStatisticsResult, result, UObject*, customData);

    /**
     * Updates the values of the specified title-specific statistics for the specific character. By default, clients are not
     * permitted to update statistics. Developers may override this setting in the Game Manager > Settings > API Features.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UpdateCharacterStatistics(FClientUpdateCharacterStatisticsRequest request,
            FDelegateOnSuccessUpdateCharacterStatistics onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateCharacterStatistics(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Content
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetContentDownloadUrl, FClientGetContentDownloadUrlResult, result, UObject*, customData);

    /**
     * This API retrieves a pre-signed URL for accessing a content file for the title. A subsequent HTTP GET to the returned
     * URL will attempt to download the content. A HEAD query to the returned URL will attempt to retrieve the metadata of the
     * content. Note that a successful result does not guarantee the existence of this content - if it has not been uploaded,
     * the query to retrieve the data will fail. See this post for more information:
     * https://community.playfab.com/hc/community/posts/205469488-How-to-upload-files-to-PlayFab-s-Content-Service. Also,
     * please be aware that the Content service is specifically PlayFab's CDN offering, for which standard CDN rates apply.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Content ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetContentDownloadUrl(FClientGetContentDownloadUrlRequest request,
            FDelegateOnSuccessGetContentDownloadUrl onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Content ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetContentDownloadUrl(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Friend List Management
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAddFriend, FClientAddFriendResult, result, UObject*, customData);

    /**
     * Adds the PlayFab user, based upon a match against a supplied unique identifier, to the friend list of the local user. At
     * least one of FriendPlayFabId,FriendUsername,FriendEmail, or FriendTitleDisplayName should be initialized.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Friend List Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* AddFriend(FClientAddFriendRequest request,
            FDelegateOnSuccessAddFriend onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Friend List Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAddFriend(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetFriendsList, FClientGetFriendsListResult, result, UObject*, customData);

    /**
     * Retrieves the current friend list for the local user, constrained to users who have PlayFab accounts. Friends from
     * linked accounts (Facebook, Steam) are also included. You may optionally exclude some linked services' friends.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Friend List Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetFriendsList(FClientGetFriendsListRequest request,
            FDelegateOnSuccessGetFriendsList onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Friend List Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetFriendsList(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRemoveFriend, FClientRemoveFriendResult, result, UObject*, customData);

    /** Removes a specified user from the friend list of the local user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Friend List Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* RemoveFriend(FClientRemoveFriendRequest request,
            FDelegateOnSuccessRemoveFriend onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Friend List Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRemoveFriend(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetFriendTags, FClientSetFriendTagsResult, result, UObject*, customData);

    /** Updates the tag list for a specified user in the friend list of the local user */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Friend List Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* SetFriendTags(FClientSetFriendTagsRequest request,
            FDelegateOnSuccessSetFriendTags onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Friend List Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetFriendTags(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Matchmaking
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetCurrentGames, FClientCurrentGamesResult, result, UObject*, customData);

    /** Get details about all current running game servers matching the given parameters. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetCurrentGames(FClientCurrentGamesRequest request,
            FDelegateOnSuccessGetCurrentGames onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetCurrentGames(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetGameServerRegions, FClientGameServerRegionsResult, result, UObject*, customData);

    /** Get details about the regions hosting game servers matching the given parameters. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetGameServerRegions(FClientGameServerRegionsRequest request,
            FDelegateOnSuccessGetGameServerRegions onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetGameServerRegions(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessMatchmake, FClientMatchmakeResult, result, UObject*, customData);

    /**
     * Attempts to locate a game session matching the given parameters. If the goal is to match the player into a specific
     * active session, only the LobbyId is required. Otherwise, the BuildVersion, GameMode, and Region are all required
     * parameters. Note that parameters specified in the search are required (they are not weighting factors). If a slot is
     * found in a server instance matching the parameters, the slot will be assigned to that player, removing it from the
     * availabe set. In that case, the information on the game session will be returned, otherwise the Status returned will be
     * GameNotFound.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* Matchmake(FClientMatchmakeRequest request,
            FDelegateOnSuccessMatchmake onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperMatchmake(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessStartGame, FClientStartGameResult, result, UObject*, customData);

    /** Start a new game server with a given configuration, add the current player and return the connection information. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* StartGame(FClientStartGameRequest request,
            FDelegateOnSuccessStartGame onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperStartGame(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Platform Specific Methods
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAndroidDevicePushNotificationRegistration, FClientAndroidDevicePushNotificationRegistrationResult, result, UObject*, customData);

    /** Registers the Android device to receive push notifications */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* AndroidDevicePushNotificationRegistration(FClientAndroidDevicePushNotificationRegistrationRequest request,
            FDelegateOnSuccessAndroidDevicePushNotificationRegistration onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAndroidDevicePushNotificationRegistration(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessConsumeMicrosoftStoreEntitlements, FClientConsumeMicrosoftStoreEntitlementsResponse, result, UObject*, customData);

    /** Grants the player's current entitlements from Microsoft Store's Collection API */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* ConsumeMicrosoftStoreEntitlements(FClientConsumeMicrosoftStoreEntitlementsRequest request,
            FDelegateOnSuccessConsumeMicrosoftStoreEntitlements onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperConsumeMicrosoftStoreEntitlements(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessConsumePS5Entitlements, FClientConsumePS5EntitlementsResult, result, UObject*, customData);

    /**
     * Checks for any new PS5 entitlements. If any are found, they are consumed (if they're consumables) and added as PlayFab
     * items
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* ConsumePS5Entitlements(FClientConsumePS5EntitlementsRequest request,
            FDelegateOnSuccessConsumePS5Entitlements onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperConsumePS5Entitlements(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessConsumePSNEntitlements, FClientConsumePSNEntitlementsResult, result, UObject*, customData);

    /** Checks for any new consumable entitlements. If any are found, they are consumed and added as PlayFab items */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* ConsumePSNEntitlements(FClientConsumePSNEntitlementsRequest request,
            FDelegateOnSuccessConsumePSNEntitlements onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperConsumePSNEntitlements(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessConsumeXboxEntitlements, FClientConsumeXboxEntitlementsResult, result, UObject*, customData);

    /**
     * Grants the player's current entitlements from Xbox Live, consuming all availble items in Xbox and granting them to the
     * player's PlayFab inventory. This call is idempotent and will not grant previously granted items to the player.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* ConsumeXboxEntitlements(FClientConsumeXboxEntitlementsRequest request,
            FDelegateOnSuccessConsumeXboxEntitlements onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperConsumeXboxEntitlements(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRefreshPSNAuthToken, FClientEmptyResponse, result, UObject*, customData);

    /** Uses the supplied OAuth code to refresh the internally cached player PSN auth token */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* RefreshPSNAuthToken(FClientRefreshPSNAuthTokenRequest request,
            FDelegateOnSuccessRefreshPSNAuthToken onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRefreshPSNAuthToken(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRegisterForIOSPushNotification, FClientRegisterForIOSPushNotificationResult, result, UObject*, customData);

    /** Registers the iOS device to receive push notifications */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* RegisterForIOSPushNotification(FClientRegisterForIOSPushNotificationRequest request,
            FDelegateOnSuccessRegisterForIOSPushNotification onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRegisterForIOSPushNotification(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRestoreIOSPurchases, FClientRestoreIOSPurchasesResult, result, UObject*, customData);

    /** Restores all in-app purchases based on the given restore receipt */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* RestoreIOSPurchases(FClientRestoreIOSPurchasesRequest request,
            FDelegateOnSuccessRestoreIOSPurchases onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRestoreIOSPurchases(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessValidateAmazonIAPReceipt, FClientValidateAmazonReceiptResult, result, UObject*, customData);

    /**
     * Validates with Amazon that the receipt for an Amazon App Store in-app purchase is valid and that it matches the
     * purchased catalog item
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* ValidateAmazonIAPReceipt(FClientValidateAmazonReceiptRequest request,
            FDelegateOnSuccessValidateAmazonIAPReceipt onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperValidateAmazonIAPReceipt(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessValidateGooglePlayPurchase, FClientValidateGooglePlayPurchaseResult, result, UObject*, customData);

    /** Validates a Google Play purchase and gives the corresponding item to the player. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* ValidateGooglePlayPurchase(FClientValidateGooglePlayPurchaseRequest request,
            FDelegateOnSuccessValidateGooglePlayPurchase onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperValidateGooglePlayPurchase(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessValidateIOSReceipt, FClientValidateIOSReceiptResult, result, UObject*, customData);

    /**
     * Validates with the Apple store that the receipt for an iOS in-app purchase is valid and that it matches the purchased
     * catalog item
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* ValidateIOSReceipt(FClientValidateIOSReceiptRequest request,
            FDelegateOnSuccessValidateIOSReceipt onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperValidateIOSReceipt(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessValidateWindowsStoreReceipt, FClientValidateWindowsReceiptResult, result, UObject*, customData);

    /**
     * Validates with Windows that the receipt for an Windows App Store in-app purchase is valid and that it matches the
     * purchased catalog item
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* ValidateWindowsStoreReceipt(FClientValidateWindowsReceiptRequest request,
            FDelegateOnSuccessValidateWindowsStoreReceipt onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperValidateWindowsStoreReceipt(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Player Data Management
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetFriendLeaderboard, FClientGetLeaderboardResult, result, UObject*, customData);

    /**
     * Retrieves a list of ranked friends of the current player for the given statistic, starting from the indicated point in
     * the leaderboard
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetFriendLeaderboard(FClientGetFriendLeaderboardRequest request,
            FDelegateOnSuccessGetFriendLeaderboard onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetFriendLeaderboard(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetFriendLeaderboardAroundPlayer, FClientGetFriendLeaderboardAroundPlayerResult, result, UObject*, customData);

    /**
     * Retrieves a list of ranked friends of the current player for the given statistic, centered on the requested PlayFab
     * user. If PlayFabId is empty or null will return currently logged in user.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetFriendLeaderboardAroundPlayer(FClientGetFriendLeaderboardAroundPlayerRequest request,
            FDelegateOnSuccessGetFriendLeaderboardAroundPlayer onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetFriendLeaderboardAroundPlayer(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetLeaderboard, FClientGetLeaderboardResult, result, UObject*, customData);

    /** Retrieves a list of ranked users for the given statistic, starting from the indicated point in the leaderboard */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetLeaderboard(FClientGetLeaderboardRequest request,
            FDelegateOnSuccessGetLeaderboard onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetLeaderboard(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetLeaderboardAroundPlayer, FClientGetLeaderboardAroundPlayerResult, result, UObject*, customData);

    /**
     * Retrieves a list of ranked users for the given statistic, centered on the requested player. If PlayFabId is empty or
     * null will return currently logged in user.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetLeaderboardAroundPlayer(FClientGetLeaderboardAroundPlayerRequest request,
            FDelegateOnSuccessGetLeaderboardAroundPlayer onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetLeaderboardAroundPlayer(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayerStatistics, FClientGetPlayerStatisticsResult, result, UObject*, customData);

    /**
     * Retrieves the indicated statistics (current version and values for all statistics, if none are specified), for the local
     * player.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetPlayerStatistics(FClientGetPlayerStatisticsRequest request,
            FDelegateOnSuccessGetPlayerStatistics onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayerStatistics(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayerStatisticVersions, FClientGetPlayerStatisticVersionsResult, result, UObject*, customData);

    /** Retrieves the information on the available versions of the specified statistic. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetPlayerStatisticVersions(FClientGetPlayerStatisticVersionsRequest request,
            FDelegateOnSuccessGetPlayerStatisticVersions onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayerStatisticVersions(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetUserData, FClientGetUserDataResult, result, UObject*, customData);

    /** Retrieves the title-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetUserData(FClientGetUserDataRequest request,
            FDelegateOnSuccessGetUserData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetUserData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetUserPublisherData, FClientGetUserDataResult, result, UObject*, customData);

    /** Retrieves the publisher-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetUserPublisherData(FClientGetUserDataRequest request,
            FDelegateOnSuccessGetUserPublisherData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetUserPublisherData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetUserPublisherReadOnlyData, FClientGetUserDataResult, result, UObject*, customData);

    /** Retrieves the publisher-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetUserPublisherReadOnlyData(FClientGetUserDataRequest request,
            FDelegateOnSuccessGetUserPublisherReadOnlyData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetUserPublisherReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetUserReadOnlyData, FClientGetUserDataResult, result, UObject*, customData);

    /** Retrieves the title-specific custom data for the user which can only be read by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetUserReadOnlyData(FClientGetUserDataRequest request,
            FDelegateOnSuccessGetUserReadOnlyData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetUserReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdatePlayerStatistics, FClientUpdatePlayerStatisticsResult, result, UObject*, customData);

    /**
     * Updates the values of the specified title-specific statistics for the user. By default, clients are not permitted to
     * update statistics. Developers may override this setting in the Game Manager > Settings > API Features.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UpdatePlayerStatistics(FClientUpdatePlayerStatisticsRequest request,
            FDelegateOnSuccessUpdatePlayerStatistics onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdatePlayerStatistics(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateUserData, FClientUpdateUserDataResult, result, UObject*, customData);

    /** Creates and updates the title-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UpdateUserData(FClientUpdateUserDataRequest request,
            FDelegateOnSuccessUpdateUserData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateUserData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateUserPublisherData, FClientUpdateUserDataResult, result, UObject*, customData);

    /** Creates and updates the publisher-specific custom data for the user which is readable and writable by the client */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UpdateUserPublisherData(FClientUpdateUserDataRequest request,
            FDelegateOnSuccessUpdateUserPublisherData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateUserPublisherData(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Player Item Management
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAddUserVirtualCurrency, FClientModifyUserVirtualCurrencyResult, result, UObject*, customData);

    /** Increments the user's balance of the specified virtual currency by the stated amount */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* AddUserVirtualCurrency(FClientAddUserVirtualCurrencyRequest request,
            FDelegateOnSuccessAddUserVirtualCurrency onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAddUserVirtualCurrency(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessConfirmPurchase, FClientConfirmPurchaseResult, result, UObject*, customData);

    /**
     * Confirms with the payment provider that the purchase was approved (if applicable) and adjusts inventory and virtual
     * currency balances as appropriate
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* ConfirmPurchase(FClientConfirmPurchaseRequest request,
            FDelegateOnSuccessConfirmPurchase onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperConfirmPurchase(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessConsumeItem, FClientConsumeItemResult, result, UObject*, customData);

    /** Consume uses of a consumable item. When all uses are consumed, it will be removed from the player's inventory. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* ConsumeItem(FClientConsumeItemRequest request,
            FDelegateOnSuccessConsumeItem onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperConsumeItem(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetCharacterInventory, FClientGetCharacterInventoryResult, result, UObject*, customData);

    /** Retrieves the specified character's current inventory of virtual goods */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetCharacterInventory(FClientGetCharacterInventoryRequest request,
            FDelegateOnSuccessGetCharacterInventory onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetCharacterInventory(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPaymentToken, FClientGetPaymentTokenResult, result, UObject*, customData);

    /**
     * For payments flows where the provider requires playfab (the fulfiller) to initiate the transaction, but the client
     * completes the rest of the flow. In the Xsolla case, the token returned here will be passed to Xsolla by the client to
     * create a cart. Poll GetPurchase using the returned OrderId once you've completed the payment.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetPaymentToken(FClientGetPaymentTokenRequest request,
            FDelegateOnSuccessGetPaymentToken onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPaymentToken(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPurchase, FClientGetPurchaseResult, result, UObject*, customData);

    /**
     * Retrieves a purchase along with its current PlayFab status. Returns inventory items from the purchase that are still
     * active.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetPurchase(FClientGetPurchaseRequest request,
            FDelegateOnSuccessGetPurchase onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPurchase(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetUserInventory, FClientGetUserInventoryResult, result, UObject*, customData);

    /** Retrieves the user's current inventory of virtual goods */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetUserInventory(FClientGetUserInventoryRequest request,
            FDelegateOnSuccessGetUserInventory onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetUserInventory(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessPayForPurchase, FClientPayForPurchaseResult, result, UObject*, customData);

    /** Selects a payment option for purchase order created via StartPurchase */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* PayForPurchase(FClientPayForPurchaseRequest request,
            FDelegateOnSuccessPayForPurchase onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperPayForPurchase(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessPurchaseItem, FClientPurchaseItemResult, result, UObject*, customData);

    /**
     * Buys a single item with virtual currency. You must specify both the virtual currency to use to purchase, as well as what
     * the client believes the price to be. This lets the server fail the purchase if the price has changed.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* PurchaseItem(FClientPurchaseItemRequest request,
            FDelegateOnSuccessPurchaseItem onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperPurchaseItem(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRedeemCoupon, FClientRedeemCouponResult, result, UObject*, customData);

    /**
     * Adds the virtual goods associated with the coupon to the user's inventory. Coupons can be generated via the
     * Economy->Catalogs tab in the PlayFab Game Manager.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* RedeemCoupon(FClientRedeemCouponRequest request,
            FDelegateOnSuccessRedeemCoupon onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRedeemCoupon(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessStartPurchase, FClientStartPurchaseResult, result, UObject*, customData);

    /** Creates an order for a list of items from the title catalog */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* StartPurchase(FClientStartPurchaseRequest request,
            FDelegateOnSuccessStartPurchase onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperStartPurchase(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSubtractUserVirtualCurrency, FClientModifyUserVirtualCurrencyResult, result, UObject*, customData);

    /**
     * Decrements the user's balance of the specified virtual currency by the stated amount. It is possible to make a VC
     * balance negative with this API.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* SubtractUserVirtualCurrency(FClientSubtractUserVirtualCurrencyRequest request,
            FDelegateOnSuccessSubtractUserVirtualCurrency onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSubtractUserVirtualCurrency(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlockContainerInstance, FClientUnlockContainerItemResult, result, UObject*, customData);

    /**
     * Opens the specified container, with the specified key (when required), and returns the contents of the opened container.
     * If the container (and key when relevant) are consumable (RemainingUses > 0), their RemainingUses will be decremented,
     * consistent with the operation of ConsumeItem.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UnlockContainerInstance(FClientUnlockContainerInstanceRequest request,
            FDelegateOnSuccessUnlockContainerInstance onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlockContainerInstance(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnlockContainerItem, FClientUnlockContainerItemResult, result, UObject*, customData);

    /**
     * Searches target inventory for an ItemInstance matching the given CatalogItemId, if necessary unlocks it using an
     * appropriate key, and returns the contents of the opened container. If the container (and key when relevant) are
     * consumable (RemainingUses > 0), their RemainingUses will be decremented, consistent with the operation of ConsumeItem.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UnlockContainerItem(FClientUnlockContainerItemRequest request,
            FDelegateOnSuccessUnlockContainerItem onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnlockContainerItem(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // PlayStream
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayerSegments, FClientGetPlayerSegmentsResult, result, UObject*, customData);

    /** List all segments that a player currently belongs to at this moment in time. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetPlayerSegments(FClientGetPlayerSegmentsRequest request,
            FDelegateOnSuccessGetPlayerSegments onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayerSegments(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayerTags, FClientGetPlayerTagsResult, result, UObject*, customData);

    /** Get all tags with a given Namespace (optional) from a player profile. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetPlayerTags(FClientGetPlayerTagsRequest request,
            FDelegateOnSuccessGetPlayerTags onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | PlayStream ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayerTags(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Server-Side Cloud Script
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessExecuteCloudScript, FClientExecuteCloudScriptResult, result, UObject*, customData);

    /** Executes a CloudScript function, with the 'currentPlayerId' set to the PlayFab ID of the authenticated player. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* ExecuteCloudScript(FClientExecuteCloudScriptRequest request,
            FDelegateOnSuccessExecuteCloudScript onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperExecuteCloudScript(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Shared Group Data
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAddSharedGroupMembers, FClientAddSharedGroupMembersResult, result, UObject*, customData);

    /**
     * Adds users to the set of those able to update both the shared data, as well as the set of users in the group. Only users
     * in the group can add new members. Shared Groups are designed for sharing data between a very small number of players,
     * please see our guide: https://docs.microsoft.com/gaming/playfab/features/social/groups/using-shared-group-data
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* AddSharedGroupMembers(FClientAddSharedGroupMembersRequest request,
            FDelegateOnSuccessAddSharedGroupMembers onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAddSharedGroupMembers(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateSharedGroup, FClientCreateSharedGroupResult, result, UObject*, customData);

    /**
     * Requests the creation of a shared group object, containing key/value pairs which may be updated by all members of the
     * group. Upon creation, the current user will be the only member of the group. Shared Groups are designed for sharing data
     * between a very small number of players, please see our guide:
     * https://docs.microsoft.com/gaming/playfab/features/social/groups/using-shared-group-data
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* CreateSharedGroup(FClientCreateSharedGroupRequest request,
            FDelegateOnSuccessCreateSharedGroup onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateSharedGroup(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetSharedGroupData, FClientGetSharedGroupDataResult, result, UObject*, customData);

    /**
     * Retrieves data stored in a shared group object, as well as the list of members in the group. Non-members of the group
     * may use this to retrieve group data, including membership, but they will not receive data for keys marked as private.
     * Shared Groups are designed for sharing data between a very small number of players, please see our guide:
     * https://docs.microsoft.com/gaming/playfab/features/social/groups/using-shared-group-data
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetSharedGroupData(FClientGetSharedGroupDataRequest request,
            FDelegateOnSuccessGetSharedGroupData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetSharedGroupData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRemoveSharedGroupMembers, FClientRemoveSharedGroupMembersResult, result, UObject*, customData);

    /**
     * Removes users from the set of those able to update the shared data and the set of users in the group. Only users in the
     * group can remove members. If as a result of the call, zero users remain with access, the group and its associated data
     * will be deleted. Shared Groups are designed for sharing data between a very small number of players, please see our
     * guide: https://docs.microsoft.com/gaming/playfab/features/social/groups/using-shared-group-data
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* RemoveSharedGroupMembers(FClientRemoveSharedGroupMembersRequest request,
            FDelegateOnSuccessRemoveSharedGroupMembers onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRemoveSharedGroupMembers(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateSharedGroupData, FClientUpdateSharedGroupDataResult, result, UObject*, customData);

    /**
     * Adds, updates, and removes data keys for a shared group object. If the permission is set to Public, all fields updated
     * or added in this call will be readable by users not in the group. By default, data permissions are set to Private.
     * Regardless of the permission setting, only members of the group can update the data. Shared Groups are designed for
     * sharing data between a very small number of players, please see our guide:
     * https://docs.microsoft.com/gaming/playfab/features/social/groups/using-shared-group-data
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* UpdateSharedGroupData(FClientUpdateSharedGroupDataRequest request,
            FDelegateOnSuccessUpdateSharedGroupData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Shared Group Data ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateSharedGroupData(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Title-Wide Data Management
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetCatalogItems, FClientGetCatalogItemsResult, result, UObject*, customData);

    /** Retrieves the specified version of the title's catalog of virtual goods, including all defined properties */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetCatalogItems(FClientGetCatalogItemsRequest request,
            FDelegateOnSuccessGetCatalogItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetCatalogItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPublisherData, FClientGetPublisherDataResult, result, UObject*, customData);

    /** Retrieves the key-value store of custom publisher settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetPublisherData(FClientGetPublisherDataRequest request,
            FDelegateOnSuccessGetPublisherData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPublisherData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetStoreItems, FClientGetStoreItemsResult, result, UObject*, customData);

    /** Retrieves the set of items defined for the specified store, including all prices defined */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetStoreItems(FClientGetStoreItemsRequest request,
            FDelegateOnSuccessGetStoreItems onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetStoreItems(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetTime, FClientGetTimeResult, result, UObject*, customData);

    /** Retrieves the current server time */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetTime(FClientGetTimeRequest request,
            FDelegateOnSuccessGetTime onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetTime(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetTitleData, FClientGetTitleDataResult, result, UObject*, customData);

    /** Retrieves the key-value store of custom title settings */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetTitleData(FClientGetTitleDataRequest request,
            FDelegateOnSuccessGetTitleData onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetTitleData(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetTitleNews, FClientGetTitleNewsResult, result, UObject*, customData);

    /** Retrieves the title news feed, as configured in the developer portal */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetTitleNews(FClientGetTitleNewsRequest request,
            FDelegateOnSuccessGetTitleNews onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Title-Wide Data Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetTitleNews(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Trading
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAcceptTrade, FClientAcceptTradeResponse, result, UObject*, customData);

    /**
     * Accepts an open trade (one that has not yet been accepted or cancelled), if the locally signed-in player is in the
     * allowed player list for the trade, or it is open to all players. If the call is successful, the offered and accepted
     * items will be swapped between the two players' inventories.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Trading ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* AcceptTrade(FClientAcceptTradeRequest request,
            FDelegateOnSuccessAcceptTrade onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Trading ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAcceptTrade(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCancelTrade, FClientCancelTradeResponse, result, UObject*, customData);

    /**
     * Cancels an open trade (one that has not yet been accepted or cancelled). Note that only the player who created the trade
     * can cancel it via this API call, to prevent griefing of the trade system (cancelling trades in order to prevent other
     * players from accepting them, for trades that can be claimed by more than one player).
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Trading ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* CancelTrade(FClientCancelTradeRequest request,
            FDelegateOnSuccessCancelTrade onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Trading ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCancelTrade(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPlayerTrades, FClientGetPlayerTradesResponse, result, UObject*, customData);

    /** Gets all trades the player has either opened or accepted, optionally filtered by trade status. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Trading ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetPlayerTrades(FClientGetPlayerTradesRequest request,
            FDelegateOnSuccessGetPlayerTrades onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Trading ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPlayerTrades(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetTradeStatus, FClientGetTradeStatusResponse, result, UObject*, customData);

    /** Gets the current status of an existing trade. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Trading ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* GetTradeStatus(FClientGetTradeStatusRequest request,
            FDelegateOnSuccessGetTradeStatus onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Trading ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetTradeStatus(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessOpenTrade, FClientOpenTradeResponse, result, UObject*, customData);

    /** Opens a new outstanding trade. Note that a given item instance may only be in one open trade at a time. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Trading ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabClientAPI* OpenTrade(FClientOpenTradeRequest request,
            FDelegateOnSuccessOpenTrade onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabClientRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Trading ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperOpenTrade(FPlayFabBaseModel response, UObject* customData, bool successful);



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
    FDelegateOnSuccessAddOrUpdateContactEmail OnSuccessAddOrUpdateContactEmail;
    FDelegateOnSuccessAddUsernamePassword OnSuccessAddUsernamePassword;
    FDelegateOnSuccessGetAccountInfo OnSuccessGetAccountInfo;
    FDelegateOnSuccessGetPlayerCombinedInfo OnSuccessGetPlayerCombinedInfo;
    FDelegateOnSuccessGetPlayerProfile OnSuccessGetPlayerProfile;
    FDelegateOnSuccessGetPlayFabIDsFromFacebookIDs OnSuccessGetPlayFabIDsFromFacebookIDs;
    FDelegateOnSuccessGetPlayFabIDsFromFacebookInstantGamesIds OnSuccessGetPlayFabIDsFromFacebookInstantGamesIds;
    FDelegateOnSuccessGetPlayFabIDsFromGameCenterIDs OnSuccessGetPlayFabIDsFromGameCenterIDs;
    FDelegateOnSuccessGetPlayFabIDsFromGenericIDs OnSuccessGetPlayFabIDsFromGenericIDs;
    FDelegateOnSuccessGetPlayFabIDsFromGoogleIDs OnSuccessGetPlayFabIDsFromGoogleIDs;
    FDelegateOnSuccessGetPlayFabIDsFromKongregateIDs OnSuccessGetPlayFabIDsFromKongregateIDs;
    FDelegateOnSuccessGetPlayFabIDsFromNintendoSwitchDeviceIds OnSuccessGetPlayFabIDsFromNintendoSwitchDeviceIds;
    FDelegateOnSuccessGetPlayFabIDsFromPSNAccountIDs OnSuccessGetPlayFabIDsFromPSNAccountIDs;
    FDelegateOnSuccessGetPlayFabIDsFromSteamIDs OnSuccessGetPlayFabIDsFromSteamIDs;
    FDelegateOnSuccessGetPlayFabIDsFromTwitchIDs OnSuccessGetPlayFabIDsFromTwitchIDs;
    FDelegateOnSuccessGetPlayFabIDsFromXboxLiveIDs OnSuccessGetPlayFabIDsFromXboxLiveIDs;
    FDelegateOnSuccessLinkAndroidDeviceID OnSuccessLinkAndroidDeviceID;
    FDelegateOnSuccessLinkApple OnSuccessLinkApple;
    FDelegateOnSuccessLinkCustomID OnSuccessLinkCustomID;
    FDelegateOnSuccessLinkFacebookAccount OnSuccessLinkFacebookAccount;
    FDelegateOnSuccessLinkFacebookInstantGamesId OnSuccessLinkFacebookInstantGamesId;
    FDelegateOnSuccessLinkGameCenterAccount OnSuccessLinkGameCenterAccount;
    FDelegateOnSuccessLinkGoogleAccount OnSuccessLinkGoogleAccount;
    FDelegateOnSuccessLinkIOSDeviceID OnSuccessLinkIOSDeviceID;
    FDelegateOnSuccessLinkKongregate OnSuccessLinkKongregate;
    FDelegateOnSuccessLinkNintendoServiceAccount OnSuccessLinkNintendoServiceAccount;
    FDelegateOnSuccessLinkNintendoSwitchDeviceId OnSuccessLinkNintendoSwitchDeviceId;
    FDelegateOnSuccessLinkOpenIdConnect OnSuccessLinkOpenIdConnect;
    FDelegateOnSuccessLinkPSNAccount OnSuccessLinkPSNAccount;
    FDelegateOnSuccessLinkSteamAccount OnSuccessLinkSteamAccount;
    FDelegateOnSuccessLinkTwitch OnSuccessLinkTwitch;
    FDelegateOnSuccessLinkXboxAccount OnSuccessLinkXboxAccount;
    FDelegateOnSuccessRemoveContactEmail OnSuccessRemoveContactEmail;
    FDelegateOnSuccessRemoveGenericID OnSuccessRemoveGenericID;
    FDelegateOnSuccessReportPlayer OnSuccessReportPlayer;
    FDelegateOnSuccessSendAccountRecoveryEmail OnSuccessSendAccountRecoveryEmail;
    FDelegateOnSuccessUnlinkAndroidDeviceID OnSuccessUnlinkAndroidDeviceID;
    FDelegateOnSuccessUnlinkApple OnSuccessUnlinkApple;
    FDelegateOnSuccessUnlinkCustomID OnSuccessUnlinkCustomID;
    FDelegateOnSuccessUnlinkFacebookAccount OnSuccessUnlinkFacebookAccount;
    FDelegateOnSuccessUnlinkFacebookInstantGamesId OnSuccessUnlinkFacebookInstantGamesId;
    FDelegateOnSuccessUnlinkGameCenterAccount OnSuccessUnlinkGameCenterAccount;
    FDelegateOnSuccessUnlinkGoogleAccount OnSuccessUnlinkGoogleAccount;
    FDelegateOnSuccessUnlinkIOSDeviceID OnSuccessUnlinkIOSDeviceID;
    FDelegateOnSuccessUnlinkKongregate OnSuccessUnlinkKongregate;
    FDelegateOnSuccessUnlinkNintendoServiceAccount OnSuccessUnlinkNintendoServiceAccount;
    FDelegateOnSuccessUnlinkNintendoSwitchDeviceId OnSuccessUnlinkNintendoSwitchDeviceId;
    FDelegateOnSuccessUnlinkOpenIdConnect OnSuccessUnlinkOpenIdConnect;
    FDelegateOnSuccessUnlinkPSNAccount OnSuccessUnlinkPSNAccount;
    FDelegateOnSuccessUnlinkSteamAccount OnSuccessUnlinkSteamAccount;
    FDelegateOnSuccessUnlinkTwitch OnSuccessUnlinkTwitch;
    FDelegateOnSuccessUnlinkXboxAccount OnSuccessUnlinkXboxAccount;
    FDelegateOnSuccessUpdateAvatarUrl OnSuccessUpdateAvatarUrl;
    FDelegateOnSuccessUpdateUserTitleDisplayName OnSuccessUpdateUserTitleDisplayName;
    FDelegateOnSuccessAttributeInstall OnSuccessAttributeInstall;
    FDelegateOnSuccessGetAdPlacements OnSuccessGetAdPlacements;
    FDelegateOnSuccessReportAdActivity OnSuccessReportAdActivity;
    FDelegateOnSuccessRewardAdActivity OnSuccessRewardAdActivity;
    FDelegateOnSuccessReportDeviceInfo OnSuccessReportDeviceInfo;
    FDelegateOnSuccessWriteCharacterEvent OnSuccessWriteCharacterEvent;
    FDelegateOnSuccessWritePlayerEvent OnSuccessWritePlayerEvent;
    FDelegateOnSuccessWriteTitleEvent OnSuccessWriteTitleEvent;
    FDelegateOnSuccessGetPhotonAuthenticationToken OnSuccessGetPhotonAuthenticationToken;
    FDelegateOnSuccessGetTitlePublicKey OnSuccessGetTitlePublicKey;
    FDelegateOnSuccessLoginWithAndroidDeviceID OnSuccessLoginWithAndroidDeviceID;
    FDelegateOnSuccessLoginWithApple OnSuccessLoginWithApple;
    FDelegateOnSuccessLoginWithCustomID OnSuccessLoginWithCustomID;
    FDelegateOnSuccessLoginWithEmailAddress OnSuccessLoginWithEmailAddress;
    FDelegateOnSuccessLoginWithFacebook OnSuccessLoginWithFacebook;
    FDelegateOnSuccessLoginWithFacebookInstantGamesId OnSuccessLoginWithFacebookInstantGamesId;
    FDelegateOnSuccessLoginWithGameCenter OnSuccessLoginWithGameCenter;
    FDelegateOnSuccessLoginWithGoogleAccount OnSuccessLoginWithGoogleAccount;
    FDelegateOnSuccessLoginWithIOSDeviceID OnSuccessLoginWithIOSDeviceID;
    FDelegateOnSuccessLoginWithKongregate OnSuccessLoginWithKongregate;
    FDelegateOnSuccessLoginWithNintendoServiceAccount OnSuccessLoginWithNintendoServiceAccount;
    FDelegateOnSuccessLoginWithNintendoSwitchDeviceId OnSuccessLoginWithNintendoSwitchDeviceId;
    FDelegateOnSuccessLoginWithOpenIdConnect OnSuccessLoginWithOpenIdConnect;
    FDelegateOnSuccessLoginWithPlayFab OnSuccessLoginWithPlayFab;
    FDelegateOnSuccessLoginWithPSN OnSuccessLoginWithPSN;
    FDelegateOnSuccessLoginWithSteam OnSuccessLoginWithSteam;
    FDelegateOnSuccessLoginWithTwitch OnSuccessLoginWithTwitch;
    FDelegateOnSuccessLoginWithXbox OnSuccessLoginWithXbox;
    FDelegateOnSuccessRegisterPlayFabUser OnSuccessRegisterPlayFabUser;
    FDelegateOnSuccessSetPlayerSecret OnSuccessSetPlayerSecret;
    FDelegateOnSuccessGetCharacterData OnSuccessGetCharacterData;
    FDelegateOnSuccessGetCharacterReadOnlyData OnSuccessGetCharacterReadOnlyData;
    FDelegateOnSuccessUpdateCharacterData OnSuccessUpdateCharacterData;
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
    FDelegateOnSuccessGetCurrentGames OnSuccessGetCurrentGames;
    FDelegateOnSuccessGetGameServerRegions OnSuccessGetGameServerRegions;
    FDelegateOnSuccessMatchmake OnSuccessMatchmake;
    FDelegateOnSuccessStartGame OnSuccessStartGame;
    FDelegateOnSuccessAndroidDevicePushNotificationRegistration OnSuccessAndroidDevicePushNotificationRegistration;
    FDelegateOnSuccessConsumeMicrosoftStoreEntitlements OnSuccessConsumeMicrosoftStoreEntitlements;
    FDelegateOnSuccessConsumePS5Entitlements OnSuccessConsumePS5Entitlements;
    FDelegateOnSuccessConsumePSNEntitlements OnSuccessConsumePSNEntitlements;
    FDelegateOnSuccessConsumeXboxEntitlements OnSuccessConsumeXboxEntitlements;
    FDelegateOnSuccessRefreshPSNAuthToken OnSuccessRefreshPSNAuthToken;
    FDelegateOnSuccessRegisterForIOSPushNotification OnSuccessRegisterForIOSPushNotification;
    FDelegateOnSuccessRestoreIOSPurchases OnSuccessRestoreIOSPurchases;
    FDelegateOnSuccessValidateAmazonIAPReceipt OnSuccessValidateAmazonIAPReceipt;
    FDelegateOnSuccessValidateGooglePlayPurchase OnSuccessValidateGooglePlayPurchase;
    FDelegateOnSuccessValidateIOSReceipt OnSuccessValidateIOSReceipt;
    FDelegateOnSuccessValidateWindowsStoreReceipt OnSuccessValidateWindowsStoreReceipt;
    FDelegateOnSuccessGetFriendLeaderboard OnSuccessGetFriendLeaderboard;
    FDelegateOnSuccessGetFriendLeaderboardAroundPlayer OnSuccessGetFriendLeaderboardAroundPlayer;
    FDelegateOnSuccessGetLeaderboard OnSuccessGetLeaderboard;
    FDelegateOnSuccessGetLeaderboardAroundPlayer OnSuccessGetLeaderboardAroundPlayer;
    FDelegateOnSuccessGetPlayerStatistics OnSuccessGetPlayerStatistics;
    FDelegateOnSuccessGetPlayerStatisticVersions OnSuccessGetPlayerStatisticVersions;
    FDelegateOnSuccessGetUserData OnSuccessGetUserData;
    FDelegateOnSuccessGetUserPublisherData OnSuccessGetUserPublisherData;
    FDelegateOnSuccessGetUserPublisherReadOnlyData OnSuccessGetUserPublisherReadOnlyData;
    FDelegateOnSuccessGetUserReadOnlyData OnSuccessGetUserReadOnlyData;
    FDelegateOnSuccessUpdatePlayerStatistics OnSuccessUpdatePlayerStatistics;
    FDelegateOnSuccessUpdateUserData OnSuccessUpdateUserData;
    FDelegateOnSuccessUpdateUserPublisherData OnSuccessUpdateUserPublisherData;
    FDelegateOnSuccessAddUserVirtualCurrency OnSuccessAddUserVirtualCurrency;
    FDelegateOnSuccessConfirmPurchase OnSuccessConfirmPurchase;
    FDelegateOnSuccessConsumeItem OnSuccessConsumeItem;
    FDelegateOnSuccessGetCharacterInventory OnSuccessGetCharacterInventory;
    FDelegateOnSuccessGetPaymentToken OnSuccessGetPaymentToken;
    FDelegateOnSuccessGetPurchase OnSuccessGetPurchase;
    FDelegateOnSuccessGetUserInventory OnSuccessGetUserInventory;
    FDelegateOnSuccessPayForPurchase OnSuccessPayForPurchase;
    FDelegateOnSuccessPurchaseItem OnSuccessPurchaseItem;
    FDelegateOnSuccessRedeemCoupon OnSuccessRedeemCoupon;
    FDelegateOnSuccessStartPurchase OnSuccessStartPurchase;
    FDelegateOnSuccessSubtractUserVirtualCurrency OnSuccessSubtractUserVirtualCurrency;
    FDelegateOnSuccessUnlockContainerInstance OnSuccessUnlockContainerInstance;
    FDelegateOnSuccessUnlockContainerItem OnSuccessUnlockContainerItem;
    FDelegateOnSuccessGetPlayerSegments OnSuccessGetPlayerSegments;
    FDelegateOnSuccessGetPlayerTags OnSuccessGetPlayerTags;
    FDelegateOnSuccessExecuteCloudScript OnSuccessExecuteCloudScript;
    FDelegateOnSuccessAddSharedGroupMembers OnSuccessAddSharedGroupMembers;
    FDelegateOnSuccessCreateSharedGroup OnSuccessCreateSharedGroup;
    FDelegateOnSuccessGetSharedGroupData OnSuccessGetSharedGroupData;
    FDelegateOnSuccessRemoveSharedGroupMembers OnSuccessRemoveSharedGroupMembers;
    FDelegateOnSuccessUpdateSharedGroupData OnSuccessUpdateSharedGroupData;
    FDelegateOnSuccessGetCatalogItems OnSuccessGetCatalogItems;
    FDelegateOnSuccessGetPublisherData OnSuccessGetPublisherData;
    FDelegateOnSuccessGetStoreItems OnSuccessGetStoreItems;
    FDelegateOnSuccessGetTime OnSuccessGetTime;
    FDelegateOnSuccessGetTitleData OnSuccessGetTitleData;
    FDelegateOnSuccessGetTitleNews OnSuccessGetTitleNews;
    FDelegateOnSuccessAcceptTrade OnSuccessAcceptTrade;
    FDelegateOnSuccessCancelTrade OnSuccessCancelTrade;
    FDelegateOnSuccessGetPlayerTrades OnSuccessGetPlayerTrades;
    FDelegateOnSuccessGetTradeStatus OnSuccessGetTradeStatus;
    FDelegateOnSuccessOpenTrade OnSuccessOpenTrade;

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
