#ifndef TURBOHIKER_PLAYER_H
#define TURBOHIKER_PLAYER_H

#include "CompetingHiker.h"

class Player : public CompetingHiker{
private:
    bool yelling;
    double yelling_range;
    int yell_duration;

public:
    Player(double speed, unsigned int lane);

    void yell();

    bool isYelling() const;

    double getYellingRange() const;

    void update() override;
};


#endif //TURBOHIKER_PLAYER_H
