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

        SDL_Rect stuff;
        stuff.x = 0;
        stuff.y = 0;
        stuff.h = 1000;
        stuff.w = 1000;

        SDL_Rect character;
        character.x = 0;
        character.y = 650;
        character.h = 100;
        character.w = 100;

        screen.loadAndRenderBmp("Welcome.bmp");
        SDL_RenderPresent(screen.renderer);
        SDL_Delay(500);



        for(int i = 0; i < 100; i++){

            //SDL_RenderClear(screen.renderer);
            screen.loadAndRenderBmp("Land1.bmp");
            character.x = i*12;


        }



        tools.quit();

    }


    screen.quitSDL();

    return 0;
}