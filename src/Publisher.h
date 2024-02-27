#ifndef SRC_PUBLISHER_H_
#define SRC_PUBLISHER_H_

#include <vector>
#include "Subscriber.h"
#include "SDL2/SDL.h"

class Publisher {
 public:
    void notifyRender(SDL_Renderer* renderer);
    void notifyOnHover(SDL_Renderer* renderer, int x, int y);
    void notifyOnClick(SDL_Renderer* renderer, int x, int y);
    void addSubscriber(Subscriber* subscriber);
    void removeSubscriber(Subscriber* subscriber);
    std::vector<Subscriber*> getSubscribers();
 private:
    std::vector<Subscriber*> subscribers_;
};

#endif  // SRC_PUBLISHER_H_
