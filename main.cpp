#include <iostream>
#include <SDL2/SDL_image.h>
#include "Tools.h"
#include "Character.h"
#include "Screen.h"


using namespace std;


// Objects
Tools tools;

Character character;

//Threads



int main() {

    Screen screen;
    while (tools.checkIfRunning()) { //Main loop for the game




        Spider spider("squishy", 100, 200, 300 ,1000);
        spider.info();

        /*
        screen.changeBackground(100, 100, 100, 255); // changes the background color and renders it.
        character.characterCreation();
        tools.clearConsole();

        character.info();
        */
        tools.quit();

    }


    screen.quitSDL();

    return 0;
}