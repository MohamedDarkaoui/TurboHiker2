#include "MovingHiker.h"

void MovingHiker::update() {
    if (state == Hiker::MOVING_STRAIGHT)
        position += {0,0.0001};
    else if (state == Hiker::MOVING_LEFT)
        position += {-0.0001,0.0001};
    else if (state == Hiker::MOVING_RIGHT)
        position += {0.0001,0.0001};
}

void MovingHiker::updateState(Hiker::State s) {
    state = s;
}
