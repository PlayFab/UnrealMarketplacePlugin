#!/bin/bash
set -e

DoWork() {
    echo ========== BUILDING Mac ==========

    targetPlatform=Mac
    projectPath=$PWD
    scriptsForProject="${projectPath}/ExampleProject.uproject"
    uePath="/Users/Shared/Epic Games"
    ueVersion="5.2"
    uatPath="${uePath}/UE_${ueVersion}/Engine/Build/BatchFiles/"
    cd "$uatPath"

    # The actual build command. To adapt depending on the needs.
    . ./RunUAT.sh -ScriptsForProject=$scriptsForProject BuildCookRun -project=$scriptsForProject -noP4 -clientconfig=Development -serverconfig=Development -nocompile -nocompileeditor -installed -utf8output -platform=$targetPlatform -targetplatform=$targetPlatform -ini:Game:[/Script/UnrealEd.ProjectPackagingSettings]:BlueprintNativizationMethod=Disabled -build -cook -compressed -iterativedeploy -stage -deploy
}

DoWork
