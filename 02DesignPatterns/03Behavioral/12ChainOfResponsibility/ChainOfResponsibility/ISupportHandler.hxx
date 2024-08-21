#pragma once
#include "Request.hxx"

class ISupporthandler {
protected:
	ISupporthandler* nextHandler;
public:
	virtual void setNextSupportHandler(ISupporthandler* iHandler) = 0;
	virtual void handleRequest(Request iRequest) = 0;
};