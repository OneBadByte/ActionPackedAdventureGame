#include <iostream>
#include <SDL2/SDL_image.h>
#include "Tools.h"
#include "Entity.h"
#include "Screen.h"
#include "Items.h"
#include "Audio.h"
#include <vector>
#include "AttributeStrings.h"

AttributeStrings strings;
Character character;
Spider spider;
Spider spider2;
Spider spider3;
Tools tools;
Screen screen;
Entity entity;
SDL_Event event;
Audio audio;
SDL_Thread *thread1;
SDL_Thread *thread2;
SDL_Thread *thread3;

using namespace std;

//SDL_Thread *thread1;
//SDL_Thread *thread1;

//used in a thread to move the character
void moveCharacter() {

    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_D:
                    //cout << "right" << character.entityRect.x << endl;
                    if (character.entityRect.x >= 600) {
                        //screen.moveScreenLeft();character.

                    } else {
                        //character.moveEntityRight(character.characterStandingRight, character.entityRect,
                          //                        character.facingRight);

                        character.moveEntityRight();
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
                        //character.moveEntityLeft(strings.CharacterStandingLeft, character.entityRect,
                        //                         character.facingRight);
                        character.moveEntityLeft();

                    }
                    //screen.moveScreen(character.entityRect);
                    //screen.moveGround(character.entityRect);
                    screen.moveScene(character.entityRect);
                    break;

                case SDL_SCANCODE_W:
                    //cout << "jump" << character.entityRect.x << endl;
                    //character.moveEntityJump(character.characterStandingRight, character.entityRect,
                    //                         character.facingRight);

                    character.moveEntityJump();

                    break;

                case SDL_SCANCODE_SPACE:
                    //cout << "Attacking" << endl;
                    if (character.mana >= 0) {
                        character.mana = character.mana - 50;
                        //character.shadowBlast(strings.Shadow, character.entityRect, character.facingRight);
                        character.shadowBlast();
                    }

                    break;

                case SDL_SCANCODE_ESCAPE:
                    cout << "Pressed escape" << endl;
                    audio.stopMusic();
                    screen.quitSDL();
                    tools.quit(tools.level1isRunning);
                    tools.quit(tools.level2isRunning);
                    tools.quit(tools.level3isRunning);
                    tools.quit(tools.level4isRunning);
                    tools.quit(tools.level5isRunning);
                    tools.quit(tools.gameIsRunning);

                    break;

            }

        }

    }
}

void enemyAttackThread() {

    while (tools.checkIfRunning(tools.gameIsRunning)) {

        if (character.entityRect.x < spider.entityRect.x) {

            //spider.shadowBlast(strings.Shadow, spider.entityRect, spider.facingRight);\

            SDL_Delay(500);
        }

    }


}

void enemyAttack(SDL_Rect &enemyRect, bool enemyFacingRight, SDL_Rect &enemyAttackRect) {


        if (character.entityRect.x < enemyRect.x) {

            spider.shadowBlast(strings.Shadow, enemyAttackRect, enemyFacingRight);
        }


}


void startScreen(){

    int SDL_CaptureMouse(SDL_bool enabled);



}


void moveEnemysLeft(SDL_Rect &rect, bool &enemyFacingRight) {
    enemyFacingRight = false;
    rect.x = rect.x - 5;

}

void moveEnemysRight(SDL_Rect &rect, bool &entityFacingRight) {
    entityFacingRight = true;
    character.facingRight = entityFacingRight;
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

void moveEnemiesWithScreen(SDL_Rect &enemyRect, bool &facingRight) {

    if (character.entityRect.x >= 1000) {
        moveEnemysLeft(enemyRect, facingRight);


    } else if (character.entityRect.x <= -100) {

        moveEnemysRight(enemyRect, facingRight);

    }

}


void getEnemies() {

    for (int i = 0; i < 3; i++) {

        //spiderVector[i] = i;



    }


}

static int characterThread(void *ptr) {

    while(tools.gameIsRunning) {
        character.checkIfAlive();
        moveCharacter(); //uses a thread to move the character by getting the keyboard input

        /*
        character.gotHit(spider.entityRect, 1);
        character.gotHit(spider.attackRect, 5);
        character.gotHit(spider2.entityRect, 1);
        character.gotHit(spider2.attackRect, 5);
        character.gotHit(spider3.attackRect, 1);
        character.gotHit(spider3.attackRect, 5);
         */

        character.gotHit(spider.entityRect, spider.attackRect, 0);
        character.gotHit(spider2.entityRect, spider2.attackRect, 0);
        character.gotHit(spider3.entityRect, spider3.attackRect, 0);




    }
    return 0;

}

static int introAudioThread(void *ptr) {

    //plays music for 120 seconds
    //audio.playMusic("Music/ghostofpredition.wav", 120);
}

static int enemyThread(void *ptr) {

    while(tools.checkIfRunning(tools.gameIsRunning)) {


        spider.checkIfAlive();
        spider2.checkIfAlive();
        spider3.checkIfAlive();

        spider.gotHit(character.attackRect, 500);
        spider2.gotHit(character.attackRect, 500);
        spider3.gotHit(character.attackRect, 500);

        spider.moveEnemyTowardsCharacter(character.entityRect);
        spider2.moveEnemyTowardsCharacter(character.entityRect);
        spider3.moveEnemyTowardsCharacter(character.entityRect);

        spider.attackIfCharacterNear(character.entityRect);
        spider2.attackIfCharacterNear(character.entityRect);
        spider3.attackIfCharacterNear(character.entityRect);


    }
    return 0;

}


//creates the screen, renderer, and loads the loading screen.
void createScreen() {

    //Creates screen
    screen.createScreen();

    //Creates the renderer
    screen.createRenderer();
    screen.createRectangles();


}

void startMenu() {

    screen.backgroundRect.w = 1200;
    screen.changeBackground(strings.Name);
    SDL_RenderPresent(screen.renderer);
    SDL_Delay(3000);


}



void level1() {


    character.setEntityPosition(0, 800);
    spider.setEntityPosition(600, 800);
    spider2.setEntityPosition(699, 800);
    spider3.setEntityPosition(1200, 800);
    screen.backgroundRect.w = 5000;
    screen.groundRect.w = 5000;

    thread1 = SDL_CreateThread(characterThread, "character Thread", (void *) NULL);
    thread3 = SDL_CreateThread(enemyThread, "enemy", (void *) NULL);
    while (tools.checkIfRunning(tools.level1isRunning)) { //Main loop for the game

        //Clears the Renderer
        SDL_RenderClear(screen.renderer);


        //loads background image and the ground
        screen.changeBackground(strings.GrassyBackground);
        screen.changeGroundWithBmp(strings.BlueGround);

        //load Health, and Mana bars
        screen.loadHealthAndManaBar(character.healthBar, character.manaBar, character.health,
                                    character.mana);


        //checks to see what direction the character is facing and then loads the character image
        screen.loadAndRenderBmp(entity.checkIfCharacterIsFacingRight(character.facingRight),
                                character.entityRect);




        //moves the enemies
        //moveEnemies(spider.entityRect, spider.facingRight, spider.pace);
        //moveEnemies(spider2.entityRect, spider2.facingRight, spider2.pace);
        //moveEnemies(spider3.entityRect, spider3.facingRight, spider3.pace);


        moveEnemiesWithScreen(spider.entityRect, spider.facingRight);
        moveEnemiesWithScreen(spider2.entityRect, spider2.facingRight);
        moveEnemiesWithScreen(spider3.entityRect, spider3.facingRight);


        screen.loadAndRenderBmp(strings.CharacterStandingLeft, spider.entityRect);
        screen.loadAndRenderBmp(strings.CharacterStandingLeft, spider2.entityRect);
        screen.loadAndRenderBmp(strings.CharacterStandingLeft, spider3.entityRect);


        //loads characters attack rectangle

        screen.loadAndRenderBmp(strings.Shadow, character.attackRect);
        screen.loadAndRenderBmp(strings.Shadow, spider.attackRect);
        screen.loadAndRenderBmp(strings.Shadow, spider2.attackRect);
        screen.loadAndRenderBmp(strings.Shadow, spider3.attackRect);


        //renders everything above
        SDL_RenderPresent(screen.renderer);

        if(screen.backgroundRect.x >= 5000){

            tools.quit(tools.level1isRunning);

        }

        if (character.mana < 300) {
            character.mana += 2;
        }



        // checks if entities have been hit
        /*
        character.gotHit(spider.entityRect);
        character.gotHit(spider.attackRect);
        character.gotHit(spider2.entityRect);
        character.gotHit(spider3.attackRect);

        spider.gotHit(character.attackRect);
        spider2.gotHit(character.attackRect);
        spider3.gotHit(character.attackRect);




        */
    }

}


void level2(){



}

void level3(){



}

void level4(){



}

void level5(){



}







int main() {

    int levelChooser[6];

    int levelsUsing = 0;

    cout << "How many Levels do you want to use?: ";
    cin >> levelsUsing;

    cout << "What level do you want to use? Enter a number: ";
    for (int i = 0; i < levelsUsing; i++) {
        cin >> levelChooser[i];
    }

    createScreen();

    //thread2 = SDL_CreateThread(introAudioThread, "audio", (void *) NULL);


    //thread1 = SDL_CreateThread(characterThread, "character Thread", (void *) NULL);
    //level.testLevel();

    while (tools.checkIfRunning(tools.gameIsRunning)) {
        int i = 0;

        switch (levelChooser[i]) {

            case 0:
                startMenu();


            case 1:
                level1();
                cout << "past Level 1" << endl;
                break;
            case 2:

                break;

            default:
                tools.quit(tools.gameIsRunning);
                break;

        }

        i++;

    }
    // destroys threads.
    SDL_DetachThread(thread1);
    SDL_DetachThread(thread2);
    SDL_DetachThread(thread3);
    return 0;
}