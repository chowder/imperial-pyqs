#ifndef TURBOCHARGE_H
#define TURBOCHARGE_H

#include "Engine.h"

class TurboCharge: public Engine {
public:
    TurboCharge(int, float, float);
    float benchmark(float, float);
};

#endif
