 #pragma once

 #include "LiftFactory.hxx"

 #include <iostream>
 using namespace std;


LiftFactory::~LiftFactory()
{
    cout << "LiftFactory Deleted\n";
}

LiftFactory::LiftFactory()
 {
    lift = nullptr;
    elevatorSystem = nullptr;
 }

 ElevatorSystem* LiftFactory::CreateElevatorSystem()
 {
    Controller* controller = new Controller("Lift01_Ctlr");
    Dispatcher* dispatcher = new Dispatcher("Lift01_Dispatcher");

    vector<LiftButton*> floorButtons;   //list of floor btns
    vector<DoorButton*> doorButtons;    //list of door btns

    //add all the floors
    floorButtons.push_back(new LiftButton("fBtnFloorN00", dispatcher, 0));
    floorButtons.push_back(new LiftButton("fBtnFloorN01", dispatcher, 1));
    floorButtons.push_back(new LiftButton("fBtnFloorN02", dispatcher, 2));
    floorButtons.push_back(new LiftButton("fBtnFloorN03", dispatcher, 3));
    floorButtons.push_back(new LiftButton("fBtnFloorN04", dispatcher, 4));

    //add all the Door actions
    doorButtons.push_back(new DoorButton("dBtnOpenLift01", dispatcher, DOORACTION::OPEN));
    doorButtons.push_back(new DoorButton("dBtnCloseLift01", dispatcher, DOORACTION::CLOSE));

    InsidePanel* insidePannel = new InsidePanel("IPanelLift01", floorButtons, doorButtons);   //created Inside panel with all buttons

    Door* door = new Door("DoorLift01");    //door created
    Display* display = new Display("DisplayLift01");   //display created
    lift = new Lift(door, display, insidePannel);   //lift created


    //list of direction Buttons (Up & down)
    vector<HallButton*> directionButtons0 = { new HallButton("hBtnUpFloor00", dispatcher, DIRECTION::UP, 0) };
    vector<HallButton*> directionButtons1 = { new HallButton("hBtnUpFloor01", dispatcher, DIRECTION::UP, 1), new HallButton("hBtnDownFloo01", dispatcher, DIRECTION::DOWN, 1) };
    vector<HallButton*> directionButtons2 = { new HallButton("hBtnUpFloor02", dispatcher, DIRECTION::UP, 2), new HallButton("hBtnDownFloo02", dispatcher, DIRECTION::DOWN, 2) };
    vector<HallButton*> directionButtons3 = { new HallButton("hBtnUpFloor03", dispatcher, DIRECTION::UP, 3), new HallButton("hBtnDownFloo03", dispatcher, DIRECTION::DOWN, 3) };
    vector<HallButton*> directionButtons4 = { new HallButton("hBtnDownFloor04", dispatcher, DIRECTION::DOWN, 4) };

    OutsidePannel* outSidePannel0 = new OutsidePannel("OPanelFloor00", directionButtons0); //floor0 panel //created outside panel with all buttons (up & down)
    OutsidePannel* outSidePannel1 = new OutsidePannel("OPanelFloor01", directionButtons1); //floor1 panel  
    OutsidePannel* outSidePannel2 = new OutsidePannel("OPanelFloor02", directionButtons2); //floor2 panel
    OutsidePannel* outSidePannel3 = new OutsidePannel("OPanelFloor03", directionButtons3); //floor3 panel
    OutsidePannel* outSidePannel4 = new OutsidePannel("OPanelFloor04", directionButtons4); //floor4 panel 

    //list of floor created
    floorList.push_back(new Floor(0, outSidePannel0, new Display("DisplayFloor00")));
    floorList.push_back(new Floor(1, outSidePannel1, new Display("DisplayFloor01")));
    floorList.push_back(new Floor(2, outSidePannel2, new Display("DisplayFloor02")));
    floorList.push_back(new Floor(3, outSidePannel3, new Display("DisplayFloor03")));
    floorList.push_back(new Floor(4, outSidePannel4, new Display("DisplayFloor04")));

    elevatorSystem = ElevatorSystem::getElevatorSystemInstance();
    elevatorSystem->setLift(lift);
    elevatorSystem->setFloors(floorList);
    elevatorSystem->setController(controller);
    controller->setLift(lift);

    return elevatorSystem;
 }

 Lift* LiftFactory::getLift()
 {
    return lift;
 }

 Floor* LiftFactory::getFloor(int floor)
 {
    return floorList[floor];
 }
