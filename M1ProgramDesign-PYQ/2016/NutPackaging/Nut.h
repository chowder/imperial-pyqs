#ifndef NUT_H
#define NUT_H

class Nut {
    const float weight;
    const float fatPercentage;
protected:
    // Hide the constructor to non-derived classes
    Nut(float, float);
public:
    float getFat();
    float getEnergy();
};

#endif
