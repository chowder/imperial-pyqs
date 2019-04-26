#include <string>
#include "MotionDetector.h"
#include "Property.h"

using namespace std;

void MotionDetector::setProperty(Property* p) {
        property = p;
}

void MotionDetector::activate() {
    property->alertAllGuards(description);
}

MotionDetector::MotionDetector(string description): description(description) {};
