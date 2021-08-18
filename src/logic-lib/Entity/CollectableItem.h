#ifndef TURBOHIKER_COLLECTABLEITEM_H
#define TURBOHIKER_COLLECTABLEITEM_H

#include "Entity.h"
#include "CompetingHiker.h"
namespace TurboHiker{

class CollectableItem : public Entity{
private:
    bool reward_given = false;

public:
    CollectableItem(unsigned int lane, std::pair<double, double> &size,
                    std::vector<double> &lanePositionsX);

    virtual void giveReward(std::shared_ptr<CompetingHiker>& competitor, std::set<std::shared_ptr<CompetingHiker>>& others) = 0;

    bool isRewardGiven() const;

    void setRewardGiven(bool rewardGiven);
};
}


#endif //TURBOHIKER_COLLECTABLEITEM_H
