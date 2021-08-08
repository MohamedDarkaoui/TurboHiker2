#include "Player.h"

#include <utility>

Player::Player(const Position2D &position, double speed, std::vector<double>& lanePositionsX) :
                                Hiker(position, speed, lanePositionsX) {}

void Player::yell() {
    isYelling = true;
}

bool Player::getIsYelling() const {
    return isYelling;
}
