#ifndef TURBOHIKER_SFMLPLAYER_H
#define TURBOHIKER_SFMLPLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../../logic-lib/Entity/Player.h"
#include "SFMLEntity.h"

namespace SFML{

class SFMLPlayer : public TurboHiker::Player, public SFMLEntity {
private:
    sf::Sound yelling_sound;
    sf::Sound dashing_sound;
    sf::Sound colliding_sound;


    sf::SoundBuffer yelling_sound_buffer;
    sf::SoundBuffer dashing_sound_buffer;
    sf::SoundBuffer colliding_sound_buffer;

public:
    SFMLPlayer(unsigned int lane, std::pair<double, double> &size, std::vector<double>& lanePositionsX, double speed,
               double speedUpFactor, double yellingRange, const std::string& path_to_image);

    void handleEvents(sf::Event& event, sf::RenderWindow& window) override;

    void updateVisuals(const TurboHiker::Position2D &relativePos, std::pair<double, double> size) override;

    void updateAnimation() override;

    sf::Text visualizeScore(sf::Font& font);

    sf::Text visualizeActiveRewards(sf::Font &font);

    sf::Text visualizePassiveRewards(sf::Font &font);

    void yell() override;

    void collide() override;

    void moveLeft() override;

    void moveRight() override;
};
}

#endif //TURBOHIKER_SFMLPLAYER_H
