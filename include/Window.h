//
// Created by sam on 5/16/21.
//
#include "SDL2/SDL.h"

#ifndef ALTERA_ENGINE_WINDOW_H
#define ALTERA_ENGINE_WINDOW_H




class Window {
    public:
        Window();

        void createWindow(const char* title, int width, int height);
        void clear();
        void render();

        void setAttribute(Uint32 flag, bool enabled);

        ~Window();

        static SDL_Renderer* renderer;
        static bool running;

    private:
        SDL_Window* window;

};


#endif //ALTERA_ENGINE_WINDOW_H
