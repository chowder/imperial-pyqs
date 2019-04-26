#ifndef WORLD_H
#define WORLD_H

#include <string>
#include <list>

class User;

class World {
    World();
    static World* instance;
    std::list<User*> users;
public:
    static World* getInstance();
    void broadcast(User*, std::string, float);
    void addUser(User*);
};

#endif
