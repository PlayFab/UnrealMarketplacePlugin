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
#include "PlayFabRequestCommon.h"
#include "PlayFabLoginResultCommon.h"
#include "PlayFabGroupsModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Groups API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Groups
//////////////////////////////////////////////////////

/**
 * Accepts an outstanding invitation to to join a group if the invited entity is not blocked by the group. Nothing is
 * returned in the case of success.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsAcceptGroupApplicationRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /**
     * Type of the entity to accept as. Must be the same entity as the claimant or an entity that is a child of the claimant
     * entity.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsEmptyResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * Accepts an outstanding invitation to join the group if the invited entity is not blocked by the group. Only the invited
 * entity or a parent in its chain (e.g. title) may accept the invitation on the invited entity's behalf. Nothing is
 * returned in the case of success.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsAcceptGroupInvitationRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

/**
 * Adds members to a group or role. Existing members of the group will added to roles within the group, but if the user is
 * not already a member of the group, only title claimants may add them to the group, and others must use the group
 * application or invite system to add new members to a group. Returns nothing if successful.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsAddMembersRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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

/**
 * Creates an application to join a group. Calling this while a group application already exists will return the same
 * application instead of an error and will not refresh the time before the application expires. By default, if the entity
 * has an invitation to join the group outstanding, this will accept the invitation to join the group instead and return an
 * error indicating such, rather than creating a duplicate application to join that will need to be cleaned up later.
 * Returns information about the application or an error indicating an invitation was accepted instead.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsApplyToGroupRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Optional, default true. Automatically accept an outstanding invitation if one exists instead of creating an application */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        bool AutoAcceptOutstandingInvite = false;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

/** Describes an application to join a group */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsApplyToGroupResponse : public FPlayFabResultCommon
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

/**
 * Blocks a list of entities from joining a group. Blocked entities may not create new applications to join, be invited to
 * join, accept an invitation, or have an application accepted. Failure due to being blocked does not clean up existing
 * applications or invitations to the group. No data is returned in the case of success.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsBlockEntityRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

/**
 * Changes the role membership of a list of entities from one role to another in in a single operation. The destination
 * role must already exist. This is equivalent to adding the entities to the destination role and removing from the origin
 * role. Returns nothing if successful.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsChangeMemberRoleRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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

/**
 * Creates a new group, as well as administration and member roles, based off of a title's group template. Returns
 * information about the group that was created.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsCreateGroupRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The name of the group. This is unique at the title level by default. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString GroupName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsCreateGroupResponse : public FPlayFabResultCommon
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
        UPlayFabJsonObject* Roles = nullptr;
};

/**
 * Creates a new role within an existing group, with no members. Both the role ID and role name must be unique within the
 * group, but the name can be the same as the ID. The role ID is set at creation and cannot be changed. Returns information
 * about the role that was created.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsCreateGroupRoleRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
struct PLAYFAB_API FGroupsCreateGroupRoleResponse : public FPlayFabResultCommon
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

/**
 * Deletes a group and all roles, invitations, join requests, and blocks associated with it. Permission to delete is only
 * required the group itself to execute this action. The group and data cannot be cannot be recovered once removed, but any
 * abuse reports about the group will remain. No data is returned in the case of success.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsDeleteGroupRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** ID of the group or role to remove */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

/** Returns information about the role */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsDeleteRoleRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
    /** The ID of the role to delete. Role IDs must be between 1 and 64 characters long. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString RoleId;
};

/** Returns the ID, name, role list and other non-membership related information about a group. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsGetGroupRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
    /** The full name of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString GroupName;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsGetGroupResponse : public FPlayFabResultCommon
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
        UPlayFabJsonObject* Roles = nullptr;
};

/**
 * Invites a player to join a group, if they are not blocked by the group. An optional role can be provided to
 * automatically assign the player to the role if they accept the invitation. By default, if the entity has an application
 * to the group outstanding, this will accept the application instead and return an error indicating such, rather than
 * creating a duplicate invitation to join that will need to be cleaned up later. Returns information about the new
 * invitation or an error indicating an existing application to join was accepted.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsInviteToGroupRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Optional, default true. Automatically accept an application if one exists instead of creating an invitation */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        bool AutoAcceptOutstandingApplication = false;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
struct PLAYFAB_API FGroupsInviteToGroupResponse : public FPlayFabResultCommon
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

/**
 * Checks to see if an entity is a member of a group or role within the group. A result indicating if the entity is a
 * member of the group is returned, or a permission error if the caller does not have permission to read the group's member
 * list.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsIsMemberRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
struct PLAYFAB_API FGroupsIsMemberResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** A value indicating whether or not the entity is a member. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        bool IsMember = false;
};

/**
 * Lists all outstanding requests to join a group. Returns a list of all requests to join, as well as when the request will
 * expire. To get the group applications for a specific entity, use ListMembershipOpportunities.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsListGroupApplicationsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsListGroupApplicationsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The requested list of applications to the group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        TArray<UPlayFabJsonObject*> Applications;
};

/** Lists all entities blocked from joining a group. A list of blocked entities is returned */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsListGroupBlocksRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsListGroupBlocksResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The requested list blocked entities. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        TArray<UPlayFabJsonObject*> BlockedEntities;
};

/**
 * Lists all outstanding invitations for a group. Returns a list of entities that have been invited, as well as when the
 * invitation will expire. To get the group invitations for a specific entity, use ListMembershipOpportunities.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsListGroupInvitationsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsListGroupInvitationsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The requested list of group invitations. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        TArray<UPlayFabJsonObject*> Invitations;
};

/**
 * Gets a list of members and the roles they belong to within the group. If the caller does not have permission to view the
 * role, and the member is in no other role, the member is not displayed. Returns a list of entities that are members of
 * the group.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsListGroupMembersRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** ID of the group to list the members and roles for */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsListGroupMembersResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The requested list of roles and member entity IDs. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        TArray<UPlayFabJsonObject*> Members;
};

/**
 * Lists the groups and roles that an entity is a part of, checking to see if group and role metadata and memberships
 * should be visible to the caller. If the entity is not in any roles that are visible to the caller, the group is not
 * returned in the results, even if the caller otherwise has permission to see that the entity is a member of that group.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsListMembershipRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsListMembershipResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of groups */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        TArray<UPlayFabJsonObject*> Groups;
};

/**
 * Lists all outstanding group applications and invitations for an entity. Anyone may call this for any entity, but data
 * will only be returned for the entity or a parent of that entity. To list invitations or applications for a group to
 * check if a player is trying to join, use ListGroupInvitations and ListGroupApplications.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsListMembershipOpportunitiesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsListMembershipOpportunitiesResponse : public FPlayFabResultCommon
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

/**
 * Removes an existing application to join the group. This is used for both rejection of an application as well as
 * withdrawing an application. The applying entity or a parent in its chain (e.g. title) may withdraw the application, and
 * any caller with appropriate access in the group may reject an application. No data is returned in the case of success.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsRemoveGroupApplicationRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

/**
 * Removes an existing invitation to join the group. This is used for both rejection of an invitation as well as rescinding
 * an invitation. The invited entity or a parent in its chain (e.g. title) may reject the invitation by calling this
 * method, and any caller with appropriate access in the group may rescind an invitation. No data is returned in the case
 * of success.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsRemoveGroupInvitationRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

/**
 * Removes members from a group. A member can always remove themselves from a group, regardless of permissions. Returns
 * nothing if successful.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsRemoveMembersRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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

/** Unblocks a list of entities from joining a group. No data is returned in the case of success. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsUnblockEntityRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** The identifier of the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* Group = nullptr;
};

/**
 * Updates data about a group, such as the name or default member role. Returns information about whether the update was
 * successful. Only title claimants may modify the administration role for a group.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsUpdateGroupRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Optional: the ID of an existing role to set as the new administrator role for the group */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        FString AdminRoleId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
struct PLAYFAB_API FGroupsUpdateGroupResponse : public FPlayFabResultCommon
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

/** Updates the role name. Returns information about whether the update was successful. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FGroupsUpdateGroupRoleRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Groups | Groups Models")
        UPlayFabJsonObject* CustomTags = nullptr;
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
struct PLAYFAB_API FGroupsUpdateGroupRoleResponse : public FPlayFabResultCommon
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

