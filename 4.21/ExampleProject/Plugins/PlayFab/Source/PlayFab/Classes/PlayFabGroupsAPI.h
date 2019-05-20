//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated header file for the UE4 PlayFab plugin.
// This header file contains the function definitions.
//
// API: Groups
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Http.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "PlayFabBaseModel.h"
#include "PlayFabGroupsModels.h"
#include "PlayFabGroupsAPI.generated.h"

class UPlayFabAuthenticationContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPlayFabGroupsRequestCompleted, FPlayFabBaseModel, response, UObject*, customData, bool, successful);

UCLASS(Blueprintable, BlueprintType)
class PLAYFAB_API UPlayFabGroupsAPI : public UOnlineBlueprintCallProxyBase
{
    GENERATED_UCLASS_BODY()

public:
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnFailurePlayFabError, FPlayFabError, error, UObject*, customData);

    UPROPERTY(BlueprintAssignable)
        FOnPlayFabGroupsRequestCompleted OnPlayFabResponse;

    void SetCallAuthenticationContext(UPlayFabAuthenticationContext* InAuthenticationContext);

    /** Set the Request Json object */
    void SetRequestObject(UPlayFabJsonObject* JsonObject);

    /** Get the Response Json object */
    UPlayFabJsonObject* GetResponseObject();

    /** Applies percent-encoding to text */
    static FString PercentEncode(const FString& Text);

    /** Reset saved response data */
    void ResetResponseData();

    /** UOnlineBlueprintCallProxyBase interface */
    virtual void Activate() override;

    //////////////////////////////////////////////////////////////////////////
    // Generated PlayFab Groups API Functions
    //////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////
    // Groups
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAcceptGroupApplication, FGroupsEmptyResponse, result, UObject*, customData);

    /** Accepts an outstanding invitation to to join a group */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* AcceptGroupApplication(FGroupsAcceptGroupApplicationRequest request,
            FDelegateOnSuccessAcceptGroupApplication onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAcceptGroupApplication(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAcceptGroupInvitation, FGroupsEmptyResponse, result, UObject*, customData);

    /** Accepts an invitation to join a group */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* AcceptGroupInvitation(FGroupsAcceptGroupInvitationRequest request,
            FDelegateOnSuccessAcceptGroupInvitation onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAcceptGroupInvitation(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAddMembers, FGroupsEmptyResponse, result, UObject*, customData);

    /** Adds members to a group or role. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* AddMembers(FGroupsAddMembersRequest request,
            FDelegateOnSuccessAddMembers onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAddMembers(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessApplyToGroup, FGroupsApplyToGroupResponse, result, UObject*, customData);

    /** Applies to join a group */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* ApplyToGroup(FGroupsApplyToGroupRequest request,
            FDelegateOnSuccessApplyToGroup onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperApplyToGroup(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessBlockEntity, FGroupsEmptyResponse, result, UObject*, customData);

    /** Blocks a list of entities from joining a group. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* BlockEntity(FGroupsBlockEntityRequest request,
            FDelegateOnSuccessBlockEntity onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperBlockEntity(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessChangeMemberRole, FGroupsEmptyResponse, result, UObject*, customData);

    /** Changes the role membership of a list of entities from one role to another. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* ChangeMemberRole(FGroupsChangeMemberRoleRequest request,
            FDelegateOnSuccessChangeMemberRole onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperChangeMemberRole(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateGroup, FGroupsCreateGroupResponse, result, UObject*, customData);

    /** Creates a new group. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* CreateGroup(FGroupsCreateGroupRequest request,
            FDelegateOnSuccessCreateGroup onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateGroup(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateRole, FGroupsCreateGroupRoleResponse, result, UObject*, customData);

    /** Creates a new group role. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* CreateRole(FGroupsCreateGroupRoleRequest request,
            FDelegateOnSuccessCreateRole onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateRole(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteGroup, FGroupsEmptyResponse, result, UObject*, customData);

    /** Deletes a group and all roles, invitations, join requests, and blocks associated with it. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* DeleteGroup(FGroupsDeleteGroupRequest request,
            FDelegateOnSuccessDeleteGroup onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteGroup(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteRole, FGroupsEmptyResponse, result, UObject*, customData);

    /** Deletes an existing role in a group. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* DeleteRole(FGroupsDeleteRoleRequest request,
            FDelegateOnSuccessDeleteRole onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteRole(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetGroup, FGroupsGetGroupResponse, result, UObject*, customData);

    /** Gets information about a group and its roles */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* GetGroup(FGroupsGetGroupRequest request,
            FDelegateOnSuccessGetGroup onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetGroup(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessInviteToGroup, FGroupsInviteToGroupResponse, result, UObject*, customData);

    /** Invites a player to join a group */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* InviteToGroup(FGroupsInviteToGroupRequest request,
            FDelegateOnSuccessInviteToGroup onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperInviteToGroup(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessIsMember, FGroupsIsMemberResponse, result, UObject*, customData);

    /** Checks to see if an entity is a member of a group or role within the group */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* IsMember(FGroupsIsMemberRequest request,
            FDelegateOnSuccessIsMember onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperIsMember(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListGroupApplications, FGroupsListGroupApplicationsResponse, result, UObject*, customData);

    /** Lists all outstanding requests to join a group */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* ListGroupApplications(FGroupsListGroupApplicationsRequest request,
            FDelegateOnSuccessListGroupApplications onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListGroupApplications(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListGroupBlocks, FGroupsListGroupBlocksResponse, result, UObject*, customData);

    /** Lists all entities blocked from joining a group */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* ListGroupBlocks(FGroupsListGroupBlocksRequest request,
            FDelegateOnSuccessListGroupBlocks onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListGroupBlocks(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListGroupInvitations, FGroupsListGroupInvitationsResponse, result, UObject*, customData);

    /** Lists all outstanding invitations for a group */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* ListGroupInvitations(FGroupsListGroupInvitationsRequest request,
            FDelegateOnSuccessListGroupInvitations onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListGroupInvitations(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListGroupMembers, FGroupsListGroupMembersResponse, result, UObject*, customData);

    /** Lists all members for a group */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* ListGroupMembers(FGroupsListGroupMembersRequest request,
            FDelegateOnSuccessListGroupMembers onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListGroupMembers(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListMembership, FGroupsListMembershipResponse, result, UObject*, customData);

    /** Lists all groups and roles for an entity */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* ListMembership(FGroupsListMembershipRequest request,
            FDelegateOnSuccessListMembership onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListMembership(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListMembershipOpportunities, FGroupsListMembershipOpportunitiesResponse, result, UObject*, customData);

    /** Lists all outstanding invitations and group applications for an entity */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* ListMembershipOpportunities(FGroupsListMembershipOpportunitiesRequest request,
            FDelegateOnSuccessListMembershipOpportunities onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListMembershipOpportunities(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRemoveGroupApplication, FGroupsEmptyResponse, result, UObject*, customData);

    /** Removes an application to join a group */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* RemoveGroupApplication(FGroupsRemoveGroupApplicationRequest request,
            FDelegateOnSuccessRemoveGroupApplication onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRemoveGroupApplication(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRemoveGroupInvitation, FGroupsEmptyResponse, result, UObject*, customData);

    /** Removes an invitation join a group */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* RemoveGroupInvitation(FGroupsRemoveGroupInvitationRequest request,
            FDelegateOnSuccessRemoveGroupInvitation onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRemoveGroupInvitation(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRemoveMembers, FGroupsEmptyResponse, result, UObject*, customData);

    /** Removes members from a group. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* RemoveMembers(FGroupsRemoveMembersRequest request,
            FDelegateOnSuccessRemoveMembers onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRemoveMembers(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnblockEntity, FGroupsEmptyResponse, result, UObject*, customData);

    /** Unblocks a list of entities from joining a group */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* UnblockEntity(FGroupsUnblockEntityRequest request,
            FDelegateOnSuccessUnblockEntity onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnblockEntity(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateGroup, FGroupsUpdateGroupResponse, result, UObject*, customData);

    /** Updates non-membership data about a group. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* UpdateGroup(FGroupsUpdateGroupRequest request,
            FDelegateOnSuccessUpdateGroup onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateGroup(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateRole, FGroupsUpdateGroupRoleResponse, result, UObject*, customData);

    /** Updates metadata about a role. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabGroupsAPI* UpdateRole(FGroupsUpdateGroupRoleRequest request,
            FDelegateOnSuccessUpdateRole onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabGroupsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateRole(FPlayFabBaseModel response, UObject* customData, bool successful);



    /** PlayFab Request Info */
    FString PlayFabRequestURL;

    bool useEntityToken = false;
    bool useSecretKey = false;
    bool useSessionTicket = false;
    bool returnsSessionTicket = false;
    bool returnsEntityToken = false;

    /** Is the response valid JSON? */
    bool bIsValidJsonResponse;
    FString ResponseContent;
    int32 ResponseCode;
    UObject* mCustomData;

    FDelegateOnFailurePlayFabError OnFailure;
    FDelegateOnSuccessAcceptGroupApplication OnSuccessAcceptGroupApplication;
    FDelegateOnSuccessAcceptGroupInvitation OnSuccessAcceptGroupInvitation;
    FDelegateOnSuccessAddMembers OnSuccessAddMembers;
    FDelegateOnSuccessApplyToGroup OnSuccessApplyToGroup;
    FDelegateOnSuccessBlockEntity OnSuccessBlockEntity;
    FDelegateOnSuccessChangeMemberRole OnSuccessChangeMemberRole;
    FDelegateOnSuccessCreateGroup OnSuccessCreateGroup;
    FDelegateOnSuccessCreateRole OnSuccessCreateRole;
    FDelegateOnSuccessDeleteGroup OnSuccessDeleteGroup;
    FDelegateOnSuccessDeleteRole OnSuccessDeleteRole;
    FDelegateOnSuccessGetGroup OnSuccessGetGroup;
    FDelegateOnSuccessInviteToGroup OnSuccessInviteToGroup;
    FDelegateOnSuccessIsMember OnSuccessIsMember;
    FDelegateOnSuccessListGroupApplications OnSuccessListGroupApplications;
    FDelegateOnSuccessListGroupBlocks OnSuccessListGroupBlocks;
    FDelegateOnSuccessListGroupInvitations OnSuccessListGroupInvitations;
    FDelegateOnSuccessListGroupMembers OnSuccessListGroupMembers;
    FDelegateOnSuccessListMembership OnSuccessListMembership;
    FDelegateOnSuccessListMembershipOpportunities OnSuccessListMembershipOpportunities;
    FDelegateOnSuccessRemoveGroupApplication OnSuccessRemoveGroupApplication;
    FDelegateOnSuccessRemoveGroupInvitation OnSuccessRemoveGroupInvitation;
    FDelegateOnSuccessRemoveMembers OnSuccessRemoveMembers;
    FDelegateOnSuccessUnblockEntity OnSuccessUnblockEntity;
    FDelegateOnSuccessUpdateGroup OnSuccessUpdateGroup;
    FDelegateOnSuccessUpdateRole OnSuccessUpdateRole;

private:
    UPROPERTY()
        UPlayFabAuthenticationContext* CallAuthenticationContext;

    /** Internal bind function for the IHTTPRequest::OnProcessRequestCompleted() event */
    void OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

protected:
    /** Internal request data stored as JSON */
    UPROPERTY()
        UPlayFabJsonObject* RequestJsonObj;

    /** Response data stored as JSON */
    UPROPERTY()
        UPlayFabJsonObject* ResponseJsonObj;

    /** Mapping of header section to values. Used to generate final header string for request */
    TMap<FString, FString> RequestHeaders;
};
