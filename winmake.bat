@echo off

set EXE_NAME=Boat_Calc

set QT_VERSION=6.11.2
set MINGW_DIR_NAME=mingw1310_64

set QT_DIR=C:\Qt\%QT_VERSION%\mingw_64
set COMPILER_DIR=C:\Qt\Tools\%MINGW_DIR_NAME%\bin

rem To not to bump into another compiler in PATH set it in the begining
set PATH=%COMPILER_DIR%;%PATH%

rem Has '\'in the end
set SOURCE_DIR=%~dp0
set BUILD_DIR=%SOURCE_DIR%build
set WIN_BIN_RELEASE=%SOURCE_DIR%bin\windows

mkdir %BUILD_DIR%

cmake -B %BUILD_DIR% -G "MinGW Makefiles" -DCMAKE_PREFIX_PATH="%QT_DIR%" -DCMAKE_BUILD_TYPE=Release
if %errorlevel% neq 0 goto error

cmake --build %BUILD_DIR% -j 8
if %errorlevel% neq 0 goto error

mkdir %WIN_BIN_RELEASE%

if exist %BUILD_DIR%\%EXE_NAME%.exe (
    copy %BUILD_DIR%\%EXE_NAME%.exe %WIN_BIN_RELEASE%
    "%QT_DIR%\bin\windeployqt.exe" %WIN_BIN_RELEASE%\%EXE_NAME%.exe
    if %errorlevel% neq 0 goto error
)

exit \b 0

:error
exit \b 1
