#include "Floor.hxx"
#include <iostream>
using namespace std;


Floor::~Floor()
{
    cout << "Floor Deleted\n";
}

Floor::Floor(int ifloorNumber, OutsidePannel* iPannel, Display* iDisplay) {
    floorNumber = ifloorNumber;
    panel = iPannel;
    display = iDisplay;
    
    cout << "Floor Created" << " : " << floorNumber << "\n";
}

void Floor::setFloorNumber(int ifloorNumber) {
    floorNumber = ifloorNumber;
}

int Floor::getFloorNumber() {
    return floorNumber;
}

void Floor::setPannel(OutsidePannel* iPannel) {
    panel = iPannel;
}

OutsidePannel* Floor::getPannel() {
    return panel;
}

void Floor::setDisplay(Display* iDisplay) {
    display = iDisplay;
}

Display* Floor::getDisplay() {
    return display;
}
