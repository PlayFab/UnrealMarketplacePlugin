//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// PlayFab Base Model Header. This file holds the base ustruct for the playfab models.
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "PlayFabBaseModel.generated.h"

class UPlayFabJsonObject;

USTRUCT(BlueprintType)
struct PLAYFAB_API FPlayFabError
{
    GENERATED_USTRUCT_BODY()

    /** Is there an error */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Error | Models")
        bool hasError;

    /** Holds the error code recieved from playfab. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Error | Models")
        int32 ErrorCode;

    /** Holds the error name recieved from playfab. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Error | Models")
        FString ErrorName;

    /** Holds the error message recieved from playfab. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Error | Models")
        FString ErrorMessage;

    /** Holds the error details recieved from playfab. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Error | Models")
        FString ErrorDetails;

    // Decode the error if there is one
    void decodeError(UPlayFabJsonObject* responseData);

};

USTRUCT(BlueprintType)
struct PLAYFAB_API FPlayFabBaseModel
{
    GENERATED_USTRUCT_BODY()

    /** Holds the error USTRUCT recieved from playfab. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Error | Models")
        FPlayFabError responseError;

    /** Holds the full JSON recieved from playfab. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Error | Models")
        UPlayFabJsonObject* responseData;

};
