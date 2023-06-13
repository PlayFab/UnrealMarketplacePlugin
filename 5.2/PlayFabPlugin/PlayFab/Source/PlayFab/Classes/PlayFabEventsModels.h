//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Events
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabRequestCommon.h"
#include "PlayFabLoginResultCommon.h"
#include "PlayFabEventsModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Events API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// PlayStream
//////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// PlayStream Events
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct PLAYFAB_API FEventsWriteEventsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The optional custom tags associated with the request (e.g. build number, external trace identifiers, etc.). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        UPlayFabJsonObject* CustomTags = nullptr;
    /** The collection of events to write. Up to 200 events can be written per request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        TArray<UPlayFabJsonObject*> Events;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FEventsWriteEventsResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /**
     * The unique identifiers assigned by the server to the events, in the same order as the events in the request. Only
     * returned if FlushToPlayStream option is true.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Events | PlayStream Events Models")
        FString AssignedEventIds;
};

