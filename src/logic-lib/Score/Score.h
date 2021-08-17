#ifndef TURBOHIKER_SCORE_H
#define TURBOHIKER_SCORE_H

#include "../Observer/Observer.h"
#include "../Clock/Clock.h"

class Score : public Observer {
private:
    int nr_competing_hiker_collisions = 0;
    int nr_enemy_collisions = 0;
    int nr_yelled_times = 0;
    int nr_bonuses = 0;
public:

    void handleNotification(ObserverEvent event) override;

    int getPoints(double player_y_position) const;

};


#endif //TURBOHIKER_SCORE_H
