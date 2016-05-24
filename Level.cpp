//
// Created by blackdartq on 5/24/16.
//

#include "Level.h"
#include "Thread.h"


Level1::Level1() {

    Tools tools;
    Screen screen;
    Character character(0, 800);
    Entity entity;
    SDL_Event event;
    //Thread threadObject;

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
    //SDL_Thread *thread;
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
        //thread = SDL_CreateThread(threadObject.characterThread,"character Thread", (void*)NULL);



    }

    // destroys character thread.
    //SDL_DetachThread(thread);



}
