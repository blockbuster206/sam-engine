//
// Created by sam on 5/22/21.
//

#include "TextureManager.h"

#include "Logger.h"
#include "Window.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"


Texture* TextureManager::load(const char* filepath) {
    Texture* texture = new Texture();
    SDL_Surface* tempSurface;
    tempSurface = IMG_Load(filepath);
    if (tempSurface) {
        texture->texture = SDL_CreateTextureFromSurface(Window::renderer, tempSurface);
        SDL_FreeSurface(tempSurface);
        if (texture->texture) {
            Logger::load(filepath);
            return texture;
        } else {
            Logger::errorLoad(filepath);
        }
    } else {
        Logger::errorLoad(filepath);
    }
}
