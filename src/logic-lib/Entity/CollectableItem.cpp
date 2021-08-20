#include "CollectableItem.h"

TurboHiker::CollectableItem::CollectableItem(unsigned int lane, std::pair<double, double>& size,
                                             std::vector<double>& lanePositionsX)
    : Entity(lane, size, lanePositionsX)
{
}

bool TurboHiker::CollectableItem::isRewardGiven() const { return reward_given; }

void TurboHiker::CollectableItem::setRewardGiven(bool rewardGiven) { reward_given = rewardGiven; }