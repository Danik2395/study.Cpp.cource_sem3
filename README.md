# Boat Calculator

## Dependencies

### Windows

- Qt
- MinGW compiler (bundled with Qt Tools)
- CMake

### Linux

- Qt base
- CMake
- Build tools (compiler, make)

## Installation

### Windows

1. Install Qt using the [Qt Online Installer](https://doc.qt.io/qt-6/qt-online-installation.html) and make sure to select the MinGW compiler kit and MinGW tools during component selection.
2. Open `winmake.bat` and set `QT_VERSION` and `MINGW_DIR_NAME` to match the Qt version and compiler folder you installed (see `C:\Qt\` and `C:\Qt\Tools\` for the exact names).
3. Run `winmake.bat`.

The script builds the project with CMake and MinGW, then copies `Boat_Calc.exe` together with its dependencies (via `windeployqt`) into `bin\windows`.

### Linux

1. Install Qt and the required build dependencies. See the official [Qt for Linux installation guide](https://doc.qt.io/qt-6/linux.html) for details.
2. Run `linuxmake.sh`.

The script builds the project with CMake and copies the resulting `Boat_Calc` binary into `bin/linux`.
