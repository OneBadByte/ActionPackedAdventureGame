#include <iostream>
#include <SDL2/SDL_image.h>
#include "Tools.h"
#include "Entity.h"
#include "Screen.h"
#include "Items.h"
#include "Audio.h"
#include <vector>


Character character;
Spider spider;
Spider spider2;
Spider spider3;
Tools tools;
Screen screen;
Entity entity;
SDL_Event event;
Audio audio1;








using namespace std;


// Objects
Audio audio;



//Thread functions




SDL_Thread *thread1;
SDL_Thread *thread2;
SDL_Thread *thread3;
//SDL_Thread *thread1;
//SDL_Thread *thread1;

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

void moveEnemiesWithScrene(SDL_Rect &enemyRect, bool &facingRight) {

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
    screen.changeBackground("Img/Name.bmp");
    SDL_RenderPresent(screen.renderer);
    SDL_Delay(3000);


}



void level1() {


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


void level2(){



}

void level3(){



}

void level4(){



}

void level5(){



}

static int characterThread(void *ptr) {

    moveCharacter(); //uses a thread to move the character by getting the keyboard input
    return 0;
}

static int introAudioThread(void *ptr) {

    //plays music for 120 seconds
    //audio.playMusic("Music/ghostofpredition.wav", 120);
}

static int enemyThread(void *ptr) {
    enemyAttackThread();
    return 0;

}




int main() {

    int levelChooser[6];

    cout << "What level do you want to use? Enter a number: ";
    for (int i = 0; i < 6; i++) {
        cin >> levelChooser[i];
    }

    createScreen();

    //thread2 = SDL_CreateThread(introAudioThread, "audio", (void *) NULL);


    //thread1 = SDL_CreateThread(characterThread, "character Thread", (void *) NULL);
    //level.testLevel();

    bool mainLoop = true;
    while (mainLoop) {
        int i = 0;

        switch (levelChooser[i]) {

            case 0:
                startMenu();


            case 1:
                thread1 = SDL_CreateThread(characterThread, "character Thread", (void *) NULL);
                thread3 = SDL_CreateThread(enemyThread, "enemy", (void *) NULL);
                level1();
                cout << "past Level 1" << endl;
                break;
            case 2:

                break;

            default:
                mainLoop = false;
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