// Observer Design Pattern
//Publisher - Subscriber

#include <iostream>
#include <string>
#include <list>
#include <queue>
using namespace std;

class ISubscriber;
//Subject
class Observer_Group{
private:
    list<ISubscriber*> observers;

public:
    void Subscribe(ISubscriber* user){
        observers.push_back(user);
    }
    void UnSubscribe(ISubscriber* user){
        observers.remove(user);
    }

    void notify(string str);
};

void Observer_Group::notify(string str){
        for(auto user : observers){
            user->notify(str);
        }
    }

//Observer Interface
class ISubscriber{
public:
    virtual void notify(string str) = 0;
};

//user1
class Subscriber : public ISubscriber{
    int userId;
public:
    Subscriber(int id){
        userId = id;
    }
    void notify(string str){
        cout<<"User - "<<userId<<" Recieved the message - "<<str<<endl;
    }

    void writeMessage(Observer_Group* p, string msg){
        p->notify(msg);
    }

};



int main(){

Subscriber user1(1);
Subscriber user2(2);
Subscriber user3(2);

Observer_Group p;
p.Subscribe(&user1);
p.Subscribe(&user2);
p.Subscribe(&user3);

p.notify("Hello !");

user3.writeMessage(&p, "Hii from User3!");

p.UnSubscribe(&user3);

p.notify("Hello Again!");

return 0;
}