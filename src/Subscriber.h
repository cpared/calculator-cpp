#ifndef SRC_SUBSCRIBER_H_
#define SRC_SUBSCRIBER_H_

#include "SDL2/SDL.h"

class Subscriber {
 public:
    virtual void Render(SDL_Renderer *renderer) = 0;
    virtual void Update(SDL_Renderer *renderer, int x, int y) = 0;
};

#endif  // SRC_SUBSCRIBER_H_
