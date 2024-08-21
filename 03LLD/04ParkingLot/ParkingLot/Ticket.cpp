
#include "Ticket.hxx"
#include <iostream>

#include <stdlib.h>
#include <ctime>
using namespace std;

int TicketNumber = 1000;

void Ticket::ShowParkingTicketInfo()
{
    cout << "\n-------- Parking Ticket ------------\n";
    cout << "Ticket ID      : " << ticketId << endl;
    std::time_t entry_time = std::chrono::system_clock::to_time_t(entryTime);
    cout << "Entry Time     : " << ctime(&entry_time);
    cout << "Slot Number    : " << parkingSlot->getParkingSlotNumber() << endl;
    cout << "Vehicle Number : " << vehicleInfo->getVehicleNumber() << endl;
    cout << "\n-------- Parking Ticket ------------\n\n";
}

Ticket::Ticket(ParkingSlot* pSlot, VehicleInfo* vInfo)
{
    ticketId = ++TicketNumber;
    entryTime = chrono::system_clock::now();
    parkingSlot = pSlot;
    vehicleInfo = vInfo;

    cout << "Ticket Ctreated for : " << vehicleInfo->getVehicleNumber() << endl;
}

double Ticket::getParkingDuration()
{
    chrono::time_point<chrono::system_clock> exitTime = chrono::system_clock::now();
    chrono::duration<double> duration = exitTime - entryTime;
    double hrs = duration.count()*1000;
    return hrs;
}

ParkingSlot* Ticket::getParkingSlot()
{
    return parkingSlot;
}

VehicleInfo* Ticket::getVehicleInfo() {
    return vehicleInfo;
}