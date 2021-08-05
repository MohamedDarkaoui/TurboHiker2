#ifndef TURBOHIKER_ENTITY_H
#define TURBOHIKER_ENTITY_H

#include <memory>
#include "../Position/Position2D.h"


class Entity {

public:
    virtual void update() = 0;
    virtual void getType() = 0;
};

#endif //TURBOHIKER_ENTITY_H
