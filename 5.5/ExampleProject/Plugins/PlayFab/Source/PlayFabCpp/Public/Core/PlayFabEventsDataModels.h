//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabCppBaseModel.h"

namespace PlayFab
{
namespace EventsModels
{

    struct PLAYFABCPP_API FEntityKey : public PlayFab::FPlayFabCppBaseModel
    {
        // Unique ID of the entity.
        FString Id;

        // [optional] Entity type. See https://docs.microsoft.com/gaming/playfab/features/data/entities/available-built-in-entity-types
        FString Type;

        FEntityKey() :
            FPlayFabCppBaseModel(),
            Id(),
            Type()
            {}

        FEntityKey(const FEntityKey& src) = default;

        FEntityKey(const TSharedPtr<FJsonObject>& obj) : FEntityKey()
        {
            readFromValue(obj);
        }

        ~FEntityKey();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FCreateTelemetryKeyRequest : public PlayFab::FPlayFabCppRequestCommon
    {
        // [optional] The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.).
        TMap<FString, FString> CustomTags;
        // [optional] The optional entity to perform this action on. Defaults to the currently logged in entity.
        TSharedPtr<FEntityKey> Entity;

        // The name of the new key. Telemetry key names must be unique within the scope of the title.
        FString KeyName;

        FCreateTelemetryKeyRequest() :
            FPlayFabCppRequestCommon(),
            CustomTags(),
            Entity(nullptr),
            KeyName()
            {}

        FCreateTelemetryKeyRequest(const FCreateTelemetryKeyRequest& src) = default;

        FCreateTelemetryKeyRequest(const TSharedPtr<FJsonObject>& obj) : FCreateTelemetryKeyRequest()
        {
            readFromValue(obj);
        }

        ~FCreateTelemetryKeyRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FTelemetryKeyDetails : public PlayFab::FPlayFabCppBaseModel
    {
        // When the key was created.
        FDateTime CreateTime;

        // Whether or not the key is currently active. Deactivated keys cannot be used for telemetry ingestion.
        bool IsActive;

        // [optional] The key that can be distributed to clients for use during telemetry ingestion.
        FString KeyValue;

        // When the key was last updated.
        FDateTime LastUpdateTime;

        // [optional] The name of the key. Telemetry key names are unique within the scope of the title.
        FString Name;

        FTelemetryKeyDetails() :
            FPlayFabCppBaseModel(),
            CreateTime(0),
            IsActive(false),
            KeyValue(),
            LastUpdateTime(0),
            Name()
            {}

        FTelemetryKeyDetails(const FTelemetryKeyDetails& src) = default;

        FTelemetryKeyDetails(const TSharedPtr<FJsonObject>& obj) : FTelemetryKeyDetails()
        {
            readFromValue(obj);
        }

        ~FTelemetryKeyDetails();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FCreateTelemetryKeyResponse : public PlayFab::FPlayFabCppResultCommon
    {
        // [optional] Details about the newly created telemetry key.
        TSharedPtr<FTelemetryKeyDetails> NewKeyDetails;

        FCreateTelemetryKeyResponse() :
            FPlayFabCppResultCommon(),
            NewKeyDetails(nullptr)
            {}

        FCreateTelemetryKeyResponse(const FCreateTelemetryKeyResponse& src) = default;

        FCreateTelemetryKeyResponse(const TSharedPtr<FJsonObject>& obj) : FCreateTelemetryKeyResponse()
        {
            readFromValue(obj);
        }

        ~FCreateTelemetryKeyResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FDataConnectionAzureBlobSettings : public PlayFab::FPlayFabCppBaseModel
    {
        // [optional] Name of the storage account.
        FString AccountName;

        // [optional] Name of the container.
        FString ContainerName;

        // [optional] Azure Entra Tenant Id.
        FString TenantId;

        FDataConnectionAzureBlobSettings() :
            FPlayFabCppBaseModel(),
            AccountName(),
            ContainerName(),
            TenantId()
            {}

        FDataConnectionAzureBlobSettings(const FDataConnectionAzureBlobSettings& src) = default;

        FDataConnectionAzureBlobSettings(const TSharedPtr<FJsonObject>& obj) : FDataConnectionAzureBlobSettings()
        {
            readFromValue(obj);
        }

        ~FDataConnectionAzureBlobSettings();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FDataConnectionAzureDataExplorerSettings : public PlayFab::FPlayFabCppBaseModel
    {
        // [optional] The URI of the ADX cluster.
        FString ClusterUri;

        // [optional] The database to write to.
        FString Database;

        // [optional] The table to write to.
        FString Table;

        FDataConnectionAzureDataExplorerSettings() :
            FPlayFabCppBaseModel(),
            ClusterUri(),
            Database(),
            Table()
            {}

        FDataConnectionAzureDataExplorerSettings(const FDataConnectionAzureDataExplorerSettings& src) = default;

        FDataConnectionAzureDataExplorerSettings(const TSharedPtr<FJsonObject>& obj) : FDataConnectionAzureDataExplorerSettings()
        {
            readFromValue(obj);
        }

        ~FDataConnectionAzureDataExplorerSettings();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FDataConnectionFabricKQLSettings : public PlayFab::FPlayFabCppBaseModel
    {
        // [optional] The URI of the Fabric cluster.
        FString ClusterUri;

        // [optional] The database to write to.
        FString Database;

        // [optional] The table to write to.
        FString Table;

        FDataConnectionFabricKQLSettings() :
            FPlayFabCppBaseModel(),
            ClusterUri(),
            Database(),
            Table()
            {}

        FDataConnectionFabricKQLSettings(const FDataConnectionFabricKQLSettings& src) = default;

        FDataConnectionFabricKQLSettings(const TSharedPtr<FJsonObject>& obj) : FDataConnectionFabricKQLSettings()
        {
            readFromValue(obj);
        }

        ~FDataConnectionFabricKQLSettings();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FDataConnectionSettings : public PlayFab::FPlayFabCppBaseModel
    {
        // [optional] Settings if the type of connection is AzureBlobStorage.
        TSharedPtr<FDataConnectionAzureBlobSettings> AzureBlobSettings;

        // [optional] Settings if the type of connection is AzureDataExplorer.
        TSharedPtr<FDataConnectionAzureDataExplorerSettings> AzureDataExplorerSettings;

        // [optional] Settings if the type of connection is FabricKQL.
        TSharedPtr<FDataConnectionFabricKQLSettings> AzureFabricKQLSettings;

        FDataConnectionSettings() :
            FPlayFabCppBaseModel(),
            AzureBlobSettings(nullptr),
            AzureDataExplorerSettings(nullptr),
            AzureFabricKQLSettings(nullptr)
            {}

        FDataConnectionSettings(const FDataConnectionSettings& src) = default;

        FDataConnectionSettings(const TSharedPtr<FJsonObject>& obj) : FDataConnectionSettings()
        {
            readFromValue(obj);
        }

        ~FDataConnectionSettings();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    enum DataConnectionErrorState
    {
        DataConnectionErrorStateOK,
        DataConnectionErrorStateError
    };

    PLAYFABCPP_API void writeDataConnectionErrorStateEnumJSON(DataConnectionErrorState enumVal, JsonWriter& writer);
    PLAYFABCPP_API DataConnectionErrorState readDataConnectionErrorStateFromValue(const TSharedPtr<FJsonValue>& value);
    PLAYFABCPP_API DataConnectionErrorState readDataConnectionErrorStateFromValue(const FString& value);

    struct PLAYFABCPP_API FDataConnectionStatusDetails : public PlayFab::FPlayFabCppBaseModel
    {
        // [optional] The name of the error affecting the data connection, if any.
        FString Error;

        // [optional] A description of the error affecting the data connection, if any. This may be empty for some errors.
        FString ErrorMessage;

        // [optional] The most recent time of the error affecting the data connection, if any.
        Boxed<FDateTime> MostRecentErrorTime;

        // [optional] Indicates if the connection is in a normal state or error state.
        Boxed<DataConnectionErrorState> State;

        FDataConnectionStatusDetails() :
            FPlayFabCppBaseModel(),
            Error(),
            ErrorMessage(),
            MostRecentErrorTime(),
            State()
            {}

        FDataConnectionStatusDetails(const FDataConnectionStatusDetails& src) = default;

        FDataConnectionStatusDetails(const TSharedPtr<FJsonObject>& obj) : FDataConnectionStatusDetails()
        {
            readFromValue(obj);
        }

        ~FDataConnectionStatusDetails();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    enum DataConnectionType
    {
        DataConnectionTypeAzureBlobStorage,
        DataConnectionTypeAzureDataExplorer,
        DataConnectionTypeFabricKQL
    };

    PLAYFABCPP_API void writeDataConnectionTypeEnumJSON(DataConnectionType enumVal, JsonWriter& writer);
    PLAYFABCPP_API DataConnectionType readDataConnectionTypeFromValue(const TSharedPtr<FJsonValue>& value);
    PLAYFABCPP_API DataConnectionType readDataConnectionTypeFromValue(const FString& value);

    struct PLAYFABCPP_API FDataConnectionDetails : public PlayFab::FPlayFabCppBaseModel
    {
        // Settings of the data connection.
        FDataConnectionSettings ConnectionSettings;

        // Whether or not the connection is currently active.
        bool IsActive;

        // The name of the data connection.
        FString Name;

        // [optional] Current status of the data connection, if any.
        TSharedPtr<FDataConnectionStatusDetails> Status;

        // The type of data connection.
        DataConnectionType Type;

        FDataConnectionDetails() :
            FPlayFabCppBaseModel(),
            ConnectionSettings(),
            IsActive(false),
            Name(),
            Status(nullptr),
            Type()
            {}

        FDataConnectionDetails(const FDataConnectionDetails& src) = default;

        FDataConnectionDetails(const TSharedPtr<FJsonObject>& obj) : FDataConnectionDetails()
        {
            readFromValue(obj);
        }

        ~FDataConnectionDetails();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FDeleteDataConnectionRequest : public PlayFab::FPlayFabCppRequestCommon
    {
        // [optional] The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.).
        TMap<FString, FString> CustomTags;
        // The name of the data connection to delete.
        FString Name;

        FDeleteDataConnectionRequest() :
            FPlayFabCppRequestCommon(),
            CustomTags(),
            Name()
            {}

        FDeleteDataConnectionRequest(const FDeleteDataConnectionRequest& src) = default;

        FDeleteDataConnectionRequest(const TSharedPtr<FJsonObject>& obj) : FDeleteDataConnectionRequest()
        {
            readFromValue(obj);
        }

        ~FDeleteDataConnectionRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FDeleteDataConnectionResponse : public PlayFab::FPlayFabCppResultCommon
    {
        // Indicates whether or not the connection was deleted as part of the request.
        bool WasDeleted;

        FDeleteDataConnectionResponse() :
            FPlayFabCppResultCommon(),
            WasDeleted(false)
            {}

        FDeleteDataConnectionResponse(const FDeleteDataConnectionResponse& src) = default;

        FDeleteDataConnectionResponse(const TSharedPtr<FJsonObject>& obj) : FDeleteDataConnectionResponse()
        {
            readFromValue(obj);
        }

        ~FDeleteDataConnectionResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FDeleteTelemetryKeyRequest : public PlayFab::FPlayFabCppRequestCommon
    {
        // [optional] The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.).
        TMap<FString, FString> CustomTags;
        // [optional] The optional entity to perform this action on. Defaults to the currently logged in entity.
        TSharedPtr<FEntityKey> Entity;

        // The name of the key to delete.
        FString KeyName;

        FDeleteTelemetryKeyRequest() :
            FPlayFabCppRequestCommon(),
            CustomTags(),
            Entity(nullptr),
            KeyName()
            {}

        FDeleteTelemetryKeyRequest(const FDeleteTelemetryKeyRequest& src) = default;

        FDeleteTelemetryKeyRequest(const TSharedPtr<FJsonObject>& obj) : FDeleteTelemetryKeyRequest()
        {
            readFromValue(obj);
        }

        ~FDeleteTelemetryKeyRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FDeleteTelemetryKeyResponse : public PlayFab::FPlayFabCppResultCommon
    {
        // Indicates whether or not the key was deleted. If false, no key with that name existed.
        bool WasKeyDeleted;

        FDeleteTelemetryKeyResponse() :
            FPlayFabCppResultCommon(),
            WasKeyDeleted(false)
            {}

        FDeleteTelemetryKeyResponse(const FDeleteTelemetryKeyResponse& src) = default;

        FDeleteTelemetryKeyResponse(const TSharedPtr<FJsonObject>& obj) : FDeleteTelemetryKeyResponse()
        {
            readFromValue(obj);
        }

        ~FDeleteTelemetryKeyResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FEventContents : public PlayFab::FPlayFabCppBaseModel
    {
        /**
         * [optional] The optional custom tags associated with the event (e.g. build number, external trace identifiers, etc.). Before an
         * event is written, this collection and the base request custom tags will be merged, but not overriden. This enables the
         * caller to specify static tags and per event tags.
         */
        TMap<FString, FString> CustomTags;
        // [optional] Entity associated with the event. If null, the event will apply to the calling entity.
        TSharedPtr<FEntityKey> Entity;

        // The namespace in which the event is defined. Allowed namespaces can vary by API.
        FString EventNamespace;

        // The name of this event.
        FString Name;

        /**
         * [optional] The original unique identifier associated with this event before it was posted to PlayFab. The value might differ from
         * the EventId value, which is assigned when the event is received by the server.
         */
        FString OriginalId;

        /**
         * [optional] The time (in UTC) associated with this event when it occurred. If specified, this value is stored in the
         * OriginalTimestamp property of the PlayStream event.
         */
        Boxed<FDateTime> OriginalTimestamp;

        // [optional] Arbitrary data associated with the event. Only one of Payload or PayloadJSON is allowed.
        FJsonKeeper Payload;

        /**
         * [optional] Arbitrary data associated with the event, represented as a JSON serialized string. Only one of Payload or PayloadJSON is
         * allowed.
         */
        FString PayloadJSON;

        FEventContents() :
            FPlayFabCppBaseModel(),
            CustomTags(),
            Entity(nullptr),
            EventNamespace(),
            Name(),
            OriginalId(),
            OriginalTimestamp(),
            Payload(),
            PayloadJSON()
            {}

        FEventContents(const FEventContents& src) = default;

        FEventContents(const TSharedPtr<FJsonObject>& obj) : FEventContents()
        {
            readFromValue(obj);
        }

        ~FEventContents();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FGetDataConnectionRequest : public PlayFab::FPlayFabCppRequestCommon
    {
        // [optional] The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.).
        TMap<FString, FString> CustomTags;
        // The name of the data connection to retrieve.
        FString Name;

        FGetDataConnectionRequest() :
            FPlayFabCppRequestCommon(),
            CustomTags(),
            Name()
            {}

        FGetDataConnectionRequest(const FGetDataConnectionRequest& src) = default;

        FGetDataConnectionRequest(const TSharedPtr<FJsonObject>& obj) : FGetDataConnectionRequest()
        {
            readFromValue(obj);
        }

        ~FGetDataConnectionRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FGetDataConnectionResponse : public PlayFab::FPlayFabCppResultCommon
    {
        // [optional] The details of the queried Data Connection.
        TSharedPtr<FDataConnectionDetails> DataConnection;

        FGetDataConnectionResponse() :
            FPlayFabCppResultCommon(),
            DataConnection(nullptr)
            {}

        FGetDataConnectionResponse(const FGetDataConnectionResponse& src) = default;

        FGetDataConnectionResponse(const TSharedPtr<FJsonObject>& obj) : FGetDataConnectionResponse()
        {
            readFromValue(obj);
        }

        ~FGetDataConnectionResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FGetTelemetryKeyRequest : public PlayFab::FPlayFabCppRequestCommon
    {
        // [optional] The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.).
        TMap<FString, FString> CustomTags;
        // [optional] The optional entity to perform this action on. Defaults to the currently logged in entity.
        TSharedPtr<FEntityKey> Entity;

        // The name of the key to retrieve.
        FString KeyName;

        FGetTelemetryKeyRequest() :
            FPlayFabCppRequestCommon(),
            CustomTags(),
            Entity(nullptr),
            KeyName()
            {}

        FGetTelemetryKeyRequest(const FGetTelemetryKeyRequest& src) = default;

        FGetTelemetryKeyRequest(const TSharedPtr<FJsonObject>& obj) : FGetTelemetryKeyRequest()
        {
            readFromValue(obj);
        }

        ~FGetTelemetryKeyRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FGetTelemetryKeyResponse : public PlayFab::FPlayFabCppResultCommon
    {
        // [optional] Details about the requested telemetry key.
        TSharedPtr<FTelemetryKeyDetails> KeyDetails;

        FGetTelemetryKeyResponse() :
            FPlayFabCppResultCommon(),
            KeyDetails(nullptr)
            {}

        FGetTelemetryKeyResponse(const FGetTelemetryKeyResponse& src) = default;

        FGetTelemetryKeyResponse(const TSharedPtr<FJsonObject>& obj) : FGetTelemetryKeyResponse()
        {
            readFromValue(obj);
        }

        ~FGetTelemetryKeyResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FListDataConnectionsRequest : public PlayFab::FPlayFabCppRequestCommon
    {
        // [optional] The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.).
        TMap<FString, FString> CustomTags;
        FListDataConnectionsRequest() :
            FPlayFabCppRequestCommon(),
            CustomTags()
            {}

        FListDataConnectionsRequest(const FListDataConnectionsRequest& src) = default;

        FListDataConnectionsRequest(const TSharedPtr<FJsonObject>& obj) : FListDataConnectionsRequest()
        {
            readFromValue(obj);
        }

        ~FListDataConnectionsRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FListDataConnectionsResponse : public PlayFab::FPlayFabCppResultCommon
    {
        // [optional] The list of existing Data Connections.
        TArray<FDataConnectionDetails> DataConnections;
        FListDataConnectionsResponse() :
            FPlayFabCppResultCommon(),
            DataConnections()
            {}

        FListDataConnectionsResponse(const FListDataConnectionsResponse& src) = default;

        FListDataConnectionsResponse(const TSharedPtr<FJsonObject>& obj) : FListDataConnectionsResponse()
        {
            readFromValue(obj);
        }

        ~FListDataConnectionsResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FListTelemetryKeysRequest : public PlayFab::FPlayFabCppRequestCommon
    {
        // [optional] The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.).
        TMap<FString, FString> CustomTags;
        // [optional] The optional entity to perform this action on. Defaults to the currently logged in entity.
        TSharedPtr<FEntityKey> Entity;

        FListTelemetryKeysRequest() :
            FPlayFabCppRequestCommon(),
            CustomTags(),
            Entity(nullptr)
            {}

        FListTelemetryKeysRequest(const FListTelemetryKeysRequest& src) = default;

        FListTelemetryKeysRequest(const TSharedPtr<FJsonObject>& obj) : FListTelemetryKeysRequest()
        {
            readFromValue(obj);
        }

        ~FListTelemetryKeysRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FListTelemetryKeysResponse : public PlayFab::FPlayFabCppResultCommon
    {
        // [optional] The telemetry keys configured for the title.
        TArray<FTelemetryKeyDetails> KeyDetails;
        FListTelemetryKeysResponse() :
            FPlayFabCppResultCommon(),
            KeyDetails()
            {}

        FListTelemetryKeysResponse(const FListTelemetryKeysResponse& src) = default;

        FListTelemetryKeysResponse(const TSharedPtr<FJsonObject>& obj) : FListTelemetryKeysResponse()
        {
            readFromValue(obj);
        }

        ~FListTelemetryKeysResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FSetDataConnectionActiveRequest : public PlayFab::FPlayFabCppRequestCommon
    {
        // Whether to set the data connection to active (true) or deactivated (false).
        bool Active;

        // [optional] The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.).
        TMap<FString, FString> CustomTags;
        // The name of the data connection to update.
        FString Name;

        FSetDataConnectionActiveRequest() :
            FPlayFabCppRequestCommon(),
            Active(false),
            CustomTags(),
            Name()
            {}

        FSetDataConnectionActiveRequest(const FSetDataConnectionActiveRequest& src) = default;

        FSetDataConnectionActiveRequest(const TSharedPtr<FJsonObject>& obj) : FSetDataConnectionActiveRequest()
        {
            readFromValue(obj);
        }

        ~FSetDataConnectionActiveRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FSetDataConnectionActiveResponse : public PlayFab::FPlayFabCppResultCommon
    {
        // [optional] The most current details about the data connection that was to be updated.
        TSharedPtr<FDataConnectionDetails> DataConnection;

        /**
         * Indicates whether or not the data connection was updated. If false, the data connection was already in the desired
         * state.
         */
        bool WasUpdated;

        FSetDataConnectionActiveResponse() :
            FPlayFabCppResultCommon(),
            DataConnection(nullptr),
            WasUpdated(false)
            {}

        FSetDataConnectionActiveResponse(const FSetDataConnectionActiveResponse& src) = default;

        FSetDataConnectionActiveResponse(const TSharedPtr<FJsonObject>& obj) : FSetDataConnectionActiveResponse()
        {
            readFromValue(obj);
        }

        ~FSetDataConnectionActiveResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FSetDataConnectionRequest : public PlayFab::FPlayFabCppRequestCommon
    {
        // Settings of the data connection.
        FDataConnectionSettings ConnectionSettings;

        // [optional] The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.).
        TMap<FString, FString> CustomTags;
        // Whether or not the connection is currently active.
        bool IsActive;

        // The name of the data connection to update or create.
        FString Name;

        // The type of data connection.
        DataConnectionType Type;

        FSetDataConnectionRequest() :
            FPlayFabCppRequestCommon(),
            ConnectionSettings(),
            CustomTags(),
            IsActive(false),
            Name(),
            Type()
            {}

        FSetDataConnectionRequest(const FSetDataConnectionRequest& src) = default;

        FSetDataConnectionRequest(const TSharedPtr<FJsonObject>& obj) : FSetDataConnectionRequest()
        {
            readFromValue(obj);
        }

        ~FSetDataConnectionRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FSetDataConnectionResponse : public PlayFab::FPlayFabCppResultCommon
    {
        // [optional] The details of the Data Connection to be created or updated.
        TSharedPtr<FDataConnectionDetails> DataConnection;

        FSetDataConnectionResponse() :
            FPlayFabCppResultCommon(),
            DataConnection(nullptr)
            {}

        FSetDataConnectionResponse(const FSetDataConnectionResponse& src) = default;

        FSetDataConnectionResponse(const TSharedPtr<FJsonObject>& obj) : FSetDataConnectionResponse()
        {
            readFromValue(obj);
        }

        ~FSetDataConnectionResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FSetTelemetryKeyActiveRequest : public PlayFab::FPlayFabCppRequestCommon
    {
        // Whether to set the key to active (true) or deactivated (false).
        bool Active;

        // [optional] The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.).
        TMap<FString, FString> CustomTags;
        // [optional] The optional entity to perform this action on. Defaults to the currently logged in entity.
        TSharedPtr<FEntityKey> Entity;

        // The name of the key to update.
        FString KeyName;

        FSetTelemetryKeyActiveRequest() :
            FPlayFabCppRequestCommon(),
            Active(false),
            CustomTags(),
            Entity(nullptr),
            KeyName()
            {}

        FSetTelemetryKeyActiveRequest(const FSetTelemetryKeyActiveRequest& src) = default;

        FSetTelemetryKeyActiveRequest(const TSharedPtr<FJsonObject>& obj) : FSetTelemetryKeyActiveRequest()
        {
            readFromValue(obj);
        }

        ~FSetTelemetryKeyActiveRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FSetTelemetryKeyActiveResponse : public PlayFab::FPlayFabCppResultCommon
    {
        // [optional] The most current details about the telemetry key that was to be updated.
        TSharedPtr<FTelemetryKeyDetails> KeyDetails;

        // Indicates whether or not the key was updated. If false, the key was already in the desired state.
        bool WasKeyUpdated;

        FSetTelemetryKeyActiveResponse() :
            FPlayFabCppResultCommon(),
            KeyDetails(nullptr),
            WasKeyUpdated(false)
            {}

        FSetTelemetryKeyActiveResponse(const FSetTelemetryKeyActiveResponse& src) = default;

        FSetTelemetryKeyActiveResponse(const TSharedPtr<FJsonObject>& obj) : FSetTelemetryKeyActiveResponse()
        {
            readFromValue(obj);
        }

        ~FSetTelemetryKeyActiveResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FWriteEventsRequest : public PlayFab::FPlayFabCppRequestCommon
    {
        // [optional] The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.).
        TMap<FString, FString> CustomTags;
        // The collection of events to write. Up to 200 events can be written per request.
        TArray<FEventContents> Events;
        FWriteEventsRequest() :
            FPlayFabCppRequestCommon(),
            CustomTags(),
            Events()
            {}

        FWriteEventsRequest(const FWriteEventsRequest& src) = default;

        FWriteEventsRequest(const TSharedPtr<FJsonObject>& obj) : FWriteEventsRequest()
        {
            readFromValue(obj);
        }

        ~FWriteEventsRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FWriteEventsResponse : public PlayFab::FPlayFabCppResultCommon
    {
        /**
         * [optional] The unique identifiers assigned by the server to the events, in the same order as the events in the request. Only
         * returned if FlushToPlayStream option is true.
         */
        TArray<FString> AssignedEventIds;
        FWriteEventsResponse() :
            FPlayFabCppResultCommon(),
            AssignedEventIds()
            {}

        FWriteEventsResponse(const FWriteEventsResponse& src) = default;

        FWriteEventsResponse(const TSharedPtr<FJsonObject>& obj) : FWriteEventsResponse()
        {
            readFromValue(obj);
        }

        ~FWriteEventsResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

}
}
