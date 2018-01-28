:test
call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\Tools\VsDevCmd.bat"
:test
msbuild myApp.sln /t:Build /p:Configuration=Release
Release\demo.app.exe
pause
goto test