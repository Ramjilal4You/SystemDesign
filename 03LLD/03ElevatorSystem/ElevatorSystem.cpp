/*Elevator System*/
//BottomUp approach

#include <iostream>

#include <vector>


using namespace std;

//Enum Floor Numbers
enum FLOORNUMBERS{
    FLOOR0, FLOOR1, FLOOR2
};

//Enum Elevator number
enum ELEVATORNUMBERS{
    ELEVATOR1=1, ELEVATOR2
};

//Enum Door actions
enum DOORACTIONS{
    OPEN, CLOSE
};

//Enum elevator state/direction
enum DIRECTION{
    UP, DOWN, IDLE
};

//Button Interface & It's concrete classes
class Button{
protected:
    bool buttonStatus;
public:
    virtual bool IsPressed() = 0;
    virtual bool Press() = 0;
};

//get & set floor number
class ElevatorButton : public Button{
    FLOORNUMBERS fNumber;
public:
    ElevatorButton(){}
    ElevatorButton(bool iStatus, FLOORNUMBERS iFNumber){
        cout<<"Creating ElevatorButton with status "<<iStatus<<" for floor number"<<iFNumber<<"\n";
        buttonStatus = iStatus;
        fNumber = iFNumber;
    }
    //getter & setter
    FLOORNUMBERS getFloorNumber(){
        //TODO : check is button is pressed or not
        return fNumber;
    }

    void setFloorNumber(FLOORNUMBERS iFloorNumber){
        fNumber = iFloorNumber;
    }

    bool IsPressed(){return buttonStatus;}
    bool Press() {
        cout<<"Elevator Button Pressed\n";
        if(!buttonStatus)
            buttonStatus = true;
        return buttonStatus;
    }

};

//get & set floor button
class FloorButton : public Button{
    DIRECTION direction;
public:
    FloorButton(){}
    FloorButton(bool iStatus, DIRECTION iDirection){
        cout<<"Creating FloorButton with status "<<iStatus<<" and Direction "<<iDirection<<"\n";
        buttonStatus = iStatus;
        direction = iDirection;
    }
    //getter & setter
    DIRECTION getDirection(){
        //TODO : check is button is pressed or not
        return direction;
    }

    void setDirection(DIRECTION iDirection){
        direction = iDirection;
    }

    bool IsPressed(){
        return buttonStatus;
    }
    bool Press() {
        cout<<"Floor Button Pressed\n";
        if(!buttonStatus)
            buttonStatus = true;
        return buttonStatus;
    }

};

//get & set floor button
class DoorButton : public Button{
    DOORACTIONS action;
public:
    DoorButton(){}
    DoorButton(bool iStatus, DOORACTIONS iAction){
        cout<<"Creating DoorButton with status "<<iStatus<<" and Action "<<iAction<<"\n";
        buttonStatus = iStatus;
        action = iAction;
    }
    //getter & setter
    DOORACTIONS getDoorAction(){
        //TODO : check is button is pressed or not
        return action;
    }

    void setDoorAction(DOORACTIONS iDirection){
        action = iDirection;
    }

    bool IsPressed(){
        return buttonStatus;
    }
    bool Press() {
        cout<<"Door Button Pressed\n";
        if(!buttonStatus)
            buttonStatus = true;
        return buttonStatus;
    }

};


//Pannel classes

class InsidePannel{
private:
    vector<ElevatorButton*> elevatorButtons;
    vector<DoorButton*> doorButtons;

public:
    InsidePannel(){
        //add all the floors
        cout<<"Inside pannel Created\n";
        elevatorButtons.push_back(new ElevatorButton(false, FLOORNUMBERS::FLOOR0));
        elevatorButtons.push_back(new ElevatorButton(false, FLOORNUMBERS::FLOOR1));
        elevatorButtons.push_back(new ElevatorButton(false, FLOORNUMBERS::FLOOR2));
        
        //add all the Door actions
        doorButtons.push_back(new DoorButton(false, DOORACTIONS::OPEN));
        doorButtons.push_back(new DoorButton(false, DOORACTIONS::CLOSE));
    }

    bool PressElevatorButton(FLOORNUMBERS iFloorNumber){
        //TODO : elevatorButtons[iFloorNumber]->setFloorNumber(iFloorNumber);
        return elevatorButtons[iFloorNumber]->Press();
    }

    bool PressDoorButton(DOORACTIONS iDoorAction){
        //TODO : elevatorButtons[iFloorNumber]->setFloorNumber(iFloorNumber);
        return elevatorButtons[iDoorAction]->Press();
    }

};

class OutsidePannel{
private:
    vector<FloorButton*> floorButtons;  //up & down direction

public:
    OutsidePannel(){
        //add all the Door actions
        cout<<"Outside pannel Created\n";
        floorButtons.push_back(new FloorButton(false, DIRECTION::UP));
        floorButtons.push_back(new FloorButton(false, DIRECTION::DOWN));
        floorButtons.push_back(new FloorButton(false, DIRECTION::IDLE));
    }

    bool PressFloorButton(int iDirection){
        //TODO
        return floorButtons[iDirection]->Press();
    }

};

class Display{
private:
    FLOORNUMBERS fNumber;
    DIRECTION direction;
public:
    Display(FLOORNUMBERS ifNumber, DIRECTION iDirection){
        cout<<"Display Created\n";
        fNumber = ifNumber;
        direction = iDirection;
    }
    void setFloorNumber(FLOORNUMBERS ifNumber){
        fNumber = ifNumber;
    }
    FLOORNUMBERS getFloorNUmber(){
        return fNumber;
    }
    void setDirection(DIRECTION iDirection){
        direction = iDirection;
    }
    DIRECTION getDirection(){
        return direction;
    }
};

class Door{
private:
    DOORACTIONS doorAction;
public:
    Door(DOORACTIONS iDoorAction){
        cout<<"Door created\n";
        doorAction = iDoorAction;
    }
    void openDoor(){
        doorAction = DOORACTIONS::OPEN;
        cout<<"Opening Door\n";
    }
    void closeDoor(){
        doorAction = DOORACTIONS::CLOSE;
        cout<<"Closing Door\n";
    }

    DOORACTIONS getDoorStatus(){
        return doorAction;
    }
};

class Floor{
private:
    FLOORNUMBERS floorNumber;
    OutsidePannel *pannel;
    Display *display;
public:
    Floor(FLOORNUMBERS ifloorNumber, OutsidePannel *iPannel, Display *iDisplay){
        cout<<"Floor "<<ifloorNumber <<" created\n";
        floorNumber = ifloorNumber;
        pannel = iPannel;
        display = iDisplay;
    }

    void setFloorNumber(FLOORNUMBERS ifloorNumber){
        floorNumber = ifloorNumber;
    }

    FLOORNUMBERS getFloorNumber(){
        return floorNumber;
    }

    void setPannel(OutsidePannel *iPannel){
        pannel = iPannel;
    }

    OutsidePannel* getPannel(){
        return pannel;
    }

    void setDisplay(Display *iDisplay){
        display = iDisplay;
    }

    Display* getDisplay(){
        return display;
    }
};


class Elevator{
private:
    Door *door;
    Display *display;
    InsidePannel *pannel;

    ELEVATORNUMBERS eNumber;
    FLOORNUMBERS currentFloor;
    DIRECTION direction;

public:
    Elevator(ELEVATORNUMBERS number, FLOORNUMBERS floor, DIRECTION iDirection, Door *iDoor, Display *iDisplay, InsidePannel *iPannel){
        cout<<"Elevator "<<number<<" Created\n";
        eNumber = number;
        currentFloor = floor;
        direction = iDirection;
        door = iDoor;
        display = iDisplay;
        pannel = iPannel;
    }

    void setElevatorNumber(ELEVATORNUMBERS number){
        eNumber = number;
    }
    ELEVATORNUMBERS getElevatorNumber(){
        return eNumber;
    }
    void setFloorNumber(FLOORNUMBERS floor){
        currentFloor = floor;
    }
    FLOORNUMBERS getFloorNumber(){
        return currentFloor;
    }
    void setDirection(DIRECTION iDirection){
        direction = iDirection;
    }
    DIRECTION getDirection(){
        return direction;
    }

    void setDoor(Door *iDoor){
        door = iDoor;
    }
    Door* getDoor(){
        return door;
    }

    void setDisplay(Display *iDisplay){
        display = iDisplay;
    }
    Display* getDisplay(){
        return display;
    }

    void setPannel(InsidePannel *iPannel){
        pannel = iPannel;
    }
    InsidePannel* getPannel(){
        return pannel;
    }

};

#include <mutex>
mutex mtx;

//Main Elevator class --> Singleton
class ElevatorSystem{
private:
    vector<Elevator*> elevators;
    vector<Floor*> floors;
    static ElevatorSystem* elevator;

    ElevatorSystem(){}

    vector<Elevator*> getElevators(){
        return elevators;
    }
    vector<Floor*> getFloors(){
        return floors;
    }

public:
    ElevatorSystem(const ElevatorSystem& ) = delete;

    static ElevatorSystem* getElevatorInstance( vector<Elevator*> elevators , vector<Floor*> floors){
        if(elevator == nullptr){
            //lock
            lock_guard<mutex> lock(mtx);
            //mtx.lock();
            if(elevator == nullptr){
                cout<<"Elevator System Created\n";
                elevator = new ElevatorSystem();
                elevator->setElevators(elevators);
                elevator->setFloors(floors);
            }
            //mtx.unlock();
        }
        
        return elevator;
    }

    void setElevators(vector<Elevator*> iElevators){
        elevators = iElevators;
    }

    void setFloors(vector<Floor*> iFloors){
        floors = iFloors;
    }

    //Elevator operations
    //1. Select direction from floor
    //2. Open the door
    //3. Close the door
    //4. get into lift & select the floor

    void requestElevator(FLOORNUMBERS floor, DIRECTION directionBtn){
        //TODO: returning elevator using smart dispatch, setting up the properties of the elevator
        elevators[0]->setDirection(directionBtn);
        cout<<"Requesting Elevator at "<<floor<<" floor with direction "<<directionBtn<<"\n";
    }

    void openDoor(Elevator *lift){
        cout<<"Selected openDoor inside lift "<<lift->getElevatorNumber()<<"\n";
        lift->getDoor()->openDoor();
    }

    void closeDoor(Elevator *lift){
        cout<<"Selected closeDoor inside lift "<<lift->getElevatorNumber()<<"\n";
        lift->getDoor()->closeDoor();
    }

    void selectFloor(Elevator *lift, FLOORNUMBERS floor){
        lift->getPannel()->PressElevatorButton(floor);
        cout<<"Selected floor "<<floor<<" inside lift "<<lift->getElevatorNumber()<<"\n";
    }
};

ElevatorSystem* ElevatorSystem::elevator = nullptr;


//client
int main(){

    Door *door = new Door(DOORACTIONS::CLOSE);
    Display *display = new Display(FLOORNUMBERS::FLOOR0, DIRECTION::IDLE);
    InsidePannel *liftPannel = new InsidePannel();
    Elevator *lift1 = new Elevator(ELEVATORNUMBERS::ELEVATOR1, FLOORNUMBERS::FLOOR0, DIRECTION::IDLE, door, display, liftPannel);
    Elevator *lift2 = new Elevator(ELEVATORNUMBERS::ELEVATOR2, FLOORNUMBERS::FLOOR0, DIRECTION::IDLE, door, display, liftPannel);
    
    OutsidePannel *outSidePannel = new OutsidePannel();

    Floor *floor0 = new Floor(FLOORNUMBERS::FLOOR0, outSidePannel, display);
    Floor *floor1 = new Floor(FLOORNUMBERS::FLOOR1, outSidePannel, display);
    Floor *floor2 = new Floor(FLOORNUMBERS::FLOOR2, outSidePannel, display);

    vector<Elevator*> elevators {lift1, lift2};
    vector<Floor*> floors {floor0, floor1, floor2};

    ElevatorSystem *elevatorSystem = ElevatorSystem::getElevatorInstance(elevators, floors);
    cout<<"\n\n";
    elevatorSystem->requestElevator(FLOOR0, UP);
    elevatorSystem->openDoor(lift1);
    elevatorSystem->closeDoor(lift1);
    elevatorSystem->selectFloor(lift1, FLOOR2);

    cout<<"\n\n";
    elevatorSystem->requestElevator(FLOOR2, DOWN);
    elevatorSystem->openDoor(lift2);
    elevatorSystem->closeDoor(lift2);
    elevatorSystem->selectFloor(lift2, FLOOR1);

return 0;
}