/* Factory Methos Pattern - Shape Factory
*/
#ifndef SHAPEFACTORY_CPP
#define SHAPEFACTORY_CPP

#include <iostream>
using namespace std;

//Abstract Product
class Shape{
public:
    virtual void Draw()=0;
};

//1. Concrete Products
class Circle : public Shape{
public:
    void Draw() override{
        cout<<"Circle is Drawn\n";
    }
};

//2. Concrete Products
class Square : public Shape{
public:
    void Draw() override{
        cout<<"Square is Drawn\n";
    }
};

// //3. Concrete Products
// class Rectangle : public Shape{
// public:
//     void Draw() override{
//         cout<<"Rectangle is Drawn\n";
//     }
// };


// Shape Factory
class ShapeFactory{
public:
    static Shape* getShape(int opt){
        Shape *shape = nullptr;
        switch (opt)
        {
        case 1:
            shape = new Circle();
            break;
        case 2:
            shape = new Square();
            break;
        // case 3:
        //     shape = new Rectangle();
        //     break;
        default:
            cout<<"Either Entered the wronge inoput or This Shape is not supported!\n";
        }
        return shape;
    }
    virtual ~ShapeFactory(){
        cout<<"~ShapeFactory()\n";
    }
};

#endif