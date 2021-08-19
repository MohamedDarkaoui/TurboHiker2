#include "PassiveItem.h"

TurboHiker::PassiveItem::PassiveItem(unsigned int lane, std::pair<double, double> &size, std::vector<double> &lanePositionsX,
                         std::vector<std::vector<int>>& possible_rewards)
        : CollectableItem(lane, size, lanePositionsX), possible_rewards(possible_rewards) {

}

void TurboHiker::PassiveItem::giveReward(std::shared_ptr<CompetingHiker>& competitor, std::set<std::shared_ptr<CompetingHiker>>& others) {
    unsigned int position = 0;
    for (const auto& hiker : others){
        if (hiker->getPosition().getY() > competitor->getPosition().getY())
            position++;
    }
    assert(possible_rewards.size() >= others.size());

    std::vector<int> possible_boosts = possible_rewards[position];

    int random = possible_boosts[Random::getInstance().randomInt(0,(int)possible_boosts.size())];
    competitor->speedBoost(random);
    setRewardGiven(true);
}

void TurboHiker::PassiveItem::update() {}
