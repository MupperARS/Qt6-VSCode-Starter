cmake_minimum_required(VERSION 3.10) # CMake install : https://cmake.org/download/
project("Qt6-VSCode-Starter" VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "D:/Program Files/Qt/6.9.2/mingw_64") # Qt Kit Dir
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt6 COMPONENTS Core Gui Widgets SerialPort REQUIRED) # Qt COMPONENTS
find_package(Vulkan REQUIRED)

qt_standard_project_setup()

# add_compile_options(-std=c++19 -Wall)

#判断构建类型
if(!CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

#判断构建类型是否是MINGW 并且是发行优化
if(MINGW AND CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "-mwindows")
endif(MINGW AND CMAKE_BUILD_TYPE STREQUAL "Release")

# Specify MSVC UTF-8 encoding
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

#这里写入显式的头文件
include_directories("src/Application")

# Can manually add the sources using the set command as follows:
# set(SOURCES src/mainapp.cpp src/Student.cpp)
# However, the file(GLOB...) allows for wildcard additions:

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/[^.]*.cpp")

#这个是在将ui文件添加到源文件的尾部
list(APPEND CMAKE_AUTOUIC_SEARCH_PATHS "${PROJECT_SOURCE_DIR}/ui")

# set((EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build))
add_executable(${PROJECT_NAME}
    #WIN32 # If you need a terminal for debug, please comment this statement
    ${SOURCES}
)
#来这里写要连接的库(动态连接dll)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::SerialPort Vulkan::Vulkan) # Qt6 Shared Library

#加载测试器
include(CTest)
find_package(Qt6 COMPONENTS Test REQUIRED)
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS "test/*.cpp")
enable_testing()

if(TEST_SOURCES)
    set(TEST_SOURCE_FILES ${SOURCES})
    list(REMOVE_ITEM TEST_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

    add_executable(${PROJECT_NAME}_Tests ${TEST_SOURCES} ${TEST_SOURCE_FILES})

    # 设置测试目标的包含目录
    target_include_directories(${PROJECT_NAME}_Tests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Application
        ${CMAKE_CURRENT_SOURCE_DIR}/test
    )

    # 链接测试目标
    target_link_libraries(${PROJECT_NAME}_Tests PRIVATE
        Qt6::Test
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::SerialPort
    )
    add_test(NAME ${PROJECT_NAME}_Tests COMMAND ${PROJECT_NAME}_Tests)
endif()

install(TARGETS ${PROJECT_NAME}
    # ARCHIVE DESTINATION ${PROJECT_NAME}/lib
    RUNTIME DESTINATION bin    #位置改为bin目录内
    # PUBLIC_HEADER DESTINATION ${PROJECT_NAME}/include
)

#use Qt6 deploy script
qt_generate_deploy_app_script(
    TARGET ${PROJECT_NAME}
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)

install(SCRIPT ${deploy_script})

install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/static"
    DESTINATION "."
    PATTERN ".gitignore" EXCLUDE
)

include(InstallRequiredSystemLibraries)
set(CPACK_GENERATOR "NSIS")     #NSIS安装器 可选RAR、7ZIP等
set(CPACK_NSIS_ENABLE_UNINSTALL_BEFORE_INSTALL ON)
set(CPACK_NSIS_MODIFY_PATH OFF)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_NSIS_MUI_ICON "${CMAKE_CURRENT_SOURCE_DIR}/static/icon.ico")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_CREATE_DESKTOP_LINKS "${PROJECT_NAME}")
#判断是否是Windows
if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(CPACK_NSIS_MENU_LINKS "${PROJECT_NAME}.exe" "Launch ${PROJECT_NAME}")
else()
    set(CPACK_PACKAGE_EXECUTABLES "bin/${PROJECT_NAME}" "Launch ${PROJECT_NAME}")
endif()
set(CPACK_PACKAGE_INSTALL_DIRECTORY "${PROJECT_NAME}")
include(CPack)
