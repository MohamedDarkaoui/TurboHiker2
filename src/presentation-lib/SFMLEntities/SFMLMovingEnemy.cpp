#include "SFMLMovingEnemy.h"

SFMLMovingEnemy::SFMLMovingEnemy(unsigned int lane, std::pair<double, double> &size,
                                 std::vector<double> &lanePositionsX, double speed, double speedUpFactor,
                                 const std::string &path_to_image) :
                                 MovingEnemy(lane, size, lanePositionsX, speed, speedUpFactor),
                                 SFMLEntity(path_to_image){
    auto relative_position = getRelativePosition(getPosition());
    initialize(size,relative_position);
    animation->update(0);
    shape.setTextureRect(animation->getCurrentFrame());
}

void SFMLMovingEnemy::updateAnimation() {
    int factor = 1;
    if (getAcceleration() == Hiker::SLOW_DOWN)
        factor = 2;
    int row;
    if (getSpeed() > 0)
        row = 3;
    else
        row = 0;
    setClockTickTime(100*factor);
    if (clock->clockTicked()){
        animation->update(row);
        shape.setTextureRect(animation->getCurrentFrame());
    }
}

void SFMLMovingEnemy::updateVisuals(const Position2D &relativePos, std::pair<double, double> size) {
    SFMLEntity::updateVisuals(relativePos, size);
}
