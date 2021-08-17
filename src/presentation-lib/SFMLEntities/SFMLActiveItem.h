#ifndef TURBOHIKER_SFMLACTIVEITEM_H
#define TURBOHIKER_SFMLACTIVEITEM_H


#include "../../logic-lib/Entity/ActiveItem.h"
#include "SFMLEntity.h"

class SFMLActiveItem : public ActiveItem, public SFMLEntity{

public:
    SFMLActiveItem(const std::string &pathToImage, unsigned int lane, std::pair<double, double> &size,
                   std::vector<double> &lanePositionsX);

    void updateVisuals(const Position2D &relativePos, std::pair<double, double> size) override;
};


#endif //TURBOHIKER_SFMLACTIVEITEM_H
