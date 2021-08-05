#ifndef TURBOHIKER_TRANSFORMATION_H
#define TURBOHIKER_TRANSFORMATION_H


#include "../../logic-lib/Position/Position2D.h"

class Transformation {
private:
    double win_x = 1040;
    double win_y = 780;

    static Transformation instance;

    Transformation() = default;

public:
    Transformation(Transformation const&) =  delete;

    void operator=(Transformation const&) = delete;

    Position2D transform(Position2D) const;

    static Transformation& getInstance();
};


#endif //TURBOHIKER_TRANSFORMATION_H
