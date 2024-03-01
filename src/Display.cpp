#include <iostream>
#include <sstream>
#include <string>
#include "Display.h"

Display::Display(SDL_Renderer *renderer, std::vector<int> dim, SDL_Color color) {
    font = TTF_OpenFont("fonts/Roboto-Black.ttf", 16);
    surface_ = TTF_RenderText_Solid(font, "0", color);
    texture_ = SDL_CreateTextureFromSurface(renderer, surface_);
    for (int i = 0; i < 10; i++) {
        SDL_Rect rect = {dim[0] + i * 40, dim[1], 40, 60};
        rects_.push_back(rect);
    }
    SDL_FreeSurface(surface_);
}

void Display::Render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, color_[0], color_[1], color_[2], color_[3]);
    int size = display_.size();
    for (int i = 0; i < size; i++) {
        std::ostringstream oss;
        oss << display_[i];
        std::string str = oss.str();
        surface_ = TTF_RenderText_Solid(font, str.c_str() , text_color_);
        texture_ = SDL_CreateTextureFromSurface(renderer, surface_);
        SDL_FreeSurface(surface_);
        SDL_RenderFillRect(renderer, &rects_[i]);
        SDL_RenderCopy(renderer, texture_, NULL, &rects_[i]);
    }
}

void Display::Update(SDL_Renderer *renderer, int x, int y, Stack* stack) {
    if (stack->Top() != -1) {
        display_.push_back(stack->Top());
    }
}
