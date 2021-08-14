#include "SFMLStaticEnemy.h"


SFMLStaticEnemy::SFMLStaticEnemy(unsigned int lane, std::pair<double, double> &size,std::vector<double> &lanePositionsX,
                                 double speed,const std::string &path_to_image) : StaticEnemy(lane, size,
                                 lanePositionsX, speed),SFMLEntity(path_to_image) {
    auto relative_position = getRelativePosition(getPosition());
    initialize(size,relative_position);
    shape.setTextureRect(animation->getCurrentFrame());
}

void SFMLStaticEnemy::updateVisuals(const Position2D& reference) {
    Position2D relativePos = getRelativePosition(reference);
    std::pair<double,double> size = getSize();
    Position2D transformed = Transformation::getInstance().transform(relativePos);
    std::pair<float,float> SFMLSize = Transformation::getInstance().transformSize(size.first,size.second);
    auto x = float(transformed.getX() - SFMLSize.first * 0.5);
    auto y = float(transformed.getY() - SFMLSize.second * 0.5);
    shape.setPosition(x,y);
}

void SFMLStaticEnemy::updateAnimation() {
    if (clock->clockTicked()){
        if (getMovement() == Hiker::MOVING_LEFT){
            animation->update(1);
            shape.setTextureRect(animation->getCurrentFrame());
        }
        else if (getMovement() == Hiker::MOVING_RIGHT){
            animation->update(2);
            shape.setTextureRect(animation->getCurrentFrame());
        }
        else
            shape.setTextureRect(animation->getCurrentFrame());
    }
}
