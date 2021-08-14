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

void SFMLMovingEnemy::updateVisuals(const Position2D& reference) {
    Position2D relativePos = getRelativePosition(reference);
    std::pair<double,double> size = getSize();
    Position2D transformed = Transformation::getInstance().transform(relativePos);
    std::pair<float,float> SFMLSize = Transformation::getInstance().transformSize(size.first,size.second);
    auto x = float(transformed.getX() - SFMLSize.first * 0.5);
    auto y = float(transformed.getY() - SFMLSize.second * 0.5);
    shape.setPosition(x,y);
}

void SFMLMovingEnemy::updateAnimation() {
    int factor = 1;
    if (getAcceleration() == Hiker::SLOW_DOWN)
        factor = 2;

    setClockTickTime(100*factor);
    if (clock->clockTicked()){
        animation->update(0);
        shape.setTextureRect(animation->getCurrentFrame());
    }
}
