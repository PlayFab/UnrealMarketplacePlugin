set uatPath=%~d0\dev\EpicGames\UE_4.24_src\Engine\Build\BatchFiles\RunUAT.bat
set targetPlatform=PS4
set exampleProjArchDir=%~dp0..\Archive
set exampleProjFile=%~dp0\ExampleProject.uproject
call "%uatPath%" -ScriptsForProject=%exampleProjFile% BuildCookRun -nocompileeditor -nop4 -project=%exampleProjFile% -cook -stage -archive -archivedirectory=%exampleProjArchDir% -package -pak -prereqs -nodebuginfo -targetplatform=%targetPlatform% -build -target=ExampleProject -clientconfig=Development -utf8output -compile
pause
