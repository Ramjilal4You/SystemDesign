#pragma once

#include <string>
#include <vector>
#include <mutex>

using namespace std;

#include "ParkingFloor.hxx"
#include "Ticket.hxx"

class ParkingLot {
	string ParkingLotName;
	string ParkingLotAddress;

	vector<ParkingFloor*> floorList;
	//vector<EntryGate*> entryList;
	//vector<ExitGate*> exitList;

	static ParkingLot* instance;
	static mutex mtx;
	ParkingLot(string name, string address, vector<ParkingFloor*> floors);
	ParkingLot(const ParkingLot&) = default;
	ParkingLot& operator=(const ParkingLot&) = default;

	double getParkingCharges(int parkingTime, ParkingSlotType slotType);
public:
	
	static ParkingLot* getParkingLotInstance(string name, string address, vector<ParkingFloor*> floors) {
		if (instance == nullptr) {
			mtx.lock();
			if (instance == nullptr) {
				instance = new ParkingLot(name, address, floors);
			}
			mtx.unlock();
		}
		return instance;
	}

	Ticket* getParkingTicket(VehicleInfo* vehicle);	//entry time
	double getParkingChargeAndPay(Ticket* ticket);	//exit time

};