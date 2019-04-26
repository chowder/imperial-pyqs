#include <cmath>
#include "Superman.h"

using namespace std;

Superman::Superman(int cylinders, float mass, float power_factor):
                   Engine(cylinders, mass, power_factor) {}

float Superman::benchmark(float distance, float racing_mass) {
    return sqrt(2 * racing_mass * distance / (power_factor * cylinders));
}
