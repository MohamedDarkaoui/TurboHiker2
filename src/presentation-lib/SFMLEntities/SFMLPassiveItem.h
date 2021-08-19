#ifndef TURBOHIKER_SFMLPASSIVEITEM_H
#define TURBOHIKER_SFMLPASSIVEITEM_H

#include "../../logic-lib/Entity/PassiveItem.h"
#include "SFMLEntity.h"

namespace SFML {

class SFMLPassiveItem : public TurboHiker::PassiveItem, public SFMLEntity{
public:
    /**
     * simple constructor
     * @param pathToImage: the path to the image
     * @param lane: the initial lane where the Item is located
     * @param size: the size of the Item
     * @param lanePositionsX: all possible lane x-coordinates
     * @param possible_rewards: all possible rewards depending on the position of the hiker on the race
     */
    SFMLPassiveItem(const std::string &pathToImage, unsigned int lane, std::pair<double, double> &size,
                    std::vector<double> &lanePositionsX, std::vector<std::vector<int>>& possible_rewards);

    /**
     * default destructor
     */
    ~SFMLPassiveItem() override = default;

    /**
     * visualizes the passive item
     * @param relativePos: the relative position with respect to a given point
     * @param size: size of the item
     */
    void updateVisuals(const TurboHiker::Position2D& relativePos, std::pair<double,double> size) override;
};
}

#endif //TURBOHIKER_SFMLPASSIVEITEM_H
