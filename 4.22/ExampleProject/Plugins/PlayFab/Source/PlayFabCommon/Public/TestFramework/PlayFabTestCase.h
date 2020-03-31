//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "Misc/Paths.h"

#include "PlayFabTestCase.generated.h"

class UPlayFabTestContext;

/**
 * A macro to quickly add a test to a TArray<UPlayFabTestContext*>.
 * To be used in GetTests.
 */
#define ADD_TEST(TestName, TestMethod) Add(UPlayFabTestContext::CreateTestContext(TEXT(#TestName), this, TEXT(#TestMethod)));

// A collection of Tests to execute.
UCLASS(abstract)
class PLAYFABCOMMON_API UPlayFabTestCase : public UObject
{
    GENERATED_BODY()

protected:
    // A bunch of constants: load these from testTitleData.json
    // TODO: Should be moved out of UPlayFabTestCase.
    UPROPERTY()
    FString TEST_TITLE_DATA_LOC = FPaths::ProjectContentDir() + TEXT("/TestTitleData/testTitleData.json");;
    UPROPERTY()
    FString TEST_DATA_KEY = "testCounter";
    UPROPERTY()
    FString TEST_STAT_NAME = "str";
    UPROPERTY()
    FString PlayFabId;
    UPROPERTY()
    FString entityId;
    UPROPERTY()
    FString entityType;
    UPROPERTY()
    FDateTime testMessageTime;

    UPROPERTY()
    FString TitleId;
    UPROPERTY()
    FString DevSecretKey;
    UPROPERTY()
    FString UserEmail;

public:
    // Default Constructor.
    UPlayFabTestCase();

    /**
     * Before testing, this function is called to gather the list of tests to run for each TestCase.
     * It is not considered part of any test. A failure or exception in this method will halt the test framework.
     */
    virtual void GetTests(TArray<UPlayFabTestContext*>& InTestList) { }

    /**
     * During testing, this is the first function that will be called for each TestCase.
     * This is run exactly once for this type.
     */
    virtual void ClassSetUp() { }

    /**
     * During testing, this will be called once before every test function.
     * This is run once for each test.
     * This is considered part of the active test. A failure or exception in this method will be considered a failure for the active test.
     */
    virtual void SetUp(UPlayFabTestContext* /* testContext */) { }

    /**
     * During testing, this will be called every tick that a test is asynchronous.
     * This is run every tick until testContext.EndTest() is called, or until the test times out.
     * This is considered part of the active test. A failure or exception in this method will be considered a failure for the active test.
     */
    virtual void Tick(UPlayFabTestContext* /* testContext */) { }

    /**
     * During testing, this will be called once after every test function.
     * This is run once for each test.
     * This is considered part of the active test. A failure or exception in this method will be considered a failure for the active test.
     */
    virtual void TearDown(UPlayFabTestContext* /* testContext */) { }

    /**
     * During testing, this is the last function that will be called for each TestCase.
     * This is run exactly once for this type.
     * It is not considered part of any test. A failure or exception in this method will halt the test framework.
     */
    virtual void ClassTearDown() { }
};
