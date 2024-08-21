#pragma once

#include "Constents.hxx"
#include "AbstractLogger.hxx"
#include "InfoLogger.hxx"
#include "DebugLogger.hxx"
#include "ErrorLogger.hxx"

class Factory {
public:
	static AbstractLogger* buildChainOfLogger() {
		InfoLogger* infologger = new InfoLogger(INFO);
		DebugLogger* debuglogger = new DebugLogger(DEBUG);
		ErrorLogger* errorlogger = new ErrorLogger(ERROR);

		errorlogger->setNextLogger(debuglogger);
		debuglogger->setNextLogger(infologger);
		infologger->setNextLogger(nullptr);
		

		return errorlogger;
	}
};