echo ========== BUILDING ANDROID ==========
set ueVersion=4.20
call "C:\Program Files\Epic Games\UE_%ueVersion%\Engine\Build\BatchFiles\RunUAT.bat" BuildPlugin -plugin="%~dp0PlayFab\PlayFab.uplugin" -package="%~dp0..\Build\Android" -TargetPlatforms=Android
pause
