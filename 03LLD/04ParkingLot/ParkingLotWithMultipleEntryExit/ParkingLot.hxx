#pragma once

#include <string>
#include <vector>
#include <mutex>

using namespace std;

#include "ParkingFloor.hxx"
#include "Ticket.hxx"
#include "Entry.hxx"
#include "Exit.hxx"

class ParkingLot {
	string ParkingLotName;
	string ParkingLotAddress;

	vector<ParkingFloor*> floorList;
	vector<Entry*> entryList;
	vector<Exit*> exitList;

	static ParkingLot* instance;
	static mutex mtx;
	ParkingLot() = default;
	ParkingLot(const ParkingLot&) = default;
	ParkingLot& operator=(const ParkingLot&) = default;

	double getParkingCharges(int parkingTime, ParkingSlotType slotType);
	void updateParkingDisplaySlotStausInfo(ParkingSlot slot);
public:
	void setParkingLot(string name, string address, vector<ParkingFloor*> floors);
	static ParkingLot* getParkingLotInstance();

	void setEntryGateList(vector<Entry*> eGateList);
	vector<Entry*> getEntryGateList();

	void setExitGateList(vector<Exit*> eGateList);
	vector<Exit*> getExitGateList();

	Ticket* getParkingTicket(VehicleInfo* vehicle);	//entry time
	double getParkingChargeAndPay(Ticket* ticket);	//exit time

	void showParkingLotStatus();
	void updateDisplayConfiguration();

};