//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "CoreMinimal.h"
#include "PlayFabAPISettings.h"
#include "PlayFabCppBaseModel.h"
#include "PlayFabError.h"
#include "PlayFabSettings.h"
#include "Http.h"

namespace PlayFab
{
    class PlayFabRequestHandler
    {
    private:
        static int pendingCalls;
    public:
        static int GetPendingCalls();
        static TSharedRef<IHttpRequest, ESPMode::ThreadSafe> SendRequest(TSharedPtr<UPlayFabAPISettings> settings, const FString& urlPath, const FString& callBody, const FString& authKey, const FString& authValue);
        static TSharedRef<IHttpRequest, ESPMode::ThreadSafe> SendFullUrlRequest(const FString& fullUrl, const FString& callBody, const FString& authKey, const FString& authValue);
        static bool DecodeRequest(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, PlayFab::FPlayFabCppBaseModel& OutResult, PlayFab::FPlayFabCppError& OutError);
        static bool DecodeError(TSharedPtr<FJsonObject> JsonObject, PlayFab::FPlayFabCppError& OutError);
    };
};
