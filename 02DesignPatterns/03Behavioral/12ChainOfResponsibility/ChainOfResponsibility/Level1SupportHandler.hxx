#pragma once
#include "ISupportHandler.hxx"

class Level1Supporthandler : public ISupporthandler {
public:
	void setNextSupportHandler(ISupporthandler* iHandler);
	void handleRequest(Request iRequest);
};