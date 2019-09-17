//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "CoreMinimal.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Dom/JsonObject.h"

namespace PlayFabCommon
{
    class PLAYFABCOMMON_API PlayFabCommonUtils
    {
    private:
        static FString GetTempDir();
        static FString GetLocalSettingsFileContent();
        static TSharedPtr<FJsonObject> GetLocalSettingsFileJson();
    public:
        static FString GetLocalSettingsFileProperty(const FString& propertyKey);
    };
}
