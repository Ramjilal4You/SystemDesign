/* Facade Design Pattern */
// Hide the complexity of the system and Provide the simplified INterface to client
// Hotel Keeper example

#include <iostream>
using namespace std;

//Complext System
class Hotel{
public:
    virtual void getMenu() = 0;
};

class VegRestaurent : public Hotel{
public:
    void getMenu(){
        cout<<"Veg Restaurent Menu\n";
    }
};

class NonVegRestaurent : public Hotel{
public:
    void getMenu(){
        cout<<"Nonveg Restaurent Menu\n";
    }
};

class BothRestaurent : public Hotel{
public:
    void getMenu(){
        cout<<"Veg & NonVeg Restaurent Menu\n";
    }
};

//Facade
class HotelKeeper{
public:
    void getVegMenu(){
        VegRestaurent *veg = new VegRestaurent();
        veg->getMenu(); 
    }
    void getNonVegMenu(){
        NonVegRestaurent *veg = new NonVegRestaurent();
        veg->getMenu(); 
    }
    void getVegNonVegMenu(){
        BothRestaurent *veg = new BothRestaurent();
        veg->getMenu(); 
    }
};


//client
int main(){
    HotelKeeper *hk = new HotelKeeper();
    hk->getVegMenu();
    hk->getNonVegMenu();
    hk->getVegNonVegMenu();
return 0;
}