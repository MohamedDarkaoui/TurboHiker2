#include "Player.h"

#include <utility>

Player::Player(const Position2D &position, double speed) : CompetingHiker(position, speed) {
    yelling_range = 2;
    yelling = false;
}

void Player::yell() {
    yelling = true;
}

bool Player::isYelling() const {
    return yelling;
}

double Player::getYellingRange() const {
    return yelling_range;
}
