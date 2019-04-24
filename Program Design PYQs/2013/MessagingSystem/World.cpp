#include <cmath>
#include <iostream>
#include "World.h"
#include "User.h"

using namespace std;

float distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

World::World() {}

World* World::instance = 0;

World* World::getInstance() {
    if (!instance) {
        instance = new World();
    }
    return instance;
}

void World::addUser(User* user) {
    users.push_back(user);
}

void World::broadcast(User* sender, string message, float radius) {
    list<User*> receivers;
    for (User* user: users) {
        if (user == sender) continue;
        if (distance(sender->x, sender->y, user->x, user->y) < radius) {
            receivers.push_back(user);
        }
    }
    if (receivers.size() < sender->credits) {
        for (User* receiver: receivers) {
            receiver->alert(sender->name, message);
            sender->credits--;
        }
    }
    else {
        cout << sender->name << " has insufficient credits!" << endl;
        cout << "Has: " << sender->credits << endl;
        cout << "Required: " << receivers.size() << endl;
    }
}
