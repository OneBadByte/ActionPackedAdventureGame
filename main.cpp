#include <iostream>
#include <SDL2/SDL_image.h>
#include "Tools.h"
#include "Entity.h"
#include "Screen.h"
#include "Items.h"
#include "Audio.h"
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

//used in a thread to move the character
void moveCharacter() {

    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_D:

                    if (character.entityRect.x >= 600) {

                    } else {

                        character.moveEntityRight(10);
                    }

                    screen.moveScene(character.entityRect);
                    break;

                case SDL_SCANCODE_A:

                    if (character.entityRect.x == 0 && screen.backgroundRect.x >= 0) {


                    } else if (character.entityRect.x == 0) {


                    } else {

                        character.moveEntityLeft(10);

                    }

                    screen.moveScene(character.entityRect);
                    break;

                case SDL_SCANCODE_W:

                    character.moveEntityJump(10);
                    break;

                case SDL_SCANCODE_SPACE:

                    if (character.mana >= 0) {
                        character.mana = character.mana - 50;
                        character.shadowBlast();

                    }
                    break;

                case SDL_SCANCODE_ESCAPE:
                    cout << "Pressed escape" << endl;
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


static int characterThread(void *ptr) {

    while (tools.gameIsRunning) {
        moveCharacter();


    }
    return 0;

}

static int introAudioThread(void *ptr) {

    //plays music for 120 seconds
    audio.playMusic("Music/ghostofpredition.wav", 120);


}


static int enemyThread(void *ptr) {

    while (tools.checkIfRunning(tools.gameIsRunning)) {


        spider.moveEnemyTowardsCharacter(character.entityRect);
        spider2.moveEnemyTowardsCharacter(character.entityRect);
        spider3.moveEnemyTowardsCharacter(character.entityRect);

        spider.moveEnemiesWithScreen(character.entityRect, screen.backgroundRect);
        spider2.moveEnemiesWithScreen(character.entityRect, screen.backgroundRect);
        spider3.moveEnemiesWithScreen(character.entityRect, screen.backgroundRect);

        spider.attackIfCharacterNear(character.entityRect);
        spider2.attackIfCharacterNear(character.entityRect);
        spider3.attackIfCharacterNear(character.entityRect);


    }
    return 0;

}

static int lifeThread(void *ptr) {
    while (tools.checkIfRunning(tools.gameIsRunning)) {


        spider.checkIfAlive();
        spider2.checkIfAlive();
        spider3.checkIfAlive();
        character.checkIfAlive();

        character.gotHit(spider.entityRect, spider.attackRect, 0);
        character.gotHit(spider2.entityRect, spider2.attackRect, 0);
        character.gotHit(spider3.entityRect, spider3.attackRect, 0);

        spider.gotHit(character.attackRect, character.attack);
        spider2.gotHit(character.attackRect, character.attack);
        spider3.gotHit(character.attackRect, character.attack);


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
    spider.setEntityPosition(2800, 800);
    spider2.setEntityPosition(1899, 800);
    spider3.setEntityPosition(1200, 800);
    screen.backgroundRect.w = 5000;
    screen.groundRect.w = 5000;

    thread1 = SDL_CreateThread(characterThread, "character Thread", (void *) NULL);
    thread3 = SDL_CreateThread(enemyThread, "enemy", (void *) NULL);
    thread2 = SDL_CreateThread(lifeThread, "Life", (void *) NULL);

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

        if (screen.backgroundRect.x >= 5000) {

            tools.quit(tools.level1isRunning);

        }

        if (character.mana < 300) {
            character.mana += 2;
        }


    }

}


void level2() {


}

void level3() {


}

void level4() {


}

void level5() {


}


void levelPicker() {
    bool loopRunning = true;
    char levelToStart;

    while (loopRunning) {
        cout << "What level would you like to start on?: ";
        cin >> levelToStart;
        switch (levelToStart) {

            case '1':
                cout << "Print one" << endl;
                level1();
            case '2':
                cout << "Print two" << endl;
                level2();
            case '3':
                cout << "Print three" << endl;
                level3();
            case '4':
                cout << "Print four" << endl;
                level4();
            case '5':
                cout << "Print five" << endl;
                level5();
                loopRunning = false;
                break;

            default:
                cout << "be serious, lol noob" << endl;

                continue;
        }


    }


}


int main() {

    /*
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
    int i = 0;
    while (tools.checkIfRunning(tools.gameIsRunning)) {


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

    } */


    createScreen();
    levelPicker();

    // destroys threads.
    SDL_DetachThread(thread1);
    SDL_DetachThread(thread2);
    SDL_DetachThread(thread3);
    audio.stopMusic();
    screen.quitSDL();
    return 0;
}