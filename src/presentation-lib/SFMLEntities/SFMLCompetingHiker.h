
#ifndef TURBOHIKER_SFMLCOMPETINGHIKER_H
#define TURBOHIKER_SFMLCOMPETINGHIKER_H


#include "../../logic-lib/Entity/CompetingHiker.h"
#include "SFMLEntity.h"

class SFMLCompetingHiker : public CompetingHiker, public SFMLEntity{
public:
    SFMLCompetingHiker(unsigned int lane, std::pair<double, double> &size, std::vector<double>& lanePositionsX,
                       double speed, double speedUpFactor, const std::string &path_to_image);

};


#endif //TURBOHIKER_SFMLCOMPETINGHIKER_H
