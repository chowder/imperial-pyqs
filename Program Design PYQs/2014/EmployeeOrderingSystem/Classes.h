#ifndef CLASSES_H
#define CLASSES_H

#include <string>
#include <vector>

class Component {
protected:
    int price;
    std::string make;
public:
    Component(int, std::string);
    int getPrice();
    virtual float getScore() = 0;
};


class Memory: public Component {
    int size;
public:
    Memory(int, std::string, int);
    float getScore();
};


class IODevice: public Component {
    float response_time;
public:
    IODevice(float, std::string, float);
    float getScore();
};


class Laptop {
    int cost;
    int score = 100;
    std::vector<Component*> components;
public:
    Laptop(int, std::vector<Component*>);
    int getCost();
    float getScore();
    void addComponent(Component*);
    ~Laptop();
};


class Employee {
    std::string name;
    Laptop* laptop;
    const int budget = 850;
public:
    Employee(std::string name);
    bool order(int, std::vector<Component*>);
    float getLaptopScore();
    bool addLaptopComponent(Component*);
    ~Employee();
};

#endif
