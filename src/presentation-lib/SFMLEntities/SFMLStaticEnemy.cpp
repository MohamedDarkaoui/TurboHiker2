#include "SFMLStaticEnemy.h"


SFML::SFMLStaticEnemy::SFMLStaticEnemy(unsigned int lane, std::pair<double, double> &size,std::vector<double> &lanePositionsX,
                                 double speed,const std::string &path_to_image) : StaticEnemy(lane, size,
                                 lanePositionsX, speed),SFMLEntity(path_to_image) {
    auto relative_position = getRelativePosition(getPosition());
    initialize(size,relative_position);
    shape.setTextureRect(animation->getCurrentFrame());
}

void SFML::SFMLStaticEnemy::updateAnimation() {
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

void SFML::SFMLStaticEnemy::updateVisuals(const TurboHiker::Position2D &relativePos, std::pair<double, double> size) {
    SFMLEntity::updateVisuals(relativePos, size);
}
