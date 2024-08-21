//Vending Machine Low Level Design

/*
--> single transaction at time or only 1 user can use at a time
    

// State wise operations
        State               :   Operation
1. Idle State               :   1. Press Start button -> Go to ProductSelection state

2. ProductSelection state   :   1. Enter Product Code
                                2. Enter Button  -> Go to Payment state
                                3. Cancel Button -> Go to Idle state

3. payment State            :   1. Insert Coin
                                2. Cancel Button -> if coin insrted - Go to Refund state
                                                 -> else - Go to Idle state
                                3. Enter Button  -> if insreted amount is less -> stay here & show message to insert coin
                                                 -> if inserted amount is more -> refund extra amount
                                                 -> else -> Go to Dispense state

4. Dispense State           :   1. Dispense Product
                                2. UpdateInventry()
                                3. Go to Idle state

//Design Pattern Used --> 
- Singleton --> single instance of VM
- State --> VM state management
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <mutex>
using namespace std;

class VendingMachine;

// state Interface
class IState{
public:
    virtual void ShowStateName() = 0;
    virtual void PressEnterBtn(VendingMachine* vm){
        cout<<"INFO: IState::PressEnterBtn\n";
    }
    virtual void PressCancelBtn(VendingMachine* vm){
        cout<<"INFO: IState::PressCancelBtn\n";
    }
    virtual void EnterProductCode(string){
        cout<<"INFO: EnterProductCode & Press Enter Button\n";
    }
    virtual void InsertCoin(int amt){
        cout<<"INFO: InsertCoin & Press Enter Button\n";
    }
    virtual void DispenseProduct(VendingMachine* vm){
        cout<<"INFO: IState::DispenseProduct\n";
    }
    virtual void PressStartBtn(VendingMachine* vm){
        cout<<"INFO: IState::PressStartBtn\n";
    }
};

/*1. Idle State               :   1. Press Start button -> Go to ProductSelection state*/
class IdleState : public IState{
public:
    IdleState();
    void ShowStateName();
    void PressStartBtn(VendingMachine* vm);
};

/*2. ProductSelection state   :   1. Enter Product Code
                                2. Enter Button  -> Go to Payment state
                                3. Cancel Button -> Go to Idle state
*/
class ProductSelectionState : public IState{
    string str; //pro
public:
    ProductSelectionState();
    void ShowStateName();
    void EnterProductCode(string iCode);
    void PressEnterBtn(VendingMachine* vm);
    void PressCancelBtn(VendingMachine* vm);
};

/*
3. PaymentState            :   1. Insert Coin
                                2. Cancel Button -> if coin insrted - Go to Refund state
                                                 -> else - Go to Idle state
                                3. Enter Button  -> if insreted amount is less -> stay here & show message to insert coin
                                                 -> if inserted amount is more -> refund extra amount
                                                 -> else -> Go to Dispense state
*/
class PaymentState : public IState{
    int insertedAmt;
    int productCost;
public:
    PaymentState(int pCost);
    void ShowStateName();
    void InsertCoin(int Amt);
    void PressEnterBtn(VendingMachine* vm);
    void PressCancelBtn(VendingMachine* vm);
};

/*
4. Dispense State           :   1. Dispense Product
                                2. UpdateInventry()
                                3. Go to Idle state
*/
class DispenseState : public IState{
public:
    DispenseState();
    void ShowStateName();
    void DispenseProduct(VendingMachine* vm);
};

//Context
class VendingMachine
{
private:
    IState *state;
    unordered_map<string, pair<int, int>> inventry; //<ProductCode, <price, productCount>> 
    int balance = 0;
    string itemForSell;
    static inline VendingMachine* vmInstance = nullptr;
    static inline mutex mtx;
    string vmId = "XYZ_0101";
    VendingMachine(IState *iState); //ctor
    VendingMachine(const VendingMachine&);  //copy ctor
    VendingMachine& operator=(const VendingMachine&);   //copy assignment operator
public:
    static inline VendingMachine* getVendingMachineInstance(){
        if(vmInstance == nullptr){
            mtx.lock();
            if(vmInstance==nullptr){
                vmInstance = new VendingMachine(new IdleState);
            }
            mtx.unlock();
        }
        return vmInstance;
    }
    ~VendingMachine();
    void ShowVMId();
    void SetInVentory(unordered_map<string, pair<int, int>> iInventry);
    void SetVendingMachineState(IState *iState);
    void ShowInventry();
    void ShowBalance();
    bool isProductAvailable(string pCode);
    int ProductCost(string pCode);
    void UpdateInventoryOnItemSold();
    void SetItemForSell(string str);
    string GetItemForSell();
    
    //--------------------------
    void ShowCurrentState();
    void StartTransaction();
    void PressCancelButton();
    void PressEnterButton();
    void EnterProductCode(string str);
    void DoPaymentInCoin(int amt);
    void DispenseProduct();
};

// ***** 1. Idle State *****
IdleState::IdleState(){
    cout<<"IdleState\n";
}
void IdleState::ShowStateName(){
    cout<<"IdleState\n";
}
void IdleState::PressStartBtn(VendingMachine* vm){
    cout<<"Start Button Pressed\n";
    vm->SetVendingMachineState(new ProductSelectionState);
}

// ***** 2. ProductSelection state *****
ProductSelectionState::ProductSelectionState(){
    cout<<"ProductSelectionState\n";
}
void ProductSelectionState::ShowStateName(){
    cout<<"ProductSelectionState\n";
}
void ProductSelectionState::EnterProductCode(string iCode){
    cout<<"EnterProductCode : "<<iCode<<"\n";
    str = iCode;
}
void ProductSelectionState::PressEnterBtn(VendingMachine* vm){
    cout<<"Enter Button Pressed\n";
    if(!vm->isProductAvailable(str)){
        cout<<"Error: Product Not Found!\n";
        vm->SetVendingMachineState(new IdleState);
        return;
    }
    else{
        vm->SetItemForSell(str);
    }
    vm->SetVendingMachineState(new PaymentState(vm->ProductCost(str)));
}
void ProductSelectionState::PressCancelBtn(VendingMachine* vm){
    cout<<"Cancel Button Pressed\n";
    vm->SetVendingMachineState(new IdleState);
}

// ***** 3. PaymentState *****
PaymentState::PaymentState(int pCost):productCost(pCost){
    cout<<"PaymentState\n";
}
void PaymentState::ShowStateName(){
    cout<<"PaymentState\n";
}
void PaymentState::InsertCoin(int Amt){
    cout<<"InsertCoin : "<<Amt<<"\n";
    insertedAmt = Amt;
}
void PaymentState::PressEnterBtn(VendingMachine* vm){
    cout<<"Enter Button Pressed\n";
    if(insertedAmt<productCost){
        cout<<"Please Insert more amount\n";
    }
    else if(insertedAmt>productCost){
        int refund = insertedAmt-productCost;
        cout<<"Please collect you extra amount : "<<refund<<"\n";
        //vm->SetVendingMachineState(new RefundState());
    }
    else{
        vm->SetVendingMachineState(new DispenseState);
    }
}
void PaymentState::PressCancelBtn(VendingMachine* vm){
    cout<<"Cancel Button Pressed\n";
    if(insertedAmt>0){
        cout<<"Please collect you amount : "<<insertedAmt<<"\n";
        //vm->SetVendingMachineState(new RefundState());
    }
    vm->SetVendingMachineState(new IdleState);
}

// ***** 4. Dispense State *****
DispenseState::DispenseState(){
    cout<<"DispenseState\n";
}
void DispenseState::ShowStateName(){
    cout<<"DispenseState\n";
}
void DispenseState::DispenseProduct(VendingMachine* vm){
    cout<<"Please collect you product : "<<vm->GetItemForSell() <<"\n";
    vm->UpdateInventoryOnItemSold();
    vm->SetVendingMachineState(new IdleState);
}


//********** VendingMachine **********
VendingMachine::VendingMachine(IState *iState){
    state = iState;
}
VendingMachine::~VendingMachine(){
    delete state;
}

void VendingMachine::SetInVentory(unordered_map<string, pair<int, int>> iInventry){
    inventry = iInventry;
}

void VendingMachine::SetVendingMachineState(IState *iState){
    state = iState;
}
void VendingMachine::ShowInventry(){
    cout<<"----- Inventry Items -----\n";
    cout<<"Product Code : Product Price : Product Count \n";
    for(auto it = inventry.begin(); it!=inventry.end(); it++){
        cout<<it->first<<" : "<<it->second.first<<" : "<<it->second.second<<"\n";
    }
}

void VendingMachine::ShowBalance(){
    cout<<"Current Balance : "<<balance<<"\n";
}

void VendingMachine::ShowVMId(){
    cout<<"VendingMachine Id : "<<vmId<<"\n";
}

bool VendingMachine::isProductAvailable(string pCode){
    auto it = inventry.find(pCode);
    return it!=inventry.end();
}
int VendingMachine::ProductCost(string pCode){
    int cost = INT_MAX;
    auto it = inventry.find(pCode);
    if(it!=inventry.end())
        cost = it->second.first;
    return cost;
}
void VendingMachine::UpdateInventoryOnItemSold(){
    auto it = inventry.find(itemForSell);
    if(it!=inventry.end())
        balance += it->second.first;
    if(it->second.second>1)
        it->second.second--;
    else
        inventry.erase(itemForSell);
    cout<<"Inventory Updated\n";
}

void VendingMachine::ShowCurrentState(){
    state->ShowStateName();
}

void VendingMachine::StartTransaction(){
    state->PressStartBtn(this);
}

void VendingMachine::PressCancelButton(){
    state->PressCancelBtn(this);
}

void VendingMachine::PressEnterButton(){
    state->PressEnterBtn(this);
}

void VendingMachine::EnterProductCode(string str){
    state->EnterProductCode(str);
}
void VendingMachine::DoPaymentInCoin(int amt){
    state->InsertCoin(amt);
}
void VendingMachine::DispenseProduct(){
    state->DispenseProduct(this);
}

void VendingMachine::SetItemForSell(string sellItem){
    itemForSell = sellItem;
}

string VendingMachine::GetItemForSell(){
    return itemForSell;
}


// ********* Client code *********

//perform use case - 1
//Start -> Enter product Code(available)->Press Enter -> Payment(equal o product cost)->Press Enter -> dispense --> Check state (should be Idle)
void UseCase1(VendingMachine *vm){
    cout<<"\n\n******UseCase1********\n";
    vm->ShowVMId();
    vm->ShowCurrentState();
    vm->StartTransaction();
    vm->EnterProductCode("item1");
    vm->PressEnterButton();
    vm->DoPaymentInCoin(10);
    vm->PressEnterButton();
    vm->DispenseProduct();
}

//perform use case - 2
//Start -> Enter product Code(available)->Press Enter -> Payment(equal o product cost)->Press Cancel 
    //  -> Check state (should be Idle & Inventory should not be updated)
void UseCase2(VendingMachine *vm){
    cout<<"\n\n******UseCase2********\n";
    vm->ShowVMId();
    vm->ShowCurrentState();
    vm->StartTransaction();
    vm->EnterProductCode("item2");
    vm->PressEnterButton();
    vm->DoPaymentInCoin(10);
    vm->PressCancelButton();
}

//perform use case - 3
//Start -> Enter product Code(Wrong Product Code)->Press Enter
    //  -> Check state (should be Idle & Inventory should not be updated)
void UseCase3(VendingMachine *vm){
    cout<<"\n\n******UseCase3********\n";
    vm->ShowVMId();
    vm->ShowCurrentState();
    vm->StartTransaction();
    vm->EnterProductCode("item1");
    vm->PressEnterButton();
}

//client
int main(){
    
    unordered_map<string, pair<int, int>> inventry = {{"item1", {10,2}}, {"item2", {12,1}}, {"item3", {20,1}}, {"item4", {5,1}}};
    VendingMachine *vm = VendingMachine::getVendingMachineInstance();
    vm->SetInVentory(inventry);

    vm->ShowInventry();
    vm->ShowBalance();
    
    //perform use case - 1
    //Start -> Enter product Code(available)->Press Enter -> Payment(equal o product cost)->Press Enter -> dispense --> Check state (should be Idle)
    UseCase1(vm);
    vm->ShowInventry();
    vm->ShowBalance();
    //perform use case - 2
    //Start -> Enter product Code(available)->Press Enter -> Payment(equal o product cost)->Press Cancel 
    //  -> Check state (should be Idle & Inventory should not be updated)
    VendingMachine *vm2 = VendingMachine::getVendingMachineInstance();
    UseCase2(vm2);
    vm2->ShowInventry();
    vm2->ShowBalance();
    
    //perform use case - 3
    //Start -> Enter product Code(Wrong Product Code)->Press Enter
    //  -> Check state (should be Idle & Inventory should not be updated)
    VendingMachine *vm3 = VendingMachine::getVendingMachineInstance();
    UseCase3(vm3);
    vm3->ShowInventry();
    vm3->ShowBalance();


return 0;
}

