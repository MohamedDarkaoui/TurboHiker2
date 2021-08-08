#ifndef TURBOHIKER_PLAYER_H
#define TURBOHIKER_PLAYER_H

#include "Hiker.h"

class Player : public Hiker{
    bool isYelling = false;
public:
    Player(const Position2D &position, double speed, std::vector<double>& lanePositionsX);

    void yell();

    bool getIsYelling() const;

};


#endif //TURBOHIKER_PLAYER_H
