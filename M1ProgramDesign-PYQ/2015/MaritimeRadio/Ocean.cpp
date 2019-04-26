#include "Ship.h"
#include "Ocean.h"
#include <cmath>
#include <iostream>

using namespace std;

float hav(float theta) {
    return pow(sin(theta/2), 2);
}

float rad(float alpha) {
    return 3.142 * alpha / 180;
}

float distance(float lat1, float lon1, float lat2, float lon2) {
    const float r = 3956;
    float del_lat = lat2 - lat1;
    float del_lon = lon2 - lon1;
    return 2 * r * asin(sqrt(hav(rad(del_lat) +
                             cos(rad(lat1)) *
                             cos(rad(lat2)) *
                             hav(rad(del_lon)))));
}

Ocean::Ocean() {}

Ocean* Ocean::instance = 0;

Ocean* Ocean::getInstance() {
    if (!instance) instance = new Ocean();
    return instance;
}

void Ocean::addShip(Ship* ship) {
    ships.push_back(ship);
}

void Ocean::broadcast(Ship* s) {
    for (Ship* ship: ships) {
        if (ship == s)
            continue;
        float dist = distance(s->lat, s->lon, ship->lat, ship->lon);
        if (dist <= s->range) ship->alert(s->callsign);
    }
}
