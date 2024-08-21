#pragma once

#include "Buttons.hxx"

#include <string>
#include <vector>
using namespace std;


//Panel classes

class OutsidePannel {
private:
    string panelId;
    vector<HallButton*> hallButtons;  //2 btns : up & down direction
public:
    ~OutsidePannel();
    OutsidePannel(string id, vector<HallButton*> hallBtns);
    string getPanelId();

    void setDirectionBtnList(vector<HallButton*> iHallButtonList);
    vector<HallButton*> getDirectionBtnList();
};