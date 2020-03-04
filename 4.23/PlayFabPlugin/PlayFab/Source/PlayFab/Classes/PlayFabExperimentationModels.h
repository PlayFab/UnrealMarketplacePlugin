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
#include "PlayFabRequestCommon.h"
#include "PlayFabLoginResultCommon.h"
#include "PlayFabExperimentationModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Experimentation API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Experimentation
//////////////////////////////////////////////////////

/** Given a title entity token and experiment details, will create a new experiment for the title. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FExperimentationCreateExperimentRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Description of the experiment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        FString Description;
    /** The duration of the experiment, in days. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        int32 Duration = 0;
    /** Type of experiment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        EExperimentType ExperimentType;
    /** Friendly name of the experiment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        FString Name;
    /** Id of the segment to which this experiment applies. Defaults to the 'All Players' segment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        FString SegmentId;
    /** When experiment should start. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        FString StartDate;
    /**
     * List of title player account IDs that automatically receive treatments in the experiment, but are not included when
     * calculating experiment metrics.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        FString TitlePlayerAccountTestIds;
    /** List of variants for the experiment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        TArray<UPlayFabJsonObject*> Variants;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FExperimentationCreateExperimentResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The ID of the new experiment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        FString ExperimentId;
};

/**
 * Given an entity token and an experiment ID this API deletes the experiment. A running experiment must be stopped before
 * it can be deleted.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FExperimentationDeleteExperimentRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The ID of the experiment to delete. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        FString ExperimentId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FExperimentationEmptyResponse : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

/**
 * Given a title entity token will return the list of all experiments for a title, including scheduled, started, stopped or
 * completed experiments.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FExperimentationGetExperimentsRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FExperimentationGetExperimentsResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of experiments for the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        TArray<UPlayFabJsonObject*> Experiments;
};

/** Given a title entity token and experiment details, will return the latest available scorecard. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FExperimentationGetLatestScorecardRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The ID of the experiment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        FString ExperimentId;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FExperimentationGetLatestScorecardResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Scorecard for the experiment of the title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        UPlayFabJsonObject* Scorecard = nullptr;
};

/**
 * Given a title player or a title entity token, returns the treatment variants and variables assigned to the entity across
 * all running experiments
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FExperimentationGetTreatmentAssignmentRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The entity to perform this action on. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        UPlayFabJsonObject* Entity = nullptr;
};

USTRUCT(BlueprintType)
struct PLAYFAB_API FExperimentationGetTreatmentAssignmentResult : public FPlayFabResultCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Treatment assignment for the entity. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        UPlayFabJsonObject* TreatmentAssignment = nullptr;
};

/** Given a title entity token and an experiment ID, this API starts the experiment. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FExperimentationStartExperimentRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The ID of the experiment to start. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        FString ExperimentId;
};

/** Given a title entity token and an experiment ID, this API stops the experiment if it is running. */
USTRUCT(BlueprintType)
struct PLAYFAB_API FExperimentationStopExperimentRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** The ID of the experiment to stop. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        FString ExperimentId;
};

/**
 * Given a title entity token and experiment details, this API updates the experiment. If an experiment is already running,
 * only the description and duration properties can be updated.
 */
USTRUCT(BlueprintType)
struct PLAYFAB_API FExperimentationUpdateExperimentRequest : public FPlayFabRequestCommon
{
    GENERATED_USTRUCT_BODY()
public:
    /** Description of the experiment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        FString Description;
    /** The duration of the experiment, in days. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        int32 Duration = 0;
    /** Type of experiment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        EExperimentType ExperimentType;
    /** Id of the experiment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        FString Id;
    /** Friendly name of the experiment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        FString Name;
    /** Id of the segment to which this experiment applies. Defaults to the 'All Players' segment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        FString SegmentId;
    /** When experiment should start. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        FString StartDate;
    /**
     * List of title player account IDs that automatically receive treatments in the experiment, but are not included when
     * calculating experiment metrics.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        FString TitlePlayerAccountTestIds;
    /** List of variants for the experiment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Experimentation | Experimentation Models")
        TArray<UPlayFabJsonObject*> Variants;
};

