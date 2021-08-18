#include "Position2D.h"


TurboHiker::Position2D& TurboHiker::Position2D::operator+=(const Position2D &rhs) {
    x += rhs.x;
    y += rhs.y;

    return *this;
}

TurboHiker::Position2D operator+(TurboHiker::Position2D lhs, const TurboHiker::Position2D &rhs) {
    return lhs += rhs;
}

TurboHiker::Position2D &TurboHiker::Position2D::operator-=(const Position2D &rhs) {
    x -= rhs.x;
    y -= rhs.y;

    return *this;
}

TurboHiker::Position2D operator-(TurboHiker::Position2D lhs, const TurboHiker::Position2D &rhs) {
    return lhs -= rhs;
}

double TurboHiker::Position2D::getX() const {
    return x;
}

void TurboHiker::Position2D::setX(double x) {
    this->x = x;
}

double TurboHiker::Position2D::getY() const {
    return y;
}

void TurboHiker::Position2D::setY(double y) {
    this->y = y;
}


