rem # Note: In order to cook for Xbox / XboxOneGDK / WinGDK, the following environment variables need to be set:
rem #	GameDK : Points to the Microsoft GDK folder; Example: set "GameDK=C:\Program Files (x86)\\Microsoft GDK\\"
rem #	GameDKLatest : Points to the GDK folder with the version number; Example: set "GameDKLatest=C:\Program Files (x86)\\Microsoft GDK\\210607\"

echo ========== BUILDING XboxOneGDK ==========

rem # Unreal Path, to change depending on your workspace setup.
set uePath=C:\Program Files\Epic Games

rem # Unreal Version, to change on every unreal version
set ueVersion=5.2
rem # Full Path. In theory it should not be edited (the engine path/version are the only ones that should be edited).
set uatPath=%uePath%\UE_%ueVersion%\Engine\Build\BatchFiles\RunUAT.bat

rem # Target Platform
set targetPlatform=XboxOneGDK

rem # Destination Path, where the build will end up (relative to active directory).
set archivePath=Build\%targetPlatform%


rem # UBT path. calling UBT from RunUAT gives an error about the path.
set ubtPath=%uePath%\UE_%ueVersion%\Engine\Binaries\DotNET\UnrealBuildTool.exe

rem # Build the editor exe and libraries. Needed on UE4 < 20 for the build command to work.
call "%ubtPath%" ExampleProject Development Win64 -project="%~dp0\ExampleProject.uproject" -editorrecompile -NoHotReloadFromIDE

rem # The actual build command. To adapt depending on the needs.
call "%uatPath%" BuildCookRun -rocket -installed -nop4 -compile -compileeditor -project="%~dp0ExampleProject.uproject" -cook -stage -archive -archivedirectory="%~dp0%archivePath%" -package -clientconfig=Development -Platform=%targetPlatform% -compressed -CookAll -pak -prereqs -build -utf8output


