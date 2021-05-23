//
// Created by sam on 5/23/21.
//

#include "Managers/EventManager.h"
#include "Window.h"
#include "SDL.h"

SDL_Event EventManager::event;

void EventManager::doEvents() {
    while (SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                Window::running = false;
                break;
        }
    }
}