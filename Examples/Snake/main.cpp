#include <iostream>
#include "Window.h"
#include "Managers/TextureManager.h"
#include "Managers/EventManager.h"
#include "Vector2/Float.h"
#include "Logger.h"

Window* gameWindow;

EventManager eventManager;

Vector2f hello(50, 6);

int main() {
    gameWindow = new Window();

    gameWindow->createWindow("Snake", 800, 800);

    while (gameWindow->running) {
        eventManager.doEvents();

        std::cout << hello.x << std::endl;
        hello.add(Vector2f(1, 0));

        gameWindow->clear();
        gameWindow->render();
    }

    return EXIT_SUCCESS;
}
