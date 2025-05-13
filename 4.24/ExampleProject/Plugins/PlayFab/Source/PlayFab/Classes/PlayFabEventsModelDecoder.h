//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Events
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabEventsModels.h"
#include "PlayFabEventsModelDecoder.generated.h"

class UPlayFabJsonObject;

UCLASS()
class PLAYFAB_API UPlayFabEventsModelDecoder : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    //////////////////////////////////////////////////////////////////////////
    // Generated PlayFab Events API Functions
    //////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////
    // PlayStream
    //////////////////////////////////////////////////////



    ///////////////////////////////////////////////////////
    // PlayStream Events
    //////////////////////////////////////////////////////

    /** Decode the CreateTelemetryKeyResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events Models")
        static FEventsCreateTelemetryKeyResponse decodeCreateTelemetryKeyResponseResponse(UPlayFabJsonObject* response);

    /** Decode the DeleteDataConnectionResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events Models")
        static FEventsDeleteDataConnectionResponse decodeDeleteDataConnectionResponseResponse(UPlayFabJsonObject* response);

    /** Decode the DeleteTelemetryKeyResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events Models")
        static FEventsDeleteTelemetryKeyResponse decodeDeleteTelemetryKeyResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetDataConnectionResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events Models")
        static FEventsGetDataConnectionResponse decodeGetDataConnectionResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetTelemetryKeyResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events Models")
        static FEventsGetTelemetryKeyResponse decodeGetTelemetryKeyResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListDataConnectionsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events Models")
        static FEventsListDataConnectionsResponse decodeListDataConnectionsResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ListTelemetryKeysResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events Models")
        static FEventsListTelemetryKeysResponse decodeListTelemetryKeysResponseResponse(UPlayFabJsonObject* response);

    /** Decode the SetDataConnectionResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events Models")
        static FEventsSetDataConnectionResponse decodeSetDataConnectionResponseResponse(UPlayFabJsonObject* response);

    /** Decode the SetDataConnectionActiveResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events Models")
        static FEventsSetDataConnectionActiveResponse decodeSetDataConnectionActiveResponseResponse(UPlayFabJsonObject* response);

    /** Decode the SetTelemetryKeyActiveResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events Models")
        static FEventsSetTelemetryKeyActiveResponse decodeSetTelemetryKeyActiveResponseResponse(UPlayFabJsonObject* response);

    /** Decode the WriteEventsResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Events | PlayStream Events Models")
        static FEventsWriteEventsResponse decodeWriteEventsResponseResponse(UPlayFabJsonObject* response);



};
