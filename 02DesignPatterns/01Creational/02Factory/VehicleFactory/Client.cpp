#include "Factory.hxx"

#include <iostream>
using namespace std;

int main(){
    //Which type of vehicle you want??
    int vType;
    cout<<"Entr Vehicle type (1:Car, 2:Bus) ";
    cin>>vType;

    Vehicle* vObject = Factory::getVehicle(vType);

    if(vObject)
        vObject->showVehicleName();

    
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