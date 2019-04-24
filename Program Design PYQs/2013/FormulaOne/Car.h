#ifndef CAR_H
#define CAR_H

#include <string>

class Driver;
class Engine;

class Car {
    const std::string name;
    Driver* driver;
    const float chassisMass;
    Engine* engine;
    float* min_mass;
public:
    Car(std::string, float, Engine*, float*);
    float getRacingMass();
    float benchmark(float);
    void setDriver(Driver*);
};

#endif
