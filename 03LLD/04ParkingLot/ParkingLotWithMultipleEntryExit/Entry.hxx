#pragma once

#include <string>
using namespace std;

#include "Ticket.hxx"
#include "VehicleInfo.hxx"



class Entry {
private:
	string entryGateId;
	Ticket* ticket;
public:
	Entry(string eGateId);
	Ticket* getParkingTicket(VehicleInfo* vehicle);	//entry time
};