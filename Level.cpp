//
// Created by blackdartq on 5/24/16.
//

#include "Level.h"
#include "Audio.h"


Character character;
Spider spider;
Spider spider2;
Spider spider3;
Tools tools;
Screen screen;
Entity entity;
SDL_Event event;
Audio audio1;


Level::Level() {




}

//used in a thread to move the character
void moveCharacter() {

    //const Uint8 *state = SDL_GetKeyboardState(NULL);
    while (tools.checkIfRunning(tools.gameIsRunning)) {
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_D:
                        //cout << "right" << character.entityRect.x << endl;
                        if (character.entityRect.x >= 600) {
                            //screen.moveScreenLeft();character.

                        } else {
                            character.moveEntityRight(character.characterStandingRight, character.entityRect,
                                                      character.facingRight);
                        }

                        //screen.moveScreen(character.entityRect);
                        //screen.moveGround(character.entityRect);
                        screen.moveScene(character.entityRect);
                        break;

                    case SDL_SCANCODE_A:
                        //cout << "Left" << character.entityRect.x << endl;

                        if (character.entityRect.x == 0 && screen.backgroundRect.x >= 0) {


                        } else if (character.entityRect.x == 0) {
                            //screen.moveScreenRight();

                        } else {
                            character.moveEntityLeft("Img/CharacterStandingLeft.bmp", character.entityRect,
                                                     character.facingRight);
                        }
                        //screen.moveScreen(character.entityRect);
                        //screen.moveGround(character.entityRect);
                        screen.moveScene(character.entityRect);
                        break;

                    case SDL_SCANCODE_W:
                        //cout << "jump" << character.entityRect.x << endl;
                        character.moveEntityJump(character.characterStandingRight, character.entityRect,
                                                 character.facingRight);

                        break;

                    case SDL_SCANCODE_SPACE:
                        //cout << "Attacking" << endl;
                        if (character.mana >= 0) {
                            character.mana = character.mana - 50;
                            character.shadowBlast("Img/Shadow.bmp", character.entityRect, character.facingRight);
                        }

                        break;

                    case SDL_SCANCODE_ESCAPE:
                        cout << "Pressed escape" << endl;
                        audio1.stopMusic();
                        screen.quitSDL();
                        tools.quit(tools.gameIsRunning);
                        break;

                }

            }

        }
    }
    cout << "out of While loop";
}

void enemyAttackThread() {

    while (tools.checkIfRunning(tools.gameIsRunning)) {

        if (character.entityRect.x < spider.entityRect.x) {

            spider.shadowBlast("Shadow.bmp", spider.entityRect, spider.facingRight);
            SDL_Delay(500);
        }

    }


}

void startScreen(){

    int SDL_CaptureMouse(SDL_bool enabled);



}


void moveEnemysLeft(SDL_Rect &rect, bool &facingRight) {
    facingRight = false;
    rect.x = rect.x - 5;

}

void moveEnemysRight(SDL_Rect &rect, bool &facingRight) {
    facingRight = true;
    rect.x = rect.x + 5;
}

void moveEnemies() {
    spider.entityRect;
    int movementRange = 20;
    while (tools.checkIfRunning(tools.gameIsRunning)) {
        for (int i = 0; i < movementRange; i++) {
            moveEnemysLeft(spider.entityRect, spider.facingRight);
            SDL_Delay(100);

        }

        for (int i = 0; i < movementRange; i++) {
            moveEnemysRight(spider.entityRect, spider.facingRight);
            SDL_Delay(100);

        }


    }


}

void moveEnemies(SDL_Rect &rect, bool &moveRight, int &pace) {

    if (rect.x >= character.entityRect.x) {
        moveEnemysLeft(rect, moveRight);


    } else if (rect.x <= character.entityRect.x) {
        moveEnemysRight(rect, moveRight);

    }


}


void getEnemies() {

    for (int i = 0; i < 3; i++) {

        //spiderVector[i] = i;



    }


}

//creates the screen, renderer, and loads the loading screen.
void createScreen() {

    //Creates screen
    screen.createScreen();

    //Creates the renderer
    screen.createRenderer();
    screen.createRectangles();


}

void Level::startMenu() {

    screen.backgroundRect.w = 1200;
    screen.changeBackground("Img/Name.bmp");
    SDL_RenderPresent(screen.renderer);
    SDL_Delay(3000);


}





void Level::testLevel() {


}


void Level::level1() {


    character.setEntityPosition(0, 800);
    spider.setEntityPosition(1000, 800);
    spider2.setEntityPosition(399, 800);
    spider3.setEntityPosition(1200, 800);
    screen.backgroundRect.w = 5000;
    screen.groundRect.w = 5000;

    while (tools.checkIfRunning(tools.level1isRunning)) { //Main loop for the game

        //Clears the Renderer
        SDL_RenderClear(screen.renderer);


        //loads background image and the ground
        screen.changeBackground("Img/GrassyBackground.bmp");
        screen.changeGroundWithBmp("Img/BlueGround.bmp");

        //load Health, and Mana bars
        screen.loadHealthAndManaBar(character.healthBar, character.manaBar, character.health,
                                    character.mana);


        //checks to see what direction the character is facing and then loads the character image
        screen.loadAndRenderBmp(entity.checkIfCharacterIsFacingRight(character.facingRight),
                                character.entityRect);


        character.checkIfAlive();
        spider.checkIfAlive();
        spider2.checkIfAlive();
        spider3.checkIfAlive();


        //moves the enemies


        moveEnemies(spider.entityRect, spider.facingRight, spider.pace);
        moveEnemies(spider2.entityRect, spider2.facingRight, spider2.pace);
        moveEnemies(spider3.entityRect, spider3.facingRight, spider3.pace);

        moveEnemiesWithScrene(spider.entityRect, spider.facingRight);
        moveEnemiesWithScrene(spider2.entityRect, spider2.facingRight);
        moveEnemiesWithScrene(spider3.entityRect, spider3.facingRight);


        screen.loadAndRenderBmp("Img/CharacterStandingLeft.bmp", spider.entityRect);
        screen.loadAndRenderBmp("Img/CharacterStandingLeft.bmp", spider2.entityRect);
        screen.loadAndRenderBmp("Img/CharacterStandingLeft.bmp", spider3.entityRect);


        //loads characters attack rectangle
        screen.loadAndRenderBmp("Img/Shadow.bmp", character.attackRect);
        screen.loadAndRenderBmp("Img/Shadow.bmp", spider.attackRect);
        screen.loadAndRenderBmp("Img/Shadow.bmp", spider2.attackRect);
        screen.loadAndRenderBmp("Img/Shadow.bmp", spider3.attackRect);


        //renders everything above
        SDL_RenderPresent(screen.renderer);


        // checks if entities have been hit
        character.gotHit(spider.entityRect);
        character.gotHit(spider.attackRect);
        character.gotHit(spider2.entityRect);
        character.gotHit(spider3.attackRect);

        spider.gotHit(character.attackRect);
        spider2.gotHit(character.attackRect);
        spider3.gotHit(character.attackRect);


        if(screen.backgroundRect.x >= 5000){

            tools.quit(tools.level1isRunning);

        }

        if (character.mana < 300) {
            character.mana += 2;
        }


    }

}


void Level::level2(){



}

void Level::level3(){



}

void Level::level4(){



}

void Level::level5(){



}
