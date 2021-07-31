cmake_minimum_required(VERSION 3.18)
project(SAM_ENGINE)

project(Saminater)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake-modules)
set(CMAKE_EXE_LINKER_FLAGS)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Build)


file(COPY ${CMAKE_CURRENT_LIST_DIR}/Examples/Saminater/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Build)


set(LIBRARIES ${SDL2_LIBRARIES})
set(INCLUDE_DIRS ${SDL2_INCLUDE_DIR} include)

include_directories(${INCLUDE_DIRS})


add_executable(Saminater Examples/Saminater/main.cpp)

target_link_libraries(Saminater SAM_ENGINE -static-libgcc)