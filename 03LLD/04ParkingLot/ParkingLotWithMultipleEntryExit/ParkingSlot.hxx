#pragma once

#include <string>
using namespace std;

#include "Constants.hxx"
#include "VehicleInfo.hxx"

class ParkingSlot {
private:
	string slotNumber;
	bool slotAvailable;
	ParkingSlotType slotType;

	VehicleInfo* vehicleInfo;
public:
	ParkingSlot(string sNumber, ParkingSlotType sType);
	void parkVehicle(VehicleInfo* vehicle);
	void removeVehicle();

	void setparkingSlotStatus(bool status);
	bool getParkingSlotStatus();
	ParkingSlotType getParkingSlotType();
	string getParkingSlotNumber();
};