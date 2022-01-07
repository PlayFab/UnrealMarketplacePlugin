//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
//
// API: Profiles
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabProfilesAPI.h"
#include "PlayFabProfilesModels.h"
#include "PlayFabProfilesModelDecoder.h"
#include "PlayFabPrivate.h"
#include "PlayFabEnums.h"
#include "PlayFabCommon/Public/PlayFabAuthenticationContext.h"
#include "PlayFabCommon/Public/PlayFabCommonUtils.h"

UPlayFabProfilesAPI::UPlayFabProfilesAPI(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , CallAuthenticationContext(nullptr)
{
}

void UPlayFabProfilesAPI::SetCallAuthenticationContext(UPlayFabAuthenticationContext* InAuthenticationContext)
{
    CallAuthenticationContext = InAuthenticationContext;
}

void UPlayFabProfilesAPI::SetRequestObject(UPlayFabJsonObject* JsonObject)
{
    RequestJsonObj = JsonObject;
}

UPlayFabJsonObject* UPlayFabProfilesAPI::GetResponseObject()
{
    return ResponseJsonObj;
}

FString UPlayFabProfilesAPI::PercentEncode(const FString& Text)
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
// Generated PlayFab Profiles API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////
/** Gets the global title access policy  */
UPlayFabProfilesAPI* UPlayFabProfilesAPI::GetGlobalPolicy(FProfilesGetGlobalPolicyRequest request,
    FDelegateOnSuccessGetGlobalPolicy onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProfilesAPI* manager = NewObject<UPlayFabProfilesAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetGlobalPolicy = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProfilesAPI::HelperGetGlobalPolicy);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Profile/GetGlobalPolicy";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabProfilesRequestCompleted
void UPlayFabProfilesAPI::HelperGetGlobalPolicy(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetGlobalPolicy.IsBound())
    {
        FProfilesGetGlobalPolicyResponse ResultStruct = UPlayFabProfilesModelDecoder::decodeGetGlobalPolicyResponseResponse(response.responseData);
        OnSuccessGetGlobalPolicy.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the entity's profile. */
UPlayFabProfilesAPI* UPlayFabProfilesAPI::GetProfile(FProfilesGetEntityProfileRequest request,
    FDelegateOnSuccessGetProfile onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProfilesAPI* manager = NewObject<UPlayFabProfilesAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetProfile = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProfilesAPI::HelperGetProfile);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Profile/GetProfile";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    OutRestJsonObj->SetBoolField(TEXT("DataAsObject"), request.DataAsObject);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabProfilesRequestCompleted
void UPlayFabProfilesAPI::HelperGetProfile(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetProfile.IsBound())
    {
        FProfilesGetEntityProfileResponse ResultStruct = UPlayFabProfilesModelDecoder::decodeGetEntityProfileResponseResponse(response.responseData);
        OnSuccessGetProfile.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the entity's profile. */
UPlayFabProfilesAPI* UPlayFabProfilesAPI::GetProfiles(FProfilesGetEntityProfilesRequest request,
    FDelegateOnSuccessGetProfiles onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProfilesAPI* manager = NewObject<UPlayFabProfilesAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetProfiles = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProfilesAPI::HelperGetProfiles);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Profile/GetProfiles";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    OutRestJsonObj->SetBoolField(TEXT("DataAsObject"), request.DataAsObject);
    if (request.Entities.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Entities"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Entities"), request.Entities);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabProfilesRequestCompleted
void UPlayFabProfilesAPI::HelperGetProfiles(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetProfiles.IsBound())
    {
        FProfilesGetEntityProfilesResponse ResultStruct = UPlayFabProfilesModelDecoder::decodeGetEntityProfilesResponseResponse(response.responseData);
        OnSuccessGetProfiles.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the title player accounts associated with the given master player account. */
UPlayFabProfilesAPI* UPlayFabProfilesAPI::GetTitlePlayersFromMasterPlayerAccountIds(FProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequest request,
    FDelegateOnSuccessGetTitlePlayersFromMasterPlayerAccountIds onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProfilesAPI* manager = NewObject<UPlayFabProfilesAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetTitlePlayersFromMasterPlayerAccountIds = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProfilesAPI::HelperGetTitlePlayersFromMasterPlayerAccountIds);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Profile/GetTitlePlayersFromMasterPlayerAccountIds";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    // Check to see if string is empty
    if (request.MasterPlayerAccountIds.IsEmpty() || request.MasterPlayerAccountIds == "") {
        OutRestJsonObj->SetFieldNull(TEXT("MasterPlayerAccountIds"));
    } else {
        TArray<FString> MasterPlayerAccountIdsArray;
        FString(request.MasterPlayerAccountIds).ParseIntoArray(MasterPlayerAccountIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("MasterPlayerAccountIds"), MasterPlayerAccountIdsArray);
    }
    OutRestJsonObj->SetStringField(TEXT("TitleId"), GetDefault<UPlayFabRuntimeSettings>()->TitleId);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabProfilesRequestCompleted
void UPlayFabProfilesAPI::HelperGetTitlePlayersFromMasterPlayerAccountIds(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetTitlePlayersFromMasterPlayerAccountIds.IsBound())
    {
        FProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse ResultStruct = UPlayFabProfilesModelDecoder::decodeGetTitlePlayersFromMasterPlayerAccountIdsResponseResponse(response.responseData);
        OnSuccessGetTitlePlayersFromMasterPlayerAccountIds.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Sets the global title access policy  */
UPlayFabProfilesAPI* UPlayFabProfilesAPI::SetGlobalPolicy(FProfilesSetGlobalPolicyRequest request,
    FDelegateOnSuccessSetGlobalPolicy onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProfilesAPI* manager = NewObject<UPlayFabProfilesAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetGlobalPolicy = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProfilesAPI::HelperSetGlobalPolicy);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Profile/SetGlobalPolicy";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Permissions.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Permissions"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Permissions"), request.Permissions);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabProfilesRequestCompleted
void UPlayFabProfilesAPI::HelperSetGlobalPolicy(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessSetGlobalPolicy.IsBound())
    {
        FProfilesSetGlobalPolicyResponse ResultStruct = UPlayFabProfilesModelDecoder::decodeSetGlobalPolicyResponseResponse(response.responseData);
        OnSuccessSetGlobalPolicy.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Updates the entity's language. The precedence hierarchy for communication to the player is Title Player Account language, Master Player Account language, and then title default language if the first two aren't set or supported. */
UPlayFabProfilesAPI* UPlayFabProfilesAPI::SetProfileLanguage(FProfilesSetProfileLanguageRequest request,
    FDelegateOnSuccessSetProfileLanguage onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProfilesAPI* manager = NewObject<UPlayFabProfilesAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetProfileLanguage = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProfilesAPI::HelperSetProfileLanguage);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Profile/SetProfileLanguage";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    OutRestJsonObj->SetNumberField(TEXT("ExpectedVersion"), request.ExpectedVersion);
    if (request.Language.IsEmpty() || request.Language == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Language"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Language"), request.Language);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabProfilesRequestCompleted
void UPlayFabProfilesAPI::HelperSetProfileLanguage(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessSetProfileLanguage.IsBound())
    {
        FProfilesSetProfileLanguageResponse ResultStruct = UPlayFabProfilesModelDecoder::decodeSetProfileLanguageResponseResponse(response.responseData);
        OnSuccessSetProfileLanguage.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Sets the profiles access policy */
UPlayFabProfilesAPI* UPlayFabProfilesAPI::SetProfilePolicy(FProfilesSetEntityProfilePolicyRequest request,
    FDelegateOnSuccessSetProfilePolicy onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProfilesAPI* manager = NewObject<UPlayFabProfilesAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetProfilePolicy = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProfilesAPI::HelperSetProfilePolicy);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Profile/SetProfilePolicy";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.Statements.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Statements"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Statements"), request.Statements);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabProfilesRequestCompleted
void UPlayFabProfilesAPI::HelperSetProfilePolicy(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessSetProfilePolicy.IsBound())
    {
        FProfilesSetEntityProfilePolicyResponse ResultStruct = UPlayFabProfilesModelDecoder::decodeSetEntityProfilePolicyResponseResponse(response.responseData);
        OnSuccessSetProfilePolicy.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}



void UPlayFabProfilesAPI::OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
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

void UPlayFabProfilesAPI::Activate()
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
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UPlayFabProfilesAPI::OnProcessRequestComplete);

    // Execute the request
    pfSettings->ModifyPendingCallCount(1);
    HttpRequest->ProcessRequest();
}

void UPlayFabProfilesAPI::ResetResponseData()
{
    if (ResponseJsonObj != nullptr)
        ResponseJsonObj->Reset();
    else
        ResponseJsonObj = NewObject<UPlayFabJsonObject>();
    bIsValidJsonResponse = false;
}
