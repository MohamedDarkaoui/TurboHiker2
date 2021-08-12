#ifndef TURBOHIKER_SFMLWORLD_H
#define TURBOHIKER_SFMLWORLD_H


#include "../../logic-lib/Entity/World.h"
#include "../EntityFactory/EntityFactory.h"

class SFMLWorld : public World, public SFMLEntity {
public:
    SFMLWorld(double top, double height, double left, double width);

    ~SFMLWorld() override = default;

    void buildWorld(const std::shared_ptr<AbstractFactory>& factory) override;

};


#endif //TURBOHIKER_SFMLWORLD_H
