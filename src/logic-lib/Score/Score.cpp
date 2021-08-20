#include "Score.h"
#include <cmath>

void TurboHiker::Score::handleNotification(ObserverEvent event)
{
        switch (event) {
        case ObserverEvent::COMPETING_HIKER_COLLISION:
                nr_competing_hiker_collisions++;
                break;
        case ObserverEvent::ENEMY_COLLISION:
                nr_enemy_collisions++;
                break;
        case ObserverEvent::YELLING:
                nr_yelled_times++;
                break;
        case ObserverEvent::BONUS:
                nr_bonuses++;
                break;
        case ObserverEvent::FINISHED:
                finished = true;
                break;
        }
}

int TurboHiker::Score::getPoints(double player_y_position)
{
        if (!finished)
                pos = player_y_position;

        double score = pos * 10;

        score -= nr_competing_hiker_collisions * 20;
        score -= nr_yelled_times * 5;
        score -= nr_enemy_collisions * 10;
        score -= nr_bonuses * 100;

        return floor(score);
}
