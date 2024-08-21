// Builder Design Pattern

#include <iostream>
#include <string>

using namespace std;

// Product class
class Computer {
private:
    string cpu_;
    string memory_;
public:
    void setCPU(string cpu) {
        cpu_ = cpu;
    }

    void setMemory(string memory) {
        memory_ = memory;
    }

    void show() {
        cout <<"CPU : "<< cpu_ << endl;
        cout << "Memory : " << memory_ << endl;
    }
};

// Builder interface
class ComputerBuilder {
protected:
    Computer *computer_;
public:
    ComputerBuilder(){
        computer_ = new Computer;
    }
    virtual void buildCPU() = 0;
    virtual void buildMemory() = 0;
    virtual Computer* getProduct(){
        return computer_;
    }
};

// Concrete Builder1
class DesktopComputerBuilder : public ComputerBuilder {
public:
    void buildCPU() override {
        computer_->setCPU("Desktop : Intel i7");
    }

    void buildMemory() override {
        computer_->setMemory("Desktop : 16GB");
    } 
};

// Concrete Builder2
class LaptopComputerBuilder : public ComputerBuilder {
public:
    void buildCPU() override {
        computer_->setCPU("Laptop : Intel i6");
    }

    void buildMemory() override {
        computer_->setMemory("Laptop : 8GB");
    }
};

// Director
class ComputerAssembler {
    ComputerBuilder *builder;
public:
    ComputerAssembler(ComputerBuilder *pBuilder){
        builder = pBuilder;
    }
    Computer* assembleComputer() {
        builder->buildCPU();
        builder->buildMemory();
        return builder->getProduct();
    }
};

int main() 
{
    DesktopComputerBuilder *desktopBuilder = new DesktopComputerBuilder();
    ComputerAssembler *desktopAssembler = new ComputerAssembler(desktopBuilder);
    Computer *desktop = desktopAssembler->assembleComputer();
    desktop->show();

    LaptopComputerBuilder *laptopBuilder = new LaptopComputerBuilder();
    ComputerAssembler *laptopAssembler = new ComputerAssembler(laptopBuilder);
    Computer *laptop = laptopAssembler->assembleComputer();
    laptop->show();
    

    return 0;
}
