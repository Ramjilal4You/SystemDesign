#pragma once

#include "Floor.hxx"
#include "Lift.hxx"
#include "Controller.hxx"

#include <vector>
#include <mutex>
using namespace std;

//Elevator System class --> Singleton
class ElevatorSystem {
private:
    Lift* lift;
    Controller* controller;
    vector<Floor*> floors;

    static ElevatorSystem* liftSystem;
    static mutex mtx;

    ElevatorSystem();
    ElevatorSystem(const ElevatorSystem&) = default;
    ElevatorSystem& operator=(const ElevatorSystem&) = default;
public:
    ~ElevatorSystem();
    static ElevatorSystem* getElevatorSystemInstance();

    void setLift(Lift* iLift);
    Lift* getLift();


    void setFloors(vector<Floor*> iFloors);

    void setController(Controller* ctlr);
    Controller* getController();
};

//Elevator operations
//1. Request Lift at floor for going UP/DOWN
//2. Open the door
//3. Close the door
//4. get into lift & select the floor
