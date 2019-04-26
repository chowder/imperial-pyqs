#include <iostream>
#include "User.h"
#include "World.h"

using namespace std;

User::User(string name, float x, float y, int credits):
           name(name), x(x), y(x), credits(credits) {
    world = World::getInstance();
    world->addUser(this);
}

void User::moveTo(float new_x, float new_y) {
    x = new_x;
    y = new_y;
}

int User::getCredits() {
    return credits;
}

void User::addCredits(int i) {
    credits += i;
}

void User::broadcast(string message, float radius) {
    world->broadcast(this, message, radius);
}

void User::alert(string sender, string message) {
    cout << "[" << name << "] " << sender << ": " << message << endl;
}
