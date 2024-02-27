#include <algorithm>
#include <iostream>
#include "Publisher.h"

void Publisher::addSubscriber(Subscriber* subscriber) {
    subscribers_.push_back(subscriber);
}

void Publisher::removeSubscriber(Subscriber* subscriber) {
    subscribers_.erase(std::remove(subscribers_.begin(), subscribers_.end(), subscriber), subscribers_.end());
}

void Publisher::notifyOnHover(SDL_Renderer* renderer, int x, int y) {
    for (auto subscriber : subscribers_) {
        subscriber->Update(renderer, x, y);
    }
}

void Publisher::notifyRender(SDL_Renderer* renderer) {
    for (auto subscriber : subscribers_) {
        subscriber->Render(renderer);
    }
}

std::vector<Subscriber*> Publisher::getSubscribers() {
    return subscribers_;
}
