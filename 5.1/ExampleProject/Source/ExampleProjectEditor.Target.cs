//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////

using UnrealBuildTool;
using System.Collections.Generic;

public class ExampleProjectEditorTarget : TargetRules
{
    public ExampleProjectEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        ExtraModuleNames.AddRange(new string[] { "ExampleProject" });
        DefaultBuildSettings = BuildSettingsVersion.V2;

        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;

    }
}
