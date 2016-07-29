//
// Created by blackdartq on 5/10/16.
//

#include <SDL_thread.h>
#include <SDL_events.h>
#include "Entity.h"

//Entity class


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
int Entity::getEntityPosition(SDL_Rect &rect) {

    return rect.x, rect.y;


}


//setters

void Entity::setName(string characterName) {

    name = characterName;

}

void Entity::setAttack(int attackPower) {

    attack = attackPower;
}

void Entity::setDefence(int defencePower) {

    defence = defencePower;

}

void Entity::setHealth(int h) {

    health = h;

}

void Entity::setMoney(int m) {

    money = m;

}

void Entity::setEntityPosition(int x, int y) {

    entityRect.x = x;
    entityRect.y = y;

}

//

//checks what value health is for the entity
void Entity::checkIfAlive() {

    if (this->health > 0) {


    } else {

        this->killEntity();
        this->killEntity();
    }

}

//kills entity and puts their x,y axis to 1000
void Entity::killEntity() {

    this->entityRect.x = 1000;
    this->entityRect.y = 900;
    this->entityRect.w = 0;
    this->entityRect.h = 0;

    this->attackRect.x = 1000;
    this->attackRect.y = 900;
    this->attackRect.w = 0;
    this->attackRect.h = 0;


}


void Entity::moveEntityLeft(int speed) {

    this->facingRight = false;
    this->entityRect.x = this->entityRect.x - speed;


}

void Entity::moveEntityRight(int speed) {

    this->entityRect.x = this->entityRect.x + speed;
    this->facingRight = true;
    //loadAndRenderBmp(image, rect);
    //SDL_RenderPresent(renderer);

}

void Entity::moveEntityJump(int speed) {


    int jumpHeight = 10;
    int jumpWidth = 5;
    Uint32 jumpDelay = 20;
    if (this->facingRight) {
        for (int i = 0; i <= jumpWidth; i++) {
            SDL_RenderClear(renderer);
            this->entityRect.y = this->entityRect.y - jumpHeight * i;
            moveEntityRight(speed);
            SDL_RenderPresent(renderer);
            SDL_Delay(jumpDelay);
        }

        for (int i = 0; i <= jumpWidth; i++) {
            this->entityRect.y = this->entityRect.y + jumpHeight * i;
            moveEntityRight(speed);
            //loadAndRenderBmp(image, this->entityRect);
            SDL_RenderPresent(renderer);
            SDL_Delay(jumpDelay);
        }

    } else {
        for (int i = 0; i <= jumpWidth; i++) {
            this->entityRect.y = this->entityRect.y - jumpHeight * i;
            moveEntityLeft(speed);
            //loadAndRenderBmp(image, this->entityRect);
            SDL_RenderPresent(renderer);

            SDL_Delay(jumpDelay);
        }

        for (int i = 0; i <= jumpWidth; i++) {
            this->entityRect.y = this->entityRect.y + jumpHeight * i;
            moveEntityLeft(speed);
            //loadAndRenderBmp(image, this->entityRect);
            SDL_RenderPresent(renderer);
            SDL_Delay(jumpDelay);
        }

    }
}

void Entity::moveEnemyTowardsCharacter(SDL_Rect &characterRect) {

    for (int i = 0; i < 5; i++){
        if (this->entityRect.x >= characterRect.x) {
            this->moveEntityLeft(2);


        } else if (this->entityRect.x <= characterRect.x) {
            this->moveEntityRight(2);

        }
}

}


const char *Entity::checkIfCharacterIsFacingRight(bool facingRight) {

    if (facingRight) {

        return "Img/CharacterShootingRight.bmp";

    } else {

        return "Img/CharacterShootingLeft.bmp";
    }

}


void Entity::gotHit(SDL_Rect &rect2) {

    if (getEntityRectX(this->entityRect) >= getEntityRectX(rect2) &&
        getEntityRectX(this->entityRect) <= getEntityRectX(rect2) + 100 &&
        getEntityRectY(rect2) < 900) {

        this->health = this->health - 10;

    } else {


    }


}

void Entity::gotHit(SDL_Rect &rect2, int attackPower) {

    if (getEntityRectX(this->entityRect) >= getEntityRectX(rect2) &&
        getEntityRectX(this->entityRect) <= getEntityRectX(rect2) + 100 &&
        getEntityRectY(rect2) < 900) {

        this->health = this->health - attackPower;
        SDL_Delay(20);

    } else {


    }


}

void Entity::gotHit(SDL_Rect &entityRect1, SDL_Rect &attackRect2, int attackPower) {

    if (getEntityRectX(this->entityRect) >= getEntityRectX(entityRect1) &&
        getEntityRectX(this->entityRect) <= getEntityRectX(entityRect1) + 100 &&
        getEntityRectY(entityRect1) < 900) {

        this->health = this->health - attackPower;
        SDL_Delay(20);

    } else {


    }

    if (getEntityRectX(this->entityRect) >= getEntityRectX(attackRect2) &&
        getEntityRectX(this->entityRect) <= getEntityRectX(attackRect2) + 100 &&
        getEntityRectY(attackRect2) < 900) {

        this->health = this->health - attackPower;
        SDL_Delay(20);

    } else {


    }


}




void Entity::moveEnemiesWithScreen(SDL_Rect &characterRect,SDL_Rect &screenRect) {

    if (characterRect.x > 500 && screenRect.x != 5000) {
        //moveEnemysLeft(enemyRect, facingRight);
        this->moveEntityLeft(15);


    } else if (characterRect.x < 10 && screenRect.x != 0 ) {

        moveEntityRight(11);

    }

}


//

void Entity::attackIfCharacterNear(SDL_Rect &characterRect) {

    if(this->health > 0) {
        if (characterRect.x > this->entityRect.x - 150 && characterRect.x < this->entityRect.x ||
            characterRect.x < this->entityRect.x + 150 && characterRect.x > this->entityRect.x ) {

            //this->shadowBlast("Img/Shadow.bmp", this->attackRect, this->facingRight);
            this->shadowBlast();
        }
    }


}


// attack makes the entity uses an attack and renders to the screen

void Entity::shadowBlast() {


    this->attackRect.x = this->entityRect.x + 100;
    this->attackRect.y = this->entityRect.y;
    this->attackRect.w = 0;
    this->attackRect.h = 100;

    if (this->facingRight) {
        for (int i = 0; i < 15; i++) {
            this->attackingRight = true;
            loadAndRenderBmp("Img/Shadow.bmp", this->attackRect);
            this->attackRect.w = this->attackRect.w + 10;

            SDL_Delay(20);

        }

        for (int i = 0; i < 15; i++) {
            loadAndRenderBmp("Img/Shadow.bmp", this->attackRect);
            this->attackRect.w = this->attackRect.w - 10;
            this->attackRect.x = this->attackRect.x + 10;

            SDL_Delay(20);

        }
    } else {
        this->attackingRight = false;
        this->attackRect.x = entityRect.x - 1;
        for (int i = 0; i < 15; i++) {
            loadAndRenderBmp("Img/Shadow.bmp", attackRect);
            this->attackRect.w = this->attackRect.w + 10;
            this->attackRect.x = this->attackRect.x - 10;

            SDL_Delay(20);
        }

        for (int i = 0; i < 15; i++) {
            loadAndRenderBmp("Img/Shadow.bmp", this->attackRect);
            this->attackRect.w = this->attackRect.w - 10;

            SDL_Delay(20);


        }

    }

    this->attackRect.x = 1000;
    this->attackRect.y = 0;
    this->attackRect.w = 0;
    this->attackRect.h = 0;


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

    mana = 300;

    facingRight = true;
    attackingRight = true;
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

    facingRight = false;
    attackingRight = false;

    attackRect.x = 1000;
    attackRect.y = 0;

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



