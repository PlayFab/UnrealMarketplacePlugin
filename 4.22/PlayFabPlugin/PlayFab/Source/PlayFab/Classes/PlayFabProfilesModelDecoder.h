//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Profiles
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabProfilesModels.h"
#include "PlayFabProfilesModelDecoder.generated.h"

class UPlayFabJsonObject;

UCLASS()
class PLAYFAB_API UPlayFabProfilesModelDecoder : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    //////////////////////////////////////////////////////////////////////////
    // Generated PlayFab Profiles API Functions
    //////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////
    // Account Management
    //////////////////////////////////////////////////////

    /** Decode the GetGlobalPolicyResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Profiles | Account Management Models")
        static FProfilesGetGlobalPolicyResponse decodeGetGlobalPolicyResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetEntityProfileResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Profiles | Account Management Models")
        static FProfilesGetEntityProfileResponse decodeGetEntityProfileResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetEntityProfilesResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Profiles | Account Management Models")
        static FProfilesGetEntityProfilesResponse decodeGetEntityProfilesResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetTitlePlayersFromMasterPlayerAccountIdsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Profiles | Account Management Models")
        static FProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse decodeGetTitlePlayersFromMasterPlayerAccountIdsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the SetGlobalPolicyResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Profiles | Account Management Models")
        static FProfilesSetGlobalPolicyResponse decodeSetGlobalPolicyResponseResponse(UPlayFabJsonObject* response);

    /** Decode the SetProfileLanguageResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Profiles | Account Management Models")
        static FProfilesSetProfileLanguageResponse decodeSetProfileLanguageResponseResponse(UPlayFabJsonObject* response);

    /** Decode the SetEntityProfilePolicyResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Profiles | Account Management Models")
        static FProfilesSetEntityProfilePolicyResponse decodeSetEntityProfilePolicyResponseResponse(UPlayFabJsonObject* response);



};
