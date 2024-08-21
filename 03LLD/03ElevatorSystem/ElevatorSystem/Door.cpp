#include "Door.hxx"

#include <iostream>
using namespace std;

Door::~Door()
{
    cout << "Door Deleted\n";
}

Door::Door(string id) {
    doorId = id;
    status = CLOSED;
    cout << "Door created : " << doorId << "\n";
}
string Door::getDoorId() {
    return doorId;
}
DOORSTATUS Door::getDoorStatus() {
    return status;
}

bool Door::openDoor() {
    if (status == DOORSTATUS::CLOSED) {
        status = OPENED;
        cout << "Opening Door\n";
        return true;
    }
    return false;
}
bool Door::closeDoor() {
    if (status == DOORSTATUS::OPENED) {
        status = CLOSED;
        cout << "Closing Door\n";
        return true;
    }
    return false;
}
