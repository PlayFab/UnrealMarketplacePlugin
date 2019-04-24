//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated header file for the UE4 PlayFab plugin.
// This header file contains the function definitions.
//
// API: Authentication
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Http.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "PlayFabBaseModel.h"
#include "PlayFabAuthenticationModels.h"
#include "PlayFabAuthenticationAPI.generated.h"

class UPlayFabAuthenticationContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPlayFabAuthenticationRequestCompleted, FPlayFabBaseModel, response, UObject*, customData, bool, successful);

UCLASS(Blueprintable, BlueprintType)
class PLAYFAB_API UPlayFabAuthenticationAPI : public UOnlineBlueprintCallProxyBase
{
    GENERATED_UCLASS_BODY()

public:
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnFailurePlayFabError, FPlayFabError, error, UObject*, customData);

    UPROPERTY(BlueprintAssignable)
        FOnPlayFabAuthenticationRequestCompleted OnPlayFabResponse;

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
    // Generated PlayFab Authentication API Functions
    //////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////
    // API Keys
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessActivateKey, FAuthenticationActivateAPIKeyResponse, result, UObject*, customData);

    /** Activates the given API key. Active keys may be used for authentication. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Authentication | API Keys ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAuthenticationAPI* ActivateKey(FAuthenticationActivateAPIKeyRequest request,
            FDelegateOnSuccessActivateKey onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAuthenticationRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Authentication | API Keys ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperActivateKey(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateKey, FAuthenticationCreateAPIKeyResponse, result, UObject*, customData);

    /** Creates an API key for the given entity. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Authentication | API Keys ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAuthenticationAPI* CreateKey(FAuthenticationCreateAPIKeyRequest request,
            FDelegateOnSuccessCreateKey onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAuthenticationRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Authentication | API Keys ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateKey(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeactivateKey, FAuthenticationDeactivateAPIKeyResponse, result, UObject*, customData);

    /**
     * Deactivates the given API key, causing subsequent authentication attempts with it to fail.Deactivating a key is a way to
     * verify that the key is not in use before deleting it.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Authentication | API Keys ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAuthenticationAPI* DeactivateKey(FAuthenticationDeactivateAPIKeyRequest request,
            FDelegateOnSuccessDeactivateKey onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAuthenticationRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Authentication | API Keys ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeactivateKey(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteKey, FAuthenticationDeleteAPIKeyResponse, result, UObject*, customData);

    /** Deletes the given API key. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Authentication | API Keys ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAuthenticationAPI* DeleteKey(FAuthenticationDeleteAPIKeyRequest request,
            FDelegateOnSuccessDeleteKey onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAuthenticationRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Authentication | API Keys ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteKey(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetKeys, FAuthenticationGetAPIKeysResponse, result, UObject*, customData);

    /** Gets the API keys associated with the given entity. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Authentication | API Keys ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAuthenticationAPI* GetKeys(FAuthenticationGetAPIKeysRequest request,
            FDelegateOnSuccessGetKeys onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAuthenticationRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Authentication | API Keys ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetKeys(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Authentication
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetEntityToken, FAuthenticationGetEntityTokenResponse, result, UObject*, customData);

    /**
     * Method to exchange a legacy AuthenticationTicket or title SecretKey for an Entity Token or to refresh a still valid
     * Entity Token.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Authentication | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAuthenticationAPI* GetEntityToken(FAuthenticationGetEntityTokenRequest request,
            FDelegateOnSuccessGetEntityToken onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAuthenticationRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Authentication | Authentication ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetEntityToken(FPlayFabBaseModel response, UObject* customData, bool successful);



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
    FDelegateOnSuccessActivateKey OnSuccessActivateKey;
    FDelegateOnSuccessCreateKey OnSuccessCreateKey;
    FDelegateOnSuccessDeactivateKey OnSuccessDeactivateKey;
    FDelegateOnSuccessDeleteKey OnSuccessDeleteKey;
    FDelegateOnSuccessGetKeys OnSuccessGetKeys;
    FDelegateOnSuccessGetEntityToken OnSuccessGetEntityToken;

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
