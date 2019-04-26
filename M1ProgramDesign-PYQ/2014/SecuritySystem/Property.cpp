#include <list>
#include <string>
#include "Property.h"
#include "Guard.h"
#include "MotionDetector.h"

using namespace std;

void Property::alertAllGuards(string description) {
    for (Guard* guard: guards) {
        guard->alert("Intruder at " + description + ", " + name);
    }
}

void Property::addMotionDetector(MotionDetector* detector) {
    detectors.push_back(detector);
    detector->setProperty(this);
}

void Property::addGuard(Guard* guard) {
    guards.push_back(guard);
    guard->setProperty(this);
}

void Property::transferGuard(Guard* guard, Property* property) {
    if (property != this) {
        guards.remove(guard);
        property->addGuard(guard);
    }
}

Property::Property(string name): name(name) {};
