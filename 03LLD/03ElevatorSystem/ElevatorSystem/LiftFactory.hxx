#pragma once

#include "ElevatorSystem.hxx"

class LiftFactory {
private:
	Lift* lift;
	vector<Floor*> floorList;
	ElevatorSystem* elevatorSystem;
public:
	~LiftFactory();
	LiftFactory();
	ElevatorSystem* CreateElevatorSystem();
	Lift* getLift();
	Floor* getFloor(int floor);
};

