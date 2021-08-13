#include "SFMLMovingEnemy.h"

SFMLMovingEnemy::SFMLMovingEnemy(unsigned int lane, std::pair<double, double> &size,
                                 std::vector<double> &lanePositionsX, double speed, double speedUpFactor,
                                 const std::string &path_to_image) :
                                 MovingEnemy(lane, size, lanePositionsX, speed, speedUpFactor),
                                 SFMLEntity(path_to_image){
    auto relative_position = getRelativePosition(getPosition());
    initialize(size,relative_position);
}
