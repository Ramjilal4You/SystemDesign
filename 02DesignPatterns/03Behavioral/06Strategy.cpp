// Strategy Design Pattern for Sorting algorithms

#include <iostream>
using namespace std;

//Strategy Interface
class IStrategy{
public:
    virtual void Sort(int arr[]) = 0;
};

//Concrete Strategy 1
class BubbleSort : public IStrategy{
public:
    void Sort(int arr[]){
        cout<<"Using Bubble Sorting Algorithms\n";
    }
};

//Concrete Strategy 2
class QuickSort : public IStrategy{
public:
    void Sort(int arr[]){
        cout<<"Using Quick Sorting Algorithms\n";
    }
};

//Concrete Strategy 3
class MergeSort : public IStrategy{
public:
    void Sort(int arr[]){
        cout<<"Using Merge Sorting Algorithms\n";
    }
};

//Strategy Context
class SortingContext{
private:
    IStrategy *strategy;
public:
    SortingContext(IStrategy *iStrategy):strategy(iStrategy){}
    void setStrategy(IStrategy *iStrategy){
        strategy = iStrategy;
    }
    void performSorting(int arr[]){
        strategy->Sort(arr);
    }
};


//client
int main(){
    BubbleSort bsort;
    QuickSort qsort;
    MergeSort msort;

    SortingContext context(&bsort);
    context.performSorting({});

    //changing strategy
    context.setStrategy(&qsort);
    context.performSorting({});

    //again changing strategy
    context.setStrategy(&msort);
    context.performSorting({});

return 0;
}
