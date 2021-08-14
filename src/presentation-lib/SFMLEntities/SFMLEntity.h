#ifndef TURBOHIKER_SFMLENTITY_H
#define TURBOHIKER_SFMLENTITY_H

#include <cassert>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../Transformation/Transformation.h"
#include "../../logic-lib/Entity/Entity.h"
#include "../Animation/Animation.h"
#include "../../logic-lib/Clock/Clock.h"

class AbstractFactory;

class SFMLEntity {
private:
    std::shared_ptr<sf::Texture> texture;

protected:
    sf::RectangleShape shape;
    std::unique_ptr<Animation> animation;
    std::unique_ptr<Clock> clock;

public:
    explicit SFMLEntity(const std::string &path_to_image);

    const sf::RectangleShape& getShape() const;

    virtual void handleEvents(sf::Event &event, sf::RenderWindow& window) {}

    virtual void updateAnimation();

    void initialize(const std::pair<double,double> &size, const Position2D& relativePos);

    void setClockTickTime(const unsigned int& tickTime);

};


#endif //TURBOHIKER_SFMLENTITY_H
