#ifndef DRONE_H
#define DRONE_H

#include <functional>

class Pizza;

class Drone {
    float lat;
    float lon;
    float alt;
    Pizza* pizza;
    void move(float, float);
    void changeAltitude(float);
public:
    static float cruising_altidude;
    Drone(float, float, float);
    bool load(Pizza* p);
    void flyTo(float, float, float);
    Pizza* release();
    ~Drone();
};

#endif
