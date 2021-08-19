#ifndef TURBOHIKER_PASSIVEITEM_H
#define TURBOHIKER_PASSIVEITEM_H

#include "CollectableItem.h"

namespace TurboHiker{

class PassiveItem : public CollectableItem {
private:
    std::vector<std::vector<int>> possible_rewards;
public:
    /**
     * simple constructor
     * @param lane: the initial lane where the Item is located
     * @param size: the size of the Item
     * @param lanePositionsX: all possible lane x-coordinates
     * @param possible_rewards: all possible rewards depending on the position of the hiker on the race
     */
    PassiveItem(unsigned int lane, std::pair<double, double> &size, std::vector<double> &lanePositionsX,
                std::vector<std::vector<int>>& possible_rewards);

    /**
     * default destructor
     */
    ~PassiveItem() override = default;

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

#endif //TURBOHIKER_PASSIVEITEM_H
