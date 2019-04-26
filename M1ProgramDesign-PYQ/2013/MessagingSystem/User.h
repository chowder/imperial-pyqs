#ifndef USER_H
#define USER_H

#include <string>
class World;

class User {
    const std::string name;
    float x;
    float y;
    int credits;
    World* world;
    void charge(int);
    void alert(std::string, std::string);
    friend class World;
public:
    User(std::string, float, float, int);
    void moveTo(float, float);
    int getCredits();
    void addCredits(int);
    void broadcast(std::string, float);
};

#endif
