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
#include "PlayFabRequestCommon.h"
#include "PlayFabLoginResultCommon.h"
#include "PlayFabAddonModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Addon API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Addon
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonCreateOrUpdateAppleRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Allow validation of receipts from the Apple production environment. Required for app releases. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool AllowProduction = false;
    /** Allow validation of receipts from the Apple sandbox environment. Typically used while testing. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool AllowSandbox = false;
    /** iOS App Bundle ID obtained after setting up your app in the App Store. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString AppBundleId;
    /** AppId obtained after setting up your app in the App Store. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString AppId;
    /** iOS App Shared Secret obtained after setting up your app in the App Store. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString AppSharedSecret;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** If an error should be returned if the addon already exists. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool ErrorIfExists = false;
    /**
     * Ignore expiration date for identity tokens. Be aware that when set to true this can invalidate expired tokens in the
     * case where Apple rotates their signing keys.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool IgnoreExpirationDate = false;
    /** IssuerId obtained after setting up your app in the App Store. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString IssuerId;
    /** KeyId obtained after setting up your app in the App Store. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString KeyId;
    /** PrivateKey obtained after setting up your app in the App Store. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString PrivateKey;
    /** Require secure authentication only for this app. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool RequireSecureAuthentication = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonCreateOrUpdateAppleResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonCreateOrUpdateFacebookRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Facebook App ID obtained after setting up your app in Facebook. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString AppID;
    /** Facebook App Secret obtained after setting up your app in Facebook. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString AppSecret;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** If an error should be returned if the addon already exists. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool ErrorIfExists = false;
    /** Email address for purchase dispute notifications. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString NotificationEmail;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonCreateOrUpdateFacebookResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonCreateOrUpdateFacebookInstantGamesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Facebook App ID obtained after setting up your app in Facebook Instant Games. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString AppID;
    /** Facebook App Secret obtained after setting up your app in Facebook Instant Games. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString AppSecret;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** If an error should be returned if the addon already exists. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool ErrorIfExists = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonCreateOrUpdateFacebookInstantGamesResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonCreateOrUpdateGoogleRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Google App License Key obtained after setting up your app in the Google Play developer portal. Required if using Google
     * receipt validation.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString AppLicenseKey;
    /**
     * Google App Package ID obtained after setting up your app in the Google Play developer portal. Required if using Google
     * receipt validation.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString AppPackageID;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** If an error should be returned if the addon already exists. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool ErrorIfExists = false;
    /**
     * Google OAuth Client ID obtained through the Google Developer Console by creating a new set of "OAuth Client ID".
     * Required if using Google Authentication.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString OAuthClientID;
    /**
     * Google OAuth Client Secret obtained through the Google Developer Console by creating a new set of "OAuth Client ID".
     * Required if using Google Authentication.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString OAuthClientSecret;
    /**
     * Authorized Redirect Uri obtained through the Google Developer Console. This currently defaults to
     * https://oauth.playfab.com/oauth2/google. If you are authenticating players via browser, please update this to your own
     * domain.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString OAuthCustomRedirectUri;
    /** Needed to enable pending purchase handling and subscription processing. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString ServiceAccountKey;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonCreateOrUpdateGoogleResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonCreateOrUpdateKongregateRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** If an error should be returned if the addon already exists. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool ErrorIfExists = false;
    /** Kongregate Secret API Key obtained after setting up your game in your Kongregate developer account. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString SecretAPIKey;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonCreateOrUpdateKongregateResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonCreateOrUpdateNintendoRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Nintendo Switch Application ID, without the "0x" prefix. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString ApplicationID;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** List of Nintendo Environments, currently supporting up to 4. Needs Catalog enabled. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        TArray<UPlayFabJsonObject*> Environments;
    /** If an error should be returned if the addon already exists. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool ErrorIfExists = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonCreateOrUpdateNintendoResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonCreateOrUpdatePSNRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Client ID obtained after setting up your game with Sony. This one is associated with the existing PS4 marketplace. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString ClientID;
    /** Client secret obtained after setting up your game with Sony. This one is associated with the existing PS4 marketplace. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString ClientSecret;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** If an error should be returned if the addon already exists. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool ErrorIfExists = false;
    /**
     * Client ID obtained after setting up your game with Sony. This one is associated with the modern marketplace, which
     * includes PS5, cross-generation for PS4, and unified entitlements.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString NextGenClientID;
    /**
     * Client secret obtained after setting up your game with Sony. This one is associated with the modern marketplace, which
     * includes PS5, cross-generation for PS4, and unified entitlements.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString NextGenClientSecret;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonCreateOrUpdatePSNResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonCreateOrUpdateSteamRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Application ID obtained after setting up your app in Valve's developer portal. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString ApplicationId;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Enforce usage of AzurePlayFab identity in user authentication tickets. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool EnforceServiceSpecificTickets = false;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** If an error should be returned if the addon already exists. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool ErrorIfExists = false;
    /** Sercet Key obtained after setting up your app in Valve's developer portal. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString SecretKey;
    /** Use Steam Payments sandbox endpoint for test transactions. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool UseSandbox = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonCreateOrUpdateSteamResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonCreateOrUpdateToxModRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Account ID obtained after creating your ToxMod developer account. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString AccountId;
    /** Account Key obtained after creating your ToxMod developer account. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString AccountKey;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** Whether ToxMod Addon is Enabled by Title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool Enabled = false;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** If an error should be returned if the addon already exists. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool ErrorIfExists = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonCreateOrUpdateToxModResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonCreateOrUpdateTwitchRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Client ID obtained after creating your Twitch developer account. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString ClientID;
    /** Client Secret obtained after creating your Twitch developer account. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString ClientSecret;
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
    /** If an error should be returned if the addon already exists. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool ErrorIfExists = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonCreateOrUpdateTwitchResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonDeleteAppleRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonDeleteAppleResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonDeleteFacebookRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonDeleteFacebookResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonDeleteFacebookInstantGamesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonDeleteFacebookInstantGamesResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonDeleteGoogleRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonDeleteGoogleResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonDeleteKongregateRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonDeleteKongregateResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonDeleteNintendoRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonDeleteNintendoResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonDeletePSNRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonDeletePSNResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonDeleteSteamRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonDeleteSteamResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonDeleteToxModRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonDeleteToxModResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonDeleteTwitchRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonDeleteTwitchResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonGetAppleRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonGetAppleResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** iOS App Bundle ID obtained after setting up your app in the App Store. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString AppBundleId;
    /** Addon status. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool Created = false;
    /** Ignore expiration date for identity tokens. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool IgnoreExpirationDate = false;
    /** Require secure authentication only for this app. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool RequireSecureAuthentication = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonGetFacebookRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonGetFacebookResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Facebook App ID obtained after setting up your app in Facebook. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString AppID;
    /** Addon status. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool Created = false;
    /** Email address for purchase dispute notifications. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString NotificationEmail;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonGetFacebookInstantGamesRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonGetFacebookInstantGamesResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Facebook App ID obtained after setting up your app in Facebook Instant Games. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString AppID;
    /** Addon status. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool Created = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonGetGoogleRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonGetGoogleResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * Google App Package ID obtained after setting up your app in the Google Play developer portal. Required if using Google
     * receipt validation.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString AppPackageID;
    /** Addon status. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool Created = false;
    /**
     * Google OAuth Client ID obtained through the Google Developer Console by creating a new set of "OAuth Client ID".
     * Required if using Google Authentication.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString OAuthClientID;
    /**
     * Authorized Redirect Uri obtained through the Google Developer Console. This currently defaults to
     * https://oauth.playfab.com/oauth2/google. If you are authenticating players via browser, please update this to your own
     * domain.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString OauthCustomRedirectUri;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonGetKongregateRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonGetKongregateResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Addon status. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool Created = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonGetNintendoRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonGetNintendoResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Nintendo Switch Application ID, without the "0x" prefix. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString ApplicationID;
    /** Addon status. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool Created = false;
    /** List of Nintendo Environments, currently supporting up to 4. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        TArray<UPlayFabJsonObject*> Environments;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonGetPSNRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonGetPSNResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Client ID obtained after setting up your game with Sony. This one is associated with the existing PS4 marketplace. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString ClientID;
    /** Addon status. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool Created = false;
    /**
     * Client ID obtained after setting up your game with Sony. This one is associated with the modern marketplace, which
     * includes PS5, cross-generation for PS4, and unified entitlements.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString NextGenClientID;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonGetSteamRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonGetSteamResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Application ID obtained after setting up your game in Valve's developer portal. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString ApplicationId;
    /** Addon status. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool Created = false;
    /** Enforce usage of AzurePlayFab identity in user authentication tickets. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool EnforceServiceSpecificTickets = false;
    /** Use Steam Payments sandbox endpoint for test transactions. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool UseSandbox = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonGetToxModRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonGetToxModResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Account ID obtained after creating your Twitch developer account. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString AccountId;
    /** Account Key obtained after creating your Twitch developer account. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString AccountKey;
    /** Addon status. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool Created = false;
    /** Whether the ToxMod Addon is enabled by the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool Enabled = false;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonGetTwitchRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The optional entity to perform this action on. Defaults to the currently logged in entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FAddonGetTwitchResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Client ID obtained after creating your Twitch developer account. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        FString ClientID;
    /** Addon status. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Addon | Addon Models")
        bool Created = false;
};

