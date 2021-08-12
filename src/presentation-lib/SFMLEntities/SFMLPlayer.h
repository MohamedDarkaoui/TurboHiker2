#ifndef TURBOHIKER_SFMLPLAYER_H
#define TURBOHIKER_SFMLPLAYER_H

#include <SFML/Graphics.hpp>
#include "../Transformation/Transformation.h"
#include "../../logic-lib/Entity/Player.h"
#include "SFMLEntity.h"


class SFMLPlayer : public Player, public SFMLEntity {
private:
    sf::RectangleShape shape;
    std::shared_ptr<sf::Texture> texture;

public:
    SFMLPlayer(double speed, unsigned int lane, const std::string& path_to_image);

    const sf::RectangleShape& getShape() const override;

    void handleEvents(sf::Event& event, sf::RenderWindow& window) override;

    void updateVisuals() override;

    void update() override;

    const sf::Texture &getTexture() const;

};


#endif //TURBOHIKER_SFMLPLAYER_H
