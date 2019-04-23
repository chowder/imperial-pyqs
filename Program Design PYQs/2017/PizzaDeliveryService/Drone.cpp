#include <iostream>
#include <string>
#include "Drone.h"
#include "Pizza.h"

using namespace std;


Drone::Drone(float lat, float lon, float alt, float* cruise):
             lat(lat), lon(lon), alt(alt), cruise(cruise) {}


bool Drone::load(Pizza* p) {
    if (p->weight < 500) {
        cout << "Loaded on pizza" << endl;
        pizza = p;
        return true;
    }
    else {
        cout << "Pizza is too heavy to load" << endl;
        return false;
    }
}


void Drone::flyTo(float lat, float lon, float alt) {
    ascend(*cruise);
    move(lat, lon);
    descend(alt);
    if (pizza) release();
}


void Drone::ascend(float new_alt) {
    cout << "Ascending to " << new_alt << " meters..." << endl;
    alt = new_alt;
}


void Drone::move(float new_lat, float new_lon) {
    cout << "Travelling to " << new_lat << ", " << new_lon << "..." << endl;
    lat = new_lat;
    lon = new_lon;
}


void Drone::descend(float new_alt) {
    cout << "Descending to " << new_alt << " meters..." << endl;
    alt = new_alt;
}


void Drone::release() {
    if (pizza) {
        cout << "Dropping the pizza..." << endl;
        delete pizza;
        pizza = nullptr;
    }
    else {
        cout << "The pizza somehow disappeared!" << endl;
    }
}
