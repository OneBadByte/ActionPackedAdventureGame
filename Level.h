//
// Created by blackdartq on 5/24/16.
//

#ifndef ACTIONPACKEDADVENTUREGAME_LEVEL_H
#define ACTIONPACKEDADVENTUREGAME_LEVEL_H

#include <iostream>
#include <vector>
#include <SDL2/SDL_image.h>
#include "Tools.h"
#include "Entity.h"
#include "Screen.h"
#include "Items.h"
#include "Audio.h"


class Level {

public:


    vector<Spider> spiderVector;


    Level();

    void createScreen();

    void startMenu();

    void level1();

    void level2();

    void level3();

    void level4();

    void level5();


    void moveCharacter();

    void moveEnemies();

    void enemyAttackThread();

    void startScreen();

    void moveEnemies(SDL_Rect &rect, bool &moveRight, int &pace);

    void moveEnemiesWithScrene(SDL_Rect &rect, bool &facingRight);

    void moveEnemysRight(SDL_Rect &rect, bool &facingRight);

    void moveEnemysLeft(SDL_Rect &rect, bool &facingRight);

    void getEnemies();

    void testLevel();
};


#endif //ACTIONPACKEDADVENTUREGAME_LEVEL_H
