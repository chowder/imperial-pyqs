#include <iostream>
#include <string>
#include "Drone.h"
#include "Pizza.h"

using namespace std;

Drone::Drone(float lat, float lon, float alt):
             lat(lat), lon(lon), alt(alt) {}

float Drone::cruising_altidude = 100;


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
    changeAltitude(cruising_altidude);
    move(lat, lon);
    changeAltitude(alt);
}


void Drone::changeAltitude(float new_alt) {
    cout << (new_alt < alt ? "Descending" : "Ascending")
         << " to " << new_alt << " meters..." << endl;
    alt = new_alt;
}


void Drone::move(float new_lat, float new_lon) {
    cout << "Travelling to " << new_lat << ", " << new_lon << "..." << endl;
    lat = new_lat;
    lon = new_lon;
}


Pizza* Drone::release() {
    if (pizza) {
        cout << "Dropping the pizza..." << endl;
        Pizza* tmp = pizza;
        pizza = nullptr;
        return tmp;
    }
    else cout << "The pizza somehow disappeared!" << endl;
    return nullptr;
}

Drone::~Drone() {
  if (pizza) delete pizza;
}
