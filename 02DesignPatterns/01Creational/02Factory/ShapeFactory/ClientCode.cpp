#include "ShapeFactory.hpp"

#include <iostream>
using namespace std;

//client code
int main(){
    int opt;
    cout<<"Please Enter (1 : Circle(Red), 2 : Square(Blue)) \nYour Input is : ";
    cin>>opt;

    //get the shape obj
    Shape* shape = ShapeFactory::getShape(opt);
    if(shape!=nullptr)
        shape->Draw();

return 0;
}

/* .cpp --> Preprocessor --> Assembler --> Compiler --> Linker --> .exe
g++ -E .\ShapeFactory.cpp -o .\ShapeFactory.i   --> create .i file
g++ -S .\ShapeFactory.i                         --> create .s file
g++ -c .\ShapeFactory.s --> Generate the .o file
ar r ShapeFactory.a .\ShapeFactory.o   --> Generate the ShapeFactory.a library
g++ -o .\ShapeFactory .\ClientCode.cpp .\ShapeFactory.a  --> ShapeFactory.exe
ShapeFactory.exe --> run the exe

*/