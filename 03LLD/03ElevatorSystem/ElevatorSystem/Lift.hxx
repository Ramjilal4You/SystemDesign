#pragma once

#include "Constants.hxx"
#include "Door.hxx"
#include "Display.hxx"
#include "InsidePanels.hxx"

class Lift {
private:
    string liftId;
    int currentFloor;
    DIRECTION direction;

    Door* door;
    Display* display;
    InsidePanel* panel;

public:
    ~Lift();
    Lift(Door* iDoor, Display* iDisplay, InsidePanel* iPannel);
    void setLiftId(string id);
    string getLiftId();
    void setCurrentFloor(int floor);
    int getCurrentFloor();
    void setDirection(DIRECTION iDirection);
    DIRECTION getDirection();

    void setDoor(Door* iDoor);
    Door* getDoor();

    void setPannel(InsidePanel* iPanel);
    InsidePanel* getPanel();

    void setDisplay(Display* display);
    Display* getDisplay();

    void moveLift(DIRECTION dir);
};
