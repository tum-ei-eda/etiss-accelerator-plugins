project(QVanillaAccelerator)

cmake_minimum_required(VERSION 3.18)

set(SRC_FILES
    src/QVanillaAccelerator.cpp
    src/Plugin.cpp
)

find_package(ETISS REQUIRED)

add_library(${PROJECT_NAME} SHARED ${SRC_FILES})

ETISSPlugin(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC include)
