//
// Created by blackdartq on 5/24/16.
//

#ifndef ACTIONPACKEDADVENTUREGAME_LEVEL_H
#define ACTIONPACKEDADVENTUREGAME_LEVEL_H

#include <iostream>
#include <SDL2/SDL_image.h>
#include "Tools.h"
#include "Entity.h"
#include "Screen.h"
#include "Items.h"
#include "Audio.h"




class Level {

public:

    Level();

    void createScreen();

    void startMenu();

    void level1();

    void moveCharacter();
};


#endif //ACTIONPACKEDADVENTUREGAME_LEVEL_H
