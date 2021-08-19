#ifndef TURBOHIKER_SFMLGROUNDPLOT_H
#define TURBOHIKER_SFMLGROUNDPLOT_H

#include "SFML/Graphics.hpp"
#include "SFMLEntity.h"
#include "../../logic-lib/Entity/GroundPlot.h"

namespace SFML {

class SFMLGroundPlot : public TurboHiker::GroundPlot, public SFMLEntity{
private:

public:
    /**
     * simple constructor
     * @param position: the position of the ground
     * @param size: the size of the shape
     * @param path_to_image: path to the ground image
     * @param dimensions: number of rows and columns in the sprite
     * @param imageCoordinates: the coordinate of the image in the sprite
     */
    SFMLGroundPlot(TurboHiker::Position2D position, std::pair<double, double> &size, const std::string& path_to_image,
                   std::pair<int,int> dimensions, std::pair<int,int> imageCoordinates);

    /**
     * default destructor
     */
    ~SFMLGroundPlot() override = default;

    /**
     * updates entity visuals
     * @param relativePos: the relative position with respect to a given point
     * @param size: size of the entity
     */
    void updateVisuals(const TurboHiker::Position2D& relativePos, std::pair<double,double> size) final;
};
}

#endif //TURBOHIKER_SFMLGROUNDPLOT_H
