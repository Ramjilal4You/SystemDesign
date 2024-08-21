#include "Exit.hxx"

#include "ParkingLot.hxx"

Exit::Exit(string eGate)
{
	exitGateId = eGate;
}

void Exit::payAndLeave(Ticket* ticket)
{
	ParkingLot* pl = ParkingLot::getParkingLotInstance();
	pl->getParkingChargeAndPay(ticket);
}
