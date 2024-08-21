// State Design Pattern : client -> Context <>-- IState <- States
//Vending Machine Example

#include <iostream>
using namespace std;

//State Interface
class IState{
public:
    virtual void handleRequest() = 0;
};

//Concrete States
class ReadyState : public IState{
public:
    void handleRequest(){
        cout<<"Ready State : : Please select a product.\n";
    }
    void handleRequest1(){
        cout<<"Ready State : : Please select a product.\n";
    }
};

class ProductSelectedState : public IState{
    void handleRequest(){
        cout<<"ProductSelectedState : Processing payment.\n";
    }
};

class PaymentPendingState : public IState{
    void handleRequest(){
        cout<<"PaymentPendingState : Dispensing product.\n";
    }
};

class OutOfStockState : public IState{
    void handleRequest(){
        cout<<"PayementState : Product unavailable. Please select another product.\n";
    }
};

//Context
class VendingMachineContext{
private:
    IState* state;
public:
    VendingMachineContext(IState* iState){
        state = iState;
    }

    void setState(IState* iState){
        state = iState;
    }

    void request(){
        state->handleRequest();
    }
};

//client
int main()
{
    // Create context with ready state
    VendingMachineContext *vendingMachine = new VendingMachineContext(new ReadyState());
    vendingMachine->request();  // Request state change

    // Change state
    vendingMachine->setState(new ProductSelectedState());
    vendingMachine->request();  // Request state change
    
    // Change state
    vendingMachine->setState(new PaymentPendingState());
    vendingMachine->request();  // Request state change
    
    // Change state
    vendingMachine->setState(new OutOfStockState());
    vendingMachine->request();  // Request state change

    // Set initial state
    vendingMachine->setState(new ReadyState());
    vendingMachine->request();  // Request state change

return 0;
}