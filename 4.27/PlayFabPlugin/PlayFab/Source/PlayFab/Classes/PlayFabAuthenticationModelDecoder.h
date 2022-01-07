//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Authentication
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabAuthenticationModels.h"
#include "PlayFabAuthenticationModelDecoder.generated.h"

class UPlayFabJsonObject;

UCLASS()
class PLAYFAB_API UPlayFabAuthenticationModelDecoder : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    //////////////////////////////////////////////////////////////////////////
    // Generated PlayFab Authentication API Functions
    //////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////
    // API Keys
    //////////////////////////////////////////////////////



    ///////////////////////////////////////////////////////
    // Authentication
    //////////////////////////////////////////////////////

    /** Decode the GetEntityTokenResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Authentication | Authentication Models")
        static FAuthenticationGetEntityTokenResponse decodeGetEntityTokenResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ValidateEntityTokenResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Authentication | Authentication Models")
        static FAuthenticationValidateEntityTokenResponse decodeValidateEntityTokenResponseResponse(UPlayFabJsonObject* response);



};
