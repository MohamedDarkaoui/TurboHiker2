#ifndef TURBOHIKER_ANIMATION_H
#define TURBOHIKER_ANIMATION_H

#include <SFML/Graphics.hpp>
#include <memory>

namespace SFML {

class Animation {
private:
    sf::IntRect currentFrame;
    sf::Vector2u dimensions;
    unsigned int currColumn = 0;

public:
    Animation(const std::shared_ptr<sf::Texture>& texture, sf::Vector2u &dimensions);

    sf::IntRect getCurrentFrame();

    void update(unsigned int row);

};
}


#endif //TURBOHIKER_ANIMATION_H
