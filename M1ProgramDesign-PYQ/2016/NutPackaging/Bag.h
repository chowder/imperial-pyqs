#ifndef BAG_H
#define BAG_H

#include <list>

class Nut;
class Label;

class Bag {
    const int capacity;
    Label* label = nullptr;
    std::list<Nut*> contents;
public:
    Bag(int);
    void insert(Nut*);
    std::string getBNI();
    void stick(Label*);
    void showLabel();
    ~Bag();
};

#endif
