#ifndef TURBOHIKER_SFMLENTITY_H
#define TURBOHIKER_SFMLENTITY_H

#include <cassert>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../Transformation/Transformation.h"
#include "../../logic-lib/Entity/Entity.h"
#include "../Animation/Animation.h"
#include "../../logic-lib/Clock/Clock.h"

namespace TurboHiker{
    class AbstractFactory;
}

namespace SFML{

class SFMLEntity {
private:
    std::shared_ptr<sf::Texture> texture;

protected:
    sf::RectangleShape shape;
    std::unique_ptr<Animation> animation;
    std::unique_ptr<TurboHiker::Clock> clock;

public:
    /**
     * simple constructor
     * @param path_to_image: the path to the image of the entity
     */
    explicit SFMLEntity(const std::string &path_to_image);

    /**
     * default destructor
     */
    virtual ~SFMLEntity() = default;

    /**
     * simple getter
     * @return shape
     */
    const sf::RectangleShape& getShape() const;

    /**
     * handles sfml events
     * @param event: the event
     * @param window: the window
     */


    /**
     * helps construct an entity
     * @param size: size of the entity
     * @param relativePos: the relative position with respect to a given point
     */
    void initialize(const std::pair<double,double> &size, const TurboHiker::Position2D& relativePos);

    /**
     * sets the ticking time of a clock to a new value
     * @param tickTime: the new tick_time
     */
    void setClockTickTime(const unsigned int& tickTime);

    /**
     * updates entity visuals
     * @param relativePos: the relative position with respect to a given point
     * @param size: size of the entity
     */
    virtual void updateVisuals(const TurboHiker::Position2D& relativePos, std::pair<double,double> size);

    /**
     * updates the animation
     */
    virtual void updateAnimation();

};
}

#endif //TURBOHIKER_SFMLENTITY_H
