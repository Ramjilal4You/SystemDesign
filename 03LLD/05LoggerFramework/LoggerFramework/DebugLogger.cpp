#include "DebugLogger.hxx"

#include <iostream>

using namespace std;

DebugLogger::DebugLogger(LOGLEVEL iLevel)
{
	level = iLevel;
}

void DebugLogger::display(string msg)
{
	cout << "DEBUG : " + msg << endl << "DebugLogger::display(string msg)" << endl;
}

