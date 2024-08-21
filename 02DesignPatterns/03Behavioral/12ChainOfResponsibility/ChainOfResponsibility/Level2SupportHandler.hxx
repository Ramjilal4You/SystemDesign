#pragma once
#include "ISupportHandler.hxx"

class Level2Supporthandler : public ISupporthandler {
public:
	void setNextSupportHandler(ISupporthandler* iHandler);
	void handleRequest(Request iRequest);
};