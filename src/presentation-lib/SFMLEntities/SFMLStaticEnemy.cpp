#include "SFMLStaticEnemy.h"


SFMLStaticEnemy::SFMLStaticEnemy(unsigned int lane, std::pair<double, double> &size,std::vector<double> &lanePositionsX,
                                 double speed,const std::string &path_to_image) : StaticEnemy(lane, size,
                                 lanePositionsX, speed),SFMLEntity(path_to_image) {
    auto relative_position = getRelativePosition(getPosition());
    initialize(size,relative_position);
}
