//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "CoreMinimal.h"
#include "PlayFabBaseModel.h"
#include "PlayFabError.h"
#include "Http.h"

namespace PlayFab
{
    class PlayFabRequestHandler
    {
    private:
        static int pendingCalls;
    public:
        static int GetPendingCalls();
        static TSharedRef<IHttpRequest> SendRequest(const FString& url, const FString& callBody, const FString& authKey, const FString& authValue);
        static bool DecodeRequest(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, PlayFab::FPlayFabBaseModel& OutResult, PlayFab::FPlayFabError& OutError);
        static bool DecodeError(TSharedPtr<FJsonObject> JsonObject, PlayFab::FPlayFabError& OutError);
    };
};
