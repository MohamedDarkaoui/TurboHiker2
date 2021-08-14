#ifndef TURBOHIKER_SFMLPLAYER_H
#define TURBOHIKER_SFMLPLAYER_H

#include <SFML/Graphics.hpp>
#include "../../logic-lib/Entity/Player.h"
#include "SFMLEntity.h"


class SFMLPlayer : public Player, public SFMLEntity {
private:

public:
    SFMLPlayer(unsigned int lane, std::pair<double, double> &size, std::vector<double>& lanePositionsX, double speed,
               double speedUpFactor, double yellingRange, const std::string& path_to_image);

    void handleEvents(sf::Event& event, sf::RenderWindow& window) override;

    void updateVisuals(const Position2D& reference) override;

    void updateAnimation() override;
};


#endif //TURBOHIKER_SFMLPLAYER_H
