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

    int pace;

    //gives every entity a rectangle
    SDL_Rect entityRect;

    //used for attack rectangle of the entity
    SDL_Rect attackRect;

    //used for checking the direction of the entity
    bool facingRight;

    //used to check which direction the entity is attacking
    bool attackingRight;

    //prints to the console all the entitys info
    void entityInfo();

    void characterCreation();

    //getters

    string getName();

    int getAttack();

    int getDefence();

    int getHealth();

    int getMoney();

    bool checkIfAlive();
    void killEntity(SDL_Rect &rect);


    //setters
    void setName(string characterName);

    void setHealth(int h);

    void setAttack(int attackPower);

    void setDefence(int defencePower);

    void setMoney(int m);

    void setEntityPosition(int x, int y);


    //Used to get entitys x,y axis info
    int getEntityRectX(SDL_Rect &rect);

    int getEntityRectY(SDL_Rect &rect);

    int getEntityPosition(SDL_Rect rect);


    //used to move entity left, right, and jump
    void moveEntityLeft(const char *image, SDL_Rect &rect, bool &entityFacingRight, bool &entityShootingRight);

    void moveEntityRight(const char *image, SDL_Rect &rect, bool &entityFacingRight, bool &entityShootingRight);

    void moveEntityJump(const char *image, SDL_Rect &rect, bool &entityFacingRight, bool &entityShootingRight);

    //entity attacks
    void shadowBlast(const char *image, SDL_Rect &rect, bool &entityFacingRight, bool &entityShootingRight);

    //checks which way the entity is facing
    const char *checkIfCharacterIsFacingRight(bool facingRight, bool attackingRight);

    bool gotHit( SDL_Rect rect,  SDL_Rect rect2);

    void moveEntityWithScreneRight(SDL_Rect &rect);


private:
    // all values to the getters and setters
    string name;
    int money = 0;
    int health = 100;
    int attack = 10;
    int defence = 8;



};

class Character : public Entity {

public:
    //SDL_Rect characterRect;

    Character();

    SDL_Rect healthBar; //used for the health bar
    SDL_Rect manaBar;   //used for the mana bar

    const char *characterStandingRight = "Img/CharacterStandingRight.bmp";
    const char *characterStandingLeft = "Img/CharacterStandingLeft.bmp";


private:


};

class Spider : public Entity {


public:
    Spider();


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
