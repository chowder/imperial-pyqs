#include <string>
#include <iostream>
#include <cmath>
#include "Player.h"
#include "Court.h"

using namespace std;

Player::Player(string name, float skill, float x, float y):
               name(name), skill(skill), pos_x(x), pos_y(y) {}

void Player::moveTo(float x, float y) {
    if (court) {
        pos_x = x;
        pos_y = y;
        cout << name << " moved to (" << x << ", " << y << ")" << endl;
    }
    else {
        cout << name << " is not on a court" << endl;
    }
}

void Player::passTo(Player* player) {
    if (hasBall) {
        if (court != player->court) {
            cout << name << " is not in the same court as " << player->name << endl;
            return;
        }
        cout << "Passed the ball to " << player->name << endl;
        hasBall = false;
        player->hasBall = true;
    }
    else {
        cout << name << " does not have a ball!" << endl;
    }
}

void Player::giveBall() {
    if (!court) {
        cout << name << " has not joined a court yet!" << endl;
        return;
    }
    if (!hasBall) {
        cout << "Gave " << name << " a ball" << endl;
        hasBall = true;
    }
    else {
        cout << name << " already has a ball!" << endl;
    }
}

void Player::assignCourt(Court* c) {
    court = c;
}

bool Player::rollSuccess() {
    srand48(time(NULL));
    float x = court->distanceFromBasket(pos_x, pos_y);
    float probability = 1 - (1 / (1 + exp(-0.62 * (x - 6.84 * skill))));
    float chance = drand48();
    return chance > probability;
}

void Player::shootBall() {
    if (!hasBall) {
        cout << name << " does not have the ball!" << endl;
        return;
    }
    if (!court) {
        cout << name << " is not on a court!" << endl;
        return;
    }
    cout << name << " tries to shoot the ball..." << endl;
    if (rollSuccess()) {
        int points = court->score(pos_x, pos_y);
        if (points) {
            cout << name << " scored " << points << " points!" << endl;
        }
        else {
            cout << name << " had an invalid throw!" << endl;
        }
    }
    else {
        cout << name << " missed!" << endl;
    }
}
