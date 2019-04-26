#ifndef DRONE_H
#define DRONE_H

#include <functional>

class Pizza;

class Drone {
    float lat;
    float lon;
    float alt;
    std::function<float()>* getAltitude;
    Pizza* pizza;
    void ascend(float);
    void move(float, float);
    void descend(float);
    void release();
public:
    Drone(float, float, float, std::function<float()>*);
    bool load(Pizza* p);
    void flyTo(float, float, float);
};

#endif
