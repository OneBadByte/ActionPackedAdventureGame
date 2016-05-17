//
// Created by blackdartq on 5/10/16.
//

#ifndef ACTIONPACKEDADVENTUREGAME_CHARACTER_H
#define ACTIONPACKEDADVENTUREGAME_CHARACTER_H

#include <SDL_rect.h>
#include "Tools.h"
#include "Screen.h"
using namespace std;

class Entity : Screen {

public:
    Entity(); //Sets character rectangleconst char* image,
    SDL_Rect entityRect;
    SDL_Rect attackRect;
    bool jumpRight = true;
    void info();

    //getters

    int getAttack();

    int getDefence();

    int getHealth();

    int getMoney();

    bool checkIfAlive();

    string getName();
    int getEntityRectX(SDL_Rect rect);
    int getEntityRectY(SDL_Rect rect);


    //setters
    void setName(string characterName);

    void setHealth(int h);

    void setAttack(int attackPower);

    void setDefence(int defencePower);

    void setMoney(int m);

    void characterCreation();

    ~Entity();

    void moveEntityLeft(const char* image, SDL_Rect &rect);
    void moveEntityRight(const char* image, SDL_Rect &rect);
    void moveEntityJump(const char* image, SDL_Rect &rect);
    void Attack(const char* image, SDL_Rect &rect);




private:
    // all values to the getters and setters
    string name;
    int money = 0;
    int health = 100;
    int attack = 10;
    int defence = 8;


};

class Character : public Entity{

public:
    //SDL_Rect characterRect;
    Character();
    const char * image = "Character.bmp";



private:


};


class Spider : public Entity {


public:
    Spider(string name, int health, int attack, int defence, int money);

    ~Spider();

private:


protected:


};

class Vampire : public Entity {


public:
    Vampire(string name, int health, int attack, int defence, int money);

private:

protected:

};

class Troll : public Entity {

public:
    Troll(string name, int health, int attack, int defence, int money);

private:

protected:

};

class Skeleton : public Entity {

public:
    Skeleton(string name, int health, int attack, int defence, int money);

private:

protected:

};

class Dragon : public Entity {

public:
    Dragon(string name, int health, int attack, int defence, int money);

private:

protected:

};




#endif //ACTIONPACKEDADVENTUREGAME_CHARACTER_H
