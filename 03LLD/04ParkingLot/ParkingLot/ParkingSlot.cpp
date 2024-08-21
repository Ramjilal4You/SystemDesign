#include "ParkingSlot.hxx"

#include <iostream>
using namespace std;

ParkingSlot::ParkingSlot(string sNumber, ParkingSlotType sType)
{
	slotNumber = sNumber;
	slotAvailable = true;
	slotType = sType;
	vehicleInfo = nullptr;
	cout << "ParkingSlot Created : slotNumber - " << slotNumber << " slotType - " << slotType << "\n";
}

void ParkingSlot::parkVehicle(VehicleInfo* vehicle)
{
	vehicleInfo = vehicle;
	slotAvailable = false;
}

void ParkingSlot::removeVehicle()
{
	vehicleInfo = nullptr;
	setparkingSlotStatus(true);
}

bool ParkingSlot::getParkingSlotStatus()
{
	return slotAvailable;
}

void ParkingSlot::setparkingSlotStatus(bool status)
{
	slotAvailable = status;
}

ParkingSlotType ParkingSlot::getParkingSlotType()
{
	return slotType;
}

string ParkingSlot::getParkingSlotNumber()
{
	return slotNumber;
}
