#ifndef TURBOHIKER_COLLECTABLEITEM_H
#define TURBOHIKER_COLLECTABLEITEM_H

#include "CompetingHiker.h"

namespace TurboHiker{

class CollectableItem : public Entity{
private:
    bool reward_given = false;

public:
    /**
     * simple constructor
     * @param lane: the initial lane where the Item is located
     * @param size: the size of the Item
     * @param lanePositionsX: all possible lane x-coordinates
     */
    CollectableItem(unsigned int lane, std::pair<double, double> &size,
                    std::vector<double> &lanePositionsX);

    /**
     * default destructor
     */
    ~CollectableItem() override = default;

    /**
     * gives the reward to a given competing_hiker, depending on it's position in the race
     * @param competitor: the competing_hiker who is receiving the reward
     * @param others: the other hikers on the trail
     */
    virtual void giveReward(std::shared_ptr<CompetingHiker>& competitor, std::set<std::shared_ptr<CompetingHiker>>& others) = 0;

    /**
     * simple getter of reward_given
     * @return reward_given
     */
    bool isRewardGiven() const;

    /**
     * simple setter of reward_given
     * @param rewardGiven: a boolean which indicates if this item has already been collected
     */
    void setRewardGiven(bool rewardGiven);
};
}


#endif //TURBOHIKER_COLLECTABLEITEM_H
