#include "Factory.hxx"
#include "Car.hxx"
#include "Bus.hxx"

#include <iostream>
using namespace std;

Vehicle* Factory::getVehicle(int vType){
    Vehicle* vObject = nullptr;
    if(vType==1){
        vObject = new Car;
    }
    else if(vType==2){
        vObject = new Bus;
    }
    else{
        cout<<"This type of object can not be created";
    }
    return vObject;
}
