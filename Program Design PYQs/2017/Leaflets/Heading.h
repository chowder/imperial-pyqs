#ifndef HEADING_H
#define HEADING_H

#include <string>
#include "Text.h"

class Leaflet;

class Heading: public Text {
public:
    Heading(std::string);
    void printOn(Leaflet*);
};

#endif
