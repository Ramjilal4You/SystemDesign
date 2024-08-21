#pragma once

#include "Buttons.hxx"

#include <string>
#include <vector>
using namespace std;

//Panel classes
class InsidePanel {
private:
    string panelId;
    vector<LiftButton*> floorButtons;
    vector<DoorButton*> doorButtons;

public:
    ~InsidePanel();
    InsidePanel(string id, vector<LiftButton*> ifloorButtons, vector<DoorButton*> idoorButtons);
    string getPanelId();

    void setFloorNumberBtnList(vector<LiftButton*> iFloorButtonList);
    vector<LiftButton*> getFloorBtnList();

    void setDoorBtnList(vector<DoorButton*> iDoorButtonList);
    vector<DoorButton*> getDoorBtnList();
};
