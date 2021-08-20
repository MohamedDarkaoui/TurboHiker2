#include "Observable.h"
#include <iostream>

void TurboHiker::Observable::addObserver(const std::shared_ptr<Observer>& observer) { observers.insert(observer); }

void TurboHiker::Observable::removeObserver(std::shared_ptr<Observer>& observer) { observers.erase(observer); }

void TurboHiker::Observable::notifyObservers(ObserverEvent event)
{
        for (auto& observer : observers)
                observer->handleNotification(event);
}
