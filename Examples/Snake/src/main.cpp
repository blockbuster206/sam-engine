#include <iostream>
#include "Window.h"
#include "TextureManager.h"

Window* window;


int main() {
    window = new Window();

    window->createWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, false);
    TextureManager::load("assets/lol.png");

    while (window->isRunning()) {
        window->doPollUpdates();

        window->render();
    }

    return EXIT_SUCCESS;
}
