#ifndef SRC_DISPLAY_H_
#define SRC_DISPLAY_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include "Subscriber.h"

class Display: public Subscriber {
 public:
    Display(SDL_Renderer *renderer, std::vector<int> dim, SDL_Color color);
    void Render(SDL_Renderer *renderer) override;
    void Update(SDL_Renderer *renderer, int x, int y, Stack* stack) override;
 private:
    std::vector<SDL_Rect> rects_;
    SDL_Surface* surface_;
    SDL_Texture* texture_;
    TTF_Font* font;
    SDL_Color text_color_ = {255, 255, 255, 255};
    std::vector<Uint8> color_ = {86, 64, 88, 0};
    std::vector<int> display_;
};

#endif  // SRC_DISPLAY_H_
