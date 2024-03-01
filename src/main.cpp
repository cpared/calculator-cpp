#include <vector>
#include <string>
#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "Button.h"
#include "Publisher.h"
#include "Display.h"

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() != 0) {
        printf("TTF_Init Error: %s\n", TTF_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("GAME",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        400, 600, 0);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    TTF_Font* font = TTF_OpenFont("fonts/Roboto-Black.ttf", 16);
    SDL_Color color = {255, 255, 255, 255};

    Publisher pub;
    pub.addSubscriber(new Button(renderer, "1", {50, 150}, font, color));
    pub.addSubscriber(new Button(renderer, "2", {50, 250}, font, color));
    pub.addSubscriber(new Button(renderer, "3", {50, 350}, font, color));
    pub.addSubscriber(new Button(renderer, "4", {150, 150}, font, color));
    pub.addSubscriber(new Button(renderer, "5", {150, 250}, font, color));
    pub.addSubscriber(new Button(renderer, "6", {150, 350}, font, color));
    pub.addSubscriber(new Button(renderer, "7", {250, 150}, font, color));
    pub.addSubscriber(new Button(renderer, "8", {250, 250}, font, color));
    pub.addSubscriber(new Button(renderer, "9", {250, 350}, font, color));
    pub.addSubscriber(new Button(renderer, "0", {150, 450}, font, color));
    pub.addSubscriber(new Display(renderer, {0, 50}, color));

    // Main loop
    SDL_Event event;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                pub.notifyOnMouseClick(renderer, x, y);
            }
        }

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 86, 64, 88, 0);
        SDL_RenderClear(renderer);

        pub.notifyRender(renderer);

        // Present the screen
        SDL_RenderPresent(renderer);
    }

    // Clean up
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}
