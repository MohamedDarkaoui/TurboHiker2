#include "Position2D.h"


Position2D& Position2D::operator+=(const Position2D &rhs) {
    x += rhs.x;
    y += rhs.y;

    return *this;
}

Position2D operator+(Position2D lhs, const Position2D &rhs) {
    return lhs += rhs;
}

Position2D &Position2D::operator-=(const Position2D &rhs) {
    x -= rhs.x;
    y -= rhs.y;

    return *this;
}

Position2D operator-(Position2D lhs, const Position2D &rhs) {
    return lhs -= rhs;
}

double Position2D::getX() const {
    return x;
}

void Position2D::setX(double x) {
    this->x = x;
}

double Position2D::getY() const {
    return y;
}

void Position2D::setY(double y) {
    this->y = y;
}


