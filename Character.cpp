//
// Created by blackdartq on 5/10/16.
//

#include "Character.h"

Character::Character() {


}

//Character creation dialog
void Character::characterCreation() {
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


void Character::info() {
    cout << name << endl;
    cout << "Health: " << health << endl;
    cout << "Attack power: " << attack << endl;
    cout << "Defence power: " << defence << endl;
    cout << "money: " << money << endl;

} //prints to the console the health, attack, defence, money values.


// getters
string Character::getName() {

    return name;

} //shows characters name

int Character::getDefence() {
    return defence;
} //shows how much defence there is
int Character::getAttack() {
    return attack;
}  //shows the attack power

int Character::getHealth() {


    return health;
} //shows characters health

int Character::getMoney() {
    return money;
}   //shows how much money the character has



//setters
void Character::setName(string characterName) {

    name = characterName;

} //sets the characters name


void Character::setAttack(int attackPower) {

    attack = attackPower;
} //sets the characters attack Power

void Character::setDefence(int defencePower) {

    defence = defencePower;

} // sets the characters defence

void Character::setHealth(int h) {

    health = h;

}   //sets the health of the character

void Character::setMoney(int m) {

    money = m;

}   //sets money value


bool Character::checkIfAlive() {

    if (health > 0) {

        return true;

    } else {

        return false;
    }

} //checks if health is > 0


Character::~Character() {

}




