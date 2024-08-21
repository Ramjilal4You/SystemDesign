#include "Level1SupportHandler.hxx"


#include <iostream>
using namespace std;

void Level1Supporthandler::setNextSupportHandler(ISupporthandler* iHandler)
{
	nextHandler = iHandler;
}

void Level1Supporthandler::handleRequest(Request iRequest)
{
	if (iRequest.getPriority() == 1) {
		cout << "Level1Supporthandler :: Handling the request\n";
	}
	else {
		nextHandler->handleRequest(iRequest);
	}
}
