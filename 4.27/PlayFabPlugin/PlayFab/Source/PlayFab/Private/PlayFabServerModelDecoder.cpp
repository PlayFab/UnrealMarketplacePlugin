//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the play fab models
//
// API: Server
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabServerModelDecoder.h"
#include "PlayFabPrivate.h"

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Server API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////

FServerEmptyResult UPlayFabServerModelDecoder::decodeEmptyResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerEmptyResult tempStruct;


    return tempStruct;
}

FServerBanUsersResult UPlayFabServerModelDecoder::decodeBanUsersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerBanUsersResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.BanData = !(dataObj->HasField("BanData")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("BanData");

    return tempStruct;
}

FServerDeletePlayerResult UPlayFabServerModelDecoder::decodeDeletePlayerResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerDeletePlayerResult tempStruct;


    return tempStruct;
}

FServerDeletePushNotificationTemplateResult UPlayFabServerModelDecoder::decodeDeletePushNotificationTemplateResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerDeletePushNotificationTemplateResult tempStruct;


    return tempStruct;
}

FServerGetPlayerProfileResult UPlayFabServerModelDecoder::decodeGetPlayerProfileResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetPlayerProfileResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.PlayerProfile = !(dataObj->HasField("PlayerProfile")) ? nullptr : dataObj->GetObjectField("PlayerProfile");

    return tempStruct;
}

FServerGetPlayFabIDsFromFacebookIDsResult UPlayFabServerModelDecoder::decodeGetPlayFabIDsFromFacebookIDsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetPlayFabIDsFromFacebookIDsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Data");

    return tempStruct;
}

FServerGetPlayFabIDsFromFacebookInstantGamesIdsResult UPlayFabServerModelDecoder::decodeGetPlayFabIDsFromFacebookInstantGamesIdsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetPlayFabIDsFromFacebookInstantGamesIdsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Data");

    return tempStruct;
}

FServerGetPlayFabIDsFromGenericIDsResult UPlayFabServerModelDecoder::decodeGetPlayFabIDsFromGenericIDsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetPlayFabIDsFromGenericIDsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Data");

    return tempStruct;
}

FServerGetPlayFabIDsFromNintendoSwitchDeviceIdsResult UPlayFabServerModelDecoder::decodeGetPlayFabIDsFromNintendoSwitchDeviceIdsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetPlayFabIDsFromNintendoSwitchDeviceIdsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Data");

    return tempStruct;
}

FServerGetPlayFabIDsFromPSNAccountIDsResult UPlayFabServerModelDecoder::decodeGetPlayFabIDsFromPSNAccountIDsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetPlayFabIDsFromPSNAccountIDsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Data");

    return tempStruct;
}

FServerGetPlayFabIDsFromSteamIDsResult UPlayFabServerModelDecoder::decodeGetPlayFabIDsFromSteamIDsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetPlayFabIDsFromSteamIDsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Data");

    return tempStruct;
}

FServerGetPlayFabIDsFromXboxLiveIDsResult UPlayFabServerModelDecoder::decodeGetPlayFabIDsFromXboxLiveIDsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetPlayFabIDsFromXboxLiveIDsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Data");

    return tempStruct;
}

FServerGetServerCustomIDsFromPlayFabIDsResult UPlayFabServerModelDecoder::decodeGetServerCustomIDsFromPlayFabIDsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetServerCustomIDsFromPlayFabIDsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Data");

    return tempStruct;
}

FServerGetUserAccountInfoResult UPlayFabServerModelDecoder::decodeGetUserAccountInfoResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetUserAccountInfoResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.UserInfo = !(dataObj->HasField("UserInfo")) ? nullptr : dataObj->GetObjectField("UserInfo");

    return tempStruct;
}

FServerGetUserBansResult UPlayFabServerModelDecoder::decodeGetUserBansResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetUserBansResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.BanData = !(dataObj->HasField("BanData")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("BanData");

    return tempStruct;
}

FServerLinkPSNAccountResult UPlayFabServerModelDecoder::decodeLinkPSNAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerLinkPSNAccountResult tempStruct;


    return tempStruct;
}

FServerLinkServerCustomIdResult UPlayFabServerModelDecoder::decodeLinkServerCustomIdResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerLinkServerCustomIdResult tempStruct;


    return tempStruct;
}

FServerLinkXboxAccountResult UPlayFabServerModelDecoder::decodeLinkXboxAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerLinkXboxAccountResult tempStruct;


    return tempStruct;
}

FServerRevokeAllBansForUserResult UPlayFabServerModelDecoder::decodeRevokeAllBansForUserResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerRevokeAllBansForUserResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.BanData = !(dataObj->HasField("BanData")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("BanData");

    return tempStruct;
}

FServerRevokeBansResult UPlayFabServerModelDecoder::decodeRevokeBansResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerRevokeBansResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.BanData = !(dataObj->HasField("BanData")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("BanData");

    return tempStruct;
}

FServerSavePushNotificationTemplateResult UPlayFabServerModelDecoder::decodeSavePushNotificationTemplateResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerSavePushNotificationTemplateResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.PushNotificationTemplateId = !(dataObj->HasField("PushNotificationTemplateId")) ? TEXT("") : dataObj->GetStringField("PushNotificationTemplateId");

    return tempStruct;
}

FServerSendCustomAccountRecoveryEmailResult UPlayFabServerModelDecoder::decodeSendCustomAccountRecoveryEmailResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerSendCustomAccountRecoveryEmailResult tempStruct;


    return tempStruct;
}

FServerSendEmailFromTemplateResult UPlayFabServerModelDecoder::decodeSendEmailFromTemplateResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerSendEmailFromTemplateResult tempStruct;


    return tempStruct;
}

FServerSendPushNotificationResult UPlayFabServerModelDecoder::decodeSendPushNotificationResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerSendPushNotificationResult tempStruct;


    return tempStruct;
}

FServerUnlinkPSNAccountResult UPlayFabServerModelDecoder::decodeUnlinkPSNAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerUnlinkPSNAccountResult tempStruct;


    return tempStruct;
}

FServerUnlinkServerCustomIdResult UPlayFabServerModelDecoder::decodeUnlinkServerCustomIdResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerUnlinkServerCustomIdResult tempStruct;


    return tempStruct;
}

FServerUnlinkXboxAccountResult UPlayFabServerModelDecoder::decodeUnlinkXboxAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerUnlinkXboxAccountResult tempStruct;


    return tempStruct;
}

FServerEmptyResponse UPlayFabServerModelDecoder::decodeEmptyResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerEmptyResponse tempStruct;


    return tempStruct;
}

FServerUpdateBansResult UPlayFabServerModelDecoder::decodeUpdateBansResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerUpdateBansResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.BanData = !(dataObj->HasField("BanData")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("BanData");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Analytics
//////////////////////////////////////////////////////

FServerWriteEventResponse UPlayFabServerModelDecoder::decodeWriteEventResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerWriteEventResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.EventId = !(dataObj->HasField("EventId")) ? TEXT("") : dataObj->GetStringField("EventId");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Authentication
//////////////////////////////////////////////////////

FServerAuthenticateSessionTicketResult UPlayFabServerModelDecoder::decodeAuthenticateSessionTicketResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerAuthenticateSessionTicketResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.IsSessionTicketExpired = !(dataObj->HasField("IsSessionTicketExpired")) ? false : dataObj->GetBoolField("IsSessionTicketExpired");
    tempStruct.UserInfo = !(dataObj->HasField("UserInfo")) ? nullptr : dataObj->GetObjectField("UserInfo");

    return tempStruct;
}

FServerServerLoginResult UPlayFabServerModelDecoder::decodeServerLoginResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerServerLoginResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.EntityToken = !(dataObj->HasField("EntityToken")) ? nullptr : dataObj->GetObjectField("EntityToken");
    tempStruct.InfoResultPayload = !(dataObj->HasField("InfoResultPayload")) ? nullptr : dataObj->GetObjectField("InfoResultPayload");
    tempStruct.LastLoginTime = !(dataObj->HasField("LastLoginTime")) ? TEXT("") : dataObj->GetStringField("LastLoginTime");
    tempStruct.NewlyCreated = !(dataObj->HasField("NewlyCreated")) ? false : dataObj->GetBoolField("NewlyCreated");
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");
    tempStruct.SessionTicket = !(dataObj->HasField("SessionTicket")) ? TEXT("") : dataObj->GetStringField("SessionTicket");
    tempStruct.SettingsForUser = !(dataObj->HasField("SettingsForUser")) ? nullptr : dataObj->GetObjectField("SettingsForUser");
    tempStruct.TreatmentAssignment = !(dataObj->HasField("TreatmentAssignment")) ? nullptr : dataObj->GetObjectField("TreatmentAssignment");

    return tempStruct;
}

FServerSetPlayerSecretResult UPlayFabServerModelDecoder::decodeSetPlayerSecretResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerSetPlayerSecretResult tempStruct;


    return tempStruct;
}



///////////////////////////////////////////////////////
// Character Data
//////////////////////////////////////////////////////

FServerGetCharacterDataResult UPlayFabServerModelDecoder::decodeGetCharacterDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetCharacterDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.CharacterId = !(dataObj->HasField("CharacterId")) ? TEXT("") : dataObj->GetStringField("CharacterId");
    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");
    tempStruct.DataVersion = !(dataObj->HasField("DataVersion")) ? 0 : int(dataObj->GetNumberField("DataVersion"));
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");

    return tempStruct;
}

FServerUpdateCharacterDataResult UPlayFabServerModelDecoder::decodeUpdateCharacterDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerUpdateCharacterDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.DataVersion = !(dataObj->HasField("DataVersion")) ? 0 : int(dataObj->GetNumberField("DataVersion"));

    return tempStruct;
}



///////////////////////////////////////////////////////
// Characters
//////////////////////////////////////////////////////

FServerDeleteCharacterFromUserResult UPlayFabServerModelDecoder::decodeDeleteCharacterFromUserResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerDeleteCharacterFromUserResult tempStruct;


    return tempStruct;
}

FServerListUsersCharactersResult UPlayFabServerModelDecoder::decodeListUsersCharactersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerListUsersCharactersResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Characters = !(dataObj->HasField("Characters")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Characters");

    return tempStruct;
}

FServerGetCharacterLeaderboardResult UPlayFabServerModelDecoder::decodeGetCharacterLeaderboardResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetCharacterLeaderboardResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Leaderboard = !(dataObj->HasField("Leaderboard")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FServerGetCharacterStatisticsResult UPlayFabServerModelDecoder::decodeGetCharacterStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetCharacterStatisticsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.CharacterId = !(dataObj->HasField("CharacterId")) ? TEXT("") : dataObj->GetStringField("CharacterId");
    tempStruct.CharacterStatistics = !(dataObj->HasField("CharacterStatistics")) ? nullptr : dataObj->GetObjectField("CharacterStatistics");
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");

    return tempStruct;
}

FServerGetLeaderboardAroundCharacterResult UPlayFabServerModelDecoder::decodeGetLeaderboardAroundCharacterResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetLeaderboardAroundCharacterResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Leaderboard = !(dataObj->HasField("Leaderboard")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FServerGetLeaderboardForUsersCharactersResult UPlayFabServerModelDecoder::decodeGetLeaderboardForUsersCharactersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetLeaderboardForUsersCharactersResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Leaderboard = !(dataObj->HasField("Leaderboard")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Leaderboard");

    return tempStruct;
}

FServerGrantCharacterToUserResult UPlayFabServerModelDecoder::decodeGrantCharacterToUserResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGrantCharacterToUserResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.CharacterId = !(dataObj->HasField("CharacterId")) ? TEXT("") : dataObj->GetStringField("CharacterId");

    return tempStruct;
}

FServerUpdateCharacterStatisticsResult UPlayFabServerModelDecoder::decodeUpdateCharacterStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerUpdateCharacterStatisticsResult tempStruct;


    return tempStruct;
}



///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////

FServerGetContentDownloadUrlResult UPlayFabServerModelDecoder::decodeGetContentDownloadUrlResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetContentDownloadUrlResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.URL = !(dataObj->HasField("URL")) ? TEXT("") : dataObj->GetStringField("URL");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Friend List Management
//////////////////////////////////////////////////////

FServerGetFriendsListResult UPlayFabServerModelDecoder::decodeGetFriendsListResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetFriendsListResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Friends = !(dataObj->HasField("Friends")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Friends");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Matchmaking
//////////////////////////////////////////////////////

FServerDeregisterGameResponse UPlayFabServerModelDecoder::decodeDeregisterGameResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerDeregisterGameResponse tempStruct;


    return tempStruct;
}

FServerNotifyMatchmakerPlayerLeftResult UPlayFabServerModelDecoder::decodeNotifyMatchmakerPlayerLeftResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerNotifyMatchmakerPlayerLeftResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    GetEnumValueFromString<EPlayerConnectionState>(TEXT("EPlayerConnectionState"), dataObj->GetStringField("PlayerState"), tempStruct.PlayerState);

    return tempStruct;
}

FServerRedeemMatchmakerTicketResult UPlayFabServerModelDecoder::decodeRedeemMatchmakerTicketResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerRedeemMatchmakerTicketResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Error = !(dataObj->HasField("Error")) ? TEXT("") : dataObj->GetStringField("Error");
    tempStruct.TicketIsValid = !(dataObj->HasField("TicketIsValid")) ? false : dataObj->GetBoolField("TicketIsValid");
    tempStruct.UserInfo = !(dataObj->HasField("UserInfo")) ? nullptr : dataObj->GetObjectField("UserInfo");

    return tempStruct;
}

FServerRefreshGameServerInstanceHeartbeatResult UPlayFabServerModelDecoder::decodeRefreshGameServerInstanceHeartbeatResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerRefreshGameServerInstanceHeartbeatResult tempStruct;


    return tempStruct;
}

FServerRegisterGameResponse UPlayFabServerModelDecoder::decodeRegisterGameResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerRegisterGameResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.LobbyId = !(dataObj->HasField("LobbyId")) ? TEXT("") : dataObj->GetStringField("LobbyId");

    return tempStruct;
}

FServerSetGameServerInstanceDataResult UPlayFabServerModelDecoder::decodeSetGameServerInstanceDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerSetGameServerInstanceDataResult tempStruct;


    return tempStruct;
}

FServerSetGameServerInstanceStateResult UPlayFabServerModelDecoder::decodeSetGameServerInstanceStateResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerSetGameServerInstanceStateResult tempStruct;


    return tempStruct;
}

FServerSetGameServerInstanceTagsResult UPlayFabServerModelDecoder::decodeSetGameServerInstanceTagsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerSetGameServerInstanceTagsResult tempStruct;


    return tempStruct;
}



///////////////////////////////////////////////////////
// Platform Specific Methods
//////////////////////////////////////////////////////

FServerAwardSteamAchievementResult UPlayFabServerModelDecoder::decodeAwardSteamAchievementResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerAwardSteamAchievementResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.AchievementResults = !(dataObj->HasField("AchievementResults")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("AchievementResults");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Player Data Management
//////////////////////////////////////////////////////

FServerGetLeaderboardResult UPlayFabServerModelDecoder::decodeGetLeaderboardResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetLeaderboardResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Leaderboard = !(dataObj->HasField("Leaderboard")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Leaderboard");
    tempStruct.NextReset = !(dataObj->HasField("NextReset")) ? TEXT("") : dataObj->GetStringField("NextReset");
    tempStruct.Version = !(dataObj->HasField("Version")) ? 0 : int(dataObj->GetNumberField("Version"));

    return tempStruct;
}

FServerGetLeaderboardAroundUserResult UPlayFabServerModelDecoder::decodeGetLeaderboardAroundUserResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetLeaderboardAroundUserResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Leaderboard = !(dataObj->HasField("Leaderboard")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Leaderboard");
    tempStruct.NextReset = !(dataObj->HasField("NextReset")) ? TEXT("") : dataObj->GetStringField("NextReset");
    tempStruct.Version = !(dataObj->HasField("Version")) ? 0 : int(dataObj->GetNumberField("Version"));

    return tempStruct;
}

FServerGetPlayerCombinedInfoResult UPlayFabServerModelDecoder::decodeGetPlayerCombinedInfoResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetPlayerCombinedInfoResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.InfoResultPayload = !(dataObj->HasField("InfoResultPayload")) ? nullptr : dataObj->GetObjectField("InfoResultPayload");
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");

    return tempStruct;
}

FServerGetPlayerStatisticsResult UPlayFabServerModelDecoder::decodeGetPlayerStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetPlayerStatisticsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");
    tempStruct.Statistics = !(dataObj->HasField("Statistics")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Statistics");

    return tempStruct;
}

FServerGetPlayerStatisticVersionsResult UPlayFabServerModelDecoder::decodeGetPlayerStatisticVersionsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetPlayerStatisticVersionsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.StatisticVersions = !(dataObj->HasField("StatisticVersions")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("StatisticVersions");

    return tempStruct;
}

FServerGetUserDataResult UPlayFabServerModelDecoder::decodeGetUserDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetUserDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");
    tempStruct.DataVersion = !(dataObj->HasField("DataVersion")) ? 0 : int(dataObj->GetNumberField("DataVersion"));
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");

    return tempStruct;
}

FServerUpdatePlayerStatisticsResult UPlayFabServerModelDecoder::decodeUpdatePlayerStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerUpdatePlayerStatisticsResult tempStruct;


    return tempStruct;
}

FServerUpdateUserDataResult UPlayFabServerModelDecoder::decodeUpdateUserDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerUpdateUserDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.DataVersion = !(dataObj->HasField("DataVersion")) ? 0 : int(dataObj->GetNumberField("DataVersion"));

    return tempStruct;
}



///////////////////////////////////////////////////////
// Player Item Management
//////////////////////////////////////////////////////

FServerModifyCharacterVirtualCurrencyResult UPlayFabServerModelDecoder::decodeModifyCharacterVirtualCurrencyResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerModifyCharacterVirtualCurrencyResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Balance = !(dataObj->HasField("Balance")) ? 0 : int(dataObj->GetNumberField("Balance"));
    tempStruct.VirtualCurrency = !(dataObj->HasField("VirtualCurrency")) ? TEXT("") : dataObj->GetStringField("VirtualCurrency");

    return tempStruct;
}

FServerModifyUserVirtualCurrencyResult UPlayFabServerModelDecoder::decodeModifyUserVirtualCurrencyResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerModifyUserVirtualCurrencyResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Balance = !(dataObj->HasField("Balance")) ? 0 : int(dataObj->GetNumberField("Balance"));
    tempStruct.BalanceChange = !(dataObj->HasField("BalanceChange")) ? 0 : int(dataObj->GetNumberField("BalanceChange"));
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");
    tempStruct.VirtualCurrency = !(dataObj->HasField("VirtualCurrency")) ? TEXT("") : dataObj->GetStringField("VirtualCurrency");

    return tempStruct;
}

FServerConsumeItemResult UPlayFabServerModelDecoder::decodeConsumeItemResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerConsumeItemResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ItemInstanceId = !(dataObj->HasField("ItemInstanceId")) ? TEXT("") : dataObj->GetStringField("ItemInstanceId");
    tempStruct.RemainingUses = !(dataObj->HasField("RemainingUses")) ? 0 : int(dataObj->GetNumberField("RemainingUses"));

    return tempStruct;
}

FServerEvaluateRandomResultTableResult UPlayFabServerModelDecoder::decodeEvaluateRandomResultTableResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerEvaluateRandomResultTableResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ResultItemId = !(dataObj->HasField("ResultItemId")) ? TEXT("") : dataObj->GetStringField("ResultItemId");

    return tempStruct;
}

FServerGetCharacterInventoryResult UPlayFabServerModelDecoder::decodeGetCharacterInventoryResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetCharacterInventoryResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.CharacterId = !(dataObj->HasField("CharacterId")) ? TEXT("") : dataObj->GetStringField("CharacterId");
    tempStruct.Inventory = !(dataObj->HasField("Inventory")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Inventory");
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");
    tempStruct.VirtualCurrency = !(dataObj->HasField("VirtualCurrency")) ? nullptr : dataObj->GetObjectField("VirtualCurrency");
    tempStruct.VirtualCurrencyRechargeTimes = !(dataObj->HasField("VirtualCurrencyRechargeTimes")) ? nullptr : dataObj->GetObjectField("VirtualCurrencyRechargeTimes");

    return tempStruct;
}

FServerGetRandomResultTablesResult UPlayFabServerModelDecoder::decodeGetRandomResultTablesResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetRandomResultTablesResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Tables = !(dataObj->HasField("Tables")) ? nullptr : dataObj->GetObjectField("Tables");

    return tempStruct;
}

FServerGetUserInventoryResult UPlayFabServerModelDecoder::decodeGetUserInventoryResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetUserInventoryResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Inventory = !(dataObj->HasField("Inventory")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Inventory");
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");
    tempStruct.VirtualCurrency = !(dataObj->HasField("VirtualCurrency")) ? nullptr : dataObj->GetObjectField("VirtualCurrency");
    tempStruct.VirtualCurrencyRechargeTimes = !(dataObj->HasField("VirtualCurrencyRechargeTimes")) ? nullptr : dataObj->GetObjectField("VirtualCurrencyRechargeTimes");

    return tempStruct;
}

FServerGrantItemsToCharacterResult UPlayFabServerModelDecoder::decodeGrantItemsToCharacterResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGrantItemsToCharacterResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ItemGrantResults = !(dataObj->HasField("ItemGrantResults")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("ItemGrantResults");

    return tempStruct;
}

FServerGrantItemsToUserResult UPlayFabServerModelDecoder::decodeGrantItemsToUserResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGrantItemsToUserResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ItemGrantResults = !(dataObj->HasField("ItemGrantResults")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("ItemGrantResults");

    return tempStruct;
}

FServerGrantItemsToUsersResult UPlayFabServerModelDecoder::decodeGrantItemsToUsersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGrantItemsToUsersResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ItemGrantResults = !(dataObj->HasField("ItemGrantResults")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("ItemGrantResults");

    return tempStruct;
}

FServerModifyItemUsesResult UPlayFabServerModelDecoder::decodeModifyItemUsesResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerModifyItemUsesResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ItemInstanceId = !(dataObj->HasField("ItemInstanceId")) ? TEXT("") : dataObj->GetStringField("ItemInstanceId");
    tempStruct.RemainingUses = !(dataObj->HasField("RemainingUses")) ? 0 : int(dataObj->GetNumberField("RemainingUses"));

    return tempStruct;
}

FServerMoveItemToCharacterFromCharacterResult UPlayFabServerModelDecoder::decodeMoveItemToCharacterFromCharacterResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerMoveItemToCharacterFromCharacterResult tempStruct;


    return tempStruct;
}

FServerMoveItemToCharacterFromUserResult UPlayFabServerModelDecoder::decodeMoveItemToCharacterFromUserResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerMoveItemToCharacterFromUserResult tempStruct;


    return tempStruct;
}

FServerMoveItemToUserFromCharacterResult UPlayFabServerModelDecoder::decodeMoveItemToUserFromCharacterResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerMoveItemToUserFromCharacterResult tempStruct;


    return tempStruct;
}

FServerRedeemCouponResult UPlayFabServerModelDecoder::decodeRedeemCouponResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerRedeemCouponResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.GrantedItems = !(dataObj->HasField("GrantedItems")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("GrantedItems");

    return tempStruct;
}

FServerReportPlayerServerResult UPlayFabServerModelDecoder::decodeReportPlayerServerResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerReportPlayerServerResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.SubmissionsRemaining = !(dataObj->HasField("SubmissionsRemaining")) ? 0 : int(dataObj->GetNumberField("SubmissionsRemaining"));

    return tempStruct;
}

FServerRevokeInventoryResult UPlayFabServerModelDecoder::decodeRevokeInventoryResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerRevokeInventoryResult tempStruct;


    return tempStruct;
}

FServerRevokeInventoryItemsResult UPlayFabServerModelDecoder::decodeRevokeInventoryItemsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerRevokeInventoryItemsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Errors = !(dataObj->HasField("Errors")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Errors");

    return tempStruct;
}

FServerUnlockContainerItemResult UPlayFabServerModelDecoder::decodeUnlockContainerItemResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerUnlockContainerItemResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.GrantedItems = !(dataObj->HasField("GrantedItems")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("GrantedItems");
    tempStruct.UnlockedItemInstanceId = !(dataObj->HasField("UnlockedItemInstanceId")) ? TEXT("") : dataObj->GetStringField("UnlockedItemInstanceId");
    tempStruct.UnlockedWithItemInstanceId = !(dataObj->HasField("UnlockedWithItemInstanceId")) ? TEXT("") : dataObj->GetStringField("UnlockedWithItemInstanceId");
    tempStruct.VirtualCurrency = !(dataObj->HasField("VirtualCurrency")) ? nullptr : dataObj->GetObjectField("VirtualCurrency");

    return tempStruct;
}



///////////////////////////////////////////////////////
// PlayStream
//////////////////////////////////////////////////////

FServerAddPlayerTagResult UPlayFabServerModelDecoder::decodeAddPlayerTagResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerAddPlayerTagResult tempStruct;


    return tempStruct;
}

FServerGetAllSegmentsResult UPlayFabServerModelDecoder::decodeGetAllSegmentsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetAllSegmentsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Segments = !(dataObj->HasField("Segments")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Segments");

    return tempStruct;
}

FServerGetPlayerSegmentsResult UPlayFabServerModelDecoder::decodeGetPlayerSegmentsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetPlayerSegmentsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Segments = !(dataObj->HasField("Segments")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Segments");

    return tempStruct;
}

FServerGetPlayersInSegmentResult UPlayFabServerModelDecoder::decodeGetPlayersInSegmentResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetPlayersInSegmentResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ContinuationToken = !(dataObj->HasField("ContinuationToken")) ? TEXT("") : dataObj->GetStringField("ContinuationToken");
    tempStruct.PlayerProfiles = !(dataObj->HasField("PlayerProfiles")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("PlayerProfiles");
    tempStruct.ProfilesInSegment = !(dataObj->HasField("ProfilesInSegment")) ? 0 : int(dataObj->GetNumberField("ProfilesInSegment"));

    return tempStruct;
}

FServerGetPlayerTagsResult UPlayFabServerModelDecoder::decodeGetPlayerTagsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetPlayerTagsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");
    tempStruct.Tags = !(dataObj->HasField("Tags")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("Tags"), TEXT(","));

    return tempStruct;
}

FServerRemovePlayerTagResult UPlayFabServerModelDecoder::decodeRemovePlayerTagResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerRemovePlayerTagResult tempStruct;


    return tempStruct;
}



///////////////////////////////////////////////////////
// Server-Side Cloud Script
//////////////////////////////////////////////////////

FServerExecuteCloudScriptResult UPlayFabServerModelDecoder::decodeExecuteCloudScriptResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerExecuteCloudScriptResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.APIRequestsIssued = !(dataObj->HasField("APIRequestsIssued")) ? 0 : int(dataObj->GetNumberField("APIRequestsIssued"));
    tempStruct.Error = !(dataObj->HasField("Error")) ? nullptr : dataObj->GetObjectField("Error");
    tempStruct.ExecutionTimeSeconds = !(dataObj->HasField("ExecutionTimeSeconds")) ? 0 : int(dataObj->GetNumberField("ExecutionTimeSeconds"));
    tempStruct.FunctionName = !(dataObj->HasField("FunctionName")) ? TEXT("") : dataObj->GetStringField("FunctionName");
    tempStruct.FunctionResult = !(dataObj->HasField("FunctionResult")) ? nullptr : dataObj->GetObjectField("FunctionResult");
    tempStruct.FunctionResultTooLarge = !(dataObj->HasField("FunctionResultTooLarge")) ? false : dataObj->GetBoolField("FunctionResultTooLarge");
    tempStruct.HttpRequestsIssued = !(dataObj->HasField("HttpRequestsIssued")) ? 0 : int(dataObj->GetNumberField("HttpRequestsIssued"));
    tempStruct.Logs = !(dataObj->HasField("Logs")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Logs");
    tempStruct.LogsTooLarge = !(dataObj->HasField("LogsTooLarge")) ? false : dataObj->GetBoolField("LogsTooLarge");
    tempStruct.MemoryConsumedBytes = !(dataObj->HasField("MemoryConsumedBytes")) ? 0 : int(dataObj->GetNumberField("MemoryConsumedBytes"));
    tempStruct.ProcessorTimeSeconds = !(dataObj->HasField("ProcessorTimeSeconds")) ? 0 : int(dataObj->GetNumberField("ProcessorTimeSeconds"));
    tempStruct.Revision = !(dataObj->HasField("Revision")) ? 0 : int(dataObj->GetNumberField("Revision"));

    return tempStruct;
}



///////////////////////////////////////////////////////
// Shared Group Data
//////////////////////////////////////////////////////

FServerAddSharedGroupMembersResult UPlayFabServerModelDecoder::decodeAddSharedGroupMembersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerAddSharedGroupMembersResult tempStruct;


    return tempStruct;
}

FServerCreateSharedGroupResult UPlayFabServerModelDecoder::decodeCreateSharedGroupResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerCreateSharedGroupResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.SharedGroupId = !(dataObj->HasField("SharedGroupId")) ? TEXT("") : dataObj->GetStringField("SharedGroupId");

    return tempStruct;
}

FServerGetSharedGroupDataResult UPlayFabServerModelDecoder::decodeGetSharedGroupDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetSharedGroupDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");
    tempStruct.Members = !(dataObj->HasField("Members")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("Members"), TEXT(","));

    return tempStruct;
}

FServerRemoveSharedGroupMembersResult UPlayFabServerModelDecoder::decodeRemoveSharedGroupMembersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerRemoveSharedGroupMembersResult tempStruct;


    return tempStruct;
}

FServerUpdateSharedGroupDataResult UPlayFabServerModelDecoder::decodeUpdateSharedGroupDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerUpdateSharedGroupDataResult tempStruct;


    return tempStruct;
}



///////////////////////////////////////////////////////
// Title-Wide Data Management
//////////////////////////////////////////////////////

FServerGetCatalogItemsResult UPlayFabServerModelDecoder::decodeGetCatalogItemsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetCatalogItemsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Catalog = !(dataObj->HasField("Catalog")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Catalog");

    return tempStruct;
}

FServerGetPublisherDataResult UPlayFabServerModelDecoder::decodeGetPublisherDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetPublisherDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");

    return tempStruct;
}

FServerGetStoreItemsResult UPlayFabServerModelDecoder::decodeGetStoreItemsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetStoreItemsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.CatalogVersion = !(dataObj->HasField("CatalogVersion")) ? TEXT("") : dataObj->GetStringField("CatalogVersion");
    tempStruct.MarketingData = !(dataObj->HasField("MarketingData")) ? nullptr : dataObj->GetObjectField("MarketingData");
    GetEnumValueFromString<EPfSourceType>(TEXT("EPfSourceType"), dataObj->GetStringField("Source"), tempStruct.Source);
    tempStruct.Store = !(dataObj->HasField("Store")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Store");
    tempStruct.StoreId = !(dataObj->HasField("StoreId")) ? TEXT("") : dataObj->GetStringField("StoreId");

    return tempStruct;
}

FServerGetTimeResult UPlayFabServerModelDecoder::decodeGetTimeResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetTimeResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Time = !(dataObj->HasField("Time")) ? TEXT("") : dataObj->GetStringField("Time");

    return tempStruct;
}

FServerGetTitleDataResult UPlayFabServerModelDecoder::decodeGetTitleDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetTitleDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");

    return tempStruct;
}

FServerGetTitleNewsResult UPlayFabServerModelDecoder::decodeGetTitleNewsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerGetTitleNewsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.News = !(dataObj->HasField("News")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("News");

    return tempStruct;
}

FServerSetPublisherDataResult UPlayFabServerModelDecoder::decodeSetPublisherDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerSetPublisherDataResult tempStruct;


    return tempStruct;
}

FServerSetTitleDataResult UPlayFabServerModelDecoder::decodeSetTitleDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FServerSetTitleDataResult tempStruct;


    return tempStruct;
}


