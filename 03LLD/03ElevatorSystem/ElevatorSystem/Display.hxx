#pragma once

#include "Constants.hxx"

#include <string>

using namespace std;

class Display {
private:
    string displayId;
public:
    ~Display();
    Display(string id);
    string getDisplayId();

    void notify(int ifNumber, string iDirection);
};