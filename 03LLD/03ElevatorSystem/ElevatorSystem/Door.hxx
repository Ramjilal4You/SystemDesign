#pragma once

#include "Constants.hxx"

#include <string>

using namespace std;

class Door {
private:
    string doorId;
    DOORSTATUS status;
public:
    ~Door();
    Door(string id);
    string getDoorId();
    DOORSTATUS getDoorStatus();

    bool openDoor();
    bool closeDoor();  
};
