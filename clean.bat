@echo off
echo ********************************************
echo *       VC,Delphi垃圾文件清理程序          *
echo ********************************************
if "%1"=="-h" goto _help
echo 开始清理，请等待......
echo.
if "%1"=="" set dir="." 
goto _lab
set dir="%1"
:_lab
for /R %dir% %%i in (*.obj *.pch *.pdb *.idb *.ilk *.sbr *.tmp *.res *.dcu *.opt *.ncb *.plg *.bsc *.aps *.tli *.tlh *.suo *.user *.dep *.htm *.intermediate.manifest) do @del /f /s /q "%%i"
for /R %dir% %%i in (Debug Release Debug_Unicode Release_Unicode) do @rd /q "%%i"
echo 清理完毕！
goto _end
:_help
echo  注意：1）不输入路径，表示从当前目录开始删除
echo        2）输入路径，则从所输入路径开始山删除
echo.
:_end
echo. & pause
