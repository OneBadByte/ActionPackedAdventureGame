//
// Created by blackdartq on 5/10/16.
//

#ifndef ACTIONPACKEDADVENTUREGAME_TOOLS_H
#define ACTIONPACKEDADVENTUREGAME_TOOLS_H

#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

class Tools {

public:
    //quits the main loop
    void quit(bool runningBool);
    // checks if isRunning is true
    bool checkIfRunning(bool runningBool);
    // drops 30 strings in the console to make space
    void clearConsole();
    void start(bool runningBool);

    //Used to check if the main loop is running
    bool gameIsRunning = true;
    bool level1isRunning = true;
    bool level2isRunning = true;
    bool level3isRunning = true;
    bool level4isRunning = true;
    bool level5isRunning = true;



};


#endif //ACTIONPACKEDADVENTUREGAME_TOOLS_H
