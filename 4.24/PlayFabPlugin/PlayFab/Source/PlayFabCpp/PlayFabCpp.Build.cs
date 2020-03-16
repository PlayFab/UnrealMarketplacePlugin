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
			"Engine",
            "HTTP",
            "Json",
            "JsonUtilities",
            "PlayFabCommon"
        });

		string partyHeaderIncludePath = "Party/{0}/build/native/include";
		string partyDllIncludePath = "Party/{0}/build/native/lib/{1}/release/{2}";
		string partyIncludesFolder = "";
		string partyXBLIncludesFolder = "";
		string partyPlatformFolder = "";
		string partyDLLName = "";

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			partyIncludesFolder = "Microsoft.PlayFab.PlayFabParty.Cpp.Windows.1.3.0";
			partyXBLIncludesFolder = "Microsoft.PlayFab.PlayFabPartyXboxLive.Cpp.Windows.1.2.0";
			partyPlatformFolder = "x64";
			partyDLLName = "PartyWin.dll";
		}
		else if (Target.Platform == UnrealTargetPlatform.XboxOne)
		{
			partyIncludesFolder = "Microsoft.PlayFab.PlayFabParty.Cpp.XboxOneXDK.1.3.0";
			partyXBLIncludesFolder = "Microsoft.PlayFab.PlayFabPartyXboxLive.Cpp.XboxOneXDK.1.2.0";
			partyPlatformFolder = "durango";
			partyDLLName = "Party.dll";

			PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Public/Party", partyDllIncludePath, "Party.lib"));
		}

		PublicIncludePaths.AddRange(
			new string[] {
				Path.Combine(
					ModuleDirectory,
					"Public", 
					string.Format(partyHeaderIncludePath, partyIncludesFolder)
				),
				Path.Combine(
					ModuleDirectory,
					"Public",
					string.Format(partyHeaderIncludePath, partyXBLIncludesFolder)
				)
			}
		);

		RuntimeDependencies.Add(string.Format(partyDllIncludePath, partyIncludesFolder, partyPlatformFolder, partyDLLName));
		PublicDelayLoadDLLs.Add(partyDLLName);
		RuntimeDependencies.Add(string.Format(partyDllIncludePath, partyXBLIncludesFolder, partyPlatformFolder, "PartyXboxLive.dll"));
		PublicDelayLoadDLLs.Add("PartyXboxLive.lib");

		PublicAdditionalLibraries.Add(
			Path.Combine(
				ModuleDirectory, 
				"Public", 
				string.Format(partyDllIncludePath, partyXBLIncludesFolder, partyPlatformFolder, "PartyXboxLive.lib")				
			)
		);

		//PublicIncludePaths.AddRange(
		//	new string[] {
		//		string.Format(partyHeaderIncludePath, partyIncludesFolder),
		//		string.Format(partyHeaderIncludePath, partyXBLIncludesFolder)
		//	}
		//);
	}

}
