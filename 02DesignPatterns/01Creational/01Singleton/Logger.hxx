#ifndef LOGGER_HXX
#define LOGGER_HXX

#include <mutex>
#include <string>

using namespace std;

class Logger{
    private:
        static int counter;
        static Logger* instance;
        static mutex mtx;

        Logger();

    public:
        Logger(const Logger & ) = delete;
        Logger& operator=(const Logger&) = delete;
        //no need to explicitly delete move copy constructor & move assignment operator 

        static Logger& GetLoggerInstance();
        void Log(string str);
};

#endif //LOGGER_HXX