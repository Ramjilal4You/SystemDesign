#pragma once

#include "Constents.hxx"

#include <string>

using namespace std;

//Chain of responsibility interface
class AbstractLogger {
private:
	virtual void display(string msg) = 0;
protected:
	LOGLEVEL level;
	AbstractLogger* nextLogger;
public:
	void setNextLogger(AbstractLogger* iLogger)
	{
		nextLogger = iLogger;
	}

	void logMessage(LOGLEVEL iLevel, string msg)
	{
		if (level == iLevel) {
			display(msg);
		}
		else {
			nextLogger->logMessage(iLevel, msg);
		}
	}

	
};