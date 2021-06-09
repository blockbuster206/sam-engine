//
// Created by sam on 5/22/21.
//

#include "SDL2/SDL.h"

#ifndef SAM_ENGINE_TEXTURE_H
#define SAM_ENGINE_TEXTURE_H

struct Texture {
    SDL_Texture* texture;
    SDL_Rect transformDetails;
};

class TextureManager {
    public:
        static Texture* createTexture(const char* filepath, int width, int height);
        static void drawTexture(Texture* texture);
};


#endif //SAM_ENGINE_TEXTURE_H
