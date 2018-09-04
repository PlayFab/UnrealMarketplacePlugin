//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Groups
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabGroupsModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Groups API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Groups
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FGroupsAcceptGroupApplicationRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Optional. Type of the entity to accept as. If specified, must be the same entity as the claimant or an entity that is a
     * child of the claimant entity. Defaults to the claimant entity.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

USTRUCT(BlueprintType)
struct FGroupsEmptyResponse
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FGroupsAcceptGroupInvitationRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

USTRUCT(BlueprintType)
struct FGroupsAddMembersRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
    /** List of entities to add to the group. Only entities of type title_player_account and character may be added to groups. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        TArray<UPlayFabJsonObject*> Members;
    /**
     * Optional: The ID of the existing role to add the entities to. If this is not specified, the default member role for the
     * group will be used. Role IDs must be between 1 and 64 characters long.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString RoleId;
};

USTRUCT(BlueprintType)
struct FGroupsApplyToGroupRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Optional, default true. Automatically accept an outstanding invitation if one exists instead of creating an application */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        bool AutoAcceptOutstandingInvite = false;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

/** Describes an application to join a group */
USTRUCT(BlueprintType)
struct FGroupsApplyToGroupResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** Type of entity that requested membership */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** When the application to join will expire and be deleted */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString Expires;
    /** ID of the group that the entity requesting membership to */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

USTRUCT(BlueprintType)
struct FGroupsBlockEntityRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

USTRUCT(BlueprintType)
struct FGroupsChangeMemberRoleRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * The ID of the role that the entities will become a member of. This must be an existing role. Role IDs must be between 1
     * and 64 characters long.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString DestinationRoleId;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
    /**
     * List of entities to move between roles in the group. All entities in this list must be members of the group and origin
     * role.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        TArray<UPlayFabJsonObject*> Members;
    /** The ID of the role that the entities currently are a member of. Role IDs must be between 1 and 64 characters long. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString OriginRoleId;
};

USTRUCT(BlueprintType)
struct FGroupsCreateGroupRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The name of the group. This is unique at the title level by default. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString GroupName;
};

USTRUCT(BlueprintType)
struct FGroupsCreateGroupResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** The ID of the administrator role for the group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString AdminRoleId;
    /** The server date and time the group was created. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString Created;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
    /** The name of the group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString GroupName;
    /** The ID of the default member role for the group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString MemberRoleId;
    /** The current version of the profile, can be used for concurrency control during updates. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        int32 ProfileVersion = 0;
    /** The list of roles and names that belong to the group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Roles;
};

USTRUCT(BlueprintType)
struct FGroupsCreateGroupRoleRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
    /**
     * The ID of the role. This must be unique within the group and cannot be changed. Role IDs must be between 1 and 64
     * characters long.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString RoleId;
    /**
     * The name of the role. This must be unique within the group and can be changed later. Role names must be between 1 and
     * 100 characters long
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString RoleName;
};

USTRUCT(BlueprintType)
struct FGroupsCreateGroupRoleResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** The current version of the group profile, can be used for concurrency control during updates. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        int32 ProfileVersion = 0;
    /** ID for the role */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString RoleId;
    /** The name of the role */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString RoleName;
};

USTRUCT(BlueprintType)
struct FGroupsDeleteGroupRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** ID of the group or role to remove */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

USTRUCT(BlueprintType)
struct FGroupsDeleteRoleRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
    /** The ID of the role to delete. Role IDs must be between 1 and 64 characters long. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString RoleId;
};

USTRUCT(BlueprintType)
struct FGroupsGetGroupRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
    /** The full name of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString GroupName;
};

USTRUCT(BlueprintType)
struct FGroupsGetGroupResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** The ID of the administrator role for the group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString AdminRoleId;
    /** The server date and time the group was created. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString Created;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
    /** The name of the group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString GroupName;
    /** The ID of the default member role for the group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString MemberRoleId;
    /** The current version of the profile, can be used for concurrency control during updates. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        int32 ProfileVersion = 0;
    /** The list of roles and names that belong to the group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Roles;
};

USTRUCT(BlueprintType)
struct FGroupsInviteToGroupRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Optional, default true. Automatically accept an application if one exists instead of creating an invitation */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        bool AutoAcceptOutstandingApplication = false;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
    /**
     * Optional. ID of an existing a role in the group to assign the user to. The group's default member role is used if this
     * is not specified. Role IDs must be between 1 and 64 characters long.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString RoleId;
};

/** Describes an invitation to a group. */
USTRUCT(BlueprintType)
struct FGroupsInviteToGroupResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** When the invitation will expire and be deleted */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString Expires;
    /** The group that the entity invited to */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
    /** The entity that created the invitation */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* InvitedByEntity = nullptr;
    /** The entity that is invited */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* InvitedEntity = nullptr;
    /** ID of the role in the group to assign the user to. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString RoleId;
};

USTRUCT(BlueprintType)
struct FGroupsIsMemberRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
    /**
     * Optional: ID of the role to check membership of. Defaults to any role (that is, check to see if the entity is a member
     * of the group in any capacity) if not specified.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString RoleId;
};

USTRUCT(BlueprintType)
struct FGroupsIsMemberResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** A value indicating whether or not the entity is a member. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        bool IsMember = false;
};

USTRUCT(BlueprintType)
struct FGroupsListGroupApplicationsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

USTRUCT(BlueprintType)
struct FGroupsListGroupApplicationsResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** The requested list of applications to the group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        TArray<UPlayFabJsonObject*> Applications;
};

USTRUCT(BlueprintType)
struct FGroupsListGroupBlocksRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

USTRUCT(BlueprintType)
struct FGroupsListGroupBlocksResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** The requested list blocked entities. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        TArray<UPlayFabJsonObject*> BlockedEntities;
};

USTRUCT(BlueprintType)
struct FGroupsListGroupInvitationsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

USTRUCT(BlueprintType)
struct FGroupsListGroupInvitationsResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** The requested list of group invitations. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        TArray<UPlayFabJsonObject*> Invitations;
};

USTRUCT(BlueprintType)
struct FGroupsListGroupMembersRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** ID of the group to list the members and roles for */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

USTRUCT(BlueprintType)
struct FGroupsListGroupMembersResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** The requested list of roles and member entity IDs. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        TArray<UPlayFabJsonObject*> Members;
};

USTRUCT(BlueprintType)
struct FGroupsListMembershipRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct FGroupsListMembershipResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of groups */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        TArray<UPlayFabJsonObject*> Groups;
};

USTRUCT(BlueprintType)
struct FGroupsListMembershipOpportunitiesRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct FGroupsListMembershipOpportunitiesResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** The requested list of group applications. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        TArray<UPlayFabJsonObject*> Applications;
    /** The requested list of group invitations. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        TArray<UPlayFabJsonObject*> Invitations;
};

USTRUCT(BlueprintType)
struct FGroupsRemoveGroupApplicationRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

USTRUCT(BlueprintType)
struct FGroupsRemoveGroupInvitationRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

USTRUCT(BlueprintType)
struct FGroupsRemoveMembersRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
    /** List of entities to remove */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        TArray<UPlayFabJsonObject*> Members;
    /** The ID of the role to remove the entities from. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString RoleId;
};

USTRUCT(BlueprintType)
struct FGroupsUnblockEntityRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

USTRUCT(BlueprintType)
struct FGroupsUpdateGroupRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Optional: the ID of an existing role to set as the new administrator role for the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString AdminRoleId;
    /**
     * Optional field used for concurrency control. By specifying the previously returned value of ProfileVersion from the
     * GetGroup API, you can ensure that the group data update will only be performed if the group has not been updated by any
     * other clients since the version you last loaded.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        int32 ExpectedProfileVersion = 0;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
    /** Optional: the new name of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString GroupName;
    /** Optional: the ID of an existing role to set as the new member role for the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString MemberRoleId;
};

USTRUCT(BlueprintType)
struct FGroupsUpdateGroupResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** Optional reason to explain why the operation was the result that it was. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString OperationReason;
    /** New version of the group data. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        int32 ProfileVersion = 0;
    /** Indicates which operation was completed, either Created, Updated, Deleted or None. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        EOperationTypes SetResult;
};

USTRUCT(BlueprintType)
struct FGroupsUpdateGroupRoleRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Optional field used for concurrency control. By specifying the previously returned value of ProfileVersion from the
     * GetGroup API, you can ensure that the group data update will only be performed if the group has not been updated by any
     * other clients since the version you last loaded.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        int32 ExpectedProfileVersion = 0;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
    /** ID of the role to update. Role IDs must be between 1 and 64 characters long. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString RoleId;
    /** The new name of the role */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString RoleName;
};

USTRUCT(BlueprintType)
struct FGroupsUpdateGroupRoleResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** Optional reason to explain why the operation was the result that it was. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString OperationReason;
    /** New version of the role data. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        int32 ProfileVersion = 0;
    /** Indicates which operation was completed, either Created, Updated, Deleted or None. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        EOperationTypes SetResult;
};

