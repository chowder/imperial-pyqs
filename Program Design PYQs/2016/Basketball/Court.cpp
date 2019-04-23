#include <iostream>
#include <cmath>
#include "Player.h"
#include "Court.h"

using namespace std;

bool Court::isOnCourt(float x, float y) {
    return (x > LEFT_BOUND && x < RIGHT_BOUND && x > LOWER_BOUND);
}

bool Court::isInThreePointLine(float x, float y) {
    float distance = sqrt(pow((x - BASKET_X), 2) +
                          pow((y - BASKET_Y), 2));
    // here we assume that it's not possible to shoot from behind the basket
    return distance < THREE_POINT_RADIUS;
}

float Court::distanceFromBasket(float x, float y) {
    return sqrt(pow((x - BASKET_X), 2) +
                pow((y - BASKET_Y), 2));
}

void Court::addPlayer(Player* player) {
    cout << player->name << " has entered the court" << endl;
    player->assignCourt(this);
}

int Court::score(float x, float y) {
    if (isOnCourt(x, y)) {
        if (isInThreePointLine(x, y))
            return 3;
        return 1;
    }
    return 0;
}
