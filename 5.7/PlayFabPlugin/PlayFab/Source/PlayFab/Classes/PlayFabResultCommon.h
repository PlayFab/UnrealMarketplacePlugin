//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "CoreMinimal.h"
#include "PlayFabJsonObject.h"
#include "PlayFabResultCommon.generated.h"

USTRUCT(BlueprintType)
struct PLAYFAB_API FPlayFabResultCommon
{
    GENERATED_BODY()

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayFab | Core")
        TObjectPtr<UPlayFabJsonObject> Request;
};
