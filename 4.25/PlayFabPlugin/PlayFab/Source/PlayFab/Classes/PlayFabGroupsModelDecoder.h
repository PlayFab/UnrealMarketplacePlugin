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
#include "PlayFabGroupsModels.h"
#include "PlayFabGroupsModelDecoder.generated.h"

class UPlayFabJsonObject;

UCLASS()
class PLAYFAB_API UPlayFabGroupsModelDecoder : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    //////////////////////////////////////////////////////////////////////////
    // Generated PlayFab Groups API Functions
    //////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////
    // Groups
    //////////////////////////////////////////////////////

    /** Decode the EmptyResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups Models")
        static FGroupsEmptyResponse decodeEmptyResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ApplyToGroupResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups Models")
        static FGroupsApplyToGroupResponse decodeApplyToGroupResponseResponse(UPlayFabJsonObject* response);

    /** Decode the CreateGroupResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups Models")
        static FGroupsCreateGroupResponse decodeCreateGroupResponseResponse(UPlayFabJsonObject* response);

    /** Decode the CreateGroupRoleResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups Models")
        static FGroupsCreateGroupRoleResponse decodeCreateGroupRoleResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetGroupResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups Models")
        static FGroupsGetGroupResponse decodeGetGroupResponseResponse(UPlayFabJsonObject* response);

    /** Decode the InviteToGroupResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups Models")
        static FGroupsInviteToGroupResponse decodeInviteToGroupResponseResponse(UPlayFabJsonObject* response);

    /** Decode the IsMemberResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups Models")
        static FGroupsIsMemberResponse decodeIsMemberResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListGroupApplicationsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups Models")
        static FGroupsListGroupApplicationsResponse decodeListGroupApplicationsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListGroupBlocksResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups Models")
        static FGroupsListGroupBlocksResponse decodeListGroupBlocksResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListGroupInvitationsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups Models")
        static FGroupsListGroupInvitationsResponse decodeListGroupInvitationsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListGroupMembersResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups Models")
        static FGroupsListGroupMembersResponse decodeListGroupMembersResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListMembershipResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups Models")
        static FGroupsListMembershipResponse decodeListMembershipResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListMembershipOpportunitiesResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups Models")
        static FGroupsListMembershipOpportunitiesResponse decodeListMembershipOpportunitiesResponseResponse(UPlayFabJsonObject* response);

    /** Decode the UpdateGroupResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups Models")
        static FGroupsUpdateGroupResponse decodeUpdateGroupResponseResponse(UPlayFabJsonObject* response);

    /** Decode the UpdateGroupRoleResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Groups | Groups Models")
        static FGroupsUpdateGroupRoleResponse decodeUpdateGroupRoleResponseResponse(UPlayFabJsonObject* response);



};
