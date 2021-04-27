//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
//
// API: Groups
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabGroupsAPI.h"
#include "PlayFabGroupsModels.h"
#include "PlayFabGroupsModelDecoder.h"
#include "PlayFabPrivate.h"
#include "PlayFabEnums.h"
#include "PlayFabCommon/Public/PlayFabAuthenticationContext.h"
#include "PlayFabCommon/Public/PlayFabCommonUtils.h"

UPlayFabGroupsAPI::UPlayFabGroupsAPI(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , CallAuthenticationContext(nullptr)
{
}

void UPlayFabGroupsAPI::SetCallAuthenticationContext(UPlayFabAuthenticationContext* InAuthenticationContext)
{
    CallAuthenticationContext = InAuthenticationContext;
}

void UPlayFabGroupsAPI::SetRequestObject(UPlayFabJsonObject* JsonObject)
{
    RequestJsonObj = JsonObject;
}

UPlayFabJsonObject* UPlayFabGroupsAPI::GetResponseObject()
{
    return ResponseJsonObj;
}

FString UPlayFabGroupsAPI::PercentEncode(const FString& Text)
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
// Generated PlayFab Groups API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Groups
//////////////////////////////////////////////////////
/** Accepts an outstanding invitation to to join a group */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::AcceptGroupApplication(FGroupsAcceptGroupApplicationRequest request,
    FDelegateOnSuccessAcceptGroupApplication onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAcceptGroupApplication = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperAcceptGroupApplication);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/AcceptGroupApplication";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.Group != nullptr) OutRestJsonObj->SetObjectField(TEXT("Group"), request.Group);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperAcceptGroupApplication(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessAcceptGroupApplication.IsBound())
    {
        FGroupsEmptyResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeEmptyResponseResponse(response.responseData);
        OnSuccessAcceptGroupApplication.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Accepts an invitation to join a group */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::AcceptGroupInvitation(FGroupsAcceptGroupInvitationRequest request,
    FDelegateOnSuccessAcceptGroupInvitation onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAcceptGroupInvitation = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperAcceptGroupInvitation);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/AcceptGroupInvitation";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.Group != nullptr) OutRestJsonObj->SetObjectField(TEXT("Group"), request.Group);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperAcceptGroupInvitation(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessAcceptGroupInvitation.IsBound())
    {
        FGroupsEmptyResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessAcceptGroupInvitation.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Adds members to a group or role. */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::AddMembers(FGroupsAddMembersRequest request,
    FDelegateOnSuccessAddMembers onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAddMembers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperAddMembers);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/AddMembers";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Group != nullptr) OutRestJsonObj->SetObjectField(TEXT("Group"), request.Group);
    if (request.Members.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Members"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Members"), request.Members);
    }
    if (request.RoleId.IsEmpty() || request.RoleId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("RoleId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("RoleId"), request.RoleId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperAddMembers(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessAddMembers.IsBound())
    {
        FGroupsEmptyResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessAddMembers.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Applies to join a group */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::ApplyToGroup(FGroupsApplyToGroupRequest request,
    FDelegateOnSuccessApplyToGroup onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessApplyToGroup = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperApplyToGroup);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/ApplyToGroup";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    OutRestJsonObj->SetBoolField(TEXT("AutoAcceptOutstandingInvite"), request.AutoAcceptOutstandingInvite);
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.Group != nullptr) OutRestJsonObj->SetObjectField(TEXT("Group"), request.Group);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperApplyToGroup(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessApplyToGroup.IsBound())
    {
        FGroupsApplyToGroupResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeApplyToGroupResponseResponse(response.responseData);
        OnSuccessApplyToGroup.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Blocks a list of entities from joining a group. */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::BlockEntity(FGroupsBlockEntityRequest request,
    FDelegateOnSuccessBlockEntity onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessBlockEntity = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperBlockEntity);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/BlockEntity";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.Group != nullptr) OutRestJsonObj->SetObjectField(TEXT("Group"), request.Group);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperBlockEntity(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessBlockEntity.IsBound())
    {
        FGroupsEmptyResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessBlockEntity.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Changes the role membership of a list of entities from one role to another. */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::ChangeMemberRole(FGroupsChangeMemberRoleRequest request,
    FDelegateOnSuccessChangeMemberRole onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessChangeMemberRole = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperChangeMemberRole);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/ChangeMemberRole";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.DestinationRoleId.IsEmpty() || request.DestinationRoleId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("DestinationRoleId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("DestinationRoleId"), request.DestinationRoleId);
    }
    if (request.Group != nullptr) OutRestJsonObj->SetObjectField(TEXT("Group"), request.Group);
    if (request.Members.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Members"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Members"), request.Members);
    }
    if (request.OriginRoleId.IsEmpty() || request.OriginRoleId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("OriginRoleId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("OriginRoleId"), request.OriginRoleId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperChangeMemberRole(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessChangeMemberRole.IsBound())
    {
        FGroupsEmptyResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessChangeMemberRole.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Creates a new group. */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::CreateGroup(FGroupsCreateGroupRequest request,
    FDelegateOnSuccessCreateGroup onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateGroup = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperCreateGroup);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/CreateGroup";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.GroupName.IsEmpty() || request.GroupName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("GroupName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("GroupName"), request.GroupName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperCreateGroup(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateGroup.IsBound())
    {
        FGroupsCreateGroupResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeCreateGroupResponseResponse(response.responseData);
        OnSuccessCreateGroup.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Creates a new group role. */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::CreateRole(FGroupsCreateGroupRoleRequest request,
    FDelegateOnSuccessCreateRole onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateRole = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperCreateRole);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/CreateRole";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Group != nullptr) OutRestJsonObj->SetObjectField(TEXT("Group"), request.Group);
    if (request.RoleId.IsEmpty() || request.RoleId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("RoleId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("RoleId"), request.RoleId);
    }
    if (request.RoleName.IsEmpty() || request.RoleName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("RoleName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("RoleName"), request.RoleName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperCreateRole(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateRole.IsBound())
    {
        FGroupsCreateGroupRoleResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeCreateGroupRoleResponseResponse(response.responseData);
        OnSuccessCreateRole.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes a group and all roles, invitations, join requests, and blocks associated with it. */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::DeleteGroup(FGroupsDeleteGroupRequest request,
    FDelegateOnSuccessDeleteGroup onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteGroup = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperDeleteGroup);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/DeleteGroup";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Group != nullptr) OutRestJsonObj->SetObjectField(TEXT("Group"), request.Group);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperDeleteGroup(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteGroup.IsBound())
    {
        FGroupsEmptyResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessDeleteGroup.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes an existing role in a group. */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::DeleteRole(FGroupsDeleteRoleRequest request,
    FDelegateOnSuccessDeleteRole onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteRole = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperDeleteRole);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/DeleteRole";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Group != nullptr) OutRestJsonObj->SetObjectField(TEXT("Group"), request.Group);
    if (request.RoleId.IsEmpty() || request.RoleId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("RoleId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("RoleId"), request.RoleId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperDeleteRole(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteRole.IsBound())
    {
        FGroupsEmptyResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessDeleteRole.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets information about a group and its roles */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::GetGroup(FGroupsGetGroupRequest request,
    FDelegateOnSuccessGetGroup onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetGroup = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperGetGroup);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/GetGroup";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Group != nullptr) OutRestJsonObj->SetObjectField(TEXT("Group"), request.Group);
    if (request.GroupName.IsEmpty() || request.GroupName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("GroupName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("GroupName"), request.GroupName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperGetGroup(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetGroup.IsBound())
    {
        FGroupsGetGroupResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeGetGroupResponseResponse(response.responseData);
        OnSuccessGetGroup.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Invites a player to join a group */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::InviteToGroup(FGroupsInviteToGroupRequest request,
    FDelegateOnSuccessInviteToGroup onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessInviteToGroup = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperInviteToGroup);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/InviteToGroup";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    OutRestJsonObj->SetBoolField(TEXT("AutoAcceptOutstandingApplication"), request.AutoAcceptOutstandingApplication);
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.Group != nullptr) OutRestJsonObj->SetObjectField(TEXT("Group"), request.Group);
    if (request.RoleId.IsEmpty() || request.RoleId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("RoleId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("RoleId"), request.RoleId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperInviteToGroup(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessInviteToGroup.IsBound())
    {
        FGroupsInviteToGroupResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeInviteToGroupResponseResponse(response.responseData);
        OnSuccessInviteToGroup.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Checks to see if an entity is a member of a group or role within the group */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::IsMember(FGroupsIsMemberRequest request,
    FDelegateOnSuccessIsMember onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessIsMember = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperIsMember);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/IsMember";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.Group != nullptr) OutRestJsonObj->SetObjectField(TEXT("Group"), request.Group);
    if (request.RoleId.IsEmpty() || request.RoleId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("RoleId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("RoleId"), request.RoleId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperIsMember(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessIsMember.IsBound())
    {
        FGroupsIsMemberResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeIsMemberResponseResponse(response.responseData);
        OnSuccessIsMember.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Lists all outstanding requests to join a group */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::ListGroupApplications(FGroupsListGroupApplicationsRequest request,
    FDelegateOnSuccessListGroupApplications onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListGroupApplications = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperListGroupApplications);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/ListGroupApplications";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Group != nullptr) OutRestJsonObj->SetObjectField(TEXT("Group"), request.Group);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperListGroupApplications(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListGroupApplications.IsBound())
    {
        FGroupsListGroupApplicationsResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeListGroupApplicationsResponseResponse(response.responseData);
        OnSuccessListGroupApplications.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Lists all entities blocked from joining a group */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::ListGroupBlocks(FGroupsListGroupBlocksRequest request,
    FDelegateOnSuccessListGroupBlocks onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListGroupBlocks = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperListGroupBlocks);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/ListGroupBlocks";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Group != nullptr) OutRestJsonObj->SetObjectField(TEXT("Group"), request.Group);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperListGroupBlocks(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListGroupBlocks.IsBound())
    {
        FGroupsListGroupBlocksResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeListGroupBlocksResponseResponse(response.responseData);
        OnSuccessListGroupBlocks.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Lists all outstanding invitations for a group */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::ListGroupInvitations(FGroupsListGroupInvitationsRequest request,
    FDelegateOnSuccessListGroupInvitations onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListGroupInvitations = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperListGroupInvitations);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/ListGroupInvitations";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Group != nullptr) OutRestJsonObj->SetObjectField(TEXT("Group"), request.Group);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperListGroupInvitations(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListGroupInvitations.IsBound())
    {
        FGroupsListGroupInvitationsResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeListGroupInvitationsResponseResponse(response.responseData);
        OnSuccessListGroupInvitations.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Lists all members for a group */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::ListGroupMembers(FGroupsListGroupMembersRequest request,
    FDelegateOnSuccessListGroupMembers onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListGroupMembers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperListGroupMembers);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/ListGroupMembers";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Group != nullptr) OutRestJsonObj->SetObjectField(TEXT("Group"), request.Group);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperListGroupMembers(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListGroupMembers.IsBound())
    {
        FGroupsListGroupMembersResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeListGroupMembersResponseResponse(response.responseData);
        OnSuccessListGroupMembers.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Lists all groups and roles for an entity */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::ListMembership(FGroupsListMembershipRequest request,
    FDelegateOnSuccessListMembership onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListMembership = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperListMembership);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/ListMembership";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperListMembership(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListMembership.IsBound())
    {
        FGroupsListMembershipResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeListMembershipResponseResponse(response.responseData);
        OnSuccessListMembership.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Lists all outstanding invitations and group applications for an entity */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::ListMembershipOpportunities(FGroupsListMembershipOpportunitiesRequest request,
    FDelegateOnSuccessListMembershipOpportunities onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListMembershipOpportunities = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperListMembershipOpportunities);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/ListMembershipOpportunities";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperListMembershipOpportunities(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListMembershipOpportunities.IsBound())
    {
        FGroupsListMembershipOpportunitiesResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeListMembershipOpportunitiesResponseResponse(response.responseData);
        OnSuccessListMembershipOpportunities.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Removes an application to join a group */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::RemoveGroupApplication(FGroupsRemoveGroupApplicationRequest request,
    FDelegateOnSuccessRemoveGroupApplication onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRemoveGroupApplication = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperRemoveGroupApplication);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/RemoveGroupApplication";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.Group != nullptr) OutRestJsonObj->SetObjectField(TEXT("Group"), request.Group);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperRemoveGroupApplication(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessRemoveGroupApplication.IsBound())
    {
        FGroupsEmptyResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessRemoveGroupApplication.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Removes an invitation join a group */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::RemoveGroupInvitation(FGroupsRemoveGroupInvitationRequest request,
    FDelegateOnSuccessRemoveGroupInvitation onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRemoveGroupInvitation = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperRemoveGroupInvitation);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/RemoveGroupInvitation";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.Group != nullptr) OutRestJsonObj->SetObjectField(TEXT("Group"), request.Group);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperRemoveGroupInvitation(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessRemoveGroupInvitation.IsBound())
    {
        FGroupsEmptyResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessRemoveGroupInvitation.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Removes members from a group. */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::RemoveMembers(FGroupsRemoveMembersRequest request,
    FDelegateOnSuccessRemoveMembers onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRemoveMembers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperRemoveMembers);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/RemoveMembers";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Group != nullptr) OutRestJsonObj->SetObjectField(TEXT("Group"), request.Group);
    if (request.Members.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Members"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Members"), request.Members);
    }
    if (request.RoleId.IsEmpty() || request.RoleId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("RoleId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("RoleId"), request.RoleId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperRemoveMembers(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessRemoveMembers.IsBound())
    {
        FGroupsEmptyResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessRemoveMembers.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Unblocks a list of entities from joining a group */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::UnblockEntity(FGroupsUnblockEntityRequest request,
    FDelegateOnSuccessUnblockEntity onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUnblockEntity = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperUnblockEntity);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/UnblockEntity";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.Group != nullptr) OutRestJsonObj->SetObjectField(TEXT("Group"), request.Group);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperUnblockEntity(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUnblockEntity.IsBound())
    {
        FGroupsEmptyResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessUnblockEntity.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Updates non-membership data about a group. */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::UpdateGroup(FGroupsUpdateGroupRequest request,
    FDelegateOnSuccessUpdateGroup onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateGroup = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperUpdateGroup);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/UpdateGroup";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.AdminRoleId.IsEmpty() || request.AdminRoleId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("AdminRoleId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("AdminRoleId"), request.AdminRoleId);
    }
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    OutRestJsonObj->SetNumberField(TEXT("ExpectedProfileVersion"), request.ExpectedProfileVersion);
    if (request.Group != nullptr) OutRestJsonObj->SetObjectField(TEXT("Group"), request.Group);
    if (request.GroupName.IsEmpty() || request.GroupName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("GroupName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("GroupName"), request.GroupName);
    }
    if (request.MemberRoleId.IsEmpty() || request.MemberRoleId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("MemberRoleId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("MemberRoleId"), request.MemberRoleId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperUpdateGroup(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdateGroup.IsBound())
    {
        FGroupsUpdateGroupResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeUpdateGroupResponseResponse(response.responseData);
        OnSuccessUpdateGroup.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Updates metadata about a role. */
UPlayFabGroupsAPI* UPlayFabGroupsAPI::UpdateRole(FGroupsUpdateGroupRoleRequest request,
    FDelegateOnSuccessUpdateRole onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabGroupsAPI* manager = NewObject<UPlayFabGroupsAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateRole = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabGroupsAPI::HelperUpdateRole);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Group/UpdateRole";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.CustomTags != nullptr) OutRestJsonObj->SetObjectField(TEXT("CustomTags"), request.CustomTags);
    OutRestJsonObj->SetNumberField(TEXT("ExpectedProfileVersion"), request.ExpectedProfileVersion);
    if (request.Group != nullptr) OutRestJsonObj->SetObjectField(TEXT("Group"), request.Group);
    if (request.RoleId.IsEmpty() || request.RoleId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("RoleId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("RoleId"), request.RoleId);
    }
    if (request.RoleName.IsEmpty() || request.RoleName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("RoleName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("RoleName"), request.RoleName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabGroupsRequestCompleted
void UPlayFabGroupsAPI::HelperUpdateRole(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdateRole.IsBound())
    {
        FGroupsUpdateGroupRoleResponse ResultStruct = UPlayFabGroupsModelDecoder::decodeUpdateGroupRoleResponseResponse(response.responseData);
        OnSuccessUpdateRole.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}



void UPlayFabGroupsAPI::OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
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

void UPlayFabGroupsAPI::Activate()
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
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UPlayFabGroupsAPI::OnProcessRequestComplete);

    // Execute the request
    pfSettings->ModifyPendingCallCount(1);
    HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::ResetResponseData()
{
    if (ResponseJsonObj != nullptr)
        ResponseJsonObj->Reset();
    else
        ResponseJsonObj = NewObject<UPlayFabJsonObject>();
    bIsValidJsonResponse = false;
}
