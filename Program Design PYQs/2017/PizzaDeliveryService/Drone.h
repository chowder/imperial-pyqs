#ifndef DRONE_H
#define DRONE_H

class Pizza;

class Drone {
    float lat;
    float lon;
    float alt;
    float* cruise;
    Pizza* pizza;
    void ascend(float);
    void move(float, float);
    void descend(float);
    void release();
public:
    Drone(float, float, float, float*);
    bool load(Pizza* p);
    void flyTo(float, float, float);
};

#endif
