//
// Created by blackdartq on 5/10/16.
//

#include "Tools.h"

void Tools::quit() { //quits the game

    isRunning = false;


}

bool Tools::checkIfRunning() { // checks if the game is still running.

    if (isRunning == true) {

        return true;

    } else {
        return false;

    }

}

void Tools::clearConsole() { //Drops 30 lines

    cout << string(30, '\n');

}
