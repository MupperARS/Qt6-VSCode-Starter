# Qt6-VSCode-Starter
A ready-to-use Qt6 development template with integrated VSCode configuration and CMake build system.
![Qt](https://img.shields.io/badge/Qt-6.9.2-green?style=flat-square&logo=qt)
![License](https://img.shields.io/badge/License-MIT-yellow?style=flat-square)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey?style=flat-square)
![IDE](https://img.shields.io/badge/Primary%20IDE-VSCode-0078d7?style=flat-square&logo=visualstudiocode)

## Project Structure
```
.
├── .vscode/
│ └── settings.json
├── src/
│ ├── main.cpp
│ └── Application/
│   ├── MainWindow.cpp
│   └── MainWindow.h
├── static/
│ ├── icon.ico
│ └── icon.png
├── .gitgnore
├── CMakeLists.txt
├── License.txt
└── README.md
```

## Configuration File Examples

### .vscode/settings.json
```json
{
    "C_Cpp.default.configurationProvider": "ms-vscode.cmake-tools",
    "qtConfigure.qtKitDir": "D:\\Program Files\\Qt\\6.8.2\\mingw_64\\bin",
    "cmake.options.statusBarVisibility": "visible"
}
```

### CMakeLists.txt

```cmake
    set(CMAKE_PREFIX_PATH "D:/Program Files/Qt/6.9.2/mingw_64") # Qt Kit Dir
```

## Quick Start
```bash
    git clone https://github.com/MupperARS/Qt6-VSCode-Starter.git
    cd Qt6-VSCode-Starter
    code .
```

1. **​​Configure Environment**
    Install qt tools, Qt C++ Extension Pack
2. **​​Configure Active Kit**
    Select the mingw32/bin path from Qt in the configurable active kit at the bottom
    If not added to the system environment, add mingw32/bin
3. **Generate Build System​**
    Click Generate to proceed
4. **Compile Project​**
    Click the build arrow to compile and launch the project

## Features

- ✅ Ready-to-use Qt6 configuration
- ✅ Deep VSCode integration
- ✅ Cross-platform support
- ✅ CMake build system
- ✅ Automated resource handling

## License

MIT License