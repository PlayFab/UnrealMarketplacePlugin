//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Addon
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabAddonModels.h"
#include "PlayFabAddonModelDecoder.generated.h"

class UPlayFabJsonObject;

UCLASS()
class PLAYFAB_API UPlayFabAddonModelDecoder : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    //////////////////////////////////////////////////////////////////////////
    // Generated PlayFab Addon API Functions
    //////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////
    // Addon
    //////////////////////////////////////////////////////

    /** Decode the CreateOrUpdateAppleResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonCreateOrUpdateAppleResponse decodeCreateOrUpdateAppleResponseResponse(UPlayFabJsonObject* response);

    /** Decode the CreateOrUpdateFacebookResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonCreateOrUpdateFacebookResponse decodeCreateOrUpdateFacebookResponseResponse(UPlayFabJsonObject* response);

    /** Decode the CreateOrUpdateFacebookInstantGamesResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonCreateOrUpdateFacebookInstantGamesResponse decodeCreateOrUpdateFacebookInstantGamesResponseResponse(UPlayFabJsonObject* response);

    /** Decode the CreateOrUpdateGoogleResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonCreateOrUpdateGoogleResponse decodeCreateOrUpdateGoogleResponseResponse(UPlayFabJsonObject* response);

    /** Decode the CreateOrUpdateKongregateResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonCreateOrUpdateKongregateResponse decodeCreateOrUpdateKongregateResponseResponse(UPlayFabJsonObject* response);

    /** Decode the CreateOrUpdateNintendoResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonCreateOrUpdateNintendoResponse decodeCreateOrUpdateNintendoResponseResponse(UPlayFabJsonObject* response);

    /** Decode the CreateOrUpdatePSNResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonCreateOrUpdatePSNResponse decodeCreateOrUpdatePSNResponseResponse(UPlayFabJsonObject* response);

    /** Decode the CreateOrUpdateSteamResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonCreateOrUpdateSteamResponse decodeCreateOrUpdateSteamResponseResponse(UPlayFabJsonObject* response);

    /** Decode the CreateOrUpdateTwitchResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonCreateOrUpdateTwitchResponse decodeCreateOrUpdateTwitchResponseResponse(UPlayFabJsonObject* response);

    /** Decode the DeleteAppleResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonDeleteAppleResponse decodeDeleteAppleResponseResponse(UPlayFabJsonObject* response);

    /** Decode the DeleteFacebookResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonDeleteFacebookResponse decodeDeleteFacebookResponseResponse(UPlayFabJsonObject* response);

    /** Decode the DeleteFacebookInstantGamesResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonDeleteFacebookInstantGamesResponse decodeDeleteFacebookInstantGamesResponseResponse(UPlayFabJsonObject* response);

    /** Decode the DeleteGoogleResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonDeleteGoogleResponse decodeDeleteGoogleResponseResponse(UPlayFabJsonObject* response);

    /** Decode the DeleteKongregateResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonDeleteKongregateResponse decodeDeleteKongregateResponseResponse(UPlayFabJsonObject* response);

    /** Decode the DeleteNintendoResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonDeleteNintendoResponse decodeDeleteNintendoResponseResponse(UPlayFabJsonObject* response);

    /** Decode the DeletePSNResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonDeletePSNResponse decodeDeletePSNResponseResponse(UPlayFabJsonObject* response);

    /** Decode the DeleteSteamResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonDeleteSteamResponse decodeDeleteSteamResponseResponse(UPlayFabJsonObject* response);

    /** Decode the DeleteTwitchResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonDeleteTwitchResponse decodeDeleteTwitchResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetAppleResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonGetAppleResponse decodeGetAppleResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetFacebookResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonGetFacebookResponse decodeGetFacebookResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetFacebookInstantGamesResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonGetFacebookInstantGamesResponse decodeGetFacebookInstantGamesResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetGoogleResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonGetGoogleResponse decodeGetGoogleResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetKongregateResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonGetKongregateResponse decodeGetKongregateResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetNintendoResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonGetNintendoResponse decodeGetNintendoResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetPSNResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonGetPSNResponse decodeGetPSNResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetSteamResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonGetSteamResponse decodeGetSteamResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetTwitchResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon Models")
        static FAddonGetTwitchResponse decodeGetTwitchResponseResponse(UPlayFabJsonObject* response);



};
