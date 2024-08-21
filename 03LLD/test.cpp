/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <mutex>


using namespace std;
mutex mtx;

void fun1(){
    
    //mtx.lock();
    lock_guard<mutex> lock(mtx);
    //unique_lock<mutex> ulock(mtx);
    for(int i=1;i<10;i++)
        cout<<i<<" ";
    cout<<"\n";
    //mtx.unlock();
}

int main()
{
    fun1();
    
    return 0;
}