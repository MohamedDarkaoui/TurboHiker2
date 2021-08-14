#ifndef TURBOHIKER_SFMLGROUNDPLOT_H
#define TURBOHIKER_SFMLGROUNDPLOT_H

#include "SFML/Graphics.hpp"
#include "SFMLEntity.h"
#include "../../logic-lib/Entity/GroundPlot.h"

class SFMLGroundPlot : public GroundPlot, public SFMLEntity{
private:

public:
    SFMLGroundPlot(Position2D position, std::pair<double, double> &size, const std::string& path_to_image,
               std::pair<int,int> dimensions, std::pair<int,int> imageCoordinates);

    void update() final;

    void updateVisuals(const Position2D& reference) final;
};


#endif //TURBOHIKER_SFMLGROUNDPLOT_H
