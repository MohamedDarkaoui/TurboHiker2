#include "CollectableItem.h"

CollectableItem::CollectableItem(unsigned int lane, std::pair<double, double> &size,
                                 std::vector<double> &lanePositionsX) :
                                 Entity(lane, size, lanePositionsX) {}

bool CollectableItem::isRewardGiven() const {
    return reward_given;
}

void CollectableItem::setRewardGiven(bool rewardGiven) {
    reward_given = rewardGiven;
}