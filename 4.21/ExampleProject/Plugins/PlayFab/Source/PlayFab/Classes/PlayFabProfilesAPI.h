//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated header file for the UE4 PlayFab plugin.
// This header file contains the function definitions.
//
// API: Profiles
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Http.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "PlayFabBaseModel.h"
#include "PlayFabProfilesModels.h"
#include "PlayFabProfilesAPI.generated.h"

class UPlayFabAuthenticationContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPlayFabProfilesRequestCompleted, FPlayFabBaseModel, response, UObject*, customData, bool, successful);

UCLASS(Blueprintable, BlueprintType)
class PLAYFAB_API UPlayFabProfilesAPI : public UOnlineBlueprintCallProxyBase
{
    GENERATED_UCLASS_BODY()

public:
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnFailurePlayFabError, FPlayFabError, error, UObject*, customData);

    UPROPERTY(BlueprintAssignable)
        FOnPlayFabProfilesRequestCompleted OnPlayFabResponse;

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
    // Generated PlayFab Profiles API Functions
    //////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////
    // Account Management
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetGlobalPolicy, FProfilesGetGlobalPolicyResponse, result, UObject*, customData);

    /** Gets the global title access policy */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Profiles | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProfilesAPI* GetGlobalPolicy(FProfilesGetGlobalPolicyRequest request,
            FDelegateOnSuccessGetGlobalPolicy onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProfilesRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Profiles | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetGlobalPolicy(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetProfile, FProfilesGetEntityProfileResponse, result, UObject*, customData);

    /** Retrieves the entity's profile. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Profiles | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProfilesAPI* GetProfile(FProfilesGetEntityProfileRequest request,
            FDelegateOnSuccessGetProfile onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProfilesRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Profiles | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetProfile(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetProfiles, FProfilesGetEntityProfilesResponse, result, UObject*, customData);

    /** Retrieves the entity's profile. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Profiles | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProfilesAPI* GetProfiles(FProfilesGetEntityProfilesRequest request,
            FDelegateOnSuccessGetProfiles onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProfilesRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Profiles | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetProfiles(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetTitlePlayersFromMasterPlayerAccountIds, FProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse, result, UObject*, customData);

    /** Retrieves the title player accounts associated with the given master player account. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Profiles | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProfilesAPI* GetTitlePlayersFromMasterPlayerAccountIds(FProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequest request,
            FDelegateOnSuccessGetTitlePlayersFromMasterPlayerAccountIds onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProfilesRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Profiles | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetTitlePlayersFromMasterPlayerAccountIds(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetGlobalPolicy, FProfilesSetGlobalPolicyResponse, result, UObject*, customData);

    /** Sets the global title access policy */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Profiles | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProfilesAPI* SetGlobalPolicy(FProfilesSetGlobalPolicyRequest request,
            FDelegateOnSuccessSetGlobalPolicy onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProfilesRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Profiles | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetGlobalPolicy(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetProfileLanguage, FProfilesSetProfileLanguageResponse, result, UObject*, customData);

    /**
     * Updates the entity's language. The precedence hierarchy for communication to the player is Title Player Account
     * language, Master Player Account language, and then title default language if the first two aren't set or supported.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Profiles | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProfilesAPI* SetProfileLanguage(FProfilesSetProfileLanguageRequest request,
            FDelegateOnSuccessSetProfileLanguage onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProfilesRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Profiles | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetProfileLanguage(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetProfilePolicy, FProfilesSetEntityProfilePolicyResponse, result, UObject*, customData);

    /** Sets the profiles access policy */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Profiles | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabProfilesAPI* SetProfilePolicy(FProfilesSetEntityProfilePolicyRequest request,
            FDelegateOnSuccessSetProfilePolicy onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabProfilesRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Profiles | Account Management ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetProfilePolicy(FPlayFabBaseModel response, UObject* customData, bool successful);



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
    FDelegateOnSuccessGetGlobalPolicy OnSuccessGetGlobalPolicy;
    FDelegateOnSuccessGetProfile OnSuccessGetProfile;
    FDelegateOnSuccessGetProfiles OnSuccessGetProfiles;
    FDelegateOnSuccessGetTitlePlayersFromMasterPlayerAccountIds OnSuccessGetTitlePlayersFromMasterPlayerAccountIds;
    FDelegateOnSuccessSetGlobalPolicy OnSuccessSetGlobalPolicy;
    FDelegateOnSuccessSetProfileLanguage OnSuccessSetProfileLanguage;
    FDelegateOnSuccessSetProfilePolicy OnSuccessSetProfilePolicy;

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
