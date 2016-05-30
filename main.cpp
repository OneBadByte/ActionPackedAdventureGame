#include <iostream>
#include <SDL2/SDL_image.h>
#include "Tools.h"
#include "Entity.h"
#include "Screen.h"
#include "Items.h"
#include "Level.h"
#include "Audio.h"


using namespace std;


// Objects

Audio audio;
Level level;


//Thread functions

static int characterThread(void *ptr) {

    level.moveCharacter(); //uses a thread to move the character by getting the keyboard input
    return 0;
}

static int introAudioThread(void *ptr){

    //plays music for 120 seconds
    //audio.playMusic("Music/ghostofpredition.wav", 120);
}



SDL_Thread *thread1;
SDL_Thread *thread2;
//SDL_Thread *thread1;
//SDL_Thread *thread1;

int main() {


    level.createScreen();

    thread2 = SDL_CreateThread(introAudioThread, "audio", (void *) NULL);
    level.startMenu();

    thread1 = SDL_CreateThread(characterThread, "character Thread", (void *) NULL);
    level.level1();
    cout << "past Level 1" << endl;


    // destroys threads.
    SDL_DetachThread(thread1);
    SDL_DetachThread(thread2);


    return 0;
}