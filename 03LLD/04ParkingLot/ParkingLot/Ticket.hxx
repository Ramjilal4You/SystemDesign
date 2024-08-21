#pragma once

#include <string>

#include <chrono>
#include <ctime>
using namespace std;

#include "ParkingSlot.hxx"
#include "VehicleInfo.hxx"

class Ticket {
private:
	int ticketId;
	chrono::time_point<chrono::system_clock> entryTime;
	ParkingSlot* parkingSlot;
	VehicleInfo* vehicleInfo;
public:
	Ticket(ParkingSlot* pSlot, VehicleInfo* vInfo);
	void ShowParkingTicketInfo();
	double getParkingDuration();
	ParkingSlot* getParkingSlot();
	VehicleInfo* getVehicleInfo();
};