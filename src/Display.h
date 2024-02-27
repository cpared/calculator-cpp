#ifndef SRC_DISPLAY_H_
#define SRC_DISPLAY_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include "Subscriber.h"

class Display: public Subscriber {
 public:
    Display(SDL_Renderer *renderer, const char* text, std::vector<int> dim, TTF_Font* font, SDL_Color color);
    void Render(SDL_Renderer *renderer) override;
    void Update(SDL_Renderer *renderer, int x, int y) override;
 private:
    SDL_Rect rect_;
    SDL_Texture* texture_;
    std::vector<Uint8> color_ = {86, 64, 88, 0};
};

#endif  // SRC_DISPLAY_H_
