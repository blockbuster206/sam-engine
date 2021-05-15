#include <iostream>
#include "SDL2/SDL.h"

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event event;

bool running;

int main() {
    window = SDL_CreateWindow("SAM is Gya", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 320, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

    running = true;

    while(running) {
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }
    }



    return 0;
}
