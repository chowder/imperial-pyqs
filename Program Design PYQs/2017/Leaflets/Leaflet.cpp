#include "Leaflet.h"
#include "Text.h"

using namespace std;

Leaflet::Leaflet(int uid): uid(uid) {}

void Leaflet::addElement(Text* element) {
    if (characters + element->length() < CHAR_LIMIT) {
        elements.push_back(element);
        characters += element->length();
    }
}

void Leaflet::useSheet(Sheet* s) {
    sheet = s;
}

void Leaflet::print() 
    for (Text* element: elements) {
        element->printOn(this);
    }
    currentIndex = 1;
}

Leaflet::~Leaflet() {
    for (Text* element: elements) {
        delete element;
    }
}
