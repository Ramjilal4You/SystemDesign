#ifndef SQUARE_FACTORY_HXX
#define SQUARE_FACTORY_HXX

#include "AbstractFactory.hxx"
#include "Shape.hxx"

class SquareFactory : public AbstractFactory
{
public:
    virtual Shape* createShape();
};




#endif //SQUARE_FACTORY_HXX