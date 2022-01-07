//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "PlayFabResultHandler.h"
#include "PlayFab.h"
#include "Serialization/JsonSerializer.h"

using namespace PlayFab;

int PlayFabRequestHandler::pendingCalls = 0;

int PlayFabRequestHandler::GetPendingCalls()
{
    return PlayFabRequestHandler::pendingCalls;
}

TSharedRef<IHttpRequest, ESPMode::ThreadSafe> PlayFabRequestHandler::SendRequest(TSharedPtr<UPlayFabAPISettings> settings, const FString& urlPath, const FString& callBody, const FString& authKey, const FString& authValue)
{
    FString fullUrl = settings.IsValid() ? settings->GeneratePfUrl(urlPath) : PlayFabSettings::GeneratePfUrl(urlPath);
    return SendFullUrlRequest(fullUrl, callBody, authKey, authValue);
}

TSharedRef<IHttpRequest, ESPMode::ThreadSafe> PlayFabRequestHandler::SendFullUrlRequest(const FString& fullUrl, const FString& callBody, const FString& authKey, const FString& authValue)
{
    if (GetDefault<UPlayFabRuntimeSettings>()->TitleId.Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must define a titleID before making API Calls."));
    }
    PlayFabRequestHandler::pendingCalls += 1;

    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
    HttpRequest->SetVerb(TEXT("POST"));
    HttpRequest->SetURL(fullUrl);
    HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json; charset=utf-8"));
    HttpRequest->SetHeader(TEXT("X-PlayFabSDK"), PlayFabSettings::versionString);

    if (authKey != TEXT(""))
        HttpRequest->SetHeader(authKey, authValue);

    HttpRequest->SetContentAsString(callBody);
    return HttpRequest;
}

bool PlayFabRequestHandler::DecodeRequest(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, PlayFab::FPlayFabCppBaseModel& OutResult, PlayFab::FPlayFabCppError& OutError)
{
    PlayFabRequestHandler::pendingCalls -= 1;

    FString ResponseStr, ErrorStr;
    if (bSucceeded && HttpResponse.IsValid())
    {
        if (EHttpResponseCodes::IsOk(HttpResponse->GetResponseCode()))
        {
            // Create the Json parser
            ResponseStr = HttpResponse->GetContentAsString();
            TSharedPtr<FJsonObject> JsonObject;
            TSharedRef<TJsonReader<> > JsonReader = TJsonReaderFactory<>::Create(ResponseStr);

            if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
            {
                if (PlayFabRequestHandler::DecodeError(JsonObject, OutError))
                {
                    return false;
                }

                const TSharedPtr<FJsonObject>* DataJsonObject;
                if (JsonObject->TryGetObjectField(TEXT("data"), DataJsonObject))
                {
                    return OutResult.readFromValue(*DataJsonObject);
                }
            }
        }
        else
        {
            // Create the Json parser
            ResponseStr = HttpResponse->GetContentAsString();
            TSharedPtr<FJsonObject> JsonObject;
            TSharedRef<TJsonReader<> > JsonReader = TJsonReaderFactory<>::Create(ResponseStr);

            if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
            {
                if (PlayFabRequestHandler::DecodeError(JsonObject, OutError))
                {
                    return false;
                }
            }
        }
    }

    // If we get here, we failed to connect meaningfully to the server - Assume a timeout
    OutError.HttpCode = 408;
    OutError.ErrorCode = PlayFabErrorConnectionTimeout;
    // For text returns, use the non-json response if possible, else default to no response
    OutError.ErrorName = OutError.ErrorMessage = OutError.HttpStatus = TEXT("Request Timeout or null response");

    return false;
}

bool PlayFabRequestHandler::DecodeError(TSharedPtr<FJsonObject> JsonObject, PlayFab::FPlayFabCppError& OutError)
{
    // check if returned json indicates an error
    if (JsonObject->HasField(TEXT("errorCode")))
    {
        // deserialize the FPlayFabCppError object 
        JsonObject->TryGetNumberField(TEXT("errorCode"), OutError.ErrorCode);
        JsonObject->TryGetNumberField(TEXT("code"), OutError.HttpCode);
        JsonObject->TryGetStringField(TEXT("status"), OutError.HttpStatus);
        JsonObject->TryGetStringField(TEXT("error"), OutError.ErrorName);
        JsonObject->TryGetStringField(TEXT("errorMessage"), OutError.ErrorMessage);

        const TSharedPtr<FJsonObject>* obj;
        if (JsonObject->TryGetObjectField(TEXT("errorDetails"), obj))
        {
            auto vals = (*obj)->Values;
            for (auto val : vals)
            {
                if (val.Value->AsArray().Num() > 0)
                {
                    for(const auto& item : val.Value->AsArray())
                    {
                        OutError.ErrorDetails.Add(val.Key, item->AsString());
                    }
                }
                else
                {
                    OutError.ErrorDetails.Add(val.Key, val.Value->AsString());
                }
            }
        }

        // TODO: handle global error delegate here

        // We encountered no errors parsing the error
        return true;
    }

    return false;
}
