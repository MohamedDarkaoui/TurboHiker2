#ifndef TURBOHIKER_SFMLFINISHLINE_H
#define TURBOHIKER_SFMLFINISHLINE_H

#include "../../logic-lib/Entity/FinishLine.h"
#include "SFMLEntity.h"

namespace SFML {

class SFMLFinishLine : public TurboHiker::FinishLine, public SFMLEntity {
public:
    /**
     * simple constructor
     * @param pathToImage: the path to the finish line image
     * @param position: the position of the finish line
     * @param size: the size of the shape
     * @param imageCoordinates: row and column of the sprite
     */
    SFMLFinishLine(const std::string &pathToImage, TurboHiker::Position2D position,
                   std::pair<double, double> &size, std::pair<int,int> imageCoordinates);

    /**
     * default destructor
     */
    ~SFMLFinishLine() override = default;

    /**
     * updates entity visuals
     * @param relativePos: the relative position with respect to a given point
     * @param size: size of the finish lane shape
     */
    void updateVisuals(const TurboHiker::Position2D& relativePos, std::pair<double,double> size) override;
};
}

#endif //TURBOHIKER_SFMLFINISHLINE_H
