#ifndef TURBOHIKER_MOVINGHIKER_H
#define TURBOHIKER_MOVINGHIKER_H

#include "Hiker.h"

class MovingHiker : public Hiker {
private:
    double speed;
    double acceleration;

public:
    MovingHiker(Position2D position, State state, double speed, double acceleration) : Hiker(position, state),
                                                                                       speed(speed),
                                                                                       acceleration(acceleration) {}

    void update();

    void updateState(State s);

};

#endif //TURBOHIKER_MOVINGHIKER_H
