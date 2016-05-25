//
// Created by blackdartq on 5/11/16.
//

#include <SDL2/SDL.h>
#include "Screen.h"

using namespace std;


//gives the X,Y,H,W to the ground rectangle
Screen::Screen() {




}

void Screen::createRectangles(){

    groundRect.x = 0;
    groundRect.y = 900;
    groundRect.w = 1000;
    groundRect.h = 100;

    groundShownRect.x = 0;
    groundShownRect.y = 0;
    groundShownRect.w = SCREENWIDTH;
    groundShownRect.h = 100;

    backgroundRect.x = 10;
    backgroundRect.y = 0;
    backgroundRect.w = 1000;
    backgroundRect.h = 5000;

    backgroundShownRect.x = 0;
    backgroundShownRect.y = 0;
    backgroundShownRect.w = 1200;
    backgroundShownRect.h = SCREENHEIGHT;


}

// Opens window to 1200px width, 1000px height called window
void Screen::createScreen() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {

        cout << "SDL init failed" << endl;

    }
    cout << "SDL succeeded" << endl;

    window = SDL_CreateWindow("Adventure",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              SCREENWIDTH,
                              SCREENHEIGHT,
                              SDL_WINDOW_RESIZABLE);


}

//creates the renderer
void Screen::createRenderer() {

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

}  //Creates a renderer using the window

//Destroys renderer, window, and then quits SDL and the main loop
void Screen::quitSDL() {

    Tools tools;
    tools.quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();



}

//changes the background color using rgba,clears, and renders it.
void Screen::changeBackground(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

}

void Screen::changeBackground(const char *imagePath) {

    SDL_Texture *texture1 = NULL;
    surface = SDL_LoadBMP(imagePath);
    texture1 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture1, NULL, &backgroundShownRect);
    SDL_DestroyTexture(texture1);


}

//loadAndRenderBmp loads a bmp to the main background or to a rectangle
void Screen::loadAndRenderBmp(const char *imagePath) {

    SDL_Texture *texture1 = NULL;
    surface = SDL_LoadBMP(imagePath);
    texture1 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture1, NULL, NULL);
    SDL_DestroyTexture(texture1);

}

void Screen::loadAndRenderBmp(const char *imagePath, SDL_Rect rect) {

    SDL_Texture *texture1 = NULL;
    surface = SDL_LoadBMP(imagePath);
    texture1 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture1, NULL, &rect);
    SDL_DestroyTexture(texture1);


}

void Screen::loadAndRenderBmp(const char *imagePath, SDL_Rect textureRect, SDL_Rect rect) {

    SDL_Texture *texture1 = NULL;
    surface = SDL_LoadBMP(imagePath);
    texture1 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture1, &textureRect, &rect);
    SDL_DestroyTexture(texture1);


}
//


//changes the bmp image of the ground
void Screen::changeGroundWithBmp(const char *image) {


    //this->loadAndRenderBmp(image, groundRect);
    SDL_Texture *texture1 = NULL;
    surface = SDL_LoadBMP(image);
    texture1 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture1, &groundShownRect, &groundRect);
    SDL_DestroyTexture(texture1);


}

void Screen::moveScreenLeft() {
    backgroundShownRect.x = backgroundShownRect.x - 20;
}

void Screen::moveScreenRight() {
    backgroundShownRect.x = backgroundShownRect.x + 20;
}

void Screen::moveScreen(SDL_Rect rect){

    if(rect.x >= 600 ){
        moveScreenLeft();

    }else if(rect.x == 0 && backgroundShownRect.x >= 0){


    }else if(rect.x == 0){
        moveScreenRight();

    }



}

Screen::~Screen() {

}



