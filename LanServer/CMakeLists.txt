cmake_minimum_required(VERSION 3.16)

project(LanServer LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core HttpServer Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core HttpServer Sql)

add_executable(LanServer
  main.cpp
)
target_link_libraries(LanServer Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::HttpServer Qt${QT_VERSION_MAJOR}::Sql)

include(GNUInstallDirs)
install(TARGETS LanServer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
