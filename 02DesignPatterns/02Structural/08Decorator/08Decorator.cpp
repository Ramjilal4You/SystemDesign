/* Decorator Design pattern*/
// Allow to add new fetures/functionality to an object, dynamically without altering the other objects of same class.

#include <string>
#include <iostream>

using namespace std;

//Product
class Coffee{
public:
    virtual string getDescription() = 0;
    virtual double getCost() = 0;
}; 

//Concrete Product
class PlainCoffee : public Coffee{
public:
    string getDescription(){
        return "Plain";
    }

    double getCost(){
        return 10.0;
    }
};

//Decorator Interface
class CoffeeDecorator : public Coffee{
protected:
    Coffee *plainCoffee;
public:
    CoffeeDecorator(Coffee *pCoffee): plainCoffee(pCoffee){}
};

//concrete Decorators
class MilkCoffee : public CoffeeDecorator{
public:
    MilkCoffee(Coffee *pCoffee):CoffeeDecorator(pCoffee){}
    string getDescription(){
        return plainCoffee->getDescription()+" with Milk";
    }
    double getCost(){
        return plainCoffee->getCost()+ 5.0;
    }
};

class SugerCoffee : public CoffeeDecorator{
public:
    SugerCoffee(Coffee *pCoffee):CoffeeDecorator(pCoffee){}
    string getDescription(){

        return plainCoffee->getDescription()+" with Suger";
    }
    double getCost(){
        return plainCoffee->getCost()+ 2.5;
    }
};

//client
int main(){
    Coffee *plainCoffee = new PlainCoffee();
    Coffee *mCoffee = new MilkCoffee(plainCoffee);
    
    //Coffee with milk
    string name = mCoffee->getDescription();
    double cost  = mCoffee->getCost();
    cout<<"Coffee "<<name <<" : "<<cost<<" Rs\n\n";

    //plain coffee
    name = plainCoffee->getDescription();
    cost = plainCoffee->getCost();
    cout<<"Coffee "<<name <<" : "<<cost<<" Rs\n\n";

    //coffee with milk & suger
    Coffee *msCoffee = new SugerCoffee(mCoffee);
    name = msCoffee->getDescription();
    cost = msCoffee->getCost();
    cout<<"Coffee "<<name <<" : "<<cost<<" Rs\n\n";

    //coffee with milk & suger
    Coffee *mssCoffee = new SugerCoffee(msCoffee);
    name = mssCoffee->getDescription();
    cost = mssCoffee->getCost();
    cout<<"Coffee "<<name <<" : "<<cost<<" Rs\n\n";

return 0;
}