//
// Created by sam on 5/23/21.
//

#include "SDL2/SDL.h"
#include "vector"

#ifndef SAM_ENGINE_EVENTMANAGER_H
#define SAM_ENGINE_EVENTMANAGER_H

class EventManager {
    public:
        void doEvents();
        void doCustomEvents();
        void addCustomEvent(void (*func)(SDL_Event event));
        void removeCustomEvent(void (*func)(SDL_Event event));

    private:
        std::vector<void (*)(SDL_Event event)> customEvents;
        SDL_Event event;
};




#endif //SAM_ENGINE_EVENTMANAGER_H
