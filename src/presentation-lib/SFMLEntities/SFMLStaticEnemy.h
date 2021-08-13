#ifndef TURBOHIKER_SFMLSTATICENEMY_H
#define TURBOHIKER_SFMLSTATICENEMY_H


#include "../../logic-lib/Entity/StaticEnemy.h"
#include "SFMLEntity.h"

class SFMLStaticEnemy : public StaticEnemy, public SFMLEntity{

public:
    SFMLStaticEnemy(unsigned int lane, std::pair<double, double> &size,std::vector<double> &lanePositionsX, double speed,
                    const std::string &path_to_image);


};


#endif //TURBOHIKER_SFMLSTATICENEMY_H
