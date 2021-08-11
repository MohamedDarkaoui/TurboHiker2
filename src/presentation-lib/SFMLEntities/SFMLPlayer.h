#ifndef TURBOHIKER_SFMLPLAYER_H
#define TURBOHIKER_SFMLPLAYER_H

#include <SFML/Graphics.hpp>
#include "../../logic-lib/Entity/Player.h"

class SFMLPlayer : public Player {
private:
    sf::RectangleShape shape;
    sf::Texture player_texture;

public:
    SFMLPlayer(double speed, unsigned int lane, const std::string& path_to_image);

    void handleEvents(sf::Event& event, sf::Window& window);
};


#endif //TURBOHIKER_SFMLPLAYER_H
