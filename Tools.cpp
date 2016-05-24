//
// Created by blackdartq on 5/10/16.
//

#include "Tools.h"
#include "Screen.h"

//quits the game
void Tools::quit() {
    isRunning = false;


}

// checks if the game is still running.
bool Tools::checkIfRunning() {

    if (isRunning == true) {

        return true;

    } else {
        return false;

    }

}

//Drops 30 lines
void Tools::clearConsole() {

    cout << string(30, '\n');

}
