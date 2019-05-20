//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated header file for the UE4 PlayFab plugin.
// This header file contains the function definitions.
//
// API: Data
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Http.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "PlayFabBaseModel.h"
#include "PlayFabDataModels.h"
#include "PlayFabDataAPI.generated.h"

class UPlayFabAuthenticationContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPlayFabDataRequestCompleted, FPlayFabBaseModel, response, UObject*, customData, bool, successful);

UCLASS(Blueprintable, BlueprintType)
class PLAYFAB_API UPlayFabDataAPI : public UOnlineBlueprintCallProxyBase
{
    GENERATED_UCLASS_BODY()

public:
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnFailurePlayFabError, FPlayFabError, error, UObject*, customData);

    UPROPERTY(BlueprintAssignable)
        FOnPlayFabDataRequestCompleted OnPlayFabResponse;

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
    // Generated PlayFab Data API Functions
    //////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////
    // File
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAbortFileUploads, FDataAbortFileUploadsResponse, result, UObject*, customData);

    /** Abort pending file uploads to an entity's profile. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Data | File ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabDataAPI* AbortFileUploads(FDataAbortFileUploadsRequest request,
            FDelegateOnSuccessAbortFileUploads onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabDataRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Data | File ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAbortFileUploads(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteFiles, FDataDeleteFilesResponse, result, UObject*, customData);

    /** Delete files on an entity's profile. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Data | File ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabDataAPI* DeleteFiles(FDataDeleteFilesRequest request,
            FDelegateOnSuccessDeleteFiles onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabDataRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Data | File ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteFiles(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessFinalizeFileUploads, FDataFinalizeFileUploadsResponse, result, UObject*, customData);

    /** Finalize file uploads to an entity's profile. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Data | File ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabDataAPI* FinalizeFileUploads(FDataFinalizeFileUploadsRequest request,
            FDelegateOnSuccessFinalizeFileUploads onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabDataRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Data | File ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperFinalizeFileUploads(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetFiles, FDataGetFilesResponse, result, UObject*, customData);

    /** Retrieves file metadata from an entity's profile. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Data | File ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabDataAPI* GetFiles(FDataGetFilesRequest request,
            FDelegateOnSuccessGetFiles onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabDataRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Data | File ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetFiles(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessInitiateFileUploads, FDataInitiateFileUploadsResponse, result, UObject*, customData);

    /** Initiates file uploads to an entity's profile. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Data | File ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabDataAPI* InitiateFileUploads(FDataInitiateFileUploadsRequest request,
            FDelegateOnSuccessInitiateFileUploads onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabDataRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Data | File ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperInitiateFileUploads(FPlayFabBaseModel response, UObject* customData, bool successful);


    ///////////////////////////////////////////////////////
    // Object
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetObjects, FDataGetObjectsResponse, result, UObject*, customData);

    /** Retrieves objects from an entity's profile. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Data | Object ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabDataAPI* GetObjects(FDataGetObjectsRequest request,
            FDelegateOnSuccessGetObjects onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabDataRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Data | Object ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetObjects(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessSetObjects, FDataSetObjectsResponse, result, UObject*, customData);

    /** Sets objects on an entity's profile. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Data | Object ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabDataAPI* SetObjects(FDataSetObjectsRequest request,
            FDelegateOnSuccessSetObjects onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabDataRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Data | Object ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperSetObjects(FPlayFabBaseModel response, UObject* customData, bool successful);



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
    FDelegateOnSuccessAbortFileUploads OnSuccessAbortFileUploads;
    FDelegateOnSuccessDeleteFiles OnSuccessDeleteFiles;
    FDelegateOnSuccessFinalizeFileUploads OnSuccessFinalizeFileUploads;
    FDelegateOnSuccessGetFiles OnSuccessGetFiles;
    FDelegateOnSuccessInitiateFileUploads OnSuccessInitiateFileUploads;
    FDelegateOnSuccessGetObjects OnSuccessGetObjects;
    FDelegateOnSuccessSetObjects OnSuccessSetObjects;

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
