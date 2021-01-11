//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "PlayFabCommon/Public/PlayFabAuthenticationContext.h"
#include "PlayFabRequestCommon.generated.h"

/**
* Base class for all PlayFab Requests
*/
USTRUCT(BlueprintType)
struct PLAYFAB_API FPlayFabRequestCommon
{
    GENERATED_BODY()

    // An optional authentication context (can used in multi-user scenarios)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Core")
        UPlayFabAuthenticationContext* AuthenticationContext = nullptr;
};
