/* Logger Framework

**	Application -> Logger --> (log level : INFO, DEBUG, ERROR) --> (Sink : Console, File, Database)
**	Requirements
*	1. Log level --> INFO, DEBUG, ERROR
*	2. Sink (Where to log) --> Console, File, Database

**	DesignPatterns -> Singleton, Chain Of Responsibility, Observer
*/

#pragma once

#include "Constents.hxx"
#include "AbstractLogger.hxx"

#include <mutex>
#include <string>

using namespace std;


class Logger {
private:
	static AbstractLogger* chainOflogger;

	static Logger* instance;
	static mutex mtx;
	Logger() = default;
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;
public:
	static Logger* getLoggerInstance();

	void log(LOGLEVEL level, string msg);

};