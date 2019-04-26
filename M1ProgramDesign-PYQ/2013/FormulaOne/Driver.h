#ifndef DRIVER_H
#define DRIVER_H

#include <string>

class Driver {
public:
    const std::string name;
    const float mass;
    Driver(std::string, float);
};

#endif
