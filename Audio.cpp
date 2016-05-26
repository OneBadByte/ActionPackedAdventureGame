//
// Created by blackdartq on 5/25/16.
//

#include "Audio.h"


void Audio::playMusic(const char *song, int seconds) {
    SDL_Event event;
    seconds = seconds * 1000;

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());

    }

    Mix_AllocateChannels(2);
    scratch = Mix_LoadWAV(song);
    if (scratch == NULL) {
        printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
    }


    Mix_PlayChannel(-1, scratch, 0);

    //for (int i = 0; i <= seconds; i++) {
    while(musicRunning) {
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_R:
                        //cout << "right" << character.entityRect.x << endl;
                        stopMusic();
                        musicRunning = false;
                        break;


                }

            }

        }
    }

    Mix_FreeChunk(scratch);
    Mix_Quit();

}

void Audio::stopMusic() {

    Mix_HaltChannel(-1);
    cout << "Music Halted";

}
