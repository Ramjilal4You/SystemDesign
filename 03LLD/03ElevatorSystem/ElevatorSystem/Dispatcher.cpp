#include "Dispatcher.hxx"
#include "ElevatorSystem.hxx"

#include <iostream>
using namespace std;

Dispatcher::~Dispatcher()
{
	cout << "Dispatcher Deleted\n";
}

Dispatcher::Dispatcher(string id)
{
	dispatcherId = id;
	cout << "Dispatcher Created : " << dispatcherId << endl;
}

string Dispatcher::getDispatcherId()
{
	return dispatcherId;
}

bool Dispatcher::sendRequestToController(int dstFloor, DIRECTION direction)
{
	cout << "Requesting Elevator at " << dstFloor << " floor for going : " << direction << "\n";

	ElevatorSystem* eleSys = ElevatorSystem::getElevatorSystemInstance();
	
	return eleSys->getController()->requestLift(dstFloor, direction);
}

bool Dispatcher::sendRequestToController(int dstFloor)
{
	cout << "Selected floor " << dstFloor << " inside lift\n";
	ElevatorSystem* eleSys = ElevatorSystem::getElevatorSystemInstance();

	int currFloor = eleSys->getLift()->getCurrentFloor();

	DIRECTION direction = DIRECTION::IDLE;
	if (currFloor < dstFloor)
		direction = DIRECTION::UP;
	else if (currFloor > dstFloor)
		direction = DIRECTION::DOWN;

	return eleSys->getController()->requestLift(dstFloor, direction);
}

bool Dispatcher::sendRequestToController(DOORACTION doorAction)
{
	cout << "Pressing Door action button\n";

	ElevatorSystem* eleSys = ElevatorSystem::getElevatorSystemInstance();

	return eleSys->getController()->doorActionRequest(doorAction);
}
