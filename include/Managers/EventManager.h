//
// Created by sam on 5/23/21.
//

#include "SDL.h"
#include "vector"
#include "iostream"

#ifndef SAM_ENGINE_EVENTMANAGER_H
#define SAM_ENGINE_EVENTMANAGER_H

struct Event {

};


class EventManager {
    public:
        static void doEvents();
        //template<typename func> static void addCustomEvent();

        // put events here for now
;

    private:
        static SDL_Event event;
        static std::vector<void> customEvents;


};


#endif //SAM_ENGINE_EVENTMANAGER_H
