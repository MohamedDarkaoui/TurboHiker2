#ifndef TURBOHIKER_GROUNDPLOT_H
#define TURBOHIKER_GROUNDPLOT_H

#include "Entity.h"

namespace TurboHiker{

class GroundPlot : public Entity{
public:
    GroundPlot(Position2D position, std::pair<double, double> &size);
};
}

#endif //TURBOHIKER_GROUNDPLOT_H
