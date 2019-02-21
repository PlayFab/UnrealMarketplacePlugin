echo ========== BUILDING WIN64 ==========

rem # Unreal Path, to change depending on your workspace setup.
set uePath=C:\Program Files\Epic Games

rem # Unreal Version, to change on every unreal version
set ueVersion=4.18

rem # Full Path. In theory it should not be edited (the engine path/version are the only ones that should be edited).
set uatPath=%uePath%\UE_%ueVersion%\Engine\Build\BatchFiles\RunUAT.bat

rem # Destination Path, where the build will end up (relative to active directory).
set archivePath=Build\Win64

rem # The actual build command. To adapt depending on the needs.
call "%uatPath%" BuildCookRun -rocket -nocompile -nocompileeditor -installed -nop4 -project="%~dp0\ExampleProject.uproject" -cook -stage -archive -archivedirectory="%~dp0\%archivePath%" -package -clientconfig=Development -clean -compressed -CookAll -pak -prereqs -distribution -nodebuginfo -build -utf8output
