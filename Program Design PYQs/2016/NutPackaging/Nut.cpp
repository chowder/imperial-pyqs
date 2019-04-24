#include "Nut.h"

Nut::Nut(float weight, float fatPercentage):
         weight(weight), fatPercentage(fatPercentage){}

float Nut::getFat() {
    return weight * fatPercentage;
}

float Nut::getEnergy() {
    float fat = weight * fatPercentage;
    float non_fat = weight - fat;
    return (fat * 9) + (non_fat * 4);
}
