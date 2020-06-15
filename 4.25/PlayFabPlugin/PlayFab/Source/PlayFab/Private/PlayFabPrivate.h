//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// PlayFab Main Header File
////////////////////////////////////////////////////////////

#pragma once

#include "Delegates/Delegate.h"
#include "Http.h"
#include "Containers/Map.h"

#include "Serialization/JsonWriter.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogPlayFab, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(LogPlayFabTests, Log, All);

#include "PlayFab/Public/IPlayFab.h"
