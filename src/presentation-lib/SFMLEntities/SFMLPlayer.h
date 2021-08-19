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
    /**
     * simple constructor
     * @param lane: the initial lane where the Hiker is located
     * @param size: the size of the hiker
     * @param lanePositionsX: all possible lane x-coordinates
     * @param speed: the initial speed of the hiker
     * @param speedUpFactor: the factor by which the speed can change
     * @param yellingRange: the range in which enemy hikers can react to the yelling
     * @param path_to_image: the path to the image of the competing hiker
     */
    SFMLPlayer(unsigned int lane, std::pair<double, double> &size, std::vector<double>& lanePositionsX, double speed,
               double speedUpFactor, double yellingRange, const std::string& path_to_image);

    /**
     * default destructor
     */
    ~SFMLPlayer() override = default;

    /**
     * handles player input
     * @param event: the sfml event
     * @param window: the sfml render window
     */
    void handleEvents(sf::Event& event, sf::RenderWindow& window) override;

    /**
     * updates player visuals
     * @param relativePos: the relative position with respect to a given point
     * @param size: size of the entity
     */
    void updateVisuals(const TurboHiker::Position2D &relativePos, std::pair<double, double> size) override;

    /**
     * updates the animation
     */
    void updateAnimation() override;

    /**
     * visualizes the score on the scree
     * @param font: the font that is used for the text
     * @return the sfml text that visualizes the score
     */
    sf::Text visualizeScore(sf::Font& font);

    /**
     * visualizes the active rewards on the screen
     * @param font: the font that is used for the text
     * @return the sfml text that visualizes the active rewards
     */
    sf::Text visualizeActiveRewards(sf::Font &font);

    /**
     * visualizes the passive rewards on the screen
     * @param font: the font that is used for the text
     * @return the sfml text that visualizes the passive rewards
     */
    sf::Text visualizePassiveRewards(sf::Font &font);

    /**
     * player::yell and play yelling sound
     */
    void yell() override;

    /**
     * player::collide and play colliding sound
     */
    void collide() override;

    /**
     * player::moveLeft and play dashing sound
     */
    void moveLeft() override;

    /**
     * player::moveRight and play dashing sound
     */
    void moveRight() override;
};
}

#endif //TURBOHIKER_SFMLPLAYER_H
