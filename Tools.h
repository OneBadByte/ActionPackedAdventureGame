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
    void quit(); //quits the main loop
    bool checkIfRunning();  // checks if isRunning is true
    void clearConsole();    // drops 30 strings in the console to make space

private:
    bool isRunning = true;


};


#endif //ACTIONPACKEDADVENTUREGAME_TOOLS_H
