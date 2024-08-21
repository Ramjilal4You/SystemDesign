#ifndef CIRCLE_FACTORY_HXX
#define CIRCLE_FACTORY_HXX

#include "AbstractFactory.hxx"
#include "Shape.hxx"


class CircleFactory : public AbstractFactory
{
public:
    virtual Shape* createShape();
};




#endif //CIRCLE_FACTORY_HXX