#pragma once

#include <string>
#include <map>
#include <vector>
using namespace std;

#include "ParkingSlot.hxx"
#include "Display.hxx"

class ParkingFloor {
private:
	string floorName;
			   //<slotType   <slotName, Slot obj>>
	map<ParkingSlotType, vector<ParkingSlot*>> parkingSlotList;
	Display* display;

	ParkingSlotType getCorrectParkingSlot(VehicleCategory vCategory);
	vector<ParkingSlot*> getRelaventParkingSlotList(VehicleCategory vCategory);
	ParkingSlot* getBestSuitableParkingSlot(vector<ParkingSlot*> relaventParkingSlotList);
public:
	ParkingFloor(string name, map<ParkingSlotType, vector<ParkingSlot*>> slotList);
	ParkingSlot* getParkingSlotForVehicleAndPark(VehicleInfo* vehicle);
	void setDisplay(Display* iDisplay);
	Display* getDisplay();

	map<ParkingSlotType, vector<ParkingSlot*>> getParkingSlotList();
};