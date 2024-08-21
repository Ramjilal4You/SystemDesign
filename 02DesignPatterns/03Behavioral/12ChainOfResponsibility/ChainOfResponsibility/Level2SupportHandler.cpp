#include "Level2SupportHandler.hxx"

#include <iostream>
using namespace std;

void Level2Supporthandler::setNextSupportHandler(ISupporthandler* iHandler)
{
	nextHandler = iHandler;
}

void Level2Supporthandler::handleRequest(Request iRequest)
{
	if (iRequest.getPriority() == 2) {
		cout << "Level2Supporthandler :: Handling the request\n";
	}
	else {
		nextHandler->handleRequest(iRequest);
	}
}
