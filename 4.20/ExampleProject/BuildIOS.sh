#!/bin/bash
echo ========== BUILDING iOS ==========

Usage="./BuildAndRunTestsIOS.sh <target ipa directory path> <path to project>"

archivePath=$1
projectPath=$2

if [ "$#" -ne 2 ]; then
    echo $usage
    exit 1
fi
 
# Unreal Path, to change depending on your workspace setup.
uePath="/Users/Shared/Epic Games"

# Unreal Version, to change on every unreal version
ueVersion="4.20"

# Full Path. In theory it should not be edited (the engine path/version are the only ones that should be edited).
uatPath="$uePath/UE_${ueVersion}/Engine/Build/BatchFiles/"

# Target Platform
targetPlatform=iOS

uprojdir="$projectPath/ExampleProject.uproject"

cd "$uatPath"

# The actual build command. To adapt depending on the needs.
. ./RunUAT.sh -ScriptsForProject="$uprojdir" BuildCookRun -nocompile -editorrecompile -installed -nop4 -project="$uprojdir" -cook -stage -archive -archivedirectory="$archivePath" -package -clientconfig=Development -ue4exe=UE4Editor -pak -prereqs -nodebuginfo -targetplatform=IOS -build -utf8output

