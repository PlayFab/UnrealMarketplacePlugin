//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////

using UnrealBuildTool;
using System.IO; 

namespace UnrealBuildTool.Rules
{
    public class PlayFabTests : ModuleRules
    {
        public PlayFabTests(ReadOnlyTargetRules Target) : base(Target)
        {
            PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

            PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
            PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private"));

            PublicDependencyModuleNames.AddRange(
                new string[]
                {
                    "Core",
                    "CoreUObject",
                    "Engine",
                    "HTTP",
                    "Json",
                    "JsonUtilities"
                }
            );

            PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                    "PlayFab",
                    "PlayFabCpp"
                }
            );
        }
    }
}
