#include <algorithm>
#include <iostream>
#include "Publisher.h"

Publisher::Publisher() {
    stack_ = Stack();
}

void Publisher::addSubscriber(Subscriber* subscriber) {
    subscribers_.push_back(subscriber);
}

void Publisher::removeSubscriber(Subscriber* subscriber) {
    subscribers_.erase(std::remove(subscribers_.begin(), subscribers_.end(), subscriber), subscribers_.end());
}

void Publisher::notifyOnMouseClick(SDL_Renderer* renderer, int x, int y) {
    for (auto subscriber : subscribers_) {
        subscriber->Update(renderer, x, y, &stack_);
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

Publisher::~Publisher() {
    for (auto subscriber : subscribers_) {
        delete subscriber;
    }
}
