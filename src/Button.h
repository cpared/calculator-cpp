#ifndef SRC_BUTTON_H_
#define SRC_BUTTON_H_

#include <vector>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "Subscriber.h"

class Button: public Subscriber{
 public:
    Button(SDL_Renderer *renderer, const char* text, std::vector<int> dim, TTF_Font* font, SDL_Color color);
    bool isOnHover(int x, int y);
    void Update(SDL_Renderer *renderer, int x, int y) override;
    void Render(SDL_Renderer *renderer) override;
    ~Button();
 private:
    std::vector<Uint8> color = {127, 107, 129, 0};
    SDL_Texture* texture;
    SDL_Rect rect;
};

#endif  // SRC_BUTTON_H_
