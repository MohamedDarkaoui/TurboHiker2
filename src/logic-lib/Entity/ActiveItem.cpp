#include "ActiveItem.h"

TurboHiker::ActiveItem::ActiveItem(unsigned int lane, std::pair<double, double>& size,
                                   std::vector<double>& lanePositionsX)
    : CollectableItem(lane, size, lanePositionsX)
{
}

void TurboHiker::ActiveItem::giveReward(std::shared_ptr<CompetingHiker>& competitor,
                                        std::set<std::shared_ptr<CompetingHiker>>& others)
{
        unsigned int position = 0;
        for (const auto& hiker : others) {
                if (hiker->getPosition().getY() > competitor->getPosition().getY())
                        position++;
        }

        int random = Random::getInstance().randomInt(0, 2);
        if (random == 0) {
                if (position >= 2)
                        competitor->pushActiveReward(std::make_pair(true, 0.3));
                else
                        competitor->pushActiveReward(std::make_pair(true, -0.3));
        } else
                competitor->pushActiveReward(std::make_pair(false, 0));

        setRewardGiven(true);
}

void TurboHiker::ActiveItem::update() {}
