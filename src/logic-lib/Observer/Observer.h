#ifndef TURBOHIKER_OBSERVER_H
#define TURBOHIKER_OBSERVER_H


enum class ObserverEvent{
    COMPETING_HIKER_COLLISION,
    ENEMY_COLLISION,
    YELLING,
};

class Observer {
public:
    virtual void handleNotification(ObserverEvent event) = 0;
};


#endif //TURBOHIKER_OBSERVER_H
