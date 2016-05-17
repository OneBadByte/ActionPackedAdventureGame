//
// Created by blackdartq on 5/10/16.
//

#include <SDL_thread.h>
#include <SDL_events.h>
#include "Entity.h"


Entity::Entity() {


}

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


void Entity::info() {
    cout << name << endl;
    cout << "Health: " << health << endl;
    cout << "Attack power: " << attack << endl;
    cout << "Defence power: " << defence << endl;
    cout << "money: " << money << endl;

} //prints to the console the health, attack, defence, money values.


// getters
string Entity::getName() {

    return name;

} //shows characters name

int Entity::getDefence() {
    return defence;
} //shows how much defence there is
int Entity::getAttack() {
    return attack;
}  //shows the attack power

int Entity::getHealth() {


    return health;
} //shows characters health

int Entity::getMoney() {
    return money;
}   //shows how much money the character has

int Entity::getEntityRectX(SDL_Rect rect) {


    return rect.x;
}

int Entity::getEntityRectY(SDL_Rect rect) {

    return rect.x;
}


//setters
void Entity::setName(string characterName) {

    name = characterName;

} //sets the characters name


void Entity::setAttack(int attackPower) {

    attack = attackPower;
} //sets the characters attack Power

void Entity::setDefence(int defencePower) {

    defence = defencePower;

} // sets the characters defence

void Entity::setHealth(int h) {

    health = h;

}   //sets the health of the character

void Entity::setMoney(int m) {

    money = m;

}   //sets money value




bool Entity::checkIfAlive() {

    if (health > 0) {

        return true;

    } else {

        return false;
    }

} //checks if health is > 0













Entity::~Entity() {


}


void Entity::moveEntityLeft(const char *image, SDL_Rect &rect) {

    for (int i = 0; i <= 10; i++) {
        jumpRight = false;
        rect.x = rect.x - 2;
        loadAndRenderBmp(image, rect);
        SDL_RenderPresent(renderer);


    }

}

void Entity::moveEntityRight(const char *image, SDL_Rect &rect) {

    for (int i = 0; i <= 10; i++) {
        rect.x = rect.x + 2;
        jumpRight = true;
        loadAndRenderBmp(image, rect);
        SDL_RenderPresent(renderer);

    }

}

void Entity::moveEntityJump(const char *image, SDL_Rect &rect) {

    if (jumpRight) {
        for (int i = 0; i <= 4; i++) {
            SDL_RenderClear(renderer);
            rect.y = rect.y - 10 * i;
            moveEntityRight(image, rect);
            SDL_RenderPresent(renderer);
            SDL_Delay(20);
        }

        for (int i = 0; i <= 4; i++) {
            rect.y = rect.y + 10 * i;
            moveEntityRight(image, rect);
            loadAndRenderBmp(image, rect);
            SDL_RenderPresent(renderer);
            SDL_Delay(20);
        }

    } else {
        for (int i = 0; i <= 4; i++) {
            rect.y = rect.y - 10 * i;
            moveEntityLeft(image, rect);
            loadAndRenderBmp(image, rect);
            SDL_RenderPresent(renderer);

            SDL_Delay(20);
        }

        for (int i = 0; i <= 4; i++) {
            rect.y = rect.y + 10 * i;
            moveEntityLeft(image, rect);
            loadAndRenderBmp(image, rect);
            SDL_RenderPresent(renderer);
            SDL_Delay(20);
        }

    }
}

void Entity::Attack(const char *image, SDL_Rect &rect) {

    cout << getEntityRectX(rect) << endl;
    cout << getEntityRectY(rect) << endl;
    attackRect.x = rect.x + 100;
    attackRect.y = rect.y;
    attackRect.w = 150;
    attackRect.h = 100;
    loadAndRenderBmp(image, attackRect);
    SDL_RenderPresent(renderer);
    SDL_Delay(500);
    SDL_RenderPresent(renderer);

}


Character::Character() {


    entityRect.x = 0;
    entityRect.y = 800;
    entityRect.h = 100;
    entityRect.w = 100;



    //renderEntity(image, characterRect);




}

Spider::Spider(string name, int health, int attack, int defence, int money) {

    setName(name);
    setHealth(health);
    setAttack(attack);
    setDefence(defence);
    setMoney(money);

    entityRect.x = 800;
    entityRect.y = 800;
    entityRect.h = 100;
    entityRect.w = 100;



}


Spider::~Spider() {

}

Vampire::Vampire(string name, int health, int attack, int defence, int money) {

    setName(name);
    setHealth(health);
    setAttack(attack);
    setDefence(defence);
    setMoney(money);


}

Troll::Troll(string name, int health, int attack, int defence, int money) {

    setName(name);
    setHealth(health);
    setAttack(attack);
    setDefence(defence);
    setMoney(money);

}

Skeleton::Skeleton(string name, int health, int attack, int defence, int money) {

    setName(name);
    setHealth(health);
    setAttack(attack);
    setDefence(defence);
    setMoney(money);

}

Dragon::Dragon(string name, int health, int attack, int defence, int money) {

    setName(name);
    setHealth(health);
    setAttack(attack);
    setDefence(defence);
    setMoney(money);

}


