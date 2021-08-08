#ifndef TURBOHIKER_ENTITY_H
#define TURBOHIKER_ENTITY_H

#include <memory>
#include "../Position/Position2D.h"
#include "../Random/Random.h"

class Entity {
protected:

public:

    virtual ~Entity() = default;

    virtual void update() = 0;

};

#endif //TURBOHIKER_ENTITY_H
