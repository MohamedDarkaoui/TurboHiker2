#ifndef TURBOHIKER_PLAYER_H
#define TURBOHIKER_PLAYER_H

#include "CompetingHiker.h"

namespace TurboHiker{

class Player : public CompetingHiker {
private:
    bool yelling;
    double yelling_range;
    int yell_duration;

public:
    Player(unsigned int lane, std::pair<double, double> &size, std::vector<double>& lanePositionsX, double speed,
           double speedUpFactor, double yellingRange);

    virtual void yell();

    bool isYelling() const;

    double getYellingRange() const;

    void update() override;

};
}

#endif //TURBOHIKER_PLAYER_H
