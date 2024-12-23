//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////

using UnrealBuildTool;
using System.IO; 

public class PlayFabCpp : ModuleRules
{
    public PlayFabCpp(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
      
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));

        PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private"));

        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public/Core"));

        PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private/Core"));

        PublicDependencyModuleNames.AddRange(new string[]{
            "Core",
            "CoreUObject",
            "HTTP",
            "Json",
            "JsonUtilities",
            "PlayFabCommon"
        });
    }
}
