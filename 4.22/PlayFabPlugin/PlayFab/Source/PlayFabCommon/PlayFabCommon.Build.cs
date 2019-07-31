//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////

using UnrealBuildTool;
using System.IO; 

public class PlayFabCommon : ModuleRules
{
    public PlayFabCommon(ReadOnlyTargetRules Target) : base(Target)
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
                "JsonUtilities",
            }
        );

        if (Target.bBuildEditor == true)
        {
            PrivateDependencyModuleNames.AddRange(new string[] {
                "Settings"
            });
        }

        BuildVersion Version;
        BuildVersion.TryRead(BuildVersion.GetDefaultFileName(), out Version);
        PublicDefinitions.Add(string.Format("ENGINE_MAJOR_VERSION={0}", Version.MajorVersion));
        PublicDefinitions.Add(string.Format("ENGINE_MINOR_VERSION={0}", Version.MinorVersion));

    }
}
