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
#include "PlayFabClientModels.h"
#include "PlayFabClientModelDecoder.generated.h"

class UPlayFabJsonObject;

UCLASS()
class PLAYFAB_API UPlayFabClientModelDecoder : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    //////////////////////////////////////////////////////////////////////////
    // Generated PlayFab Client API Functions
    //////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////
    // Account Management
    //////////////////////////////////////////////////////

    /** Decode the AddGenericIDResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientAddGenericIDResult decodeAddGenericIDResultResponse(UPlayFabJsonObject* response);

    /** Decode the AddOrUpdateContactEmailResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientAddOrUpdateContactEmailResult decodeAddOrUpdateContactEmailResultResponse(UPlayFabJsonObject* response);

    /** Decode the AddUsernamePasswordResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientAddUsernamePasswordResult decodeAddUsernamePasswordResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetAccountInfoResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientGetAccountInfoResult decodeGetAccountInfoResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayerCombinedInfoResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientGetPlayerCombinedInfoResult decodeGetPlayerCombinedInfoResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayerProfileResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientGetPlayerProfileResult decodeGetPlayerProfileResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayFabIDsFromFacebookIDsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientGetPlayFabIDsFromFacebookIDsResult decodeGetPlayFabIDsFromFacebookIDsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayFabIDsFromFacebookInstantGamesIdsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientGetPlayFabIDsFromFacebookInstantGamesIdsResult decodeGetPlayFabIDsFromFacebookInstantGamesIdsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayFabIDsFromGameCenterIDsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientGetPlayFabIDsFromGameCenterIDsResult decodeGetPlayFabIDsFromGameCenterIDsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayFabIDsFromGenericIDsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientGetPlayFabIDsFromGenericIDsResult decodeGetPlayFabIDsFromGenericIDsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayFabIDsFromGoogleIDsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientGetPlayFabIDsFromGoogleIDsResult decodeGetPlayFabIDsFromGoogleIDsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayFabIDsFromKongregateIDsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientGetPlayFabIDsFromKongregateIDsResult decodeGetPlayFabIDsFromKongregateIDsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayFabIDsFromNintendoSwitchDeviceIdsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientGetPlayFabIDsFromNintendoSwitchDeviceIdsResult decodeGetPlayFabIDsFromNintendoSwitchDeviceIdsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayFabIDsFromPSNAccountIDsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientGetPlayFabIDsFromPSNAccountIDsResult decodeGetPlayFabIDsFromPSNAccountIDsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayFabIDsFromSteamIDsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientGetPlayFabIDsFromSteamIDsResult decodeGetPlayFabIDsFromSteamIDsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayFabIDsFromTwitchIDsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientGetPlayFabIDsFromTwitchIDsResult decodeGetPlayFabIDsFromTwitchIDsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayFabIDsFromXboxLiveIDsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientGetPlayFabIDsFromXboxLiveIDsResult decodeGetPlayFabIDsFromXboxLiveIDsResultResponse(UPlayFabJsonObject* response);

    /** Decode the LinkAndroidDeviceIDResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientLinkAndroidDeviceIDResult decodeLinkAndroidDeviceIDResultResponse(UPlayFabJsonObject* response);

    /** Decode the EmptyResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientEmptyResult decodeEmptyResultResponse(UPlayFabJsonObject* response);

    /** Decode the LinkCustomIDResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientLinkCustomIDResult decodeLinkCustomIDResultResponse(UPlayFabJsonObject* response);

    /** Decode the LinkFacebookAccountResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientLinkFacebookAccountResult decodeLinkFacebookAccountResultResponse(UPlayFabJsonObject* response);

    /** Decode the LinkFacebookInstantGamesIdResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientLinkFacebookInstantGamesIdResult decodeLinkFacebookInstantGamesIdResultResponse(UPlayFabJsonObject* response);

    /** Decode the LinkGameCenterAccountResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientLinkGameCenterAccountResult decodeLinkGameCenterAccountResultResponse(UPlayFabJsonObject* response);

    /** Decode the LinkGoogleAccountResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientLinkGoogleAccountResult decodeLinkGoogleAccountResultResponse(UPlayFabJsonObject* response);

    /** Decode the LinkIOSDeviceIDResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientLinkIOSDeviceIDResult decodeLinkIOSDeviceIDResultResponse(UPlayFabJsonObject* response);

    /** Decode the LinkKongregateAccountResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientLinkKongregateAccountResult decodeLinkKongregateAccountResultResponse(UPlayFabJsonObject* response);

    /** Decode the LinkNintendoSwitchDeviceIdResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientLinkNintendoSwitchDeviceIdResult decodeLinkNintendoSwitchDeviceIdResultResponse(UPlayFabJsonObject* response);

    /** Decode the LinkPSNAccountResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientLinkPSNAccountResult decodeLinkPSNAccountResultResponse(UPlayFabJsonObject* response);

    /** Decode the LinkSteamAccountResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientLinkSteamAccountResult decodeLinkSteamAccountResultResponse(UPlayFabJsonObject* response);

    /** Decode the LinkTwitchAccountResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientLinkTwitchAccountResult decodeLinkTwitchAccountResultResponse(UPlayFabJsonObject* response);

    /** Decode the LinkXboxAccountResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientLinkXboxAccountResult decodeLinkXboxAccountResultResponse(UPlayFabJsonObject* response);

    /** Decode the RemoveContactEmailResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientRemoveContactEmailResult decodeRemoveContactEmailResultResponse(UPlayFabJsonObject* response);

    /** Decode the RemoveGenericIDResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientRemoveGenericIDResult decodeRemoveGenericIDResultResponse(UPlayFabJsonObject* response);

    /** Decode the ReportPlayerClientResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientReportPlayerClientResult decodeReportPlayerClientResultResponse(UPlayFabJsonObject* response);

    /** Decode the SendAccountRecoveryEmailResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientSendAccountRecoveryEmailResult decodeSendAccountRecoveryEmailResultResponse(UPlayFabJsonObject* response);

    /** Decode the UnlinkAndroidDeviceIDResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientUnlinkAndroidDeviceIDResult decodeUnlinkAndroidDeviceIDResultResponse(UPlayFabJsonObject* response);

    /** Decode the EmptyResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientEmptyResponse decodeEmptyResponseResponse(UPlayFabJsonObject* response);

    /** Decode the UnlinkCustomIDResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientUnlinkCustomIDResult decodeUnlinkCustomIDResultResponse(UPlayFabJsonObject* response);

    /** Decode the UnlinkFacebookAccountResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientUnlinkFacebookAccountResult decodeUnlinkFacebookAccountResultResponse(UPlayFabJsonObject* response);

    /** Decode the UnlinkFacebookInstantGamesIdResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientUnlinkFacebookInstantGamesIdResult decodeUnlinkFacebookInstantGamesIdResultResponse(UPlayFabJsonObject* response);

    /** Decode the UnlinkGameCenterAccountResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientUnlinkGameCenterAccountResult decodeUnlinkGameCenterAccountResultResponse(UPlayFabJsonObject* response);

    /** Decode the UnlinkGoogleAccountResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientUnlinkGoogleAccountResult decodeUnlinkGoogleAccountResultResponse(UPlayFabJsonObject* response);

    /** Decode the UnlinkIOSDeviceIDResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientUnlinkIOSDeviceIDResult decodeUnlinkIOSDeviceIDResultResponse(UPlayFabJsonObject* response);

    /** Decode the UnlinkKongregateAccountResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientUnlinkKongregateAccountResult decodeUnlinkKongregateAccountResultResponse(UPlayFabJsonObject* response);

    /** Decode the UnlinkNintendoSwitchDeviceIdResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientUnlinkNintendoSwitchDeviceIdResult decodeUnlinkNintendoSwitchDeviceIdResultResponse(UPlayFabJsonObject* response);

    /** Decode the UnlinkPSNAccountResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientUnlinkPSNAccountResult decodeUnlinkPSNAccountResultResponse(UPlayFabJsonObject* response);

    /** Decode the UnlinkSteamAccountResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientUnlinkSteamAccountResult decodeUnlinkSteamAccountResultResponse(UPlayFabJsonObject* response);

    /** Decode the UnlinkTwitchAccountResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientUnlinkTwitchAccountResult decodeUnlinkTwitchAccountResultResponse(UPlayFabJsonObject* response);

    /** Decode the UnlinkXboxAccountResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientUnlinkXboxAccountResult decodeUnlinkXboxAccountResultResponse(UPlayFabJsonObject* response);

    /** Decode the UpdateUserTitleDisplayNameResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management Models")
        static FClientUpdateUserTitleDisplayNameResult decodeUpdateUserTitleDisplayNameResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Advertising
    //////////////////////////////////////////////////////

    /** Decode the AttributeInstallResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Advertising Models")
        static FClientAttributeInstallResult decodeAttributeInstallResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetAdPlacementsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Advertising Models")
        static FClientGetAdPlacementsResult decodeGetAdPlacementsResultResponse(UPlayFabJsonObject* response);

    /** Decode the ReportAdActivityResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Advertising Models")
        static FClientReportAdActivityResult decodeReportAdActivityResultResponse(UPlayFabJsonObject* response);

    /** Decode the RewardAdActivityResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Advertising Models")
        static FClientRewardAdActivityResult decodeRewardAdActivityResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Analytics
    //////////////////////////////////////////////////////

    /** Decode the WriteEventResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Analytics Models")
        static FClientWriteEventResponse decodeWriteEventResponseResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Authentication
    //////////////////////////////////////////////////////

    /** Decode the GetPhotonAuthenticationTokenResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication Models")
        static FClientGetPhotonAuthenticationTokenResult decodeGetPhotonAuthenticationTokenResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetTitlePublicKeyResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication Models")
        static FClientGetTitlePublicKeyResult decodeGetTitlePublicKeyResultResponse(UPlayFabJsonObject* response);

    /** Decode the LoginResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication Models")
        static FClientLoginResult decodeLoginResultResponse(UPlayFabJsonObject* response);

    /** Decode the RegisterPlayFabUserResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication Models")
        static FClientRegisterPlayFabUserResult decodeRegisterPlayFabUserResultResponse(UPlayFabJsonObject* response);

    /** Decode the SetPlayerSecretResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication Models")
        static FClientSetPlayerSecretResult decodeSetPlayerSecretResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Character Data
    //////////////////////////////////////////////////////

    /** Decode the GetCharacterDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Character Data Models")
        static FClientGetCharacterDataResult decodeGetCharacterDataResultResponse(UPlayFabJsonObject* response);

    /** Decode the UpdateCharacterDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Character Data Models")
        static FClientUpdateCharacterDataResult decodeUpdateCharacterDataResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Characters
    //////////////////////////////////////////////////////

    /** Decode the ListUsersCharactersResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters Models")
        static FClientListUsersCharactersResult decodeListUsersCharactersResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetCharacterLeaderboardResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters Models")
        static FClientGetCharacterLeaderboardResult decodeGetCharacterLeaderboardResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetCharacterStatisticsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters Models")
        static FClientGetCharacterStatisticsResult decodeGetCharacterStatisticsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetLeaderboardAroundCharacterResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters Models")
        static FClientGetLeaderboardAroundCharacterResult decodeGetLeaderboardAroundCharacterResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetLeaderboardForUsersCharactersResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters Models")
        static FClientGetLeaderboardForUsersCharactersResult decodeGetLeaderboardForUsersCharactersResultResponse(UPlayFabJsonObject* response);

    /** Decode the GrantCharacterToUserResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters Models")
        static FClientGrantCharacterToUserResult decodeGrantCharacterToUserResultResponse(UPlayFabJsonObject* response);

    /** Decode the UpdateCharacterStatisticsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters Models")
        static FClientUpdateCharacterStatisticsResult decodeUpdateCharacterStatisticsResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Content
    //////////////////////////////////////////////////////

    /** Decode the GetContentDownloadUrlResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Content Models")
        static FClientGetContentDownloadUrlResult decodeGetContentDownloadUrlResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Friend List Management
    //////////////////////////////////////////////////////

    /** Decode the AddFriendResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Friend List Management Models")
        static FClientAddFriendResult decodeAddFriendResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetFriendsListResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Friend List Management Models")
        static FClientGetFriendsListResult decodeGetFriendsListResultResponse(UPlayFabJsonObject* response);

    /** Decode the RemoveFriendResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Friend List Management Models")
        static FClientRemoveFriendResult decodeRemoveFriendResultResponse(UPlayFabJsonObject* response);

    /** Decode the SetFriendTagsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Friend List Management Models")
        static FClientSetFriendTagsResult decodeSetFriendTagsResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Matchmaking
    //////////////////////////////////////////////////////

    /** Decode the CurrentGamesResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Matchmaking Models")
        static FClientCurrentGamesResult decodeCurrentGamesResultResponse(UPlayFabJsonObject* response);

    /** Decode the GameServerRegionsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Matchmaking Models")
        static FClientGameServerRegionsResult decodeGameServerRegionsResultResponse(UPlayFabJsonObject* response);

    /** Decode the MatchmakeResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Matchmaking Models")
        static FClientMatchmakeResult decodeMatchmakeResultResponse(UPlayFabJsonObject* response);

    /** Decode the StartGameResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Matchmaking Models")
        static FClientStartGameResult decodeStartGameResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Platform Specific Methods
    //////////////////////////////////////////////////////

    /** Decode the AndroidDevicePushNotificationRegistrationResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods Models")
        static FClientAndroidDevicePushNotificationRegistrationResult decodeAndroidDevicePushNotificationRegistrationResultResponse(UPlayFabJsonObject* response);

    /** Decode the ConsumeMicrosoftStoreEntitlementsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods Models")
        static FClientConsumeMicrosoftStoreEntitlementsResponse decodeConsumeMicrosoftStoreEntitlementsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ConsumePS5EntitlementsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods Models")
        static FClientConsumePS5EntitlementsResult decodeConsumePS5EntitlementsResultResponse(UPlayFabJsonObject* response);

    /** Decode the ConsumePSNEntitlementsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods Models")
        static FClientConsumePSNEntitlementsResult decodeConsumePSNEntitlementsResultResponse(UPlayFabJsonObject* response);

    /** Decode the ConsumeXboxEntitlementsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods Models")
        static FClientConsumeXboxEntitlementsResult decodeConsumeXboxEntitlementsResultResponse(UPlayFabJsonObject* response);

    /** Decode the RegisterForIOSPushNotificationResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods Models")
        static FClientRegisterForIOSPushNotificationResult decodeRegisterForIOSPushNotificationResultResponse(UPlayFabJsonObject* response);

    /** Decode the RestoreIOSPurchasesResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods Models")
        static FClientRestoreIOSPurchasesResult decodeRestoreIOSPurchasesResultResponse(UPlayFabJsonObject* response);

    /** Decode the ValidateAmazonReceiptResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods Models")
        static FClientValidateAmazonReceiptResult decodeValidateAmazonReceiptResultResponse(UPlayFabJsonObject* response);

    /** Decode the ValidateGooglePlayPurchaseResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods Models")
        static FClientValidateGooglePlayPurchaseResult decodeValidateGooglePlayPurchaseResultResponse(UPlayFabJsonObject* response);

    /** Decode the ValidateIOSReceiptResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods Models")
        static FClientValidateIOSReceiptResult decodeValidateIOSReceiptResultResponse(UPlayFabJsonObject* response);

    /** Decode the ValidateWindowsReceiptResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Platform Specific Methods Models")
        static FClientValidateWindowsReceiptResult decodeValidateWindowsReceiptResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Player Data Management
    //////////////////////////////////////////////////////

    /** Decode the GetLeaderboardResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management Models")
        static FClientGetLeaderboardResult decodeGetLeaderboardResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetFriendLeaderboardAroundPlayerResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management Models")
        static FClientGetFriendLeaderboardAroundPlayerResult decodeGetFriendLeaderboardAroundPlayerResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetLeaderboardAroundPlayerResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management Models")
        static FClientGetLeaderboardAroundPlayerResult decodeGetLeaderboardAroundPlayerResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayerStatisticsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management Models")
        static FClientGetPlayerStatisticsResult decodeGetPlayerStatisticsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayerStatisticVersionsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management Models")
        static FClientGetPlayerStatisticVersionsResult decodeGetPlayerStatisticVersionsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetUserDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management Models")
        static FClientGetUserDataResult decodeGetUserDataResultResponse(UPlayFabJsonObject* response);

    /** Decode the UpdatePlayerStatisticsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management Models")
        static FClientUpdatePlayerStatisticsResult decodeUpdatePlayerStatisticsResultResponse(UPlayFabJsonObject* response);

    /** Decode the UpdateUserDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management Models")
        static FClientUpdateUserDataResult decodeUpdateUserDataResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Player Item Management
    //////////////////////////////////////////////////////

    /** Decode the ModifyUserVirtualCurrencyResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management Models")
        static FClientModifyUserVirtualCurrencyResult decodeModifyUserVirtualCurrencyResultResponse(UPlayFabJsonObject* response);

    /** Decode the ConfirmPurchaseResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management Models")
        static FClientConfirmPurchaseResult decodeConfirmPurchaseResultResponse(UPlayFabJsonObject* response);

    /** Decode the ConsumeItemResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management Models")
        static FClientConsumeItemResult decodeConsumeItemResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetCharacterInventoryResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management Models")
        static FClientGetCharacterInventoryResult decodeGetCharacterInventoryResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPaymentTokenResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management Models")
        static FClientGetPaymentTokenResult decodeGetPaymentTokenResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPurchaseResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management Models")
        static FClientGetPurchaseResult decodeGetPurchaseResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetUserInventoryResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management Models")
        static FClientGetUserInventoryResult decodeGetUserInventoryResultResponse(UPlayFabJsonObject* response);

    /** Decode the PayForPurchaseResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management Models")
        static FClientPayForPurchaseResult decodePayForPurchaseResultResponse(UPlayFabJsonObject* response);

    /** Decode the PurchaseItemResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management Models")
        static FClientPurchaseItemResult decodePurchaseItemResultResponse(UPlayFabJsonObject* response);

    /** Decode the RedeemCouponResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management Models")
        static FClientRedeemCouponResult decodeRedeemCouponResultResponse(UPlayFabJsonObject* response);

    /** Decode the StartPurchaseResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management Models")
        static FClientStartPurchaseResult decodeStartPurchaseResultResponse(UPlayFabJsonObject* response);

    /** Decode the UnlockContainerItemResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management Models")
        static FClientUnlockContainerItemResult decodeUnlockContainerItemResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // PlayStream
    //////////////////////////////////////////////////////

    /** Decode the GetPlayerSegmentsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | PlayStream Models")
        static FClientGetPlayerSegmentsResult decodeGetPlayerSegmentsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayerTagsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | PlayStream Models")
        static FClientGetPlayerTagsResult decodeGetPlayerTagsResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Server-Side Cloud Script
    //////////////////////////////////////////////////////

    /** Decode the ExecuteCloudScriptResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Server-Side Cloud Script Models")
        static FClientExecuteCloudScriptResult decodeExecuteCloudScriptResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Shared Group Data
    //////////////////////////////////////////////////////

    /** Decode the AddSharedGroupMembersResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Shared Group Data Models")
        static FClientAddSharedGroupMembersResult decodeAddSharedGroupMembersResultResponse(UPlayFabJsonObject* response);

    /** Decode the CreateSharedGroupResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Shared Group Data Models")
        static FClientCreateSharedGroupResult decodeCreateSharedGroupResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetSharedGroupDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Shared Group Data Models")
        static FClientGetSharedGroupDataResult decodeGetSharedGroupDataResultResponse(UPlayFabJsonObject* response);

    /** Decode the RemoveSharedGroupMembersResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Shared Group Data Models")
        static FClientRemoveSharedGroupMembersResult decodeRemoveSharedGroupMembersResultResponse(UPlayFabJsonObject* response);

    /** Decode the UpdateSharedGroupDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Shared Group Data Models")
        static FClientUpdateSharedGroupDataResult decodeUpdateSharedGroupDataResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Title-Wide Data Management
    //////////////////////////////////////////////////////

    /** Decode the GetCatalogItemsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Title-Wide Data Management Models")
        static FClientGetCatalogItemsResult decodeGetCatalogItemsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPublisherDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Title-Wide Data Management Models")
        static FClientGetPublisherDataResult decodeGetPublisherDataResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetStoreItemsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Title-Wide Data Management Models")
        static FClientGetStoreItemsResult decodeGetStoreItemsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetTimeResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Title-Wide Data Management Models")
        static FClientGetTimeResult decodeGetTimeResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetTitleDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Title-Wide Data Management Models")
        static FClientGetTitleDataResult decodeGetTitleDataResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetTitleNewsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Title-Wide Data Management Models")
        static FClientGetTitleNewsResult decodeGetTitleNewsResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Trading
    //////////////////////////////////////////////////////

    /** Decode the AcceptTradeResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Trading Models")
        static FClientAcceptTradeResponse decodeAcceptTradeResponseResponse(UPlayFabJsonObject* response);

    /** Decode the CancelTradeResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Trading Models")
        static FClientCancelTradeResponse decodeCancelTradeResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayerTradesResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Trading Models")
        static FClientGetPlayerTradesResponse decodeGetPlayerTradesResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetTradeStatusResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Trading Models")
        static FClientGetTradeStatusResponse decodeGetTradeStatusResponseResponse(UPlayFabJsonObject* response);

    /** Decode the OpenTradeResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Trading Models")
        static FClientOpenTradeResponse decodeOpenTradeResponseResponse(UPlayFabJsonObject* response);



};
