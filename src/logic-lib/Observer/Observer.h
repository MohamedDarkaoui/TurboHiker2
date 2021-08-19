#ifndef TURBOHIKER_OBSERVER_H
#define TURBOHIKER_OBSERVER_H

namespace TurboHiker{
enum class ObserverEvent{
    COMPETING_HIKER_COLLISION,
    ENEMY_COLLISION,
    YELLING,
    BONUS
};

class Observer {
public:

    /**
     * handles the notifications from the observables
     * @param event: the event that occurred at the observable
     */
    virtual void handleNotification(ObserverEvent event) = 0;
};

}
#endif //TURBOHIKER_OBSERVER_H
