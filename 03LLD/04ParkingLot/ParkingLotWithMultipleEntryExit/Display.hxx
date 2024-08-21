#pragma once

#include <vector>
#include <iostream>
using namespace std;

#include "ParkingSlot.hxx"

class Display {
	string displayId;
	vector<ParkingSlot> slots;

public:
	Display(string id);
	void updateParkingDisplaySlotStaus(ParkingSlot slot);
	void showParkingDisplayInfo();
	void configDisplay(ParkingSlot slot);
};