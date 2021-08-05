#ifndef TURBOHIKER_POSITION2D_H
#define TURBOHIKER_POSITION2D_H

class Position2D {
private:
    double x;
    double y;

public:
    Position2D(double x, double y) : x(x), y(y){}

    Position2D(const Position2D& rhs) = default;

    ~Position2D() = default;

    Position2D& operator+= (const Position2D& rhs);

    friend Position2D operator+ (Position2D lhs, const Position2D &rhs);

    Position2D& operator-= (const Position2D& rhs);

    friend Position2D operator- (Position2D lhs, const Position2D &rhs);

    double getY() const;

    void setY(double y);

    double getX() const;

    void setX(double x);

};

#endif //TURBOHIKER_POSITION2D_H
