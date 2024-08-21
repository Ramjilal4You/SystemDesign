#include "ErrorLogger.hxx"

#include <iostream>
using namespace std;

ErrorLogger::ErrorLogger(LOGLEVEL iLevel)
{
	level = iLevel;
}

void ErrorLogger::display(string msg)
{
	cout << "ERROR : " + msg << endl << "ErrorLogger::display(string msg)" << endl;
}