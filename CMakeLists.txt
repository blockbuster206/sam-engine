cmake_minimum_required(VERSION 3.19)
project(ALTERA_ENGINE)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/Build")
set(CMAKE_MODULE_PATH Modules)

set(SOURCES ${CMAKE_CURRENT_LIST_DIR}/main.cpp)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})

add_executable(ALTERA_ENGINE ${SOURCES})

target_link_libraries(ALTERA_ENGINE -lSDL2main -lSDL2)