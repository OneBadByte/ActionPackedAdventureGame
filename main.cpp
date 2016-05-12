#include <iostream>
#include <SDL2/SDL_image.h>
#include "Tools.h"
#include "Character.h"
#include "Screen.h"


using namespace std;

int main() {

    // Objects
    Tools tools;
    Screen screen;



    while(tools.checkIfRunning()) { //Main loop for the game

        screen.changeBackground(100, 100, 100, 255); // changes the background color and renders it.




            cout << "Welcome!" << endl;
            cout << endl;
            Character character;
            tools.clearConsole();
            character.info();

            tools.quit();

    }


    screen.quitSDL();

    return 0;
}