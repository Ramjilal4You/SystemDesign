#pragma once

#include "Constants.hxx"
#include "Dispatcher.hxx"

//Button Interface & It's concrete classes
class IButton {
protected:
    string buttonId;
    bool buttonStatus;
    Dispatcher* dispatcher;
public:
    virtual ~IButton();
    virtual bool IsPressed() = 0;
    virtual bool Press() = 0;    //sedInstructionToDispatcher
};

class HallButton : public IButton {
private:
    DIRECTION direction; //up or down
    int floor;
public:
    ~HallButton();
    HallButton(string id, Dispatcher* iDispatcher, DIRECTION iDirection, int ifloor);
    void setFloorNumber(int ifloor);

    bool IsPressed();
    bool Press();
};

class LiftButton : public IButton {
private:
    int fNumber;
public:
    ~LiftButton();
    LiftButton(string id, Dispatcher* iDispatcher, int iFNumber);
    int getLiftButtonId();

    bool IsPressed();
    bool Press();
};

class DoorButton : public IButton {
private:
    DOORACTION type;
public:
    ~DoorButton();
    DoorButton(string id, Dispatcher* iDispatcher, DOORACTION iBtnType);
    DOORACTION getDoorBtnType();
    
    bool IsPressed();
    bool Press();
};