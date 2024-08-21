#include "Level3SupportHandler.hxx"

#include <iostream>
using namespace std;

void Level3Supporthandler::setNextSupportHandler(ISupporthandler* iHandler)
{
	nextHandler = iHandler;
}

void Level3Supporthandler::handleRequest(Request iRequest)
{
	if (iRequest.getPriority() == 3) {
		cout << "Level3Supporthandler :: Handling the request\n";
	}
	else {
		nextHandler->handleRequest(iRequest);
	}
}
