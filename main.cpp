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
Character character(0, 800);
Entity entity;
SDL_Event event;

void moveScreen(){

    if(character.entityRect.x >= 600 ){
        screen.moveScreenLeft();

    }else if(character.entityRect.x == 0 && screen.backgroundShownRect.x >= 0){


    }else if(character.entityRect.x == 0){
        screen.moveScreenRight();

    }



}

//uses a thread to move the character by getting the keyboard input
void moveCharacter(){
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_D:
                        //cout << "right" << character.entityRect.x << endl;
                        if(character.entityRect.x >= 600 ){
                            //screen.moveScreenLeft();

                        }else {
                            character.moveEntityRight(character.characterStandingRight, character.entityRect,
                                                      character.facingRight, character.attackingRight);
                        }

                        moveScreen();
                        break;

                    case SDL_SCANCODE_A:
                        //cout << "Left" << character.entityRect.x << endl;

                        if(character.entityRect.x == 0 && screen.backgroundShownRect.x >= 0){


                        }else if(character.entityRect.x == 0){
                            //screen.moveScreenRight();

                        }else {
                            character.moveEntityLeft("Img/CharacterStandingLeft.bmp", character.entityRect,
                                                     character.facingRight, character.attackingRight);
                        }
                        moveScreen();
                        break;

                    case SDL_SCANCODE_W:
                        //cout << "jump" << character.entityRect.x << endl;
                        character.moveEntityJump(character.characterStandingRight, character.entityRect, character.facingRight, character.attackingRight);

                        break;

                    case SDL_SCANCODE_SPACE:
                        //cout << "Attacking" << endl;
                        character.shadowBlast("Img/Character.bmp", character.entityRect, character.facingRight, character.attackingRight);
                        break;

                    case SDL_SCANCODE_ESCAPE:
                        cout << "Pressed escape" << endl;
                        tools.quit();
                        break;
                }



              //  break;

            }
            //break;

        }

    }



//Threads

// calls moveCharacter()
static int characterThread(void *ptr) {

    moveCharacter();

    return 0;
}

static int enemyThread(void *ptr){



    return 0;
}


int main() {

    //Creates screen
    screen.createScreen();

    //Creates the renderer
    screen.createRenderer();

    //renders the loading screen
    //and delays SDL to give time for the window to open
    //screen.loadAndRenderBmp("Img/Loading1.bmp");
    SDL_Delay(300);
    screen.changeBackground("Img/Loading1.bmp");
    SDL_RenderPresent(screen.renderer);
    SDL_Delay(1000);

    //Creates the thread and delays SDL to load the thread
    SDL_Thread *thread;
    SDL_Delay(3000);
    Spider spider(500, 800);


    while (tools.checkIfRunning()) { //Main loop for the game

        //Clears the Renderer
        SDL_RenderClear(screen.renderer);


        //loads background image and the ground
        screen.changeBackground("Img/Land1.bmp");
        screen.changeGroundWithBmp("Img/BrickGround.bmp");


        //checks to see what direction the character is facing and then loads the character image
        screen.loadAndRenderBmp(entity.checkIfCharacterIsFacingRight(character.facingRight, character.attackingRight), character.entityRect);
        screen.loadAndRenderBmp("Img/Shadow.bmp", spider.entityRect);

        //loads characters attack rectangle
        screen.loadAndRenderBmp("Img/Shadow.bmp", character.attackRect);


        //renders everything above
        SDL_RenderPresent(screen.renderer);

        // assigns thread to characterThread
        thread = SDL_CreateThread(characterThread,"character Thread", (void*)NULL);



    }

    // destroys character thread.
    SDL_DetachThread(thread);
    return 0;
}