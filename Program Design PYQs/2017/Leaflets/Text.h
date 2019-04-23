#ifndef TEXT_H
#define TEXT_H

#include <string>

class Leaflet;

class Text {
public:
    const std::string body;
    Text(std::string);
    int length();
    virtual void printOn(Leaflet*) = 0;
};

#endif
