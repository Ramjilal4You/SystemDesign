#pragma once

#include <string>
using namespace std;

#include "Ticket.hxx"

class Exit {
private:
	string exitGateId;
public:
	Exit(string eGate);
	void payAndLeave(Ticket* ticket);
};