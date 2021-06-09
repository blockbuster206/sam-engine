//
// Created by sam on 5/16/21.
//

#include "Window.h"
#include "Logger.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

SDL_Renderer* Window::renderer = nullptr;
bool Window::running;

Window::Window() {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        Logger::initialize("Subsystems");
        if (IMG_Init(IMG_INIT_PNG )) {
            Logger::initialize("Image");
        } else {
            Logger::error("Failed to Initialize Image");
        }
    } else {
        Logger::error("Failed to Initialize Subsystems");
    }
    // initialize the variables so errors dont happen
    window = nullptr;
}

void Window::createWindow(const char* title, int xPos, int yPos, int width, int height) {
    window = SDL_CreateWindow(title, xPos, yPos, width, height, 0);
    if (window) {
        Logger::initialize("Window");

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
        if (renderer) {
            Logger::initialize("Renderer");
            running = true;

            Logger::log("Started main window");

        } else {
            Logger::error("Failed to Initialize Renderer");
        }
    } else {
        Logger::error("Failed to Initialize Window");
    }
}



void Window::clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Window::render() {
    SDL_RenderPresent(renderer);
}

void Window::setAttribute(Uint32 flag, bool enabled) {
    Uint32 windowFlags = SDL_GetWindowFlags(window);
    Uint32 availableFlags = SDL_WINDOW_FULLSCREEN;
    if(availableFlags & flag) {
        if(windowFlags & flag) {
            if(enabled) {
                Logger::errorAttribute(flag);
            } else {
                // this switch disables the attributes
                switch(flag) {
                    case SDL_WINDOW_FULLSCREEN:
                        SDL_SetWindowFullscreen(window, 0);
                        Logger::attribute(flag, false);
                }
            }
        } else {
            // this switch enabled the attributes
            switch(flag) {
                case SDL_WINDOW_FULLSCREEN:
                    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
                    Logger::attribute(flag, true);
            }
        }
    }
}

Window::~Window() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
};
