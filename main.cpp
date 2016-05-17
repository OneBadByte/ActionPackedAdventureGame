#include <iostream>
#include <SDL2/SDL_image.h>
#include "Tools.h"
#include "Entity.h"
#include "Screen.h"
#include "Items.h"


using namespace std;


// Objects
Tools tools;
Screen screen;
Character character;
Entity entity;

int threadReturnValue;


void moveCharacter(){
    SDL_Event event;
    //cout << "in do while loop" << endl;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_D:
                        cout << "right" << character.entityRect.x << endl;
                        character.moveEntityRight(character.image, character.entityRect);

                        continue;

                    case SDL_SCANCODE_A:
                        cout << "Left" << character.entityRect.x << endl;
                        character.moveEntityLeft(character.image, character.entityRect);

                        continue;

                    case SDL_SCANCODE_W:
                        cout << "jump" << character.entityRect.x << endl;
                        character.moveEntityJump(character.image, character.entityRect);

                        continue;

                    case SDL_SCANCODE_SPACE:
                        cout << "Attacking" << endl;
                        character.Attack("Shadow.bmp", character.entityRect);
                        continue;

                    case SDL_SCANCODE_ESCAPE:
                        cout << "Pressed escape" << endl;

                        tools.quit();
                }
                break;

            }
            break;

        }

    }



//Threads
static int staticCharacterThread(void *ptr) {

    moveCharacter();
    return 0;
}


int main() {

    Screen screen;

    screen.createScreen();
    screen.createRenderer();

    screen.loadAndRenderBmp("Loading1.bmp");
    SDL_RenderPresent(screen.renderer);
    SDL_Delay(1000);


    Spider spider("spongy",12,12,12,12);
    SDL_Thread *thread;

    while (tools.checkIfRunning()) { //Main loop for the game

        SDL_Rect stuff;
        stuff.x = 100;
        stuff.y = 100;
        stuff.h = 100;
        stuff.w = 100;


        thread = SDL_CreateThread(staticCharacterThread,"stuff", (void*)NULL);
        screen.loadAndRenderBmp("Shadow.bmp", character.attackRect);
        screen.loadAndRenderBmp("Land1.bmp");
        screen.changeGroundWithBmp("BrickGround.bmp");
        screen.loadAndRenderBmp(character.image, character.entityRect);
        SDL_RenderPresent(screen.renderer);

        SDL_RenderClear(screen.renderer);




    }
    SDL_DetachThread(thread);
    screen.quitSDL();
    tools.quit();
    return 0;
}