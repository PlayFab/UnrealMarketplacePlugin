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



    ///////////////////////////////////////////////////////
    // Matchmaking Admin
    //////////////////////////////////////////////////////



    ///////////////////////////////////////////////////////
    // MultiplayerServer
    //////////////////////////////////////////////////////

    /** Decode the CreateBuildWithCustomContainerResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerCreateBuildWithCustomContainerResponse decodeCreateBuildWithCustomContainerResponseResponse(UPlayFabJsonObject* response);

    /** Decode the CreateBuildWithManagedContainerResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerCreateBuildWithManagedContainerResponse decodeCreateBuildWithManagedContainerResponseResponse(UPlayFabJsonObject* response);

    /** Decode the CreateRemoteUserResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerCreateRemoteUserResponse decodeCreateRemoteUserResponseResponse(UPlayFabJsonObject* response);

    /** Decode the EmptyResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerEmptyResponse decodeEmptyResponseResponse(UPlayFabJsonObject* response);

    /** Decode the EnableMultiplayerServersForTitleResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerEnableMultiplayerServersForTitleResponse decodeEnableMultiplayerServersForTitleResponseResponse(UPlayFabJsonObject* response);

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

    /** Decode the GetRemoteLoginEndpointResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerGetRemoteLoginEndpointResponse decodeGetRemoteLoginEndpointResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetTitleEnabledForMultiplayerServersStatusResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerGetTitleEnabledForMultiplayerServersStatusResponse decodeGetTitleEnabledForMultiplayerServersStatusResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListAssetSummariesResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerListAssetSummariesResponse decodeListAssetSummariesResponseResponse(UPlayFabJsonObject* response);

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

    /** Decode the ListMultiplayerServersResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerListMultiplayerServersResponse decodeListMultiplayerServersResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListQosServersResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        static FMultiplayerListQosServersResponse decodeListQosServersResponseResponse(UPlayFabJsonObject* response);

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
