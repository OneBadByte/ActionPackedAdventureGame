//
// Created by blackdartq on 5/10/16.
//

#include "Tools.h"
#include "Screen.h"

//quits the game
void Tools::quit() {
    cout << "stopping game" << endl;
    isRunning = false;



}

// checks if the game is still running.
bool Tools::checkIfRunning() {

    if (isRunning) {

        return true;

    } else {
        return false;

    }

}

//Drops 30 lines
void Tools::clearConsole() {

    cout << string(30, '\n');

}
