//
// Created by blackdartq on 5/12/16.
//

#ifndef ACTIONPACKEDADVENTUREGAME_ENEMY_H
#define ACTIONPACKEDADVENTUREGAME_ENEMY_H

#include "Tools.h"

using namespace std;

class Enemy {


public:

    void info(); //prints info about the enemy

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


private:

    int health;
    string name;
    int attack;
    int defence;
    int money;

protected:


};

class Spider : public Enemy {


public:
    Spider(string name, int health, int attack, int defence, int money);

    ~Spider();

private:


protected:


};

class Vampire : public Enemy {


public:
    Vampire(string name, int health, int attack, int defence, int money);

private:

protected:

};

class Troll : public Enemy {

public:
    Troll(string name, int health, int attack, int defence, int money);

private:

protected:

};

class Skeleton : public Enemy {

public:
    Skeleton(string name, int health, int attack, int defence, int money);

private:

protected:

};

class Dragon : public Enemy {

public:
    Dragon(string name, int health, int attack, int defence, int money);

private:

protected:

};


#endif //ACTIONPACKEDADVENTUREGAME_ENEMY_H
