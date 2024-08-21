/* Bridge Design Pattern
Separate the Imlementation from Abstraction
*/
// Clinet --> Abstraction(Vehicle<-Car & Bike) <>-- Implementor(Workshop <- Produce & Assemble)

#include <iostream>
using namespace std;

//Implementor
class IWorkshop{
public:
    virtual void work() = 0;
};

//Concrete Implementor
class Produce : public IWorkshop{
public:
    void work(){
        cout<<"Produced ";
    }
};

class Assemble : public IWorkshop{
public:
    void work(){
        cout<<"Assembled \n\n";
    }
};

//Abstract
class IVehicle{
protected:
    IWorkshop *workshop1;
    IWorkshop *workshop2;
public:
    IVehicle(IWorkshop *pWorkshop1, IWorkshop *pWorkshop2):workshop1(pWorkshop1),workshop2(pWorkshop2){}
    virtual void manufacture() = 0;
};

//Refined Abstraction
class Car : public IVehicle{
public:
    Car(IWorkshop *pWorkshop1, IWorkshop *pWorkshop2):IVehicle(pWorkshop1, pWorkshop2){}
    void manufacture(){
        cout<<"Car ";
        workshop1->work();
        cout<<"And ";
        workshop2->work();
    }
};

class Bike : public IVehicle{
public:
    Bike(IWorkshop *pWorkshop1, IWorkshop *pWorkshop2):IVehicle(pWorkshop1, pWorkshop2){}
    void manufacture(){
        cout<<"Bike ";
        workshop1->work();
        cout<<"And ";
        workshop2->work();
    }
};

//Client
int main(){
    IVehicle *vehicle_car = new Car(new Produce, new Assemble);
    vehicle_car->manufacture();

    IVehicle *vehicle_bike = new Bike(new Produce, new Assemble);
    vehicle_bike->manufacture();

return 0;
}