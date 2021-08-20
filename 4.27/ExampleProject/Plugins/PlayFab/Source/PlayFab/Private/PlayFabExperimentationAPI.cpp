//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
//
// API: Experimentation
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabExperimentationAPI.h"
#include "PlayFabExperimentationModels.h"
#include "PlayFabExperimentationModelDecoder.h"
#include "PlayFabPrivate.h"
#include "PlayFabEnums.h"
#include "PlayFabCommon/Public/PlayFabAuthenticationContext.h"
#include "PlayFabCommon/Public/PlayFabCommonUtils.h"

UPlayFabExperimentationAPI::UPlayFabExperimentationAPI(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , CallAuthenticationContext(nullptr)
{
}

void UPlayFabExperimentationAPI::SetCallAuthenticationContext(UPlayFabAuthenticationContext* InAuthenticationContext)
{
    CallAuthenticationContext = InAuthenticationContext;
}

void UPlayFabExperimentationAPI::SetRequestObject(UPlayFabJsonObject* JsonObject)
{
    RequestJsonObj = JsonObject;
}

UPlayFabJsonObject* UPlayFabExperimentationAPI::GetResponseObject()
{
    return ResponseJsonObj;
}

FString UPlayFabExperimentationAPI::PercentEncode(const FString& Text)
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
// Generated PlayFab Experimentation API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Experimentation
//////////////////////////////////////////////////////
/** Creates a new experiment exclusion group for a title. */
UPlayFabExperimentationAPI* UPlayFabExperimentationAPI::CreateExclusionGroup(FExperimentationCreateExclusionGroupRequest request,
    FDelegateOnSuccessCreateExclusionGroup onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabExperimentationAPI* manager = NewObject<UPlayFabExperimentationAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateExclusionGroup = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabExperimentationAPI::HelperCreateExclusionGroup);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Experimentation/CreateExclusionGroup";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Description.IsEmpty() || request.Description == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Description"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Description"), request.Description);
    }
    if (request.Name.IsEmpty() || request.Name == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Name"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Name"), request.Name);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabExperimentationRequestCompleted
void UPlayFabExperimentationAPI::HelperCreateExclusionGroup(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateExclusionGroup.IsBound())
    {
        FExperimentationCreateExclusionGroupResult ResultStruct = UPlayFabExperimentationModelDecoder::decodeCreateExclusionGroupResultResponse(response.responseData);
        OnSuccessCreateExclusionGroup.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Creates a new experiment for a title. */
UPlayFabExperimentationAPI* UPlayFabExperimentationAPI::CreateExperiment(FExperimentationCreateExperimentRequest request,
    FDelegateOnSuccessCreateExperiment onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabExperimentationAPI* manager = NewObject<UPlayFabExperimentationAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateExperiment = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabExperimentationAPI::HelperCreateExperiment);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Experimentation/CreateExperiment";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Description.IsEmpty() || request.Description == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Description"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Description"), request.Description);
    }
    if (request.EndDate.IsEmpty() || request.EndDate == "") {
        OutRestJsonObj->SetFieldNull(TEXT("EndDate"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("EndDate"), request.EndDate);
    }
    if (request.ExclusionGroupId.IsEmpty() || request.ExclusionGroupId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ExclusionGroupId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ExclusionGroupId"), request.ExclusionGroupId);
    }
    OutRestJsonObj->SetNumberField(TEXT("ExclusionGroupTrafficAllocation"), request.ExclusionGroupTrafficAllocation);
    FString temp_ExperimentType;
    if (GetEnumValueToString<EExperimentType>(TEXT("EExperimentType"), request.ExperimentType, temp_ExperimentType))
        OutRestJsonObj->SetStringField(TEXT("ExperimentType"), temp_ExperimentType);
    if (request.Name.IsEmpty() || request.Name == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Name"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Name"), request.Name);
    }
    if (request.SegmentId.IsEmpty() || request.SegmentId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SegmentId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SegmentId"), request.SegmentId);
    }
    if (request.StartDate.IsEmpty() || request.StartDate == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StartDate"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StartDate"), request.StartDate);
    }
    // Check to see if string is empty
    if (request.TitlePlayerAccountTestIds.IsEmpty() || request.TitlePlayerAccountTestIds == "") {
        OutRestJsonObj->SetFieldNull(TEXT("TitlePlayerAccountTestIds"));
    } else {
        TArray<FString> TitlePlayerAccountTestIdsArray;
        FString(request.TitlePlayerAccountTestIds).ParseIntoArray(TitlePlayerAccountTestIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("TitlePlayerAccountTestIds"), TitlePlayerAccountTestIdsArray);
    }
    if (request.Variants.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Variants"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Variants"), request.Variants);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabExperimentationRequestCompleted
void UPlayFabExperimentationAPI::HelperCreateExperiment(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateExperiment.IsBound())
    {
        FExperimentationCreateExperimentResult ResultStruct = UPlayFabExperimentationModelDecoder::decodeCreateExperimentResultResponse(response.responseData);
        OnSuccessCreateExperiment.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes an existing exclusion group for a title. */
UPlayFabExperimentationAPI* UPlayFabExperimentationAPI::DeleteExclusionGroup(FExperimentationDeleteExclusionGroupRequest request,
    FDelegateOnSuccessDeleteExclusionGroup onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabExperimentationAPI* manager = NewObject<UPlayFabExperimentationAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteExclusionGroup = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabExperimentationAPI::HelperDeleteExclusionGroup);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Experimentation/DeleteExclusionGroup";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.ExclusionGroupId.IsEmpty() || request.ExclusionGroupId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ExclusionGroupId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ExclusionGroupId"), request.ExclusionGroupId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabExperimentationRequestCompleted
void UPlayFabExperimentationAPI::HelperDeleteExclusionGroup(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteExclusionGroup.IsBound())
    {
        FExperimentationEmptyResponse ResultStruct = UPlayFabExperimentationModelDecoder::decodeEmptyResponseResponse(response.responseData);
        OnSuccessDeleteExclusionGroup.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes an existing experiment for a title. */
UPlayFabExperimentationAPI* UPlayFabExperimentationAPI::DeleteExperiment(FExperimentationDeleteExperimentRequest request,
    FDelegateOnSuccessDeleteExperiment onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabExperimentationAPI* manager = NewObject<UPlayFabExperimentationAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteExperiment = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabExperimentationAPI::HelperDeleteExperiment);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Experimentation/DeleteExperiment";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.ExperimentId.IsEmpty() || request.ExperimentId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ExperimentId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ExperimentId"), request.ExperimentId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabExperimentationRequestCompleted
void UPlayFabExperimentationAPI::HelperDeleteExperiment(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteExperiment.IsBound())
    {
        FExperimentationEmptyResponse ResultStruct = UPlayFabExperimentationModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessDeleteExperiment.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets the details of all exclusion groups for a title. */
UPlayFabExperimentationAPI* UPlayFabExperimentationAPI::GetExclusionGroups(FExperimentationGetExclusionGroupsRequest request,
    FDelegateOnSuccessGetExclusionGroups onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabExperimentationAPI* manager = NewObject<UPlayFabExperimentationAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetExclusionGroups = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabExperimentationAPI::HelperGetExclusionGroups);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Experimentation/GetExclusionGroups";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabExperimentationRequestCompleted
void UPlayFabExperimentationAPI::HelperGetExclusionGroups(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetExclusionGroups.IsBound())
    {
        FExperimentationGetExclusionGroupsResult ResultStruct = UPlayFabExperimentationModelDecoder::decodeGetExclusionGroupsResultResponse(response.responseData);
        OnSuccessGetExclusionGroups.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets the details of all exclusion groups for a title. */
UPlayFabExperimentationAPI* UPlayFabExperimentationAPI::GetExclusionGroupTraffic(FExperimentationGetExclusionGroupTrafficRequest request,
    FDelegateOnSuccessGetExclusionGroupTraffic onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabExperimentationAPI* manager = NewObject<UPlayFabExperimentationAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetExclusionGroupTraffic = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabExperimentationAPI::HelperGetExclusionGroupTraffic);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Experimentation/GetExclusionGroupTraffic";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.ExclusionGroupId.IsEmpty() || request.ExclusionGroupId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ExclusionGroupId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ExclusionGroupId"), request.ExclusionGroupId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabExperimentationRequestCompleted
void UPlayFabExperimentationAPI::HelperGetExclusionGroupTraffic(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetExclusionGroupTraffic.IsBound())
    {
        FExperimentationGetExclusionGroupTrafficResult ResultStruct = UPlayFabExperimentationModelDecoder::decodeGetExclusionGroupTrafficResultResponse(response.responseData);
        OnSuccessGetExclusionGroupTraffic.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets the details of all experiments for a title. */
UPlayFabExperimentationAPI* UPlayFabExperimentationAPI::GetExperiments(FExperimentationGetExperimentsRequest request,
    FDelegateOnSuccessGetExperiments onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabExperimentationAPI* manager = NewObject<UPlayFabExperimentationAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetExperiments = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabExperimentationAPI::HelperGetExperiments);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Experimentation/GetExperiments";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabExperimentationRequestCompleted
void UPlayFabExperimentationAPI::HelperGetExperiments(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetExperiments.IsBound())
    {
        FExperimentationGetExperimentsResult ResultStruct = UPlayFabExperimentationModelDecoder::decodeGetExperimentsResultResponse(response.responseData);
        OnSuccessGetExperiments.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets the latest scorecard of the experiment for the title. */
UPlayFabExperimentationAPI* UPlayFabExperimentationAPI::GetLatestScorecard(FExperimentationGetLatestScorecardRequest request,
    FDelegateOnSuccessGetLatestScorecard onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabExperimentationAPI* manager = NewObject<UPlayFabExperimentationAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetLatestScorecard = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabExperimentationAPI::HelperGetLatestScorecard);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Experimentation/GetLatestScorecard";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.ExperimentId.IsEmpty() || request.ExperimentId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ExperimentId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ExperimentId"), request.ExperimentId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabExperimentationRequestCompleted
void UPlayFabExperimentationAPI::HelperGetLatestScorecard(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetLatestScorecard.IsBound())
    {
        FExperimentationGetLatestScorecardResult ResultStruct = UPlayFabExperimentationModelDecoder::decodeGetLatestScorecardResultResponse(response.responseData);
        OnSuccessGetLatestScorecard.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets the treatment assignments for a player for every running experiment in the title. */
UPlayFabExperimentationAPI* UPlayFabExperimentationAPI::GetTreatmentAssignment(FExperimentationGetTreatmentAssignmentRequest request,
    FDelegateOnSuccessGetTreatmentAssignment onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabExperimentationAPI* manager = NewObject<UPlayFabExperimentationAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetTreatmentAssignment = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabExperimentationAPI::HelperGetTreatmentAssignment);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Experimentation/GetTreatmentAssignment";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabExperimentationRequestCompleted
void UPlayFabExperimentationAPI::HelperGetTreatmentAssignment(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetTreatmentAssignment.IsBound())
    {
        FExperimentationGetTreatmentAssignmentResult ResultStruct = UPlayFabExperimentationModelDecoder::decodeGetTreatmentAssignmentResultResponse(response.responseData);
        OnSuccessGetTreatmentAssignment.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Starts an existing experiment for a title. */
UPlayFabExperimentationAPI* UPlayFabExperimentationAPI::StartExperiment(FExperimentationStartExperimentRequest request,
    FDelegateOnSuccessStartExperiment onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabExperimentationAPI* manager = NewObject<UPlayFabExperimentationAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessStartExperiment = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabExperimentationAPI::HelperStartExperiment);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Experimentation/StartExperiment";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.ExperimentId.IsEmpty() || request.ExperimentId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ExperimentId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ExperimentId"), request.ExperimentId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabExperimentationRequestCompleted
void UPlayFabExperimentationAPI::HelperStartExperiment(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessStartExperiment.IsBound())
    {
        FExperimentationEmptyResponse ResultStruct = UPlayFabExperimentationModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessStartExperiment.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Stops an existing experiment for a title. */
UPlayFabExperimentationAPI* UPlayFabExperimentationAPI::StopExperiment(FExperimentationStopExperimentRequest request,
    FDelegateOnSuccessStopExperiment onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabExperimentationAPI* manager = NewObject<UPlayFabExperimentationAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessStopExperiment = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabExperimentationAPI::HelperStopExperiment);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Experimentation/StopExperiment";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.ExperimentId.IsEmpty() || request.ExperimentId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ExperimentId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ExperimentId"), request.ExperimentId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabExperimentationRequestCompleted
void UPlayFabExperimentationAPI::HelperStopExperiment(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessStopExperiment.IsBound())
    {
        FExperimentationEmptyResponse ResultStruct = UPlayFabExperimentationModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessStopExperiment.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Updates an existing exclusion group for a title. */
UPlayFabExperimentationAPI* UPlayFabExperimentationAPI::UpdateExclusionGroup(FExperimentationUpdateExclusionGroupRequest request,
    FDelegateOnSuccessUpdateExclusionGroup onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabExperimentationAPI* manager = NewObject<UPlayFabExperimentationAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateExclusionGroup = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabExperimentationAPI::HelperUpdateExclusionGroup);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Experimentation/UpdateExclusionGroup";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Description.IsEmpty() || request.Description == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Description"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Description"), request.Description);
    }
    if (request.ExclusionGroupId.IsEmpty() || request.ExclusionGroupId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ExclusionGroupId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ExclusionGroupId"), request.ExclusionGroupId);
    }
    if (request.Name.IsEmpty() || request.Name == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Name"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Name"), request.Name);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabExperimentationRequestCompleted
void UPlayFabExperimentationAPI::HelperUpdateExclusionGroup(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdateExclusionGroup.IsBound())
    {
        FExperimentationEmptyResponse ResultStruct = UPlayFabExperimentationModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessUpdateExclusionGroup.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Updates an existing experiment for a title. */
UPlayFabExperimentationAPI* UPlayFabExperimentationAPI::UpdateExperiment(FExperimentationUpdateExperimentRequest request,
    FDelegateOnSuccessUpdateExperiment onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabExperimentationAPI* manager = NewObject<UPlayFabExperimentationAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateExperiment = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabExperimentationAPI::HelperUpdateExperiment);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Experimentation/UpdateExperiment";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Description.IsEmpty() || request.Description == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Description"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Description"), request.Description);
    }
    if (request.EndDate.IsEmpty() || request.EndDate == "") {
        OutRestJsonObj->SetFieldNull(TEXT("EndDate"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("EndDate"), request.EndDate);
    }
    if (request.ExclusionGroupId.IsEmpty() || request.ExclusionGroupId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ExclusionGroupId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ExclusionGroupId"), request.ExclusionGroupId);
    }
    OutRestJsonObj->SetNumberField(TEXT("ExclusionGroupTrafficAllocation"), request.ExclusionGroupTrafficAllocation);
    FString temp_ExperimentType;
    if (GetEnumValueToString<EExperimentType>(TEXT("EExperimentType"), request.ExperimentType, temp_ExperimentType))
        OutRestJsonObj->SetStringField(TEXT("ExperimentType"), temp_ExperimentType);
    if (request.Id.IsEmpty() || request.Id == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Id"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Id"), request.Id);
    }
    if (request.Name.IsEmpty() || request.Name == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Name"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Name"), request.Name);
    }
    if (request.SegmentId.IsEmpty() || request.SegmentId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SegmentId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SegmentId"), request.SegmentId);
    }
    if (request.StartDate.IsEmpty() || request.StartDate == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StartDate"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StartDate"), request.StartDate);
    }
    // Check to see if string is empty
    if (request.TitlePlayerAccountTestIds.IsEmpty() || request.TitlePlayerAccountTestIds == "") {
        OutRestJsonObj->SetFieldNull(TEXT("TitlePlayerAccountTestIds"));
    } else {
        TArray<FString> TitlePlayerAccountTestIdsArray;
        FString(request.TitlePlayerAccountTestIds).ParseIntoArray(TitlePlayerAccountTestIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("TitlePlayerAccountTestIds"), TitlePlayerAccountTestIdsArray);
    }
    if (request.Variants.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Variants"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Variants"), request.Variants);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabExperimentationRequestCompleted
void UPlayFabExperimentationAPI::HelperUpdateExperiment(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdateExperiment.IsBound())
    {
        FExperimentationEmptyResponse ResultStruct = UPlayFabExperimentationModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessUpdateExperiment.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}



void UPlayFabExperimentationAPI::OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
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

void UPlayFabExperimentationAPI::Activate()
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
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UPlayFabExperimentationAPI::OnProcessRequestComplete);

    // Execute the request
    pfSettings->ModifyPendingCallCount(1);
    HttpRequest->ProcessRequest();
}

void UPlayFabExperimentationAPI::ResetResponseData()
{
    if (ResponseJsonObj != nullptr)
        ResponseJsonObj->Reset();
    else
        ResponseJsonObj = NewObject<UPlayFabJsonObject>();
    bIsValidJsonResponse = false;
}
