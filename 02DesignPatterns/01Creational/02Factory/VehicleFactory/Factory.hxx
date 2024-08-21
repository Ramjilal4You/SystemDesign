#ifndef FACTORY_HXX
#define FACTORY_HXX

#include "Vehicle.hxx"

class Factory
{
public:
    static Vehicle* getVehicle(int vType);
};

#endif