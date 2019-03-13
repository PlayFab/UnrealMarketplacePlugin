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


    ///////////////////////////////////////////////////////
    // Matchmaking Admin
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetMatchmakingQueue, FMultiplayerGetMatchmakingQueueResult, result, UObject*, customData);

    /** Get a matchmaking queue configuration. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking Admin ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* GetMatchmakingQueue(FMultiplayerGetMatchmakingQueueRequest request,
            FDelegateOnSuccessGetMatchmakingQueue onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking Admin ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetMatchmakingQueue(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListMatchmakingQueues, FMultiplayerListMatchmakingQueuesResult, result, UObject*, customData);

    /** List all matchmaking queue configs. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking Admin ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* ListMatchmakingQueues(FMultiplayerListMatchmakingQueuesRequest request,
            FDelegateOnSuccessListMatchmakingQueues onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking Admin ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListMatchmakingQueues(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRemoveMatchmakingQueue, FMultiplayerRemoveMatchmakingQueueResult, result, UObject*, customData);

    /** Remove a matchmaking queue config. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking Admin ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* RemoveMatchmakingQueue(FMultiplayerRemoveMatchmakingQueueRequest request,
            FDelegateOnSuccessRemoveMatchmakingQueue onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking Admin ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRemoveMatchmakingQueue(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetMatchmakingQueue, FMultiplayerSetMatchmakingQueueResult, result, UObject*, customData);

    /** Create or update a matchmaking queue configuration. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking Admin ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* SetMatchmakingQueue(FMultiplayerSetMatchmakingQueueRequest request,
            FDelegateOnSuccessSetMatchmakingQueue onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | Matchmaking Admin ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetMatchmakingQueue(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // MultiplayerServer
    //////////////////////////////////////////////////////
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
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetAssetUploadUrl, FMultiplayerGetAssetUploadUrlResponse, result, UObject*, customData);

    /** Gets the URL to upload assets to. */
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
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListBuildSummaries, FMultiplayerListBuildSummariesResponse, result, UObject*, customData);

    /** Lists summarized details of all multiplayer server builds for a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* ListBuildSummaries(FMultiplayerListBuildSummariesRequest request,
            FDelegateOnSuccessListBuildSummaries onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListBuildSummaries(FPlayFabBaseModel response, UObject* customData, bool successful);

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
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListQosServers, FMultiplayerListQosServersResponse, result, UObject*, customData);

    /** Lists quality of service servers. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMultiplayerAPI* ListQosServers(FMultiplayerListQosServersRequest request,
            FDelegateOnSuccessListQosServers onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMultiplayerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListQosServers(FPlayFabBaseModel response, UObject* customData, bool successful);

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
     * Request a multiplayer server session. Accepts tokens for title and if game client accesss is enabled, allows game client
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
    FDelegateOnSuccessCancelMatchmakingTicket OnSuccessCancelMatchmakingTicket;
    FDelegateOnSuccessCreateMatchmakingTicket OnSuccessCreateMatchmakingTicket;
    FDelegateOnSuccessCreateServerMatchmakingTicket OnSuccessCreateServerMatchmakingTicket;
    FDelegateOnSuccessGetMatch OnSuccessGetMatch;
    FDelegateOnSuccessGetMatchmakingTicket OnSuccessGetMatchmakingTicket;
    FDelegateOnSuccessGetQueueStatistics OnSuccessGetQueueStatistics;
    FDelegateOnSuccessJoinMatchmakingTicket OnSuccessJoinMatchmakingTicket;
    FDelegateOnSuccessListMatchmakingTicketsForPlayer OnSuccessListMatchmakingTicketsForPlayer;
    FDelegateOnSuccessGetMatchmakingQueue OnSuccessGetMatchmakingQueue;
    FDelegateOnSuccessListMatchmakingQueues OnSuccessListMatchmakingQueues;
    FDelegateOnSuccessRemoveMatchmakingQueue OnSuccessRemoveMatchmakingQueue;
    FDelegateOnSuccessSetMatchmakingQueue OnSuccessSetMatchmakingQueue;
    FDelegateOnSuccessCreateBuildWithCustomContainer OnSuccessCreateBuildWithCustomContainer;
    FDelegateOnSuccessCreateBuildWithManagedContainer OnSuccessCreateBuildWithManagedContainer;
    FDelegateOnSuccessCreateRemoteUser OnSuccessCreateRemoteUser;
    FDelegateOnSuccessDeleteAsset OnSuccessDeleteAsset;
    FDelegateOnSuccessDeleteBuild OnSuccessDeleteBuild;
    FDelegateOnSuccessDeleteCertificate OnSuccessDeleteCertificate;
    FDelegateOnSuccessDeleteRemoteUser OnSuccessDeleteRemoteUser;
    FDelegateOnSuccessEnableMultiplayerServersForTitle OnSuccessEnableMultiplayerServersForTitle;
    FDelegateOnSuccessGetAssetUploadUrl OnSuccessGetAssetUploadUrl;
    FDelegateOnSuccessGetBuild OnSuccessGetBuild;
    FDelegateOnSuccessGetContainerRegistryCredentials OnSuccessGetContainerRegistryCredentials;
    FDelegateOnSuccessGetMultiplayerServerDetails OnSuccessGetMultiplayerServerDetails;
    FDelegateOnSuccessGetRemoteLoginEndpoint OnSuccessGetRemoteLoginEndpoint;
    FDelegateOnSuccessGetTitleEnabledForMultiplayerServersStatus OnSuccessGetTitleEnabledForMultiplayerServersStatus;
    FDelegateOnSuccessListArchivedMultiplayerServers OnSuccessListArchivedMultiplayerServers;
    FDelegateOnSuccessListAssetSummaries OnSuccessListAssetSummaries;
    FDelegateOnSuccessListBuildSummaries OnSuccessListBuildSummaries;
    FDelegateOnSuccessListCertificateSummaries OnSuccessListCertificateSummaries;
    FDelegateOnSuccessListContainerImages OnSuccessListContainerImages;
    FDelegateOnSuccessListContainerImageTags OnSuccessListContainerImageTags;
    FDelegateOnSuccessListMultiplayerServers OnSuccessListMultiplayerServers;
    FDelegateOnSuccessListQosServers OnSuccessListQosServers;
    FDelegateOnSuccessListVirtualMachineSummaries OnSuccessListVirtualMachineSummaries;
    FDelegateOnSuccessRequestMultiplayerServer OnSuccessRequestMultiplayerServer;
    FDelegateOnSuccessRolloverContainerRegistryCredentials OnSuccessRolloverContainerRegistryCredentials;
    FDelegateOnSuccessShutdownMultiplayerServer OnSuccessShutdownMultiplayerServer;
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
