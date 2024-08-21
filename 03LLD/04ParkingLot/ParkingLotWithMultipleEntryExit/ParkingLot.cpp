// Parking Lot System
/*
**	Requirements - 
*	1. multiple floors, multiple type of parking spots
*	2. multiple entry & exit
*	3. charges - hourly

**	Actors/Classes
*	1. ParkingLot (Main class) <>-- (list of Floors, payment)
*	2. Floor <>-- (ParkingSlot, , Display etc )
*	3. ParkingSlot <>-- (ParkingSlotCategory, Vehicle)
*	4. Payment
*	5. Ticket
*	6. Vehicle <>-- VehicleCategory
*	7. ParkingSlotType
* 
**	Use case
*	1. User can ask for parking ticket
*	2. User can get/denied on the parking slot availablity
*	3. User can park the vehicle
*	4. User can pay the charges & go
* 
* 
*/

#include "ParkingLot.hxx"

#include <iostream>
using namespace std;

ParkingLot* ParkingLot::instance = nullptr;
mutex ParkingLot::mtx;

void ParkingLot::setParkingLot(string name, string address, vector<ParkingFloor*> floors)
{
	ParkingLotName = name;
	ParkingLotAddress = address;
	floorList = floors;

	updateDisplayConfiguration();

	cout << "ParkingLot Created : " << ParkingLotName << endl;
}

ParkingLot* ParkingLot::getParkingLotInstance()
{
	if (instance == nullptr) {
		mtx.lock();
		if (instance == nullptr) {
			instance = new ParkingLot();
		}
		mtx.unlock();
	}
	return instance;
}

void ParkingLot::setEntryGateList(vector<Entry*> eGateList) {	entryList = eGateList;	}
vector<Entry*> ParkingLot::getEntryGateList() {		return entryList;	}

void ParkingLot::setExitGateList(vector<Exit*> eGateList) {		exitList = eGateList;	 }
vector<Exit*> ParkingLot::getExitGateList() {	return exitList;	}


Ticket* ParkingLot::getParkingTicket(VehicleInfo* vehicle)
{
	//TODO : make this thread safe
	ParkingSlot* slot = nullptr;
	for (auto it : floorList) {
		slot = it->getParkingSlotForVehicleAndPark(vehicle);

		if (slot != nullptr) {
			it->getDisplay()->updateParkingDisplaySlotStaus(*slot);//update display database
			break;
		}
	}
	if (slot == nullptr) {
		cout << "Parking is full\n\n";
		return nullptr;
	}

	
	Ticket* ticket = new Ticket(slot, vehicle);

	return ticket;
}


double ParkingLot::getParkingCharges(int parkingTime, ParkingSlotType slotType)
{
	double amount = 0.0;
	if (slotType == TwoWheelerSlot) {
		amount = parkingTime * 20;
	}
	else if (slotType == CompactSlot) {
		amount = parkingTime * 40;
	}
	else if (slotType == MediumSlot) {
		amount = parkingTime * 100;
	}
	else if (slotType == LargeSlot) {
		amount = parkingTime * 200;
	}
	return amount;
}

double ParkingLot::getParkingChargeAndPay(Ticket* ticket)
{
	ParkingLot* parkinglot = ParkingLot::getParkingLotInstance();

	double amount = 0.0;
	if (ticket) {
		ticket->getParkingSlot()->removeVehicle();	//remove vehicle
		double parkingDuration = ticket->getParkingDuration();
		ParkingSlotType stype = ticket->getParkingSlot()->getParkingSlotType();
		amount = getParkingCharges(parkingDuration, stype);
		cout << "Leaving Vehicle : " << ticket->getVehicleInfo()->getVehicleNumber();
		cout << "Parking Charge Paid Successfully : " << amount << endl;

		updateParkingDisplaySlotStausInfo(*ticket->getParkingSlot());
	}
	else {
		cout << "Not a Valid Ticket\n\n";
	}
	return amount;
}

void ParkingLot::updateParkingDisplaySlotStausInfo(ParkingSlot slot)
{
	for (auto it : floorList) {
		it->getDisplay()->updateParkingDisplaySlotStaus(slot); //update display database
	}
}

void ParkingLot::showParkingLotStatus()
{
	for (auto it : floorList) {	
		it->getDisplay()->showParkingDisplayInfo();
	}
}

void ParkingLot::updateDisplayConfiguration()
{
	for (auto it : floorList) {
		for (auto it1 : it->getParkingSlotList()) {
			for (auto it2 : it1.second) {
				it->getDisplay()->configDisplay(*it2);
			}
		}

	}
}
