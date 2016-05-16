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
static int staticCharacterThread(void *ptr) {
    Screen screen;
    int cnt = 0;
    SDL_Event event;
    cout << "in do while loop" << endl;

    bool loopRunning = true;
    while (loopRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_D:
                        character.moveCharacterRight();
                        //cout << "right" << endl;
                        continue;

                    case SDL_SCANCODE_A:
                        character.moveCharacterLeft();
                        //cout << "Left" << endl;
                        continue;

                    case SDL_SCANCODE_W:
                        character.moveCharacterJump();
                        //cout << "jump" << endl;
                        continue;

                    case SDL_SCANCODE_ESCAPE:
                        loopRunning = false;
                        cout << "Pressed escape" << endl;
                        break;
                }

            }

        }


    }

screen.quitSDL();
tools.quit();

return 0;
}


int main() {
    Screen screen;

    SDL_Thread *characterThread;
    characterThread = SDL_CreateThread(staticCharacterThread, "thread and stuff", (void *) NULL);

    screen.createScreen();
    screen.createRenderer();
    while (tools.checkIfRunning()) { //Main loop for the game

        screen.loadAndRenderBmp("Land1.bmp");
        screen.changeGroundWithBmp("BrickGround.bmp");
        screen.loadAndRenderBmp("Character.bmp", character.characterRect);
        SDL_RenderPresent(screen.renderer);
        SDL_RenderClear(screen.renderer);



        /*
        while (true) {

            SDL_RenderClear(screen.renderer);
            screen.loadAndRenderBmp("Land1.bmp");
            screen.changeGroundWithBmp("Welcome.bmp");
            screen.loadAndRenderBmp("Character.bmp", character.characterRect);
            SDL_RenderPresent(screen.renderer);

        }*/




    }


    return 0;
}