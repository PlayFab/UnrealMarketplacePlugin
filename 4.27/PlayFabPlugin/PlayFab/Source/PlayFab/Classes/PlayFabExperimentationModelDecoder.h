//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Experimentation
//////////////////////////////////////////////////////////////////////////////////////////////

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabExperimentationModels.h"
#include "PlayFabExperimentationModelDecoder.generated.h"

class UPlayFabJsonObject;

UCLASS()
class PLAYFAB_API UPlayFabExperimentationModelDecoder : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    //////////////////////////////////////////////////////////////////////////
    // Generated PlayFab Experimentation API Functions
    //////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////
    // Experimentation
    //////////////////////////////////////////////////////

    /** Decode the CreateExclusionGroupResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Experimentation | Experimentation Models")
        static FExperimentationCreateExclusionGroupResult decodeCreateExclusionGroupResultResponse(UPlayFabJsonObject* response);

    /** Decode the CreateExperimentResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Experimentation | Experimentation Models")
        static FExperimentationCreateExperimentResult decodeCreateExperimentResultResponse(UPlayFabJsonObject* response);

    /** Decode the EmptyResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Experimentation | Experimentation Models")
        static FExperimentationEmptyResponse decodeEmptyResponseResponse(UPlayFabJsonObject* response);

    /** Decode the GetExclusionGroupsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Experimentation | Experimentation Models")
        static FExperimentationGetExclusionGroupsResult decodeGetExclusionGroupsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetExclusionGroupTrafficResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Experimentation | Experimentation Models")
        static FExperimentationGetExclusionGroupTrafficResult decodeGetExclusionGroupTrafficResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetExperimentsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Experimentation | Experimentation Models")
        static FExperimentationGetExperimentsResult decodeGetExperimentsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetLatestScorecardResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Experimentation | Experimentation Models")
        static FExperimentationGetLatestScorecardResult decodeGetLatestScorecardResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetTreatmentAssignmentResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Experimentation | Experimentation Models")
        static FExperimentationGetTreatmentAssignmentResult decodeGetTreatmentAssignmentResultResponse(UPlayFabJsonObject* response);



};
