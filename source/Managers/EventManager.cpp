//
// Created by samscv on 10/07/2021.
//
#include "Managers/EventManager.h"
#include "vector"
#include "Window.h"
#include "algorithm"
#include "Logger.h"

void EventManager::doEvents() {
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                Window::running = false;
                break;
        }
    }
}

void EventManager::doCustomEvents() {
    for(auto func : customEvents) {
        func(event);
    }
}

void EventManager::addCustomEvent(void (*func)(SDL_Event event)) {
    if (std::find(customEvents.begin(), customEvents.end(), func) == customEvents.end()) {
        customEvents.push_back(func);
    } else { Logger::error("You have already added that function"); }
}

void EventManager::removeCustomEvent(void (*func)(SDL_Event event)) {
    std::vector<void (*)(SDL_Event event)>::iterator find_func = std::find(customEvents.begin(), customEvents.end(), func);
    if (find_func != customEvents.end()) {
        int index = std::distance(customEvents.begin(), find_func);
        customEvents.erase(customEvents.begin() + index);
    }
}

