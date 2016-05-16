//
// Created by blackdartq on 5/13/16.
//

#include "Items.h"
using namespace std;

void Items::info() {
    cout << name << endl;
    cout << "Attack power: " << attack << endl;
    cout << "Defence power: " << defence << endl;
    cout << "money: " << money << endl;

} //prints to the console the health, attack, defence, money values.


// getters
string Items::getName() {

    return name;

} //shows characters name

int Items::getDefence() {
    return defence;
} //shows how much defence there is
int Items::getAttack() {
    return attack;
}  //shows the attack power

int Items::getMoney() {
    return money;
}   //shows how much money the character has

//setters
void Items::setName(string itemName) {

    name = itemName;

} //sets the characters name


void Items::setAttack(int attackPower) {

    attack = attackPower;
} //sets the characters attack Power

void Items::setDefence(int defencePower) {

    defence = defencePower;

} // sets the characters defence

void Items::setMoney(int m) {

    money = m;

}   //sets money valueFlamingIronSword::FlamingIronSword(string name, int attack, int defence, int money){




//constructors
WoodSword::WoodSword (string name, int attack, int defence, int money) {

    setName(name);
    setAttack(attack);
    setDefence(defence);
    setMoney(money);

}

FlamingIronSword::FlamingIronSword(string name, int attack, int defence, int money) {

    setName(name);
    setAttack(attack);
    setDefence(defence);
    setMoney(money);

}

IronSword::IronSword(string name, int attack, int defence, int money) {

    setName(name);
    setAttack(attack);
    setDefence(defence);
    setMoney(money);

}
