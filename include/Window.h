//
// Created by sam on 5/16/21.
//

#ifndef ALTERA_ENGINE_WINDOW_H
#define ALTERA_ENGINE_WINDOW_H

#include "SDL2/SDL.h"


class Window {
    public:
        Window();

        void createWindow(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
        void doPollUpdates();
        void render();

        bool isRunning() {return running;}

        ~Window();

        static SDL_Renderer* renderer;

    private:
        SDL_Window* window;
        SDL_Event event;

        bool running;

};


#endif //ALTERA_ENGINE_WINDOW_H
