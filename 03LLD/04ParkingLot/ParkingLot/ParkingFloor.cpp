#include "ParkingFloor.hxx"

#include <iostream>
using namespace std;

ParkingFloor::ParkingFloor(string name, map<ParkingSlotType, vector<ParkingSlot*>> slotList)
{
    floorName = name;
    parkingSlotList = slotList;

    cout << "ParkingFloor Created : " << floorName << endl;
}

ParkingSlotType ParkingFloor::getCorrectParkingSlot(VehicleCategory vCategory)
{
    if (vCategory == VehicleCategory::TwoWheeler) {
        return ParkingSlotType::TwoWheelerSlot;
    }
    else if (vCategory == VehicleCategory::Sedan || vCategory == VehicleCategory::HatchBack) {
        return ParkingSlotType::CompactSlot;
    }
    else if (vCategory == VehicleCategory::SUV) {
        return ParkingSlotType::MediumSlot;
    }
    
    return ParkingSlotType::LargeSlot;
}

vector<ParkingSlot*> ParkingFloor::getRelaventParkingSlotList(VehicleCategory vCategory)
{
    ParkingSlotType slotType = getCorrectParkingSlot(vCategory);
    vector<ParkingSlot*> relaventSlotlist;

    for (auto it : parkingSlotList) {
        if (slotType == it.first) {
            relaventSlotlist = it.second;
            break;
        }
    }
    return relaventSlotlist;
}

ParkingSlot* ParkingFloor::getBestSuitableParkingSlot(vector<ParkingSlot*> relaventParkingSlotList)
{
    ParkingSlot* slot = nullptr;
    for (auto it : relaventParkingSlotList) {
        if (true == it->getParkingSlotStatus()) {
            slot = it;
            break;
        }
    }
    return slot;
}

ParkingSlot* ParkingFloor::getParkingSlotForVehicleAndPark(VehicleInfo* vehicle)
{
    VehicleCategory vCategory = vehicle->getVehicleCategory();
    vector<ParkingSlot*> relaventSlotlist = getRelaventParkingSlotList(vCategory);
    
    ParkingSlot* bestSuitableSlot = getBestSuitableParkingSlot(relaventSlotlist);
    if (bestSuitableSlot)
        bestSuitableSlot->setparkingSlotStatus(false);

    return bestSuitableSlot;
}
