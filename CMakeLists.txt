cmake_minimum_required(VERSION 3.19)
project(SAM_ENGINE)
project(Snake)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake-modules)

set(SOURCES
        source/Window.cpp
        include/Window.h
        source/Logger.cpp
        include/Logger.h
        source/Managers/TextureManager.cpp
        include/Managers/TextureManager.h
        include/Managers/EventManager.h
        source/Vector2/Float.cpp
        include/Vector2/Float.h
        source/Vector2/Vector2i.cpp
        include/Vector2/Vector2i.h
        source/Managers/EntityManager.cpp
        include/Managers/EntityManager.h
        )


find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} "${CMAKE_CURRENT_LIST_DIR}/include")

add_library(SAM_ENGINE ${SOURCES})
add_executable(Snake Examples/Snake/main.cpp)

target_link_libraries(SAM_ENGINE -lSDL2main -lSDL2 -lSDL2_image)
target_link_libraries(Snake SAM_ENGINE)