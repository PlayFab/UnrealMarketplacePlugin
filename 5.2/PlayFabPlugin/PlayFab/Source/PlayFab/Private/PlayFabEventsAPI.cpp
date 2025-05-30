//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
//
// API: Events
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabEventsAPI.h"
#include "PlayFabEventsModels.h"
#include "PlayFabEventsModelDecoder.h"
#include "PlayFabPrivate.h"
#include "PlayFabEnums.h"
#include "PlayFabCommon/Public/PlayFabAuthenticationContext.h"
#include "PlayFabCommon/Public/PlayFabCommonUtils.h"

UPlayFabEventsAPI::UPlayFabEventsAPI(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , CallAuthenticationContext(nullptr)
{
}

void UPlayFabEventsAPI::SetCallAuthenticationContext(UPlayFabAuthenticationContext* InAuthenticationContext)
{
    CallAuthenticationContext = InAuthenticationContext;
}

void UPlayFabEventsAPI::SetRequestObject(UPlayFabJsonObject* JsonObject)
{
    RequestJsonObj = JsonObject;
}

UPlayFabJsonObject* UPlayFabEventsAPI::GetResponseObject()
{
    return ResponseJsonObj;
}

FString UPlayFabEventsAPI::PercentEncode(const FString& Text)
{
    FString OutText = Text;

    OutText = OutText.Replace(TEXT("!"), TEXT("%21"));
    OutText = OutText.Replace(TEXT("\""), TEXT("%22"));
    OutText = OutText.Replace(TEXT("#"), TEXT("%23"));
    OutText = OutText.Replace(TEXT("$"), TEXT("%24"));
    //OutText = OutText.Replace(TEXT("&"), TEXT("%26"));
    OutText = OutText.Replace(TEXT("'"), TEXT("%27"));
    OutText = OutText.Replace(TEXT("("), TEXT("%28"));
    OutText = OutText.Replace(TEXT(")"), TEXT("%29"));
    OutText = OutText.Replace(TEXT("*"), TEXT("%2A"));
    OutText = OutText.Replace(TEXT("+"), TEXT("%2B"));
    OutText = OutText.Replace(TEXT(","), TEXT("%2C"));
    //OutText = OutText.Replace(TEXT("/"), TEXT("%2F"));
    OutText = OutText.Replace(TEXT(":"), TEXT("%3A"));
    OutText = OutText.Replace(TEXT(";"), TEXT("%3B"));
    OutText = OutText.Replace(TEXT("="), TEXT("%3D"));
    //OutText = OutText.Replace(TEXT("?"), TEXT("%3F"));
    OutText = OutText.Replace(TEXT("@"), TEXT("%40"));
    OutText = OutText.Replace(TEXT("["), TEXT("%5B"));
    OutText = OutText.Replace(TEXT("]"), TEXT("%5D"));
    OutText = OutText.Replace(TEXT("{"), TEXT("%7B"));
    OutText = OutText.Replace(TEXT("}"), TEXT("%7D"));

    return OutText;
}

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Events API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// PlayStream
//////////////////////////////////////////////////////

///////////////////////////////////////////////////////
// PlayStream Events
//////////////////////////////////////////////////////
/** Creates a new telemetry key for the title. */
UPlayFabEventsAPI* UPlayFabEventsAPI::CreateTelemetryKey(FEventsCreateTelemetryKeyRequest request,
    FDelegateOnSuccessCreateTelemetryKey onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEventsAPI* manager = NewObject<UPlayFabEventsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateTelemetryKey = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEventsAPI::HelperCreateTelemetryKey);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Event/CreateTelemetryKey";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.KeyName.IsEmpty() || request.KeyName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KeyName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("KeyName"), request.KeyName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEventsRequestCompleted
void UPlayFabEventsAPI::HelperCreateTelemetryKey(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateTelemetryKey.IsBound())
    {
        FEventsCreateTelemetryKeyResponse ResultStruct = UPlayFabEventsModelDecoder::decodeCreateTelemetryKeyResponseResponse(response.responseData);
        OnSuccessCreateTelemetryKey.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes a Data Connection from a title. */
UPlayFabEventsAPI* UPlayFabEventsAPI::DeleteDataConnection(FEventsDeleteDataConnectionRequest request,
    FDelegateOnSuccessDeleteDataConnection onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEventsAPI* manager = NewObject<UPlayFabEventsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteDataConnection = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEventsAPI::HelperDeleteDataConnection);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Event/DeleteDataConnection";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Name.IsEmpty() || request.Name == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Name"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Name"), request.Name);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEventsRequestCompleted
void UPlayFabEventsAPI::HelperDeleteDataConnection(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteDataConnection.IsBound())
    {
        FEventsDeleteDataConnectionResponse ResultStruct = UPlayFabEventsModelDecoder::decodeDeleteDataConnectionResponseResponse(response.responseData);
        OnSuccessDeleteDataConnection.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes a telemetry key configured for the title. */
UPlayFabEventsAPI* UPlayFabEventsAPI::DeleteTelemetryKey(FEventsDeleteTelemetryKeyRequest request,
    FDelegateOnSuccessDeleteTelemetryKey onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEventsAPI* manager = NewObject<UPlayFabEventsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteTelemetryKey = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEventsAPI::HelperDeleteTelemetryKey);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Event/DeleteTelemetryKey";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.KeyName.IsEmpty() || request.KeyName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KeyName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("KeyName"), request.KeyName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEventsRequestCompleted
void UPlayFabEventsAPI::HelperDeleteTelemetryKey(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteTelemetryKey.IsBound())
    {
        FEventsDeleteTelemetryKeyResponse ResultStruct = UPlayFabEventsModelDecoder::decodeDeleteTelemetryKeyResponseResponse(response.responseData);
        OnSuccessDeleteTelemetryKey.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves a single Data Connection associated with a title. */
UPlayFabEventsAPI* UPlayFabEventsAPI::GetDataConnection(FEventsGetDataConnectionRequest request,
    FDelegateOnSuccessGetDataConnection onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEventsAPI* manager = NewObject<UPlayFabEventsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetDataConnection = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEventsAPI::HelperGetDataConnection);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Event/GetDataConnection";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Name.IsEmpty() || request.Name == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Name"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Name"), request.Name);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEventsRequestCompleted
void UPlayFabEventsAPI::HelperGetDataConnection(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetDataConnection.IsBound())
    {
        FEventsGetDataConnectionResponse ResultStruct = UPlayFabEventsModelDecoder::decodeGetDataConnectionResponseResponse(response.responseData);
        OnSuccessGetDataConnection.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets information about a telemetry key configured for the title. */
UPlayFabEventsAPI* UPlayFabEventsAPI::GetTelemetryKey(FEventsGetTelemetryKeyRequest request,
    FDelegateOnSuccessGetTelemetryKey onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEventsAPI* manager = NewObject<UPlayFabEventsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetTelemetryKey = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEventsAPI::HelperGetTelemetryKey);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Event/GetTelemetryKey";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.KeyName.IsEmpty() || request.KeyName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KeyName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("KeyName"), request.KeyName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEventsRequestCompleted
void UPlayFabEventsAPI::HelperGetTelemetryKey(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetTelemetryKey.IsBound())
    {
        FEventsGetTelemetryKeyResponse ResultStruct = UPlayFabEventsModelDecoder::decodeGetTelemetryKeyResponseResponse(response.responseData);
        OnSuccessGetTelemetryKey.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the list of Data Connections associated with a title. */
UPlayFabEventsAPI* UPlayFabEventsAPI::ListDataConnections(FEventsListDataConnectionsRequest request,
    FDelegateOnSuccessListDataConnections onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEventsAPI* manager = NewObject<UPlayFabEventsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListDataConnections = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEventsAPI::HelperListDataConnections);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Event/ListDataConnections";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEventsRequestCompleted
void UPlayFabEventsAPI::HelperListDataConnections(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListDataConnections.IsBound())
    {
        FEventsListDataConnectionsResponse ResultStruct = UPlayFabEventsModelDecoder::decodeListDataConnectionsResponseResponse(response.responseData);
        OnSuccessListDataConnections.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Lists all telemetry keys configured for the title. */
UPlayFabEventsAPI* UPlayFabEventsAPI::ListTelemetryKeys(FEventsListTelemetryKeysRequest request,
    FDelegateOnSuccessListTelemetryKeys onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEventsAPI* manager = NewObject<UPlayFabEventsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListTelemetryKeys = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEventsAPI::HelperListTelemetryKeys);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Event/ListTelemetryKeys";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEventsRequestCompleted
void UPlayFabEventsAPI::HelperListTelemetryKeys(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListTelemetryKeys.IsBound())
    {
        FEventsListTelemetryKeysResponse ResultStruct = UPlayFabEventsModelDecoder::decodeListTelemetryKeysResponseResponse(response.responseData);
        OnSuccessListTelemetryKeys.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Creates or updates a Data Connection on a title. */
UPlayFabEventsAPI* UPlayFabEventsAPI::SetDataConnection(FEventsSetDataConnectionRequest request,
    FDelegateOnSuccessSetDataConnection onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEventsAPI* manager = NewObject<UPlayFabEventsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetDataConnection = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEventsAPI::HelperSetDataConnection);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Event/SetDataConnection";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.ConnectionSettings != nullptr) OutRestJsonObj->SetObjectField(TEXT("ConnectionSettings"), request.ConnectionSettings);
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    OutRestJsonObj->SetBoolField(TEXT("IsActive"), request.IsActive);
    if (request.Name.IsEmpty() || request.Name == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Name"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Name"), request.Name);
    }
    FString temp_Type;
    if (GetEnumValueToString<EDataConnectionType>(TEXT("EDataConnectionType"), request.Type, temp_Type))
        OutRestJsonObj->SetStringField(TEXT("Type"), temp_Type);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEventsRequestCompleted
void UPlayFabEventsAPI::HelperSetDataConnection(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessSetDataConnection.IsBound())
    {
        FEventsSetDataConnectionResponse ResultStruct = UPlayFabEventsModelDecoder::decodeSetDataConnectionResponseResponse(response.responseData);
        OnSuccessSetDataConnection.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Sets a Data Connection for the title to either the active or deactivated state. */
UPlayFabEventsAPI* UPlayFabEventsAPI::SetDataConnectionActive(FEventsSetDataConnectionActiveRequest request,
    FDelegateOnSuccessSetDataConnectionActive onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEventsAPI* manager = NewObject<UPlayFabEventsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetDataConnectionActive = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEventsAPI::HelperSetDataConnectionActive);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Event/SetDataConnectionActive";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    OutRestJsonObj->SetBoolField(TEXT("Active"), request.Active);
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Name.IsEmpty() || request.Name == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Name"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Name"), request.Name);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEventsRequestCompleted
void UPlayFabEventsAPI::HelperSetDataConnectionActive(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessSetDataConnectionActive.IsBound())
    {
        FEventsSetDataConnectionActiveResponse ResultStruct = UPlayFabEventsModelDecoder::decodeSetDataConnectionActiveResponseResponse(response.responseData);
        OnSuccessSetDataConnectionActive.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Sets a telemetry key to the active or deactivated state. */
UPlayFabEventsAPI* UPlayFabEventsAPI::SetTelemetryKeyActive(FEventsSetTelemetryKeyActiveRequest request,
    FDelegateOnSuccessSetTelemetryKeyActive onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEventsAPI* manager = NewObject<UPlayFabEventsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetTelemetryKeyActive = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEventsAPI::HelperSetTelemetryKeyActive);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Event/SetTelemetryKeyActive";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    OutRestJsonObj->SetBoolField(TEXT("Active"), request.Active);
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.KeyName.IsEmpty() || request.KeyName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KeyName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("KeyName"), request.KeyName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEventsRequestCompleted
void UPlayFabEventsAPI::HelperSetTelemetryKeyActive(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessSetTelemetryKeyActive.IsBound())
    {
        FEventsSetTelemetryKeyActiveResponse ResultStruct = UPlayFabEventsModelDecoder::decodeSetTelemetryKeyActiveResponseResponse(response.responseData);
        OnSuccessSetTelemetryKeyActive.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Write batches of entity based events to PlayStream. The namespace of the Event must be 'custom' or start with 'custom.'. */
UPlayFabEventsAPI* UPlayFabEventsAPI::WriteEvents(FEventsWriteEventsRequest request,
    FDelegateOnSuccessWriteEvents onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEventsAPI* manager = NewObject<UPlayFabEventsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessWriteEvents = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEventsAPI::HelperWriteEvents);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Event/WriteEvents";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Events.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Events"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Events"), request.Events);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEventsRequestCompleted
void UPlayFabEventsAPI::HelperWriteEvents(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessWriteEvents.IsBound())
    {
        FEventsWriteEventsResponse ResultStruct = UPlayFabEventsModelDecoder::decodeWriteEventsResponseResponse(response.responseData);
        OnSuccessWriteEvents.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Write batches of entity based events to as Telemetry events (bypass PlayStream). The namespace must be 'custom' or start with 'custom.' */
UPlayFabEventsAPI* UPlayFabEventsAPI::WriteTelemetryEvents(FEventsWriteEventsRequest request,
    FDelegateOnSuccessWriteTelemetryEvents onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEventsAPI* manager = NewObject<UPlayFabEventsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessWriteTelemetryEvents = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEventsAPI::HelperWriteTelemetryEvents);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Event/WriteTelemetryEvents";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Events.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Events"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Events"), request.Events);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Write batches of entity based events to as Telemetry events (bypass PlayStream) using a Telemetry Key. The namespace must be 'custom' or start with 'custom.' */
UPlayFabEventsAPI* UPlayFabEventsAPI::WriteTelemetryEventsWithTelemetryKey(FEventsWriteEventsRequest request,
    FString telemetryKey,
    FDelegateOnSuccessWriteTelemetryEvents onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabEventsAPI* manager = NewObject<UPlayFabEventsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessWriteTelemetryEvents = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabEventsAPI::HelperWriteTelemetryEvents);

    // Setup the request
    manager->PlayFabRequestURL = "/Event/WriteTelemetryEvents";
    manager->useTelemetryKey = true;
    manager->telemetryKey = telemetryKey;

    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Events.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Events"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Events"), request.Events);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabEventsRequestCompleted
void UPlayFabEventsAPI::HelperWriteTelemetryEvents(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessWriteTelemetryEvents.IsBound())
    {
        FEventsWriteEventsResponse ResultStruct = UPlayFabEventsModelDecoder::decodeWriteEventsResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessWriteTelemetryEvents.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}



void UPlayFabEventsAPI::OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    // Be sure that we have no data from previous response
    ResetResponseData();

    if (!IsValidLowLevel())
    {
        UE_LOG(LogPlayFab, Error, TEXT("The request object is invalid during OnProcessRequestComplete."));
        return;
    }
    if (!OnPlayFabResponse.IsBound())
    {
        UE_LOG(LogPlayFab, Error, TEXT("OnPlayFabResponse has come un-bound during OnProcessRequestComplete."));
        return;
    }

    FPlayFabBaseModel myResponse;

    // Check we have result to process further
    if (!bWasSuccessful)
    {
        UE_LOG(LogPlayFab, Error, TEXT("Request failed: %s"), *Request->GetURL());

        // Broadcast the result event
        myResponse.responseError.hasError = true;
        myResponse.responseError.ErrorCode = 503;
        myResponse.responseError.ErrorName = "Unable to contact server";
        myResponse.responseError.ErrorMessage = "Unable to contact server";

        OnPlayFabResponse.Broadcast(myResponse, mCustomData, false);

        return;
    }

    // Save response data as a string
    ResponseContent = Response->GetContentAsString();

    // Save response code as int32
    ResponseCode = Response->GetResponseCode();

    // Try to deserialize data to JSON
    TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(ResponseContent);
    FJsonSerializer::Deserialize(JsonReader, ResponseJsonObj->GetRootObject());

    // Decide whether the request was successful
    bIsValidJsonResponse = bWasSuccessful && ResponseJsonObj->GetRootObject().IsValid();

    // Log errors
    if (!bIsValidJsonResponse)
        UE_LOG(LogPlayFab, Warning, TEXT("JSON could not be decoded!"));

    // Log response state
    UE_LOG(LogPlayFab, Log, TEXT("Response : %s"), *ResponseContent);

    myResponse.responseError.decodeError(ResponseJsonObj);
    myResponse.responseData = ResponseJsonObj;
    IPlayFab* pfSettings = &(IPlayFab::Get());

    if (returnsEntityToken)
    {
        CallAuthenticationContext = NewObject<UPlayFabAuthenticationContext>();
        FString NewEntityToken = myResponse.responseData->GetObjectField("data")->GetStringField("EntityToken");
        pfSettings->setEntityToken(NewEntityToken);
        CallAuthenticationContext->SetEntityToken(MoveTemp(NewEntityToken));
    }

    // Broadcast the result event
    OnPlayFabResponse.Broadcast(myResponse, mCustomData, !myResponse.responseError.hasError);
    pfSettings->ModifyPendingCallCount(-1);
}

void UPlayFabEventsAPI::Activate()
{
    IPlayFab* pfSettings = &(IPlayFab::Get());

    FString RequestUrl;
    RequestUrl = pfSettings->GeneratePfUrl(PlayFabRequestURL);


    TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
    HttpRequest->SetURL(RequestUrl);
    HttpRequest->SetVerb(TEXT("POST"));

    // Headers
    // Only set one of the potential authentication headers.
    bool AuthSet = false;

    if (useEntityToken && !AuthSet)
    {
        FString AuthValue =
        CallAuthenticationContext != nullptr ? CallAuthenticationContext->GetEntityToken() : pfSettings->getEntityToken();
        if (!AuthValue.IsEmpty())
        {
            HttpRequest->SetHeader(TEXT("X-EntityToken"), AuthValue);
            AuthSet = true;
        }
    }

    if (useSessionTicket && !AuthSet)
    {
        FString AuthValue = CallAuthenticationContext != nullptr ? CallAuthenticationContext->GetClientSessionTicket()
                                                                 : pfSettings->getSessionTicket();
        if (!AuthValue.IsEmpty())
        {
            HttpRequest->SetHeader(TEXT("X-Authorization"), AuthValue);
            AuthSet = true;
        }
    }

    if (useSecretKey && !AuthSet)
    {
        FString AuthValue = CallAuthenticationContext != nullptr ? CallAuthenticationContext->GetDeveloperSecretKey()
                                                                 : GetDefault<UPlayFabRuntimeSettings>()->DeveloperSecretKey;
        if (!AuthValue.IsEmpty())
        {
            HttpRequest->SetHeader(TEXT("X-SecretKey"), AuthValue);
            AuthSet = true;
        }
    }

    if (useTelemetryKey && !AuthSet)
    {
        if (!telemetryKey.IsEmpty())
        {
            HttpRequest->SetHeader(TEXT("X-TelemetryKey"), telemetryKey);
            AuthSet = true;
        }
    }

    HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
    HttpRequest->SetHeader(TEXT("X-PlayFabSDK"), pfSettings->getVersionString());
    HttpRequest->SetHeader(TEXT("X-ReportErrorAsSuccess"), TEXT("true")); // FHttpResponsePtr doesn't provide sufficient information when an error code is returned
    for (TMap<FString, FString>::TConstIterator It(RequestHeaders); It; ++It)
        HttpRequest->SetHeader(It.Key(), It.Value());

    // Serialize data to json string
    FString OutputString;
    TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
    FJsonSerializer::Serialize(RequestJsonObj->GetRootObject().ToSharedRef(), Writer);

    // Set Json content
    HttpRequest->SetContentAsString(OutputString);

    UE_LOG(LogPlayFab, Log, TEXT("Request: %s"), *OutputString);

    // Bind event
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UPlayFabEventsAPI::OnProcessRequestComplete);

    // Execute the request
    pfSettings->ModifyPendingCallCount(1);
    HttpRequest->ProcessRequest();
}

void UPlayFabEventsAPI::ResetResponseData()
{
    if (ResponseJsonObj != nullptr)
        ResponseJsonObj->Reset();
    else
        ResponseJsonObj = NewObject<UPlayFabJsonObject>();
    bIsValidJsonResponse = false;
}
