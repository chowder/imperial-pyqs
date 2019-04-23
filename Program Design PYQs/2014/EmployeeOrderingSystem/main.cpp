#include <iostream>
#include "Classes.h"

using namespace std;


int main() {
    bool res;
    // Andrew orders a laptop
    Employee andrew = Employee("andrew");
    vector<Component*> components = {new Memory(90, "Crucial", 8),
                                     new Memory(90, "Crucial", 8),
                                     new IODevice(150, "Samsung", 5.5)};
    res = andrew.order(500, components);
    cout << "Laptop order: " << (res ? "Success" : "Failed") << endl << endl;
    // Andrew gets his laptop's score
    cout << "Laptop score is: " << andrew.getLaptopScore() << endl << endl;
    // Andrew adds a new component to his laptop
    res = andrew.addLaptopComponent(new Memory(50, "Corsair", 4));
    cout << "Adding more memory: " << (res ? "Success" : "Failed") << endl;
    cout << "New laptop score is: " << andrew.getLaptopScore() << endl << endl;
}
