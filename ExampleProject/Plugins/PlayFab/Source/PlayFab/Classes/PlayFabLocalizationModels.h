//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Localization
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabLocalizationModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Localization API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Localization
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FLocalizationGetLanguageListRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FLocalizationGetLanguageListResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** The list of Playfab-supported languages */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Localization | Localization Models")
        FString LanguageList;
};

