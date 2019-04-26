#include <cmath>
#include "Turbocharge.h"

using namespace std;

TurboCharge::TurboCharge(int cylinders, float mass, float power_factor):
                         Engine(cylinders, mass, power_factor) {}

float TurboCharge::benchmark(float distance, float racing_mass) {
    return racing_mass * distance * (1 - log(1 + exp(-distance))) /
           (power_factor * pow(cylinders, 2));
}
