#ifndef ENGINE_H
#define ENGINE_H

class Engine {
public:
    const int cylinders;
    const float mass;
    const float power_factor;
    Engine(int, float, float);
    virtual float benchmark(float, float) = 0;
};

#endif
