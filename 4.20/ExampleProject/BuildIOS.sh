#!/bin/bash
echo ========== BUILDING MAC ==========

# Unreal Path, to change depending on your workspace setup.
uePath="/Users/Shared/Epic Games"

# Unreal Version, to change on every unreal version
ueVersion="4.20"

# Full Path. In theory it should not be edited (the engine path/version are the only ones that should be edited).
uatPath="$uePath"/UE_"$ueVersion"/Engine/Build/BatchFiles/

# Target Platform
targetPlatform=iOS

currentdir=`pwd`

uprojdir="$currentdir"/ExampleProject.uproject

currentdir=`pwd`

# Destination Path, where the build will end up (relative to active directory).
archivePath=Build/"$targetPlatform"
pushd "$uatPath"
# The actual build command. To adapt depending on the needs.
. RunUAT.sh BuildCookRun -clean -rocket -installed -nop4 -nocompile -project="$uprojdir" -cook -stage -archive -archivedirectory="$archivePath" -package -clientconfig=Development -Platform="$targetPlatform" -compressed -CookAll -pak -prereqs -build -utf8output -editorrecompile
popd
