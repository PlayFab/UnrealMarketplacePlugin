//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated header file for the UE4 PlayFab plugin.
// This header file contains the function definitions.
//
// API: Addon
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Http.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "PlayFabBaseModel.h"
#include "PlayFabAddonModels.h"
#include "PlayFabAddonAPI.generated.h"

class UPlayFabAuthenticationContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPlayFabAddonRequestCompleted, FPlayFabBaseModel, response, UObject*, customData, bool, successful);

UCLASS(Blueprintable, BlueprintType)
class PLAYFAB_API UPlayFabAddonAPI : public UOnlineBlueprintCallProxyBase
{
    GENERATED_UCLASS_BODY()

public:
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnFailurePlayFabError, FPlayFabError, error, UObject*, customData);

    UPROPERTY(BlueprintAssignable)
        FOnPlayFabAddonRequestCompleted OnPlayFabResponse;

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
    // Generated PlayFab Addon API Functions
    //////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////
    // Addon
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateOrUpdateApple, FAddonCreateOrUpdateAppleResponse, result, UObject*, customData);

    /** Creates the Apple addon on a title, or updates it if it already exists. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* CreateOrUpdateApple(FAddonCreateOrUpdateAppleRequest request,
            FDelegateOnSuccessCreateOrUpdateApple onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateOrUpdateApple(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateOrUpdateFacebook, FAddonCreateOrUpdateFacebookResponse, result, UObject*, customData);

    /** Creates the Facebook addon on a title, or updates it if it already exists. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* CreateOrUpdateFacebook(FAddonCreateOrUpdateFacebookRequest request,
            FDelegateOnSuccessCreateOrUpdateFacebook onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateOrUpdateFacebook(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateOrUpdateFacebookInstantGames, FAddonCreateOrUpdateFacebookInstantGamesResponse, result, UObject*, customData);

    /** Creates the Facebook Instant Games addon on a title, or updates it if it already exists. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* CreateOrUpdateFacebookInstantGames(FAddonCreateOrUpdateFacebookInstantGamesRequest request,
            FDelegateOnSuccessCreateOrUpdateFacebookInstantGames onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateOrUpdateFacebookInstantGames(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateOrUpdateGoogle, FAddonCreateOrUpdateGoogleResponse, result, UObject*, customData);

    /** Creates the Google addon on a title, or updates it if it already exists. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* CreateOrUpdateGoogle(FAddonCreateOrUpdateGoogleRequest request,
            FDelegateOnSuccessCreateOrUpdateGoogle onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateOrUpdateGoogle(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateOrUpdateKongregate, FAddonCreateOrUpdateKongregateResponse, result, UObject*, customData);

    /** Creates the Kongregate addon on a title, or updates it if it already exists. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* CreateOrUpdateKongregate(FAddonCreateOrUpdateKongregateRequest request,
            FDelegateOnSuccessCreateOrUpdateKongregate onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateOrUpdateKongregate(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateOrUpdateNintendo, FAddonCreateOrUpdateNintendoResponse, result, UObject*, customData);

    /** Creates the Nintendo addon on a title, or updates it if it already exists. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* CreateOrUpdateNintendo(FAddonCreateOrUpdateNintendoRequest request,
            FDelegateOnSuccessCreateOrUpdateNintendo onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateOrUpdateNintendo(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateOrUpdatePSN, FAddonCreateOrUpdatePSNResponse, result, UObject*, customData);

    /** Creates the PSN addon on a title, or updates it if it already exists. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* CreateOrUpdatePSN(FAddonCreateOrUpdatePSNRequest request,
            FDelegateOnSuccessCreateOrUpdatePSN onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateOrUpdatePSN(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateOrUpdateSteam, FAddonCreateOrUpdateSteamResponse, result, UObject*, customData);

    /** Creates the Steam addon on a title, or updates it if it already exists. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* CreateOrUpdateSteam(FAddonCreateOrUpdateSteamRequest request,
            FDelegateOnSuccessCreateOrUpdateSteam onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateOrUpdateSteam(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessCreateOrUpdateTwitch, FAddonCreateOrUpdateTwitchResponse, result, UObject*, customData);

    /** Creates the Twitch addon on a title, or updates it if it already exists. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* CreateOrUpdateTwitch(FAddonCreateOrUpdateTwitchRequest request,
            FDelegateOnSuccessCreateOrUpdateTwitch onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperCreateOrUpdateTwitch(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteApple, FAddonDeleteAppleResponse, result, UObject*, customData);

    /** Deletes the Apple addon on a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* DeleteApple(FAddonDeleteAppleRequest request,
            FDelegateOnSuccessDeleteApple onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteApple(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteFacebook, FAddonDeleteFacebookResponse, result, UObject*, customData);

    /** Deletes the Facebook addon on a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* DeleteFacebook(FAddonDeleteFacebookRequest request,
            FDelegateOnSuccessDeleteFacebook onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteFacebook(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteFacebookInstantGames, FAddonDeleteFacebookInstantGamesResponse, result, UObject*, customData);

    /** Deletes the Facebook addon on a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* DeleteFacebookInstantGames(FAddonDeleteFacebookInstantGamesRequest request,
            FDelegateOnSuccessDeleteFacebookInstantGames onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteFacebookInstantGames(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteGoogle, FAddonDeleteGoogleResponse, result, UObject*, customData);

    /** Deletes the Google addon on a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* DeleteGoogle(FAddonDeleteGoogleRequest request,
            FDelegateOnSuccessDeleteGoogle onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteGoogle(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteKongregate, FAddonDeleteKongregateResponse, result, UObject*, customData);

    /** Deletes the Kongregate addon on a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* DeleteKongregate(FAddonDeleteKongregateRequest request,
            FDelegateOnSuccessDeleteKongregate onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteKongregate(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteNintendo, FAddonDeleteNintendoResponse, result, UObject*, customData);

    /** Deletes the Nintendo addon on a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* DeleteNintendo(FAddonDeleteNintendoRequest request,
            FDelegateOnSuccessDeleteNintendo onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteNintendo(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeletePSN, FAddonDeletePSNResponse, result, UObject*, customData);

    /** Deletes the PSN addon on a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* DeletePSN(FAddonDeletePSNRequest request,
            FDelegateOnSuccessDeletePSN onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeletePSN(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteSteam, FAddonDeleteSteamResponse, result, UObject*, customData);

    /** Deletes the Steam addon on a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* DeleteSteam(FAddonDeleteSteamRequest request,
            FDelegateOnSuccessDeleteSteam onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteSteam(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessDeleteTwitch, FAddonDeleteTwitchResponse, result, UObject*, customData);

    /** Deletes the Twitch addon on a title. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* DeleteTwitch(FAddonDeleteTwitchRequest request,
            FDelegateOnSuccessDeleteTwitch onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperDeleteTwitch(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetApple, FAddonGetAppleResponse, result, UObject*, customData);

    /** Gets information of the Apple addon on a title, omits secrets. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* GetApple(FAddonGetAppleRequest request,
            FDelegateOnSuccessGetApple onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetApple(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetFacebook, FAddonGetFacebookResponse, result, UObject*, customData);

    /** Gets information of the Facebook addon on a title, omits secrets. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* GetFacebook(FAddonGetFacebookRequest request,
            FDelegateOnSuccessGetFacebook onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetFacebook(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetFacebookInstantGames, FAddonGetFacebookInstantGamesResponse, result, UObject*, customData);

    /** Gets information of the Facebook Instant Games addon on a title, omits secrets. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* GetFacebookInstantGames(FAddonGetFacebookInstantGamesRequest request,
            FDelegateOnSuccessGetFacebookInstantGames onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetFacebookInstantGames(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetGoogle, FAddonGetGoogleResponse, result, UObject*, customData);

    /** Gets information of the Google addon on a title, omits secrets. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* GetGoogle(FAddonGetGoogleRequest request,
            FDelegateOnSuccessGetGoogle onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetGoogle(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetKongregate, FAddonGetKongregateResponse, result, UObject*, customData);

    /** Gets information of the Kongregate addon on a title, omits secrets. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* GetKongregate(FAddonGetKongregateRequest request,
            FDelegateOnSuccessGetKongregate onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetKongregate(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetNintendo, FAddonGetNintendoResponse, result, UObject*, customData);

    /** Gets information of the Nintendo addon on a title, omits secrets. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* GetNintendo(FAddonGetNintendoRequest request,
            FDelegateOnSuccessGetNintendo onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetNintendo(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetPSN, FAddonGetPSNResponse, result, UObject*, customData);

    /** Gets information of the PSN addon on a title, omits secrets. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* GetPSN(FAddonGetPSNRequest request,
            FDelegateOnSuccessGetPSN onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetPSN(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetSteam, FAddonGetSteamResponse, result, UObject*, customData);

    /** Gets information of the Steam addon on a title, omits secrets. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* GetSteam(FAddonGetSteamRequest request,
            FDelegateOnSuccessGetSteam onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetSteam(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessGetTwitch, FAddonGetTwitchResponse, result, UObject*, customData);

    /** Gets information of the Twitch addon on a title, omits secrets. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabAddonAPI* GetTwitch(FAddonGetTwitchRequest request,
            FDelegateOnSuccessGetTwitch onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabAddonRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Addon | Addon ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperGetTwitch(FPlayFabBaseModel response, UObject* customData, bool successful);



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
    FDelegateOnSuccessCreateOrUpdateApple OnSuccessCreateOrUpdateApple;
    FDelegateOnSuccessCreateOrUpdateFacebook OnSuccessCreateOrUpdateFacebook;
    FDelegateOnSuccessCreateOrUpdateFacebookInstantGames OnSuccessCreateOrUpdateFacebookInstantGames;
    FDelegateOnSuccessCreateOrUpdateGoogle OnSuccessCreateOrUpdateGoogle;
    FDelegateOnSuccessCreateOrUpdateKongregate OnSuccessCreateOrUpdateKongregate;
    FDelegateOnSuccessCreateOrUpdateNintendo OnSuccessCreateOrUpdateNintendo;
    FDelegateOnSuccessCreateOrUpdatePSN OnSuccessCreateOrUpdatePSN;
    FDelegateOnSuccessCreateOrUpdateSteam OnSuccessCreateOrUpdateSteam;
    FDelegateOnSuccessCreateOrUpdateTwitch OnSuccessCreateOrUpdateTwitch;
    FDelegateOnSuccessDeleteApple OnSuccessDeleteApple;
    FDelegateOnSuccessDeleteFacebook OnSuccessDeleteFacebook;
    FDelegateOnSuccessDeleteFacebookInstantGames OnSuccessDeleteFacebookInstantGames;
    FDelegateOnSuccessDeleteGoogle OnSuccessDeleteGoogle;
    FDelegateOnSuccessDeleteKongregate OnSuccessDeleteKongregate;
    FDelegateOnSuccessDeleteNintendo OnSuccessDeleteNintendo;
    FDelegateOnSuccessDeletePSN OnSuccessDeletePSN;
    FDelegateOnSuccessDeleteSteam OnSuccessDeleteSteam;
    FDelegateOnSuccessDeleteTwitch OnSuccessDeleteTwitch;
    FDelegateOnSuccessGetApple OnSuccessGetApple;
    FDelegateOnSuccessGetFacebook OnSuccessGetFacebook;
    FDelegateOnSuccessGetFacebookInstantGames OnSuccessGetFacebookInstantGames;
    FDelegateOnSuccessGetGoogle OnSuccessGetGoogle;
    FDelegateOnSuccessGetKongregate OnSuccessGetKongregate;
    FDelegateOnSuccessGetNintendo OnSuccessGetNintendo;
    FDelegateOnSuccessGetPSN OnSuccessGetPSN;
    FDelegateOnSuccessGetSteam OnSuccessGetSteam;
    FDelegateOnSuccessGetTwitch OnSuccessGetTwitch;

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
