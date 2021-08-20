#ifndef TURBOHIKER_SFMLBOMB_H
#define TURBOHIKER_SFMLBOMB_H

#include "../../logic-lib/Entity/Bomb.h"
#include "SFMLEntity.h"

namespace SFML{
class SFMLBomb : public TurboHiker::Bomb, public SFMLEntity{

public:
    /**
     * simple constructor
     * @param pathToImage
     * @param position
     * @param size
     */
    SFMLBomb(const std::string &pathToImage, TurboHiker::Position2D position,
             std::pair<double, double> &size, double speed);

    /**
     * default destructor
     */
    ~SFMLBomb() override = default;

    /**
     * updates entity visuals
     * @param relativePos: the relative position with respect to a given point
     * @param size: size of the active bomb
     */
    void updateVisuals(const TurboHiker::Position2D &relativePos, std::pair<double, double> size) override;
};
}


#endif //TURBOHIKER_SFMLBOMB_H
