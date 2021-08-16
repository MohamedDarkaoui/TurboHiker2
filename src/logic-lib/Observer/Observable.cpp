#include <iostream>
#include "Observable.h"

void Observable::addObserver(const std::shared_ptr<Observer>& observer) {
    observers.insert(observer);
}

void Observable::removeObserver(std::shared_ptr<Observer>& observer) {
    observers.erase(observer);
}

void Observable::notifyObservers(ObserverEvent event) {
    for (auto& observer : observers)
        observer->handleNotification(event);
}
