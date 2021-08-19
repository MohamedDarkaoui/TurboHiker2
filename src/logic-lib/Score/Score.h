#ifndef TURBOHIKER_SCORE_H
#define TURBOHIKER_SCORE_H

#include "../Observer/Observer.h"
#include "../Clock/Clock.h"

namespace TurboHiker{

class Score : public Observer {
private:
    int nr_competing_hiker_collisions = 0;
    int nr_enemy_collisions = 0;
    int nr_yelled_times = 0;
    int nr_bonuses = 0;

public:
    /**
     * handles notifications from the observables
     * @param event: the event that occurred at the observable
     */
    void handleNotification(ObserverEvent event) override;

    /**
     * calculates the score
     * @param player_y_position: the position of the competitor
     * @return the score of the competitor
     */
    int getPoints(double player_y_position) const;

};
}

#endif //TURBOHIKER_SCORE_H
