//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////

using UnrealBuildTool;

public class ExampleProject : ModuleRules
{
    public ExampleProject(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivatePCHHeaderFile = "ExampleProject.h";
        PCHUsage = PCHUsageMode.NoSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
        PublicDependencyModuleNames.AddRange(new string[] { "Json", "JsonUtilities" });

        PrivateDependencyModuleNames.AddRange(new string[] { "PlayFab", "PlayFabCpp", "PlayFabCommon" });
    }
}
