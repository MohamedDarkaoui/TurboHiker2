#ifndef TURBOHIKER_OBSERVABLE_H
#define TURBOHIKER_OBSERVABLE_H

#include <memory>
#include <set>
#include "Observer.h"

namespace TurboHiker{
class Observable {
private:
    std::set<std::shared_ptr<Observer>> observers;

public:
    /**
     * adds a new observer to the set of observers
     * @param observer
     */
    void addObserver(const std::shared_ptr<Observer>& observer);

    /**
     * removes an observer from the set of observers
     * @param observer
     */
    void removeObserver(std::shared_ptr<Observer>& observer);

    /**
     * notifies the observers when an events occurs
     * @param event
     */
    void notifyObservers(ObserverEvent event);
};
}

#endif //TURBOHIKER_OBSERVABLE_H
