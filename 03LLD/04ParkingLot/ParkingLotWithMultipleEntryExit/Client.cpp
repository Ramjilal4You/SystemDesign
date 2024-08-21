
#include "ParkingLot.hxx"
#include "ParkingFloor.hxx"
#include "ParkingSlot.hxx"
#include "Constants.hxx"

#include "VehicleInfo.hxx"
#include "Ticket.hxx"
#include "Display.hxx"

#include <windows.h>

#include <map>
#include <vector>
#include <iostream>
using namespace std;

ParkingFloor* getFloor(string floorName) {

	vector<ParkingSlot*> TwoWheelerSlotList = { new ParkingSlot(floorName+"_T01", TwoWheelerSlot), new ParkingSlot(floorName + "_T02", TwoWheelerSlot) };
	vector<ParkingSlot*> CompactSlotList = { new ParkingSlot(floorName + "_C01", CompactSlot) ,new ParkingSlot(floorName + "_C02", CompactSlot) };
	vector<ParkingSlot*> MediumSlotList = { new ParkingSlot(floorName + "_M01", MediumSlot) , new ParkingSlot(floorName + "_M02", MediumSlot) };
	vector<ParkingSlot*> LargeSlotList = { new ParkingSlot(floorName + "_L01", LargeSlot) , new ParkingSlot(floorName + "_L02", LargeSlot) };

	map<ParkingSlotType, vector<ParkingSlot*>> parkingSlotsMap1;

	parkingSlotsMap1.insert({ TwoWheelerSlot, TwoWheelerSlotList });
	parkingSlotsMap1.insert({ CompactSlot, CompactSlotList });
	parkingSlotsMap1.insert({ MediumSlot, MediumSlotList });
	parkingSlotsMap1.insert({ LargeSlot, LargeSlotList });

	ParkingFloor* floor = new ParkingFloor(floorName, parkingSlotsMap1);
	Display* display = new Display(floorName + "_Display");
	floor->setDisplay(display);

	return floor;
}

Ticket* requestparkingSlot(ParkingLot* parkinglot, VehicleInfo* vInfo)
{
	return parkinglot->getParkingTicket(vInfo);
}
void leaveParking(ParkingLot* parkinglot, Ticket* ticket)
{
	parkinglot->getParkingChargeAndPay(ticket);
}

void request1(ParkingLot* parkinglot, VehicleInfo* bike, Ticket* ticket) {
	ticket = requestparkingSlot(parkinglot, bike);
}

void request2(ParkingLot* parkinglot, VehicleInfo* bike, Ticket* ticket) {
	ticket = requestparkingSlot(parkinglot, bike);
}

void request3(ParkingLot* parkinglot, VehicleInfo* bike, Ticket* ticket) {
	ticket = requestparkingSlot(parkinglot, bike);
}


int main() {

	cout << "\n\n************ ParkingLotWithMultipleEntryExit ******************\n\n";

	ParkingFloor* floor0 = getFloor("Floor0");
	ParkingFloor* floor1 = getFloor("Floor1");
	vector<ParkingFloor*> floorList = { floor0 };
	ParkingLot* parkinglot = ParkingLot::getParkingLotInstance();
	parkinglot->setParkingLot("XYZ_name", "XYZ_Address", floorList);

	Entry* entry1 = new Entry("entryGate1");
	Entry* entry2 = new Entry("entryGate2");

	Exit* exit1 = new Exit("exitGate1");
	Exit* exit2 = new Exit("exitGate2");
	parkinglot->setEntryGateList({ entry1, entry2 });
	parkinglot->setExitGateList({ exit1, exit2 });


	//use case
	cout << "\n---- Testing ------\n\n";
	VehicleInfo* bike1 = new VehicleInfo("TS01XY0001", VehicleCategory::TwoWheeler);
	VehicleInfo* bike2 = new VehicleInfo("TS01XY0002", VehicleCategory::TwoWheeler);
	VehicleInfo* bike3 = new VehicleInfo("TS01XY0003", VehicleCategory::TwoWheeler);
	VehicleInfo* bike4 = new VehicleInfo("TS01XY0004", VehicleCategory::TwoWheeler);
	VehicleInfo* bus5 = new VehicleInfo("TS01XY0005", VehicleCategory::Bus);
	VehicleInfo* sedan6 = new VehicleInfo("TS01XY0006", VehicleCategory::Sedan);
	cout << "\n\n *** \n\n";
	Ticket* ticket1 = requestparkingSlot(parkinglot, bike1);
	if (ticket1)
		ticket1->ShowParkingTicketInfo();
	

	Ticket* ticket2 = requestparkingSlot(parkinglot, bike2);
	if (ticket2)
		ticket2->ShowParkingTicketInfo();

	parkinglot->showParkingLotStatus();

	Ticket* ticket3 = requestparkingSlot(parkinglot, bike3);
	if (ticket3)
		ticket3->ShowParkingTicketInfo();
	//leaveParking(parkinglot, ticket3);
	exit1->payAndLeave(ticket3);

	Ticket* ticket4 = requestparkingSlot(parkinglot, bus5);
	if (ticket4)
		ticket4->ShowParkingTicketInfo();

	Ticket* ticket5 = requestparkingSlot(parkinglot, sedan6);
	if (ticket5)
		ticket5->ShowParkingTicketInfo();

	Ticket* ticket6 = requestparkingSlot(parkinglot, bike4);
	if (ticket6)
		ticket6->ShowParkingTicketInfo();

	Sleep(20);

	parkinglot->showParkingLotStatus();

	//leaveParking(parkinglot, ticket6);
	exit1->payAndLeave(ticket6);

	parkinglot->showParkingLotStatus();

	/*leaveParking(parkinglot, ticket1);
	leaveParking(parkinglot, ticket2);

	leaveParking(parkinglot, ticket4);
	leaveParking(parkinglot, ticket5);*/
	exit2->payAndLeave(ticket1);
	exit1->payAndLeave(ticket2);
	exit2->payAndLeave(ticket4);
	exit1->payAndLeave(ticket5);
	parkinglot->showParkingLotStatus();

	/*
	cout << "\n\n\n";
	VehicleInfo* bike1 = new VehicleInfo("TS01XY0001", VehicleCategory::TwoWheeler);
	VehicleInfo* bike2 = new VehicleInfo("TS01XY0002", VehicleCategory::TwoWheeler);
	VehicleInfo* bike3 = new VehicleInfo("TS01XY0003", VehicleCategory::TwoWheeler);

	Ticket* ticket1 = nullptr, *ticket2 = nullptr, *ticket3 = nullptr;
	thread t1(request1, parkinglot, bike1, ticket1);
	thread t2(request2, parkinglot, bike2, ticket2);
	thread t3(request3, parkinglot, bike3, ticket3);
	t1.join();
	t2.join();
	t3.join();
	if (ticket1)
		ticket1->ShowParkingTicketInfo();
	if (ticket2)
		ticket2->ShowParkingTicketInfo();
	if (ticket3)
		ticket3->ShowParkingTicketInfo();

	leaveParking(parkinglot, ticket1);
	leaveParking(parkinglot, ticket3);
	leaveParking(parkinglot, ticket2);

	*/

	return 0;
}