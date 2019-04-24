#include <iostream>
#include "Car.h"
#include "Engine.h"
#include "Driver.h"

using namespace std;

Car::Car(string name, float chassisMass, Engine* engine, float* min_mass):
         name(name), chassisMass(chassisMass), engine(engine),
         min_mass(min_mass) {}

float Car::getRacingMass() {
    if (!driver) {
        cout << name << " does not have a driver!" << endl;
        return -1;
    }
    float racing_mass = chassisMass + engine->mass + driver->mass;
    return racing_mass > *min_mass ? racing_mass : *min_mass;
}

float Car::benchmark(float distance) {
    return engine->benchmark(distance, getRacingMass());
}

void Car::setDriver(Driver* d) {
    driver = d;
}
