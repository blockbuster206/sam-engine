//
// Created by sam on 5/22/21.
//

#include "SDL2/SDL.h"
#include "vulkan/vulkan.hpp"

#ifndef SAM_ENGINE_TEXTURE_H
#define SAM_ENGINE_TEXTURE_H

struct Texture {
    SDL_Texture* texture;
    SDL_Rect transformDetails;
    double angle;
    SDL_Point rotationPoint;
};

class TextureManager {
    public:
        static Texture* createTexture(const char* filepath, int width, int height);
        static void drawTexture(Texture* texture);
        static void setTexturePosition(Texture* texture, int x, int y);
        static void setTextureRotationPoint(Texture* texture, int xPos, int yPos);
        static void setTextureSize(Texture* texture, int width, int height);

        static void rotateTexture(Texture* texture, double angle);
};


#endif //SAM_ENGINE_TEXTURE_H
