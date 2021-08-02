//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the play fab models
//
// API: Multiplayer
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabMultiplayerModelDecoder.h"
#include "PlayFabPrivate.h"

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Multiplayer API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Matchmaking
//////////////////////////////////////////////////////

FMultiplayerCancelAllMatchmakingTicketsForPlayerResult UPlayFabMultiplayerModelDecoder::decodeCancelAllMatchmakingTicketsForPlayerResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerCancelAllMatchmakingTicketsForPlayerResult tempStruct;


    return tempStruct;
}

FMultiplayerCancelAllServerBackfillTicketsForPlayerResult UPlayFabMultiplayerModelDecoder::decodeCancelAllServerBackfillTicketsForPlayerResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerCancelAllServerBackfillTicketsForPlayerResult tempStruct;


    return tempStruct;
}

FMultiplayerCancelMatchmakingTicketResult UPlayFabMultiplayerModelDecoder::decodeCancelMatchmakingTicketResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerCancelMatchmakingTicketResult tempStruct;


    return tempStruct;
}

FMultiplayerCancelServerBackfillTicketResult UPlayFabMultiplayerModelDecoder::decodeCancelServerBackfillTicketResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerCancelServerBackfillTicketResult tempStruct;


    return tempStruct;
}

FMultiplayerCreateMatchmakingTicketResult UPlayFabMultiplayerModelDecoder::decodeCreateMatchmakingTicketResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerCreateMatchmakingTicketResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.TicketId = !(dataObj->HasField("TicketId")) ? TEXT("") : dataObj->GetStringField("TicketId");

    return tempStruct;
}

FMultiplayerCreateServerBackfillTicketResult UPlayFabMultiplayerModelDecoder::decodeCreateServerBackfillTicketResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerCreateServerBackfillTicketResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.TicketId = !(dataObj->HasField("TicketId")) ? TEXT("") : dataObj->GetStringField("TicketId");

    return tempStruct;
}

FMultiplayerGetMatchResult UPlayFabMultiplayerModelDecoder::decodeGetMatchResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerGetMatchResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.MatchId = !(dataObj->HasField("MatchId")) ? TEXT("") : dataObj->GetStringField("MatchId");
    tempStruct.Members = !(dataObj->HasField("Members")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Members");
    tempStruct.RegionPreferences = !(dataObj->HasField("RegionPreferences")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("RegionPreferences"), TEXT(","));
    tempStruct.ServerDetails = !(dataObj->HasField("ServerDetails")) ? nullptr : dataObj->GetObjectField("ServerDetails");

    return tempStruct;
}

FMultiplayerGetMatchmakingTicketResult UPlayFabMultiplayerModelDecoder::decodeGetMatchmakingTicketResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerGetMatchmakingTicketResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.CancellationReasonString = !(dataObj->HasField("CancellationReasonString")) ? TEXT("") : dataObj->GetStringField("CancellationReasonString");
    tempStruct.Created = !(dataObj->HasField("Created")) ? TEXT("") : dataObj->GetStringField("Created");
    tempStruct.Creator = !(dataObj->HasField("Creator")) ? nullptr : dataObj->GetObjectField("Creator");
    tempStruct.GiveUpAfterSeconds = !(dataObj->HasField("GiveUpAfterSeconds")) ? 0 : int(dataObj->GetNumberField("GiveUpAfterSeconds"));
    tempStruct.MatchId = !(dataObj->HasField("MatchId")) ? TEXT("") : dataObj->GetStringField("MatchId");
    tempStruct.Members = !(dataObj->HasField("Members")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Members");
    tempStruct.MembersToMatchWith = !(dataObj->HasField("MembersToMatchWith")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("MembersToMatchWith");
    tempStruct.QueueName = !(dataObj->HasField("QueueName")) ? TEXT("") : dataObj->GetStringField("QueueName");
    tempStruct.Status = !(dataObj->HasField("Status")) ? TEXT("") : dataObj->GetStringField("Status");
    tempStruct.TicketId = !(dataObj->HasField("TicketId")) ? TEXT("") : dataObj->GetStringField("TicketId");

    return tempStruct;
}

FMultiplayerGetQueueStatisticsResult UPlayFabMultiplayerModelDecoder::decodeGetQueueStatisticsResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerGetQueueStatisticsResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.NumberOfPlayersMatching = !(dataObj->HasField("NumberOfPlayersMatching")) ? 0 : int(dataObj->GetNumberField("NumberOfPlayersMatching"));
    tempStruct.TimeToMatchStatisticsInSeconds = !(dataObj->HasField("TimeToMatchStatisticsInSeconds")) ? nullptr : dataObj->GetObjectField("TimeToMatchStatisticsInSeconds");

    return tempStruct;
}

FMultiplayerGetServerBackfillTicketResult UPlayFabMultiplayerModelDecoder::decodeGetServerBackfillTicketResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerGetServerBackfillTicketResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.CancellationReasonString = !(dataObj->HasField("CancellationReasonString")) ? TEXT("") : dataObj->GetStringField("CancellationReasonString");
    tempStruct.Created = !(dataObj->HasField("Created")) ? TEXT("") : dataObj->GetStringField("Created");
    tempStruct.GiveUpAfterSeconds = !(dataObj->HasField("GiveUpAfterSeconds")) ? 0 : int(dataObj->GetNumberField("GiveUpAfterSeconds"));
    tempStruct.MatchId = !(dataObj->HasField("MatchId")) ? TEXT("") : dataObj->GetStringField("MatchId");
    tempStruct.Members = !(dataObj->HasField("Members")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Members");
    tempStruct.QueueName = !(dataObj->HasField("QueueName")) ? TEXT("") : dataObj->GetStringField("QueueName");
    tempStruct.ServerDetails = !(dataObj->HasField("ServerDetails")) ? nullptr : dataObj->GetObjectField("ServerDetails");
    tempStruct.Status = !(dataObj->HasField("Status")) ? TEXT("") : dataObj->GetStringField("Status");
    tempStruct.TicketId = !(dataObj->HasField("TicketId")) ? TEXT("") : dataObj->GetStringField("TicketId");

    return tempStruct;
}

FMultiplayerJoinMatchmakingTicketResult UPlayFabMultiplayerModelDecoder::decodeJoinMatchmakingTicketResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerJoinMatchmakingTicketResult tempStruct;


    return tempStruct;
}

FMultiplayerListMatchmakingTicketsForPlayerResult UPlayFabMultiplayerModelDecoder::decodeListMatchmakingTicketsForPlayerResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerListMatchmakingTicketsForPlayerResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.TicketIds = !(dataObj->HasField("TicketIds")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("TicketIds"), TEXT(","));

    return tempStruct;
}

FMultiplayerListServerBackfillTicketsForPlayerResult UPlayFabMultiplayerModelDecoder::decodeListServerBackfillTicketsForPlayerResultResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerListServerBackfillTicketsForPlayerResult tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.TicketIds = !(dataObj->HasField("TicketIds")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("TicketIds"), TEXT(","));

    return tempStruct;
}



///////////////////////////////////////////////////////
// Matchmaking Admin
//////////////////////////////////////////////////////



///////////////////////////////////////////////////////
// MultiplayerServer
//////////////////////////////////////////////////////

FMultiplayerBuildAliasDetailsResponse UPlayFabMultiplayerModelDecoder::decodeBuildAliasDetailsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerBuildAliasDetailsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.AliasId = !(dataObj->HasField("AliasId")) ? TEXT("") : dataObj->GetStringField("AliasId");
    tempStruct.AliasName = !(dataObj->HasField("AliasName")) ? TEXT("") : dataObj->GetStringField("AliasName");
    tempStruct.BuildSelectionCriteria = !(dataObj->HasField("BuildSelectionCriteria")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("BuildSelectionCriteria");

    return tempStruct;
}

FMultiplayerCreateBuildWithCustomContainerResponse UPlayFabMultiplayerModelDecoder::decodeCreateBuildWithCustomContainerResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerCreateBuildWithCustomContainerResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.AreAssetsReadonly = !(dataObj->HasField("AreAssetsReadonly")) ? false : dataObj->GetBoolField("AreAssetsReadonly");
    tempStruct.BuildId = !(dataObj->HasField("BuildId")) ? TEXT("") : dataObj->GetStringField("BuildId");
    tempStruct.BuildName = !(dataObj->HasField("BuildName")) ? TEXT("") : dataObj->GetStringField("BuildName");
    GetEnumValueFromString<EContainerFlavor>(TEXT("EContainerFlavor"), dataObj->GetStringField("ContainerFlavor"), tempStruct.ContainerFlavor);
    tempStruct.ContainerRunCommand = !(dataObj->HasField("ContainerRunCommand")) ? TEXT("") : dataObj->GetStringField("ContainerRunCommand");
    tempStruct.CreationTime = !(dataObj->HasField("CreationTime")) ? TEXT("") : dataObj->GetStringField("CreationTime");
    tempStruct.CustomGameContainerImage = !(dataObj->HasField("CustomGameContainerImage")) ? nullptr : dataObj->GetObjectField("CustomGameContainerImage");
    tempStruct.GameAssetReferences = !(dataObj->HasField("GameAssetReferences")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("GameAssetReferences");
    tempStruct.GameCertificateReferences = !(dataObj->HasField("GameCertificateReferences")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("GameCertificateReferences");
    tempStruct.LinuxInstrumentationConfiguration = !(dataObj->HasField("LinuxInstrumentationConfiguration")) ? nullptr : dataObj->GetObjectField("LinuxInstrumentationConfiguration");
    tempStruct.Metadata = !(dataObj->HasField("Metadata")) ? nullptr : dataObj->GetObjectField("Metadata");
    tempStruct.MultiplayerServerCountPerVm = !(dataObj->HasField("MultiplayerServerCountPerVm")) ? 0 : int(dataObj->GetNumberField("MultiplayerServerCountPerVm"));
    tempStruct.OsPlatform = !(dataObj->HasField("OsPlatform")) ? TEXT("") : dataObj->GetStringField("OsPlatform");
    tempStruct.Ports = !(dataObj->HasField("Ports")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Ports");
    tempStruct.RegionConfigurations = !(dataObj->HasField("RegionConfigurations")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("RegionConfigurations");
    tempStruct.ServerType = !(dataObj->HasField("ServerType")) ? TEXT("") : dataObj->GetStringField("ServerType");
    tempStruct.UseStreamingForAssetDownloads = !(dataObj->HasField("UseStreamingForAssetDownloads")) ? false : dataObj->GetBoolField("UseStreamingForAssetDownloads");
    GetEnumValueFromString<EAzureVmSize>(TEXT("EAzureVmSize"), dataObj->GetStringField("VmSize"), tempStruct.VmSize);

    return tempStruct;
}

FMultiplayerCreateBuildWithManagedContainerResponse UPlayFabMultiplayerModelDecoder::decodeCreateBuildWithManagedContainerResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerCreateBuildWithManagedContainerResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.AreAssetsReadonly = !(dataObj->HasField("AreAssetsReadonly")) ? false : dataObj->GetBoolField("AreAssetsReadonly");
    tempStruct.BuildId = !(dataObj->HasField("BuildId")) ? TEXT("") : dataObj->GetStringField("BuildId");
    tempStruct.BuildName = !(dataObj->HasField("BuildName")) ? TEXT("") : dataObj->GetStringField("BuildName");
    GetEnumValueFromString<EContainerFlavor>(TEXT("EContainerFlavor"), dataObj->GetStringField("ContainerFlavor"), tempStruct.ContainerFlavor);
    tempStruct.CreationTime = !(dataObj->HasField("CreationTime")) ? TEXT("") : dataObj->GetStringField("CreationTime");
    tempStruct.GameAssetReferences = !(dataObj->HasField("GameAssetReferences")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("GameAssetReferences");
    tempStruct.GameCertificateReferences = !(dataObj->HasField("GameCertificateReferences")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("GameCertificateReferences");
    tempStruct.GameWorkingDirectory = !(dataObj->HasField("GameWorkingDirectory")) ? TEXT("") : dataObj->GetStringField("GameWorkingDirectory");
    tempStruct.InstrumentationConfiguration = !(dataObj->HasField("InstrumentationConfiguration")) ? nullptr : dataObj->GetObjectField("InstrumentationConfiguration");
    tempStruct.Metadata = !(dataObj->HasField("Metadata")) ? nullptr : dataObj->GetObjectField("Metadata");
    tempStruct.MultiplayerServerCountPerVm = !(dataObj->HasField("MultiplayerServerCountPerVm")) ? 0 : int(dataObj->GetNumberField("MultiplayerServerCountPerVm"));
    tempStruct.OsPlatform = !(dataObj->HasField("OsPlatform")) ? TEXT("") : dataObj->GetStringField("OsPlatform");
    tempStruct.Ports = !(dataObj->HasField("Ports")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Ports");
    tempStruct.RegionConfigurations = !(dataObj->HasField("RegionConfigurations")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("RegionConfigurations");
    tempStruct.ServerType = !(dataObj->HasField("ServerType")) ? TEXT("") : dataObj->GetStringField("ServerType");
    tempStruct.StartMultiplayerServerCommand = !(dataObj->HasField("StartMultiplayerServerCommand")) ? TEXT("") : dataObj->GetStringField("StartMultiplayerServerCommand");
    tempStruct.UseStreamingForAssetDownloads = !(dataObj->HasField("UseStreamingForAssetDownloads")) ? false : dataObj->GetBoolField("UseStreamingForAssetDownloads");
    GetEnumValueFromString<EAzureVmSize>(TEXT("EAzureVmSize"), dataObj->GetStringField("VmSize"), tempStruct.VmSize);

    return tempStruct;
}

FMultiplayerCreateBuildWithProcessBasedServerResponse UPlayFabMultiplayerModelDecoder::decodeCreateBuildWithProcessBasedServerResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerCreateBuildWithProcessBasedServerResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.AreAssetsReadonly = !(dataObj->HasField("AreAssetsReadonly")) ? false : dataObj->GetBoolField("AreAssetsReadonly");
    tempStruct.BuildId = !(dataObj->HasField("BuildId")) ? TEXT("") : dataObj->GetStringField("BuildId");
    tempStruct.BuildName = !(dataObj->HasField("BuildName")) ? TEXT("") : dataObj->GetStringField("BuildName");
    GetEnumValueFromString<EContainerFlavor>(TEXT("EContainerFlavor"), dataObj->GetStringField("ContainerFlavor"), tempStruct.ContainerFlavor);
    tempStruct.CreationTime = !(dataObj->HasField("CreationTime")) ? TEXT("") : dataObj->GetStringField("CreationTime");
    tempStruct.GameAssetReferences = !(dataObj->HasField("GameAssetReferences")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("GameAssetReferences");
    tempStruct.GameCertificateReferences = !(dataObj->HasField("GameCertificateReferences")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("GameCertificateReferences");
    tempStruct.GameWorkingDirectory = !(dataObj->HasField("GameWorkingDirectory")) ? TEXT("") : dataObj->GetStringField("GameWorkingDirectory");
    tempStruct.InstrumentationConfiguration = !(dataObj->HasField("InstrumentationConfiguration")) ? nullptr : dataObj->GetObjectField("InstrumentationConfiguration");
    tempStruct.IsOSPreview = !(dataObj->HasField("IsOSPreview")) ? false : dataObj->GetBoolField("IsOSPreview");
    tempStruct.Metadata = !(dataObj->HasField("Metadata")) ? nullptr : dataObj->GetObjectField("Metadata");
    tempStruct.MultiplayerServerCountPerVm = !(dataObj->HasField("MultiplayerServerCountPerVm")) ? 0 : int(dataObj->GetNumberField("MultiplayerServerCountPerVm"));
    tempStruct.OsPlatform = !(dataObj->HasField("OsPlatform")) ? TEXT("") : dataObj->GetStringField("OsPlatform");
    tempStruct.Ports = !(dataObj->HasField("Ports")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Ports");
    tempStruct.RegionConfigurations = !(dataObj->HasField("RegionConfigurations")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("RegionConfigurations");
    tempStruct.ServerType = !(dataObj->HasField("ServerType")) ? TEXT("") : dataObj->GetStringField("ServerType");
    tempStruct.StartMultiplayerServerCommand = !(dataObj->HasField("StartMultiplayerServerCommand")) ? TEXT("") : dataObj->GetStringField("StartMultiplayerServerCommand");
    tempStruct.UseStreamingForAssetDownloads = !(dataObj->HasField("UseStreamingForAssetDownloads")) ? false : dataObj->GetBoolField("UseStreamingForAssetDownloads");
    GetEnumValueFromString<EAzureVmSize>(TEXT("EAzureVmSize"), dataObj->GetStringField("VmSize"), tempStruct.VmSize);

    return tempStruct;
}

FMultiplayerCreateRemoteUserResponse UPlayFabMultiplayerModelDecoder::decodeCreateRemoteUserResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerCreateRemoteUserResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ExpirationTime = !(dataObj->HasField("ExpirationTime")) ? TEXT("") : dataObj->GetStringField("ExpirationTime");
    tempStruct.Password = !(dataObj->HasField("Password")) ? TEXT("") : dataObj->GetStringField("Password");
    tempStruct.Username = !(dataObj->HasField("Username")) ? TEXT("") : dataObj->GetStringField("Username");

    return tempStruct;
}

FMultiplayerCreateTitleMultiplayerServersQuotaChangeResponse UPlayFabMultiplayerModelDecoder::decodeCreateTitleMultiplayerServersQuotaChangeResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerCreateTitleMultiplayerServersQuotaChangeResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.RequestId = !(dataObj->HasField("RequestId")) ? TEXT("") : dataObj->GetStringField("RequestId");
    tempStruct.WasApproved = !(dataObj->HasField("WasApproved")) ? false : dataObj->GetBoolField("WasApproved");

    return tempStruct;
}

FMultiplayerEmptyResponse UPlayFabMultiplayerModelDecoder::decodeEmptyResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerEmptyResponse tempStruct;


    return tempStruct;
}

FMultiplayerEnableMultiplayerServersForTitleResponse UPlayFabMultiplayerModelDecoder::decodeEnableMultiplayerServersForTitleResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerEnableMultiplayerServersForTitleResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    GetEnumValueFromString<ETitleMultiplayerServerEnabledStatus>(TEXT("ETitleMultiplayerServerEnabledStatus"), dataObj->GetStringField("Status"), tempStruct.Status);

    return tempStruct;
}

FMultiplayerGetAssetDownloadUrlResponse UPlayFabMultiplayerModelDecoder::decodeGetAssetDownloadUrlResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerGetAssetDownloadUrlResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.AssetDownloadUrl = !(dataObj->HasField("AssetDownloadUrl")) ? TEXT("") : dataObj->GetStringField("AssetDownloadUrl");
    tempStruct.FileName = !(dataObj->HasField("FileName")) ? TEXT("") : dataObj->GetStringField("FileName");

    return tempStruct;
}

FMultiplayerGetAssetUploadUrlResponse UPlayFabMultiplayerModelDecoder::decodeGetAssetUploadUrlResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerGetAssetUploadUrlResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.AssetUploadUrl = !(dataObj->HasField("AssetUploadUrl")) ? TEXT("") : dataObj->GetStringField("AssetUploadUrl");
    tempStruct.FileName = !(dataObj->HasField("FileName")) ? TEXT("") : dataObj->GetStringField("FileName");

    return tempStruct;
}

FMultiplayerGetBuildResponse UPlayFabMultiplayerModelDecoder::decodeGetBuildResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerGetBuildResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.AreAssetsReadonly = !(dataObj->HasField("AreAssetsReadonly")) ? false : dataObj->GetBoolField("AreAssetsReadonly");
    tempStruct.BuildId = !(dataObj->HasField("BuildId")) ? TEXT("") : dataObj->GetStringField("BuildId");
    tempStruct.BuildName = !(dataObj->HasField("BuildName")) ? TEXT("") : dataObj->GetStringField("BuildName");
    tempStruct.BuildStatus = !(dataObj->HasField("BuildStatus")) ? TEXT("") : dataObj->GetStringField("BuildStatus");
    GetEnumValueFromString<EContainerFlavor>(TEXT("EContainerFlavor"), dataObj->GetStringField("ContainerFlavor"), tempStruct.ContainerFlavor);
    tempStruct.ContainerRunCommand = !(dataObj->HasField("ContainerRunCommand")) ? TEXT("") : dataObj->GetStringField("ContainerRunCommand");
    tempStruct.CreationTime = !(dataObj->HasField("CreationTime")) ? TEXT("") : dataObj->GetStringField("CreationTime");
    tempStruct.CustomGameContainerImage = !(dataObj->HasField("CustomGameContainerImage")) ? nullptr : dataObj->GetObjectField("CustomGameContainerImage");
    tempStruct.GameAssetReferences = !(dataObj->HasField("GameAssetReferences")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("GameAssetReferences");
    tempStruct.GameCertificateReferences = !(dataObj->HasField("GameCertificateReferences")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("GameCertificateReferences");
    tempStruct.InstrumentationConfiguration = !(dataObj->HasField("InstrumentationConfiguration")) ? nullptr : dataObj->GetObjectField("InstrumentationConfiguration");
    tempStruct.Metadata = !(dataObj->HasField("Metadata")) ? nullptr : dataObj->GetObjectField("Metadata");
    tempStruct.MultiplayerServerCountPerVm = !(dataObj->HasField("MultiplayerServerCountPerVm")) ? 0 : int(dataObj->GetNumberField("MultiplayerServerCountPerVm"));
    tempStruct.OsPlatform = !(dataObj->HasField("OsPlatform")) ? TEXT("") : dataObj->GetStringField("OsPlatform");
    tempStruct.Ports = !(dataObj->HasField("Ports")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Ports");
    tempStruct.RegionConfigurations = !(dataObj->HasField("RegionConfigurations")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("RegionConfigurations");
    tempStruct.ServerType = !(dataObj->HasField("ServerType")) ? TEXT("") : dataObj->GetStringField("ServerType");
    tempStruct.StartMultiplayerServerCommand = !(dataObj->HasField("StartMultiplayerServerCommand")) ? TEXT("") : dataObj->GetStringField("StartMultiplayerServerCommand");
    tempStruct.UseStreamingForAssetDownloads = !(dataObj->HasField("UseStreamingForAssetDownloads")) ? false : dataObj->GetBoolField("UseStreamingForAssetDownloads");
    GetEnumValueFromString<EAzureVmSize>(TEXT("EAzureVmSize"), dataObj->GetStringField("VmSize"), tempStruct.VmSize);

    return tempStruct;
}

FMultiplayerGetContainerRegistryCredentialsResponse UPlayFabMultiplayerModelDecoder::decodeGetContainerRegistryCredentialsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerGetContainerRegistryCredentialsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.DnsName = !(dataObj->HasField("DnsName")) ? TEXT("") : dataObj->GetStringField("DnsName");
    tempStruct.Password = !(dataObj->HasField("Password")) ? TEXT("") : dataObj->GetStringField("Password");
    tempStruct.Username = !(dataObj->HasField("Username")) ? TEXT("") : dataObj->GetStringField("Username");

    return tempStruct;
}

FMultiplayerGetMultiplayerServerDetailsResponse UPlayFabMultiplayerModelDecoder::decodeGetMultiplayerServerDetailsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerGetMultiplayerServerDetailsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.BuildId = !(dataObj->HasField("BuildId")) ? TEXT("") : dataObj->GetStringField("BuildId");
    tempStruct.ConnectedPlayers = !(dataObj->HasField("ConnectedPlayers")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("ConnectedPlayers");
    tempStruct.FQDN = !(dataObj->HasField("FQDN")) ? TEXT("") : dataObj->GetStringField("FQDN");
    tempStruct.IPV4Address = !(dataObj->HasField("IPV4Address")) ? TEXT("") : dataObj->GetStringField("IPV4Address");
    tempStruct.LastStateTransitionTime = !(dataObj->HasField("LastStateTransitionTime")) ? TEXT("") : dataObj->GetStringField("LastStateTransitionTime");
    tempStruct.Ports = !(dataObj->HasField("Ports")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Ports");
    tempStruct.Region = !(dataObj->HasField("Region")) ? TEXT("") : dataObj->GetStringField("Region");
    tempStruct.ServerId = !(dataObj->HasField("ServerId")) ? TEXT("") : dataObj->GetStringField("ServerId");
    tempStruct.SessionId = !(dataObj->HasField("SessionId")) ? TEXT("") : dataObj->GetStringField("SessionId");
    tempStruct.State = !(dataObj->HasField("State")) ? TEXT("") : dataObj->GetStringField("State");
    tempStruct.VmId = !(dataObj->HasField("VmId")) ? TEXT("") : dataObj->GetStringField("VmId");

    return tempStruct;
}

FMultiplayerGetMultiplayerServerLogsResponse UPlayFabMultiplayerModelDecoder::decodeGetMultiplayerServerLogsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerGetMultiplayerServerLogsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.LogDownloadUrl = !(dataObj->HasField("LogDownloadUrl")) ? TEXT("") : dataObj->GetStringField("LogDownloadUrl");

    return tempStruct;
}

FMultiplayerGetRemoteLoginEndpointResponse UPlayFabMultiplayerModelDecoder::decodeGetRemoteLoginEndpointResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerGetRemoteLoginEndpointResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.IPV4Address = !(dataObj->HasField("IPV4Address")) ? TEXT("") : dataObj->GetStringField("IPV4Address");
    tempStruct.Port = !(dataObj->HasField("Port")) ? 0 : int(dataObj->GetNumberField("Port"));

    return tempStruct;
}

FMultiplayerGetTitleEnabledForMultiplayerServersStatusResponse UPlayFabMultiplayerModelDecoder::decodeGetTitleEnabledForMultiplayerServersStatusResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerGetTitleEnabledForMultiplayerServersStatusResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    GetEnumValueFromString<ETitleMultiplayerServerEnabledStatus>(TEXT("ETitleMultiplayerServerEnabledStatus"), dataObj->GetStringField("Status"), tempStruct.Status);

    return tempStruct;
}

FMultiplayerGetTitleMultiplayerServersQuotaChangeResponse UPlayFabMultiplayerModelDecoder::decodeGetTitleMultiplayerServersQuotaChangeResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerGetTitleMultiplayerServersQuotaChangeResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Change = !(dataObj->HasField("Change")) ? nullptr : dataObj->GetObjectField("Change");

    return tempStruct;
}

FMultiplayerGetTitleMultiplayerServersQuotasResponse UPlayFabMultiplayerModelDecoder::decodeGetTitleMultiplayerServersQuotasResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerGetTitleMultiplayerServersQuotasResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Quotas = !(dataObj->HasField("Quotas")) ? nullptr : dataObj->GetObjectField("Quotas");

    return tempStruct;
}

FMultiplayerListMultiplayerServersResponse UPlayFabMultiplayerModelDecoder::decodeListMultiplayerServersResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerListMultiplayerServersResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.MultiplayerServerSummaries = !(dataObj->HasField("MultiplayerServerSummaries")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("MultiplayerServerSummaries");
    tempStruct.PageSize = !(dataObj->HasField("PageSize")) ? 0 : int(dataObj->GetNumberField("PageSize"));
    tempStruct.SkipToken = !(dataObj->HasField("SkipToken")) ? TEXT("") : dataObj->GetStringField("SkipToken");

    return tempStruct;
}

FMultiplayerListAssetSummariesResponse UPlayFabMultiplayerModelDecoder::decodeListAssetSummariesResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerListAssetSummariesResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.AssetSummaries = !(dataObj->HasField("AssetSummaries")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("AssetSummaries");
    tempStruct.PageSize = !(dataObj->HasField("PageSize")) ? 0 : int(dataObj->GetNumberField("PageSize"));
    tempStruct.SkipToken = !(dataObj->HasField("SkipToken")) ? TEXT("") : dataObj->GetStringField("SkipToken");

    return tempStruct;
}

FMultiplayerListBuildAliasesResponse UPlayFabMultiplayerModelDecoder::decodeListBuildAliasesResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerListBuildAliasesResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.BuildAliases = !(dataObj->HasField("BuildAliases")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("BuildAliases");
    tempStruct.PageSize = !(dataObj->HasField("PageSize")) ? 0 : int(dataObj->GetNumberField("PageSize"));
    tempStruct.SkipToken = !(dataObj->HasField("SkipToken")) ? TEXT("") : dataObj->GetStringField("SkipToken");

    return tempStruct;
}

FMultiplayerListBuildSummariesResponse UPlayFabMultiplayerModelDecoder::decodeListBuildSummariesResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerListBuildSummariesResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.BuildSummaries = !(dataObj->HasField("BuildSummaries")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("BuildSummaries");
    tempStruct.PageSize = !(dataObj->HasField("PageSize")) ? 0 : int(dataObj->GetNumberField("PageSize"));
    tempStruct.SkipToken = !(dataObj->HasField("SkipToken")) ? TEXT("") : dataObj->GetStringField("SkipToken");

    return tempStruct;
}

FMultiplayerListCertificateSummariesResponse UPlayFabMultiplayerModelDecoder::decodeListCertificateSummariesResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerListCertificateSummariesResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.CertificateSummaries = !(dataObj->HasField("CertificateSummaries")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("CertificateSummaries");
    tempStruct.PageSize = !(dataObj->HasField("PageSize")) ? 0 : int(dataObj->GetNumberField("PageSize"));
    tempStruct.SkipToken = !(dataObj->HasField("SkipToken")) ? TEXT("") : dataObj->GetStringField("SkipToken");

    return tempStruct;
}

FMultiplayerListContainerImagesResponse UPlayFabMultiplayerModelDecoder::decodeListContainerImagesResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerListContainerImagesResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Images = !(dataObj->HasField("Images")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("Images"), TEXT(","));
    tempStruct.PageSize = !(dataObj->HasField("PageSize")) ? 0 : int(dataObj->GetNumberField("PageSize"));
    tempStruct.SkipToken = !(dataObj->HasField("SkipToken")) ? TEXT("") : dataObj->GetStringField("SkipToken");

    return tempStruct;
}

FMultiplayerListContainerImageTagsResponse UPlayFabMultiplayerModelDecoder::decodeListContainerImageTagsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerListContainerImageTagsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Tags = !(dataObj->HasField("Tags")) ? TEXT("") : FString::Join(dataObj->GetStringArrayField("Tags"), TEXT(","));

    return tempStruct;
}

FMultiplayerListPartyQosServersResponse UPlayFabMultiplayerModelDecoder::decodeListPartyQosServersResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerListPartyQosServersResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.PageSize = !(dataObj->HasField("PageSize")) ? 0 : int(dataObj->GetNumberField("PageSize"));
    tempStruct.QosServers = !(dataObj->HasField("QosServers")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("QosServers");
    tempStruct.SkipToken = !(dataObj->HasField("SkipToken")) ? TEXT("") : dataObj->GetStringField("SkipToken");

    return tempStruct;
}

FMultiplayerListQosServersForTitleResponse UPlayFabMultiplayerModelDecoder::decodeListQosServersForTitleResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerListQosServersForTitleResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.PageSize = !(dataObj->HasField("PageSize")) ? 0 : int(dataObj->GetNumberField("PageSize"));
    tempStruct.QosServers = !(dataObj->HasField("QosServers")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("QosServers");
    tempStruct.SkipToken = !(dataObj->HasField("SkipToken")) ? TEXT("") : dataObj->GetStringField("SkipToken");

    return tempStruct;
}

FMultiplayerListTitleMultiplayerServersQuotaChangesResponse UPlayFabMultiplayerModelDecoder::decodeListTitleMultiplayerServersQuotaChangesResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerListTitleMultiplayerServersQuotaChangesResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Changes = !(dataObj->HasField("Changes")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Changes");

    return tempStruct;
}

FMultiplayerListVirtualMachineSummariesResponse UPlayFabMultiplayerModelDecoder::decodeListVirtualMachineSummariesResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerListVirtualMachineSummariesResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.PageSize = !(dataObj->HasField("PageSize")) ? 0 : int(dataObj->GetNumberField("PageSize"));
    tempStruct.SkipToken = !(dataObj->HasField("SkipToken")) ? TEXT("") : dataObj->GetStringField("SkipToken");
    tempStruct.VirtualMachines = !(dataObj->HasField("VirtualMachines")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("VirtualMachines");

    return tempStruct;
}

FMultiplayerRequestMultiplayerServerResponse UPlayFabMultiplayerModelDecoder::decodeRequestMultiplayerServerResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerRequestMultiplayerServerResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.BuildId = !(dataObj->HasField("BuildId")) ? TEXT("") : dataObj->GetStringField("BuildId");
    tempStruct.ConnectedPlayers = !(dataObj->HasField("ConnectedPlayers")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("ConnectedPlayers");
    tempStruct.FQDN = !(dataObj->HasField("FQDN")) ? TEXT("") : dataObj->GetStringField("FQDN");
    tempStruct.IPV4Address = !(dataObj->HasField("IPV4Address")) ? TEXT("") : dataObj->GetStringField("IPV4Address");
    tempStruct.LastStateTransitionTime = !(dataObj->HasField("LastStateTransitionTime")) ? TEXT("") : dataObj->GetStringField("LastStateTransitionTime");
    tempStruct.Ports = !(dataObj->HasField("Ports")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Ports");
    tempStruct.Region = !(dataObj->HasField("Region")) ? TEXT("") : dataObj->GetStringField("Region");
    tempStruct.ServerId = !(dataObj->HasField("ServerId")) ? TEXT("") : dataObj->GetStringField("ServerId");
    tempStruct.SessionId = !(dataObj->HasField("SessionId")) ? TEXT("") : dataObj->GetStringField("SessionId");
    tempStruct.State = !(dataObj->HasField("State")) ? TEXT("") : dataObj->GetStringField("State");
    tempStruct.VmId = !(dataObj->HasField("VmId")) ? TEXT("") : dataObj->GetStringField("VmId");

    return tempStruct;
}

FMultiplayerRolloverContainerRegistryCredentialsResponse UPlayFabMultiplayerModelDecoder::decodeRolloverContainerRegistryCredentialsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FMultiplayerRolloverContainerRegistryCredentialsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.DnsName = !(dataObj->HasField("DnsName")) ? TEXT("") : dataObj->GetStringField("DnsName");
    tempStruct.Password = !(dataObj->HasField("Password")) ? TEXT("") : dataObj->GetStringField("Password");
    tempStruct.Username = !(dataObj->HasField("Username")) ? TEXT("") : dataObj->GetStringField("Username");

    return tempStruct;
}


