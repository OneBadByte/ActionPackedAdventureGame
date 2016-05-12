//
// Created by blackdartq on 5/10/16.
//

#ifndef ACTIONPACKEDADVENTUREGAME_CHARACTER_H
#define ACTIONPACKEDADVENTUREGAME_CHARACTER_H

#include "Tools.h"

using namespace std;

class Character {

public:
    Character(); //runs code for the character creation


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


    ~Character();


private:
    // all values to the getters and setters
    string name;
    int money = 0;
    int health = 100;
    int attack = 10;
    int defence = 8;


};


#endif //ACTIONPACKEDADVENTUREGAME_CHARACTER_H
