#ifndef TURBOHIKER_GROUNDPLOT_H
#define TURBOHIKER_GROUNDPLOT_H

#include "Entity.h"

namespace TurboHiker{

class GroundPlot : public Entity{
public:
    /**
     * simple constructor
     * @param position: the position of the ground
     * @param size: the size of the shape
     */
    GroundPlot(Position2D position, std::pair<double, double> &size);

    /**
     * default destructor
     */
    ~GroundPlot() override = default;

    /**
     * does nothing
     */
    void update() final;
};
}

#endif //TURBOHIKER_GROUNDPLOT_H
