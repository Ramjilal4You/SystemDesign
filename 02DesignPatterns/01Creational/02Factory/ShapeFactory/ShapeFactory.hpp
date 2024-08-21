// Shape Factory

#ifndef SHAPEFACTORY_HPP
#define SHAPEFACTORY_HPP

#include <string>   //string color
using namespace std;

//Abstract Product
class Shape{
protected:
    string color;
public:
    Shape();
    virtual ~Shape();
    virtual void Draw()=0;
    virtual void setColor(string str)=0;
};

//Factory
class ShapeFactory{
public:
    static Shape* getShape(int opt);
    ShapeFactory();
    virtual ~ShapeFactory();
};

#endif