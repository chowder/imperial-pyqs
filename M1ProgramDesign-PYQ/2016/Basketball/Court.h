#ifndef COURT_H
#define COURT_H

class Player;

class Court {
    const float LEFT_BOUND = 0;
    const float RIGHT_BOUND = 15;
    const float LOWER_BOUND = 0;

    const float THREE_POINT_RADIUS = 6.6;
    const float BASKET_X = 7.5;
    const float BASKET_Y = 1.575;

    int score(float, float);
    float distanceFromBasket(float, float);
    bool isOnCourt(float, float);
    bool isInThreePointLine(float, float);
    friend class Player;

public:
    void addPlayer(Player*);
};

#endif
