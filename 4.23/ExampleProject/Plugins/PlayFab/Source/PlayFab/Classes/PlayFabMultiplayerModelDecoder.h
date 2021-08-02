//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Multiplayer
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabMultiplayerModels.h"
#include "PlayFabMultiplayerModelDecoder.generated.h"

class UPlayFabJsonObject;

UCLASS()
class PLAYFAB_API UPlayFabMultiplayerModelDecoder : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    //////////////////////////////////////////////////////////////////////////
    // Generated PlayFab Multiplayer API Functions
    //////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////
    // Matchmaking
    //////////////////////////////////////////////////////

    /** Decode the CancelAllMatchmakingTicketsForPlayerResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking Models")
        static FMultiplayerCancelAllMatchmakingTicketsForPlayerResult decodeCancelAllMatchmakingTicketsForPlayerResultResponse(UPlayFabJsonObject* response);

    /** Decode the CancelAllServerBackfillTicketsForPlayerResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking Models")
        static FMultiplayerCancelAllServerBackfillTicketsForPlayerResult decodeCancelAllServerBackfillTicketsForPlayerResultResponse(UPlayFabJsonObject* response);

    /** Decode the CancelMatchmakingTicketResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking Models")
        static FMultiplayerCancelMatchmakingTicketResult decodeCancelMatchmakingTicketResultResponse(UPlayFabJsonObject* response);

    /** Decode the CancelServerBackfillTicketResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking Models")
        static FMultiplayerCancelServerBackfillTicketResult decodeCancelServerBackfillTicketResultResponse(UPlayFabJsonObject* response);

    /** Decode the CreateMatchmakingTicketResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking Models")
        static FMultiplayerCreateMatchmakingTicketResult decodeCreateMatchmakingTicketResultResponse(UPlayFabJsonObject* response);

    /** Decode the CreateServerBackfillTicketResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking Models")
        static FMultiplayerCreateServerBackfillTicketResult decodeCreateServerBackfillTicketResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetMatchResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking Models")
        static FMultiplayerGetMatchResult decodeGetMatchResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetMatchmakingTicketResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking Models")
        static FMultiplayerGetMatchmakingTicketResult decodeGetMatchmakingTicketResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetQueueStatisticsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking Models")
        static FMultiplayerGetQueueStatisticsResult decodeGetQueueStatisticsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetServerBackfillTicketResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking Models")
        static FMultiplayerGetServerBackfillTicketResult decodeGetServerBackfillTicketResultResponse(UPlayFabJsonObject* response);

    /** Decode the JoinMatchmakingTicketResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking Models")
        static FMultiplayerJoinMatchmakingTicketResult decodeJoinMatchmakingTicketResultResponse(UPlayFabJsonObject* response);

    /** Decode the ListMatchmakingTicketsForPlayerResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking Models")
        static FMultiplayerListMatchmakingTicketsForPlayerResult decodeListMatchmakingTicketsForPlayerResultResponse(UPlayFabJsonObject* response);

    /** Decode the ListServerBackfillTicketsForPlayerResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking Models")
        static FMultiplayerListServerBackfillTicketsForPlayerResult decodeListServerBackfillTicketsForPlayerResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Matchmaking Admin
    //////////////////////////////////////////////////////



    ///////////////////////////////////////////////////////
    // MultiplayerServer
    //////////////////////////////////////////////////////

    /** Decode the BuildAliasDetailsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerBuildAliasDetailsResponse decodeBuildAliasDetailsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the CreateBuildWithCustomContainerResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerCreateBuildWithCustomContainerResponse decodeCreateBuildWithCustomContainerResponseResponse(UPlayFabJsonObject* response);

    /** Decode the CreateBuildWithManagedContainerResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerCreateBuildWithManagedContainerResponse decodeCreateBuildWithManagedContainerResponseResponse(UPlayFabJsonObject* response);

    /** Decode the CreateBuildWithProcessBasedServerResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerCreateBuildWithProcessBasedServerResponse decodeCreateBuildWithProcessBasedServerResponseResponse(UPlayFabJsonObject* response);

    /** Decode the CreateRemoteUserResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerCreateRemoteUserResponse decodeCreateRemoteUserResponseResponse(UPlayFabJsonObject* response);

    /** Decode the CreateTitleMultiplayerServersQuotaChangeResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerCreateTitleMultiplayerServersQuotaChangeResponse decodeCreateTitleMultiplayerServersQuotaChangeResponseResponse(UPlayFabJsonObject* response);

    /** Decode the EmptyResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerEmptyResponse decodeEmptyResponseResponse(UPlayFabJsonObject* response);

    /** Decode the EnableMultiplayerServersForTitleResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerEnableMultiplayerServersForTitleResponse decodeEnableMultiplayerServersForTitleResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetAssetDownloadUrlResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerGetAssetDownloadUrlResponse decodeGetAssetDownloadUrlResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetAssetUploadUrlResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerGetAssetUploadUrlResponse decodeGetAssetUploadUrlResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetBuildResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerGetBuildResponse decodeGetBuildResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetContainerRegistryCredentialsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerGetContainerRegistryCredentialsResponse decodeGetContainerRegistryCredentialsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetMultiplayerServerDetailsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerGetMultiplayerServerDetailsResponse decodeGetMultiplayerServerDetailsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetMultiplayerServerLogsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerGetMultiplayerServerLogsResponse decodeGetMultiplayerServerLogsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetRemoteLoginEndpointResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerGetRemoteLoginEndpointResponse decodeGetRemoteLoginEndpointResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetTitleEnabledForMultiplayerServersStatusResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerGetTitleEnabledForMultiplayerServersStatusResponse decodeGetTitleEnabledForMultiplayerServersStatusResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetTitleMultiplayerServersQuotaChangeResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerGetTitleMultiplayerServersQuotaChangeResponse decodeGetTitleMultiplayerServersQuotaChangeResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetTitleMultiplayerServersQuotasResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerGetTitleMultiplayerServersQuotasResponse decodeGetTitleMultiplayerServersQuotasResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListMultiplayerServersResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerListMultiplayerServersResponse decodeListMultiplayerServersResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListAssetSummariesResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerListAssetSummariesResponse decodeListAssetSummariesResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListBuildAliasesResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerListBuildAliasesResponse decodeListBuildAliasesResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListBuildSummariesResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerListBuildSummariesResponse decodeListBuildSummariesResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListCertificateSummariesResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerListCertificateSummariesResponse decodeListCertificateSummariesResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListContainerImagesResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerListContainerImagesResponse decodeListContainerImagesResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListContainerImageTagsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerListContainerImageTagsResponse decodeListContainerImageTagsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListPartyQosServersResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerListPartyQosServersResponse decodeListPartyQosServersResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListQosServersForTitleResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerListQosServersForTitleResponse decodeListQosServersForTitleResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListTitleMultiplayerServersQuotaChangesResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerListTitleMultiplayerServersQuotaChangesResponse decodeListTitleMultiplayerServersQuotaChangesResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListVirtualMachineSummariesResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerListVirtualMachineSummariesResponse decodeListVirtualMachineSummariesResponseResponse(UPlayFabJsonObject* response);

    /** Decode the RequestMultiplayerServerResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerRequestMultiplayerServerResponse decodeRequestMultiplayerServerResponseResponse(UPlayFabJsonObject* response);

    /** Decode the RolloverContainerRegistryCredentialsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerRolloverContainerRegistryCredentialsResponse decodeRolloverContainerRegistryCredentialsResponseResponse(UPlayFabJsonObject* response);



};
