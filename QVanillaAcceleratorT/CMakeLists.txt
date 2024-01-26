project(QVanillaAcceleratorT)

set(SRC_FILES
    src/QVanillaAcceleratorT.cpp
)

add_library(${PROJECT_NAME} SHARED ${SRC_FILES})

ETISSPlugin(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC include)
