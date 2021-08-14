#include "Animation.h"

Animation::Animation(const std::shared_ptr<sf::Texture>& texture, sf::Vector2u &dimensions) {
    this->dimensions = dimensions;

    currentFrame.width = int(texture->getSize().x / dimensions.x);
    currentFrame.height = int(texture->getSize().y / dimensions.y);
}


sf::IntRect Animation::getCurrentFrame() {
    return currentFrame;
}

void Animation::update(unsigned int row) {
    if (currColumn > dimensions.x - 1)
        currColumn = 0;

    currentFrame.left = int(currColumn) * currentFrame.width;
    currentFrame.top = int(row) * currentFrame.height;
    currColumn++;
}
