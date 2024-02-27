
#include "Display.h"

Display::Display(SDL_Renderer *renderer, const char* text, std::vector<int> dim, TTF_Font* font, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
    texture_ = SDL_CreateTextureFromSurface(renderer, surface);
    rect_ = {dim[0], dim[1], 400, 150};
    SDL_FreeSurface(surface);
}

void Display::Render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, color_[0], color_[1], color_[2], color_[3]);
    SDL_RenderFillRect(renderer, &rect_);
    SDL_RenderCopy(renderer, texture_, NULL, &rect_);
}

void Display::Update(SDL_Renderer *renderer, int x, int y) {
    // Do nothing
}
