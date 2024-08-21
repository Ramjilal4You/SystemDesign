#include "Logger.hxx"
#include <iostream>

int Logger::counter=0;
mutex Logger::mtx;
Logger* Logger::instance=nullptr;

Logger::Logger(){
    counter++;
    cout<<"Logger instance created : "<<counter<<endl;
}

Logger& Logger::GetLoggerInstance(){

    if(instance==nullptr)
    {
        mtx.lock();
        if(instance==nullptr){
            instance = new Logger();
        }
        mtx.unlock();
    }
    return *instance;
}

void Logger::Log(string str){
    cout<<str<<endl;
}