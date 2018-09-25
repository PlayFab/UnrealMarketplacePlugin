//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Data
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabDataModels.h"
#include "PlayFabDataModelDecoder.generated.h"

class UPlayFabJsonObject;

UCLASS()
class PLAYFAB_API UPlayFabDataModelDecoder : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    //////////////////////////////////////////////////////////////////////////
    // Generated PlayFab Data API Functions
    //////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////
    // File
    //////////////////////////////////////////////////////

    /** Decode the AbortFileUploadsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Data | File Models")
        static FDataAbortFileUploadsResponse decodeAbortFileUploadsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the DeleteFilesResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Data | File Models")
        static FDataDeleteFilesResponse decodeDeleteFilesResponseResponse(UPlayFabJsonObject* response);

    /** Decode the FinalizeFileUploadsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Data | File Models")
        static FDataFinalizeFileUploadsResponse decodeFinalizeFileUploadsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetFilesResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Data | File Models")
        static FDataGetFilesResponse decodeGetFilesResponseResponse(UPlayFabJsonObject* response);

    /** Decode the InitiateFileUploadsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Data | File Models")
        static FDataInitiateFileUploadsResponse decodeInitiateFileUploadsResponseResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Object
    //////////////////////////////////////////////////////

    /** Decode the GetObjectsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Data | Object Models")
        static FDataGetObjectsResponse decodeGetObjectsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the SetObjectsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Data | Object Models")
        static FDataSetObjectsResponse decodeSetObjectsResponseResponse(UPlayFabJsonObject* response);



};
