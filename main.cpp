#include <iostream>
#include <SDL2/SDL_image.h>
#include "Tools.h"
#include "Character.h"
#include "Screen.h"
#include "Items.h"
#include "Control.h"


using namespace std;


// Objects
Tools tools;

Character character;

//Threads



int main() {

    Screen screen;
    Control control;

    while (tools.checkIfRunning()) { //Main loop for the game

        screen.loadAndRenderBmp("Land1.bmp");
        screen.loadAndRenderBmp("BrickGround.bmp", control.ground);
        screen.loadAndRenderBmp("Character.bmp", control.character);
        SDL_RenderPresent(screen.renderer);
        SDL_Delay(5000);
        SDL_RenderClear(screen.renderer);


        tools.quit();

    }


    screen.quitSDL();

    return 0;
}