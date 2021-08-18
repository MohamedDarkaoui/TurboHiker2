#ifndef TURBOHIKER_PASSIVEITEM_H
#define TURBOHIKER_PASSIVEITEM_H

#include "CollectableItem.h"

namespace TurboHiker{

class PassiveItem : public CollectableItem {
private:
    std::vector<std::vector<int>> possible_rewards;
public:
    PassiveItem(unsigned int lane, std::pair<double, double> &size, std::vector<double> &lanePositionsX,
                std::vector<std::vector<int>>& possible_rewards);

    void giveReward(std::shared_ptr<CompetingHiker>& competitor, std::set<std::shared_ptr<CompetingHiker>>& others) final;
};
}

#endif //TURBOHIKER_PASSIVEITEM_H
