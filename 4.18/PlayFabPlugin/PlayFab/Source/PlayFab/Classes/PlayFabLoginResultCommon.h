//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "PlayFabResultCommon.h"
#include "PlayFabCommon/Public/PlayFabAuthenticationContext.h"
#include "PlayFabLoginResultCommon.generated.h"

/**
* Base class for all PlayFab Login method Results
*/
USTRUCT(BlueprintType)
struct PLAYFAB_API FPlayFabLoginResultCommon : public FPlayFabResultCommon
{
    GENERATED_BODY()

    // An authentication context returned by Login methods (can used in multi-user scenarios)
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayFab | Core")
        UPlayFabAuthenticationContext* AuthenticationContext;
};
