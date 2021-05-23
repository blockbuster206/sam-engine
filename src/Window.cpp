//
// Created by sam on 5/16/21.
//

#include "Window.h"
#include "Logger.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

SDL_Renderer* Window::renderer = nullptr;

Window::Window() {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        Logger::initialize("SubSystems");
        if (IMG_Init(IMG_INIT_PNG )) {
            Logger::initialize("Image");
        } else {
            Logger::error("Failed to Initialize Image");
        }
    } else {
        Logger::error("Failed to Initialize SubSystems");
    }
    // initialize the variables so errors dont happen
    window = nullptr;
}

void Window::createWindow(const char* title, int xPos, int yPos, int width, int height, bool fullscreen) {
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
void Window::doPollUpdates() {
    while (SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                running = false;
                break;
        }
    }
}
void Window::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

Window::~Window() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
};
