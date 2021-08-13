#ifndef TURBOHIKER_SFMLENTITY_H
#define TURBOHIKER_SFMLENTITY_H

#include <cassert>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../Transformation/Transformation.h"
#include "../../logic-lib/Entity/Entity.h"

class AbstractFactory;

class SFMLEntity {
private:
    std::shared_ptr<sf::Texture> texture;

protected:
    sf::RectangleShape shape;

public:
    explicit SFMLEntity(const std::string &path_to_image);

    void updateVisuals(Position2D& relativePosition, std::pair<double,double>& size);

    const sf::RectangleShape& getShape() const;

    virtual void handleEvents(sf::Event &event, sf::RenderWindow& window) {}

    void initialize(const std::pair<double,double> &size, const Position2D& relativePos);
    //virtual void buildWorld (const std::shared_ptr<AbstractFactory>& factory){};

};


#endif //TURBOHIKER_SFMLENTITY_H
