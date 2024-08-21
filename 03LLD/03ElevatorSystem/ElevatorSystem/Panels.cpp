//Panel classes
#include "InsidePanels.hxx"
#include "OutsidePanels.hxx"

#include <iostream>
using namespace std;

//********* InsidePanel *********

InsidePanel::~InsidePanel()
{
	cout << "InsidePanel Deleted\n";
}

InsidePanel::InsidePanel(string id, vector<LiftButton*> ifloorButtons, vector<DoorButton*> idoorButtons) {
   panelId = id;
   floorButtons = ifloorButtons;
   doorButtons = idoorButtons;
   cout << "InsidePanel Created" << " : " << panelId << "\n";
}

string InsidePanel::getPanelId() { return panelId; }

void InsidePanel::setFloorNumberBtnList(vector<LiftButton*> iFloorButtonList)
{
   floorButtons = iFloorButtonList;
}

vector<LiftButton*> InsidePanel::getFloorBtnList()
{
   return floorButtons;
}

void InsidePanel::setDoorBtnList(vector<DoorButton*> iDoorButtonList)
{
   doorButtons = iDoorButtonList;
}

vector<DoorButton*> InsidePanel::getDoorBtnList()
{
   return doorButtons;
}

//********* OutsidePannel *********

OutsidePannel::~OutsidePannel()
{
	cout << "OutsidePannel Deleted\n";
}

OutsidePannel::OutsidePannel(string id, vector<HallButton*> hallBtns) {
   panelId = id;
   hallButtons = hallBtns;
   cout << "OutsidePannel Created" << " : " << panelId << "\n";
}
string OutsidePannel::getPanelId() { return panelId; }

void OutsidePannel::setDirectionBtnList(vector<HallButton*> iHallButtonList)
{
   hallButtons = iHallButtonList;
}

vector<HallButton*> OutsidePannel::getDirectionBtnList()
{
   return hallButtons;
}
