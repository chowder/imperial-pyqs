#include <iostream>
#include <string>
#include "Pizza.h"

using namespace std;

Pizza::Pizza(int weight): weight(weight) {
}

void Pizza::cook() {
    cout << "Cooking pizza of weight " << weight << "g" << endl;
    cooked = true;
    weight *= 0.85;
    cout << "Done cooking - new pizza weight is " << weight << "g" << endl;
}
