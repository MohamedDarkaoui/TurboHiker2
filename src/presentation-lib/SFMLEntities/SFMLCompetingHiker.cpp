#include "SFMLCompetingHiker.h"

SFMLCompetingHiker::SFMLCompetingHiker(double speed, unsigned int lane) : CompetingHiker(speed, lane) {

}

const sf::RectangleShape &SFMLCompetingHiker::getShape() const {
    return sf::RectangleShape();
}
