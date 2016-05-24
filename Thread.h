//
// Created by blackdartq on 5/24/16.
//

#ifndef ACTIONPACKEDADVENTUREGAME_THREAD_H
#define ACTIONPACKEDADVENTUREGAME_THREAD_H
#include <iostream>
#include <SDL2/SDL_image.h>
#include "Tools.h"
#include "Entity.h"
#include "Screen.h"
#include "Items.h"

class Thread : public Character {


public:
    void moveScreen();
    void moveCharacter();
    int characterThread(void *ptr);
};


#endif //ACTIONPACKEDADVENTUREGAME_THREAD_H
