#pragma once
#include "ISupportHandler.hxx"

class Level3Supporthandler : public ISupporthandler {
public:
	void setNextSupportHandler(ISupporthandler* iHandler);
	void handleRequest(Request iRequest);
};