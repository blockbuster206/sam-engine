#include <iostream>
#include "Window.h"
#include "Managers/TextureManager.h"
#include "Managers/EventManager.h"

Window* window;

EventManager eventManager;

int main() {
    window = new Window();

    window->createWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, false);
    Texture* lol = TextureManager::load("assets/lol.png", 100, 100);

    lol->transformDetails.x = 0;
    lol->transformDetails.y = 0;

    SDL_ShowCursor(0);
    int x, y;

    while (window->running) {
        eventManager.doEvents();

        window->clear();

        SDL_GetMouseState(&x, &y);
        lol->transformDetails.x = x - lol->transformDetails.w/2;
        lol->transformDetails.y = y - lol->transformDetails.h/2;

        TextureManager::draw(lol);

        window->render();
    }

    return EXIT_SUCCESS;
}
