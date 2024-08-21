/* Chain Of Responsibility */

#include "ISupportHandler.hxx"
#include "Level1SupportHandler.hxx"
#include "Level2SupportHandler.hxx"
#include "Level3SupportHandler.hxx"
#include "DefaultSupportHandler.hxx"


//this function will build handle instance & do the chaining 
ISupporthandler* buildSupporthandler() {
	Level1Supporthandler* level1Handler = new Level1Supporthandler();
	Level2Supporthandler* level2Handler = new Level2Supporthandler();
	Level3Supporthandler* level3Handler = new Level3Supporthandler();
	DefaultSupporthandler* defaultHandler = new DefaultSupporthandler();

	level1Handler->setNextSupportHandler(level2Handler);
	level2Handler->setNextSupportHandler(level3Handler);
	level3Handler->setNextSupportHandler(defaultHandler);
	defaultHandler->setNextSupportHandler(nullptr);

	return level1Handler;
}

int main() {

	ISupporthandler* supportHandler = buildSupporthandler();

	Request req1(1), req2(2), req3(3), req4(4);
	//supportHandler->handleRequest(req1);
	//supportHandler->handleRequest(req2);
	//supportHandler->handleRequest(req3);
	supportHandler->handleRequest(req4);


	return 0;
}