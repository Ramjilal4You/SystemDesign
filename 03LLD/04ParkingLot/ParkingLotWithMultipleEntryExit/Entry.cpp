#include "Entry.hxx"
#include "ParkingSlot.hxx"
#include "ParkingLot.hxx"

Entry::Entry(string eGateId)
{
	entryGateId = eGateId;
}

Ticket* Entry::getParkingTicket(VehicleInfo* vehicle)
{
	ParkingLot* pl = ParkingLot::getParkingLotInstance();

	Ticket* ticket = pl->getParkingTicket(vehicle);

	return ticket;
}

