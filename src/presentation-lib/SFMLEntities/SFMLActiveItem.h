#ifndef TURBOHIKER_SFMLACTIVEITEM_H
#define TURBOHIKER_SFMLACTIVEITEM_H

#include "../../logic-lib/Entity/ActiveItem.h"
#include "SFMLEntity.h"

namespace SFML{

class SFMLActiveItem : public TurboHiker::ActiveItem, public SFMLEntity{

public:
    /**
     * simple constructor
     * @param pathToImage: path to the active item image
     * @param lane: the initial lane where the Item is located
     * @param size: the size of the Item
     * @param lanePositionsX: all possible lane x-coordinates
     */
    SFMLActiveItem(const std::string &pathToImage, unsigned int lane, std::pair<double, double> &size,
                   std::vector<double> &lanePositionsX);

    /**
     * default destructor
     */
    ~SFMLActiveItem() override = default;

    /**
     * updates entity visuals
     * @param relativePos: the relative position with respect to a given point
     * @param size: size of the active item
     */
    void updateVisuals(const TurboHiker::Position2D &relativePos, std::pair<double, double> size) override;
};
}

#endif //TURBOHIKER_SFMLACTIVEITEM_H
