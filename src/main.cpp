#include <SFML/Graphics.hpp>
#include "presentation-lib/Game/Game.h"
#include <iostream>
#include "logic-lib/Position/Position2D.h"
#include "logic-lib/Entity/Entity.h"

#include "logic-lib/Random/Random.h"
#include "logic-lib/Entity/Player.h"
#include "logic-lib/Entity/Hiker.h"
#include "logic-lib/Entity/MovingHiker.h"


int main(){


    SFMLGame game;

    game.run();
    return 0;
}
