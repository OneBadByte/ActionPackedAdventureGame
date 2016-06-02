//
// Created by blackdartq on 5/11/16.
//

#include <SDL2/SDL.h>
#include "Screen.h"

using namespace std;


//gives the X,Y,H,W to the ground rectangle
Screen::Screen() {


}

//Creates the ground and background rectangles
void Screen::createRectangles() {

    groundRect.x = 0;
    groundRect.y = 900;
    groundRect.w = SCREENWIDTH;
    groundRect.h = 100;


    backgroundRect.x = 0;
    backgroundRect.y = 0;
    backgroundRect.w = 5000;
    backgroundRect.h = SCREENHEIGHT;


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

}

//Destroys renderer, window, and then quits SDL and the main loop
void Screen::quitSDL() {

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

//changes retangle color
void Screen::changeRectangleColor(SDL_Rect rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderFillRect(renderer, &rect);
    //SDL_RenderPresent(renderer);

}

void Screen::loadHealthAndManaBar(SDL_Rect healthRect, SDL_Rect manaRect, int health, int mana){

    healthRect.w = health;
    manaRect.w = mana;
    changeRectangleColor(healthRect, 233, 22, 22, 1);
    changeRectangleColor(manaRect, 0, 62, 250, 1);

}


// changes the background using an image.
void Screen::changeBackground(const char *imagePath) {

    SDL_Texture *texture1 = NULL;
    surface = SDL_LoadBMP(imagePath);
    texture1 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture1, NULL, &backgroundRect);
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


//


//changes the bmp image of the ground
void Screen::changeGroundWithBmp(const char *image) {


    //this->loadAndRenderBmp(image, groundRect);
    SDL_Texture *texture1 = NULL;
    surface = SDL_LoadBMP(image);
    texture1 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture1, NULL, &groundRect);
    SDL_DestroyTexture(texture1);


}


//Moves the ground when the character gets to a certain point on the screen
void Screen::moveGroundLeft() {

}

void Screen::moveGroundRight() {
    groundRect.x = groundRect.x + 10;
}

void Screen::moveGround(SDL_Rect rect) {

    if (rect.x >= 600) {
        moveGroundLeft();

    } else if (rect.x == 0 && groundRect.x >= 0) {


    } else if (rect.x == 0) {
        moveGroundRight();

    }


}


//Move screen functions
void Screen::moveScreenLeft() {
    backgroundRect.x = backgroundRect.x - 10;
}

void Screen::moveScreenRight() {
    backgroundRect.x = backgroundRect.x + 10;
}

void Screen::moveScreen(SDL_Rect rect) {

    if (rect.x >= 600) {
        moveScreenLeft();

    } else if (rect.x == 0 && backgroundRect.x >= 0) {


    } else if (rect.x == 0) {
        moveScreenRight();

    }


}


void Screen::moveSceneLeft(){


    groundRect.x = groundRect.x - 10;
    backgroundRect.x = backgroundRect.x - 10;
}

void Screen::moveSceneRight(){


    groundRect.x = groundRect.x + 10;
    backgroundRect.x = backgroundRect.x + 10;

}



void Screen::moveScene(SDL_Rect rect) {

    if (rect.x >= 600) {
        moveSceneLeft();


    } else if (rect.x == 0 && backgroundRect.x >= 0 && groundRect.x >= 0) {


    } else if (rect.x == 0) {
        moveSceneRight();

    }


}



Screen::~Screen() {

}



