echo ======= RUNNING TESTS WIN64 =======

rem # Destination Path, where the build will end up (relative to active directory).
set archivePath=Build\Win64

call "%~dp0%archivePath%\WindowsNoEditor\ExampleProject.exe" -run=RunTests -NoShaderCompile
