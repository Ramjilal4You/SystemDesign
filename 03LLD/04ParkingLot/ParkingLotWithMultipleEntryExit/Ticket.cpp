
#include "Ticket.hxx"
#include <iostream>

#include <mutex>
#include <stdlib.h>
#include <ctime>
using namespace std;

int TicketNumber = 1000;
mutex mtx1;
mutex mtx2;

void Ticket::ShowParkingTicketInfo()
{
    mtx1.lock();

    cout << "\n-------- Parking Ticket ------------\n";
    cout << "Ticket ID      : " << ticketId << endl;
    std::time_t entry_time = chrono::system_clock::to_time_t(entryTime);
    cout << "Entry Time     : " << ctime(&entry_time);
    cout << "Slot Number    : " << parkingSlot->getParkingSlotNumber() << endl;
    cout << "Vehicle Number : " << vehicleInfo->getVehicleNumber() << endl;
    cout << "\n-------- Parking Ticket ------------\n\n";

    mtx1.unlock();
}

Ticket::Ticket(ParkingSlot* pSlot, VehicleInfo* vInfo)
{
    mtx2.lock();
    ticketId = ++TicketNumber;
    entryTime = chrono::system_clock::now();
    parkingSlot = pSlot;
    vehicleInfo = vInfo;

    cout << "Ticket Ctreated for : " << vehicleInfo->getVehicleNumber() << endl;

    mtx2.unlock();
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