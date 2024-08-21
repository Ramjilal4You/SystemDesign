#pragma once

#include "AbstractLogger.hxx"

class InfoLogger : public AbstractLogger {
public:
	InfoLogger(LOGLEVEL iLevel);
	void display(string msg);
};