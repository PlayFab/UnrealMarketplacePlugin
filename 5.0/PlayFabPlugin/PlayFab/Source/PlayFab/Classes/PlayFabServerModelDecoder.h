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
#include "PlayFabServerModels.h"
#include "PlayFabServerModelDecoder.generated.h"

class UPlayFabJsonObject;

UCLASS()
class PLAYFAB_API UPlayFabServerModelDecoder : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    //////////////////////////////////////////////////////////////////////////
    // Generated PlayFab Server API Functions
    //////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////
    // Account Management
    //////////////////////////////////////////////////////

    /** Decode the EmptyResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerEmptyResult decodeEmptyResultResponse(UPlayFabJsonObject* response);

    /** Decode the BanUsersResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerBanUsersResult decodeBanUsersResultResponse(UPlayFabJsonObject* response);

    /** Decode the DeletePlayerResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerDeletePlayerResult decodeDeletePlayerResultResponse(UPlayFabJsonObject* response);

    /** Decode the DeletePushNotificationTemplateResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerDeletePushNotificationTemplateResult decodeDeletePushNotificationTemplateResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayerProfileResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerGetPlayerProfileResult decodeGetPlayerProfileResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayFabIDsFromFacebookIDsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerGetPlayFabIDsFromFacebookIDsResult decodeGetPlayFabIDsFromFacebookIDsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayFabIDsFromFacebookInstantGamesIdsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerGetPlayFabIDsFromFacebookInstantGamesIdsResult decodeGetPlayFabIDsFromFacebookInstantGamesIdsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayFabIDsFromGenericIDsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerGetPlayFabIDsFromGenericIDsResult decodeGetPlayFabIDsFromGenericIDsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayFabIDsFromNintendoSwitchDeviceIdsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerGetPlayFabIDsFromNintendoSwitchDeviceIdsResult decodeGetPlayFabIDsFromNintendoSwitchDeviceIdsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayFabIDsFromPSNAccountIDsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerGetPlayFabIDsFromPSNAccountIDsResult decodeGetPlayFabIDsFromPSNAccountIDsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayFabIDsFromSteamIDsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerGetPlayFabIDsFromSteamIDsResult decodeGetPlayFabIDsFromSteamIDsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayFabIDsFromXboxLiveIDsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerGetPlayFabIDsFromXboxLiveIDsResult decodeGetPlayFabIDsFromXboxLiveIDsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetServerCustomIDsFromPlayFabIDsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerGetServerCustomIDsFromPlayFabIDsResult decodeGetServerCustomIDsFromPlayFabIDsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetUserAccountInfoResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerGetUserAccountInfoResult decodeGetUserAccountInfoResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetUserBansResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerGetUserBansResult decodeGetUserBansResultResponse(UPlayFabJsonObject* response);

    /** Decode the LinkPSNAccountResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerLinkPSNAccountResult decodeLinkPSNAccountResultResponse(UPlayFabJsonObject* response);

    /** Decode the LinkServerCustomIdResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerLinkServerCustomIdResult decodeLinkServerCustomIdResultResponse(UPlayFabJsonObject* response);

    /** Decode the LinkXboxAccountResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerLinkXboxAccountResult decodeLinkXboxAccountResultResponse(UPlayFabJsonObject* response);

    /** Decode the RevokeAllBansForUserResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerRevokeAllBansForUserResult decodeRevokeAllBansForUserResultResponse(UPlayFabJsonObject* response);

    /** Decode the RevokeBansResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerRevokeBansResult decodeRevokeBansResultResponse(UPlayFabJsonObject* response);

    /** Decode the SavePushNotificationTemplateResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerSavePushNotificationTemplateResult decodeSavePushNotificationTemplateResultResponse(UPlayFabJsonObject* response);

    /** Decode the SendCustomAccountRecoveryEmailResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerSendCustomAccountRecoveryEmailResult decodeSendCustomAccountRecoveryEmailResultResponse(UPlayFabJsonObject* response);

    /** Decode the SendEmailFromTemplateResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerSendEmailFromTemplateResult decodeSendEmailFromTemplateResultResponse(UPlayFabJsonObject* response);

    /** Decode the SendPushNotificationResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerSendPushNotificationResult decodeSendPushNotificationResultResponse(UPlayFabJsonObject* response);

    /** Decode the UnlinkPSNAccountResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerUnlinkPSNAccountResult decodeUnlinkPSNAccountResultResponse(UPlayFabJsonObject* response);

    /** Decode the UnlinkServerCustomIdResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerUnlinkServerCustomIdResult decodeUnlinkServerCustomIdResultResponse(UPlayFabJsonObject* response);

    /** Decode the UnlinkXboxAccountResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerUnlinkXboxAccountResult decodeUnlinkXboxAccountResultResponse(UPlayFabJsonObject* response);

    /** Decode the EmptyResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerEmptyResponse decodeEmptyResponseResponse(UPlayFabJsonObject* response);

    /** Decode the UpdateBansResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management Models")
        static FServerUpdateBansResult decodeUpdateBansResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Analytics
    //////////////////////////////////////////////////////

    /** Decode the WriteEventResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Analytics Models")
        static FServerWriteEventResponse decodeWriteEventResponseResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Authentication
    //////////////////////////////////////////////////////

    /** Decode the AuthenticateSessionTicketResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Authentication Models")
        static FServerAuthenticateSessionTicketResult decodeAuthenticateSessionTicketResultResponse(UPlayFabJsonObject* response);

    /** Decode the ServerLoginResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Authentication Models")
        static FServerServerLoginResult decodeServerLoginResultResponse(UPlayFabJsonObject* response);

    /** Decode the SetPlayerSecretResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Authentication Models")
        static FServerSetPlayerSecretResult decodeSetPlayerSecretResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Character Data
    //////////////////////////////////////////////////////

    /** Decode the GetCharacterDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data Models")
        static FServerGetCharacterDataResult decodeGetCharacterDataResultResponse(UPlayFabJsonObject* response);

    /** Decode the UpdateCharacterDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data Models")
        static FServerUpdateCharacterDataResult decodeUpdateCharacterDataResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Characters
    //////////////////////////////////////////////////////

    /** Decode the DeleteCharacterFromUserResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters Models")
        static FServerDeleteCharacterFromUserResult decodeDeleteCharacterFromUserResultResponse(UPlayFabJsonObject* response);

    /** Decode the ListUsersCharactersResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters Models")
        static FServerListUsersCharactersResult decodeListUsersCharactersResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetCharacterLeaderboardResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters Models")
        static FServerGetCharacterLeaderboardResult decodeGetCharacterLeaderboardResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetCharacterStatisticsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters Models")
        static FServerGetCharacterStatisticsResult decodeGetCharacterStatisticsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetLeaderboardAroundCharacterResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters Models")
        static FServerGetLeaderboardAroundCharacterResult decodeGetLeaderboardAroundCharacterResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetLeaderboardForUsersCharactersResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters Models")
        static FServerGetLeaderboardForUsersCharactersResult decodeGetLeaderboardForUsersCharactersResultResponse(UPlayFabJsonObject* response);

    /** Decode the GrantCharacterToUserResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters Models")
        static FServerGrantCharacterToUserResult decodeGrantCharacterToUserResultResponse(UPlayFabJsonObject* response);

    /** Decode the UpdateCharacterStatisticsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters Models")
        static FServerUpdateCharacterStatisticsResult decodeUpdateCharacterStatisticsResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Content
    //////////////////////////////////////////////////////

    /** Decode the GetContentDownloadUrlResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Content Models")
        static FServerGetContentDownloadUrlResult decodeGetContentDownloadUrlResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Friend List Management
    //////////////////////////////////////////////////////

    /** Decode the GetFriendsListResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Friend List Management Models")
        static FServerGetFriendsListResult decodeGetFriendsListResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Matchmaking
    //////////////////////////////////////////////////////

    /** Decode the DeregisterGameResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking Models")
        static FServerDeregisterGameResponse decodeDeregisterGameResponseResponse(UPlayFabJsonObject* response);

    /** Decode the NotifyMatchmakerPlayerLeftResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking Models")
        static FServerNotifyMatchmakerPlayerLeftResult decodeNotifyMatchmakerPlayerLeftResultResponse(UPlayFabJsonObject* response);

    /** Decode the RedeemMatchmakerTicketResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking Models")
        static FServerRedeemMatchmakerTicketResult decodeRedeemMatchmakerTicketResultResponse(UPlayFabJsonObject* response);

    /** Decode the RefreshGameServerInstanceHeartbeatResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking Models")
        static FServerRefreshGameServerInstanceHeartbeatResult decodeRefreshGameServerInstanceHeartbeatResultResponse(UPlayFabJsonObject* response);

    /** Decode the RegisterGameResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking Models")
        static FServerRegisterGameResponse decodeRegisterGameResponseResponse(UPlayFabJsonObject* response);

    /** Decode the SetGameServerInstanceDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking Models")
        static FServerSetGameServerInstanceDataResult decodeSetGameServerInstanceDataResultResponse(UPlayFabJsonObject* response);

    /** Decode the SetGameServerInstanceStateResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking Models")
        static FServerSetGameServerInstanceStateResult decodeSetGameServerInstanceStateResultResponse(UPlayFabJsonObject* response);

    /** Decode the SetGameServerInstanceTagsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking Models")
        static FServerSetGameServerInstanceTagsResult decodeSetGameServerInstanceTagsResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Platform Specific Methods
    //////////////////////////////////////////////////////

    /** Decode the AwardSteamAchievementResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Platform Specific Methods Models")
        static FServerAwardSteamAchievementResult decodeAwardSteamAchievementResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Player Data Management
    //////////////////////////////////////////////////////

    /** Decode the GetLeaderboardResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management Models")
        static FServerGetLeaderboardResult decodeGetLeaderboardResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetLeaderboardAroundUserResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management Models")
        static FServerGetLeaderboardAroundUserResult decodeGetLeaderboardAroundUserResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayerCombinedInfoResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management Models")
        static FServerGetPlayerCombinedInfoResult decodeGetPlayerCombinedInfoResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayerStatisticsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management Models")
        static FServerGetPlayerStatisticsResult decodeGetPlayerStatisticsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayerStatisticVersionsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management Models")
        static FServerGetPlayerStatisticVersionsResult decodeGetPlayerStatisticVersionsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetUserDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management Models")
        static FServerGetUserDataResult decodeGetUserDataResultResponse(UPlayFabJsonObject* response);

    /** Decode the UpdatePlayerStatisticsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management Models")
        static FServerUpdatePlayerStatisticsResult decodeUpdatePlayerStatisticsResultResponse(UPlayFabJsonObject* response);

    /** Decode the UpdateUserDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management Models")
        static FServerUpdateUserDataResult decodeUpdateUserDataResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Player Item Management
    //////////////////////////////////////////////////////

    /** Decode the ModifyCharacterVirtualCurrencyResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management Models")
        static FServerModifyCharacterVirtualCurrencyResult decodeModifyCharacterVirtualCurrencyResultResponse(UPlayFabJsonObject* response);

    /** Decode the ModifyUserVirtualCurrencyResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management Models")
        static FServerModifyUserVirtualCurrencyResult decodeModifyUserVirtualCurrencyResultResponse(UPlayFabJsonObject* response);

    /** Decode the ConsumeItemResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management Models")
        static FServerConsumeItemResult decodeConsumeItemResultResponse(UPlayFabJsonObject* response);

    /** Decode the EvaluateRandomResultTableResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management Models")
        static FServerEvaluateRandomResultTableResult decodeEvaluateRandomResultTableResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetCharacterInventoryResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management Models")
        static FServerGetCharacterInventoryResult decodeGetCharacterInventoryResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetRandomResultTablesResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management Models")
        static FServerGetRandomResultTablesResult decodeGetRandomResultTablesResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetUserInventoryResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management Models")
        static FServerGetUserInventoryResult decodeGetUserInventoryResultResponse(UPlayFabJsonObject* response);

    /** Decode the GrantItemsToCharacterResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management Models")
        static FServerGrantItemsToCharacterResult decodeGrantItemsToCharacterResultResponse(UPlayFabJsonObject* response);

    /** Decode the GrantItemsToUserResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management Models")
        static FServerGrantItemsToUserResult decodeGrantItemsToUserResultResponse(UPlayFabJsonObject* response);

    /** Decode the GrantItemsToUsersResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management Models")
        static FServerGrantItemsToUsersResult decodeGrantItemsToUsersResultResponse(UPlayFabJsonObject* response);

    /** Decode the ModifyItemUsesResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management Models")
        static FServerModifyItemUsesResult decodeModifyItemUsesResultResponse(UPlayFabJsonObject* response);

    /** Decode the MoveItemToCharacterFromCharacterResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management Models")
        static FServerMoveItemToCharacterFromCharacterResult decodeMoveItemToCharacterFromCharacterResultResponse(UPlayFabJsonObject* response);

    /** Decode the MoveItemToCharacterFromUserResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management Models")
        static FServerMoveItemToCharacterFromUserResult decodeMoveItemToCharacterFromUserResultResponse(UPlayFabJsonObject* response);

    /** Decode the MoveItemToUserFromCharacterResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management Models")
        static FServerMoveItemToUserFromCharacterResult decodeMoveItemToUserFromCharacterResultResponse(UPlayFabJsonObject* response);

    /** Decode the RedeemCouponResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management Models")
        static FServerRedeemCouponResult decodeRedeemCouponResultResponse(UPlayFabJsonObject* response);

    /** Decode the ReportPlayerServerResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management Models")
        static FServerReportPlayerServerResult decodeReportPlayerServerResultResponse(UPlayFabJsonObject* response);

    /** Decode the RevokeInventoryResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management Models")
        static FServerRevokeInventoryResult decodeRevokeInventoryResultResponse(UPlayFabJsonObject* response);

    /** Decode the RevokeInventoryItemsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management Models")
        static FServerRevokeInventoryItemsResult decodeRevokeInventoryItemsResultResponse(UPlayFabJsonObject* response);

    /** Decode the UnlockContainerItemResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management Models")
        static FServerUnlockContainerItemResult decodeUnlockContainerItemResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // PlayStream
    //////////////////////////////////////////////////////

    /** Decode the AddPlayerTagResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | PlayStream Models")
        static FServerAddPlayerTagResult decodeAddPlayerTagResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetAllSegmentsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | PlayStream Models")
        static FServerGetAllSegmentsResult decodeGetAllSegmentsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayerSegmentsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | PlayStream Models")
        static FServerGetPlayerSegmentsResult decodeGetPlayerSegmentsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayersInSegmentResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | PlayStream Models")
        static FServerGetPlayersInSegmentResult decodeGetPlayersInSegmentResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayerTagsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | PlayStream Models")
        static FServerGetPlayerTagsResult decodeGetPlayerTagsResultResponse(UPlayFabJsonObject* response);

    /** Decode the RemovePlayerTagResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | PlayStream Models")
        static FServerRemovePlayerTagResult decodeRemovePlayerTagResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Server-Side Cloud Script
    //////////////////////////////////////////////////////

    /** Decode the ExecuteCloudScriptResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        static FServerExecuteCloudScriptResult decodeExecuteCloudScriptResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Shared Group Data
    //////////////////////////////////////////////////////

    /** Decode the AddSharedGroupMembersResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data Models")
        static FServerAddSharedGroupMembersResult decodeAddSharedGroupMembersResultResponse(UPlayFabJsonObject* response);

    /** Decode the CreateSharedGroupResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data Models")
        static FServerCreateSharedGroupResult decodeCreateSharedGroupResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetSharedGroupDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data Models")
        static FServerGetSharedGroupDataResult decodeGetSharedGroupDataResultResponse(UPlayFabJsonObject* response);

    /** Decode the RemoveSharedGroupMembersResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data Models")
        static FServerRemoveSharedGroupMembersResult decodeRemoveSharedGroupMembersResultResponse(UPlayFabJsonObject* response);

    /** Decode the UpdateSharedGroupDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data Models")
        static FServerUpdateSharedGroupDataResult decodeUpdateSharedGroupDataResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Title-Wide Data Management
    //////////////////////////////////////////////////////

    /** Decode the GetCatalogItemsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management Models")
        static FServerGetCatalogItemsResult decodeGetCatalogItemsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPublisherDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management Models")
        static FServerGetPublisherDataResult decodeGetPublisherDataResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetStoreItemsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management Models")
        static FServerGetStoreItemsResult decodeGetStoreItemsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetTimeResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management Models")
        static FServerGetTimeResult decodeGetTimeResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetTitleDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management Models")
        static FServerGetTitleDataResult decodeGetTitleDataResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetTitleNewsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management Models")
        static FServerGetTitleNewsResult decodeGetTitleNewsResultResponse(UPlayFabJsonObject* response);

    /** Decode the SetPublisherDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management Models")
        static FServerSetPublisherDataResult decodeSetPublisherDataResultResponse(UPlayFabJsonObject* response);

    /** Decode the SetTitleDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title-Wide Data Management Models")
        static FServerSetTitleDataResult decodeSetTitleDataResultResponse(UPlayFabJsonObject* response);



};
