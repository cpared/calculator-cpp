#include <iostream>
#include <cstdlib>
#include "Button.h"

Button::Button(SDL_Renderer *renderer, const char* text, std::vector<int> dim, TTF_Font* font, SDL_Color color) {
    char* end;
    num = std::strtol(text, &end, 10);
    if (*end == '\0') {
        isNumber = true;
    }

    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    rect = {dim[0], dim[1], 99, 99};
    SDL_FreeSurface(surface);
}

void Button::Render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

bool Button::isOnHover(int x, int y) {
    return x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h;
}

void Button::Update(SDL_Renderer *renderer, int x, int y, Stack* stack) {
    if (isOnHover(x, y)) {
        if (isNumber) {
            std::cout << num << std::endl;
            stack->Push(num);
        }
    }
}

Button::~Button() {
    SDL_DestroyTexture(texture);
}
