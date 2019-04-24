#ifndef SHIP_H
#define SHIP_H

#include <string>

class Ocean;

class Ship {
    const std::string name;
    const std::string callsign;
    const float range;
    Ocean* ocean;
    bool inEmergency = false;
    float lat, lon;
    friend class Ocean;
public:
    Ship(std::string, std::string, float, float, float);
    void moveTo(float, float);
    void alert(std::string callsign);
    void setEmergency(bool);
    void broadcast();
};


#endif
