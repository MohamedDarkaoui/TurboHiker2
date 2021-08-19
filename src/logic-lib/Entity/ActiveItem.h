#ifndef TURBOHIKER_ACTIVEITEM_H
#define TURBOHIKER_ACTIVEITEM_H

#include "CollectableItem.h"
#include "MovingEnemy.h"
#include "StaticEnemy.h"

namespace TurboHiker{
enum class ActiveItemType {STATIC, MOVING};

class ActiveItem : public CollectableItem {
public:
    /**
     * simple constructor
     * @param lane: the initial lane where the Item is located
     * @param size: the size of the Item
     * @param lanePositionsX: all possible lane x-coordinates
     */
    ActiveItem(unsigned int lane, std::pair<double, double> &size, std::vector<double> &lanePositionsX);

    /**
     * gives the reward to a given competing_hiker, depending on it's position in the race
     * @param competitor: the competing_hiker who is receiving the reward
     * @param others: the other hikers on the trail
     */
    void giveReward(std::shared_ptr<CompetingHiker>& competitor, std::set<std::shared_ptr<CompetingHiker>>& others) final;

    /**
     * does nothing
     */
    void update() override;
};
}

#endif //TURBOHIKER_ACTIVEITEM_H
