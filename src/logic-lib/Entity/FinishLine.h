#ifndef TURBOHIKER_FINISHLINE_H
#define TURBOHIKER_FINISHLINE_H

#include "Entity.h"

namespace TurboHiker{

class FinishLine : public Entity{
private:

public:
    /**
     * simple constructor
     * @param position: the position of the finish line
     * @param size: the size of the shape
     */
    FinishLine(Position2D position, std::pair<double, double> &size);

    /**
     * derault destructor
     */
    ~FinishLine() override = default;

    /**
     * does nothing
     */
    void update() override;
};
}

#endif //TURBOHIKER_FINISHLINE_H
