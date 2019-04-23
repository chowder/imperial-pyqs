#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Court;

class Player {
    const std::string name;
    float pos_x;
    float pos_y;
    float skill;
    Court* court = nullptr;
    bool hasBall = false;
    bool rollSuccess();
    void assignCourt(Court*);
    friend class Court;
public:
    Player(std::string, float, float, float);
    void moveTo(float, float);
    void passTo(Player*);
    void shootBall();
    void giveBall();
};

#endif
