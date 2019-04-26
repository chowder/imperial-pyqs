#ifndef SUPERMAN_H
#define SUPERMAN_H

#include "Engine.h"

class Superman: public Engine {
public:
    Superman(int, float, float);
    float benchmark(float, float);
};

#endif
