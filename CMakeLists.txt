cmake_minimum_required(VERSION 3.19)
project(SAM_ENGINE)

project(Snake)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake-modules)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Build)

set(SOURCES
        #Window Files
        source/Window.cpp
        include/Window.h
        #Logger Files
        source/Logger.cpp
        include/Logger.h
        #Vector Files
        source/Vector2/Float.cpp
        include/Vector2/Float.h
        source/Vector2/Vector2i.cpp
        include/Vector2/Vector2i.h
        #Entity Files
        include/Managers/EntityManager.h

        source/Managers/TextureManager.cpp
        include/Managers/TextureManager.h

        include/Managers/EventManager.h
        source/Managers/GameManager.cpp include/Managers/GameManager.h source/Text.cpp include/Text.h)

#SDL2 Libraries
find_package(SDL2 REQUIRED)
#find_package(SDL2_net REQUIRED)
#find_package(SDL2_mixer REQUIRED)
find_package(SDL2_image REQUIRED)
#find_package(SDL2_gfx REQUIRED)
find_package(SDL2_ttf REQUIRED)

#SDL2::Main SDL2::Net SDL2::Mixer SDL2::Image SDL2::TTF SDL2::GFX
set(SDL2_LIBRARIES SDL2::Core SDL2::Main SDL2::Image SDL2::TTF)

set(LIBRARIES ${SDL2_LIBRARIES})
set(INCLUDE_DIRS ${SDL2_INCLUDE_DIR} include)

include_directories(${INCLUDE_DIRS})

add_library(SAM_ENGINE SHARED ${SOURCES})

add_executable(Snake Examples/Snake/main.cpp)

target_link_libraries(SAM_ENGINE ${LIBRARIES})
target_link_libraries(Snake SAM_ENGINE)