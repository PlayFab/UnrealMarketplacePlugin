echo ========== BUILDING ANDROID EXAMPLE PROJECT ==========
set usage="USAGE: BuildAndroidOnWin64.bat [archive directory]"

if "%~1"=="" goto USAGE

rem # Unreal Path, to change depending on your workspace setup.
set uePath=C:\Program Files\Epic Games

rem # Unreal Version, to change on every unreal version
set ueVersion=4.27

rem # Full Path. In theory it should not be edited (the engine path/version are the only ones that should be edited).
set uatPath=%uePath%\UE_%ueVersion%\Engine\Build\BatchFiles

rem # Destination Path, where the build will end up (relative to active directory).
set archivePath=%1

rem # Clear out the destination folder so the build lands on clean ground.
if exist %archivePath% rd /s /q %archivePath%

rem $ Copy testTitleData.json into the build folder
copy /Y "%PF_TEST_TITLE_DATA_JSON%" "%~dp0%Content\TestTitleData"

rem # The actual build command. To adapt depending on the needs.
pushd "%uatPath%"
.\RunUAT.bat -ScriptsForProject="%~dp0ExampleProject.uproject" BuildCookRun -nocompile -editorrecompile -installed -nop4 -project="%~dp0ExampleProject.uproject" -cook -stage -archive -archivedirectory="%archivePath%" -package -clientconfig=Development -ue4exe=UE4Editor-Cmd.exe -pak -prereqs -nodebuginfo -targetplatform=Android -cookflavor=Multi -build -utf8output
popd 

rem $ Delete testTitleData out of the build folder now that the APK packaging is complete.
del "%~dp0%Content\TestTitleData\testTitleData.json"

goto DONE

:USAGE
echo %usage%

:DONE
