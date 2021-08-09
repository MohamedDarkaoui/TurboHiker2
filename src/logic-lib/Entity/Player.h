#ifndef TURBOHIKER_PLAYER_H
#define TURBOHIKER_PLAYER_H

#include "CompetingHiker.h"

class Player : public CompetingHiker{
    bool yelling;
    double yelling_range;
public:
    Player(const Position2D &position, double speed);

    void yell();

    bool isYelling() const;

    double getYellingRange() const;
};


#endif //TURBOHIKER_PLAYER_H
