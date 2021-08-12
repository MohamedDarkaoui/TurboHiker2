#include "SFMLStaticEnemy.h"

SFMLStaticEnemy::SFMLStaticEnemy(unsigned int lane) : StaticEnemy(lane) {

}

const sf::RectangleShape &SFMLStaticEnemy::getShape() const {
    return sf::RectangleShape();
}
