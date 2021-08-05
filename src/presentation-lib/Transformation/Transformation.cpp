#include "Transformation.h"

Transformation &Transformation::getInstance() {
    static Transformation instance;
    return instance;
}

Position2D Transformation::transform(Position2D position) const {
    double x = position.getX();
    double y = -position.getY(); //SFML works with an inverted y-axis

    x += 4;
    y += 3;

    x = x * win_x/8;
    y = y * win_y/6;

    return {x,y};
}