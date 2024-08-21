#include "Logger.hxx"
#include <thread>

void logger1(){
    Logger& lgr1 = Logger::GetLoggerInstance();

    lgr1.Log("Log info for logger 1\n");
}

void logger2(){
    Logger& lgr1 = Logger::GetLoggerInstance();

    lgr1.Log("Log info for logger 2\n");
}



int main(){

    thread t1(logger1);
    thread t2(logger2);

    t1.join();
    t2.join();


    return 0;
}