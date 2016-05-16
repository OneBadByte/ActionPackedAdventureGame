//
// Created by blackdartq on 5/11/16.
//

#include <SDL2/SDL.h>
#include "Screen.h"

using namespace std;

Screen::Screen() {



} //initializes SDL_Init and then creates a screen and renderer


void Screen::createScreen() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {

        cout << "SDL init failed" << endl;

    }
    cout << "SDL succeeded" << endl;

    window = SDL_CreateWindow("Adventure", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREENHEIGHT, SCREENWIDTH,
                              SDL_WINDOW_RESIZABLE);


} // Opens window to 1000px width, 1000px height called window

void Screen::createRenderer() {

    renderer = SDL_CreateRenderer(window, -1, 0);

}  //Creates a renderer using the window


void Screen::quitSDL() {

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

} //Destroys the renderer and the quits SDL

void Screen::changeBackground(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

} //changes the background color using rgba,clears, and renders it.

void Screen::quitOnExitButtonPress() {


}


Screen::~Screen() {

}




void Screen::loadAndRenderBmp(const char *imagePath) {

    SDL_Texture *texture1;
    surface = SDL_LoadBMP(imagePath);
    texture1 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture1, NULL, NULL);
    SDL_DestroyTexture(texture1);

}


void Screen::loadAndRenderBmp(const char *imagePath, SDL_Rect rect) {

    SDL_Texture *texture1;
    surface = SDL_LoadBMP(imagePath);
    texture1 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture1, NULL, &rect);
    SDL_DestroyTexture(texture1);


}

void Screen::changeGroundWithBmp(const char *image) {

    groundRect.x = 0;
    groundRect.y = 900;
    groundRect.w = 1000;
    groundRect.h = 100;

    this->loadAndRenderBmp(image, groundRect);

}
