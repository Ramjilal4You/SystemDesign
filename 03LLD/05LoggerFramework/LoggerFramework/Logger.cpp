#include "Logger.hxx"
#include "Factory.hxx"

#include <iostream>
using namespace std;

AbstractLogger* Logger::chainOflogger = nullptr;

Logger* Logger::instance = nullptr;
mutex Logger::mtx;

Logger* Logger::getLoggerInstance() 
{
	if (instance == nullptr) {
		mtx.lock();
		if (instance == nullptr) {
			instance = new Logger();
			chainOflogger = Factory::buildChainOfLogger();
		}
		mtx.unlock();
	}
	return instance;
}

void Logger::log(LOGLEVEL level, string msg)
{
	mtx.lock();
	chainOflogger->logMessage(level, msg);
	mtx.unlock();
}
