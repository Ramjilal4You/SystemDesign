#pragma once

#include <string>
#include <map>
#include <vector>
using namespace std;

#include "ParkingSlot.hxx"

class ParkingFloor {
private:
	string floorName;
			   //<slotType   <slotName, Slot obj>>
	map<ParkingSlotType, vector<ParkingSlot*>> parkingSlotList;

	ParkingSlotType getCorrectParkingSlot(VehicleCategory vCategory);
	vector<ParkingSlot*> getRelaventParkingSlotList(VehicleCategory vCategory);
	ParkingSlot* getBestSuitableParkingSlot(vector<ParkingSlot*> relaventParkingSlotList);
public:
	ParkingFloor(string name, map<ParkingSlotType, vector<ParkingSlot*>> slotList);
	ParkingSlot* getParkingSlotForVehicleAndPark(VehicleInfo* vehicle);
};