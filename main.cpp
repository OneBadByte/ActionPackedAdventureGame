#include <iostream>
#include <SDL2/SDL_image.h>
#include "Tools.h"
#include "Entity.h"
#include "Screen.h"
#include "Items.h"
#include "Level.h"


using namespace std;


// Objects


Level level;
//uses a thread to move the character by getting the keyboard input





//Threads

// calls moveCharacter()
static int characterThread(void *ptr) {
    level.moveCharacter();
    return 0;
}


SDL_Thread *thread;

int main() {


    thread = SDL_CreateThread(characterThread, "character Thread", (void *) NULL);
    level.createScreen();
    level.startMenu();
    level.level1();
    cout << "past Level 1" << endl;

    // destroys character thread.
    SDL_DetachThread(thread);


    return 0;
}