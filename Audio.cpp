//
// Created by blackdartq on 5/25/16.
//

#include "Audio.h"

// plays music but needs a song and seconds of the song past in.
void Audio::playMusic(const char *song, int seconds) {
    SDL_Event event;
    seconds = seconds * 1000;

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());

    }

    Mix_AllocateChannels(5); //Allocates channels to be used
    scratch = Mix_LoadWAV(song); //loads the song that passed in.

    if (scratch == NULL) { // checks to see if there was anything passed in
        printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
    }

    Mix_PlayChannel(-1, scratch, 0); // plays music using any channel that's available

    while(musicRunning) { //plays music until stopMusic() is used

    }

    Mix_FreeChunk(scratch);
    Mix_Quit();

}

//stops Music on all channels
void Audio::stopMusic() {

    Mix_HaltChannel(-1); //stops all audio channels.
    cout << "Music Halted";

}
