#ifndef PARAGRAPH_H
#define PARAGRAPH_H

#include <string>
#include "Text.h"

class Leaflet;

class Paragraph: public Text {
public:
    Paragraph(std::string);
    void printOn(Leaflet*);
};

#endif
