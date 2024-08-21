#include "InfoLogger.hxx"

#include <iostream>
using namespace std;

InfoLogger::InfoLogger(LOGLEVEL iLevel)
{
	level = iLevel;
}

void InfoLogger::display(string msg)
{
	cout << "INFO : " + msg << endl << "InfoLogger::display(string msg)\n";
}
