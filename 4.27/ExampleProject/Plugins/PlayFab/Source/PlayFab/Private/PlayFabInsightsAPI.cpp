//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
//
// API: Insights
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabInsightsAPI.h"
#include "PlayFabInsightsModels.h"
#include "PlayFabInsightsModelDecoder.h"
#include "PlayFabPrivate.h"
#include "PlayFabEnums.h"
#include "PlayFabCommon/Public/PlayFabAuthenticationContext.h"
#include "PlayFabCommon/Public/PlayFabCommonUtils.h"

UPlayFabInsightsAPI::UPlayFabInsightsAPI(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , CallAuthenticationContext(nullptr)
{
}

void UPlayFabInsightsAPI::SetCallAuthenticationContext(UPlayFabAuthenticationContext* InAuthenticationContext)
{
    CallAuthenticationContext = InAuthenticationContext;
}

void UPlayFabInsightsAPI::SetRequestObject(UPlayFabJsonObject* JsonObject)
{
    RequestJsonObj = JsonObject;
}

UPlayFabJsonObject* UPlayFabInsightsAPI::GetResponseObject()
{
    return ResponseJsonObj;
}

FString UPlayFabInsightsAPI::PercentEncode(const FString& Text)
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
// Generated PlayFab Insights API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Analytics
//////////////////////////////////////////////////////
/** Gets the current values for the Insights performance and data storage retention, list of pending operations, and the performance and data storage retention limits. */
UPlayFabInsightsAPI* UPlayFabInsightsAPI::GetDetails(FInsightsInsightsEmptyRequest request,
    FDelegateOnSuccessGetDetails onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabInsightsAPI* manager = NewObject<UPlayFabInsightsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetDetails = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabInsightsAPI::HelperGetDetails);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Insights/GetDetails";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabInsightsRequestCompleted
void UPlayFabInsightsAPI::HelperGetDetails(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetDetails.IsBound())
    {
        FInsightsInsightsGetDetailsResponse ResultStruct = UPlayFabInsightsModelDecoder::decodeInsightsGetDetailsResponseResponse(response.responseData);
        OnSuccessGetDetails.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the range of allowed values for performance and data storage retention values as well as the submeter details for each performance level. */
UPlayFabInsightsAPI* UPlayFabInsightsAPI::GetLimits(FInsightsInsightsEmptyRequest request,
    FDelegateOnSuccessGetLimits onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabInsightsAPI* manager = NewObject<UPlayFabInsightsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetLimits = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabInsightsAPI::HelperGetLimits);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Insights/GetLimits";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabInsightsRequestCompleted
void UPlayFabInsightsAPI::HelperGetLimits(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetLimits.IsBound())
    {
        FInsightsInsightsGetLimitsResponse ResultStruct = UPlayFabInsightsModelDecoder::decodeInsightsGetLimitsResponseResponse(response.responseData);
        OnSuccessGetLimits.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets the status of a SetPerformance or SetStorageRetention operation. */
UPlayFabInsightsAPI* UPlayFabInsightsAPI::GetOperationStatus(FInsightsInsightsGetOperationStatusRequest request,
    FDelegateOnSuccessGetOperationStatus onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabInsightsAPI* manager = NewObject<UPlayFabInsightsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetOperationStatus = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabInsightsAPI::HelperGetOperationStatus);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Insights/GetOperationStatus";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.OperationId.IsEmpty() || request.OperationId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("OperationId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("OperationId"), request.OperationId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabInsightsRequestCompleted
void UPlayFabInsightsAPI::HelperGetOperationStatus(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetOperationStatus.IsBound())
    {
        FInsightsInsightsGetOperationStatusResponse ResultStruct = UPlayFabInsightsModelDecoder::decodeInsightsGetOperationStatusResponseResponse(response.responseData);
        OnSuccessGetOperationStatus.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets a list of pending SetPerformance and/or SetStorageRetention operations for the title. */
UPlayFabInsightsAPI* UPlayFabInsightsAPI::GetPendingOperations(FInsightsInsightsGetPendingOperationsRequest request,
    FDelegateOnSuccessGetPendingOperations onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabInsightsAPI* manager = NewObject<UPlayFabInsightsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPendingOperations = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabInsightsAPI::HelperGetPendingOperations);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Insights/GetPendingOperations";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.OperationType.IsEmpty() || request.OperationType == "") {
        OutRestJsonObj->SetFieldNull(TEXT("OperationType"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("OperationType"), request.OperationType);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabInsightsRequestCompleted
void UPlayFabInsightsAPI::HelperGetPendingOperations(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetPendingOperations.IsBound())
    {
        FInsightsInsightsGetPendingOperationsResponse ResultStruct = UPlayFabInsightsModelDecoder::decodeInsightsGetPendingOperationsResponseResponse(response.responseData);
        OnSuccessGetPendingOperations.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Sets the Insights performance level value for the title. */
UPlayFabInsightsAPI* UPlayFabInsightsAPI::SetPerformance(FInsightsInsightsSetPerformanceRequest request,
    FDelegateOnSuccessSetPerformance onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabInsightsAPI* manager = NewObject<UPlayFabInsightsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetPerformance = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabInsightsAPI::HelperSetPerformance);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Insights/SetPerformance";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    OutRestJsonObj->SetNumberField(TEXT("PerformanceLevel"), request.PerformanceLevel);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabInsightsRequestCompleted
void UPlayFabInsightsAPI::HelperSetPerformance(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessSetPerformance.IsBound())
    {
        FInsightsInsightsOperationResponse ResultStruct = UPlayFabInsightsModelDecoder::decodeInsightsOperationResponseResponse(response.responseData);
        OnSuccessSetPerformance.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Sets the Insights data storage retention days value for the title. */
UPlayFabInsightsAPI* UPlayFabInsightsAPI::SetStorageRetention(FInsightsInsightsSetStorageRetentionRequest request,
    FDelegateOnSuccessSetStorageRetention onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabInsightsAPI* manager = NewObject<UPlayFabInsightsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetStorageRetention = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabInsightsAPI::HelperSetStorageRetention);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Insights/SetStorageRetention";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    OutRestJsonObj->SetNumberField(TEXT("RetentionDays"), request.RetentionDays);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabInsightsRequestCompleted
void UPlayFabInsightsAPI::HelperSetStorageRetention(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessSetStorageRetention.IsBound())
    {
        FInsightsInsightsOperationResponse ResultStruct = UPlayFabInsightsModelDecoder::decodeInsightsOperationResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessSetStorageRetention.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}



void UPlayFabInsightsAPI::OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
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

void UPlayFabInsightsAPI::Activate()
{
    IPlayFab* pfSettings = &(IPlayFab::Get());

    FString RequestUrl;
    RequestUrl = pfSettings->GeneratePfUrl(PlayFabRequestURL);


    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
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
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UPlayFabInsightsAPI::OnProcessRequestComplete);

    // Execute the request
    pfSettings->ModifyPendingCallCount(1);
    HttpRequest->ProcessRequest();
}

void UPlayFabInsightsAPI::ResetResponseData()
{
    if (ResponseJsonObj != nullptr)
        ResponseJsonObj->Reset();
    else
        ResponseJsonObj = NewObject<UPlayFabJsonObject>();
    bIsValidJsonResponse = false;
}
