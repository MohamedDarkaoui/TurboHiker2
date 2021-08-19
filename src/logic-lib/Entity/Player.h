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
    /**
     * Simple constructor
     * @param lane: the initial lane where the Hiker is located
     * @param size: the size of the hiker
     * @param lanePositionsX: all possible lane x-coordinates
     * @param speed: the initial speed of the hiker
     * @param speedUpFactor: the factor by which the speed can change
     * @param yellingRange: the range in which enemy hikers can react to the yelling
     */
    Player(unsigned int lane, std::pair<double, double> &size, std::vector<double>& lanePositionsX, double speed,
           double speedUpFactor, double yellingRange);

    /**
     * default destructor
     */
    ~Player() override = default;

    /**
     * changes the yelling status to yelling
     */
    virtual void yell();

    /**
     * simple getter of the yelling variable
     * @return yelling
     */
    bool isYelling() const;

    /**
     * simple getter of the yelling range
     * @return
     */
    double getYellingRange() const;

    /**
     * updates the position, movement, acceleration, speed, etc. of the Player
     */
    void update() override;

};
}

#endif //TURBOHIKER_PLAYER_H
