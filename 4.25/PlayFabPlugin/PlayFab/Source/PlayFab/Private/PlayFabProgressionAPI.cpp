//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
//
// API: Progression
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabProgressionAPI.h"
#include "PlayFabProgressionModels.h"
#include "PlayFabProgressionModelDecoder.h"
#include "PlayFabPrivate.h"
#include "PlayFabEnums.h"
#include "PlayFabCommon/Public/PlayFabAuthenticationContext.h"
#include "PlayFabCommon/Public/PlayFabCommonUtils.h"

UPlayFabProgressionAPI::UPlayFabProgressionAPI(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , CallAuthenticationContext(nullptr)
{
}

void UPlayFabProgressionAPI::SetCallAuthenticationContext(UPlayFabAuthenticationContext* InAuthenticationContext)
{
    CallAuthenticationContext = InAuthenticationContext;
}

void UPlayFabProgressionAPI::SetRequestObject(UPlayFabJsonObject* JsonObject)
{
    RequestJsonObj = JsonObject;
}

UPlayFabJsonObject* UPlayFabProgressionAPI::GetResponseObject()
{
    return ResponseJsonObj;
}

FString UPlayFabProgressionAPI::PercentEncode(const FString& Text)
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
// Generated PlayFab Progression API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Leaderboards
//////////////////////////////////////////////////////
/** Creates a new leaderboard definition. */
UPlayFabProgressionAPI* UPlayFabProgressionAPI::CreateLeaderboardDefinition(FProgressionCreateLeaderboardDefinitionRequest request,
    FDelegateOnSuccessCreateLeaderboardDefinition onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProgressionAPI* manager = NewObject<UPlayFabProgressionAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateLeaderboardDefinition = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProgressionAPI::HelperCreateLeaderboardDefinition);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Leaderboard/CreateLeaderboardDefinition";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.Columns.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Columns"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Columns"), request.Columns);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.EntityType.IsEmpty() || request.EntityType == "") {
        OutRestJsonObj->SetFieldNull(TEXT("EntityType"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("EntityType"), request.EntityType);
    }
    if (request.Name.IsEmpty() || request.Name == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Name"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Name"), request.Name);
    }
    OutRestJsonObj->SetNumberField(TEXT("SizeLimit"), request.SizeLimit);
    if (request.VersionConfiguration != nullptr) OutRestJsonObj->SetObjectField(TEXT("VersionConfiguration"), request.VersionConfiguration);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabProgressionRequestCompleted
void UPlayFabProgressionAPI::HelperCreateLeaderboardDefinition(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateLeaderboardDefinition.IsBound())
    {
        FProgressionEmptyResponse ResultStruct = UPlayFabProgressionModelDecoder::decodeEmptyResponseResponse(response.responseData);
        OnSuccessCreateLeaderboardDefinition.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes a leaderboard definition. */
UPlayFabProgressionAPI* UPlayFabProgressionAPI::DeleteLeaderboardDefinition(FProgressionDeleteLeaderboardDefinitionRequest request,
    FDelegateOnSuccessDeleteLeaderboardDefinition onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProgressionAPI* manager = NewObject<UPlayFabProgressionAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteLeaderboardDefinition = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProgressionAPI::HelperDeleteLeaderboardDefinition);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Leaderboard/DeleteLeaderboardDefinition";
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

// Implements FOnPlayFabProgressionRequestCompleted
void UPlayFabProgressionAPI::HelperDeleteLeaderboardDefinition(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteLeaderboardDefinition.IsBound())
    {
        FProgressionEmptyResponse ResultStruct = UPlayFabProgressionModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessDeleteLeaderboardDefinition.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes the specified entries from the given leaderboard. */
UPlayFabProgressionAPI* UPlayFabProgressionAPI::DeleteLeaderboardEntries(FProgressionDeleteLeaderboardEntriesRequest request,
    FDelegateOnSuccessDeleteLeaderboardEntries onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProgressionAPI* manager = NewObject<UPlayFabProgressionAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteLeaderboardEntries = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProgressionAPI::HelperDeleteLeaderboardEntries);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Leaderboard/DeleteLeaderboardEntries";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    // Check to see if string is empty
    if (request.EntityIds.IsEmpty() || request.EntityIds == "") {
        OutRestJsonObj->SetFieldNull(TEXT("EntityIds"));
    } else {
        TArray<FString> EntityIdsArray;
        FString(request.EntityIds).ParseIntoArray(EntityIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("EntityIds"), EntityIdsArray);
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

// Implements FOnPlayFabProgressionRequestCompleted
void UPlayFabProgressionAPI::HelperDeleteLeaderboardEntries(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteLeaderboardEntries.IsBound())
    {
        FProgressionEmptyResponse ResultStruct = UPlayFabProgressionModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessDeleteLeaderboardEntries.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Get the friend leaderboard for the specified entity. A maximum of 25 friend entries are listed in the leaderboard. */
UPlayFabProgressionAPI* UPlayFabProgressionAPI::GetFriendLeaderboardForEntity(FProgressionGetFriendLeaderboardForEntityRequest request,
    FDelegateOnSuccessGetFriendLeaderboardForEntity onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProgressionAPI* manager = NewObject<UPlayFabProgressionAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetFriendLeaderboardForEntity = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProgressionAPI::HelperGetFriendLeaderboardForEntity);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Leaderboard/GetFriendLeaderboardForEntity";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    FString temp_ExternalFriendSources;
    if (GetEnumValueToString<EExternalFriendSources>(TEXT("EExternalFriendSources"), request.ExternalFriendSources, temp_ExternalFriendSources))
        OutRestJsonObj->SetStringField(TEXT("ExternalFriendSources"), temp_ExternalFriendSources);
    if (request.LeaderboardName.IsEmpty() || request.LeaderboardName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("LeaderboardName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("LeaderboardName"), request.LeaderboardName);
    }
    OutRestJsonObj->SetNumberField(TEXT("Version"), request.Version);
    if (request.XboxToken.IsEmpty() || request.XboxToken == "") {
        OutRestJsonObj->SetFieldNull(TEXT("XboxToken"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("XboxToken"), request.XboxToken);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabProgressionRequestCompleted
void UPlayFabProgressionAPI::HelperGetFriendLeaderboardForEntity(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetFriendLeaderboardForEntity.IsBound())
    {
        FProgressionGetEntityLeaderboardResponse ResultStruct = UPlayFabProgressionModelDecoder::decodeGetEntityLeaderboardResponseResponse(response.responseData);
        OnSuccessGetFriendLeaderboardForEntity.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Get the leaderboard for a specific entity type and statistic. */
UPlayFabProgressionAPI* UPlayFabProgressionAPI::GetLeaderboard(FProgressionGetEntityLeaderboardRequest request,
    FDelegateOnSuccessGetLeaderboard onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProgressionAPI* manager = NewObject<UPlayFabProgressionAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetLeaderboard = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProgressionAPI::HelperGetLeaderboard);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Leaderboard/GetLeaderboard";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.LeaderboardName.IsEmpty() || request.LeaderboardName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("LeaderboardName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("LeaderboardName"), request.LeaderboardName);
    }
    OutRestJsonObj->SetNumberField(TEXT("PageSize"), request.PageSize);
    OutRestJsonObj->SetNumberField(TEXT("StartingPosition"), request.StartingPosition);
    OutRestJsonObj->SetNumberField(TEXT("Version"), request.Version);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabProgressionRequestCompleted
void UPlayFabProgressionAPI::HelperGetLeaderboard(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetLeaderboard.IsBound())
    {
        FProgressionGetEntityLeaderboardResponse ResultStruct = UPlayFabProgressionModelDecoder::decodeGetEntityLeaderboardResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessGetLeaderboard.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Get the leaderboard around a specific entity. */
UPlayFabProgressionAPI* UPlayFabProgressionAPI::GetLeaderboardAroundEntity(FProgressionGetLeaderboardAroundEntityRequest request,
    FDelegateOnSuccessGetLeaderboardAroundEntity onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProgressionAPI* manager = NewObject<UPlayFabProgressionAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetLeaderboardAroundEntity = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProgressionAPI::HelperGetLeaderboardAroundEntity);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Leaderboard/GetLeaderboardAroundEntity";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.LeaderboardName.IsEmpty() || request.LeaderboardName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("LeaderboardName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("LeaderboardName"), request.LeaderboardName);
    }
    OutRestJsonObj->SetNumberField(TEXT("MaxSurroundingEntries"), request.MaxSurroundingEntries);
    OutRestJsonObj->SetNumberField(TEXT("Version"), request.Version);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabProgressionRequestCompleted
void UPlayFabProgressionAPI::HelperGetLeaderboardAroundEntity(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetLeaderboardAroundEntity.IsBound())
    {
        FProgressionGetEntityLeaderboardResponse ResultStruct = UPlayFabProgressionModelDecoder::decodeGetEntityLeaderboardResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessGetLeaderboardAroundEntity.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets the specified leaderboard definition. */
UPlayFabProgressionAPI* UPlayFabProgressionAPI::GetLeaderboardDefinition(FProgressionGetLeaderboardDefinitionRequest request,
    FDelegateOnSuccessGetLeaderboardDefinition onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProgressionAPI* manager = NewObject<UPlayFabProgressionAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetLeaderboardDefinition = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProgressionAPI::HelperGetLeaderboardDefinition);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Leaderboard/GetLeaderboardDefinition";
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

// Implements FOnPlayFabProgressionRequestCompleted
void UPlayFabProgressionAPI::HelperGetLeaderboardDefinition(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetLeaderboardDefinition.IsBound())
    {
        FProgressionGetLeaderboardDefinitionResponse ResultStruct = UPlayFabProgressionModelDecoder::decodeGetLeaderboardDefinitionResponseResponse(response.responseData);
        OnSuccessGetLeaderboardDefinition.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Get the leaderboard limited to a set of entities. */
UPlayFabProgressionAPI* UPlayFabProgressionAPI::GetLeaderboardForEntities(FProgressionGetLeaderboardForEntitiesRequest request,
    FDelegateOnSuccessGetLeaderboardForEntities onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProgressionAPI* manager = NewObject<UPlayFabProgressionAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetLeaderboardForEntities = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProgressionAPI::HelperGetLeaderboardForEntities);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Leaderboard/GetLeaderboardForEntities";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    // Check to see if string is empty
    if (request.EntityIds.IsEmpty() || request.EntityIds == "") {
        OutRestJsonObj->SetFieldNull(TEXT("EntityIds"));
    } else {
        TArray<FString> EntityIdsArray;
        FString(request.EntityIds).ParseIntoArray(EntityIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("EntityIds"), EntityIdsArray);
    }
    if (request.LeaderboardName.IsEmpty() || request.LeaderboardName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("LeaderboardName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("LeaderboardName"), request.LeaderboardName);
    }
    OutRestJsonObj->SetNumberField(TEXT("Version"), request.Version);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabProgressionRequestCompleted
void UPlayFabProgressionAPI::HelperGetLeaderboardForEntities(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetLeaderboardForEntities.IsBound())
    {
        FProgressionGetEntityLeaderboardResponse ResultStruct = UPlayFabProgressionModelDecoder::decodeGetEntityLeaderboardResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessGetLeaderboardForEntities.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Increment a leaderboard version. */
UPlayFabProgressionAPI* UPlayFabProgressionAPI::IncrementLeaderboardVersion(FProgressionIncrementLeaderboardVersionRequest request,
    FDelegateOnSuccessIncrementLeaderboardVersion onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProgressionAPI* manager = NewObject<UPlayFabProgressionAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessIncrementLeaderboardVersion = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProgressionAPI::HelperIncrementLeaderboardVersion);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Leaderboard/IncrementLeaderboardVersion";
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

// Implements FOnPlayFabProgressionRequestCompleted
void UPlayFabProgressionAPI::HelperIncrementLeaderboardVersion(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessIncrementLeaderboardVersion.IsBound())
    {
        FProgressionIncrementLeaderboardVersionResponse ResultStruct = UPlayFabProgressionModelDecoder::decodeIncrementLeaderboardVersionResponseResponse(response.responseData);
        OnSuccessIncrementLeaderboardVersion.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Lists the leaderboard definitions defined for the Title. */
UPlayFabProgressionAPI* UPlayFabProgressionAPI::ListLeaderboardDefinitions(FProgressionListLeaderboardDefinitionsRequest request,
    FDelegateOnSuccessListLeaderboardDefinitions onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProgressionAPI* manager = NewObject<UPlayFabProgressionAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListLeaderboardDefinitions = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProgressionAPI::HelperListLeaderboardDefinitions);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Leaderboard/ListLeaderboardDefinitions";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabProgressionRequestCompleted
void UPlayFabProgressionAPI::HelperListLeaderboardDefinitions(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListLeaderboardDefinitions.IsBound())
    {
        FProgressionListLeaderboardDefinitionsResponse ResultStruct = UPlayFabProgressionModelDecoder::decodeListLeaderboardDefinitionsResponseResponse(response.responseData);
        OnSuccessListLeaderboardDefinitions.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Unlinks a leaderboard definition from it's linked statistic definition. */
UPlayFabProgressionAPI* UPlayFabProgressionAPI::UnlinkLeaderboardFromStatistic(FProgressionUnlinkLeaderboardFromStatisticRequest request,
    FDelegateOnSuccessUnlinkLeaderboardFromStatistic onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProgressionAPI* manager = NewObject<UPlayFabProgressionAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUnlinkLeaderboardFromStatistic = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProgressionAPI::HelperUnlinkLeaderboardFromStatistic);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Leaderboard/UnlinkLeaderboardFromStatistic";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Name.IsEmpty() || request.Name == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Name"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Name"), request.Name);
    }
    if (request.StatisticName.IsEmpty() || request.StatisticName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabProgressionRequestCompleted
void UPlayFabProgressionAPI::HelperUnlinkLeaderboardFromStatistic(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUnlinkLeaderboardFromStatistic.IsBound())
    {
        FProgressionEmptyResponse ResultStruct = UPlayFabProgressionModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessUnlinkLeaderboardFromStatistic.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Adds or updates entries on the specified leaderboard. */
UPlayFabProgressionAPI* UPlayFabProgressionAPI::UpdateLeaderboardEntries(FProgressionUpdateLeaderboardEntriesRequest request,
    FDelegateOnSuccessUpdateLeaderboardEntries onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProgressionAPI* manager = NewObject<UPlayFabProgressionAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateLeaderboardEntries = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProgressionAPI::HelperUpdateLeaderboardEntries);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Leaderboard/UpdateLeaderboardEntries";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entries.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Entries"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Entries"), request.Entries);
    }
    if (request.LeaderboardName.IsEmpty() || request.LeaderboardName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("LeaderboardName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("LeaderboardName"), request.LeaderboardName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabProgressionRequestCompleted
void UPlayFabProgressionAPI::HelperUpdateLeaderboardEntries(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdateLeaderboardEntries.IsBound())
    {
        FProgressionEmptyResponse ResultStruct = UPlayFabProgressionModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessUpdateLeaderboardEntries.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}


///////////////////////////////////////////////////////
// Statistics
//////////////////////////////////////////////////////
/** Create a new entity statistic definition. */
UPlayFabProgressionAPI* UPlayFabProgressionAPI::CreateStatisticDefinition(FProgressionCreateStatisticDefinitionRequest request,
    FDelegateOnSuccessCreateStatisticDefinition onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProgressionAPI* manager = NewObject<UPlayFabProgressionAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateStatisticDefinition = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProgressionAPI::HelperCreateStatisticDefinition);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Statistic/CreateStatisticDefinition";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.Columns.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Columns"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Columns"), request.Columns);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.EntityType.IsEmpty() || request.EntityType == "") {
        OutRestJsonObj->SetFieldNull(TEXT("EntityType"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("EntityType"), request.EntityType);
    }
    if (request.Name.IsEmpty() || request.Name == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Name"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Name"), request.Name);
    }
    if (request.VersionConfiguration != nullptr) OutRestJsonObj->SetObjectField(TEXT("VersionConfiguration"), request.VersionConfiguration);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabProgressionRequestCompleted
void UPlayFabProgressionAPI::HelperCreateStatisticDefinition(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateStatisticDefinition.IsBound())
    {
        FProgressionEmptyResponse ResultStruct = UPlayFabProgressionModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessCreateStatisticDefinition.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Delete an entity statistic definition. Will delete all statistics on entity profiles and leaderboards. */
UPlayFabProgressionAPI* UPlayFabProgressionAPI::DeleteStatisticDefinition(FProgressionDeleteStatisticDefinitionRequest request,
    FDelegateOnSuccessDeleteStatisticDefinition onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProgressionAPI* manager = NewObject<UPlayFabProgressionAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteStatisticDefinition = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProgressionAPI::HelperDeleteStatisticDefinition);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Statistic/DeleteStatisticDefinition";
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

// Implements FOnPlayFabProgressionRequestCompleted
void UPlayFabProgressionAPI::HelperDeleteStatisticDefinition(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteStatisticDefinition.IsBound())
    {
        FProgressionEmptyResponse ResultStruct = UPlayFabProgressionModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessDeleteStatisticDefinition.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Delete statistics on an entity profile. This will remove all rankings from associated leaderboards. */
UPlayFabProgressionAPI* UPlayFabProgressionAPI::DeleteStatistics(FProgressionDeleteStatisticsRequest request,
    FDelegateOnSuccessDeleteStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProgressionAPI* manager = NewObject<UPlayFabProgressionAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProgressionAPI::HelperDeleteStatistics);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Statistic/DeleteStatistics";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.Statistics.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Statistics"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Statistics"), request.Statistics);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabProgressionRequestCompleted
void UPlayFabProgressionAPI::HelperDeleteStatistics(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteStatistics.IsBound())
    {
        FProgressionDeleteStatisticsResponse ResultStruct = UPlayFabProgressionModelDecoder::decodeDeleteStatisticsResponseResponse(response.responseData);
        OnSuccessDeleteStatistics.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Get current statistic definition information */
UPlayFabProgressionAPI* UPlayFabProgressionAPI::GetStatisticDefinition(FProgressionGetStatisticDefinitionRequest request,
    FDelegateOnSuccessGetStatisticDefinition onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProgressionAPI* manager = NewObject<UPlayFabProgressionAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetStatisticDefinition = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProgressionAPI::HelperGetStatisticDefinition);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Statistic/GetStatisticDefinition";
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

// Implements FOnPlayFabProgressionRequestCompleted
void UPlayFabProgressionAPI::HelperGetStatisticDefinition(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetStatisticDefinition.IsBound())
    {
        FProgressionGetStatisticDefinitionResponse ResultStruct = UPlayFabProgressionModelDecoder::decodeGetStatisticDefinitionResponseResponse(response.responseData);
        OnSuccessGetStatisticDefinition.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets statistics for the specified entity. */
UPlayFabProgressionAPI* UPlayFabProgressionAPI::GetStatistics(FProgressionGetStatisticsRequest request,
    FDelegateOnSuccessGetStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProgressionAPI* manager = NewObject<UPlayFabProgressionAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProgressionAPI::HelperGetStatistics);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Statistic/GetStatistics";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabProgressionRequestCompleted
void UPlayFabProgressionAPI::HelperGetStatistics(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetStatistics.IsBound())
    {
        FProgressionGetStatisticsResponse ResultStruct = UPlayFabProgressionModelDecoder::decodeGetStatisticsResponseResponse(response.responseData);
        OnSuccessGetStatistics.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets statistics for the specified collection of entities. */
UPlayFabProgressionAPI* UPlayFabProgressionAPI::GetStatisticsForEntities(FProgressionGetStatisticsForEntitiesRequest request,
    FDelegateOnSuccessGetStatisticsForEntities onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProgressionAPI* manager = NewObject<UPlayFabProgressionAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetStatisticsForEntities = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProgressionAPI::HelperGetStatisticsForEntities);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Statistic/GetStatisticsForEntities";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entities.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Entities"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Entities"), request.Entities);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabProgressionRequestCompleted
void UPlayFabProgressionAPI::HelperGetStatisticsForEntities(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetStatisticsForEntities.IsBound())
    {
        FProgressionGetStatisticsForEntitiesResponse ResultStruct = UPlayFabProgressionModelDecoder::decodeGetStatisticsForEntitiesResponseResponse(response.responseData);
        OnSuccessGetStatisticsForEntities.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Increment an entity statistic definition version. */
UPlayFabProgressionAPI* UPlayFabProgressionAPI::IncrementStatisticVersion(FProgressionIncrementStatisticVersionRequest request,
    FDelegateOnSuccessIncrementStatisticVersion onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProgressionAPI* manager = NewObject<UPlayFabProgressionAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessIncrementStatisticVersion = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProgressionAPI::HelperIncrementStatisticVersion);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Statistic/IncrementStatisticVersion";
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

// Implements FOnPlayFabProgressionRequestCompleted
void UPlayFabProgressionAPI::HelperIncrementStatisticVersion(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessIncrementStatisticVersion.IsBound())
    {
        FProgressionIncrementStatisticVersionResponse ResultStruct = UPlayFabProgressionModelDecoder::decodeIncrementStatisticVersionResponseResponse(response.responseData);
        OnSuccessIncrementStatisticVersion.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Get all current statistic definitions information */
UPlayFabProgressionAPI* UPlayFabProgressionAPI::ListStatisticDefinitions(FProgressionListStatisticDefinitionsRequest request,
    FDelegateOnSuccessListStatisticDefinitions onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProgressionAPI* manager = NewObject<UPlayFabProgressionAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListStatisticDefinitions = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProgressionAPI::HelperListStatisticDefinitions);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Statistic/ListStatisticDefinitions";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabProgressionRequestCompleted
void UPlayFabProgressionAPI::HelperListStatisticDefinitions(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListStatisticDefinitions.IsBound())
    {
        FProgressionListStatisticDefinitionsResponse ResultStruct = UPlayFabProgressionModelDecoder::decodeListStatisticDefinitionsResponseResponse(response.responseData);
        OnSuccessListStatisticDefinitions.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Update statistics on an entity profile. Depending on the statistic definition, this may result in entity being ranked on various leaderboards. */
UPlayFabProgressionAPI* UPlayFabProgressionAPI::UpdateStatistics(FProgressionUpdateStatisticsRequest request,
    FDelegateOnSuccessUpdateStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabProgressionAPI* manager = NewObject<UPlayFabProgressionAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabProgressionAPI::HelperUpdateStatistics);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Statistic/UpdateStatistics";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.Statistics.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Statistics"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Statistics"), request.Statistics);
    }
    if (request.TransactionId.IsEmpty() || request.TransactionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("TransactionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("TransactionId"), request.TransactionId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabProgressionRequestCompleted
void UPlayFabProgressionAPI::HelperUpdateStatistics(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdateStatistics.IsBound())
    {
        FProgressionUpdateStatisticsResponse ResultStruct = UPlayFabProgressionModelDecoder::decodeUpdateStatisticsResponseResponse(response.responseData);
        OnSuccessUpdateStatistics.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}



void UPlayFabProgressionAPI::OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
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

void UPlayFabProgressionAPI::Activate()
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
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UPlayFabProgressionAPI::OnProcessRequestComplete);

    // Execute the request
    pfSettings->ModifyPendingCallCount(1);
    HttpRequest->ProcessRequest();
}

void UPlayFabProgressionAPI::ResetResponseData()
{
    if (ResponseJsonObj != nullptr)
        ResponseJsonObj->Reset();
    else
        ResponseJsonObj = NewObject<UPlayFabJsonObject>();
    bIsValidJsonResponse = false;
}
