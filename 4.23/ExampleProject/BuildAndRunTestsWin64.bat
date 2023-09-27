rem # Running the build
call "%~dp0BuildWin64.bat"

rem # Running the Tests
call "%~dp0RunTestsWin64.bat"

cd "Build\Win64\WindowsNoEditor\ExampleProject\Saved\Logs"
type ExampleProject.log