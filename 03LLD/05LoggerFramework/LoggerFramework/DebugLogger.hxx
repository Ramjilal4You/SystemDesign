#pragma once
#include "AbstractLogger.hxx"

class DebugLogger : public AbstractLogger {
public:
	DebugLogger(LOGLEVEL iLevel);
	void display(string msg);
};