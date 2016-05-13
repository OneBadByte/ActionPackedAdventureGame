//
// Created by blackdartq on 5/12/16.
//

#include "Enemy.h"

void Enemy::info() {
    cout << name << endl;
    cout << "Health: " << health << endl;
    cout << "Attack power: " << attack << endl;
    cout << "Defence power: " << defence << endl;
    cout << "money: " << money << endl;

} //prints to the console the health, attack, defence, money values.

//getters
string Enemy::getName() {

    return name;

} //shows characters name

int Enemy::getDefence() {
    return defence;
} //shows how much defence there is
int Enemy::getAttack() {
    return attack;
}  //shows the attack power

int Enemy::getHealth() {


    return health;
} //shows characters health

int Enemy::getMoney() {
    return money;
}   //shows how much money the character has



//setters
void Enemy::setAttack(int attackPower) {

    attack = attackPower;
} //sets the characters attack Power

void Enemy::setDefence(int defencePower) {

    defence = defencePower;

} // sets the characters defence

void Enemy::setHealth(int h) {

    health = h;

}   //sets the health of the character

void Enemy::setMoney(int m) {

    money = m;

}   //sets money value

void Enemy::setName(string enemyName) {
    name = enemyName;
}

bool Enemy::checkIfAlive() {

    if (health > 0) {

        return true;

    } else {

        return false;
    }

} //checks if health is > 0Spider::Spider(){



Spider::Spider(string name, int health, int attack, int defence, int money) {

    setName(name);
    setHealth(health);
    setAttack(attack);
    setDefence(defence);
    setMoney(money);

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
