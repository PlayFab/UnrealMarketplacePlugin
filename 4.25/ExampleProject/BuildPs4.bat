echo ========== BUILDING PS4 ==========
set ueVersion=4.25
set uatPath=%~d0\dev\EpicGames\UE_%ueVersion%_src\Engine\Build\BatchFiles\RunUAT.bat
set targetPlatform=PS4
set exampleProjArchDir=%~dp0..\Archive
set exampleProjFile=%~dp0\ExampleProject.uproject
call "%uatPath%" -ScriptsForProject=%exampleProjFile% BuildCookRun -project=%exampleProjFile% -cook -stage -archive -archivedirectory=%exampleProjArchDir% -package -pak -prereqs -nodebuginfo -targetplatform=%targetPlatform% -build -target=ExampleProject -clientconfig=Development -utf8output -compile
pause
