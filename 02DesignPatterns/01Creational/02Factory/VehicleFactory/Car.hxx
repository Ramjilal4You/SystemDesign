#ifndef CAR_HXX
#define CAR_HXX

#include "Vehicle.hxx"

class Car:public Vehicle{
    public:
        Car();
        void showVehicleName();
};

#endif