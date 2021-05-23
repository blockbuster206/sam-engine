//
// Created by sam on 5/22/21.
//

#ifndef ALTERA_ENGINE_LOGGER_H
#define ALTERA_ENGINE_LOGGER_H



class Logger {
    public:
        static void log(const char* message);
        static void initialize(const char* initMessage);

        static void load(const char* filepath);
        static void errorLoad(const char* filepath);

        static void error(const char* errorMessage);
};


#endif //ALTERA_ENGINE_LOGGER_H
