#include "DefaultSupportHandler.hxx"

#include <iostream>
using namespace std;

void DefaultSupporthandler::setNextSupportHandler(ISupporthandler* iHandler)
{
	nextHandler = iHandler;
}

void DefaultSupporthandler::handleRequest(Request iRequest)
{
	cout << "DefaultSupporthandler :: Handling the request\n";
}