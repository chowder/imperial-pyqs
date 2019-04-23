#ifndef MOTION_H
#define MOTION_H

#include <string>

class Property;

class MotionDetector {
    Property* property;
    std::string description;
    void setProperty(Property* p);
    friend class Property;
public:
    MotionDetector(std::string);
    void activate();
};

#endif
