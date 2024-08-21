#pragma once

#include "Constants.hxx"

#include <string>
using namespace std;

class Dispatcher {
	string dispatcherId;
public:
	~Dispatcher();
	Dispatcher(string id);
	string getDispatcherId();

	bool sendRequestToController(int dstFloor, DIRECTION direction);
	bool sendRequestToController(int dstFloor);
	bool sendRequestToController(DOORACTION doorAction);
};