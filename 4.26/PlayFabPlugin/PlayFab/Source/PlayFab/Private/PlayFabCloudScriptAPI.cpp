//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
//
// API: CloudScript
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabCloudScriptAPI.h"
#include "PlayFabCloudScriptModels.h"
#include "PlayFabCloudScriptModelDecoder.h"
#include "PlayFabPrivate.h"
#include "PlayFabEnums.h"
#include "PlayFabCommon/Public/PlayFabAuthenticationContext.h"
#include "PlayFabCommon/Public/PlayFabCommonUtils.h"

UPlayFabCloudScriptAPI::UPlayFabCloudScriptAPI(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , CallAuthenticationContext(nullptr)
{
}

void UPlayFabCloudScriptAPI::SetCallAuthenticationContext(UPlayFabAuthenticationContext* InAuthenticationContext)
{
    CallAuthenticationContext = InAuthenticationContext;
}

void UPlayFabCloudScriptAPI::SetRequestObject(UPlayFabJsonObject* JsonObject)
{
    RequestJsonObj = JsonObject;
}

UPlayFabJsonObject* UPlayFabCloudScriptAPI::GetResponseObject()
{
    return ResponseJsonObj;
}

FString UPlayFabCloudScriptAPI::PercentEncode(const FString& Text)
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
// Generated PlayFab CloudScript API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Server-Side Cloud Script
//////////////////////////////////////////////////////
/** Cloud Script is one of PlayFab's most versatile features. It allows client code to request execution of any kind of custom server-side functionality you can implement, and it can be used in conjunction with virtually anything. */
UPlayFabCloudScriptAPI* UPlayFabCloudScriptAPI::ExecuteEntityCloudScript(FCloudScriptExecuteEntityCloudScriptRequest request,
    FDelegateOnSuccessExecuteEntityCloudScript onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabCloudScriptAPI* manager = NewObject<UPlayFabCloudScriptAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessExecuteEntityCloudScript = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabCloudScriptAPI::HelperExecuteEntityCloudScript);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/CloudScript/ExecuteEntityCloudScript";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.FunctionName.IsEmpty() || request.FunctionName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FunctionName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("FunctionName"), request.FunctionName);
    }
    if (request.FunctionParameter != nullptr) OutRestJsonObj->SetObjectField(TEXT("FunctionParameter"), request.FunctionParameter);
    OutRestJsonObj->SetBoolField(TEXT("GeneratePlayStreamEvent"), request.GeneratePlayStreamEvent);
    FString temp_RevisionSelection;
    if (GetEnumValueToString<ECloudScriptRevisionOption>(TEXT("ECloudScriptRevisionOption"), request.RevisionSelection, temp_RevisionSelection))
        OutRestJsonObj->SetStringField(TEXT("RevisionSelection"), temp_RevisionSelection);
    OutRestJsonObj->SetNumberField(TEXT("SpecificRevision"), request.SpecificRevision);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabCloudScriptRequestCompleted
void UPlayFabCloudScriptAPI::HelperExecuteEntityCloudScript(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessExecuteEntityCloudScript.IsBound())
    {
        FCloudScriptExecuteCloudScriptResult ResultStruct = UPlayFabCloudScriptModelDecoder::decodeExecuteCloudScriptResultResponse(response.responseData);
        OnSuccessExecuteEntityCloudScript.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Cloud Script is one of PlayFab's most versatile features. It allows client code to request execution of any kind of custom server-side functionality you can implement, and it can be used in conjunction with virtually anything. */
UPlayFabCloudScriptAPI* UPlayFabCloudScriptAPI::ExecuteFunction(FCloudScriptExecuteFunctionRequest request,
    FDelegateOnSuccessExecuteFunction onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabCloudScriptAPI* manager = NewObject<UPlayFabCloudScriptAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessExecuteFunction = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabCloudScriptAPI::HelperExecuteFunction);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/CloudScript/ExecuteFunction";
    manager->useEntityToken = true;

    // Check for local debugging
    FString localApiServer = PlayFabCommon::PlayFabCommonUtils::GetLocalSettingsFileProperty(TEXT("LocalApiServer"));
    if (!localApiServer.IsEmpty())
    {
        FString endpoint = TEXT("/CloudScript/ExecuteFunction");
        endpoint.RemoveFromStart(TEXT("/"));
        FString url = localApiServer + endpoint;
        manager->PlayFabRequestFullURL = url;
    }

    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.FunctionName.IsEmpty() || request.FunctionName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FunctionName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("FunctionName"), request.FunctionName);
    }
    if (request.FunctionParameter != nullptr) OutRestJsonObj->SetObjectField(TEXT("FunctionParameter"), request.FunctionParameter);
    OutRestJsonObj->SetBoolField(TEXT("GeneratePlayStreamEvent"), request.GeneratePlayStreamEvent);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabCloudScriptRequestCompleted
void UPlayFabCloudScriptAPI::HelperExecuteFunction(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessExecuteFunction.IsBound())
    {
        FCloudScriptExecuteFunctionResult ResultStruct = UPlayFabCloudScriptModelDecoder::decodeExecuteFunctionResultResponse(response.responseData);
        OnSuccessExecuteFunction.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Lists all currently registered Azure Functions for a given title. */
UPlayFabCloudScriptAPI* UPlayFabCloudScriptAPI::ListFunctions(FCloudScriptListFunctionsRequest request,
    FDelegateOnSuccessListFunctions onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabCloudScriptAPI* manager = NewObject<UPlayFabCloudScriptAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListFunctions = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabCloudScriptAPI::HelperListFunctions);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/CloudScript/ListFunctions";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabCloudScriptRequestCompleted
void UPlayFabCloudScriptAPI::HelperListFunctions(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListFunctions.IsBound())
    {
        FCloudScriptListFunctionsResult ResultStruct = UPlayFabCloudScriptModelDecoder::decodeListFunctionsResultResponse(response.responseData);
        OnSuccessListFunctions.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Lists all currently registered HTTP triggered Azure Functions for a given title. */
UPlayFabCloudScriptAPI* UPlayFabCloudScriptAPI::ListHttpFunctions(FCloudScriptListFunctionsRequest request,
    FDelegateOnSuccessListHttpFunctions onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabCloudScriptAPI* manager = NewObject<UPlayFabCloudScriptAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListHttpFunctions = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabCloudScriptAPI::HelperListHttpFunctions);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/CloudScript/ListHttpFunctions";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabCloudScriptRequestCompleted
void UPlayFabCloudScriptAPI::HelperListHttpFunctions(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListHttpFunctions.IsBound())
    {
        FCloudScriptListHttpFunctionsResult ResultStruct = UPlayFabCloudScriptModelDecoder::decodeListHttpFunctionsResultResponse(response.responseData);
        OnSuccessListHttpFunctions.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Lists all currently registered Queue triggered Azure Functions for a given title. */
UPlayFabCloudScriptAPI* UPlayFabCloudScriptAPI::ListQueuedFunctions(FCloudScriptListFunctionsRequest request,
    FDelegateOnSuccessListQueuedFunctions onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabCloudScriptAPI* manager = NewObject<UPlayFabCloudScriptAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListQueuedFunctions = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabCloudScriptAPI::HelperListQueuedFunctions);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/CloudScript/ListQueuedFunctions";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabCloudScriptRequestCompleted
void UPlayFabCloudScriptAPI::HelperListQueuedFunctions(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListQueuedFunctions.IsBound())
    {
        FCloudScriptListQueuedFunctionsResult ResultStruct = UPlayFabCloudScriptModelDecoder::decodeListQueuedFunctionsResultResponse(response.responseData);
        OnSuccessListQueuedFunctions.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Generate an entity PlayStream event for the provided function result. */
UPlayFabCloudScriptAPI* UPlayFabCloudScriptAPI::PostFunctionResultForEntityTriggeredAction(FCloudScriptPostFunctionResultForEntityTriggeredActionRequest request,
    FDelegateOnSuccessPostFunctionResultForEntityTriggeredAction onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabCloudScriptAPI* manager = NewObject<UPlayFabCloudScriptAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessPostFunctionResultForEntityTriggeredAction = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabCloudScriptAPI::HelperPostFunctionResultForEntityTriggeredAction);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/CloudScript/PostFunctionResultForEntityTriggeredAction";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.FunctionResult != nullptr) OutRestJsonObj->SetObjectField(TEXT("FunctionResult"), request.FunctionResult);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabCloudScriptRequestCompleted
void UPlayFabCloudScriptAPI::HelperPostFunctionResultForEntityTriggeredAction(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessPostFunctionResultForEntityTriggeredAction.IsBound())
    {
        FCloudScriptEmptyResult ResultStruct = UPlayFabCloudScriptModelDecoder::decodeEmptyResultResponse(response.responseData);
        OnSuccessPostFunctionResultForEntityTriggeredAction.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Generate an entity PlayStream event for the provided function result. */
UPlayFabCloudScriptAPI* UPlayFabCloudScriptAPI::PostFunctionResultForFunctionExecution(FCloudScriptPostFunctionResultForFunctionExecutionRequest request,
    FDelegateOnSuccessPostFunctionResultForFunctionExecution onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabCloudScriptAPI* manager = NewObject<UPlayFabCloudScriptAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessPostFunctionResultForFunctionExecution = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabCloudScriptAPI::HelperPostFunctionResultForFunctionExecution);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/CloudScript/PostFunctionResultForFunctionExecution";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.FunctionResult != nullptr) OutRestJsonObj->SetObjectField(TEXT("FunctionResult"), request.FunctionResult);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabCloudScriptRequestCompleted
void UPlayFabCloudScriptAPI::HelperPostFunctionResultForFunctionExecution(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessPostFunctionResultForFunctionExecution.IsBound())
    {
        FCloudScriptEmptyResult ResultStruct = UPlayFabCloudScriptModelDecoder::decodeEmptyResultResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessPostFunctionResultForFunctionExecution.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Generate a player PlayStream event for the provided function result. */
UPlayFabCloudScriptAPI* UPlayFabCloudScriptAPI::PostFunctionResultForPlayerTriggeredAction(FCloudScriptPostFunctionResultForPlayerTriggeredActionRequest request,
    FDelegateOnSuccessPostFunctionResultForPlayerTriggeredAction onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabCloudScriptAPI* manager = NewObject<UPlayFabCloudScriptAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessPostFunctionResultForPlayerTriggeredAction = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabCloudScriptAPI::HelperPostFunctionResultForPlayerTriggeredAction);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/CloudScript/PostFunctionResultForPlayerTriggeredAction";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.FunctionResult != nullptr) OutRestJsonObj->SetObjectField(TEXT("FunctionResult"), request.FunctionResult);
    if (request.PlayerProfile != nullptr) OutRestJsonObj->SetObjectField(TEXT("PlayerProfile"), request.PlayerProfile);
    if (request.PlayStreamEventEnvelope != nullptr) OutRestJsonObj->SetObjectField(TEXT("PlayStreamEventEnvelope"), request.PlayStreamEventEnvelope);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabCloudScriptRequestCompleted
void UPlayFabCloudScriptAPI::HelperPostFunctionResultForPlayerTriggeredAction(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessPostFunctionResultForPlayerTriggeredAction.IsBound())
    {
        FCloudScriptEmptyResult ResultStruct = UPlayFabCloudScriptModelDecoder::decodeEmptyResultResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessPostFunctionResultForPlayerTriggeredAction.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Generate a PlayStream event for the provided function result. */
UPlayFabCloudScriptAPI* UPlayFabCloudScriptAPI::PostFunctionResultForScheduledTask(FCloudScriptPostFunctionResultForScheduledTaskRequest request,
    FDelegateOnSuccessPostFunctionResultForScheduledTask onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabCloudScriptAPI* manager = NewObject<UPlayFabCloudScriptAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessPostFunctionResultForScheduledTask = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabCloudScriptAPI::HelperPostFunctionResultForScheduledTask);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/CloudScript/PostFunctionResultForScheduledTask";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.FunctionResult != nullptr) OutRestJsonObj->SetObjectField(TEXT("FunctionResult"), request.FunctionResult);
    if (request.ScheduledTaskId != nullptr) OutRestJsonObj->SetObjectField(TEXT("ScheduledTaskId"), request.ScheduledTaskId);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabCloudScriptRequestCompleted
void UPlayFabCloudScriptAPI::HelperPostFunctionResultForScheduledTask(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessPostFunctionResultForScheduledTask.IsBound())
    {
        FCloudScriptEmptyResult ResultStruct = UPlayFabCloudScriptModelDecoder::decodeEmptyResultResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessPostFunctionResultForScheduledTask.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Registers an HTTP triggered Azure function with a title. */
UPlayFabCloudScriptAPI* UPlayFabCloudScriptAPI::RegisterHttpFunction(FCloudScriptRegisterHttpFunctionRequest request,
    FDelegateOnSuccessRegisterHttpFunction onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabCloudScriptAPI* manager = NewObject<UPlayFabCloudScriptAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRegisterHttpFunction = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabCloudScriptAPI::HelperRegisterHttpFunction);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/CloudScript/RegisterHttpFunction";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.FunctionName.IsEmpty() || request.FunctionName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FunctionName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("FunctionName"), request.FunctionName);
    }
    if (request.FunctionUrl.IsEmpty() || request.FunctionUrl == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FunctionUrl"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("FunctionUrl"), request.FunctionUrl);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabCloudScriptRequestCompleted
void UPlayFabCloudScriptAPI::HelperRegisterHttpFunction(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessRegisterHttpFunction.IsBound())
    {
        FCloudScriptEmptyResult ResultStruct = UPlayFabCloudScriptModelDecoder::decodeEmptyResultResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessRegisterHttpFunction.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Registers a queue triggered Azure Function with a title. */
UPlayFabCloudScriptAPI* UPlayFabCloudScriptAPI::RegisterQueuedFunction(FCloudScriptRegisterQueuedFunctionRequest request,
    FDelegateOnSuccessRegisterQueuedFunction onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabCloudScriptAPI* manager = NewObject<UPlayFabCloudScriptAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRegisterQueuedFunction = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabCloudScriptAPI::HelperRegisterQueuedFunction);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/CloudScript/RegisterQueuedFunction";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.ConnectionString.IsEmpty() || request.ConnectionString == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ConnectionString"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ConnectionString"), request.ConnectionString);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.FunctionName.IsEmpty() || request.FunctionName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FunctionName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("FunctionName"), request.FunctionName);
    }
    if (request.QueueName.IsEmpty() || request.QueueName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("QueueName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("QueueName"), request.QueueName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabCloudScriptRequestCompleted
void UPlayFabCloudScriptAPI::HelperRegisterQueuedFunction(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessRegisterQueuedFunction.IsBound())
    {
        FCloudScriptEmptyResult ResultStruct = UPlayFabCloudScriptModelDecoder::decodeEmptyResultResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessRegisterQueuedFunction.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Unregisters an Azure Function with a title. */
UPlayFabCloudScriptAPI* UPlayFabCloudScriptAPI::UnregisterFunction(FCloudScriptUnregisterFunctionRequest request,
    FDelegateOnSuccessUnregisterFunction onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabCloudScriptAPI* manager = NewObject<UPlayFabCloudScriptAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUnregisterFunction = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabCloudScriptAPI::HelperUnregisterFunction);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/CloudScript/UnregisterFunction";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.FunctionName.IsEmpty() || request.FunctionName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FunctionName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("FunctionName"), request.FunctionName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabCloudScriptRequestCompleted
void UPlayFabCloudScriptAPI::HelperUnregisterFunction(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUnregisterFunction.IsBound())
    {
        FCloudScriptEmptyResult ResultStruct = UPlayFabCloudScriptModelDecoder::decodeEmptyResultResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessUnregisterFunction.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}



void UPlayFabCloudScriptAPI::OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
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

void UPlayFabCloudScriptAPI::Activate()
{
    IPlayFab* pfSettings = &(IPlayFab::Get());

    FString RequestUrl;
    RequestUrl = this->PlayFabRequestFullURL.IsEmpty() ? pfSettings->GeneratePfUrl(PlayFabRequestURL) : this->PlayFabRequestFullURL;


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
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UPlayFabCloudScriptAPI::OnProcessRequestComplete);

    // Execute the request
    pfSettings->ModifyPendingCallCount(1);
    HttpRequest->ProcessRequest();
}

void UPlayFabCloudScriptAPI::ResetResponseData()
{
    if (ResponseJsonObj != nullptr)
        ResponseJsonObj->Reset();
    else
        ResponseJsonObj = NewObject<UPlayFabJsonObject>();
    bIsValidJsonResponse = false;
}
