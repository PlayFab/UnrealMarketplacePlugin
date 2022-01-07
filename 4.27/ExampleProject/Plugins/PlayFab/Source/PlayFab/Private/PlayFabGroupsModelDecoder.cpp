//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the play fab models
//
// API: Groups
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabGroupsModelDecoder.h"
#include "PlayFabPrivate.h"

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Groups API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Groups
//////////////////////////////////////////////////////

FGroupsEmptyResponse UPlayFabGroupsModelDecoder::decodeEmptyResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FGroupsEmptyResponse tempStruct;


    return tempStruct;
}

FGroupsApplyToGroupResponse UPlayFabGroupsModelDecoder::decodeApplyToGroupResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FGroupsApplyToGroupResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Entity = !(dataObj->HasField("Entity")) ? nullptr : dataObj->GetObjectField("Entity");
    tempStruct.Expires = !(dataObj->HasField("Expires")) ? TEXT("") : dataObj->GetStringField("Expires");
    tempStruct.Group = !(dataObj->HasField("Group")) ? nullptr : dataObj->GetObjectField("Group");

    return tempStruct;
}

FGroupsCreateGroupResponse UPlayFabGroupsModelDecoder::decodeCreateGroupResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FGroupsCreateGroupResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.AdminRoleId = !(dataObj->HasField("AdminRoleId")) ? TEXT("") : dataObj->GetStringField("AdminRoleId");
    tempStruct.Created = !(dataObj->HasField("Created")) ? TEXT("") : dataObj->GetStringField("Created");
    tempStruct.Group = !(dataObj->HasField("Group")) ? nullptr : dataObj->GetObjectField("Group");
    tempStruct.GroupName = !(dataObj->HasField("GroupName")) ? TEXT("") : dataObj->GetStringField("GroupName");
    tempStruct.MemberRoleId = !(dataObj->HasField("MemberRoleId")) ? TEXT("") : dataObj->GetStringField("MemberRoleId");
    tempStruct.ProfileVersion = !(dataObj->HasField("ProfileVersion")) ? 0 : int(dataObj->GetNumberField("ProfileVersion"));
    tempStruct.Roles = !(dataObj->HasField("Roles")) ? nullptr : dataObj->GetObjectField("Roles");

    return tempStruct;
}

FGroupsCreateGroupRoleResponse UPlayFabGroupsModelDecoder::decodeCreateGroupRoleResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FGroupsCreateGroupRoleResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.ProfileVersion = !(dataObj->HasField("ProfileVersion")) ? 0 : int(dataObj->GetNumberField("ProfileVersion"));
    tempStruct.RoleId = !(dataObj->HasField("RoleId")) ? TEXT("") : dataObj->GetStringField("RoleId");
    tempStruct.RoleName = !(dataObj->HasField("RoleName")) ? TEXT("") : dataObj->GetStringField("RoleName");

    return tempStruct;
}

FGroupsGetGroupResponse UPlayFabGroupsModelDecoder::decodeGetGroupResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FGroupsGetGroupResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.AdminRoleId = !(dataObj->HasField("AdminRoleId")) ? TEXT("") : dataObj->GetStringField("AdminRoleId");
    tempStruct.Created = !(dataObj->HasField("Created")) ? TEXT("") : dataObj->GetStringField("Created");
    tempStruct.Group = !(dataObj->HasField("Group")) ? nullptr : dataObj->GetObjectField("Group");
    tempStruct.GroupName = !(dataObj->HasField("GroupName")) ? TEXT("") : dataObj->GetStringField("GroupName");
    tempStruct.MemberRoleId = !(dataObj->HasField("MemberRoleId")) ? TEXT("") : dataObj->GetStringField("MemberRoleId");
    tempStruct.ProfileVersion = !(dataObj->HasField("ProfileVersion")) ? 0 : int(dataObj->GetNumberField("ProfileVersion"));
    tempStruct.Roles = !(dataObj->HasField("Roles")) ? nullptr : dataObj->GetObjectField("Roles");

    return tempStruct;
}

FGroupsInviteToGroupResponse UPlayFabGroupsModelDecoder::decodeInviteToGroupResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FGroupsInviteToGroupResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Expires = !(dataObj->HasField("Expires")) ? TEXT("") : dataObj->GetStringField("Expires");
    tempStruct.Group = !(dataObj->HasField("Group")) ? nullptr : dataObj->GetObjectField("Group");
    tempStruct.InvitedByEntity = !(dataObj->HasField("InvitedByEntity")) ? nullptr : dataObj->GetObjectField("InvitedByEntity");
    tempStruct.InvitedEntity = !(dataObj->HasField("InvitedEntity")) ? nullptr : dataObj->GetObjectField("InvitedEntity");
    tempStruct.RoleId = !(dataObj->HasField("RoleId")) ? TEXT("") : dataObj->GetStringField("RoleId");

    return tempStruct;
}

FGroupsIsMemberResponse UPlayFabGroupsModelDecoder::decodeIsMemberResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FGroupsIsMemberResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.IsMember = !(dataObj->HasField("IsMember")) ? false : dataObj->GetBoolField("IsMember");

    return tempStruct;
}

FGroupsListGroupApplicationsResponse UPlayFabGroupsModelDecoder::decodeListGroupApplicationsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FGroupsListGroupApplicationsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Applications = !(dataObj->HasField("Applications")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Applications");

    return tempStruct;
}

FGroupsListGroupBlocksResponse UPlayFabGroupsModelDecoder::decodeListGroupBlocksResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FGroupsListGroupBlocksResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.BlockedEntities = !(dataObj->HasField("BlockedEntities")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("BlockedEntities");

    return tempStruct;
}

FGroupsListGroupInvitationsResponse UPlayFabGroupsModelDecoder::decodeListGroupInvitationsResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FGroupsListGroupInvitationsResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Invitations = !(dataObj->HasField("Invitations")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Invitations");

    return tempStruct;
}

FGroupsListGroupMembersResponse UPlayFabGroupsModelDecoder::decodeListGroupMembersResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FGroupsListGroupMembersResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Members = !(dataObj->HasField("Members")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Members");

    return tempStruct;
}

FGroupsListMembershipResponse UPlayFabGroupsModelDecoder::decodeListMembershipResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FGroupsListMembershipResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Groups = !(dataObj->HasField("Groups")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Groups");

    return tempStruct;
}

FGroupsListMembershipOpportunitiesResponse UPlayFabGroupsModelDecoder::decodeListMembershipOpportunitiesResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FGroupsListMembershipOpportunitiesResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.Applications = !(dataObj->HasField("Applications")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Applications");
    tempStruct.Invitations = !(dataObj->HasField("Invitations")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField("Invitations");

    return tempStruct;
}

FGroupsUpdateGroupResponse UPlayFabGroupsModelDecoder::decodeUpdateGroupResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FGroupsUpdateGroupResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.OperationReason = !(dataObj->HasField("OperationReason")) ? TEXT("") : dataObj->GetStringField("OperationReason");
    tempStruct.ProfileVersion = !(dataObj->HasField("ProfileVersion")) ? 0 : int(dataObj->GetNumberField("ProfileVersion"));
    GetEnumValueFromString<EOperationTypes>(TEXT("EOperationTypes"), dataObj->GetStringField("SetResult"), tempStruct.SetResult);

    return tempStruct;
}

FGroupsUpdateGroupRoleResponse UPlayFabGroupsModelDecoder::decodeUpdateGroupRoleResponseResponse(UPlayFabJsonObject* response)
{
    // Temp ustruct
    FGroupsUpdateGroupRoleResponse tempStruct;
    UPlayFabJsonObject* dataObj = !(response->HasField("data")) ? nullptr : response->GetObjectField("data");

    tempStruct.OperationReason = !(dataObj->HasField("OperationReason")) ? TEXT("") : dataObj->GetStringField("OperationReason");
    tempStruct.ProfileVersion = !(dataObj->HasField("ProfileVersion")) ? 0 : int(dataObj->GetNumberField("ProfileVersion"));
    GetEnumValueFromString<EOperationTypes>(TEXT("EOperationTypes"), dataObj->GetStringField("SetResult"), tempStruct.SetResult);

    return tempStruct;
}


