#ifndef TURBOHIKER_ACTIVEITEM_H
#define TURBOHIKER_ACTIVEITEM_H


#include "CollectableItem.h"
#include "MovingEnemy.h"
#include "StaticEnemy.h"

enum class ActiveItemType {STATIC, MOVING};

class ActiveItem : public CollectableItem {
public:
    ActiveItem(unsigned int lane, std::pair<double, double> &size, std::vector<double> &lanePositionsX);

    void giveReward(std::shared_ptr<CompetingHiker>& competitor, std::set<std::shared_ptr<CompetingHiker>>& others) final;

    void update() override;
};


#endif //TURBOHIKER_ACTIVEITEM_H
