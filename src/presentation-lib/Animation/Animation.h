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
    /**
     * simple constructor
     * @param texture: the sfml texture
     * @param dimensions: number of images in each column and row
     */
    Animation(const std::shared_ptr<sf::Texture>& texture, sf::Vector2u &dimensions);

    /**
     * simple getter
     * @return currentFrame
     */
    sf::IntRect getCurrentFrame();

    /**
     * updates the current frame to the next one
     * @param row: the row number on the sprite
     */
    void update(unsigned int row);

};
}


#endif //TURBOHIKER_ANIMATION_H
