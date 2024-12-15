cmake_minimum_required(VERSION 3.16)

project(
    console-app
    VERSION 0.0.1
    LANGUAGES CXX C
)

# if(NOT TARGET spdlog)
#     # Stand-alone build
#     find_package(spdlog REQUIRED)
# endif()

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/perfparser/cmake/ ${CMAKE_CURRENT_SOURCE_DIR}/cmake/
                      ${CMAKE_MODULE_PATH}
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(QT6_BUILD "configure build to use Qt6/KF6" ON)

if(QT6_BUILD)
    set(QT_MAJOR_VERSION 6)
    set(QT_MIN_VERSION 6.4)
    set(KDDW_SUFFIX "-qt6")
else()
    set(QT_MAJOR_VERSION 5)
    set(QT_MIN_VERSION 5.15)
    set(KDDW_SUFFIX "")
endif()

# Enable the test harness
enable_testing()

find_package(
    Qt${QT_MAJOR_VERSION} ${QT_MIN_VERSION}
    COMPONENTS Core
               Widgets
               Network
               Test
    REQUIRED
)

find_package(ECM 1.0.0 NO_MODULE REQUIRED)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR})
find_package(
    KF${QT_MAJOR_VERSION} 5.42.0
    COMPONENTS ThreadWeaver
    REQUIRED
)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# submodule for log
add_subdirectory(3rdparty/spdlog)

# submodule for unit test
add_subdirectory(3rdparty/googletest)

add_subdirectory(src)

add_subdirectory(tests)

