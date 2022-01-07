//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated header file for the UE4 PlayFab plugin.
// This header file contains the function definitions.
//
// API: Multiplayer
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Http.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "PlayFabBaseModel.h"
#include "PlayFabMultiplayerModels.h"
#include "PlayFabMultiplayerAPI.generated.h"

class UPlayFabAuthenticationContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPlayFabMultiplayerRequestCompleted, FPlayFabBaseModel, response, UObject*, customData, bool, successful);

UCLASS(Blueprintable, BlueprintType)
class PLAYFAB_API UPlayFabMultiplayerAPI : public UOnlineBlueprintCallProxyBase
{
    GENERATED_UCLASS_BODY()

public:
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnFailurePlayFabError, FPlayFabError, error, UObject*, customData);

    UPROPERTY(BlueprintAssignable)
        FOnPlayFabMultiplayerRequestCompleted OnPlayFabResponse;

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
    // Generated PlayFab Multiplayer API Functions
    //////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////
    // Matchmaking
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCancelAllMatchmakingTicketsForPlayer, FMultiplayerCancelAllMatchmakingTicketsForPlayerResult, result, UObject*, customData);

    /** Cancel all active tickets the player is a member of in a given queue. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* CancelAllMatchmakingTicketsForPlayer(FMultiplayerCancelAllMatchmakingTicketsForPlayerRequest request,
            FDelegateOnSuccessCancelAllMatchmakingTicketsForPlayer onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCancelAllMatchmakingTicketsForPlayer(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCancelAllServerBackfillTicketsForPlayer, FMultiplayerCancelAllServerBackfillTicketsForPlayerResult, result, UObject*, customData);

    /** Cancel all active backfill tickets the player is a member of in a given queue. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* CancelAllServerBackfillTicketsForPlayer(FMultiplayerCancelAllServerBackfillTicketsForPlayerRequest request,
            FDelegateOnSuccessCancelAllServerBackfillTicketsForPlayer onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCancelAllServerBackfillTicketsForPlayer(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCancelMatchmakingTicket, FMultiplayerCancelMatchmakingTicketResult, result, UObject*, customData);

    /** Cancel a matchmaking ticket. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* CancelMatchmakingTicket(FMultiplayerCancelMatchmakingTicketRequest request,
            FDelegateOnSuccessCancelMatchmakingTicket onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCancelMatchmakingTicket(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCancelServerBackfillTicket, FMultiplayerCancelServerBackfillTicketResult, result, UObject*, customData);

    /** Cancel a server backfill ticket. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* CancelServerBackfillTicket(FMultiplayerCancelServerBackfillTicketRequest request,
            FDelegateOnSuccessCancelServerBackfillTicket onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCancelServerBackfillTicket(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateMatchmakingTicket, FMultiplayerCreateMatchmakingTicketResult, result, UObject*, customData);

    /** Create a matchmaking ticket as a client. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* CreateMatchmakingTicket(FMultiplayerCreateMatchmakingTicketRequest request,
            FDelegateOnSuccessCreateMatchmakingTicket onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateMatchmakingTicket(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateServerBackfillTicket, FMultiplayerCreateServerBackfillTicketResult, result, UObject*, customData);

    /**
     * Create a backfill matchmaking ticket as a server. A backfill ticket represents an ongoing game. The matchmaking service
     * automatically starts matching the backfill ticket against other matchmaking tickets. Backfill tickets cannot match with
     * other backfill tickets.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* CreateServerBackfillTicket(FMultiplayerCreateServerBackfillTicketRequest request,
            FDelegateOnSuccessCreateServerBackfillTicket onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateServerBackfillTicket(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateServerMatchmakingTicket, FMultiplayerCreateMatchmakingTicketResult, result, UObject*, customData);

    /**
     * Create a matchmaking ticket as a server. The matchmaking service automatically starts matching the ticket against other
     * matchmaking tickets.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* CreateServerMatchmakingTicket(FMultiplayerCreateServerMatchmakingTicketRequest request,
            FDelegateOnSuccessCreateServerMatchmakingTicket onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateServerMatchmakingTicket(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetMatch, FMultiplayerGetMatchResult, result, UObject*, customData);

    /** Get a match. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* GetMatch(FMultiplayerGetMatchRequest request,
            FDelegateOnSuccessGetMatch onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetMatch(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetMatchmakingTicket, FMultiplayerGetMatchmakingTicketResult, result, UObject*, customData);

    /** Get a matchmaking ticket by ticket Id. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* GetMatchmakingTicket(FMultiplayerGetMatchmakingTicketRequest request,
            FDelegateOnSuccessGetMatchmakingTicket onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetMatchmakingTicket(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetQueueStatistics, FMultiplayerGetQueueStatisticsResult, result, UObject*, customData);

    /** Get the statistics for a queue. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* GetQueueStatistics(FMultiplayerGetQueueStatisticsRequest request,
            FDelegateOnSuccessGetQueueStatistics onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetQueueStatistics(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetServerBackfillTicket, FMultiplayerGetServerBackfillTicketResult, result, UObject*, customData);

    /** Get a matchmaking backfill ticket by ticket Id. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* GetServerBackfillTicket(FMultiplayerGetServerBackfillTicketRequest request,
            FDelegateOnSuccessGetServerBackfillTicket onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetServerBackfillTicket(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessJoinMatchmakingTicket, FMultiplayerJoinMatchmakingTicketResult, result, UObject*, customData);

    /** Join a matchmaking ticket. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* JoinMatchmakingTicket(FMultiplayerJoinMatchmakingTicketRequest request,
            FDelegateOnSuccessJoinMatchmakingTicket onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperJoinMatchmakingTicket(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListMatchmakingTicketsForPlayer, FMultiplayerListMatchmakingTicketsForPlayerResult, result, UObject*, customData);

    /** List all matchmaking ticket Ids the user is a member of. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* ListMatchmakingTicketsForPlayer(FMultiplayerListMatchmakingTicketsForPlayerRequest request,
            FDelegateOnSuccessListMatchmakingTicketsForPlayer onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListMatchmakingTicketsForPlayer(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListServerBackfillTicketsForPlayer, FMultiplayerListServerBackfillTicketsForPlayerResult, result, UObject*, customData);

    /** List all server backfill ticket Ids the user is a member of. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* ListServerBackfillTicketsForPlayer(FMultiplayerListServerBackfillTicketsForPlayerRequest request,
            FDelegateOnSuccessListServerBackfillTicketsForPlayer onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListServerBackfillTicketsForPlayer(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Matchmaking Admin
    //////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////
    // MultiplayerServer
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateBuildAlias, FMultiplayerBuildAliasDetailsResponse, result, UObject*, customData);

    /** Creates a multiplayer server build alias. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* CreateBuildAlias(FMultiplayerCreateBuildAliasRequest request,
            FDelegateOnSuccessCreateBuildAlias onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateBuildAlias(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateBuildWithCustomContainer, FMultiplayerCreateBuildWithCustomContainerResponse, result, UObject*, customData);

    /** Creates a multiplayer server build with a custom container. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* CreateBuildWithCustomContainer(FMultiplayerCreateBuildWithCustomContainerRequest request,
            FDelegateOnSuccessCreateBuildWithCustomContainer onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateBuildWithCustomContainer(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateBuildWithManagedContainer, FMultiplayerCreateBuildWithManagedContainerResponse, result, UObject*, customData);

    /** Creates a multiplayer server build with a managed container. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* CreateBuildWithManagedContainer(FMultiplayerCreateBuildWithManagedContainerRequest request,
            FDelegateOnSuccessCreateBuildWithManagedContainer onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateBuildWithManagedContainer(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateBuildWithProcessBasedServer, FMultiplayerCreateBuildWithProcessBasedServerResponse, result, UObject*, customData);

    /** Creates a multiplayer server build with the server running as a process. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* CreateBuildWithProcessBasedServer(FMultiplayerCreateBuildWithProcessBasedServerRequest request,
            FDelegateOnSuccessCreateBuildWithProcessBasedServer onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateBuildWithProcessBasedServer(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateRemoteUser, FMultiplayerCreateRemoteUserResponse, result, UObject*, customData);

    /** Creates a remote user to log on to a VM for a multiplayer server build. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* CreateRemoteUser(FMultiplayerCreateRemoteUserRequest request,
            FDelegateOnSuccessCreateRemoteUser onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateRemoteUser(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateTitleMultiplayerServersQuotaChange, FMultiplayerCreateTitleMultiplayerServersQuotaChangeResponse, result, UObject*, customData);

    /** Creates a request to change a title's multiplayer server quotas. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* CreateTitleMultiplayerServersQuotaChange(FMultiplayerCreateTitleMultiplayerServersQuotaChangeRequest request,
            FDelegateOnSuccessCreateTitleMultiplayerServersQuotaChange onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateTitleMultiplayerServersQuotaChange(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteAsset, FMultiplayerEmptyResponse, result, UObject*, customData);

    /** Deletes a multiplayer server game asset for a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* DeleteAsset(FMultiplayerDeleteAssetRequest request,
            FDelegateOnSuccessDeleteAsset onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteAsset(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteBuild, FMultiplayerEmptyResponse, result, UObject*, customData);

    /** Deletes a multiplayer server build. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* DeleteBuild(FMultiplayerDeleteBuildRequest request,
            FDelegateOnSuccessDeleteBuild onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteBuild(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteBuildAlias, FMultiplayerEmptyResponse, result, UObject*, customData);

    /** Deletes a multiplayer server build alias. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* DeleteBuildAlias(FMultiplayerDeleteBuildAliasRequest request,
            FDelegateOnSuccessDeleteBuildAlias onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteBuildAlias(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteBuildRegion, FMultiplayerEmptyResponse, result, UObject*, customData);

    /** Removes a multiplayer server build's region. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* DeleteBuildRegion(FMultiplayerDeleteBuildRegionRequest request,
            FDelegateOnSuccessDeleteBuildRegion onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteBuildRegion(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteCertificate, FMultiplayerEmptyResponse, result, UObject*, customData);

    /** Deletes a multiplayer server game certificate. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* DeleteCertificate(FMultiplayerDeleteCertificateRequest request,
            FDelegateOnSuccessDeleteCertificate onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteCertificate(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteContainerImageRepository, FMultiplayerEmptyResponse, result, UObject*, customData);

    /** Deletes a container image repository. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* DeleteContainerImageRepository(FMultiplayerDeleteContainerImageRequest request,
            FDelegateOnSuccessDeleteContainerImageRepository onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteContainerImageRepository(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteRemoteUser, FMultiplayerEmptyResponse, result, UObject*, customData);

    /** Deletes a remote user to log on to a VM for a multiplayer server build. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* DeleteRemoteUser(FMultiplayerDeleteRemoteUserRequest request,
            FDelegateOnSuccessDeleteRemoteUser onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteRemoteUser(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessEnableMultiplayerServersForTitle, FMultiplayerEnableMultiplayerServersForTitleResponse, result, UObject*, customData);

    /** Enables the multiplayer server feature for a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* EnableMultiplayerServersForTitle(FMultiplayerEnableMultiplayerServersForTitleRequest request,
            FDelegateOnSuccessEnableMultiplayerServersForTitle onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperEnableMultiplayerServersForTitle(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetAssetDownloadUrl, FMultiplayerGetAssetDownloadUrlResponse, result, UObject*, customData);

    /**
     * Gets a URL that can be used to download the specified asset. A sample pre-authenticated url -
     * https://sampleStorageAccount.blob.core.windows.net/gameassets/gameserver.zip?sv=2015-04-05&ss=b&srt=sco&sp=rw&st=startDate&se=endDate&spr=https&sig=sampleSig&api-version=2017-07-29
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* GetAssetDownloadUrl(FMultiplayerGetAssetDownloadUrlRequest request,
            FDelegateOnSuccessGetAssetDownloadUrl onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetAssetDownloadUrl(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetAssetUploadUrl, FMultiplayerGetAssetUploadUrlResponse, result, UObject*, customData);

    /**
     * Gets the URL to upload assets to. A sample pre-authenticated url -
     * https://sampleStorageAccount.blob.core.windows.net/gameassets/gameserver.zip?sv=2015-04-05&ss=b&srt=sco&sp=rw&st=startDate&se=endDate&spr=https&sig=sampleSig&api-version=2017-07-29
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* GetAssetUploadUrl(FMultiplayerGetAssetUploadUrlRequest request,
            FDelegateOnSuccessGetAssetUploadUrl onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetAssetUploadUrl(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetBuild, FMultiplayerGetBuildResponse, result, UObject*, customData);

    /** Gets a multiplayer server build. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* GetBuild(FMultiplayerGetBuildRequest request,
            FDelegateOnSuccessGetBuild onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetBuild(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetBuildAlias, FMultiplayerBuildAliasDetailsResponse, result, UObject*, customData);

    /** Gets a multiplayer server build alias. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* GetBuildAlias(FMultiplayerGetBuildAliasRequest request,
            FDelegateOnSuccessGetBuildAlias onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetBuildAlias(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetContainerRegistryCredentials, FMultiplayerGetContainerRegistryCredentialsResponse, result, UObject*, customData);

    /** Gets the credentials to the container registry. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* GetContainerRegistryCredentials(FMultiplayerGetContainerRegistryCredentialsRequest request,
            FDelegateOnSuccessGetContainerRegistryCredentials onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetContainerRegistryCredentials(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetMultiplayerServerDetails, FMultiplayerGetMultiplayerServerDetailsResponse, result, UObject*, customData);

    /** Gets multiplayer server session details for a build. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* GetMultiplayerServerDetails(FMultiplayerGetMultiplayerServerDetailsRequest request,
            FDelegateOnSuccessGetMultiplayerServerDetails onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetMultiplayerServerDetails(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetMultiplayerServerLogs, FMultiplayerGetMultiplayerServerLogsResponse, result, UObject*, customData);

    /** Gets multiplayer server logs after a server has terminated. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* GetMultiplayerServerLogs(FMultiplayerGetMultiplayerServerLogsRequest request,
            FDelegateOnSuccessGetMultiplayerServerLogs onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetMultiplayerServerLogs(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetMultiplayerSessionLogsBySessionId, FMultiplayerGetMultiplayerServerLogsResponse, result, UObject*, customData);

    /** Gets multiplayer server logs after a server has terminated. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* GetMultiplayerSessionLogsBySessionId(FMultiplayerGetMultiplayerSessionLogsBySessionIdRequest request,
            FDelegateOnSuccessGetMultiplayerSessionLogsBySessionId onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetMultiplayerSessionLogsBySessionId(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetRemoteLoginEndpoint, FMultiplayerGetRemoteLoginEndpointResponse, result, UObject*, customData);

    /** Gets a remote login endpoint to a VM that is hosting a multiplayer server build. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* GetRemoteLoginEndpoint(FMultiplayerGetRemoteLoginEndpointRequest request,
            FDelegateOnSuccessGetRemoteLoginEndpoint onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetRemoteLoginEndpoint(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetTitleEnabledForMultiplayerServersStatus, FMultiplayerGetTitleEnabledForMultiplayerServersStatusResponse, result, UObject*, customData);

    /** Gets the status of whether a title is enabled for the multiplayer server feature. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* GetTitleEnabledForMultiplayerServersStatus(FMultiplayerGetTitleEnabledForMultiplayerServersStatusRequest request,
            FDelegateOnSuccessGetTitleEnabledForMultiplayerServersStatus onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetTitleEnabledForMultiplayerServersStatus(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetTitleMultiplayerServersQuotaChange, FMultiplayerGetTitleMultiplayerServersQuotaChangeResponse, result, UObject*, customData);

    /** Gets a title's server quota change request. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* GetTitleMultiplayerServersQuotaChange(FMultiplayerGetTitleMultiplayerServersQuotaChangeRequest request,
            FDelegateOnSuccessGetTitleMultiplayerServersQuotaChange onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetTitleMultiplayerServersQuotaChange(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetTitleMultiplayerServersQuotas, FMultiplayerGetTitleMultiplayerServersQuotasResponse, result, UObject*, customData);

    /** Gets the quotas for a title in relation to multiplayer servers. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* GetTitleMultiplayerServersQuotas(FMultiplayerGetTitleMultiplayerServersQuotasRequest request,
            FDelegateOnSuccessGetTitleMultiplayerServersQuotas onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetTitleMultiplayerServersQuotas(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListArchivedMultiplayerServers, FMultiplayerListMultiplayerServersResponse, result, UObject*, customData);

    /** Lists archived multiplayer server sessions for a build. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* ListArchivedMultiplayerServers(FMultiplayerListMultiplayerServersRequest request,
            FDelegateOnSuccessListArchivedMultiplayerServers onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListArchivedMultiplayerServers(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListAssetSummaries, FMultiplayerListAssetSummariesResponse, result, UObject*, customData);

    /** Lists multiplayer server game assets for a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* ListAssetSummaries(FMultiplayerListAssetSummariesRequest request,
            FDelegateOnSuccessListAssetSummaries onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListAssetSummaries(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListBuildAliases, FMultiplayerListBuildAliasesResponse, result, UObject*, customData);

    /**
     * Lists details of all build aliases for a title. Accepts tokens for title and if game client access is enabled, allows
     * game client to request list of builds with player entity token.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* ListBuildAliases(FMultiplayerListBuildAliasesRequest request,
            FDelegateOnSuccessListBuildAliases onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListBuildAliases(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListBuildSummariesV2, FMultiplayerListBuildSummariesResponse, result, UObject*, customData);

    /**
     * Lists summarized details of all multiplayer server builds for a title. Accepts tokens for title and if game client
     * access is enabled, allows game client to request list of builds with player entity token.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* ListBuildSummariesV2(FMultiplayerListBuildSummariesRequest request,
            FDelegateOnSuccessListBuildSummariesV2 onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListBuildSummariesV2(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListCertificateSummaries, FMultiplayerListCertificateSummariesResponse, result, UObject*, customData);

    /** Lists multiplayer server game certificates for a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* ListCertificateSummaries(FMultiplayerListCertificateSummariesRequest request,
            FDelegateOnSuccessListCertificateSummaries onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListCertificateSummaries(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListContainerImages, FMultiplayerListContainerImagesResponse, result, UObject*, customData);

    /** Lists custom container images for a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* ListContainerImages(FMultiplayerListContainerImagesRequest request,
            FDelegateOnSuccessListContainerImages onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListContainerImages(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListContainerImageTags, FMultiplayerListContainerImageTagsResponse, result, UObject*, customData);

    /** Lists the tags for a custom container image. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* ListContainerImageTags(FMultiplayerListContainerImageTagsRequest request,
            FDelegateOnSuccessListContainerImageTags onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListContainerImageTags(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListMultiplayerServers, FMultiplayerListMultiplayerServersResponse, result, UObject*, customData);

    /** Lists multiplayer server sessions for a build. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* ListMultiplayerServers(FMultiplayerListMultiplayerServersRequest request,
            FDelegateOnSuccessListMultiplayerServers onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListMultiplayerServers(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListPartyQosServers, FMultiplayerListPartyQosServersResponse, result, UObject*, customData);

    /** Lists quality of service servers for party. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* ListPartyQosServers(FMultiplayerListPartyQosServersRequest request,
            FDelegateOnSuccessListPartyQosServers onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListPartyQosServers(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListQosServersForTitle, FMultiplayerListQosServersForTitleResponse, result, UObject*, customData);

    /**
     * Lists quality of service servers for the title. By default, servers are only returned for regions where a Multiplayer
     * Servers build has been deployed.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* ListQosServersForTitle(FMultiplayerListQosServersForTitleRequest request,
            FDelegateOnSuccessListQosServersForTitle onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListQosServersForTitle(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListTitleMultiplayerServersQuotaChanges, FMultiplayerListTitleMultiplayerServersQuotaChangesResponse, result, UObject*, customData);

    /** List all server quota change requests for a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* ListTitleMultiplayerServersQuotaChanges(FMultiplayerListTitleMultiplayerServersQuotaChangesRequest request,
            FDelegateOnSuccessListTitleMultiplayerServersQuotaChanges onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListTitleMultiplayerServersQuotaChanges(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListVirtualMachineSummaries, FMultiplayerListVirtualMachineSummariesResponse, result, UObject*, customData);

    /** Lists virtual machines for a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* ListVirtualMachineSummaries(FMultiplayerListVirtualMachineSummariesRequest request,
            FDelegateOnSuccessListVirtualMachineSummaries onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListVirtualMachineSummaries(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRequestMultiplayerServer, FMultiplayerRequestMultiplayerServerResponse, result, UObject*, customData);

    /**
     * Request a multiplayer server session. Accepts tokens for title and if game client access is enabled, allows game client
     * to request a server with player entity token.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* RequestMultiplayerServer(FMultiplayerRequestMultiplayerServerRequest request,
            FDelegateOnSuccessRequestMultiplayerServer onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRequestMultiplayerServer(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRolloverContainerRegistryCredentials, FMultiplayerRolloverContainerRegistryCredentialsResponse, result, UObject*, customData);

    /** Rolls over the credentials to the container registry. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* RolloverContainerRegistryCredentials(FMultiplayerRolloverContainerRegistryCredentialsRequest request,
            FDelegateOnSuccessRolloverContainerRegistryCredentials onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRolloverContainerRegistryCredentials(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessShutdownMultiplayerServer, FMultiplayerEmptyResponse, result, UObject*, customData);

    /** Shuts down a multiplayer server session. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* ShutdownMultiplayerServer(FMultiplayerShutdownMultiplayerServerRequest request,
            FDelegateOnSuccessShutdownMultiplayerServer onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperShutdownMultiplayerServer(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUntagContainerImage, FMultiplayerEmptyResponse, result, UObject*, customData);

    /** Untags a container image. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* UntagContainerImage(FMultiplayerUntagContainerImageRequest request,
            FDelegateOnSuccessUntagContainerImage onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUntagContainerImage(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateBuildAlias, FMultiplayerBuildAliasDetailsResponse, result, UObject*, customData);

    /** Creates a multiplayer server build alias. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* UpdateBuildAlias(FMultiplayerUpdateBuildAliasRequest request,
            FDelegateOnSuccessUpdateBuildAlias onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateBuildAlias(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateBuildName, FMultiplayerEmptyResponse, result, UObject*, customData);

    /** Updates a multiplayer server build's name. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* UpdateBuildName(FMultiplayerUpdateBuildNameRequest request,
            FDelegateOnSuccessUpdateBuildName onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateBuildName(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateBuildRegion, FMultiplayerEmptyResponse, result, UObject*, customData);

    /** Updates a multiplayer server build's region. If the region is not yet created, it will be created */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* UpdateBuildRegion(FMultiplayerUpdateBuildRegionRequest request,
            FDelegateOnSuccessUpdateBuildRegion onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateBuildRegion(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateBuildRegions, FMultiplayerEmptyResponse, result, UObject*, customData);

    /** Updates a multiplayer server build's regions. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* UpdateBuildRegions(FMultiplayerUpdateBuildRegionsRequest request,
            FDelegateOnSuccessUpdateBuildRegions onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateBuildRegions(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUploadCertificate, FMultiplayerEmptyResponse, result, UObject*, customData);

    /** Uploads a multiplayer server game certificate. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* UploadCertificate(FMultiplayerUploadCertificateRequest request,
            FDelegateOnSuccessUploadCertificate onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUploadCertificate(FPlayFabBaseModel response, UObject* customData, bool successful);



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
    FDelegateOnSuccessCancelAllMatchmakingTicketsForPlayer OnSuccessCancelAllMatchmakingTicketsForPlayer;
    FDelegateOnSuccessCancelAllServerBackfillTicketsForPlayer OnSuccessCancelAllServerBackfillTicketsForPlayer;
    FDelegateOnSuccessCancelMatchmakingTicket OnSuccessCancelMatchmakingTicket;
    FDelegateOnSuccessCancelServerBackfillTicket OnSuccessCancelServerBackfillTicket;
    FDelegateOnSuccessCreateMatchmakingTicket OnSuccessCreateMatchmakingTicket;
    FDelegateOnSuccessCreateServerBackfillTicket OnSuccessCreateServerBackfillTicket;
    FDelegateOnSuccessCreateServerMatchmakingTicket OnSuccessCreateServerMatchmakingTicket;
    FDelegateOnSuccessGetMatch OnSuccessGetMatch;
    FDelegateOnSuccessGetMatchmakingTicket OnSuccessGetMatchmakingTicket;
    FDelegateOnSuccessGetQueueStatistics OnSuccessGetQueueStatistics;
    FDelegateOnSuccessGetServerBackfillTicket OnSuccessGetServerBackfillTicket;
    FDelegateOnSuccessJoinMatchmakingTicket OnSuccessJoinMatchmakingTicket;
    FDelegateOnSuccessListMatchmakingTicketsForPlayer OnSuccessListMatchmakingTicketsForPlayer;
    FDelegateOnSuccessListServerBackfillTicketsForPlayer OnSuccessListServerBackfillTicketsForPlayer;
    FDelegateOnSuccessCreateBuildAlias OnSuccessCreateBuildAlias;
    FDelegateOnSuccessCreateBuildWithCustomContainer OnSuccessCreateBuildWithCustomContainer;
    FDelegateOnSuccessCreateBuildWithManagedContainer OnSuccessCreateBuildWithManagedContainer;
    FDelegateOnSuccessCreateBuildWithProcessBasedServer OnSuccessCreateBuildWithProcessBasedServer;
    FDelegateOnSuccessCreateRemoteUser OnSuccessCreateRemoteUser;
    FDelegateOnSuccessCreateTitleMultiplayerServersQuotaChange OnSuccessCreateTitleMultiplayerServersQuotaChange;
    FDelegateOnSuccessDeleteAsset OnSuccessDeleteAsset;
    FDelegateOnSuccessDeleteBuild OnSuccessDeleteBuild;
    FDelegateOnSuccessDeleteBuildAlias OnSuccessDeleteBuildAlias;
    FDelegateOnSuccessDeleteBuildRegion OnSuccessDeleteBuildRegion;
    FDelegateOnSuccessDeleteCertificate OnSuccessDeleteCertificate;
    FDelegateOnSuccessDeleteContainerImageRepository OnSuccessDeleteContainerImageRepository;
    FDelegateOnSuccessDeleteRemoteUser OnSuccessDeleteRemoteUser;
    FDelegateOnSuccessEnableMultiplayerServersForTitle OnSuccessEnableMultiplayerServersForTitle;
    FDelegateOnSuccessGetAssetDownloadUrl OnSuccessGetAssetDownloadUrl;
    FDelegateOnSuccessGetAssetUploadUrl OnSuccessGetAssetUploadUrl;
    FDelegateOnSuccessGetBuild OnSuccessGetBuild;
    FDelegateOnSuccessGetBuildAlias OnSuccessGetBuildAlias;
    FDelegateOnSuccessGetContainerRegistryCredentials OnSuccessGetContainerRegistryCredentials;
    FDelegateOnSuccessGetMultiplayerServerDetails OnSuccessGetMultiplayerServerDetails;
    FDelegateOnSuccessGetMultiplayerServerLogs OnSuccessGetMultiplayerServerLogs;
    FDelegateOnSuccessGetMultiplayerSessionLogsBySessionId OnSuccessGetMultiplayerSessionLogsBySessionId;
    FDelegateOnSuccessGetRemoteLoginEndpoint OnSuccessGetRemoteLoginEndpoint;
    FDelegateOnSuccessGetTitleEnabledForMultiplayerServersStatus OnSuccessGetTitleEnabledForMultiplayerServersStatus;
    FDelegateOnSuccessGetTitleMultiplayerServersQuotaChange OnSuccessGetTitleMultiplayerServersQuotaChange;
    FDelegateOnSuccessGetTitleMultiplayerServersQuotas OnSuccessGetTitleMultiplayerServersQuotas;
    FDelegateOnSuccessListArchivedMultiplayerServers OnSuccessListArchivedMultiplayerServers;
    FDelegateOnSuccessListAssetSummaries OnSuccessListAssetSummaries;
    FDelegateOnSuccessListBuildAliases OnSuccessListBuildAliases;
    FDelegateOnSuccessListBuildSummariesV2 OnSuccessListBuildSummariesV2;
    FDelegateOnSuccessListCertificateSummaries OnSuccessListCertificateSummaries;
    FDelegateOnSuccessListContainerImages OnSuccessListContainerImages;
    FDelegateOnSuccessListContainerImageTags OnSuccessListContainerImageTags;
    FDelegateOnSuccessListMultiplayerServers OnSuccessListMultiplayerServers;
    FDelegateOnSuccessListPartyQosServers OnSuccessListPartyQosServers;
    FDelegateOnSuccessListQosServersForTitle OnSuccessListQosServersForTitle;
    FDelegateOnSuccessListTitleMultiplayerServersQuotaChanges OnSuccessListTitleMultiplayerServersQuotaChanges;
    FDelegateOnSuccessListVirtualMachineSummaries OnSuccessListVirtualMachineSummaries;
    FDelegateOnSuccessRequestMultiplayerServer OnSuccessRequestMultiplayerServer;
    FDelegateOnSuccessRolloverContainerRegistryCredentials OnSuccessRolloverContainerRegistryCredentials;
    FDelegateOnSuccessShutdownMultiplayerServer OnSuccessShutdownMultiplayerServer;
    FDelegateOnSuccessUntagContainerImage OnSuccessUntagContainerImage;
    FDelegateOnSuccessUpdateBuildAlias OnSuccessUpdateBuildAlias;
    FDelegateOnSuccessUpdateBuildName OnSuccessUpdateBuildName;
    FDelegateOnSuccessUpdateBuildRegion OnSuccessUpdateBuildRegion;
    FDelegateOnSuccessUpdateBuildRegions OnSuccessUpdateBuildRegions;
    FDelegateOnSuccessUploadCertificate OnSuccessUploadCertificate;

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
