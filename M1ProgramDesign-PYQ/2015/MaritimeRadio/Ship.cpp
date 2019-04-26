#include <iostream>
#include "Ship.h"
#include "Ocean.h"

using namespace std;

Ship::Ship(string name, string callsign, float range, float lat, float lon):
           name(name), callsign(callsign), range(range), lat(lat), lon(lon) {
    ocean = Ocean::getInstance();
    ocean->addShip(this);
}

void Ship::moveTo(float new_lat, float new_lon) {
    lat = new_lat;
    lon = new_lon;
}

void Ship::alert(string callsign) {
    cout << "[" << name << "] MAYDAY from " << callsign << endl;
}

void Ship::setEmergency(bool s) {
    inEmergency = s;
}

void Ship::broadcast() {
    if (inEmergency) ocean->broadcast(this);
}
