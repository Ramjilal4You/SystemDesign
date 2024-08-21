//Elevator System Low Level Design : Single Elevator & 5Floors Building
/*
** Requirements
    - 1 lift, 5 floors
    - user can press up & down button from any floor(0 - only up & 4th only down)
    - user can use lift to go to any floor from any floor
    - Panel inside lift (numbers - 0->4)
    - **Dispatcher --> To manage the lift movement

** Actors/classes
    - Lift, Door, Panel, Floor, liftSystem, Dispatcher

** Classes (Top Down approach )
    - (Lift, Floor)--<>ElevatorSystem--<>clinet
    - Floor <>-- OusidePanel
    - Lift <>-- (Door, InsidePanel)
    - InsidePanel, OusidePanel)
    - OusidePanel <>-- DirectionBtn
    - InsidePanel <>-- FloorBtn, DoorBtn
    - DoorBtn
    - FloorBtn
*/

// implement from Bottom Up approach 


#include "LiftFactory.hxx"

#include <iostream>
using namespace std;


//client
//client can press btns to give commands

int main() {
    cout << "\n\nHello Everyone!!!\n\n";
    LiftFactory liftFactory;
    ElevatorSystem* elevatorSystem = liftFactory.CreateElevatorSystem();

    Lift* lift = liftFactory.getLift();
    vector<DoorButton*> vDoorBtn = lift->getPanel()->getDoorBtnList();
    vector<LiftButton*> vFloorBtn = lift->getPanel()->getFloorBtnList();
    vector<HallButton*> floor0 = liftFactory.getFloor(0)->getPannel()->getDirectionBtnList();
    vector<HallButton*> floor1 = liftFactory.getFloor(1)->getPannel()->getDirectionBtnList();
    vector<HallButton*> floor2 = liftFactory.getFloor(2)->getPannel()->getDirectionBtnList();
    vector<HallButton*> floor3 = liftFactory.getFloor(3)->getPannel()->getDirectionBtnList();
    vector<HallButton*> floor4 = liftFactory.getFloor(4)->getPannel()->getDirectionBtnList();

    cout << "\n\nTesting...\n\n";
    //perform use case
    /* use case 1: Go from floor 0 to 4
    */
    floor0[UP]->Press();
    lift->getPanel()->getFloorBtnList()[4]->Press();
    cout << "\n\n";

    floor2[UP]->Press();
    lift->getPanel()->getFloorBtnList()[1]->Press();
    cout << "\n\n";

    floor3[DOWN]->Press();
    lift->getPanel()->getFloorBtnList()[0]->Press();
    cout << "\n\n";


    // cout<<"\n\n";
    // elevatorSystem->requestElevator(FLOOR0, UP);
    // elevatorSystem->openDoor(lift1);
    // elevatorSystem->closeDoor(lift1);
    // elevatorSystem->selectFloor(lift1, FLOOR2);

    // cout<<"\n\n";
    // elevatorSystem->requestElevator(FLOOR2, DOWN);
    // elevatorSystem->openDoor(lift2);
    // elevatorSystem->closeDoor(lift2);
    // elevatorSystem->selectFloor(lift2, FLOOR1);
    return 0;
}

