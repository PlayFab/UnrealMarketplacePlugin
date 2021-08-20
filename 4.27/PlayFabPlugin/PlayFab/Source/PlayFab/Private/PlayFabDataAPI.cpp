//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
//
// API: Data
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabDataAPI.h"
#include "PlayFabDataModels.h"
#include "PlayFabDataModelDecoder.h"
#include "PlayFabPrivate.h"
#include "PlayFabEnums.h"
#include "PlayFabCommon/Public/PlayFabAuthenticationContext.h"
#include "PlayFabCommon/Public/PlayFabCommonUtils.h"

UPlayFabDataAPI::UPlayFabDataAPI(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , CallAuthenticationContext(nullptr)
{
}

void UPlayFabDataAPI::SetCallAuthenticationContext(UPlayFabAuthenticationContext* InAuthenticationContext)
{
    CallAuthenticationContext = InAuthenticationContext;
}

void UPlayFabDataAPI::SetRequestObject(UPlayFabJsonObject* JsonObject)
{
    RequestJsonObj = JsonObject;
}

UPlayFabJsonObject* UPlayFabDataAPI::GetResponseObject()
{
    return ResponseJsonObj;
}

FString UPlayFabDataAPI::PercentEncode(const FString& Text)
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
// Generated PlayFab Data API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// File
//////////////////////////////////////////////////////
/** Abort pending file uploads to an entity's profile. */
UPlayFabDataAPI* UPlayFabDataAPI::AbortFileUploads(FDataAbortFileUploadsRequest request,
    FDelegateOnSuccessAbortFileUploads onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabDataAPI* manager = NewObject<UPlayFabDataAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAbortFileUploads = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabDataAPI::HelperAbortFileUploads);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/File/AbortFileUploads";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    // Check to see if string is empty
    if (request.FileNames.IsEmpty() || request.FileNames == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FileNames"));
    } else {
        TArray<FString> FileNamesArray;
        FString(request.FileNames).ParseIntoArray(FileNamesArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("FileNames"), FileNamesArray);
    }
    OutRestJsonObj->SetNumberField(TEXT("ProfileVersion"), request.ProfileVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabDataRequestCompleted
void UPlayFabDataAPI::HelperAbortFileUploads(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessAbortFileUploads.IsBound())
    {
        FDataAbortFileUploadsResponse ResultStruct = UPlayFabDataModelDecoder::decodeAbortFileUploadsResponseResponse(response.responseData);
        OnSuccessAbortFileUploads.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Delete files on an entity's profile. */
UPlayFabDataAPI* UPlayFabDataAPI::DeleteFiles(FDataDeleteFilesRequest request,
    FDelegateOnSuccessDeleteFiles onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabDataAPI* manager = NewObject<UPlayFabDataAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteFiles = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabDataAPI::HelperDeleteFiles);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/File/DeleteFiles";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    // Check to see if string is empty
    if (request.FileNames.IsEmpty() || request.FileNames == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FileNames"));
    } else {
        TArray<FString> FileNamesArray;
        FString(request.FileNames).ParseIntoArray(FileNamesArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("FileNames"), FileNamesArray);
    }
    OutRestJsonObj->SetNumberField(TEXT("ProfileVersion"), request.ProfileVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabDataRequestCompleted
void UPlayFabDataAPI::HelperDeleteFiles(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteFiles.IsBound())
    {
        FDataDeleteFilesResponse ResultStruct = UPlayFabDataModelDecoder::decodeDeleteFilesResponseResponse(response.responseData);
        OnSuccessDeleteFiles.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Finalize file uploads to an entity's profile. */
UPlayFabDataAPI* UPlayFabDataAPI::FinalizeFileUploads(FDataFinalizeFileUploadsRequest request,
    FDelegateOnSuccessFinalizeFileUploads onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabDataAPI* manager = NewObject<UPlayFabDataAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessFinalizeFileUploads = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabDataAPI::HelperFinalizeFileUploads);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/File/FinalizeFileUploads";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    // Check to see if string is empty
    if (request.FileNames.IsEmpty() || request.FileNames == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FileNames"));
    } else {
        TArray<FString> FileNamesArray;
        FString(request.FileNames).ParseIntoArray(FileNamesArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("FileNames"), FileNamesArray);
    }
    OutRestJsonObj->SetNumberField(TEXT("ProfileVersion"), request.ProfileVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabDataRequestCompleted
void UPlayFabDataAPI::HelperFinalizeFileUploads(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessFinalizeFileUploads.IsBound())
    {
        FDataFinalizeFileUploadsResponse ResultStruct = UPlayFabDataModelDecoder::decodeFinalizeFileUploadsResponseResponse(response.responseData);
        OnSuccessFinalizeFileUploads.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves file metadata from an entity's profile. */
UPlayFabDataAPI* UPlayFabDataAPI::GetFiles(FDataGetFilesRequest request,
    FDelegateOnSuccessGetFiles onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabDataAPI* manager = NewObject<UPlayFabDataAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetFiles = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabDataAPI::HelperGetFiles);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/File/GetFiles";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabDataRequestCompleted
void UPlayFabDataAPI::HelperGetFiles(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetFiles.IsBound())
    {
        FDataGetFilesResponse ResultStruct = UPlayFabDataModelDecoder::decodeGetFilesResponseResponse(response.responseData);
        OnSuccessGetFiles.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Initiates file uploads to an entity's profile. */
UPlayFabDataAPI* UPlayFabDataAPI::InitiateFileUploads(FDataInitiateFileUploadsRequest request,
    FDelegateOnSuccessInitiateFileUploads onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabDataAPI* manager = NewObject<UPlayFabDataAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessInitiateFileUploads = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabDataAPI::HelperInitiateFileUploads);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/File/InitiateFileUploads";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    // Check to see if string is empty
    if (request.FileNames.IsEmpty() || request.FileNames == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FileNames"));
    } else {
        TArray<FString> FileNamesArray;
        FString(request.FileNames).ParseIntoArray(FileNamesArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("FileNames"), FileNamesArray);
    }
    OutRestJsonObj->SetNumberField(TEXT("ProfileVersion"), request.ProfileVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabDataRequestCompleted
void UPlayFabDataAPI::HelperInitiateFileUploads(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessInitiateFileUploads.IsBound())
    {
        FDataInitiateFileUploadsResponse ResultStruct = UPlayFabDataModelDecoder::decodeInitiateFileUploadsResponseResponse(response.responseData);
        OnSuccessInitiateFileUploads.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}


///////////////////////////////////////////////////////
// Object
//////////////////////////////////////////////////////
/** Retrieves objects from an entity's profile. */
UPlayFabDataAPI* UPlayFabDataAPI::GetObjects(FDataGetObjectsRequest request,
    FDelegateOnSuccessGetObjects onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabDataAPI* manager = NewObject<UPlayFabDataAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetObjects = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabDataAPI::HelperGetObjects);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Object/GetObjects";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    OutRestJsonObj->SetBoolField(TEXT("EscapeObject"), request.EscapeObject);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabDataRequestCompleted
void UPlayFabDataAPI::HelperGetObjects(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetObjects.IsBound())
    {
        FDataGetObjectsResponse ResultStruct = UPlayFabDataModelDecoder::decodeGetObjectsResponseResponse(response.responseData);
        OnSuccessGetObjects.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Sets objects on an entity's profile. */
UPlayFabDataAPI* UPlayFabDataAPI::SetObjects(FDataSetObjectsRequest request,
    FDelegateOnSuccessSetObjects onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabDataAPI* manager = NewObject<UPlayFabDataAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetObjects = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabDataAPI::HelperSetObjects);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Object/SetObjects";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    OutRestJsonObj->SetNumberField(TEXT("ExpectedProfileVersion"), request.ExpectedProfileVersion);
    if (request.Objects.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Objects"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Objects"), request.Objects);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabDataRequestCompleted
void UPlayFabDataAPI::HelperSetObjects(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessSetObjects.IsBound())
    {
        FDataSetObjectsResponse ResultStruct = UPlayFabDataModelDecoder::decodeSetObjectsResponseResponse(response.responseData);
        OnSuccessSetObjects.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}



void UPlayFabDataAPI::OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
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

void UPlayFabDataAPI::Activate()
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
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UPlayFabDataAPI::OnProcessRequestComplete);

    // Execute the request
    pfSettings->ModifyPendingCallCount(1);
    HttpRequest->ProcessRequest();
}

void UPlayFabDataAPI::ResetResponseData()
{
    if (ResponseJsonObj != nullptr)
        ResponseJsonObj->Reset();
    else
        ResponseJsonObj = NewObject<UPlayFabJsonObject>();
    bIsValidJsonResponse = false;
}
