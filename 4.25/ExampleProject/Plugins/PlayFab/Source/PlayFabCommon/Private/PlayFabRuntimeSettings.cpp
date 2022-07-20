//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "PlayFabCommon/Public/PlayFabRuntimeSettings.h"

//////////////////////////////////////////////////////////////////////////
// UPlayFabRuntimeSettings

UPlayFabRuntimeSettings::UPlayFabRuntimeSettings()
    : ProductionEnvironmentURL(TEXT(".playfabapi.com"))
    , TitleId()
    , DeveloperSecretKey()
{
}
