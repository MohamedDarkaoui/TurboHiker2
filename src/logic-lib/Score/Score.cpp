#include <cmath>
#include <iostream>
#include "Score.h"

void Score::handleNotification(ObserverEvent event) {
    switch(event){
        case ObserverEvent::COMPETING_HIKER_COLLISION:
            nr_competing_hiker_collisions++;
            break;
        case ObserverEvent::ENEMY_COLLISION:
            nr_enemy_collisions++;
            break;
        case ObserverEvent::YELLING:
            nr_yelled_times++;
            break;
    }
}

int Score::getPoints(double player_y_position) const {
    double score = player_y_position *10;

    score -= nr_competing_hiker_collisions * 2;
    score -= nr_yelled_times * 10;
    score -= nr_enemy_collisions * 2;

    if (score < 0)
        score = 0;

    return floor(score);
}
