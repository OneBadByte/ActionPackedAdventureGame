#include <iostream>
#include <SDL2/SDL_image.h>
#include "Tools.h"
#include "Character.h"
#include "Screen.h"
#include "Items.h"


using namespace std;


// Objects
Tools tools;

Character character;

//Threads



int main() {

    Screen screen;
    while (tools.checkIfRunning()) { //Main loop for the game


        /*
        screen.changeBackground(100, 100, 100, 255); // changes the background color and renders it.
        character.characterCreation();
        tools.clearConsole();

        character.info();
        */

        Spider spider1("fuzzy", 21, 22,34,45);

        spider1.info();

        FlamingIronSword flamingIronSword("superSword", 12, 23,12);
        flamingIronSword.info();





        tools.quit();

    }


    screen.quitSDL();

    return 0;
}