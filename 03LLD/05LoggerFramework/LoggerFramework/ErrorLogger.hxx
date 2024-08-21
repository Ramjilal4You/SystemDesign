#pragma once

#include "AbstractLogger.hxx"

class ErrorLogger : public AbstractLogger {
public:
	ErrorLogger(LOGLEVEL iLevel);
	void display(string msg);
};