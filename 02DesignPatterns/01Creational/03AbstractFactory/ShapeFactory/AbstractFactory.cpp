#include "AbstractFactory.hxx"
#include "CircleFactory.hxx"
#include "SquareFactory.hxx"
#include <iostream>
using namespace std;

AbstractFactory* AbstractFactory::getFactory(int sType){
    if(sType == 0){
        return new CircleFactory;
    }
    else if(sType == 1){
        return new SquareFactory;
    }
    else{
        cout<<"Not supprted!\n";
    }
    return nullptr; 
}