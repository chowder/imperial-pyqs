#include <string>
#include <iostream>
#include "Guard.h"
#include "Property.h"

using namespace std;

void Guard::alert(string message) {
    cout << "[" + name + "] " + message << endl;
}

void Guard::setProperty(Property* p) {
    property = p;
}

Guard::Guard(string name): name(name){};
