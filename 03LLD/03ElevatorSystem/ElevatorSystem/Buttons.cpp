
#include "Buttons.hxx"

#include <iostream>
using namespace std;


HallButton::HallButton(string id, Dispatcher* iDispatcher, DIRECTION iDirection, int ifloor) 
{
    buttonId = id;
    buttonStatus = 0;
    direction = iDirection;
    floor = ifloor;
    dispatcher = iDispatcher;

    cout << "Creating HallButton with status " << 0 << " and Direction " << iDirection << " : " << buttonId << "\n";
}

void HallButton::setFloorNumber(int ifloor)
{
    floor = ifloor;
}
bool HallButton::IsPressed() { return buttonStatus; }

bool HallButton::Press() {
    bool res = false;
    if (!buttonStatus) {
        buttonStatus = true;
        //send request to Dispatcher & Dispatcher will send it to Controller
        res = dispatcher->sendRequestToController(floor, direction);
    }
    return res;
}

LiftButton::LiftButton(string id, Dispatcher* iDispatcher, int iFNumber) {
    buttonId = id;
    buttonStatus = false;
    fNumber = iFNumber;
    dispatcher = iDispatcher;

    cout << "Creating LiftButton with status " << false << " for floor number" << iFNumber << " : " << buttonId << "\n";
}

int LiftButton::getLiftButtonId() { return fNumber; }
bool LiftButton::IsPressed() { return buttonStatus; }


bool LiftButton::Press() {
    cout << "Elevator Button Pressed for going to floor : " << fNumber << "\n";
    bool res = false;
    if (!buttonStatus) {
        buttonStatus = true;
        //send request to Dispatcher & Dispatcher will send it to Controller
        res = dispatcher->sendRequestToController(fNumber);
    }
    return res;
}

DoorButton::DoorButton(string id, Dispatcher* iDispatcher, DOORACTION iBtnType) {
    buttonId = id;
    buttonStatus = false;
    type = iBtnType;
    dispatcher = iDispatcher;
    cout << "Creating DoorButton with status " << false << " : " << buttonId << "\n";
}
DOORACTION DoorButton::getDoorBtnType() {
    return type;
}
bool DoorButton::IsPressed() {
    return buttonStatus;
}
bool DoorButton::Press() {
    cout << "Door Button Pressed : " << type << "\n";
    bool res = false;
    if (!buttonStatus) {
        buttonStatus = true;
        res = dispatcher->sendRequestToController(type);
    }
    return res;
}

IButton::~IButton()
{
    cout << "Button Deleted\n";
}

DoorButton::~DoorButton()
{
    cout << "DoorButton Deleted\n";
}

HallButton::~HallButton()
{
    cout << "HallButton Deleted\n";
}

LiftButton::~LiftButton()
{
    cout << "LiftButton Deleted\n";
}
