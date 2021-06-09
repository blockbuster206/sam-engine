//
// Created by sam on 5/22/21.
//

#include "SDL.h"

#ifndef ALTERA_ENGINE_LOGGER_H
#define ALTERA_ENGINE_LOGGER_H



class Logger {
    public:
        static void log(const char* message);
        static void initialize(const char* initMessage);

        static void texture(const char* filepath);
        static void errorTexture(const char* filepath);

        static void attribute(Uint32 flag, bool enabled);
        static void errorAttribute(Uint32 flag);

        static void error(const char* errorMessage);
};


#endif //ALTERA_ENGINE_LOGGER_H
