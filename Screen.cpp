//
// Created by blackdartq on 5/11/16.
//

#include <SDL2/SDL.h>
#include "Screen.h"

using namespace std;

 Screen::Screen() {




    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){

        cout << "SDL init failed" << endl;

    }
     cout << "SDL succeeded" << endl;
     createScreen();
     createRenderer();








 } //initializes SDL_Init and then creates a screen and renderer


void Screen::createScreen() {

    window = SDL_CreateWindow("Adventure", SDL_WINDOWPOS_UNDEFINED , SDL_WINDOWPOS_UNDEFINED, 1000, 1000, SDL_WINDOW_RESIZABLE);





} // Opens window to 1000px width, 1000px height called window

void Screen::createRenderer(){

    renderer = SDL_CreateRenderer(window,-1,0);

}  //Creates a renderer using the window


void Screen::quitSDL() {


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



