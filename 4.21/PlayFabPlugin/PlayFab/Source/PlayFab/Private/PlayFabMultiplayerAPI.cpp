//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
//
// API: Multiplayer
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabMultiplayerAPI.h"
#include "PlayFabMultiplayerModels.h"
#include "PlayFabMultiplayerModelDecoder.h"
#include "PlayFabPrivate.h"
#include "PlayFabEnums.h"
#include "PlayFabCommon/Public/PlayFabAuthenticationContext.h"
#include "PlayFabCommon/Public/PlayFabCommonUtils.h"

UPlayFabMultiplayerAPI::UPlayFabMultiplayerAPI(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , CallAuthenticationContext(nullptr)
{
}

void UPlayFabMultiplayerAPI::SetCallAuthenticationContext(UPlayFabAuthenticationContext* InAuthenticationContext)
{
    CallAuthenticationContext = InAuthenticationContext;
}

void UPlayFabMultiplayerAPI::SetRequestObject(UPlayFabJsonObject* JsonObject)
{
    RequestJsonObj = JsonObject;
}

UPlayFabJsonObject* UPlayFabMultiplayerAPI::GetResponseObject()
{
    return ResponseJsonObj;
}

FString UPlayFabMultiplayerAPI::PercentEncode(const FString& Text)
{
    FString OutText = Text;

    OutText = OutText.Replace(TEXT("!"), TEXT("%21"));
    OutText = OutText.Replace(TEXT("\""), TEXT("%22"));
    OutText = OutText.Replace(TEXT("#"), TEXT("%23"));
    OutText = OutText.Replace(TEXT("$"), TEXT("%24"));
    //OutText = OutText.Replace(TEXT("&"), TEXT("%26"));
    OutText = OutText.Replace(TEXT("'"), TEXT("%27"));
    OutText = OutText.Replace(TEXT("("), TEXT("%28"));
    OutText = OutText.Replace(TEXT(")"), TEXT("%29"));
    OutText = OutText.Replace(TEXT("*"), TEXT("%2A"));
    OutText = OutText.Replace(TEXT("+"), TEXT("%2B"));
    OutText = OutText.Replace(TEXT(","), TEXT("%2C"));
    //OutText = OutText.Replace(TEXT("/"), TEXT("%2F"));
    OutText = OutText.Replace(TEXT(":"), TEXT("%3A"));
    OutText = OutText.Replace(TEXT(";"), TEXT("%3B"));
    OutText = OutText.Replace(TEXT("="), TEXT("%3D"));
    //OutText = OutText.Replace(TEXT("?"), TEXT("%3F"));
    OutText = OutText.Replace(TEXT("@"), TEXT("%40"));
    OutText = OutText.Replace(TEXT("["), TEXT("%5B"));
    OutText = OutText.Replace(TEXT("]"), TEXT("%5D"));
    OutText = OutText.Replace(TEXT("{"), TEXT("%7B"));
    OutText = OutText.Replace(TEXT("}"), TEXT("%7D"));

    return OutText;
}

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Multiplayer API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Matchmaking
//////////////////////////////////////////////////////
/** Cancel all active tickets the player is a member of in a given queue. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::CancelAllMatchmakingTicketsForPlayer(FMultiplayerCancelAllMatchmakingTicketsForPlayerRequest request,
    FDelegateOnSuccessCancelAllMatchmakingTicketsForPlayer onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCancelAllMatchmakingTicketsForPlayer = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperCancelAllMatchmakingTicketsForPlayer);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Match/CancelAllMatchmakingTicketsForPlayer";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.QueueName.IsEmpty() || request.QueueName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("QueueName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("QueueName"), request.QueueName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperCancelAllMatchmakingTicketsForPlayer(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCancelAllMatchmakingTicketsForPlayer.IsBound())
    {
        FMultiplayerCancelAllMatchmakingTicketsForPlayerResult ResultStruct = UPlayFabMultiplayerModelDecoder::decodeCancelAllMatchmakingTicketsForPlayerResultResponse(response.responseData);
        OnSuccessCancelAllMatchmakingTicketsForPlayer.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Cancel a matchmaking ticket. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::CancelMatchmakingTicket(FMultiplayerCancelMatchmakingTicketRequest request,
    FDelegateOnSuccessCancelMatchmakingTicket onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCancelMatchmakingTicket = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperCancelMatchmakingTicket);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Match/CancelMatchmakingTicket";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.QueueName.IsEmpty() || request.QueueName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("QueueName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("QueueName"), request.QueueName);
    }
    if (request.TicketId.IsEmpty() || request.TicketId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("TicketId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("TicketId"), request.TicketId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperCancelMatchmakingTicket(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCancelMatchmakingTicket.IsBound())
    {
        FMultiplayerCancelMatchmakingTicketResult ResultStruct = UPlayFabMultiplayerModelDecoder::decodeCancelMatchmakingTicketResultResponse(response.responseData);
        OnSuccessCancelMatchmakingTicket.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Create a matchmaking ticket as a client. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::CreateMatchmakingTicket(FMultiplayerCreateMatchmakingTicketRequest request,
    FDelegateOnSuccessCreateMatchmakingTicket onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateMatchmakingTicket = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperCreateMatchmakingTicket);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Match/CreateMatchmakingTicket";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.Creator != nullptr) OutRestJsonObj->SetObjectField(TEXT("Creator"), request.Creator);
    OutRestJsonObj->SetNumberField(TEXT("GiveUpAfterSeconds"), request.GiveUpAfterSeconds);
    if (request.MembersToMatchWith.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("MembersToMatchWith"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("MembersToMatchWith"), request.MembersToMatchWith);
    }
    if (request.QueueName.IsEmpty() || request.QueueName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("QueueName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("QueueName"), request.QueueName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperCreateMatchmakingTicket(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateMatchmakingTicket.IsBound())
    {
        FMultiplayerCreateMatchmakingTicketResult ResultStruct = UPlayFabMultiplayerModelDecoder::decodeCreateMatchmakingTicketResultResponse(response.responseData);
        OnSuccessCreateMatchmakingTicket.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Create a matchmaking ticket as a server. The matchmaking service automatically starts matching the ticket against other matchmaking tickets. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::CreateServerMatchmakingTicket(FMultiplayerCreateServerMatchmakingTicketRequest request,
    FDelegateOnSuccessCreateServerMatchmakingTicket onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateServerMatchmakingTicket = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperCreateServerMatchmakingTicket);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Match/CreateServerMatchmakingTicket";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    OutRestJsonObj->SetNumberField(TEXT("GiveUpAfterSeconds"), request.GiveUpAfterSeconds);
    if (request.Members.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Members"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Members"), request.Members);
    }
    if (request.QueueName.IsEmpty() || request.QueueName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("QueueName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("QueueName"), request.QueueName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperCreateServerMatchmakingTicket(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateServerMatchmakingTicket.IsBound())
    {
        FMultiplayerCreateMatchmakingTicketResult ResultStruct = UPlayFabMultiplayerModelDecoder::decodeCreateMatchmakingTicketResultResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessCreateServerMatchmakingTicket.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Get a match. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::GetMatch(FMultiplayerGetMatchRequest request,
    FDelegateOnSuccessGetMatch onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetMatch = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperGetMatch);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Match/GetMatch";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    OutRestJsonObj->SetBoolField(TEXT("EscapeObject"), request.EscapeObject);
    if (request.MatchId.IsEmpty() || request.MatchId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("MatchId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("MatchId"), request.MatchId);
    }
    if (request.QueueName.IsEmpty() || request.QueueName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("QueueName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("QueueName"), request.QueueName);
    }
    OutRestJsonObj->SetBoolField(TEXT("ReturnMemberAttributes"), request.ReturnMemberAttributes);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperGetMatch(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetMatch.IsBound())
    {
        FMultiplayerGetMatchResult ResultStruct = UPlayFabMultiplayerModelDecoder::decodeGetMatchResultResponse(response.responseData);
        OnSuccessGetMatch.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Get a matchmaking ticket by ticket Id. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::GetMatchmakingTicket(FMultiplayerGetMatchmakingTicketRequest request,
    FDelegateOnSuccessGetMatchmakingTicket onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetMatchmakingTicket = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperGetMatchmakingTicket);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Match/GetMatchmakingTicket";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    OutRestJsonObj->SetBoolField(TEXT("EscapeObject"), request.EscapeObject);
    if (request.QueueName.IsEmpty() || request.QueueName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("QueueName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("QueueName"), request.QueueName);
    }
    if (request.TicketId.IsEmpty() || request.TicketId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("TicketId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("TicketId"), request.TicketId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperGetMatchmakingTicket(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetMatchmakingTicket.IsBound())
    {
        FMultiplayerGetMatchmakingTicketResult ResultStruct = UPlayFabMultiplayerModelDecoder::decodeGetMatchmakingTicketResultResponse(response.responseData);
        OnSuccessGetMatchmakingTicket.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Get the statistics for a queue. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::GetQueueStatistics(FMultiplayerGetQueueStatisticsRequest request,
    FDelegateOnSuccessGetQueueStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetQueueStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperGetQueueStatistics);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Match/GetQueueStatistics";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.QueueName.IsEmpty() || request.QueueName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("QueueName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("QueueName"), request.QueueName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperGetQueueStatistics(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetQueueStatistics.IsBound())
    {
        FMultiplayerGetQueueStatisticsResult ResultStruct = UPlayFabMultiplayerModelDecoder::decodeGetQueueStatisticsResultResponse(response.responseData);
        OnSuccessGetQueueStatistics.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Join a matchmaking ticket. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::JoinMatchmakingTicket(FMultiplayerJoinMatchmakingTicketRequest request,
    FDelegateOnSuccessJoinMatchmakingTicket onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessJoinMatchmakingTicket = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperJoinMatchmakingTicket);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Match/JoinMatchmakingTicket";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.Member != nullptr) OutRestJsonObj->SetObjectField(TEXT("Member"), request.Member);
    if (request.QueueName.IsEmpty() || request.QueueName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("QueueName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("QueueName"), request.QueueName);
    }
    if (request.TicketId.IsEmpty() || request.TicketId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("TicketId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("TicketId"), request.TicketId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperJoinMatchmakingTicket(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessJoinMatchmakingTicket.IsBound())
    {
        FMultiplayerJoinMatchmakingTicketResult ResultStruct = UPlayFabMultiplayerModelDecoder::decodeJoinMatchmakingTicketResultResponse(response.responseData);
        OnSuccessJoinMatchmakingTicket.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** List all matchmaking ticket Ids the user is a member of. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::ListMatchmakingTicketsForPlayer(FMultiplayerListMatchmakingTicketsForPlayerRequest request,
    FDelegateOnSuccessListMatchmakingTicketsForPlayer onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListMatchmakingTicketsForPlayer = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperListMatchmakingTicketsForPlayer);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/Match/ListMatchmakingTicketsForPlayer";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.Entity != nullptr) OutRestJsonObj->SetObjectField(TEXT("Entity"), request.Entity);
    if (request.QueueName.IsEmpty() || request.QueueName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("QueueName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("QueueName"), request.QueueName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperListMatchmakingTicketsForPlayer(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListMatchmakingTicketsForPlayer.IsBound())
    {
        FMultiplayerListMatchmakingTicketsForPlayerResult ResultStruct = UPlayFabMultiplayerModelDecoder::decodeListMatchmakingTicketsForPlayerResultResponse(response.responseData);
        OnSuccessListMatchmakingTicketsForPlayer.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}


///////////////////////////////////////////////////////
// Matchmaking Admin
//////////////////////////////////////////////////////

///////////////////////////////////////////////////////
// MultiplayerServer
//////////////////////////////////////////////////////
/** Creates a multiplayer server build with a custom container. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::CreateBuildWithCustomContainer(FMultiplayerCreateBuildWithCustomContainerRequest request,
    FDelegateOnSuccessCreateBuildWithCustomContainer onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateBuildWithCustomContainer = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperCreateBuildWithCustomContainer);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/CreateBuildWithCustomContainer";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.BuildName.IsEmpty() || request.BuildName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildName"), request.BuildName);
    }
    FString temp_ContainerFlavor;
    if (GetEnumValueToString<EContainerFlavor>(TEXT("EContainerFlavor"), request.ContainerFlavor, temp_ContainerFlavor))
        OutRestJsonObj->SetStringField(TEXT("ContainerFlavor"), temp_ContainerFlavor);
    if (request.ContainerImageReference != nullptr) OutRestJsonObj->SetObjectField(TEXT("ContainerImageReference"), request.ContainerImageReference);
    if (request.ContainerRunCommand.IsEmpty() || request.ContainerRunCommand == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ContainerRunCommand"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ContainerRunCommand"), request.ContainerRunCommand);
    }
    if (request.GameAssetReferences.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("GameAssetReferences"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("GameAssetReferences"), request.GameAssetReferences);
    }
    if (request.GameCertificateReferences.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("GameCertificateReferences"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("GameCertificateReferences"), request.GameCertificateReferences);
    }
    if (request.Metadata != nullptr) OutRestJsonObj->SetObjectField(TEXT("Metadata"), request.Metadata);
    OutRestJsonObj->SetNumberField(TEXT("MultiplayerServerCountPerVm"), request.MultiplayerServerCountPerVm);
    if (request.Ports.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Ports"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Ports"), request.Ports);
    }
    if (request.RegionConfigurations.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("RegionConfigurations"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("RegionConfigurations"), request.RegionConfigurations);
    }
    FString temp_VmSize;
    if (GetEnumValueToString<EAzureVmSize>(TEXT("EAzureVmSize"), request.VmSize, temp_VmSize))
        OutRestJsonObj->SetStringField(TEXT("VmSize"), temp_VmSize);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperCreateBuildWithCustomContainer(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateBuildWithCustomContainer.IsBound())
    {
        FMultiplayerCreateBuildWithCustomContainerResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeCreateBuildWithCustomContainerResponseResponse(response.responseData);
        OnSuccessCreateBuildWithCustomContainer.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Creates a multiplayer server build with a managed container. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::CreateBuildWithManagedContainer(FMultiplayerCreateBuildWithManagedContainerRequest request,
    FDelegateOnSuccessCreateBuildWithManagedContainer onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateBuildWithManagedContainer = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperCreateBuildWithManagedContainer);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/CreateBuildWithManagedContainer";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.BuildName.IsEmpty() || request.BuildName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildName"), request.BuildName);
    }
    FString temp_ContainerFlavor;
    if (GetEnumValueToString<EContainerFlavor>(TEXT("EContainerFlavor"), request.ContainerFlavor, temp_ContainerFlavor))
        OutRestJsonObj->SetStringField(TEXT("ContainerFlavor"), temp_ContainerFlavor);
    if (request.GameAssetReferences.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("GameAssetReferences"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("GameAssetReferences"), request.GameAssetReferences);
    }
    if (request.GameCertificateReferences.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("GameCertificateReferences"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("GameCertificateReferences"), request.GameCertificateReferences);
    }
    if (request.InstrumentationConfiguration != nullptr) OutRestJsonObj->SetObjectField(TEXT("InstrumentationConfiguration"), request.InstrumentationConfiguration);
    if (request.Metadata != nullptr) OutRestJsonObj->SetObjectField(TEXT("Metadata"), request.Metadata);
    OutRestJsonObj->SetNumberField(TEXT("MultiplayerServerCountPerVm"), request.MultiplayerServerCountPerVm);
    if (request.Ports.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Ports"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Ports"), request.Ports);
    }
    if (request.RegionConfigurations.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("RegionConfigurations"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("RegionConfigurations"), request.RegionConfigurations);
    }
    if (request.StartMultiplayerServerCommand.IsEmpty() || request.StartMultiplayerServerCommand == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StartMultiplayerServerCommand"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StartMultiplayerServerCommand"), request.StartMultiplayerServerCommand);
    }
    FString temp_VmSize;
    if (GetEnumValueToString<EAzureVmSize>(TEXT("EAzureVmSize"), request.VmSize, temp_VmSize))
        OutRestJsonObj->SetStringField(TEXT("VmSize"), temp_VmSize);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperCreateBuildWithManagedContainer(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateBuildWithManagedContainer.IsBound())
    {
        FMultiplayerCreateBuildWithManagedContainerResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeCreateBuildWithManagedContainerResponseResponse(response.responseData);
        OnSuccessCreateBuildWithManagedContainer.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Creates a remote user to log on to a VM for a multiplayer server build. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::CreateRemoteUser(FMultiplayerCreateRemoteUserRequest request,
    FDelegateOnSuccessCreateRemoteUser onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateRemoteUser = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperCreateRemoteUser);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/CreateRemoteUser";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.BuildId.IsEmpty() || request.BuildId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildId"), request.BuildId);
    }
    if (request.ExpirationTime.IsEmpty() || request.ExpirationTime == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ExpirationTime"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ExpirationTime"), request.ExpirationTime);
    }
    if (request.Region.IsEmpty() || request.Region == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Region"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Region"), request.Region);
    }
    if (request.Username.IsEmpty() || request.Username == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Username"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Username"), request.Username);
    }
    if (request.VmId.IsEmpty() || request.VmId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("VmId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("VmId"), request.VmId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperCreateRemoteUser(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateRemoteUser.IsBound())
    {
        FMultiplayerCreateRemoteUserResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeCreateRemoteUserResponseResponse(response.responseData);
        OnSuccessCreateRemoteUser.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes a multiplayer server game asset for a title. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::DeleteAsset(FMultiplayerDeleteAssetRequest request,
    FDelegateOnSuccessDeleteAsset onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteAsset = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperDeleteAsset);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/DeleteAsset";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.FileName.IsEmpty() || request.FileName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FileName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("FileName"), request.FileName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperDeleteAsset(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteAsset.IsBound())
    {
        FMultiplayerEmptyResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeEmptyResponseResponse(response.responseData);
        OnSuccessDeleteAsset.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes a multiplayer server build. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::DeleteBuild(FMultiplayerDeleteBuildRequest request,
    FDelegateOnSuccessDeleteBuild onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteBuild = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperDeleteBuild);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/DeleteBuild";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.BuildId.IsEmpty() || request.BuildId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildId"), request.BuildId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperDeleteBuild(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteBuild.IsBound())
    {
        FMultiplayerEmptyResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessDeleteBuild.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes a multiplayer server game certificate. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::DeleteCertificate(FMultiplayerDeleteCertificateRequest request,
    FDelegateOnSuccessDeleteCertificate onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteCertificate = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperDeleteCertificate);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/DeleteCertificate";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.Name.IsEmpty() || request.Name == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Name"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Name"), request.Name);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperDeleteCertificate(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteCertificate.IsBound())
    {
        FMultiplayerEmptyResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessDeleteCertificate.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes a remote user to log on to a VM for a multiplayer server build. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::DeleteRemoteUser(FMultiplayerDeleteRemoteUserRequest request,
    FDelegateOnSuccessDeleteRemoteUser onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteRemoteUser = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperDeleteRemoteUser);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/DeleteRemoteUser";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.BuildId.IsEmpty() || request.BuildId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildId"), request.BuildId);
    }
    if (request.Region.IsEmpty() || request.Region == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Region"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Region"), request.Region);
    }
    if (request.Username.IsEmpty() || request.Username == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Username"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Username"), request.Username);
    }
    if (request.VmId.IsEmpty() || request.VmId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("VmId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("VmId"), request.VmId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperDeleteRemoteUser(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteRemoteUser.IsBound())
    {
        FMultiplayerEmptyResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessDeleteRemoteUser.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Enables the multiplayer server feature for a title. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::EnableMultiplayerServersForTitle(FMultiplayerEnableMultiplayerServersForTitleRequest request,
    FDelegateOnSuccessEnableMultiplayerServersForTitle onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessEnableMultiplayerServersForTitle = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperEnableMultiplayerServersForTitle);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/EnableMultiplayerServersForTitle";
    manager->useEntityToken = true;


    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperEnableMultiplayerServersForTitle(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessEnableMultiplayerServersForTitle.IsBound())
    {
        FMultiplayerEnableMultiplayerServersForTitleResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeEnableMultiplayerServersForTitleResponseResponse(response.responseData);
        OnSuccessEnableMultiplayerServersForTitle.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets the URL to upload assets to. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::GetAssetUploadUrl(FMultiplayerGetAssetUploadUrlRequest request,
    FDelegateOnSuccessGetAssetUploadUrl onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetAssetUploadUrl = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperGetAssetUploadUrl);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/GetAssetUploadUrl";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.FileName.IsEmpty() || request.FileName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FileName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("FileName"), request.FileName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperGetAssetUploadUrl(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetAssetUploadUrl.IsBound())
    {
        FMultiplayerGetAssetUploadUrlResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeGetAssetUploadUrlResponseResponse(response.responseData);
        OnSuccessGetAssetUploadUrl.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets a multiplayer server build. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::GetBuild(FMultiplayerGetBuildRequest request,
    FDelegateOnSuccessGetBuild onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetBuild = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperGetBuild);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/GetBuild";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.BuildId.IsEmpty() || request.BuildId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildId"), request.BuildId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperGetBuild(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetBuild.IsBound())
    {
        FMultiplayerGetBuildResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeGetBuildResponseResponse(response.responseData);
        OnSuccessGetBuild.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets the credentials to the container registry. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::GetContainerRegistryCredentials(FMultiplayerGetContainerRegistryCredentialsRequest request,
    FDelegateOnSuccessGetContainerRegistryCredentials onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetContainerRegistryCredentials = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperGetContainerRegistryCredentials);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/GetContainerRegistryCredentials";
    manager->useEntityToken = true;


    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperGetContainerRegistryCredentials(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetContainerRegistryCredentials.IsBound())
    {
        FMultiplayerGetContainerRegistryCredentialsResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeGetContainerRegistryCredentialsResponseResponse(response.responseData);
        OnSuccessGetContainerRegistryCredentials.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets multiplayer server session details for a build. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::GetMultiplayerServerDetails(FMultiplayerGetMultiplayerServerDetailsRequest request,
    FDelegateOnSuccessGetMultiplayerServerDetails onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetMultiplayerServerDetails = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperGetMultiplayerServerDetails);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/GetMultiplayerServerDetails";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.BuildId.IsEmpty() || request.BuildId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildId"), request.BuildId);
    }
    if (request.Region.IsEmpty() || request.Region == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Region"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Region"), request.Region);
    }
    if (request.SessionId.IsEmpty() || request.SessionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SessionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SessionId"), request.SessionId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperGetMultiplayerServerDetails(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetMultiplayerServerDetails.IsBound())
    {
        FMultiplayerGetMultiplayerServerDetailsResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeGetMultiplayerServerDetailsResponseResponse(response.responseData);
        OnSuccessGetMultiplayerServerDetails.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets a remote login endpoint to a VM that is hosting a multiplayer server build. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::GetRemoteLoginEndpoint(FMultiplayerGetRemoteLoginEndpointRequest request,
    FDelegateOnSuccessGetRemoteLoginEndpoint onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetRemoteLoginEndpoint = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperGetRemoteLoginEndpoint);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/GetRemoteLoginEndpoint";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.BuildId.IsEmpty() || request.BuildId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildId"), request.BuildId);
    }
    if (request.Region.IsEmpty() || request.Region == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Region"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Region"), request.Region);
    }
    if (request.VmId.IsEmpty() || request.VmId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("VmId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("VmId"), request.VmId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperGetRemoteLoginEndpoint(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetRemoteLoginEndpoint.IsBound())
    {
        FMultiplayerGetRemoteLoginEndpointResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeGetRemoteLoginEndpointResponseResponse(response.responseData);
        OnSuccessGetRemoteLoginEndpoint.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets the status of whether a title is enabled for the multiplayer server feature. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::GetTitleEnabledForMultiplayerServersStatus(FMultiplayerGetTitleEnabledForMultiplayerServersStatusRequest request,
    FDelegateOnSuccessGetTitleEnabledForMultiplayerServersStatus onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetTitleEnabledForMultiplayerServersStatus = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperGetTitleEnabledForMultiplayerServersStatus);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/GetTitleEnabledForMultiplayerServersStatus";
    manager->useEntityToken = true;


    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperGetTitleEnabledForMultiplayerServersStatus(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetTitleEnabledForMultiplayerServersStatus.IsBound())
    {
        FMultiplayerGetTitleEnabledForMultiplayerServersStatusResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeGetTitleEnabledForMultiplayerServersStatusResponseResponse(response.responseData);
        OnSuccessGetTitleEnabledForMultiplayerServersStatus.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets the quotas for a title in relation to multiplayer servers. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::GetTitleMultiplayerServersQuotas(FMultiplayerGetTitleMultiplayerServersQuotasRequest request,
    FDelegateOnSuccessGetTitleMultiplayerServersQuotas onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetTitleMultiplayerServersQuotas = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperGetTitleMultiplayerServersQuotas);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/GetTitleMultiplayerServersQuotas";
    manager->useEntityToken = true;


    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperGetTitleMultiplayerServersQuotas(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetTitleMultiplayerServersQuotas.IsBound())
    {
        FMultiplayerGetTitleMultiplayerServersQuotasResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeGetTitleMultiplayerServersQuotasResponseResponse(response.responseData);
        OnSuccessGetTitleMultiplayerServersQuotas.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Lists archived multiplayer server sessions for a build. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::ListArchivedMultiplayerServers(FMultiplayerListMultiplayerServersRequest request,
    FDelegateOnSuccessListArchivedMultiplayerServers onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListArchivedMultiplayerServers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperListArchivedMultiplayerServers);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/ListArchivedMultiplayerServers";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.BuildId.IsEmpty() || request.BuildId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildId"), request.BuildId);
    }
    OutRestJsonObj->SetNumberField(TEXT("PageSize"), request.PageSize);
    if (request.Region.IsEmpty() || request.Region == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Region"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Region"), request.Region);
    }
    if (request.SkipToken.IsEmpty() || request.SkipToken == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SkipToken"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SkipToken"), request.SkipToken);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperListArchivedMultiplayerServers(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListArchivedMultiplayerServers.IsBound())
    {
        FMultiplayerListMultiplayerServersResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeListMultiplayerServersResponseResponse(response.responseData);
        OnSuccessListArchivedMultiplayerServers.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Lists multiplayer server game assets for a title. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::ListAssetSummaries(FMultiplayerListAssetSummariesRequest request,
    FDelegateOnSuccessListAssetSummaries onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListAssetSummaries = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperListAssetSummaries);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/ListAssetSummaries";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    OutRestJsonObj->SetNumberField(TEXT("PageSize"), request.PageSize);
    if (request.SkipToken.IsEmpty() || request.SkipToken == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SkipToken"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SkipToken"), request.SkipToken);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperListAssetSummaries(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListAssetSummaries.IsBound())
    {
        FMultiplayerListAssetSummariesResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeListAssetSummariesResponseResponse(response.responseData);
        OnSuccessListAssetSummaries.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Lists summarized details of all multiplayer server builds for a title. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::ListBuildSummaries(FMultiplayerListBuildSummariesRequest request,
    FDelegateOnSuccessListBuildSummaries onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListBuildSummaries = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperListBuildSummaries);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/ListBuildSummaries";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    OutRestJsonObj->SetNumberField(TEXT("PageSize"), request.PageSize);
    if (request.SkipToken.IsEmpty() || request.SkipToken == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SkipToken"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SkipToken"), request.SkipToken);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperListBuildSummaries(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListBuildSummaries.IsBound())
    {
        FMultiplayerListBuildSummariesResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeListBuildSummariesResponseResponse(response.responseData);
        OnSuccessListBuildSummaries.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Lists multiplayer server game certificates for a title. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::ListCertificateSummaries(FMultiplayerListCertificateSummariesRequest request,
    FDelegateOnSuccessListCertificateSummaries onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListCertificateSummaries = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperListCertificateSummaries);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/ListCertificateSummaries";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    OutRestJsonObj->SetNumberField(TEXT("PageSize"), request.PageSize);
    if (request.SkipToken.IsEmpty() || request.SkipToken == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SkipToken"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SkipToken"), request.SkipToken);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperListCertificateSummaries(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListCertificateSummaries.IsBound())
    {
        FMultiplayerListCertificateSummariesResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeListCertificateSummariesResponseResponse(response.responseData);
        OnSuccessListCertificateSummaries.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Lists custom container images for a title. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::ListContainerImages(FMultiplayerListContainerImagesRequest request,
    FDelegateOnSuccessListContainerImages onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListContainerImages = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperListContainerImages);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/ListContainerImages";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    OutRestJsonObj->SetNumberField(TEXT("PageSize"), request.PageSize);
    if (request.SkipToken.IsEmpty() || request.SkipToken == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SkipToken"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SkipToken"), request.SkipToken);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperListContainerImages(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListContainerImages.IsBound())
    {
        FMultiplayerListContainerImagesResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeListContainerImagesResponseResponse(response.responseData);
        OnSuccessListContainerImages.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Lists the tags for a custom container image. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::ListContainerImageTags(FMultiplayerListContainerImageTagsRequest request,
    FDelegateOnSuccessListContainerImageTags onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListContainerImageTags = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperListContainerImageTags);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/ListContainerImageTags";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.ImageName.IsEmpty() || request.ImageName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ImageName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ImageName"), request.ImageName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperListContainerImageTags(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListContainerImageTags.IsBound())
    {
        FMultiplayerListContainerImageTagsResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeListContainerImageTagsResponseResponse(response.responseData);
        OnSuccessListContainerImageTags.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Lists multiplayer server sessions for a build. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::ListMultiplayerServers(FMultiplayerListMultiplayerServersRequest request,
    FDelegateOnSuccessListMultiplayerServers onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListMultiplayerServers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperListMultiplayerServers);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/ListMultiplayerServers";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.BuildId.IsEmpty() || request.BuildId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildId"), request.BuildId);
    }
    OutRestJsonObj->SetNumberField(TEXT("PageSize"), request.PageSize);
    if (request.Region.IsEmpty() || request.Region == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Region"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Region"), request.Region);
    }
    if (request.SkipToken.IsEmpty() || request.SkipToken == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SkipToken"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SkipToken"), request.SkipToken);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperListMultiplayerServers(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListMultiplayerServers.IsBound())
    {
        FMultiplayerListMultiplayerServersResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeListMultiplayerServersResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessListMultiplayerServers.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Lists quality of service servers for party. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::ListPartyQosServers(FMultiplayerListPartyQosServersRequest request,
    FDelegateOnSuccessListPartyQosServers onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListPartyQosServers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperListPartyQosServers);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/ListPartyQosServers";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.Version.IsEmpty() || request.Version == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Version"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Version"), request.Version);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperListPartyQosServers(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListPartyQosServers.IsBound())
    {
        FMultiplayerListPartyQosServersResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeListPartyQosServersResponseResponse(response.responseData);
        OnSuccessListPartyQosServers.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Lists quality of service servers. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::ListQosServers(FMultiplayerListQosServersRequest request,
    FDelegateOnSuccessListQosServers onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListQosServers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperListQosServers);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/ListQosServers";


    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperListQosServers(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListQosServers.IsBound())
    {
        FMultiplayerListQosServersResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeListQosServersResponseResponse(response.responseData);
        OnSuccessListQosServers.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Lists quality of service servers. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::ListQosServersForTitle(FMultiplayerListQosServersForTitleRequest request,
    FDelegateOnSuccessListQosServersForTitle onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListQosServersForTitle = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperListQosServersForTitle);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/ListQosServersForTitle";
    manager->useEntityToken = true;


    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperListQosServersForTitle(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListQosServersForTitle.IsBound())
    {
        FMultiplayerListQosServersForTitleResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeListQosServersForTitleResponseResponse(response.responseData);
        OnSuccessListQosServersForTitle.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Lists virtual machines for a title. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::ListVirtualMachineSummaries(FMultiplayerListVirtualMachineSummariesRequest request,
    FDelegateOnSuccessListVirtualMachineSummaries onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListVirtualMachineSummaries = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperListVirtualMachineSummaries);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/ListVirtualMachineSummaries";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.BuildId.IsEmpty() || request.BuildId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildId"), request.BuildId);
    }
    OutRestJsonObj->SetNumberField(TEXT("PageSize"), request.PageSize);
    if (request.Region.IsEmpty() || request.Region == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Region"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Region"), request.Region);
    }
    if (request.SkipToken.IsEmpty() || request.SkipToken == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SkipToken"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SkipToken"), request.SkipToken);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperListVirtualMachineSummaries(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessListVirtualMachineSummaries.IsBound())
    {
        FMultiplayerListVirtualMachineSummariesResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeListVirtualMachineSummariesResponseResponse(response.responseData);
        OnSuccessListVirtualMachineSummaries.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Request a multiplayer server session. Accepts tokens for title and if game client accesss is enabled, allows game client to request a server with player entity token. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::RequestMultiplayerServer(FMultiplayerRequestMultiplayerServerRequest request,
    FDelegateOnSuccessRequestMultiplayerServer onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRequestMultiplayerServer = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperRequestMultiplayerServer);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/RequestMultiplayerServer";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.BuildId.IsEmpty() || request.BuildId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildId"), request.BuildId);
    }
    // Check to see if string is empty
    if (request.InitialPlayers.IsEmpty() || request.InitialPlayers == "") {
        OutRestJsonObj->SetFieldNull(TEXT("InitialPlayers"));
    } else {
        TArray<FString> InitialPlayersArray;
        FString(request.InitialPlayers).ParseIntoArray(InitialPlayersArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("InitialPlayers"), InitialPlayersArray);
    }
    // Check to see if string is empty
    if (request.PreferredRegions.IsEmpty() || request.PreferredRegions == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PreferredRegions"));
    } else {
        TArray<FString> PreferredRegionsArray;
        FString(request.PreferredRegions).ParseIntoArray(PreferredRegionsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("PreferredRegions"), PreferredRegionsArray);
    }
    if (request.SessionCookie.IsEmpty() || request.SessionCookie == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SessionCookie"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SessionCookie"), request.SessionCookie);
    }
    if (request.SessionId.IsEmpty() || request.SessionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SessionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SessionId"), request.SessionId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperRequestMultiplayerServer(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessRequestMultiplayerServer.IsBound())
    {
        FMultiplayerRequestMultiplayerServerResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeRequestMultiplayerServerResponseResponse(response.responseData);
        OnSuccessRequestMultiplayerServer.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Rolls over the credentials to the container registry. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::RolloverContainerRegistryCredentials(FMultiplayerRolloverContainerRegistryCredentialsRequest request,
    FDelegateOnSuccessRolloverContainerRegistryCredentials onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRolloverContainerRegistryCredentials = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperRolloverContainerRegistryCredentials);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/RolloverContainerRegistryCredentials";
    manager->useEntityToken = true;


    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperRolloverContainerRegistryCredentials(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessRolloverContainerRegistryCredentials.IsBound())
    {
        FMultiplayerRolloverContainerRegistryCredentialsResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeRolloverContainerRegistryCredentialsResponseResponse(response.responseData);
        OnSuccessRolloverContainerRegistryCredentials.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Shuts down a multiplayer server session. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::ShutdownMultiplayerServer(FMultiplayerShutdownMultiplayerServerRequest request,
    FDelegateOnSuccessShutdownMultiplayerServer onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessShutdownMultiplayerServer = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperShutdownMultiplayerServer);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/ShutdownMultiplayerServer";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.BuildId.IsEmpty() || request.BuildId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildId"), request.BuildId);
    }
    if (request.Region.IsEmpty() || request.Region == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Region"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Region"), request.Region);
    }
    if (request.SessionId.IsEmpty() || request.SessionId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SessionId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SessionId"), request.SessionId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperShutdownMultiplayerServer(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessShutdownMultiplayerServer.IsBound())
    {
        FMultiplayerEmptyResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessShutdownMultiplayerServer.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Updates a multiplayer server build's regions. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::UpdateBuildRegions(FMultiplayerUpdateBuildRegionsRequest request,
    FDelegateOnSuccessUpdateBuildRegions onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateBuildRegions = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperUpdateBuildRegions);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/UpdateBuildRegions";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.BuildId.IsEmpty() || request.BuildId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildId"), request.BuildId);
    }
    if (request.BuildRegions.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("BuildRegions"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("BuildRegions"), request.BuildRegions);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperUpdateBuildRegions(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdateBuildRegions.IsBound())
    {
        FMultiplayerEmptyResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessUpdateBuildRegions.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Uploads a multiplayer server game certificate. */
UPlayFabMultiplayerAPI* UPlayFabMultiplayerAPI::UploadCertificate(FMultiplayerUploadCertificateRequest request,
    FDelegateOnSuccessUploadCertificate onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabMultiplayerAPI* manager = NewObject<UPlayFabMultiplayerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUploadCertificate = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabMultiplayerAPI::HelperUploadCertificate);

    // Setup the request
    manager->SetCallAuthenticationContext(request.AuthenticationContext);
    manager->PlayFabRequestURL = "/MultiplayerServer/UploadCertificate";
    manager->useEntityToken = true;


    // Serialize all the request properties to json
    if (request.GameCertificate != nullptr) OutRestJsonObj->SetObjectField(TEXT("GameCertificate"), request.GameCertificate);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabMultiplayerRequestCompleted
void UPlayFabMultiplayerAPI::HelperUploadCertificate(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUploadCertificate.IsBound())
    {
        FMultiplayerEmptyResponse ResultStruct = UPlayFabMultiplayerModelDecoder::decodeEmptyResponseResponse(response.responseData);
        ResultStruct.Request = RequestJsonObj;
        OnSuccessUploadCertificate.Execute(ResultStruct, mCustomData);
    }
    this->RemoveFromRoot();
}



void UPlayFabMultiplayerAPI::OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    // Be sure that we have no data from previous response
    ResetResponseData();

    if (!IsValidLowLevel())
    {
        UE_LOG(LogPlayFab, Error, TEXT("The request object is invalid during OnProcessRequestComplete."));
        return;
    }
    if (!OnPlayFabResponse.IsBound())
    {
        UE_LOG(LogPlayFab, Error, TEXT("OnPlayFabResponse has come un-bound during OnProcessRequestComplete."));
        return;
    }

    FPlayFabBaseModel myResponse;

    // Check we have result to process further
    if (!bWasSuccessful)
    {
        UE_LOG(LogPlayFab, Error, TEXT("Request failed: %s"), *Request->GetURL());

        // Broadcast the result event
        myResponse.responseError.hasError = true;
        myResponse.responseError.ErrorCode = 503;
        myResponse.responseError.ErrorName = "Unable to contact server";
        myResponse.responseError.ErrorMessage = "Unable to contact server";

        OnPlayFabResponse.Broadcast(myResponse, mCustomData, false);

        return;
    }

    // Save response data as a string
    ResponseContent = Response->GetContentAsString();

    // Save response code as int32
    ResponseCode = Response->GetResponseCode();

    // Try to deserialize data to JSON
    TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(ResponseContent);
    FJsonSerializer::Deserialize(JsonReader, ResponseJsonObj->GetRootObject());

    // Decide whether the request was successful
    bIsValidJsonResponse = bWasSuccessful && ResponseJsonObj->GetRootObject().IsValid();

    // Log errors
    if (!bIsValidJsonResponse)
        UE_LOG(LogPlayFab, Warning, TEXT("JSON could not be decoded!"));

    // Log response state
    UE_LOG(LogPlayFab, Log, TEXT("Response : %s"), *ResponseContent);

    myResponse.responseError.decodeError(ResponseJsonObj);
    myResponse.responseData = ResponseJsonObj;
    IPlayFab* pfSettings = &(IPlayFab::Get());

    if (returnsEntityToken)
    {
        CallAuthenticationContext = NewObject<UPlayFabAuthenticationContext>();
        FString NewEntityToken = myResponse.responseData->GetObjectField("data")->GetStringField("EntityToken");
        pfSettings->setEntityToken(NewEntityToken);
        CallAuthenticationContext->SetEntityToken(MoveTemp(NewEntityToken));
    }

    // Broadcast the result event
    OnPlayFabResponse.Broadcast(myResponse, mCustomData, !myResponse.responseError.hasError);
    pfSettings->ModifyPendingCallCount(-1);
}

void UPlayFabMultiplayerAPI::Activate()
{
    IPlayFab* pfSettings = &(IPlayFab::Get());

    FString RequestUrl;
    RequestUrl = pfSettings->getUrl(PlayFabRequestURL);


    TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
    HttpRequest->SetURL(RequestUrl);
    HttpRequest->SetVerb(TEXT("POST"));

    // Headers
    if (useEntityToken)
        HttpRequest->SetHeader(TEXT("X-EntityToken"), CallAuthenticationContext != nullptr ? CallAuthenticationContext->GetEntityToken() : pfSettings->getEntityToken());
    else if (useSessionTicket)
        HttpRequest->SetHeader(TEXT("X-Authorization"), CallAuthenticationContext != nullptr ? CallAuthenticationContext->GetClientSessionTicket() : pfSettings->getSessionTicket());
    else if (useSecretKey)
        HttpRequest->SetHeader(TEXT("X-SecretKey"), CallAuthenticationContext != nullptr ? CallAuthenticationContext->GetDeveloperSecretKey() : pfSettings->getSecretApiKey());
    HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
    HttpRequest->SetHeader(TEXT("X-PlayFabSDK"), pfSettings->getVersionString());
    HttpRequest->SetHeader(TEXT("X-ReportErrorAsSuccess"), TEXT("true")); // FHttpResponsePtr doesn't provide sufficient information when an error code is returned
    for (TMap<FString, FString>::TConstIterator It(RequestHeaders); It; ++It)
        HttpRequest->SetHeader(It.Key(), It.Value());

    // Serialize data to json string
    FString OutputString;
    TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
    FJsonSerializer::Serialize(RequestJsonObj->GetRootObject().ToSharedRef(), Writer);

    // Set Json content
    HttpRequest->SetContentAsString(OutputString);

    UE_LOG(LogPlayFab, Log, TEXT("Request: %s"), *OutputString);

    // Bind event
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UPlayFabMultiplayerAPI::OnProcessRequestComplete);

    // Execute the request
    pfSettings->ModifyPendingCallCount(1);
    HttpRequest->ProcessRequest();
}

void UPlayFabMultiplayerAPI::ResetResponseData()
{
    if (ResponseJsonObj != nullptr)
        ResponseJsonObj->Reset();
    else
        ResponseJsonObj = NewObject<UPlayFabJsonObject>();
    bIsValidJsonResponse = false;
}
