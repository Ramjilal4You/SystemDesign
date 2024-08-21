#include "Lift.hxx"

#include <iostream>
using namespace std;

Lift::~Lift()
{
    cout << "Lift Deleted\n";
}

Lift::Lift(Door* iDoor, Display* iDisplay, InsidePanel* iPannel) {
   
   liftId = "Lift1";
   currentFloor = 0;
   direction = IDLE;

   door = iDoor;
   display = iDisplay;
   panel = iPannel;

   cout << "Elevator Created : " << liftId << "\n";
}
void Lift::setLiftId(string id) { liftId = id; }
string Lift::getLiftId() { return liftId; }

void Lift::setCurrentFloor(int floor) {
   currentFloor = floor;
}
int Lift::getCurrentFloor() {
   return currentFloor;
}
void Lift::setDirection(DIRECTION iDirection) {
   direction = iDirection;
}
DIRECTION Lift::getDirection() {
   return direction;
}

void Lift::setDoor(Door* iDoor) {
   door = iDoor;
}
Door* Lift::getDoor() {
   return door;
}

void Lift::setPannel(InsidePanel* iPanel) {
   panel = iPanel;
}
InsidePanel* Lift::getPanel() {
   return panel;
}
void Lift::setDisplay(Display* iDisplay) { display = iDisplay; }
Display* Lift::getDisplay() { return display; }

void Lift::moveLift(DIRECTION dir) {
   cout << "Moving Lift : " << dir << ", Current floor : " << currentFloor << endl;
}
