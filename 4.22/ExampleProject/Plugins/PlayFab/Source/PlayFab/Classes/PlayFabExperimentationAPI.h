//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated header file for the UE4 PlayFab plugin.
// This header file contains the function definitions.
//
// API: Experimentation
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Http.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "PlayFabBaseModel.h"
#include "PlayFabExperimentationModels.h"
#include "PlayFabExperimentationAPI.generated.h"

class UPlayFabAuthenticationContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPlayFabExperimentationRequestCompleted, FPlayFabBaseModel, response, UObject*, customData, bool, successful);

UCLASS(Blueprintable, BlueprintType)
class PLAYFAB_API UPlayFabExperimentationAPI : public UOnlineBlueprintCallProxyBase
{
    GENERATED_UCLASS_BODY()

public:
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnFailurePlayFabError, FPlayFabError, error, UObject*, customData);

    UPROPERTY(BlueprintAssignable)
        FOnPlayFabExperimentationRequestCompleted OnPlayFabResponse;

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
    // Generated PlayFab Experimentation API Functions
    //////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////
    // Experimentation
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateExperiment, FExperimentationCreateExperimentResult, result, UObject*, customData);

    /** Creates a new experiment for a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Experimentation | Experimentation ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabExperimentationAPI* CreateExperiment(FExperimentationCreateExperimentRequest request,
            FDelegateOnSuccessCreateExperiment onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabExperimentationRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Experimentation | Experimentation ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateExperiment(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteExperiment, FExperimentationEmptyResponse, result, UObject*, customData);

    /** Deletes an existing experiment for a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Experimentation | Experimentation ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabExperimentationAPI* DeleteExperiment(FExperimentationDeleteExperimentRequest request,
            FDelegateOnSuccessDeleteExperiment onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabExperimentationRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Experimentation | Experimentation ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteExperiment(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetExperiments, FExperimentationGetExperimentsResult, result, UObject*, customData);

    /** Gets the details of all experiments for a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Experimentation | Experimentation ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabExperimentationAPI* GetExperiments(FExperimentationGetExperimentsRequest request,
            FDelegateOnSuccessGetExperiments onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabExperimentationRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Experimentation | Experimentation ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetExperiments(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetLatestScorecard, FExperimentationGetLatestScorecardResult, result, UObject*, customData);

    /** Gets the latest scorecard of the experiment for the title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Experimentation | Experimentation ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabExperimentationAPI* GetLatestScorecard(FExperimentationGetLatestScorecardRequest request,
            FDelegateOnSuccessGetLatestScorecard onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabExperimentationRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Experimentation | Experimentation ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetLatestScorecard(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetTreatmentAssignment, FExperimentationGetTreatmentAssignmentResult, result, UObject*, customData);

    /** Gets the treatment assignments for a player for every running experiment in the title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Experimentation | Experimentation ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabExperimentationAPI* GetTreatmentAssignment(FExperimentationGetTreatmentAssignmentRequest request,
            FDelegateOnSuccessGetTreatmentAssignment onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabExperimentationRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Experimentation | Experimentation ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetTreatmentAssignment(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessStartExperiment, FExperimentationEmptyResponse, result, UObject*, customData);

    /** Starts an existing experiment for a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Experimentation | Experimentation ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabExperimentationAPI* StartExperiment(FExperimentationStartExperimentRequest request,
            FDelegateOnSuccessStartExperiment onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabExperimentationRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Experimentation | Experimentation ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperStartExperiment(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessStopExperiment, FExperimentationEmptyResponse, result, UObject*, customData);

    /** Stops an existing experiment for a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Experimentation | Experimentation ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabExperimentationAPI* StopExperiment(FExperimentationStopExperimentRequest request,
            FDelegateOnSuccessStopExperiment onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabExperimentationRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Experimentation | Experimentation ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperStopExperiment(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUpdateExperiment, FExperimentationEmptyResponse, result, UObject*, customData);

    /** Updates an existing experiment for a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Experimentation | Experimentation ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabExperimentationAPI* UpdateExperiment(FExperimentationUpdateExperimentRequest request,
            FDelegateOnSuccessUpdateExperiment onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabExperimentationRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Experimentation | Experimentation ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUpdateExperiment(FPlayFabBaseModel response, UObject* customData, bool successful);



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
    FDelegateOnSuccessCreateExperiment OnSuccessCreateExperiment;
    FDelegateOnSuccessDeleteExperiment OnSuccessDeleteExperiment;
    FDelegateOnSuccessGetExperiments OnSuccessGetExperiments;
    FDelegateOnSuccessGetLatestScorecard OnSuccessGetLatestScorecard;
    FDelegateOnSuccessGetTreatmentAssignment OnSuccessGetTreatmentAssignment;
    FDelegateOnSuccessStartExperiment OnSuccessStartExperiment;
    FDelegateOnSuccessStopExperiment OnSuccessStopExperiment;
    FDelegateOnSuccessUpdateExperiment OnSuccessUpdateExperiment;

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
