#ifndef PIZZA_H
#define PIZZA_H

class Pizza {
    bool cooked = false;
public:
    int weight;
    Pizza(int);
    void cook();
};

#endif
