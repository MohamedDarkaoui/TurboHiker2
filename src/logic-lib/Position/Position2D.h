#ifndef TURBOHIKER_POSITION2D_H
#define TURBOHIKER_POSITION2D_H

namespace TurboHiker{

class Position2D {
private:
    double x;
    double y;

public:
    /**
     * simple constructor
     */
    Position2D() : x(0), y(0){}

    /**
     * simple constructor
     */
    Position2D(double x, double y) : x(x), y(y){}

    /**
     * default copy constructor
     */
    Position2D(const Position2D& rhs) = default;

    /**
     * default destructor
     */
    ~Position2D() = default;

    ////////    operator overloading    ////////
    Position2D& operator+= (const Position2D& rhs);
    friend Position2D operator+ (Position2D lhs, const Position2D &rhs);
    Position2D& operator-= (const Position2D& rhs);
    friend Position2D operator- (Position2D lhs, const Position2D &rhs);
    ////////////////////////////////////////////

    /// getters & setters ///
    double getY() const;
    void setY(double y);
    double getX() const;
    void setX(double x);
    ////////////////////////
};
}
#endif //TURBOHIKER_POSITION2D_H
