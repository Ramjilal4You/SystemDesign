#include "ElevatorSystem.hxx"

#include <iostream>
using namespace std;

ElevatorSystem* ElevatorSystem::liftSystem = nullptr;
mutex ElevatorSystem::mtx;

ElevatorSystem::ElevatorSystem() {
   cout << "ElevatorSystem Created\n";
   controller = nullptr;
   lift = nullptr;
}

ElevatorSystem::~ElevatorSystem()
{
    cout << "ElevatorSystem Deleted\n";
}

ElevatorSystem* ElevatorSystem::getElevatorSystemInstance() {
   if (liftSystem == nullptr) {
       mtx.lock();
       if (liftSystem == nullptr) {
           liftSystem = new ElevatorSystem();
       }
       mtx.unlock();
   }

   return liftSystem;
}

void ElevatorSystem::setLift(Lift* iLift) {
   lift = iLift;
}

Lift* ElevatorSystem::getLift()
{
    return lift;
}

void ElevatorSystem::setFloors(vector<Floor*> iFloors) {
   floors = iFloors;
}

void ElevatorSystem::setController(Controller* ctlr)
{
   controller = ctlr;
}

Controller* ElevatorSystem::getController()
{
    return controller;
}

