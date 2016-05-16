//
// Created by blackdartq on 5/15/16.
//

#ifndef ACTIONPACKEDADVENTUREGAME_CONTROL_H
#define ACTIONPACKEDADVENTUREGAME_CONTROL_H

#include "Tools.h"
#include "Screen.h"
#include <SDL_rect.h>
#include <SDL2/SDL.h>

using namespace std;

class Control {

public:
    Control();

    SDL_Rect character;
    SDL_Rect ground;

    ~Control();
private:




};


#endif //ACTIONPACKEDADVENTUREGAME_CONTROL_H
