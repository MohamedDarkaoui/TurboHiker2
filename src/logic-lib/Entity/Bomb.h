#ifndef TURBOHIKER_BOMB_H
#define TURBOHIKER_BOMB_H

#include "Entity.h"

namespace TurboHiker {
class Bomb : public Entity {
private:
    double speed;
public:
    /**
     * simple constructor
     * @param position: the initial position of the bomb
     * @param size: the size of the bomb
     */
    Bomb(Position2D position, std::pair<double, double> &size, double speed);

    /**
     * default destructor
     */
    ~Bomb() override = default;

    /**
     * updates the bomb position
     */
    void update() override;
};
}

#endif //TURBOHIKER_BOMB_H
