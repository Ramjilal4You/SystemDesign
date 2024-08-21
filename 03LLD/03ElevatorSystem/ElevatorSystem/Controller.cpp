#include "Controller.hxx"

#include<thread>

#include <iostream>
using namespace std;

thread t1;

Controller::~Controller()
{
    cout << "Controller Deleted\n";
}

Controller::Controller(string id)
{
   controllerId = id;
   cout << "Controller Created : " << controllerId << endl;

}

string Controller::getControllerId()
{
   return controllerId;
}

 void Controller::setLift(Lift* iLift)
 {
    lift = iLift;
 }

bool Controller::requestLift(int reqfloor, DIRECTION dir)
{
    int currfloor = lift->getCurrentFloor();

    if (currfloor < reqfloor)
        upRequests.insert(reqfloor);
    else if (currfloor > reqfloor)
        downRequests.insert(reqfloor);
    else {
        dropOrPickPassenger();
        return true;
    }

   moveLift();

   return true;
}

bool Controller::doorActionRequest(DOORACTION doorAction)
{
    bool res = false;

    if (lift->getDirection() == DIRECTION::IDLE) {
        if (doorAction == DOORACTION::OPEN)
            res = lift->getDoor()->openDoor();
        else
            res = lift->getDoor()->closeDoor();
    }

    return res;
}


bool Controller::moveLift()
{
    while (!upRequests.empty() || !downRequests.empty()) 
    {
        lift->setDirection(DIRECTION::UP);
        while (!upRequests.empty()) 
        {
            int reqfloor = *upRequests.begin();
            int currfloor = lift->getCurrentFloor();
            lift->getDisplay()->notify(currfloor, "UP");
            if (reqfloor == currfloor) {
                dropOrPickPassenger();  //stop & open door
                upRequests.erase(upRequests.begin());
            }
            if (!upRequests.empty()) {
                currfloor++;
                lift->setCurrentFloor(currfloor);
            }
        }
        lift->setDirection(DIRECTION::DOWN);
        while (!downRequests.empty())
        {
            int reqfloor = *downRequests.begin();
            int currfloor = lift->getCurrentFloor();
            lift->getDisplay()->notify(currfloor, "DOWN");
            if (reqfloor == currfloor) {
                dropOrPickPassenger();  //stop & open door
                downRequests.erase(downRequests.begin());
            }
            if (!downRequests.empty()) {
                currfloor--;
                lift->setCurrentFloor(currfloor);
            }
        }
    }

    return true;
}

bool Controller::dropOrPickPassenger()
{
    lift->setDirection(DIRECTION::IDLE);
    lift->getDoor()->openDoor();    //open door
    cout << "Pick/Drop Passenger Done at floor : " << lift->getCurrentFloor() << endl;
    lift->getDoor()->closeDoor();   //close door
    return true;
}

//Elevator operations
//1. Request Lift at floor for going UP/DOWN
//2. Open the door
//3. Close the door
//4. get into lift & select the floor