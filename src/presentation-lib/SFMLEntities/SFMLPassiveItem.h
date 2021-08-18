#ifndef TURBOHIKER_SFMLPASSIVEITEM_H
#define TURBOHIKER_SFMLPASSIVEITEM_H

#include "../../logic-lib/Entity/PassiveItem.h"
#include "SFMLEntity.h"

namespace SFML {

class SFMLPassiveItem : public TurboHiker::PassiveItem, public SFMLEntity{
public:
    SFMLPassiveItem(const std::string &pathToImage, unsigned int lane, std::pair<double, double> &size,
                    std::vector<double> &lanePositionsX, std::vector<std::vector<int>>& possible_rewards);

    void update() override;

    void updateVisuals(const TurboHiker::Position2D& relativePos, std::pair<double,double> size) override;
};
}

#endif //TURBOHIKER_SFMLPASSIVEITEM_H
