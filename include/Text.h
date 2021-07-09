//
// Created by samscv on 8/07/2021.
//

#include "Managers/TextureManager.h"
#include "iostream"

#ifndef SNAKE_TEXT_H
#define SNAKE_TEXT_H


class TextManager {
    public:
        static Texture* createText(std::string text, Uint32 r, Uint32 g, Uint32 b, Uint32 a);


};


#endif //SNAKE_TEXT_H
