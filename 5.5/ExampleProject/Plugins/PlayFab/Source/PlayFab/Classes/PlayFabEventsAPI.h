//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated header file for the UE4 PlayFab plugin.
// This header file contains the function definitions.
//
// API: Events
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Http.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "PlayFabBaseModel.h"
#include "PlayFabEventsModels.h"
#include "PlayFabEventsAPI.generated.h"

class UPlayFabAuthenticationContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPlayFabEventsRequestCompleted, FPlayFabBaseModel, response, UObject*, customData, bool, successful);

UCLASS(Blueprintable, BlueprintType)
class PLAYFAB_API UPlayFabEventsAPI : public UOnlineBlueprintCallProxyBase
{
    GENERATED_UCLASS_BODY()

public:
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnFailurePlayFabError, FPlayFabError, error, UObject*, customData);

    UPROPERTY(BlueprintAssignable)
        FOnPlayFabEventsRequestCompleted OnPlayFabResponse;

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
    // Generated PlayFab Events API Functions
    //////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////
    // PlayStream
    //////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////
    // PlayStream Events
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateTelemetryKey, FEventsCreateTelemetryKeyResponse, result, UObject*, customData);

    /** Creates a new telemetry key for the title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEventsAPI* CreateTelemetryKey(FEventsCreateTelemetryKeyRequest request,
            FDelegateOnSuccessCreateTelemetryKey onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);


    // Implements FOnPlayFabEventsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateTelemetryKey(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteTelemetryKey, FEventsDeleteTelemetryKeyResponse, result, UObject*, customData);

    /** Deletes a telemetry key configured for the title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEventsAPI* DeleteTelemetryKey(FEventsDeleteTelemetryKeyRequest request,
            FDelegateOnSuccessDeleteTelemetryKey onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);


    // Implements FOnPlayFabEventsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteTelemetryKey(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetTelemetryKey, FEventsGetTelemetryKeyResponse, result, UObject*, customData);

    /** Gets information about a telemetry key configured for the title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEventsAPI* GetTelemetryKey(FEventsGetTelemetryKeyRequest request,
            FDelegateOnSuccessGetTelemetryKey onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);


    // Implements FOnPlayFabEventsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetTelemetryKey(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListTelemetryKeys, FEventsListTelemetryKeysResponse, result, UObject*, customData);

    /** Lists all telemetry keys configured for the title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEventsAPI* ListTelemetryKeys(FEventsListTelemetryKeysRequest request,
            FDelegateOnSuccessListTelemetryKeys onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);


    // Implements FOnPlayFabEventsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListTelemetryKeys(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetTelemetryKeyActive, FEventsSetTelemetryKeyActiveResponse, result, UObject*, customData);

    /** Sets a telemetry key to the active or deactivated state. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEventsAPI* SetTelemetryKeyActive(FEventsSetTelemetryKeyActiveRequest request,
            FDelegateOnSuccessSetTelemetryKeyActive onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);


    // Implements FOnPlayFabEventsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetTelemetryKeyActive(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessWriteEvents, FEventsWriteEventsResponse, result, UObject*, customData);

    /** Write batches of entity based events to PlayStream. The namespace of the Event must be 'custom' or start with 'custom.'. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEventsAPI* WriteEvents(FEventsWriteEventsRequest request,
            FDelegateOnSuccessWriteEvents onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);


    // Implements FOnPlayFabEventsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperWriteEvents(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessWriteTelemetryEvents, FEventsWriteEventsResponse, result, UObject*, customData);

    /**
     * Write batches of entity based events to as Telemetry events (bypass PlayStream). The namespace must be 'custom' or start
     * with 'custom.'
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEventsAPI* WriteTelemetryEvents(FEventsWriteEventsRequest request,
            FDelegateOnSuccessWriteTelemetryEvents onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    /**
     * Write batches of entity based events to as Telemetry events (bypass PlayStream) using a Telemetry Key. The namespace must be 'custom' or start
     * with 'custom.'
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabEventsAPI* WriteTelemetryEventsWithTelemetryKey(FEventsWriteEventsRequest request, FString telemetryKey,
            FDelegateOnSuccessWriteTelemetryEvents onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabEventsRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperWriteTelemetryEvents(FPlayFabBaseModel response, UObject* customData, bool successful);



    /** PlayFab Request Info */
    FString PlayFabRequestURL;

    bool useEntityToken = false;
    bool useTelemetryKey = false;
    bool useSecretKey = false;
    bool useSessionTicket = false;
    bool returnsSessionTicket = false;
    bool returnsEntityToken = false;

    /** Is the response valid JSON? */
    bool bIsValidJsonResponse;
    FString ResponseContent;
    int32 ResponseCode;
    UObject* mCustomData;
    FString telemetryKey;

    FDelegateOnFailurePlayFabError OnFailure;
    FDelegateOnSuccessCreateTelemetryKey OnSuccessCreateTelemetryKey;
    FDelegateOnSuccessDeleteTelemetryKey OnSuccessDeleteTelemetryKey;
    FDelegateOnSuccessGetTelemetryKey OnSuccessGetTelemetryKey;
    FDelegateOnSuccessListTelemetryKeys OnSuccessListTelemetryKeys;
    FDelegateOnSuccessSetTelemetryKeyActive OnSuccessSetTelemetryKeyActive;
    FDelegateOnSuccessWriteEvents OnSuccessWriteEvents;
    FDelegateOnSuccessWriteTelemetryEvents OnSuccessWriteTelemetryEvents;

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
