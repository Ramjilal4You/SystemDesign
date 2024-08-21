#pragma once

#include "OutsidePanels.hxx"
#include "Display.hxx"


class Floor {
private:
    int floorNumber;
    OutsidePannel* panel;
    Display* display;
public:
    ~Floor();
    Floor(int ifloorNumber, OutsidePannel* iPannel, Display* iDisplay);

    void setFloorNumber(int ifloorNumber);
    int getFloorNumber();

    void setPannel(OutsidePannel* iPannel);
    OutsidePannel* getPannel();

    void setDisplay(Display* iDisplay);
    Display* getDisplay();
};