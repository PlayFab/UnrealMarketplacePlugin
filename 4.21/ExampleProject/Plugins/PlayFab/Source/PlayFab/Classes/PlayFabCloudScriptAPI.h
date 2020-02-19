//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated header file for the UE4 PlayFab plugin.
// This header file contains the function definitions.
//
// API: CloudScript
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Http.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "PlayFabBaseModel.h"
#include "PlayFabCloudScriptModels.h"
#include "PlayFabCloudScriptAPI.generated.h"

class UPlayFabAuthenticationContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPlayFabCloudScriptRequestCompleted, FPlayFabBaseModel, response, UObject*, customData, bool, successful);

UCLASS(Blueprintable, BlueprintType)
class PLAYFAB_API UPlayFabCloudScriptAPI : public UOnlineBlueprintCallProxyBase
{
    GENERATED_UCLASS_BODY()

public:
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnFailurePlayFabError, FPlayFabError, error, UObject*, customData);

    UPROPERTY(BlueprintAssignable)
        FOnPlayFabCloudScriptRequestCompleted OnPlayFabResponse;

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
    // Generated PlayFab CloudScript API Functions
    //////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////
    // Server-Side Cloud Script
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessExecuteEntityCloudScript, FCloudScriptExecuteCloudScriptResult, result, UObject*, customData);

    /**
     * Cloud Script is one of PlayFab's most versatile features. It allows client code to request execution of any kind of
     * custom server-side functionality you can implement, and it can be used in conjunction with virtually anything.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabCloudScriptAPI* ExecuteEntityCloudScript(FCloudScriptExecuteEntityCloudScriptRequest request,
            FDelegateOnSuccessExecuteEntityCloudScript onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabCloudScriptRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperExecuteEntityCloudScript(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessExecuteFunction, FCloudScriptExecuteFunctionResult, result, UObject*, customData);

    /**
     * Cloud Script is one of PlayFab's most versatile features. It allows client code to request execution of any kind of
     * custom server-side functionality you can implement, and it can be used in conjunction with virtually anything.
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabCloudScriptAPI* ExecuteFunction(FCloudScriptExecuteFunctionRequest request,
            FDelegateOnSuccessExecuteFunction onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabCloudScriptRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperExecuteFunction(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListFunctions, FCloudScriptListFunctionsResult, result, UObject*, customData);

    /** Lists all currently registered Azure Functions for a given title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabCloudScriptAPI* ListFunctions(FCloudScriptListFunctionsRequest request,
            FDelegateOnSuccessListFunctions onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabCloudScriptRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListFunctions(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListHttpFunctions, FCloudScriptListHttpFunctionsResult, result, UObject*, customData);

    /** Lists all currently registered HTTP triggered Azure Functions for a given title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabCloudScriptAPI* ListHttpFunctions(FCloudScriptListFunctionsRequest request,
            FDelegateOnSuccessListHttpFunctions onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabCloudScriptRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListHttpFunctions(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessListQueuedFunctions, FCloudScriptListQueuedFunctionsResult, result, UObject*, customData);

    /** Lists all currently registered Queue triggered Azure Functions for a given title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabCloudScriptAPI* ListQueuedFunctions(FCloudScriptListFunctionsRequest request,
            FDelegateOnSuccessListQueuedFunctions onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabCloudScriptRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperListQueuedFunctions(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessPostFunctionResultForEntityTriggeredAction, FCloudScriptEmptyResult, result, UObject*, customData);

    /** Generate an entity PlayStream event for the provided function result. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabCloudScriptAPI* PostFunctionResultForEntityTriggeredAction(FCloudScriptPostFunctionResultForEntityTriggeredActionRequest request,
            FDelegateOnSuccessPostFunctionResultForEntityTriggeredAction onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabCloudScriptRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperPostFunctionResultForEntityTriggeredAction(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessPostFunctionResultForFunctionExecution, FCloudScriptEmptyResult, result, UObject*, customData);

    /** Generate an entity PlayStream event for the provided function result. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabCloudScriptAPI* PostFunctionResultForFunctionExecution(FCloudScriptPostFunctionResultForFunctionExecutionRequest request,
            FDelegateOnSuccessPostFunctionResultForFunctionExecution onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabCloudScriptRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperPostFunctionResultForFunctionExecution(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessPostFunctionResultForPlayerTriggeredAction, FCloudScriptEmptyResult, result, UObject*, customData);

    /** Generate a player PlayStream event for the provided function result. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabCloudScriptAPI* PostFunctionResultForPlayerTriggeredAction(FCloudScriptPostFunctionResultForPlayerTriggeredActionRequest request,
            FDelegateOnSuccessPostFunctionResultForPlayerTriggeredAction onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabCloudScriptRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperPostFunctionResultForPlayerTriggeredAction(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessPostFunctionResultForScheduledTask, FCloudScriptEmptyResult, result, UObject*, customData);

    /** Generate a PlayStream event for the provided function result. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabCloudScriptAPI* PostFunctionResultForScheduledTask(FCloudScriptPostFunctionResultForScheduledTaskRequest request,
            FDelegateOnSuccessPostFunctionResultForScheduledTask onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabCloudScriptRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperPostFunctionResultForScheduledTask(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRegisterHttpFunction, FCloudScriptEmptyResult, result, UObject*, customData);

    /** Registers an HTTP triggered Azure function with a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabCloudScriptAPI* RegisterHttpFunction(FCloudScriptRegisterHttpFunctionRequest request,
            FDelegateOnSuccessRegisterHttpFunction onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabCloudScriptRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRegisterHttpFunction(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessRegisterQueuedFunction, FCloudScriptEmptyResult, result, UObject*, customData);

    /** Registers a queue triggered Azure Function with a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabCloudScriptAPI* RegisterQueuedFunction(FCloudScriptRegisterQueuedFunctionRequest request,
            FDelegateOnSuccessRegisterQueuedFunction onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabCloudScriptRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperRegisterQueuedFunction(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUnregisterFunction, FCloudScriptEmptyResult, result, UObject*, customData);

    /** Unregisters an Azure Function with a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabCloudScriptAPI* UnregisterFunction(FCloudScriptUnregisterFunctionRequest request,
            FDelegateOnSuccessUnregisterFunction onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabCloudScriptRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | CloudScript | Server-Side Cloud Script ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUnregisterFunction(FPlayFabBaseModel response, UObject* customData, bool successful);



    /** PlayFab Request Info */
    FString PlayFabRequestURL;
    FString PlayFabRequestFullURL;

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
    FDelegateOnSuccessExecuteEntityCloudScript OnSuccessExecuteEntityCloudScript;
    FDelegateOnSuccessExecuteFunction OnSuccessExecuteFunction;
    FDelegateOnSuccessListFunctions OnSuccessListFunctions;
    FDelegateOnSuccessListHttpFunctions OnSuccessListHttpFunctions;
    FDelegateOnSuccessListQueuedFunctions OnSuccessListQueuedFunctions;
    FDelegateOnSuccessPostFunctionResultForEntityTriggeredAction OnSuccessPostFunctionResultForEntityTriggeredAction;
    FDelegateOnSuccessPostFunctionResultForFunctionExecution OnSuccessPostFunctionResultForFunctionExecution;
    FDelegateOnSuccessPostFunctionResultForPlayerTriggeredAction OnSuccessPostFunctionResultForPlayerTriggeredAction;
    FDelegateOnSuccessPostFunctionResultForScheduledTask OnSuccessPostFunctionResultForScheduledTask;
    FDelegateOnSuccessRegisterHttpFunction OnSuccessRegisterHttpFunction;
    FDelegateOnSuccessRegisterQueuedFunction OnSuccessRegisterQueuedFunction;
    FDelegateOnSuccessUnregisterFunction OnSuccessUnregisterFunction;

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
