//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////

using UnrealBuildTool;
using System.Collections.Generic;

public class ExampleProjectTarget : TargetRules
{
    public ExampleProjectTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        ExtraModuleNames.AddRange(new string[] { "ExampleProject" });
        DefaultBuildSettings = BuildSettingsVersion.V2;
    }
}
