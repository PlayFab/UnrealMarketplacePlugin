//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "PlayFabTests.h"

DEFINE_LOG_CATEGORY(LogPlayFabTests);

class FPlayFabTestsModule : public IModuleInterface
{
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};

void FPlayFabTestsModule::StartupModule()
{

}

void FPlayFabTestsModule::ShutdownModule()
{

}

IMPLEMENT_MODULE(FPlayFabTestsModule, PlayFabTests)