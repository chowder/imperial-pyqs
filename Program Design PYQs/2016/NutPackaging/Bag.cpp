#include <string>
#include <iostream>
#include "Bag.h"
#include "Nut.h"
#include "Label.h"

using namespace std;

Bag::Bag(int capacity): capacity(capacity) {}

void Bag::insert(Nut* nut) {
    if (contents.size() < capacity) {
        cout << "Added a nut!" << endl;
        contents.push_back(nut);
    }
    else cout << "Bag is full, did not add nut" << endl;
}

string Bag::getBNI() {
    float kcal = 0;
    float fat = 0;
    for (Nut* nut: contents) {
        kcal += nut->getEnergy();
        fat += nut->getFat();
    }
    string bni = "Total of " + to_string(int(kcal)) + " kcal (" +
                 to_string(int(fat)) + " g fat)";
    if (fat > 20) bni += " [high in fat]";
    return bni;
}

void Bag::stick(Label* l) {
    if (label) delete label;
    label = l;
}

void Bag::showLabel() {
    if (label) cout << "'" << label->body << "'" << endl;
    else cout << "There is no label!" << endl;
}

Bag::~Bag() {
    for (Nut* nut: contents) {
        delete nut;
    }
}
