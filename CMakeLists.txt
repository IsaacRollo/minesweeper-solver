cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(mine-sweeper)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/tile.cpp
    src/map.cpp
    src/main.cpp
)

set(HEADERS
    include/tile.h
    include/map.h  
)

add_executable(mine-sweeper ${SOURCES} ${HEADERS})

target_include_directories(mine-sweeper PRIVATE include)
