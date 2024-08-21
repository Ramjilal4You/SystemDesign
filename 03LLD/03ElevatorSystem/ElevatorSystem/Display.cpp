#include "Display.hxx"

#include <iostream>
using namespace std;

Display::~Display()
{
    cout << "Display Deleted\n";
}

Display::Display(string id) {
    displayId = id;
    cout << "Display Created" << " : " << displayId << "\n";
}

string Display::getDisplayId() {
    return displayId;
}
void Display::notify(int ifNumber, string iDirection) {
    cout << "Display : " << displayId << " -> Lift at floor : " << ifNumber << " going : " << iDirection << endl;
}