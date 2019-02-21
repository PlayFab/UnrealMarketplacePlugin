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
#include "PlayFabRequestCommon.h"
#include "PlayFabLoginResultCommon.h"
#include "PlayFabMultiplayerModels.generated.h"

class UPlayFabJsonObject;

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

/** Creates a multiplayer server build with a custom container and returns information about the build creation request. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateBuildWithCustomContainerRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The build name. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildName;
    /** The flavor of container to create a build from. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EContainerFlavor ContainerFlavor;
    /** The name of the container repository. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ContainerRepositoryName;
    /** The container command to run when the multiplayer server has been allocated, including any arguments. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ContainerRunCommand;
    /** The tag for the container. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ContainerTag;
    /** The list of game assets related to the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> GameAssetReferences;
    /** The game certificates for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> GameCertificateReferences;
    /**
     * Metadata to tag the build. The keys are case insensitive. The build metadata is made available to the server through
     * Game Server SDK (GSDK).
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* Metadata;
    /** The number of multiplayer servers to host on a single VM. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 MultiplayerServerCountPerVm = 0;
    /** The ports to map the build on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> Ports;
    /** The region configurations for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> RegionConfigurations;
    /** The VM size to create the build on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EAzureVmSize VmSize;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateBuildWithCustomContainerResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string build ID. Must be unique for every build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The build name. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildName;
    /** The flavor of container of the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EContainerFlavor ContainerFlavor;
    /** The container command to run when the multiplayer server has been allocated, including any arguments. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ContainerRunCommand;
    /** The time the build was created in UTC. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString CreationTime;
    /** The custom game container image reference information. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomGameContainerImage = nullptr;
    /** The game assets for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> GameAssetReferences;
    /** The game certificates for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> GameCertificateReferences;
    /** The metadata of the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* Metadata;
    /** The number of multiplayer servers to host on a single VM of the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 MultiplayerServerCountPerVm = 0;
    /** The ports the build is mapped on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> Ports;
    /** The region configuration for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> RegionConfigurations;
    /** The VM size the build was created on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EAzureVmSize VmSize;
};

/** Creates a multiplayer server build with a managed container and returns information about the build creation request. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateBuildWithManagedContainerRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The build name. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildName;
    /** The flavor of container to create a build from. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EContainerFlavor ContainerFlavor;
    /** The list of game assets related to the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> GameAssetReferences;
    /** The game certificates for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> GameCertificateReferences;
    /**
     * Metadata to tag the build. The keys are case insensitive. The build metadata is made available to the server through
     * Game Server SDK (GSDK).
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* Metadata;
    /** The number of multiplayer servers to host on a single VM. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 MultiplayerServerCountPerVm = 0;
    /** The ports to map the build on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> Ports;
    /** The region configurations for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> RegionConfigurations;
    /** The command to run when the multiplayer server is started, including any arguments. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString StartMultiplayerServerCommand;
    /** The VM size to create the build on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EAzureVmSize VmSize;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateBuildWithManagedContainerResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string build ID. Must be unique for every build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The build name. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildName;
    /** The flavor of container of the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EContainerFlavor ContainerFlavor;
    /** The time the build was created in UTC. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString CreationTime;
    /** The game assets for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> GameAssetReferences;
    /** The game certificates for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> GameCertificateReferences;
    /** The metadata of the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* Metadata;
    /** The number of multiplayer servers to host on a single VM of the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 MultiplayerServerCountPerVm = 0;
    /** The ports the build is mapped on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> Ports;
    /** The region configuration for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> RegionConfigurations;
    /** The command to run when the multiplayer server has been allocated, including any arguments. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString StartMultiplayerServerCommand;
    /** The VM size the build was created on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EAzureVmSize VmSize;
};

/**
 * Creates a remote user to log on to a VM for a multiplayer server build in a specific region. Returns user credential
 * information necessary to log on.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateRemoteUserRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string build ID of to create the remote user for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The expiration time for the remote user created. Defaults to expiring in one day if not specified. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ExpirationTime;
    /** The region of virtual machine to create the remote user for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EAzureRegion Region;
    /** The username to create the remote user with. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Username;
    /** The virtual machine ID the multiplayer server is located on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString VmId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateRemoteUserResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The expiration time for the remote user created. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ExpirationTime;
    /** The generated password for the remote user that was created. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Password;
    /** The username for the remote user that was created. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Username;
};

/** Deletes a multiplayer server game asset for a title. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerDeleteAssetRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The filename of the asset to delete. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString FileName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerEmptyResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/** Deletes a multiplayer server build. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerDeleteBuildRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string build ID of the build to delete. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
};

/** Deletes a multiplayer server game certificate. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerDeleteCertificateRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The name of the certificate. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Name;
};

/**
 * Deletes a remote user to log on to a VM for a multiplayer server build in a specific region. Returns user credential
 * information necessary to log on.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerDeleteRemoteUserRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string build ID of the multiplayer server where the remote user is to delete. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The region of the multiplayer server where the remote user is to delete. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EAzureRegion Region;
    /** The username of the remote user to delete. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Username;
    /** The virtual machine ID the multiplayer server is located on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString VmId;
};

/**
 * Enables the multiplayer server feature for a title and returns the enabled status. The enabled status can be
 * Initializing, Enabled, and Disabled. It can up to 20 minutes or more for the title to be enabled for the feature. On
 * average, it can take up to 20 minutes for the title to be enabled for the feature.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerEnableMultiplayerServersForTitleRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerEnableMultiplayerServersForTitleResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The enabled status for the multiplayer server features for the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        ETitleMultiplayerServerEnabledStatus Status;
};

/** Gets the URL to upload assets to. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetAssetUploadUrlRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The asset's file name to get the upload URL for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString FileName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetAssetUploadUrlResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The asset's upload URL. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString AssetUploadUrl;
    /** The asset's file name to get the upload URL for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString FileName;
};

/** Returns the details about a multiplayer server build. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetBuildRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string build ID of the build to get. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetBuildResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string build ID of the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The build name. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildName;
    /** The current build status. Valid values are - Deploying, Deployed, DeletingRegion, Unhealthy. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildStatus;
    /** The flavor of container of he build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EContainerFlavor ContainerFlavor;
    /**
     * The container command to run when the multiplayer server has been allocated, including any arguments. This only applies
     * to custom builds. If the build is a managed build, this field will be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ContainerRunCommand;
    /** The time the build was created in UTC. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString CreationTime;
    /** The custom game container image for a custom build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* CustomGameContainerImage = nullptr;
    /** The game assets for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> GameAssetReferences;
    /** The game certificates for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> GameCertificateReferences;
    /**
     * Metadata of the build. The keys are case insensitive. The build metadata is made available to the server through Game
     * Server SDK (GSDK).
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* Metadata;
    /** The number of multiplayer servers to hosted on a single VM of the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 MultiplayerServerCountPerVm = 0;
    /** The ports the build is mapped on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> Ports;
    /** The region configuration for the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> RegionConfigurations;
    /**
     * The command to run when the multiplayer server has been allocated, including any arguments. This only applies to managed
     * builds. If the build is a custom build, this field will be null.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString StartMultiplayerServerCommand;
    /** The VM size the build was created on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EAzureVmSize VmSize;
};

/**
 * Gets credentials to the container registry where game developers can upload custom container images to before creating a
 * new build.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetContainerRegistryCredentialsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetContainerRegistryCredentialsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The url of the container registry. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString DnsName;
    /** The password for accessing the container registry. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Password;
    /** The username for accessing the container registry. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Username;
};

/** Gets multiplayer server session details for a build in a specific region. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetMultiplayerServerDetailsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string build ID of the multiplayer server to get details for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The region the multiplayer server is located in to get details for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EAzureRegion Region;
    /**
     * The title generated guid string session ID of the multiplayer server to get details for. This is to keep track of
     * multiplayer server sessions.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SessionId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetMultiplayerServerDetailsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The connected players in the multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> ConnectedPlayers;
    /** The fully qualified domain name of the virtual machine that is hosting this multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString FQDN;
    /** The IPv4 address of the virtual machine that is hosting this multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString IPV4Address;
    /** The time (UTC) at which a change in the multiplayer server state was observed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString LastStateTransitionTime;
    /** The ports the multiplayer server uses. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> Ports;
    /** The region the multiplayer server is located in. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EAzureRegion Region;
    /** The string server ID of the multiplayer server generated by PlayFab. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ServerId;
    /** The guid string session ID of the multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SessionId;
    /** The state of the multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString State;
    /** The virtual machine ID that the multiplayer server is located on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString VmId;
};

/** Gets a remote login endpoint to a VM that is hosting a multiplayer server build in a specific region. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetRemoteLoginEndpointRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string build ID of the multiplayer server to get remote login information for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The region of the multiplayer server to get remote login information for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EAzureRegion Region;
    /** The virtual machine ID the multiplayer server is located on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString VmId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetRemoteLoginEndpointResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The remote login IPV4 address of multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString IPV4Address;
    /** The remote login port of multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 Port = 0;
};

/**
 * Gets the status of whether a title is enabled for the multiplayer server feature. The enabled status can be
 * Initializing, Enabled, and Disabled.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetTitleEnabledForMultiplayerServersStatusRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetTitleEnabledForMultiplayerServersStatusResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The enabled status for the multiplayer server features for the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        ETitleMultiplayerServerEnabledStatus Status;
};

/** Returns a list of multiplayer servers for a build in a specific region. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListMultiplayerServersRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string build ID of the multiplayer servers to list. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The page size for the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The region the multiplayer servers to list. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EAzureRegion Region;
    /** The skip token for the paged request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListMultiplayerServersResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of multiplayer server summary details. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> MultiplayerServerSummaries;
    /** The page size on the response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The skip token for the paged response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

/** Returns a list of multiplayer server game asset summaries for a title. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListAssetSummariesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The page size for the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The skip token for the paged request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListAssetSummariesResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of asset summaries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> AssetSummaries;
    /** The page size on the response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The skip token for the paged response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

/** Returns a list of summarized details of all multiplayer server builds for a title. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListBuildSummariesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The page size for the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The skip token for the paged request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListBuildSummariesResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of build summaries for a title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> BuildSummaries;
    /** The page size on the response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The skip token for the paged response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

/** Returns a list of multiplayer server game certificates for a title. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListCertificateSummariesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The page size for the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The skip token for the paged request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListCertificateSummariesResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of game certificates. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> CertificateSummaries;
    /** The page size on the response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The skip token for the paged response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

/** Returns a list of the container images that have been uploaded to the container registry for a title. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListContainerImagesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The page size for the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The skip token for the paged request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListContainerImagesResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of container images. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Images;
    /** The page size on the response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The skip token for the paged response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

/** Returns a list of the tags for a particular container image that exists in the container registry for a title. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListContainerImageTagsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The container images we want to list tags for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ImageName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListContainerImageTagsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of tags for a particular container image. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Tags;
};

/** Returns a list of quality of service servers. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListQosServersRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListQosServersResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The page size on the response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The list of QoS servers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> QosServers;
    /** The skip token for the paged response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

/** Returns a list of virtual machines for a title. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListVirtualMachineSummariesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string build ID of the virtual machines to list. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The page size for the request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The region of the virtual machines to list. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EAzureRegion Region;
    /** The skip token for the paged request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListVirtualMachineSummariesResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The page size on the response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        int32 PageSize = 0;
    /** The skip token for the paged response. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SkipToken;
    /** The list of virtual machine summaries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> VirtualMachines;
};

/** Requests a multiplayer server session from a particular build in any of the given preferred regions. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerRequestMultiplayerServerRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string build ID of the multiplayer server to request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /**
     * Initial list of players (potentially matchmade) allowed to connect to the game. This list is passed to the game server
     * when requested (via GSDK) and can be used to validate players connecting to it.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString InitialPlayers;
    /**
     * The preferred regions to request a multiplayer server from. The Multiplayer Service will iterate through the regions in
     * the specified order and allocate a server from the first one that has servers available.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString PreferredRegions;
    /**
     * Data encoded as a string that is passed to the game server when requested. This can be used to to communicate
     * information such as game mode or map through the request flow.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SessionCookie;
    /** A guid string session ID created track the multiplayer server session over its life. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SessionId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerRequestMultiplayerServerResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The connected players in the multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> ConnectedPlayers;
    /** The fully qualified domain name of the virtual machine that is hosting this multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString FQDN;
    /** The IPv4 address of the virtual machine that is hosting this multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString IPV4Address;
    /** The time (UTC) at which a change in the multiplayer server state was observed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString LastStateTransitionTime;
    /** The ports the multiplayer server uses. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> Ports;
    /** The region the multiplayer server is located in. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EAzureRegion Region;
    /** The string server ID of the multiplayer server generated by PlayFab. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ServerId;
    /** The guid string session ID of the multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SessionId;
    /** The state of the multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString State;
    /** The virtual machine ID that the multiplayer server is located on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString VmId;
};

/**
 * Gets new credentials to the container registry where game developers can upload custom container images to before
 * creating a new build.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerRolloverContainerRegistryCredentialsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerRolloverContainerRegistryCredentialsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The url of the container registry. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString DnsName;
    /** The password for accessing the container registry. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Password;
    /** The username for accessing the container registry. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Username;
};

/**
 * Executes the shutdown callback from the GSDK and terminates the multiplayer server session. The callback in the GSDK
 * will allow for graceful shutdown with a 15 minute timeoutIf graceful shutdown has not been completed before 15 minutes
 * have elapsed, the multiplayer server session will be forcefully terminated on it's own.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerShutdownMultiplayerServerRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string build ID of the multiplayer server to delete. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The region of the multiplayer server to shut down. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        EAzureRegion Region;
    /** A guid string session ID of the multiplayer server to shut down. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SessionId;
};

/** Updates a multiplayer server build's regions. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerUpdateBuildRegionsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string ID of the build we want to update regions for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The updated region configuration that should be applied to the specified build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> BuildRegions;
};

/** Uploads a multiplayer server game certificate. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerUploadCertificateRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The game certificate to upload. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* GameCertificate = nullptr;
};

