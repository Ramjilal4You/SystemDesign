//ATM Machine Low Level Design

/*
--> single transaction at time or only 1 user can use at a time
    

// State wise operations
        State               :   Operation
1. Idle State               :   1. Insert Card -> Go to CardInserted State

2. CardInserted State       :   1. Enter PIN -> Go to 
                                2. Cancel Button (Eject Card) -> Go to Idle state

3. PINEntered State         :   1. Cancel Button (Eject Card) -> Go to Idle state
                                2. withdraw amount  -> if amount is sufficient -> Go to Dispense State
                                                    -> else -> Show "InSufficient Balance" msg -> Go to Idle state
                                3. Check Balance    -> Show the balance

4. Dispense State           :   1. Dispense amount
                                2. UpdateBalance()
                                3. PrintReceipt
                                4. Go to Idle state

//Design Pattern Used --> 
- Singleton --> single instance of ATM
- State --> ATM state management
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


class ATM;

// State interface
class ATMState {
protected:
    ATM *atm;
public:
    string stateName;
    ATMState(ATM* iAtm){
        atm=iAtm;
    }
    
    //-----------------
    virtual void  insertCard(unordered_map<string, pair<string, int>>::iterator iCard) {
        cout<<"ATMState::insertCard\n";
    }

    virtual void ejectCard() {
        cout<<"ATMState::Cancel Button Pressed\n";
    }

    virtual void enterPIN(string PIN) {
        cout<<"ATMState::Please insert a card first\n";
    }

    virtual void withdraw(int amount) {
        cout<<"ATMState::Please insert a card and enter PIN first\n";
    }

    virtual void CollectAmount(){
        cout<<"ATMState::Please Collect Amount\n";
    }
};

// Concrete state representing the idle state
/* 1. Idle State               :   1. Insert Card -> Go to CardInserted State*/
class IdleState : public ATMState {
public:
    IdleState(ATM* atm):ATMState(atm){
        cout<<"IdleState\n";
        stateName="IdleState";
    }
    void insertCard(unordered_map<string, pair<string, int>>::iterator CardId);
};

// Concrete state representing the card inserted state
/*2. CardInserted State     :   1. Enter PIN -> Go to 
                                2. Cancel Button (Eject Card) -> Go to Idle state
*/
class CardInsertedState : public ATMState {
public:
    CardInsertedState(ATM* atm):ATMState(atm){
        cout<<"CardInsertedState\n";
        stateName="CardInsertedState";
    }
    void ejectCard();

    void enterPIN(string PIN);
};

// Concrete state representing the PIN entered state
/*3. PINEntered State       :   1. Cancel Button (Eject Card) -> Go to Idle state
                                2. withdraw amount  -> if amount is sufficient -> Go to Dispense State
                                                    -> else -> Show "InSufficient Balance" msg -> Go to Idle state
                                3. Check Balance    -> Show the balance
*/
class PINEnteredState : public ATMState {
public:
    PINEnteredState(ATM* atm):ATMState(atm){
        cout<<"PINEnteredState\n";
        stateName="PINEnteredState";
    }
    
    void ejectCard();
    void withdraw(int amount);
    void CheckBalance();
};

// Concrete state representing the Dispense state
/*4. Dispense State         :   1. Dispense amount
                                2. UpdateBalance()
                                3. PrintReceipt
                                4. Go to Idle state
*/
class DispenseState : public ATMState{
private:
    int dispenseAmt = 0;
public:
    DispenseState(ATM* atm, int disAmt):ATMState(atm){
        dispenseAmt = disAmt;
        cout<<"DispenseState\n";
        stateName="DispenseState";
    }
    void CollectAmount();
    void UpdateBalance();
    void PrintReceipt();
    void ejectCard();
};

#include <mutex>

// Context class representing the ATM
class ATM {
private:
    string AtmId;
    ATMState *currentState;
    unordered_map<string, pair<string, int>>::iterator currentCard;
    int atmBalance = 0;
    unordered_map<string, pair<string, int>> cardDetails;
    static inline ATM *atmInstance = nullptr;
    static inline std::mutex mtx;
    ATM();
    ATM(const ATM&);
    ATM& operator=(const ATM&);
public:
    static ATM* getATMInstance(string atmId);

    void showAtmId(){
        cout<<"ATM Id : "<<AtmId<<"\n";
    }
    
    void SetCardDetails(unordered_map<string, pair<string, int>> iCardDetails);
    void ShowCardDetails();

    void setCurentCard(unordered_map<string, pair<string, int>>::iterator cCard);
    unordered_map<string, pair<string, int>>::iterator getCurentCard();

    void SetCardPin(string updatedPin);
    string getCardPIN();

    void updateCardBalance(int depositAmt, char op);
    int getCardBalance();

    void SetCurrentState(ATMState* iState);
    ATMState* GetCurrentState();

    void updateATMBalance(int amt, char op);
    int GetATMBalance();

    bool insertCard(string cardId);
    bool ejectCard();
    bool enterPIN(string PIN) ;
    bool withdraw(int amount);
    bool collectAmount();
};

/* 1. Idle State               :   1. Insert Card -> Go to CardInserted State*/
void IdleState::insertCard(unordered_map<string, pair<string, int>>::iterator CardId) {
    cout<<"Card inserted"<<"\n";
    atm->setCurentCard(CardId);
    atm->SetCurrentState(new CardInsertedState(atm));
}

/*2. CardInserted State     :   1. Enter PIN -> if correct pin -> Go to PINEnteredState else IdleState
                                2. Cancel Button (Eject Card) -> Go to Idle state
*/
void CardInsertedState::ejectCard() {
    cout<<"Card ejected"<<"\n";
    atm->SetCurrentState(new IdleState(atm));
}
void CardInsertedState::enterPIN(string enteredPin) {
    cout<<"PIN entered"<<"\n";
    //validate pin
    string cardPin = atm->getCardPIN();
    if(enteredPin==cardPin){
        cout<<"Card Pin validated\n";
        atm->SetCurrentState(new PINEnteredState(atm));
    }
    else{
        cout<<"Entered Wrong PIN\n";
        atm->SetCurrentState(new IdleState(atm));
    }
        
}

/*3. PINEntered State       :   1. Cancel Button (Eject Card) -> Go to Idle state
                                2. withdraw amount  -> if amount is sufficient int atm & card -> Go to Dispense State
                                                    -> else -> Show "InSufficient Balance" msg -> Go to Idle state
                                3. Check Balance    -> Show the Card balance
*/

void PINEnteredState::ejectCard() {
    cout<<"Card ejected"<<"\n";
    atm->SetCurrentState(new IdleState(atm));
}
void PINEnteredState::withdraw(int amount) {
    if (amount > atm->GetATMBalance() || amount > atm->getCardBalance()) {
        cout<<"Insufficient funds"<<"\n";
        ejectCard();
    } else {
        atm->SetCurrentState(new DispenseState(atm, amount));
    }
}
void PINEnteredState::CheckBalance(){
    cout<<"Current Card balance: " + atm->getCardBalance()<<"\n";
}

// Concrete state representing the Dispense state
/*4. Dispense State         :   1. Dispense amount
                                2. UpdateBalance()
                                3. PrintReceipt
                                4. Go to Idle state
*/
void DispenseState::CollectAmount(){
    UpdateBalance();    //card balance & ATM balance
    PrintReceipt();
    ejectCard();
}
void DispenseState::UpdateBalance(){
    atm->updateCardBalance(dispenseAmt,'-');    //withdrawing amount
    atm->updateATMBalance(dispenseAmt,'-');
}
void DispenseState::PrintReceipt(){
    cout<<"Please Collect your Cash : "<<dispenseAmt<<"\n";
    cout<<"Withdrawal successful. Remaining balance: " <<atm->getCardBalance()<<"\n";
}

void DispenseState::ejectCard() {
    cout<<"Card ejected"<<"\n";
    atm->SetCurrentState(new IdleState(atm));
}

// Context class representing the ATM

ATM::ATM() {
    currentState = new IdleState(this);
}

ATM* ATM::getATMInstance(string atmId){
    if(atmInstance == nullptr){
        mtx.lock();
        if(atmInstance == nullptr){
            atmInstance = new ATM();
            atmInstance->AtmId = atmId;
            atmInstance->atmBalance = 0;
        }
        mtx.unlock();
    }
    return atmInstance;
}

void ATM::SetCardDetails(unordered_map<string, pair<string, int>> iCardDetails){
    cardDetails = iCardDetails;
}
void ATM::ShowCardDetails(){
    cout<<"Card ID : Card PIN : Card Balance\n";
    for(auto it = cardDetails.begin(); it!=cardDetails.end(); it++){
        cout<<it->first<<" : "<<it->second.first<<" : "<<it->second.second<<"\n";
    }
}
void ATM::setCurentCard(unordered_map<string, pair<string, int>>::iterator cCard){
    currentCard = cCard;
}
unordered_map<string, pair<string, int>>::iterator ATM::getCurentCard(){
    return currentCard;
}
void ATM::SetCardPin(string updatedPin){
    currentCard->second.first = updatedPin;
}
string ATM::getCardPIN(){
    return currentCard->second.first;
}
void ATM::updateCardBalance(int amt, char op){
    if(op=='+')
        currentCard->second.second += amt;
    else if (op == '-')
        currentCard->second.second -= amt;
    else    
        cout<<"Wronge operation input\n";
}
int ATM::getCardBalance(){
    return currentCard->second.second;
}
void ATM::SetCurrentState(ATMState* iState){
    currentState = iState;
}
ATMState* ATM::GetCurrentState(){
    return currentState;
}
void ATM::updateATMBalance(int amt, char op){
    if(op=='+')
        atmBalance += amt;
    else if (op == '-')
        atmBalance -= amt;
    else    
        cout<<"Wronge operation input\n";
}
int ATM::GetATMBalance(){
    return atmBalance;
}

bool ATM::insertCard(string cardId) {
    if(currentState->stateName!="IdleState")
        return false;
    unordered_map<string, pair<string, int>>::iterator it = cardDetails.find(cardId);
    currentState->insertCard(it);
    return true;
}
bool ATM::ejectCard() {
    if(currentState->stateName!="CardInsertedState" || currentState->stateName!="PINEnteredState" ||currentState->stateName!="DispenseState")
        return false;
    currentState->ejectCard();
    return true;
}
bool ATM::enterPIN(string PIN) {
    if(currentState->stateName!="CardInsertedState")
        return false;
    currentState->enterPIN(PIN);
    return true;
}
bool ATM::withdraw(int amount) {
    if(currentState->stateName!="PINEnteredState")
        return false;
    currentState->withdraw(amount);
    return true;
}

bool ATM::collectAmount(){
    if(currentState->stateName!="DispenseState")
        return false;
    
    currentState->CollectAmount();
    return true;
}


// ********* Client code *********
template<class T>
void ATMOperation(T flag){
    if(flag == false)
        throw "Exit";
}
//perform use case - 1
void UseCase1(ATM *atm, string CardId, string PIN, int amt){
    cout<<"Card Id : "<<CardId<<" Withdraw amount : "<<amt<<"\n";
    // Simulate ATM interactions
    try{
    ATMOperation(atm->insertCard(CardId));
    ATMOperation(atm->enterPIN(PIN));
    ATMOperation(atm->withdraw(amt));
    ATMOperation(atm->collectAmount());
    cout<<"Curent Card Balance : "<<atm->getCardBalance()<<"\n";
    }
    catch(...){
        //cout<<"This Operation is not correct at this stage, Exited!!!\nPlease try again!!!\n";
    }
}

//client code to run the ATM
int main(int argc, char* argv[]) {
    //<CardId, <cardPin, balance>>
    unordered_map<string, pair<string, int>> CardDetails = {{"Card1", {"12345",10000}},{"Card2", {"12345",20000}},{"Card3", {"12345",30000}},{"Card4", {"12345",40000}}};
    
    // Initialize the ATM with an initial balance
    ATM *atm =  ATM::getATMInstance("atm1");
    atm->SetCardDetails(CardDetails);
    atm->updateATMBalance(100000, '+');

    cout<<"Curent ATM Balance : "<<atm->GetATMBalance()<<"\n";
    atm->ShowCardDetails();

    //perform use case - 1
    //Start -> Enter product Code(available)->Press Enter -> Payment(equal o product cost)->Press Enter -> dispense --> Check state (should be Idle)
    cout<<"\n\n******UseCase1********\n";
    atm->showAtmId();
    UseCase1(atm, "Card1", "12345", 5000);
    atm->ShowCardDetails();
    cout<<"Curent ATM Balance : "<<atm->GetATMBalance()<<"\n";
    
    //perform use case - 2
    cout<<"\n\n******UseCase2********\n";
    ATM *atm2 = ATM::getATMInstance("atm2");
    atm2->showAtmId();
    UseCase1(atm2, "Card2", "12345", 25000);
    atm2->ShowCardDetails();
    cout<<"Curent ATM Balance : "<<atm2->GetATMBalance()<<"\n";

    //perform use case - 3
    cout<<"\n\n******UseCase3********\n";
    atm2->showAtmId();
    UseCase1(atm2, "Card3", "12345", 105000);
    atm2->ShowCardDetails();
    cout<<"Curent ATM Balance : "<<atm2->GetATMBalance()<<"\n";

    //perform use case - 4
    cout<<"\n\n******UseCase3********\n";
    atm2->showAtmId();
    UseCase1(atm2, "Card3", "12346", 105000);
    atm2->ShowCardDetails();
    cout<<"Curent ATM Balance : "<<atm2->GetATMBalance()<<"\n";


return 0;
}
