//
// Created by blackdartq on 5/25/16.
//

#ifndef ACTIONPACKEDADVENTUREGAME_AUDIO_H
#define ACTIONPACKEDADVENTUREGAME_AUDIO_H

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_mixer.h>

using namespace std;

class Audio {

public:

    //The music that will be played
    Mix_Music *music = NULL;

//The sound effects that will be used
    Mix_Chunk *scratch = NULL;


    bool musicRunning = true;

    void playMusic(const char* song,int seconds);
    void stopMusic();

};

#endif //ACTIONPACKEDADVENTUREGAME_AUDIO_H
