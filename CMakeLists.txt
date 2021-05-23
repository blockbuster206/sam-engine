cmake_minimum_required(VERSION 3.19)
project(SAM_ENGINE)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/Build)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/Modules)

set(SOURCES "Examples/Snake/src/main.cpp" "src/Window.cpp" "include/Window.h" "src/Logger.cpp" "include/Logger.h" src/TextureManager.cpp include/TextureManager.h)


find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} "${CMAKE_CURRENT_LIST_DIR}/include")

add_executable(SAM_ENGINE ${SOURCES})

target_link_libraries(SAM_ENGINE -lSDL2main -lSDL2 -lSDL2_image)