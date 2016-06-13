//
// Created by blackdartq on 5/10/16.
//

#include "Tools.h"
#include "Screen.h"


//start the game
void Tools::start(bool runningBool){

    cout << "starting level" << endl;
    runningBool = true;

}


//quits the game
void Tools::quit(bool runningBool) {
    cout << "stopping game" << endl;
    runningBool = false;



}

// checks if the game is still running.
bool Tools::checkIfRunning(bool runningBool) {

    if (runningBool) {

        return true;

    } else {
        return false;

    }

}

//Drops 30 lines
void Tools::clearConsole() {

    cout << string(30, '\n');

}
