//
// Created by sam on 5/23/21.
//

#include "SDL.h"
#include "vector"
#include "iostream"
#include "Window.h"

#ifndef SAM_ENGINE_EVENTMANAGER_H
#define SAM_ENGINE_EVENTMANAGER_H

struct Event {
    void (*func)();
    std::string eventId;
};

static SDL_Event event;

class EventManager {
    public:
        void doEvents() {
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        Window::running = false;
                        break;
                }
            }
        }

        void doCustomEvents() {
            for(auto temp : customEvents) {
                temp.func();
            }
        }


        void addCustomEvent(std::string eventId, void (*func)()) {
            Event customEvent;

            customEvent.eventId = eventId;
            customEvent.func = func;
            customEvents.push_back(customEvent);
        }

    private:
        std::vector<Event> customEvents;
};




#endif //SAM_ENGINE_EVENTMANAGER_H
