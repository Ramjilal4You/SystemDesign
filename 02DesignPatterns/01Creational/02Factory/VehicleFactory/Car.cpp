#include <iostream>
#include "Car.hxx"

Car::Car(){
    std::cout<<"Car instance created"<<std::endl;
}

void Car::showVehicleName(){
    std::cout<<"VehicleName : Car"<<std::endl;
}