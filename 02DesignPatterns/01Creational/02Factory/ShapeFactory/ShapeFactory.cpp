/* Factory Methos Pattern - Shape Factory
*/

#include "ShapeFactory.hpp"
#include <iostream>
#include <string>
using namespace std;

//Abstract Product
Shape::Shape(){cout<<"Shape is creted\n";}
Shape::~Shape(){cout<<"Shape is destroyed\n";}


//1. Concrete Products
class Circle : public Shape{
public:
    Circle(){cout<<"Circle is creted\n";}
    ~Circle(){cout<<"Circle is destroyed\n";}
    void setColor(string str) override{
        color = str;
    }
    void Draw() override{
        cout<<"Circle is Drawn & color is "<<color<<"\n";
    }
    
};

//2. Concrete Products
class Square : public Shape{
public:
    Square(){cout<<"Square is creted\n";}
    ~Square(){cout<<"Square is destroyed\n";}
    void setColor(string str) override{
        color = str;
    }
    void Draw() override{
        cout<<"Square is Drawn & color is "<<color<<"\n";
    }
};

// //3. Concrete Products
// class Rectangle : public Shape{
// public:
//    Rectangle(){cout<<"Rectangle is creted\n";}
//    ~Rectangle(){cout<<"Rectangle is destroyed\n";}
//     void setColor(string str) override{
//         color = str;
//     }
//     void Draw() override{
//         cout<<"Rectangle is Drawn\n";
//     }
// };


// Shape Factory
Shape* ShapeFactory::getShape(int opt){
    //Here we will do all the operations which is required for newaly created object to get it complete
    //eg. doing settings, doing configurations etc.
    
    Shape *shape = nullptr;
    switch (opt)
    {
    case 1:
        shape = new Circle();
        shape->setColor("Red");
        break;
    case 2:
        shape = new Square();
        shape->setColor("Blue");
        break;
    // case 3:
    //     shape = new Rectangle();
    //     shape->setColor("Green");
    //     break;
    default:
        cout<<"Either Entered the wronge inoput or This Shape is not supported!\n";
    }
    
    return shape;
}
ShapeFactory::ShapeFactory(){
    cout<<"ShapeFactory()\n";
}
ShapeFactory::~ShapeFactory(){
    cout<<"~ShapeFactory()\n";
}

