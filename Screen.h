//
// Created by blackdartq on 5/11/16.
//

#ifndef ACTIONPACKEDADVENTUREGAME_SCREEN_H
#define ACTIONPACKEDADVENTUREGAME_SCREEN_H
#include "Tools.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Screen {

public:
    SDL_Window* window; // SDL value for the window
    SDL_Renderer* renderer; //SDL renderer



    Screen();   //uses createScreen, createRenderer

    void changeBackground(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void createScreen(); //creates screen with SDL_Window* window and controls the Width and height
    void createRenderer(); //creates a renderer
    void quitOnExitButtonPress();
    void quitSDL(); //Destroys everything


    ~Screen();

private:


};


#endif //ACTIONPACKEDADVENTUREGAME_SCREEN_H
