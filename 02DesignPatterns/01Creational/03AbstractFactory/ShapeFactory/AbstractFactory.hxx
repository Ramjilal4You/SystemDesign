#ifndef ABSTRACT_FACTORY_HXX
#define ABSTRACT_FACTORY_HXX

#include "Shape.hxx"


class AbstractFactory
{
public:
    virtual Shape* createShape() = 0;
    static AbstractFactory* getFactory(int sType);
};




#endif //ABSTRACT_FACTORY_HXX