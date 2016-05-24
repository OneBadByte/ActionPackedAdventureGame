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
    void quit();
    // checks if isRunning is true
    bool checkIfRunning();
    // drops 30 strings in the console to make space
    void clearConsole();

private:
    //Used to check if the main loop is running
    bool isRunning = true;


};


#endif //ACTIONPACKEDADVENTUREGAME_TOOLS_H
