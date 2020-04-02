//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated header file for the UE4 PlayFab plugin.
// This header file contains the function definitions.
//
// API: Insights
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Http.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "PlayFabBaseModel.h"
#include "PlayFabInsightsModels.h"
#include "PlayFabInsightsAPI.generated.h"

class UPlayFabAuthenticationContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPlayFabInsightsRequestCompleted, FPlayFabBaseModel, response, UObject*, customData, bool, successful);

UCLASS(Blueprintable, BlueprintType)
class PLAYFAB_API UPlayFabInsightsAPI : public UOnlineBlueprintCallProxyBase
{
    GENERATED_UCLASS_BODY()

public:
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnFailurePlayFabError, FPlayFabError, error, UObject*, customData);

    UPROPERTY(BlueprintAssignable)
        FOnPlayFabInsightsRequestCompleted OnPlayFabResponse;

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
    // Generated PlayFab Insights API Functions
    //////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////
    // Analytics
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetDetails, FInsightsInsightsGetDetailsResponse, result, UObject*, customData);

    /**
     * Gets the current values for the Insights performance and data storage retention, list of pending operations, and the
     * performance and data storage retention limits.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Insights | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabInsightsAPI* GetDetails(FInsightsInsightsEmptyRequest request,
            FDelegateOnSuccessGetDetails onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabInsightsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Insights | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetDetails(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetLimits, FInsightsInsightsGetLimitsResponse, result, UObject*, customData);

    /**
     * Retrieves the range of allowed values for performance and data storage retention values as well as the submeter details
     * for each performance level.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Insights | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabInsightsAPI* GetLimits(FInsightsInsightsEmptyRequest request,
            FDelegateOnSuccessGetLimits onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabInsightsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Insights | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetLimits(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetOperationStatus, FInsightsInsightsGetOperationStatusResponse, result, UObject*, customData);

    /** Gets the status of a SetPerformance or SetStorageRetention operation. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Insights | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabInsightsAPI* GetOperationStatus(FInsightsInsightsGetOperationStatusRequest request,
            FDelegateOnSuccessGetOperationStatus onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabInsightsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Insights | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetOperationStatus(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPendingOperations, FInsightsInsightsGetPendingOperationsResponse, result, UObject*, customData);

    /** Gets a list of pending SetPerformance and/or SetStorageRetention operations for the title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Insights | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabInsightsAPI* GetPendingOperations(FInsightsInsightsGetPendingOperationsRequest request,
            FDelegateOnSuccessGetPendingOperations onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabInsightsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Insights | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPendingOperations(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetPerformance, FInsightsInsightsOperationResponse, result, UObject*, customData);

    /** Sets the Insights performance level value for the title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Insights | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabInsightsAPI* SetPerformance(FInsightsInsightsSetPerformanceRequest request,
            FDelegateOnSuccessSetPerformance onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabInsightsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Insights | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetPerformance(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetStorageRetention, FInsightsInsightsOperationResponse, result, UObject*, customData);

    /** Sets the Insights data storage retention days value for the title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Insights | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabInsightsAPI* SetStorageRetention(FInsightsInsightsSetStorageRetentionRequest request,
            FDelegateOnSuccessSetStorageRetention onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabInsightsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Insights | Analytics ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetStorageRetention(FPlayFabBaseModel response, UObject* customData, bool successful);



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
    FDelegateOnSuccessGetDetails OnSuccessGetDetails;
    FDelegateOnSuccessGetLimits OnSuccessGetLimits;
    FDelegateOnSuccessGetOperationStatus OnSuccessGetOperationStatus;
    FDelegateOnSuccessGetPendingOperations OnSuccessGetPendingOperations;
    FDelegateOnSuccessSetPerformance OnSuccessSetPerformance;
    FDelegateOnSuccessSetStorageRetention OnSuccessSetStorageRetention;

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
