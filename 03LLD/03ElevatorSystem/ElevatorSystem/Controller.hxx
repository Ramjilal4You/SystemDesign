#pragma once

#include "Constants.hxx"
#include "Lift.hxx"

#include <set>
#include <string>
using namespace std;

class Controller {
private:
    string controllerId;
    int currentFloor;
    Lift* lift;

    set<int> upRequests;
    set<int> downRequests;

    bool dropOrPickPassenger();
public:
    ~Controller();
    Controller(string id);
    string getControllerId();

    void setLift(Lift* iLift);

    bool requestLift(int floor, DIRECTION dir);
    bool doorActionRequest(DOORACTION doorAction);
    bool moveLift();
};
