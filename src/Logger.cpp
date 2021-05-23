//
// Created by sam on 5/22/21.
//

#include "Logger.h"
#include "iostream"
#include "SDL2/SDL.h"

void Logger::log(const char* message) {
    std::cout << "Log: " << message << std::endl;
}

void Logger::initialize(const char* initMessage) {
    std::cout << "Initialized: " << initMessage << std::endl;
}

void Logger::error(const char* errorMessage) {
    std::cout << "UH OH: " << errorMessage << "!" << SDL_GetError() << std::endl;
}

