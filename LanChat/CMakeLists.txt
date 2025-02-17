cmake_minimum_required(VERSION 3.16)

project(LanChat VERSION 0.1 LANGUAGES CXX)

# 启用自动处理 MOC、UIC 和 RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找 Qt 包，支持 Qt 5 和 Qt 6
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# 你的源文件列表
set(PROJECT_SOURCES
    main.cpp
    login.cpp
    mainwidget.cpp
    login.h
    mainwidget.h
    login.ui
    mainwidget.ui
)

# 如果是 Qt 6, 使用 qt_add_executable
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(LanChat
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        images/LoginWeight.qss
        images/bg.png images/bg_2.png images/bold.png images/chose.png images/clear.png images/close.png images/color.png images/italic.png images/logo.ico images/save.png images/send.png images/unchose.png images/underline.png
        logo.ico
    )
else()
    # 如果是 Qt 5
    add_executable(LanChat
        ${PROJECT_SOURCES}
    )
endif()

# 链接 Qt Widgets 库
target_link_libraries(LanChat PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt 6 中，设置目标属性和最终化
if(${QT_VERSION_MAJOR} EQUAL 6)
    set_target_properties(LanChat PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER com.example.LanChat
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
    )
    qt_finalize_executable(LanChat)
else()
    # Qt 5 中的设置，类似设置 Mac 和 Windows 的属性
    set_target_properties(LanChat PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER com.example.LanChat
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
    )
endif()

# 安装目标
include(GNUInstallDirs)
install(TARGETS LanChat
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
