#cmake

cmake_minimum_required(VERSION 3.5)

project(concentration)

option(set_clang "set clang as default compiler" 0)
option(cros_compile "cros compile for win32" 0)

if(${UNIX})
    message(STATUS "Unix system")
elseif(${WIN32})
    message(WARNING "Work is not guaranted")
else()
    message(FATAL_ERROR "System not supported")
endif()

if(set_clang)
    set(CMAKE_CXX_COMPILER clang++)
endif()
if(cros_compile)
    set(PROJECT_NAME ${PROJECT_NAME}.exe)
    set(CMAKE_CXX_COMPILER i686-w64-mingw32-g++-posix)
    set(CMAKE_CXX_FLAGS "-static-libstdc++ -static-libgcc")
endif()

message(STATUS ${PROJECT_NAME})
message(STATUS ${CMAKE_CXX_COMPILER})

add_definitions(-Wall -std=c++14)

include_directories(include)

set(MAIN_SRC sources/main.cpp)
file(GLOB CONCENTRATION_SRC "sources/concentration/*.cpp")

if(cros_compile)
    find_package(PDCurses REQUIRED)
else()
    find_package(Curses REQUIRED)
endif()

include_directories(${CURSES_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${MAIN_SRC} ${CONCENTRATION_SRC})

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})
