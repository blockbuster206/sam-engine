//
// Created by sam on 5/23/21.
//

#include "SDL.h"

#ifndef SAM_ENGINE_EVENTMANAGER_H
#define SAM_ENGINE_EVENTMANAGER_H


class EventManager {
    public:
        static void doEvents();
        static void addEventFunction();
    private:
        static SDL_Event event;


};


#endif //SAM_ENGINE_EVENTMANAGER_H
