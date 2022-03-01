//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "CoreMinimal.h"
#include "PlayFabError.h"

namespace PlayFab
{
    class PlayFabSettings
    {
    public:
        static FString sdkVersion;
        static FString buildIdentifier;
        static FString versionString;
        static FString connectionString;

        static FString GetClientSessionTicket();
        static FString GetEntityToken();
        static FString GetLocalApiServer();
        static FString GetConnectionString();

        static void SetClientSessionTicket(const FString& clientSessionTicket);
        static void SetEntityToken(const FString& entityToken);
        static void SetConnectionString(const FString& connectionStr);

        static FString GeneratePfUrl(const FString& urlPath);
    };
}
