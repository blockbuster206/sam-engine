#include <iostream>
#include "Window.h"
#include "Managers/TextureManager.h"
#include "Managers/EventManager.h"
#include "Vector2/Float.h"
#include "Logger.h"

Window* gameWindow;

EventManager eventManager;

Texture* optical;

double amount;
double cool;
bool space_init;

void up(SDL_Event event);

int main(int argc, char *argv[]) {

    gameWindow = Window::createWindow("Saminater", 800, 800);

    optical = TextureManager::createTexture("assets/images/ro.jpg", 1000, 1000);
    TextureManager::setTextureRotationPoint(optical, optical->transformDetails.w/2, optical->transformDetails.h/2);
    TextureManager::setTexturePosition(optical, 800/2-optical->transformDetails.w/2, 800/2-optical->transformDetails.h/2);

    eventManager.addCustomEvent(up);

    amount = 0;
    cool = 0;

    while (gameWindow->running) {
        eventManager.doEvents();

        eventManager.doCustomEvents();

        gameWindow->clear();


        if (space_init) {
            TextureManager::setTextureSize(optical, 700, 700);
            if (cool <= 10000) {
                amount = -100;
                if (cool <= 100 && cool >= 0) {
                    TextureManager::setTextureSize(optical, 1000, 1000);
                    space_init = false;
                    cool = 0.2;
                    amount = 0;
                }
            } if (cool == 0) {
                amount = 0;
                cool = 0.2;
            }
            cool += amount;

        } else {
            cool += amount+0.1;
        }

        //std::cout << "cool: " << cool << ", amount: " << amount << ", space_init: " << space_init << std::endl;

        TextureManager::rotateTexture(optical,cool);
        TextureManager::drawTexture(optical);


        gameWindow->render();
    }

    return EXIT_SUCCESS;
}

void up(SDL_Event event) {
        if (event.key.type == SDL_KEYDOWN) {
            if (!space_init) {
                if (event.key.keysym.sym == SDLK_UP) {
                    amount += 0.1;
                }

                if (event.key.keysym.sym == SDLK_DOWN) {
                    amount -= 0.1;
                }

                if (event.key.keysym.sym == SDLK_LEFT) {
                    if (cool <= 0) {
                        space_init = true;
                        amount = 100;
                    } else if (cool >= 100) {
                        space_init = true;
                        amount = -100;
                        if (cool >= 100000) {
                            amount = -1000;
                        }
                    }
                }
            }
        }
}
