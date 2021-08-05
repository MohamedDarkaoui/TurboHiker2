#include <SFML/Graphics.hpp>
#include "presentation-lib/Game/Game.h"
#include <iostream>
#include "logic-lib/Position/Position2D.h"
#include "logic-lib/Entity/Entity.h"



int main(){

    Position2D pos(1,1);

    Position2D pos2(1,1);

    Position2D pos3 = pos + pos2;


    std::cout<<pos.getX() <<", " <<pos.getY()<<std::endl;
//    Entity entity(pos3);
//
    SFMLGame game;
//    double x =  entity.getPosition().getX();
//    double y = entity.getPosition().getY();
    game.run();
    return 0;
}
