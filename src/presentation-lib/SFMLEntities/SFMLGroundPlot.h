#ifndef TURBOHIKER_SFMLGROUNDPLOT_H
#define TURBOHIKER_SFMLGROUNDPLOT_H

#include "SFML/Graphics.hpp"
#include "SFMLEntity.h"
#include "../../logic-lib/Entity/GroundPlot.h"

namespace SFML {

class SFMLGroundPlot : public TurboHiker::GroundPlot, public SFMLEntity{
private:

public:
    SFMLGroundPlot(TurboHiker::Position2D position, std::pair<double, double> &size, const std::string& path_to_image,
                   std::pair<int,int> dimensions, std::pair<int,int> imageCoordinates);

void update() final;

void updateVisuals(const TurboHiker::Position2D& relativePos, std::pair<double,double> size) final;
};
}

#endif //TURBOHIKER_SFMLGROUNDPLOT_H
