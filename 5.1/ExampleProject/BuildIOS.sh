#!/bin/bash
set -e
echo ========== BUILDING iOS ==========

Usage="./BuildIOS.sh <target ipa directory path> <path to project> <path to Unreal Engine install>"

archivePath=$1
projectPath=$2
uePath=$3

if [ "$#" -ne 3 ]; then
    echo $usage
    exit 1
fi

# Unreal Version, to change on every unreal version
ueVersion="5.1"

# Full Path. In theory it should not be edited (the engine path/version are the only ones that should be edited).
uatPath="$uePath/UE_${ueVersion}/Engine/Build/BatchFiles/"

# Target Platform
targetPlatform=iOS

uprojdir="$projectPath/ExampleProject.uproject"

cd "$uatPath"

# The actual build command. To adapt depending on the needs.
. ./RunUAT.sh -ScriptsForProject="$uprojdir" BuildCookRun -nocompile -editorrecompile -installed -nop4 -project="$uprojdir" -cook -stage -archive -archivedirectory="$archivePath" -package -clientconfig=Development -ue4exe=UE4Editor -pak -prereqs -nodebuginfo -targetplatform=IOS -build -utf8output

