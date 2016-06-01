//
// Created by blackdartq on 5/10/16.
//

#include <SDL_thread.h>
#include <SDL_events.h>
#include "Entity.h"

//Entity class


//Entity creation dialog
void Entity::characterCreation() {
    Tools tools;
    string name;
    char c = 'n';

    while (c == 'n') {

        cout << "what is the name of your character?: ";
        while (tools.checkIfRunning()) {
            cin >> name;
            setName(name);
            cout << "your name is: " << getName() << endl;
            cout << " y/n: ";
            cin >> c;
            if (c == 'y') {
                break;

            } else {

                continue;
            }

        }
    }


}

//prints the entity info to the console the health, attack, defence, money values.
void Entity::entityInfo() {
    cout << name << endl;
    cout << "Health: " << health << endl;
    cout << "Attack power: " << attack << endl;
    cout << "Defence power: " << defence << endl;
    cout << "money: " << money << endl;

}


// getters

//Returns entitys name
string Entity::getName() {

    return name;

}

//Returns how much defence there is
int Entity::getDefence() {
    return defence;
}

//Returns the attack power
int Entity::getAttack() {
    return attack;
}

//Returns entity health
int Entity::getHealth() {


    return health;
}

//Returns how much money the entity has
int Entity::getMoney() {
    return money;
}

//Gets the X axis of the entity rectangle that gets passed in.
int Entity::getEntityRectX(SDL_Rect &rect) {

    return rect.x;
}

//Gets the Y axis of the entity rectangle that gets passed in.
int Entity::getEntityRectY(SDL_Rect &rect) {

    return rect.y;
}

//returns the X and Y axis of any rectangle passed in.
int Entity::getEntityPosition(SDL_Rect rect) {

    return rect.x, rect.y;


}


//setters

//sets the entity name
void Entity::setName(string characterName) {

    name = characterName;

}

//sets the entity attack Power
void Entity::setAttack(int attackPower) {

    attack = attackPower;
}

// sets the entity defence
void Entity::setDefence(int defencePower) {

    defence = defencePower;

}

//sets the health of the entity
void Entity::setHealth(int h) {

    health = h;

}

//sets money value
void Entity::setMoney(int m) {

    money = m;

}

//used to set the position of the entity class that uses it.
void Entity::setEntityPosition(int x, int y) {

    entityRect.x = x;
    entityRect.y = y;

}

//


//checks what value health is for the entity
bool Entity::checkIfAlive() {

    if (health > 0) {


        return true;

    } else {

        return false;
    }

}

//kills entity and puts their x,y axis to 1000
void Entity::killEntity(SDL_Rect &rect) {


    rect.x = 1000;
    rect.y = 900;
    rect.w = 0;
    rect.h = 0;


}



//these functions moves the entity and then renders to the screen
// checkIfCharacterIsFacingRight checks if charact is facing right and renders the image of the character facing different
//directions

void Entity::moveEntityLeft(const char *image, SDL_Rect &rect, bool &entityFacingRight, bool &entityShootingRight) {

    int runningSpeed = 2;

    for (int i = 0; i <= 10; i++) {
        entityFacingRight = false;
        entityShootingRight = false;
        rect.x = rect.x - runningSpeed;
        //loadAndRenderBmp(image, rect);
        //SDL_RenderPresent(renderer);


    }

}

void Entity::moveEntityRight(const char *image, SDL_Rect &rect, bool &entityFacingRight, bool &entityShootingRight) {

    int runningSpeed = 2;
    for (int i = 0; i <= 10; i++) {
        rect.x = rect.x + runningSpeed;
        entityFacingRight = true;
        entityShootingRight = false;
        //loadAndRenderBmp(image, rect);
        //SDL_RenderPresent(renderer);


    }

}

void Entity::moveEntityJump(const char *image, SDL_Rect &rect, bool &entityFacingRight, bool &entityShootingRight) {

    int jumpHeight = 10;
    int jumpWidth = 5;
    int jumpDelay = 20;
    if (entityFacingRight) {
        for (int i = 0; i <= jumpWidth; i++) {
            SDL_RenderClear(renderer);
            rect.y = rect.y - jumpHeight * i;
            moveEntityRight(image, rect, entityFacingRight, entityShootingRight);
            SDL_RenderPresent(renderer);
            SDL_Delay(jumpDelay);
        }

        for (int i = 0; i <= jumpWidth; i++) {
            rect.y = rect.y + jumpHeight * i;
            moveEntityRight(image, rect, entityFacingRight, entityShootingRight);
            loadAndRenderBmp(image, rect);
            SDL_RenderPresent(renderer);
            SDL_Delay(jumpDelay);
        }

    } else {
        for (int i = 0; i <= jumpWidth; i++) {
            rect.y = rect.y - jumpHeight * i;
            moveEntityLeft(image, rect, entityFacingRight, entityShootingRight);
            loadAndRenderBmp(image, rect);
            SDL_RenderPresent(renderer);

            SDL_Delay(jumpDelay);
        }

        for (int i = 0; i <= jumpWidth; i++) {
            rect.y = rect.y + jumpHeight * i;
            moveEntityLeft(image, rect, entityFacingRight, entityShootingRight);
            loadAndRenderBmp(image, rect);
            SDL_RenderPresent(renderer);
            SDL_Delay(jumpDelay);
        }

    }
}

const char *Entity::checkIfCharacterIsFacingRight(bool facingRight, bool attackingRight) {

    bool shooting = attackingRight;
    bool facing = facingRight;

    if (facing) {
        if (shooting) {

            return "Img/CharacterShootingRight.bmp";

        } else {

            return "Img/CharacterStandingRight.bmp";
        }

    } else if (!facing) {
        if (shooting) {

            return "Img/CharacterShootingLeft.bmp";

        } else {

            return "Img/CharacterStandingLeft.bmp";
        }

    }

}

bool Entity::gotHit(SDL_Rect rect, SDL_Rect rect2) {

    if (getEntityRectX(rect) >= getEntityRectX(rect2) && getEntityRectX(rect) <= getEntityRectX(rect2) + 100 &&
        getEntityRectY(rect2) < 900) {
        //cout << "Attack position is: " << "X:" << getEntityRectX(rect) << " Y: " << getEntityRectY(rect) << endl;
        //cout << "Entity position is: " << "X:" << getEntityRectX(rect2) << " Y: " << getEntityRectY(rect2) << endl;
        //cout << "hit" << endl;
        return true;

    } else {


        return false;
    }


}

void Entity::moveEntityWithScreneRight(SDL_Rect &rect){
    rect.x = rect.x + 10 ;


}


//

// attack makes the entity uses an attack and renders to the screen
void Entity::shadowBlast(const char *image, SDL_Rect &rect, bool &entityFacingRight, bool &entityShootingRight) {

    //cout << getEntityRectX(rect) << endl;
    //cout << getEntityRectY(rect) << endl;

    attackRect.x = rect.x + 100;
    attackRect.y = rect.y;
    attackRect.w = 0;
    attackRect.h = 100;

    if (entityFacingRight) {
        for (int i = 0; i < 15; i++) {
            attackingRight = true;
            loadAndRenderBmp(image, attackRect);
            attackRect.w = attackRect.w + 10;
            SDL_RenderPresent(renderer);
            SDL_Delay(20);

        }

        for (int i = 0; i < 15; i++) {
            loadAndRenderBmp(image, attackRect);
            attackRect.w = attackRect.w - 10;
            attackRect.x = attackRect.x + 10;
            SDL_RenderPresent(renderer);
            SDL_Delay(20);

        }
    } else {
        attackingRight = false;
        attackRect.x = rect.x - 1;
        for (int i = 0; i < 15; i++) {
            loadAndRenderBmp(image, attackRect);
            attackRect.w = attackRect.w + 10;
            attackRect.x = attackRect.x - 10;
            SDL_RenderPresent(renderer);
            SDL_Delay(20);
        }

        for (int i = 0; i < 15; i++) {
            loadAndRenderBmp(image, attackRect);
            attackRect.w = attackRect.w - 10;


            SDL_RenderPresent(renderer);
            SDL_Delay(20);


        }

    }

    attackRect.x = 0;
    attackRect.y = 0;
    attackRect.w = 0;
    attackRect.h = 0;


}

//End Entity class


//-----------------------------------------------------------------------------------------------


//Character class

Character::Character() {

    setName("Bro");
    setHealth(300);
    setAttack(25);
    setDefence(5);
    setMoney(10);

    facingRight = true;
    attackingRight = false;
    entityRect.h = 100;
    entityRect.w = 100;

    healthBar.x = 5;
    healthBar.y = 10;
    healthBar.w = 300;
    healthBar.h = 25;

    manaBar.x = 5;
    manaBar.y = 40;
    manaBar.w = 300;
    manaBar.h = 25;


}

//End of Character class

//-----------------------------------------------------------------------------------------------

//Spider class
Spider::Spider() {

    setName("spider");
    setHealth(100);
    setAttack(10);
    setDefence(5);
    setMoney(10);
    pace = 0;
    facingRight = true;

    entityRect.x = 0;
    entityRect.y = 0;
    entityRect.h = 100;
    entityRect.w = 100;


}


//End of Spider class

//-----------------------------------------------------------------------------------------------

//Vampire class
Vampire::Vampire(string name, int health, int attack, int defence, int money) {

    setName(name);
    setHealth(health);
    setAttack(attack);
    setDefence(defence);
    setMoney(money);

    entityRect.x = 0;
    entityRect.y = 0;
    entityRect.h = 100;
    entityRect.w = 100;

}


//end of Vampire class

//-----------------------------------------------------------------------------------------------


//Troll class
Troll::Troll(string name, int health, int attack, int defence, int money) {

    setName(name);
    setHealth(health);
    setAttack(attack);
    setDefence(defence);
    setMoney(money);

    entityRect.x = 0;
    entityRect.y = 0;
    entityRect.h = 100;
    entityRect.w = 100;
}


//end of Troll class

//-----------------------------------------------------------------------------------------------


//Skeleton class
Skeleton::Skeleton(string name, int health, int attack, int defence, int money) {

    setName(name);
    setHealth(health);
    setAttack(attack);
    setDefence(defence);
    setMoney(money);

    entityRect.x = 0;
    entityRect.y = 0;
    entityRect.h = 100;
    entityRect.w = 100;
}


//end of Skeleton class

//-----------------------------------------------------------------------------------------------


//Dragon class
Dragon::Dragon(string name, int health, int attack, int defence, int money) {

    setName(name);
    setHealth(health);
    setAttack(attack);
    setDefence(defence);
    setMoney(money);

    entityRect.x = 0;
    entityRect.y = 0;
    entityRect.h = 100;
    entityRect.w = 100;
}


//end of Dragon class


//-----------------------------------------------------------------------------------------------


