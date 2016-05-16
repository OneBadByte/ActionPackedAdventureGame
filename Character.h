//
// Created by blackdartq on 5/10/16.
//

#ifndef ACTIONPACKEDADVENTUREGAME_CHARACTER_H
#define ACTIONPACKEDADVENTUREGAME_CHARACTER_H

#include <SDL_rect.h>
#include "Tools.h"
#include "Screen.h"
using namespace std;

class Character : Screen {

public:
    Character(); //Sets character rectangle
    SDL_Rect characterRect;
    bool jumpRight = true;
    void info();

    //getters

    int getAttack();

    int getDefence();

    int getHealth();

    int getMoney();

    bool checkIfAlive();

    string getName();


    //setters
    void setName(string characterName);

    void setHealth(int h);

    void setAttack(int attackPower);

    void setDefence(int defencePower);

    void setMoney(int m);

    void characterCreation();

    ~Character();

    void moveCharacterLeft();
    void moveCharacterRight();
    void moveCharacterJump();



private:
    // all values to the getters and setters
    string name;
    int money = 0;
    int health = 100;
    int attack = 10;
    int defence = 8;


};


#endif //ACTIONPACKEDADVENTUREGAME_CHARACTER_H
