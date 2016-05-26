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
//uses a thread to move the character by getting the keyboard input





//Threads

// calls moveCharacter()
static int characterThread(void *ptr) {
    level.moveCharacter();
    return 0;
}

static int introAudioThread(void *ptr){

    audio.playMusic("ghostofpredition.wav", 120);
}


SDL_Thread *thread1;
SDL_Thread *thread2;
//SDL_Thread *thread1;
//SDL_Thread *thread1;

int main() {


    thread1 = SDL_CreateThread(characterThread, "character Thread", (void *) NULL);
    level.createScreen();
    //thread2 = SDL_CreateThread(introAudioThread, "audio", (void *) NULL);
    level.startMenu();
    level.level1();
    cout << "past Level 1" << endl;

    // destroys character thread.
    SDL_DetachThread(thread1);
    SDL_DetachThread(thread2);


    return 0;
}