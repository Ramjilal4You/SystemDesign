#pragma once
#include "ISupportHandler.hxx"

class DefaultSupporthandler : public ISupporthandler {
public:
	void setNextSupportHandler(ISupporthandler* iHandler);
	void handleRequest(Request iRequest);
};