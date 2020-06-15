//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "PlayFabCommonUtils.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

using namespace PlayFabCommon;

// GetEnvironmentVariable with 3 parameters is considered deprecated:
// http://api.unrealengine.com/INT/API/Runtime/Core/GenericPlatform/FGenericPlatformMisc/GetEnvironmentVariable/2/index.html
// The newer version of GetEnvironmentVariable with a single parameter broke our 4.20 plugin build for the Epic Store
// 
// see {your unreal root folder}\Engine\Source\Runtime\Launch\Resources\Version.h for more preprocessor defines
#if ENGINE_MINOR_VERSION==20
FString PlayFabCommonUtils::GetTempDir()
{
    FString vars[] = { TEXT("TEMPDIR"), TEXT("TEMP"), TEXT("TMP") };
    const int expectedPathSize = 256;
    TCHAR FileSystemPath[expectedPathSize];
    for (FString& envVar : vars)
    {
        FileSystemPath[0] = 0;
        FPlatformMisc::GetEnvironmentVariable(*envVar, FileSystemPath, expectedPathSize);
        if (FileSystemPath[0])
        {
            return FString(expectedPathSize, FileSystemPath);
        }
    }
    return FString();
}
#else
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
#endif

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
