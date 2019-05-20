//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated header file for the UE4 PlayFab plugin.
// This header file contains the function definitions.
//
// API: Matchmaker
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Http.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "PlayFabBaseModel.h"
#include "PlayFabMatchmakerModels.h"
#include "PlayFabMatchmakerAPI.generated.h"

class UPlayFabAuthenticationContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPlayFabMatchmakerRequestCompleted, FPlayFabBaseModel, response, UObject*, customData, bool, successful);

UCLASS(Blueprintable, BlueprintType)
class PLAYFAB_API UPlayFabMatchmakerAPI : public UOnlineBlueprintCallProxyBase
{
    GENERATED_UCLASS_BODY()

public:
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnFailurePlayFabError, FPlayFabError, error, UObject*, customData);

    UPROPERTY(BlueprintAssignable)
        FOnPlayFabMatchmakerRequestCompleted OnPlayFabResponse;

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
    // Generated PlayFab Matchmaker API Functions
    //////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////
    // Matchmaking
    //////////////////////////////////////////////////////
    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessAuthUser, FMatchmakerAuthUserResponse, result, UObject*, customData);

    /** Validates a user with the PlayFab service */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Matchmaker | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMatchmakerAPI* AuthUser(FMatchmakerAuthUserRequest request,
            FDelegateOnSuccessAuthUser onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMatchmakerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Matchmaker | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperAuthUser(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessPlayerJoined, FMatchmakerPlayerJoinedResponse, result, UObject*, customData);

    /** Informs the PlayFab game server hosting service that the indicated user has joined the Game Server Instance specified */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Matchmaker | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMatchmakerAPI* PlayerJoined(FMatchmakerPlayerJoinedRequest request,
            FDelegateOnSuccessPlayerJoined onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMatchmakerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Matchmaker | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperPlayerJoined(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessPlayerLeft, FMatchmakerPlayerLeftResponse, result, UObject*, customData);

    /** Informs the PlayFab game server hosting service that the indicated user has left the Game Server Instance specified */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Matchmaker | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMatchmakerAPI* PlayerLeft(FMatchmakerPlayerLeftRequest request,
            FDelegateOnSuccessPlayerLeft onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMatchmakerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Matchmaker | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperPlayerLeft(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessStartGame, FMatchmakerStartGameResponse, result, UObject*, customData);

    /** Instructs the PlayFab game server hosting service to instantiate a new Game Server Instance */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Matchmaker | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMatchmakerAPI* StartGame(FMatchmakerStartGameRequest request,
            FDelegateOnSuccessStartGame onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMatchmakerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Matchmaker | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperStartGame(FPlayFabBaseModel response, UObject* customData, bool successful);

    // callbacks
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateOnSuccessUserInfo, FMatchmakerUserInfoResponse, result, UObject*, customData);

    /**
     * Retrieves the relevant details for a specified user, which the external match-making service can then use to compute
     * effective matches
     */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Matchmaker | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        static UPlayFabMatchmakerAPI* UserInfo(FMatchmakerUserInfoRequest request,
            FDelegateOnSuccessUserInfo onSuccess,
            FDelegateOnFailurePlayFabError onFailure, UObject* customData);

    // Implements FOnPlayFabMatchmakerRequestCompleted
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Matchmaker | Matchmaking ", meta = (BlueprintInternalUseOnly = "true"))
        void HelperUserInfo(FPlayFabBaseModel response, UObject* customData, bool successful);



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
    FDelegateOnSuccessAuthUser OnSuccessAuthUser;
    FDelegateOnSuccessPlayerJoined OnSuccessPlayerJoined;
    FDelegateOnSuccessPlayerLeft OnSuccessPlayerLeft;
    FDelegateOnSuccessStartGame OnSuccessStartGame;
    FDelegateOnSuccessUserInfo OnSuccessUserInfo;

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
