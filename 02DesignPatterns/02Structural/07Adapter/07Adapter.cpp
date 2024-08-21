/* Adapter Design pattern - Printer --> Lagacy Printer
*/

#include <iostream>

using namespace std;

//Adaptee
//Lagacy Printer
class LagacyPrinter{
public:
    void PrintDocument(){
        cout<<"\nPrinting document using Lagacy Printer\n\n";
    }
};

//Target class Interface
//Printer Interface
class  IPrinter
{
public:
    virtual void Print() = 0;
};

//Adapter
class  PrinterAdapter : public IPrinter
{
private:
    LagacyPrinter lagacyPrinter;
public:
    void Print(){
        lagacyPrinter.PrintDocument();
    }
};

//clinet
int main(){

    IPrinter *myPrinter = new PrinterAdapter;
    myPrinter->Print();

return 0;
}