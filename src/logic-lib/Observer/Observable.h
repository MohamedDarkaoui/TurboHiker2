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

    void addObserver(const std::shared_ptr<Observer>& observer);

    void removeObserver(std::shared_ptr<Observer>& observer);

    void notifyObservers(ObserverEvent event);
};
}

#endif //TURBOHIKER_OBSERVABLE_H
