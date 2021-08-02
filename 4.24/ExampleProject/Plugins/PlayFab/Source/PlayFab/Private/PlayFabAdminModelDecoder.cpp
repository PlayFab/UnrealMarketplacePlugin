//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the play fab models
//
// API: Admin
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabAdminModelDecoder.h"
#include "PlayFabPrivate.h"

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Admin API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////

FAdminBanUsersResult UPlayFabAdminModelDecoder::decodeBanUsersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminBanUsersResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.BanData = !(dataObj->HasField("BanData")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("BanData");

    return tempStruct;
}

FAdminDeleteMasterPlayerAccountResult UPlayFabAdminModelDecoder::decodeDeleteMasterPlayerAccountResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminDeleteMasterPlayerAccountResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.JobReceiptId = !(dataObj->HasField("JobReceiptId")) ? TEXT("") : dataObj->GetStringField("JobReceiptId");
    tempStruct.TitleIds = !(dataObj->HasField("TitleIds")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("TitleIds"), TEXT(","));

    return tempStruct;
}

FAdminDeletePlayerResult UPlayFabAdminModelDecoder::decodeDeletePlayerResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminDeletePlayerResult tempStruct;


    return tempStruct;
}

FAdminDeleteTitleResult UPlayFabAdminModelDecoder::decodeDeleteTitleResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminDeleteTitleResult tempStruct;


    return tempStruct;
}

FAdminExportMasterPlayerDataResult UPlayFabAdminModelDecoder::decodeExportMasterPlayerDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminExportMasterPlayerDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.JobReceiptId = !(dataObj->HasField("JobReceiptId")) ? TEXT("") : dataObj->GetStringField("JobReceiptId");

    return tempStruct;
}

FAdminGetPlayedTitleListResult UPlayFabAdminModelDecoder::decodeGetPlayedTitleListResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetPlayedTitleListResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.TitleIds = !(dataObj->HasField("TitleIds")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("TitleIds"), TEXT(","));

    return tempStruct;
}

FAdminGetPlayerIdFromAuthTokenResult UPlayFabAdminModelDecoder::decodeGetPlayerIdFromAuthTokenResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetPlayerIdFromAuthTokenResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");

    return tempStruct;
}

FAdminGetPlayerProfileResult UPlayFabAdminModelDecoder::decodeGetPlayerProfileResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetPlayerProfileResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.PlayerProfile = !(dataObj->HasField("PlayerProfile")) ? nullptr : dataObj->GetObjectField("PlayerProfile");

    return tempStruct;
}

FAdminLookupUserAccountInfoResult UPlayFabAdminModelDecoder::decodeLookupUserAccountInfoResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminLookupUserAccountInfoResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.UserInfo = !(dataObj->HasField("UserInfo")) ? nullptr : dataObj->GetObjectField("UserInfo");

    return tempStruct;
}

FAdminGetUserBansResult UPlayFabAdminModelDecoder::decodeGetUserBansResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetUserBansResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.BanData = !(dataObj->HasField("BanData")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("BanData");

    return tempStruct;
}

FAdminResetPasswordResult UPlayFabAdminModelDecoder::decodeResetPasswordResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminResetPasswordResult tempStruct;


    return tempStruct;
}

FAdminRevokeAllBansForUserResult UPlayFabAdminModelDecoder::decodeRevokeAllBansForUserResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminRevokeAllBansForUserResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.BanData = !(dataObj->HasField("BanData")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("BanData");

    return tempStruct;
}

FAdminRevokeBansResult UPlayFabAdminModelDecoder::decodeRevokeBansResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminRevokeBansResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.BanData = !(dataObj->HasField("BanData")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("BanData");

    return tempStruct;
}

FAdminSendAccountRecoveryEmailResult UPlayFabAdminModelDecoder::decodeSendAccountRecoveryEmailResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminSendAccountRecoveryEmailResult tempStruct;


    return tempStruct;
}

FAdminUpdateBansResult UPlayFabAdminModelDecoder::decodeUpdateBansResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminUpdateBansResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.BanData = !(dataObj->HasField("BanData")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("BanData");

    return tempStruct;
}

FAdminUpdateUserTitleDisplayNameResult UPlayFabAdminModelDecoder::decodeUpdateUserTitleDisplayNameResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminUpdateUserTitleDisplayNameResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.DisplayName = !(dataObj->HasField("DisplayName")) ? TEXT("") : dataObj->GetStringField("DisplayName");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Authentication
//////////////////////////////////////////////////////

FAdminEmptyResponse UPlayFabAdminModelDecoder::decodeEmptyResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminEmptyResponse tempStruct;


    return tempStruct;
}

FAdminCreatePlayerSharedSecretResult UPlayFabAdminModelDecoder::decodeCreatePlayerSharedSecretResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminCreatePlayerSharedSecretResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.SecretKey = !(dataObj->HasField("SecretKey")) ? TEXT("") : dataObj->GetStringField("SecretKey");

    return tempStruct;
}

FAdminDeletePlayerSharedSecretResult UPlayFabAdminModelDecoder::decodeDeletePlayerSharedSecretResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminDeletePlayerSharedSecretResult tempStruct;


    return tempStruct;
}

FAdminGetPlayerSharedSecretsResult UPlayFabAdminModelDecoder::decodeGetPlayerSharedSecretsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetPlayerSharedSecretsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.SharedSecrets = !(dataObj->HasField("SharedSecrets")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("SharedSecrets");

    return tempStruct;
}

FAdminGetPolicyResponse UPlayFabAdminModelDecoder::decodeGetPolicyResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetPolicyResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.PolicyName = !(dataObj->HasField("PolicyName")) ? TEXT("") : dataObj->GetStringField("PolicyName");
    tempStruct.PolicyVersion = !(dataObj->HasField("PolicyVersion")) ? 0 : int(dataObj->GetNumberField("PolicyVersion"));
    tempStruct.Statements = !(dataObj->HasField("Statements")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Statements");

    return tempStruct;
}

FAdminListOpenIdConnectionResponse UPlayFabAdminModelDecoder::decodeListOpenIdConnectionResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminListOpenIdConnectionResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Connections = !(dataObj->HasField("Connections")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Connections");

    return tempStruct;
}

FAdminSetPlayerSecretResult UPlayFabAdminModelDecoder::decodeSetPlayerSecretResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminSetPlayerSecretResult tempStruct;


    return tempStruct;
}

FAdminUpdatePlayerSharedSecretResult UPlayFabAdminModelDecoder::decodeUpdatePlayerSharedSecretResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminUpdatePlayerSharedSecretResult tempStruct;


    return tempStruct;
}

FAdminUpdatePolicyResponse UPlayFabAdminModelDecoder::decodeUpdatePolicyResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminUpdatePolicyResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.PolicyName = !(dataObj->HasField("PolicyName")) ? TEXT("") : dataObj->GetStringField("PolicyName");
    tempStruct.Statements = !(dataObj->HasField("Statements")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Statements");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Characters
//////////////////////////////////////////////////////

FAdminResetCharacterStatisticsResult UPlayFabAdminModelDecoder::decodeResetCharacterStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminResetCharacterStatisticsResult tempStruct;


    return tempStruct;
}



///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////

FAdminBlankResult UPlayFabAdminModelDecoder::decodeBlankResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminBlankResult tempStruct;


    return tempStruct;
}

FAdminGetContentListResult UPlayFabAdminModelDecoder::decodeGetContentListResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetContentListResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Contents = !(dataObj->HasField("Contents")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Contents");
    tempStruct.ItemCount = !(dataObj->HasField("ItemCount")) ? 0 : int(dataObj->GetNumberField("ItemCount"));
    tempStruct.TotalSize = !(dataObj->HasField("TotalSize")) ? 0 : int(dataObj->GetNumberField("TotalSize"));

    return tempStruct;
}

FAdminGetContentUploadUrlResult UPlayFabAdminModelDecoder::decodeGetContentUploadUrlResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetContentUploadUrlResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.URL = !(dataObj->HasField("URL")) ? TEXT("") : dataObj->GetStringField("URL");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Custom Server Management
//////////////////////////////////////////////////////

FAdminAddServerBuildResult UPlayFabAdminModelDecoder::decodeAddServerBuildResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminAddServerBuildResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ActiveRegions = !(dataObj->HasField("ActiveRegions")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("ActiveRegions"), TEXT(","));
    tempStruct.BuildId = !(dataObj->HasField("BuildId")) ? TEXT("") : dataObj->GetStringField("BuildId");
    tempStruct.CommandLineTemplate = !(dataObj->HasField("CommandLineTemplate")) ? TEXT("") : dataObj->GetStringField("CommandLineTemplate");
    tempStruct.Comment = !(dataObj->HasField("Comment")) ? TEXT("") : dataObj->GetStringField("Comment");
    tempStruct.ExecutablePath = !(dataObj->HasField("ExecutablePath")) ? TEXT("") : dataObj->GetStringField("ExecutablePath");
    tempStruct.MaxGamesPerHost = !(dataObj->HasField("MaxGamesPerHost")) ? 0 : int(dataObj->GetNumberField("MaxGamesPerHost"));
    tempStruct.MinFreeGameSlots = !(dataObj->HasField("MinFreeGameSlots")) ? 0 : int(dataObj->GetNumberField("MinFreeGameSlots"));
    GetEnumValueFromString<EGameBuildStatus>(TEXT("EGameBuildStatus"), dataObj->GetStringField("Status"), tempStruct.Status);
    tempStruct.Timestamp = !(dataObj->HasField("Timestamp")) ? TEXT("") : dataObj->GetStringField("Timestamp");
    tempStruct.TitleId = !(dataObj->HasField("TitleId")) ? TEXT("") : dataObj->GetStringField("TitleId");

    return tempStruct;
}

FAdminGetServerBuildInfoResult UPlayFabAdminModelDecoder::decodeGetServerBuildInfoResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetServerBuildInfoResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ActiveRegions = !(dataObj->HasField("ActiveRegions")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("ActiveRegions"), TEXT(","));
    tempStruct.BuildId = !(dataObj->HasField("BuildId")) ? TEXT("") : dataObj->GetStringField("BuildId");
    tempStruct.Comment = !(dataObj->HasField("Comment")) ? TEXT("") : dataObj->GetStringField("Comment");
    tempStruct.ErrorMessage = !(dataObj->HasField("ErrorMessage")) ? TEXT("") : dataObj->GetStringField("ErrorMessage");
    tempStruct.MaxGamesPerHost = !(dataObj->HasField("MaxGamesPerHost")) ? 0 : int(dataObj->GetNumberField("MaxGamesPerHost"));
    tempStruct.MinFreeGameSlots = !(dataObj->HasField("MinFreeGameSlots")) ? 0 : int(dataObj->GetNumberField("MinFreeGameSlots"));
    GetEnumValueFromString<EGameBuildStatus>(TEXT("EGameBuildStatus"), dataObj->GetStringField("Status"), tempStruct.Status);
    tempStruct.Timestamp = !(dataObj->HasField("Timestamp")) ? TEXT("") : dataObj->GetStringField("Timestamp");
    tempStruct.TitleId = !(dataObj->HasField("TitleId")) ? TEXT("") : dataObj->GetStringField("TitleId");

    return tempStruct;
}

FAdminGetServerBuildUploadURLResult UPlayFabAdminModelDecoder::decodeGetServerBuildUploadURLResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetServerBuildUploadURLResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.URL = !(dataObj->HasField("URL")) ? TEXT("") : dataObj->GetStringField("URL");

    return tempStruct;
}

FAdminListBuildsResult UPlayFabAdminModelDecoder::decodeListBuildsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminListBuildsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Builds = !(dataObj->HasField("Builds")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Builds");

    return tempStruct;
}

FAdminModifyServerBuildResult UPlayFabAdminModelDecoder::decodeModifyServerBuildResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminModifyServerBuildResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ActiveRegions = !(dataObj->HasField("ActiveRegions")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("ActiveRegions"), TEXT(","));
    tempStruct.BuildId = !(dataObj->HasField("BuildId")) ? TEXT("") : dataObj->GetStringField("BuildId");
    tempStruct.CommandLineTemplate = !(dataObj->HasField("CommandLineTemplate")) ? TEXT("") : dataObj->GetStringField("CommandLineTemplate");
    tempStruct.Comment = !(dataObj->HasField("Comment")) ? TEXT("") : dataObj->GetStringField("Comment");
    tempStruct.ExecutablePath = !(dataObj->HasField("ExecutablePath")) ? TEXT("") : dataObj->GetStringField("ExecutablePath");
    tempStruct.MaxGamesPerHost = !(dataObj->HasField("MaxGamesPerHost")) ? 0 : int(dataObj->GetNumberField("MaxGamesPerHost"));
    tempStruct.MinFreeGameSlots = !(dataObj->HasField("MinFreeGameSlots")) ? 0 : int(dataObj->GetNumberField("MinFreeGameSlots"));
    GetEnumValueFromString<EGameBuildStatus>(TEXT("EGameBuildStatus"), dataObj->GetStringField("Status"), tempStruct.Status);
    tempStruct.Timestamp = !(dataObj->HasField("Timestamp")) ? TEXT("") : dataObj->GetStringField("Timestamp");
    tempStruct.TitleId = !(dataObj->HasField("TitleId")) ? TEXT("") : dataObj->GetStringField("TitleId");

    return tempStruct;
}

FAdminRemoveServerBuildResult UPlayFabAdminModelDecoder::decodeRemoveServerBuildResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminRemoveServerBuildResult tempStruct;


    return tempStruct;
}



///////////////////////////////////////////////////////
// Matchmaking
//////////////////////////////////////////////////////

FAdminGetMatchmakerGameInfoResult UPlayFabAdminModelDecoder::decodeGetMatchmakerGameInfoResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetMatchmakerGameInfoResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.BuildVersion = !(dataObj->HasField("BuildVersion")) ? TEXT("") : dataObj->GetStringField("BuildVersion");
    tempStruct.EndTime = !(dataObj->HasField("EndTime")) ? TEXT("") : dataObj->GetStringField("EndTime");
    tempStruct.LobbyId = !(dataObj->HasField("LobbyId")) ? TEXT("") : dataObj->GetStringField("LobbyId");
    tempStruct.Mode = !(dataObj->HasField("Mode")) ? TEXT("") : dataObj->GetStringField("Mode");
    tempStruct.Players = !(dataObj->HasField("Players")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("Players"), TEXT(","));
    GetEnumValueFromString<ERegion>(TEXT("ERegion"), dataObj->GetStringField("Region"), tempStruct.Region);
    tempStruct.ServerIPV4Address = !(dataObj->HasField("ServerIPV4Address")) ? TEXT("") : dataObj->GetStringField("ServerIPV4Address");
    tempStruct.ServerIPV6Address = !(dataObj->HasField("ServerIPV6Address")) ? TEXT("") : dataObj->GetStringField("ServerIPV6Address");
    tempStruct.ServerPort = !(dataObj->HasField("ServerPort")) ? 0 : int(dataObj->GetNumberField("ServerPort"));
    tempStruct.ServerPublicDNSName = !(dataObj->HasField("ServerPublicDNSName")) ? TEXT("") : dataObj->GetStringField("ServerPublicDNSName");
    tempStruct.StartTime = !(dataObj->HasField("StartTime")) ? TEXT("") : dataObj->GetStringField("StartTime");
    tempStruct.TitleId = !(dataObj->HasField("TitleId")) ? TEXT("") : dataObj->GetStringField("TitleId");

    return tempStruct;
}

FAdminGetMatchmakerGameModesResult UPlayFabAdminModelDecoder::decodeGetMatchmakerGameModesResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetMatchmakerGameModesResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.GameModes = !(dataObj->HasField("GameModes")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("GameModes");

    return tempStruct;
}

FAdminModifyMatchmakerGameModesResult UPlayFabAdminModelDecoder::decodeModifyMatchmakerGameModesResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminModifyMatchmakerGameModesResult tempStruct;


    return tempStruct;
}



///////////////////////////////////////////////////////
// Player Data Management
//////////////////////////////////////////////////////

FAdminCreatePlayerStatisticDefinitionResult UPlayFabAdminModelDecoder::decodeCreatePlayerStatisticDefinitionResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminCreatePlayerStatisticDefinitionResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Statistic = !(dataObj->HasField("Statistic")) ? nullptr : dataObj->GetObjectField("Statistic");

    return tempStruct;
}

FAdminGetDataReportResult UPlayFabAdminModelDecoder::decodeGetDataReportResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetDataReportResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.DownloadUrl = !(dataObj->HasField("DownloadUrl")) ? TEXT("") : dataObj->GetStringField("DownloadUrl");

    return tempStruct;
}

FAdminGetPlayerStatisticDefinitionsResult UPlayFabAdminModelDecoder::decodeGetPlayerStatisticDefinitionsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetPlayerStatisticDefinitionsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Statistics = !(dataObj->HasField("Statistics")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Statistics");

    return tempStruct;
}

FAdminGetPlayerStatisticVersionsResult UPlayFabAdminModelDecoder::decodeGetPlayerStatisticVersionsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetPlayerStatisticVersionsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.StatisticVersions = !(dataObj->HasField("StatisticVersions")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("StatisticVersions");

    return tempStruct;
}

FAdminGetUserDataResult UPlayFabAdminModelDecoder::decodeGetUserDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetUserDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");
    tempStruct.DataVersion = !(dataObj->HasField("DataVersion")) ? 0 : int(dataObj->GetNumberField("DataVersion"));
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");

    return tempStruct;
}

FAdminIncrementPlayerStatisticVersionResult UPlayFabAdminModelDecoder::decodeIncrementPlayerStatisticVersionResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminIncrementPlayerStatisticVersionResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.StatisticVersion = !(dataObj->HasField("StatisticVersion")) ? nullptr : dataObj->GetObjectField("StatisticVersion");

    return tempStruct;
}

FAdminRefundPurchaseResponse UPlayFabAdminModelDecoder::decodeRefundPurchaseResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminRefundPurchaseResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.PurchaseStatus = !(dataObj->HasField("PurchaseStatus")) ? TEXT("") : dataObj->GetStringField("PurchaseStatus");

    return tempStruct;
}

FAdminResetUserStatisticsResult UPlayFabAdminModelDecoder::decodeResetUserStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminResetUserStatisticsResult tempStruct;


    return tempStruct;
}

FAdminResolvePurchaseDisputeResponse UPlayFabAdminModelDecoder::decodeResolvePurchaseDisputeResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminResolvePurchaseDisputeResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.PurchaseStatus = !(dataObj->HasField("PurchaseStatus")) ? TEXT("") : dataObj->GetStringField("PurchaseStatus");

    return tempStruct;
}

FAdminUpdatePlayerStatisticDefinitionResult UPlayFabAdminModelDecoder::decodeUpdatePlayerStatisticDefinitionResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminUpdatePlayerStatisticDefinitionResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Statistic = !(dataObj->HasField("Statistic")) ? nullptr : dataObj->GetObjectField("Statistic");

    return tempStruct;
}

FAdminUpdateUserDataResult UPlayFabAdminModelDecoder::decodeUpdateUserDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminUpdateUserDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.DataVersion = !(dataObj->HasField("DataVersion")) ? 0 : int(dataObj->GetNumberField("DataVersion"));

    return tempStruct;
}



///////////////////////////////////////////////////////
// Player Item Management
//////////////////////////////////////////////////////

FAdminModifyUserVirtualCurrencyResult UPlayFabAdminModelDecoder::decodeModifyUserVirtualCurrencyResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminModifyUserVirtualCurrencyResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Balance = !(dataObj->HasField("Balance")) ? 0 : int(dataObj->GetNumberField("Balance"));
    tempStruct.BalanceChange = !(dataObj->HasField("BalanceChange")) ? 0 : int(dataObj->GetNumberField("BalanceChange"));
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");
    tempStruct.VirtualCurrency = !(dataObj->HasField("VirtualCurrency")) ? TEXT("") : dataObj->GetStringField("VirtualCurrency");

    return tempStruct;
}

FAdminCheckLimitedEditionItemAvailabilityResult UPlayFabAdminModelDecoder::decodeCheckLimitedEditionItemAvailabilityResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminCheckLimitedEditionItemAvailabilityResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Amount = !(dataObj->HasField("Amount")) ? 0 : int(dataObj->GetNumberField("Amount"));

    return tempStruct;
}

FAdminGetUserInventoryResult UPlayFabAdminModelDecoder::decodeGetUserInventoryResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetUserInventoryResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Inventory = !(dataObj->HasField("Inventory")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Inventory");
    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");
    tempStruct.VirtualCurrency = !(dataObj->HasField("VirtualCurrency")) ? nullptr : dataObj->GetObjectField("VirtualCurrency");
    tempStruct.VirtualCurrencyRechargeTimes = !(dataObj->HasField("VirtualCurrencyRechargeTimes")) ? nullptr : dataObj->GetObjectField("VirtualCurrencyRechargeTimes");

    return tempStruct;
}

FAdminGrantItemsToUsersResult UPlayFabAdminModelDecoder::decodeGrantItemsToUsersResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGrantItemsToUsersResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ItemGrantResults = !(dataObj->HasField("ItemGrantResults")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("ItemGrantResults");

    return tempStruct;
}

FAdminIncrementLimitedEditionItemAvailabilityResult UPlayFabAdminModelDecoder::decodeIncrementLimitedEditionItemAvailabilityResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminIncrementLimitedEditionItemAvailabilityResult tempStruct;


    return tempStruct;
}

FAdminRevokeInventoryResult UPlayFabAdminModelDecoder::decodeRevokeInventoryResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminRevokeInventoryResult tempStruct;


    return tempStruct;
}

FAdminRevokeInventoryItemsResult UPlayFabAdminModelDecoder::decodeRevokeInventoryItemsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminRevokeInventoryItemsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Errors = !(dataObj->HasField("Errors")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Errors");

    return tempStruct;
}



///////////////////////////////////////////////////////
// PlayStream
//////////////////////////////////////////////////////

FAdminAddPlayerTagResult UPlayFabAdminModelDecoder::decodeAddPlayerTagResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminAddPlayerTagResult tempStruct;


    return tempStruct;
}

FAdminGetAllSegmentsResult UPlayFabAdminModelDecoder::decodeGetAllSegmentsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetAllSegmentsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Segments = !(dataObj->HasField("Segments")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Segments");

    return tempStruct;
}

FAdminGetPlayerSegmentsResult UPlayFabAdminModelDecoder::decodeGetPlayerSegmentsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetPlayerSegmentsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Segments = !(dataObj->HasField("Segments")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Segments");

    return tempStruct;
}

FAdminGetPlayersInSegmentResult UPlayFabAdminModelDecoder::decodeGetPlayersInSegmentResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetPlayersInSegmentResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ContinuationToken = !(dataObj->HasField("ContinuationToken")) ? TEXT("") : dataObj->GetStringField("ContinuationToken");
    tempStruct.PlayerProfiles = !(dataObj->HasField("PlayerProfiles")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("PlayerProfiles");
    tempStruct.ProfilesInSegment = !(dataObj->HasField("ProfilesInSegment")) ? 0 : int(dataObj->GetNumberField("ProfilesInSegment"));

    return tempStruct;
}

FAdminGetPlayerTagsResult UPlayFabAdminModelDecoder::decodeGetPlayerTagsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetPlayerTagsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.PlayFabId = !(dataObj->HasField("PlayFabId")) ? TEXT("") : dataObj->GetStringField("PlayFabId");
    tempStruct.Tags = !(dataObj->HasField("Tags")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("Tags"), TEXT(","));

    return tempStruct;
}

FAdminRemovePlayerTagResult UPlayFabAdminModelDecoder::decodeRemovePlayerTagResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminRemovePlayerTagResult tempStruct;


    return tempStruct;
}



///////////////////////////////////////////////////////
// ScheduledTask
//////////////////////////////////////////////////////

FAdminCreateTaskResult UPlayFabAdminModelDecoder::decodeCreateTaskResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminCreateTaskResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.TaskId = !(dataObj->HasField("TaskId")) ? TEXT("") : dataObj->GetStringField("TaskId");

    return tempStruct;
}

FAdminGetActionsOnPlayersInSegmentTaskInstanceResult UPlayFabAdminModelDecoder::decodeGetActionsOnPlayersInSegmentTaskInstanceResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetActionsOnPlayersInSegmentTaskInstanceResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Parameter = !(dataObj->HasField("Parameter")) ? nullptr : dataObj->GetObjectField("Parameter");
    tempStruct.Summary = !(dataObj->HasField("Summary")) ? nullptr : dataObj->GetObjectField("Summary");

    return tempStruct;
}

FAdminGetCloudScriptTaskInstanceResult UPlayFabAdminModelDecoder::decodeGetCloudScriptTaskInstanceResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetCloudScriptTaskInstanceResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Parameter = !(dataObj->HasField("Parameter")) ? nullptr : dataObj->GetObjectField("Parameter");
    tempStruct.Summary = !(dataObj->HasField("Summary")) ? nullptr : dataObj->GetObjectField("Summary");

    return tempStruct;
}

FAdminGetTaskInstancesResult UPlayFabAdminModelDecoder::decodeGetTaskInstancesResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetTaskInstancesResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Summaries = !(dataObj->HasField("Summaries")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Summaries");

    return tempStruct;
}

FAdminGetTasksResult UPlayFabAdminModelDecoder::decodeGetTasksResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetTasksResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Tasks = !(dataObj->HasField("Tasks")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Tasks");

    return tempStruct;
}

FAdminRunTaskResult UPlayFabAdminModelDecoder::decodeRunTaskResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminRunTaskResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.TaskInstanceId = !(dataObj->HasField("TaskInstanceId")) ? TEXT("") : dataObj->GetStringField("TaskInstanceId");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Segments
//////////////////////////////////////////////////////

FAdminCreateSegmentResponse UPlayFabAdminModelDecoder::decodeCreateSegmentResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminCreateSegmentResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ErrorMessage = !(dataObj->HasField("ErrorMessage")) ? TEXT("") : dataObj->GetStringField("ErrorMessage");
    tempStruct.SegmentId = !(dataObj->HasField("SegmentId")) ? TEXT("") : dataObj->GetStringField("SegmentId");

    return tempStruct;
}

FAdminDeleteSegmentsResponse UPlayFabAdminModelDecoder::decodeDeleteSegmentsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminDeleteSegmentsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ErrorMessage = !(dataObj->HasField("ErrorMessage")) ? TEXT("") : dataObj->GetStringField("ErrorMessage");

    return tempStruct;
}

FAdminGetSegmentsResponse UPlayFabAdminModelDecoder::decodeGetSegmentsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetSegmentsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ErrorMessage = !(dataObj->HasField("ErrorMessage")) ? TEXT("") : dataObj->GetStringField("ErrorMessage");
    tempStruct.Segments = !(dataObj->HasField("Segments")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Segments");

    return tempStruct;
}

FAdminUpdateSegmentResponse UPlayFabAdminModelDecoder::decodeUpdateSegmentResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminUpdateSegmentResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ErrorMessage = !(dataObj->HasField("ErrorMessage")) ? TEXT("") : dataObj->GetStringField("ErrorMessage");
    tempStruct.SegmentId = !(dataObj->HasField("SegmentId")) ? TEXT("") : dataObj->GetStringField("SegmentId");

    return tempStruct;
}



///////////////////////////////////////////////////////
// Server-Side Cloud Script
//////////////////////////////////////////////////////

FAdminGetCloudScriptRevisionResult UPlayFabAdminModelDecoder::decodeGetCloudScriptRevisionResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetCloudScriptRevisionResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.CreatedAt = !(dataObj->HasField("CreatedAt")) ? TEXT("") : dataObj->GetStringField("CreatedAt");
    tempStruct.Files = !(dataObj->HasField("Files")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Files");
    tempStruct.IsPublished = !(dataObj->HasField("IsPublished")) ? false : dataObj->GetBoolField("IsPublished");
    tempStruct.Revision = !(dataObj->HasField("Revision")) ? 0 : int(dataObj->GetNumberField("Revision"));
    tempStruct.Version = !(dataObj->HasField("Version")) ? 0 : int(dataObj->GetNumberField("Version"));

    return tempStruct;
}

FAdminGetCloudScriptVersionsResult UPlayFabAdminModelDecoder::decodeGetCloudScriptVersionsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetCloudScriptVersionsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Versions = !(dataObj->HasField("Versions")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Versions");

    return tempStruct;
}

FAdminSetPublishedRevisionResult UPlayFabAdminModelDecoder::decodeSetPublishedRevisionResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminSetPublishedRevisionResult tempStruct;


    return tempStruct;
}

FAdminUpdateCloudScriptResult UPlayFabAdminModelDecoder::decodeUpdateCloudScriptResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminUpdateCloudScriptResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Revision = !(dataObj->HasField("Revision")) ? 0 : int(dataObj->GetNumberField("Revision"));
    tempStruct.Version = !(dataObj->HasField("Version")) ? 0 : int(dataObj->GetNumberField("Version"));

    return tempStruct;
}



///////////////////////////////////////////////////////
// Shared Group Data
//////////////////////////////////////////////////////

FAdminSetPublisherDataResult UPlayFabAdminModelDecoder::decodeSetPublisherDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminSetPublisherDataResult tempStruct;


    return tempStruct;
}



///////////////////////////////////////////////////////
// Title-Wide Data Management
//////////////////////////////////////////////////////

FAdminAddLocalizedNewsResult UPlayFabAdminModelDecoder::decodeAddLocalizedNewsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminAddLocalizedNewsResult tempStruct;


    return tempStruct;
}

FAdminAddNewsResult UPlayFabAdminModelDecoder::decodeAddNewsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminAddNewsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.NewsId = !(dataObj->HasField("NewsId")) ? TEXT("") : dataObj->GetStringField("NewsId");

    return tempStruct;
}

FAdminDeleteStoreResult UPlayFabAdminModelDecoder::decodeDeleteStoreResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminDeleteStoreResult tempStruct;


    return tempStruct;
}

FAdminDeleteTitleDataOverrideResult UPlayFabAdminModelDecoder::decodeDeleteTitleDataOverrideResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminDeleteTitleDataOverrideResult tempStruct;


    return tempStruct;
}

FAdminGetCatalogItemsResult UPlayFabAdminModelDecoder::decodeGetCatalogItemsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetCatalogItemsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Catalog = !(dataObj->HasField("Catalog")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Catalog");

    return tempStruct;
}

FAdminGetPublisherDataResult UPlayFabAdminModelDecoder::decodeGetPublisherDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetPublisherDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");

    return tempStruct;
}

FAdminGetRandomResultTablesResult UPlayFabAdminModelDecoder::decodeGetRandomResultTablesResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetRandomResultTablesResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Tables = !(dataObj->HasField("Tables")) ? nullptr : dataObj->GetObjectField("Tables");

    return tempStruct;
}

FAdminGetStoreItemsResult UPlayFabAdminModelDecoder::decodeGetStoreItemsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetStoreItemsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.CatalogVersion = !(dataObj->HasField("CatalogVersion")) ? TEXT("") : dataObj->GetStringField("CatalogVersion");
    tempStruct.MarketingData = !(dataObj->HasField("MarketingData")) ? nullptr : dataObj->GetObjectField("MarketingData");
    GetEnumValueFromString<EPfSourceType>(TEXT("EPfSourceType"), dataObj->GetStringField("Source"), tempStruct.Source);
    tempStruct.Store = !(dataObj->HasField("Store")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Store");
    tempStruct.StoreId = !(dataObj->HasField("StoreId")) ? TEXT("") : dataObj->GetStringField("StoreId");

    return tempStruct;
}

FAdminGetTitleDataResult UPlayFabAdminModelDecoder::decodeGetTitleDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminGetTitleDataResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Data = !(dataObj->HasField("Data")) ? nullptr : dataObj->GetObjectField("Data");

    return tempStruct;
}

FAdminListVirtualCurrencyTypesResult UPlayFabAdminModelDecoder::decodeListVirtualCurrencyTypesResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminListVirtualCurrencyTypesResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.VirtualCurrencies = !(dataObj->HasField("VirtualCurrencies")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("VirtualCurrencies");

    return tempStruct;
}

FAdminUpdateCatalogItemsResult UPlayFabAdminModelDecoder::decodeUpdateCatalogItemsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminUpdateCatalogItemsResult tempStruct;


    return tempStruct;
}

FAdminUpdateStoreItemsResult UPlayFabAdminModelDecoder::decodeUpdateStoreItemsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminUpdateStoreItemsResult tempStruct;


    return tempStruct;
}

FAdminSetTitleDataResult UPlayFabAdminModelDecoder::decodeSetTitleDataResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminSetTitleDataResult tempStruct;


    return tempStruct;
}

FAdminSetTitleDataAndOverridesResult UPlayFabAdminModelDecoder::decodeSetTitleDataAndOverridesResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminSetTitleDataAndOverridesResult tempStruct;


    return tempStruct;
}

FAdminSetupPushNotificationResult UPlayFabAdminModelDecoder::decodeSetupPushNotificationResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminSetupPushNotificationResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ARN = !(dataObj->HasField("ARN")) ? TEXT("") : dataObj->GetStringField("ARN");

    return tempStruct;
}

FAdminUpdateRandomResultTablesResult UPlayFabAdminModelDecoder::decodeUpdateRandomResultTablesResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FAdminUpdateRandomResultTablesResult tempStruct;


    return tempStruct;
}


