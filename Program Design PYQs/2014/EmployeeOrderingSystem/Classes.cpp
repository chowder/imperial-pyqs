#include <string>
#include <vector>
#include "Classes.h"

using namespace std;

/* COMPONENT IMPLEMENTATIONS */

Component::Component(int price, string make): price(price), make(make) {}

int Component::getPrice() {
    return price;
}

/* MEMORY IMMPLEMENTATIONNS */

Memory::Memory(int price, string make, int size):
               Component(price, make), size(size) {}

float Memory::getScore() {
    return size * 8 + price * 0.1;
}

/* IODEVICE IMPLEMENTATIONS */

IODevice::IODevice(float price, string make, float response_time):
                   Component(price, make), response_time(response_time) {}

float IODevice::getScore() {
    return price * 0.2 + (50 / response_time);
}

/* LAPTOP IMPLEMENTATIONS */

Laptop::Laptop(int base_cost, vector<Component*> components):
               cost(base_cost), components(components) {
    for (Component* component: components) {
        cost += component->getPrice();
        score += component->getScore();
    }
}


int Laptop::getCost() {
    return cost;
}

float Laptop::getScore() {
    return score;
}

void Laptop::addComponent(Component* component) {
    components.push_back(component);
    cost += component->getPrice();
    score += component->getScore();
}

Laptop::~Laptop() {
    for (Component* component: components) {
        delete component;
    }
}


/* EMPLOYEE IMPLEMENTATIONS */
Employee::Employee(string name): name(name) {}

bool Employee::order(int base_cost, vector<Component*> components) {
    // first we calculate if the total cost is under budget
    int total_cost = base_cost;
    for (Component* component: components) {
        total_cost += component->getPrice();
    }
    // then decide if we can buy it
    if (total_cost <= budget) {
        laptop = new Laptop(base_cost, components);
        return true;
    }
    else {
        return false;
    }
}

float Employee::getLaptopScore() {
    return laptop->getScore();
}

bool Employee::addLaptopComponent(Component* component) {
    if (laptop->getCost() + component->getPrice() < budget) {
        laptop->addComponent(component);
        return true;
    }
    else {
        delete component;
        return false;
    }
}

Employee::~Employee() {
    delete laptop;
}
