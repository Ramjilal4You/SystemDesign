//Abstract Factory Design Pattern

#include <iostream>
using namespace std;

//Abstract Product 1
class Car{
public:
    virtual void show() = 0;
};

class HundaiCar : public Car{
public:
    HundaiCar(){cout<<"HundaiCar Created\n";}
    void show(){
        cout<<"Showing HundaiCar\n";
    }
};
class ToyotaCar : public Car{
public:
    ToyotaCar(){cout<<"ToyotaCar Created\n";}
    void show(){
        cout<<"Showing ToyotaCar\n";
    }
};

//Abstract Product 2
class Bike{
public:
    virtual void show() = 0;
};

class HundaiBike : public Bike{
public:
    HundaiBike(){cout<<"HundaiBike Created\n";}
    void show(){
        cout<<"Showing HundaiBike\n";
    }
};
class ToyotaBike : public Bike{
public:
    ToyotaBike(){cout<<"ToyotaBike Created\n";}
    void show(){
        cout<<"Showing ToyotaBike\n";
    }
};

//AbstractFactory
class VehicleFactory
{
public:
    virtual Car* createCar() = 0; 
    virtual Bike* createBike() = 0;
};

class HundaiFactory : public VehicleFactory{

public:
    HundaiFactory(){cout<<"HundaiFactory created\n";}
    Car* createCar(){
        return new HundaiCar;
    }
    Bike* createBike(){
        return new HundaiBike;
    }
};

class ToyotaFactory : public VehicleFactory{
public:
    ToyotaFactory(){cout<<"ToyotaFactory created\n";}
    Car* createCar(){
        return new ToyotaCar;
    }
    Bike* createBike(){
        return new ToyotaBike;
    }
};

//factory of factory
class AbstractFactory{
public:
static VehicleFactory* createFactory(int type){
    VehicleFactory* factory;
    if(type == 1){
        factory = new HundaiFactory;
    }
    else if(type == 2){
        factory = new ToyotaFactory;
    }
    else{
        cout<<"Factory type is not supported, so creating HundaiFactory\n";
        factory = new HundaiFactory;
    }
    return factory;
}
};
//client
int main(){
    int factType;
    cout<<"Wwhich type of car/bike you want (Hundai : 1, Toyota : 2)\nEnter you option : ";
    cin>>factType;
    VehicleFactory *factory = AbstractFactory::createFactory(factType);
    Bike* bike = factory->createBike();
    bike->show();

    Car* car = factory->createCar();
    car->show();
return 0;
}
