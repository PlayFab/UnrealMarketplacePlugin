//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "PlayFabCommonUtils.h"

using namespace PlayFabCommon;

FString PlayFabCommonUtils::GetTempDir()
{
    FString vars[] = { TEXT("TEMPDIR"), TEXT("TEMP"), TEXT("TMP") };
    for (FString envVar : vars)
    {
        FString tempDir = FPlatformMisc::GetEnvironmentVariable((TEXT("%s"), *envVar));
        if (!tempDir.IsEmpty())
        {
            return tempDir;
        }
    }
    return FString();
}

FString PlayFabCommonUtils::GetLocalSettingsFileContent()
{
    FString tempDirPath = PlayFabCommonUtils::GetTempDir();
    FString localSettingsFilePath = FPaths::Combine(tempDirPath, TEXT("playfab.local.settings.json"));
    FString localSettingsFileContent = "";
    return FFileHelper::LoadFileToString(localSettingsFileContent, *localSettingsFilePath)
        ? localSettingsFileContent
        : FString();
}

TSharedPtr<FJsonObject> PlayFabCommonUtils::GetLocalSettingsFileJson()
{
    FString fileContent = PlayFabCommonUtils::GetLocalSettingsFileContent();
    TSharedPtr<FJsonObject> jsonObject = MakeShareable(new FJsonObject());
    TSharedRef<TJsonReader<>> jsonReader = TJsonReaderFactory<>::Create(fileContent);
    return (FJsonSerializer::Deserialize(jsonReader, jsonObject) && jsonObject.IsValid())
        ? jsonObject
        : MakeShareable(new FJsonObject());
}

FString PlayFabCommonUtils::GetLocalSettingsFileProperty(const FString& propertyKey)
{
    TSharedPtr<FJsonObject> jsonObject = PlayFabCommonUtils::GetLocalSettingsFileJson();
    FString outString;
    return jsonObject->TryGetStringField(propertyKey, outString) ? outString : FString();
}