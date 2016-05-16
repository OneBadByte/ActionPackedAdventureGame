//
// Created by blackdartq on 5/13/16.
//

#ifndef ACTIONPACKEDADVENTUREGAME_ITEMS_H
#define ACTIONPACKEDADVENTUREGAME_ITEMS_H


#include "Tools.h"

using namespace std;

class Items {


public:
    void info();

    //getters
    int getAttack();

    int getDefence();

    int getMoney();

    string getName();

    //setters
    void setName(string itemName);


    void setAttack(int attackPower);

    void setDefence(int defencePower);

    void setMoney(int m);

private:

    string name;
    int attack;
    int defence;
    int money;

protected:


};


class WoodSword : public Items {


public:
    WoodSword(string name, int attack, int defence, int money);


private:


};

class IronSword : public Items {


public:
    IronSword(string name, int attack, int defence, int money);


private:


};

class FlamingIronSword : public Items {


public:
    FlamingIronSword(string name, int attack, int defence, int money);


private:


};


#endif //ACTIONPACKEDADVENTUREGAME_ITEMS_H
