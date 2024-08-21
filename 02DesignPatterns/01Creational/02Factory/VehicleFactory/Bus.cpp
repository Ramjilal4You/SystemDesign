#include <iostream>
#include "Bus.hxx"

Bus::Bus(){
    std::cout<<"Bus instance created"<<std::endl;
}

void Bus::showVehicleName(){
    std::cout<<"VehicleName : Bus"<<std::endl;
}