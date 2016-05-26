//
// Created by blackdartq on 5/24/16.
//

#include "Level.h"
#include "Audio.h"


Character character;
Tools tools;
Screen screen;
Entity entity;
SDL_Event event;
Spider spider(500, 800);
Audio audio1;


Level::Level() {


}

void Level::moveCharacter() {
    //const Uint8 *state = SDL_GetKeyboardState(NULL);
    while (tools.checkIfRunning()) {
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_D:
                        //cout << "right" << character.entityRect.x << endl;
                        if (character.entityRect.x >= 600) {
                            //screen.moveScreenLeft();character.

                        } else {
                            character.moveEntityRight(character.characterStandingRight, character.entityRect,
                                                      character.facingRight, character.attackingRight);
                        }

                        screen.moveScreen(character.entityRect);
                        screen.moveGround(character.entityRect);
                        break;

                    case SDL_SCANCODE_A:
                        //cout << "Left" << character.entityRect.x << endl;

                        if (character.entityRect.x == 0 && screen.backgroundShownRect.x >= 0) {


                        } else if (character.entityRect.x == 0) {
                            //screen.moveScreenRight();

                        } else {
                            character.moveEntityLeft("Img/CharacterStandingLeft.bmp", character.entityRect,
                                                     character.facingRight, character.attackingRight);
                        }
                        screen.moveScreen(character.entityRect);
                        screen.moveGround(character.entityRect);
                        break;

                    case SDL_SCANCODE_W:
                        //cout << "jump" << character.entityRect.x << endl;
                        character.moveEntityJump(character.characterStandingRight, character.entityRect,
                                                 character.facingRight,
                                                 character.attackingRight);

                        break;

                    case SDL_SCANCODE_SPACE:
                        //cout << "Attacking" << endl;
                        character.shadowBlast("Img/Character.bmp", character.entityRect, character.facingRight,
                                              character.attackingRight);


                        break;

                    case SDL_SCANCODE_ESCAPE:
                        cout << "Pressed escape" << endl;
                        audio1.stopMusic();
                        screen.quitSDL();
                        tools.quit();
                        break;

                }

            }

        }
    } cout << "out of While loop";
}

void Level::createScreen() {

    //Creates screen
    screen.createScreen();

    //Creates the renderer
    screen.createRenderer();
    screen.createRectangles();

    //renders the loading screen
    //and delays SDL to give time for the window to open
    //screen.loadAndRenderBmp("Img/Loading1.bmp");
    SDL_Delay(300);
    screen.backgroundShownRect.w = 1200;
    screen.changeBackground("Img/Loading1.bmp");
    SDL_RenderPresent(screen.renderer);
    SDL_Delay(1000);

    //Creates the thread and delays SDL to load the thread
    SDL_Delay(3000);

}



void Level::startMenu() {





}

void Level::level1(){


    character.setEntityPosition(0, 800);
    screen.backgroundShownRect.w = 5000;
    while (tools.checkIfRunning()) { //Main loop for the game

        //Clears the Renderer
        SDL_RenderClear(screen.renderer);


        //loads background image and the ground
        screen.changeBackground("Img/SkyBlueBackground.bmp");
        screen.changeGroundWithBmp("Img/BrickGround.bmp");


        //checks to see what direction the character is facing and then loads the character image
        screen.loadAndRenderBmp(entity.checkIfCharacterIsFacingRight(character.facingRight, character.attackingRight), character.entityRect);
        screen.loadAndRenderBmp("Img/Shadow.bmp", spider.entityRect);

        //loads characters attack rectangle
        screen.loadAndRenderBmp("Img/Shadow.bmp", character.attackRect);


        //renders everything above
        SDL_RenderPresent(screen.renderer);




    }

}



