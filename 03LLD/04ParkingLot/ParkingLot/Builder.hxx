#pragma once

#include "ParkingSlot.hxx"
#include "ParkingFloor.hxx"
#include "ParkingLot.hxx"

class IBuilder {
	ParkingLot* parkingLot;
public:
	virtual void buildParkingSlot() = 0;
	virtual void buildParkingFloor() = 0;
	
	ParkingLot* getProduct();
};
class ParkingSlotBuilder : public IBuilder {
public:
	void buildParkingSlot();
	void buildParkingFloor();
};
class ParkingFloorBuilder : public IBuilder {
public:
	void buildParkingSlot();
	void buildParkingFloor();
};