#include "CircleFactory.hxx"
#include "Circle.hxx"

Shape* CircleFactory::createShape(){

    return new Circle();
}