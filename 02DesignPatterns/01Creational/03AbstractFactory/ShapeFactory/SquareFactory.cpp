#include "SquareFactory.hxx"
#include "Square.hxx"

Shape* SquareFactory::createShape(){

    return new Square();
}