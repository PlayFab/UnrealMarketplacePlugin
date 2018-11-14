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

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateBuildWithCustomContainerRequest
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
    /** Metadata to tag the build. */
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
struct PLAYFAB_API FMultiplayerCreateBuildWithCustomContainerResponse
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

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateBuildWithManagedContainerRequest
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
    /** Metadata to tag the build. */
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
struct PLAYFAB_API FMultiplayerCreateBuildWithManagedContainerResponse
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

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerCreateRemoteUserRequest
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
struct PLAYFAB_API FMultiplayerCreateRemoteUserResponse
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

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerDeleteAssetRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The filename of the asset to delete. This must be a filename with the .zip, .tar, or .tar.gz extension. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString FileName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerEmptyResponse
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerDeleteBuildRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string build ID of the build to delete. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerDeleteCertificateRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The name of the certificate. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Name;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerDeleteRemoteUserRequest
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

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerEnableMultiplayerServersForTitleRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerEnableMultiplayerServersForTitleResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** The enabled status for the multiplayer server features for the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        ETitleMultiplayerServerEnabledStatus Status;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetAssetUploadUrlRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The asset's file name to get the upload URL for. This must be a filename with the .zip, .tar, or .tar.gz extension. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString FileName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetAssetUploadUrlResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** The asset's upload URL. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString AssetUploadUrl;
    /**
     * The asset's file name to get the upload URL for. This must be a filename will be a file with the .zip, .tar, or .tar.gz
     * extension.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString FileName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetBuildRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string build ID of the build to get. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetBuildResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string build ID of the build. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The build name. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildName;
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
    /** The metadata of the build. */
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

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetContainerRegistryCredentialsRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetContainerRegistryCredentialsResponse
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

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetMultiplayerServerDetailsRequest
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
struct PLAYFAB_API FMultiplayerGetMultiplayerServerDetailsResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** The connected players in the multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> ConnectedPlayers;
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

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetRemoteLoginEndpointRequest
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
struct PLAYFAB_API FMultiplayerGetRemoteLoginEndpointResponse
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

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetTitleEnabledForMultiplayerServersStatusRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerGetTitleEnabledForMultiplayerServersStatusResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** The enabled status for the multiplayer server features for the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        ETitleMultiplayerServerEnabledStatus Status;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListMultiplayerServersRequest
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
struct PLAYFAB_API FMultiplayerListMultiplayerServersResponse
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

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListAssetSummariesRequest
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
struct PLAYFAB_API FMultiplayerListAssetSummariesResponse
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

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListBuildSummariesRequest
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
struct PLAYFAB_API FMultiplayerListBuildSummariesResponse
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

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListCertificateSummariesRequest
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
struct PLAYFAB_API FMultiplayerListCertificateSummariesResponse
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

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListContainerImagesRequest
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
struct PLAYFAB_API FMultiplayerListContainerImagesResponse
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

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListContainerImageTagsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The container images we want to list tags for. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString ImageName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListContainerImageTagsResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of tags for a particular container image. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString Tags;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListQosServersRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListQosServersResponse
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

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerListVirtualMachineSummariesRequest
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
struct PLAYFAB_API FMultiplayerListVirtualMachineSummariesResponse
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

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerRequestMultiplayerServerRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The guid string build ID of the multiplayer server to request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString BuildId;
    /** The preferred regions to request a multiplayer server from. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString PreferredRegions;
    /**
     * Data encoded as a string that is passed to the game server when requested. This can be used to share a cryptographic
     * secret for servers to authenticate clients or to communicate information such as game mode or map through the request
     * flow.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SessionCookie;
    /** A guid string session ID created track the multiplayer server session over its life. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        FString SessionId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerRequestMultiplayerServerResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** The connected players in the multiplayer server. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        TArray<UPlayFabJsonObject*> ConnectedPlayers;
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

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerRolloverContainerRegistryCredentialsRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerRolloverContainerRegistryCredentialsResponse
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

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerShutdownMultiplayerServerRequest
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

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerUpdateBuildRegionsRequest
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

USTRUCT(BlueprintType)
struct PLAYFAB_API FMultiplayerUploadCertificateRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The game certificate to upload. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Multiplayer | MultiplayerServer Models")
        UPlayFabJsonObject* GameCertificate = nullptr;
};

