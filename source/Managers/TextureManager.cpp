//
// Created by sam on 5/22/21.
//

#include "Managers/TextureManager.h"

#include "Logger.h"
#include "Window.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"


Texture* TextureManager::load(const char* filepath, int w, int h) {
    Texture* texture = new Texture();
    SDL_Surface* tempSurface;
    tempSurface = IMG_Load(filepath);
    if (tempSurface) {
        texture->texture = SDL_CreateTextureFromSurface(Window::renderer, tempSurface);
        SDL_FreeSurface(tempSurface);
        if (texture->texture) {
            Logger::load(filepath);

            texture->transformDetails.w = w;
            texture->transformDetails.h = h;
            return texture;
        } else {
            Logger::errorLoad(filepath);
        }
    } else {
        Logger::errorLoad(filepath);
    }
}

void TextureManager::draw(Texture* texture) {
    SDL_RenderCopy(Window::renderer, texture->texture, NULL, &texture->transformDetails);
}
