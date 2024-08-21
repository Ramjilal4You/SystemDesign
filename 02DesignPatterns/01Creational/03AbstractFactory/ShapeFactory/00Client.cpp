#include <iostream>
#include "AbstractFactory.hxx"
#include "CircleFactory.hxx"
#include "Shape.hxx"

using namespace std;

int main(){
//0 -> Circle, 1 -> Square
AbstractFactory *shapFact = AbstractFactory::getFactory(0);

Shape* shape = shapFact->createShape();
shape->draw();

AbstractFactory *shapFact1 = AbstractFactory::getFactory(1);

Shape* shape1 = shapFact1->createShape();
shape1->draw();


return 0;
}

/* build using command
g++ -o out .\00Client.cpp .\AbstractFactory.cpp .\Circle.cpp .\CircleFactory.cpp .\Square.cpp .\SquareFactory.cpp
*/