cmake_minimum_required(VERSION 3.16)
project(TextMAN LANGUAGES CXX)

# Enable Qt's automoc, autorcc, and autouic features
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Set C++ standard (C++14 or C++17 is better for Qt)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set Qt path (Make sure it's correct)
set(QT_DIR "C:/Qt/Qt5.5.1/5.5/mingw492_32")  # Adjust this path if needed
set(CMAKE_PREFIX_PATH ${QT_DIR})

# Find Qt packages
find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui)

# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/app
    ${CMAKE_CURRENT_SOURCE_DIR}/include/ui
)

# Collect source files
file(GLOB_RECURSE APP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/app/*.cpp")
file(GLOB_RECURSE UI_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/ui/*.cpp")
set(SOURCES
    ${APP_SOURCES}
    ${UI_SOURCES}
    "main.cpp"
)

# Collect header files
file(GLOB_RECURSE APP_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/app/*.h")
file(GLOB_RECURSE UI_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/ui/*.h")
set(HEADERS
    ${APP_HEADERS}
    ${UI_HEADERS}
)

set(RESOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/resource.rc)

# Create executable
add_executable(TextMAN ${SOURCES} ${HEADERS} ${RESOURCE_FILES})

# Add compiler definitions
target_compile_definitions(TextMAN PRIVATE
    _DEBUG
    UNICODE
    _UNICODE
)

# Link Qt libraries
target_link_libraries(TextMAN PRIVATE
    Qt5::Widgets
    Qt5::Core
    Qt5::Gui
)
