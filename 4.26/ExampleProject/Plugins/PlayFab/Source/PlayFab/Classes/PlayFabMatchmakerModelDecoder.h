//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Matchmaker
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabMatchmakerModels.h"
#include "PlayFabMatchmakerModelDecoder.generated.h"

class UPlayFabJsonObject;

UCLASS()
class PLAYFAB_API UPlayFabMatchmakerModelDecoder : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    //////////////////////////////////////////////////////////////////////////
    // Generated PlayFab Matchmaker API Functions
    //////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////
    // Matchmaking
    //////////////////////////////////////////////////////

    /** Decode the AuthUserResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Matchmaker | Matchmaking Models")
        static FMatchmakerAuthUserResponse decodeAuthUserResponseResponse(UPlayFabJsonObject* response);

    /** Decode the PlayerJoinedResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Matchmaker | Matchmaking Models")
        static FMatchmakerPlayerJoinedResponse decodePlayerJoinedResponseResponse(UPlayFabJsonObject* response);

    /** Decode the PlayerLeftResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Matchmaker | Matchmaking Models")
        static FMatchmakerPlayerLeftResponse decodePlayerLeftResponseResponse(UPlayFabJsonObject* response);

    /** Decode the StartGameResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Matchmaker | Matchmaking Models")
        static FMatchmakerStartGameResponse decodeStartGameResponseResponse(UPlayFabJsonObject* response);

    /** Decode the UserInfoResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Matchmaker | Matchmaking Models")
        static FMatchmakerUserInfoResponse decodeUserInfoResponseResponse(UPlayFabJsonObject* response);



};
