
#include "ParkingLot.hxx"
#include "ParkingFloor.hxx"
#include "ParkingSlot.hxx"
#include "Constants.hxx"

#include "VehicleInfo.hxx"
#include "Ticket.hxx"


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

	return new ParkingFloor(floorName, parkingSlotsMap1);
}

Ticket* requestparkingSlot(ParkingLot* parkinglot, VehicleInfo* vInfo)
{
	return parkinglot->getParkingTicket(vInfo);
}
void leaveParking(ParkingLot* parkinglot, Ticket* ticket)
{
	parkinglot->getParkingChargeAndPay(ticket);
}

void request1(ParkingLot* parkinglot, Ticket* ticket) {
	ticket = requestparkingSlot(parkinglot, new VehicleInfo("TS01XY0001", VehicleCategory::TwoWheeler));
}

void request2(ParkingLot* parkinglot, Ticket* ticket) {
	ticket = requestparkingSlot(parkinglot, new VehicleInfo("TS01XY0002", VehicleCategory::TwoWheeler));
}

void request3(ParkingLot* parkinglot, Ticket* ticket) {
	ticket = requestparkingSlot(parkinglot, new VehicleInfo("TS01XY0003", VehicleCategory::TwoWheeler));
}


int main() {

	

	ParkingFloor* floor0 = getFloor("Floor0");
	ParkingFloor* floor1 = getFloor("Floor1");
	vector<ParkingFloor*> floorList = { floor0 };
	ParkingLot* parkinglot = ParkingLot::getParkingLotInstance("XYZ_name", "XYZ_Address", floorList);

	//use case
	/*cout << "---- Testing ------\n";
	Ticket* ticket1 = requestparkingSlot(parkinglot, new VehicleInfo("TS01XY0001", VehicleCategory::TwoWheeler));
	if (ticket1)
		ticket1->ShowParkingTicketInfo();
	

	Ticket* ticket2 = requestparkingSlot(parkinglot, new VehicleInfo("TS01XY0002", VehicleCategory::TwoWheeler));
	if (ticket2)
		ticket2->ShowParkingTicketInfo();

	Ticket* ticket3 = requestparkingSlot(parkinglot, new VehicleInfo("TS01XY0003", VehicleCategory::TwoWheeler));
	if (ticket3)
		ticket3->ShowParkingTicketInfo();
	leaveParking(parkinglot, ticket3);

	Ticket* ticket4 = requestparkingSlot(parkinglot, new VehicleInfo("TS01XY0004", VehicleCategory::Bus));
	if (ticket4)
		ticket4->ShowParkingTicketInfo();

	Ticket* ticket5 = requestparkingSlot(parkinglot, new VehicleInfo("TS01XY0005", VehicleCategory::Sedan));
	if (ticket5)
		ticket5->ShowParkingTicketInfo();

	Ticket* ticket6 = requestparkingSlot(parkinglot, new VehicleInfo("TS01XY0006", VehicleCategory::TwoWheeler));
	if (ticket6)
		ticket6->ShowParkingTicketInfo();
	leaveParking(parkinglot, ticket6);

	leaveParking(parkinglot, ticket1);
	leaveParking(parkinglot, ticket2);

	leaveParking(parkinglot, ticket4);
	leaveParking(parkinglot, ticket5);*/

	cout << "\n\n\n";
	Ticket* ticket1 = nullptr, *ticket2 = nullptr, *ticket3 = nullptr;
	thread t1(request1, parkinglot, ticket1);
	thread t2(request2, parkinglot, ticket2);
	thread t3(request3, parkinglot, ticket3);
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



	return 0;
}