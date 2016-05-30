//
// Created by blackdartq on 5/11/16.
//

#ifndef ACTIONPACKEDADVENTUREGAME_SCREEN_H
#define ACTIONPACKEDADVENTUREGAME_SCREEN_H

#include "Tools.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Screen {

public:
    // SDL value for the window
    SDL_Window *window;
    //SDL renderer
    SDL_Renderer *renderer;
    //surface used in the loadAndRenderBmp()
    SDL_Surface *surface = NULL;
    //surface used in the changeGroundWithBmp()
    SDL_Rect groundRect;
    //SDL_Rect groundShownRect;

    //background rectangle that holds the screen width and height
    SDL_Rect backgroundRect;
    //SDL_Rect backgroundShownRect;

    //used to set the screens width and height
    const int SCREENWIDTH = 1200;
    const int SCREENHEIGHT = 1000;

    //sets the W,H,X,Y for the ground rectangle
    Screen();

    void createRectangles();

    //loads a bmp to a rectangle
    void loadAndRenderBmp(const char *imagePath);

    void loadAndRenderBmp(const char *imagePath, SDL_Rect rect);
    //void loadAndRenderBmp(const char *imagePath, SDL_Rect textureRect, SDL_Rect rect);

    //changes the background color
    void changeBackground(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

    void changeBackground(const char *imagePath);

    //changes retangle color
    void changeRectangleColor(SDL_Rect rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

    void loadHealthAndManaBar(SDL_Rect healthRect, SDL_Rect manaRect);

    //changes the grounds bmp
    void changeGroundWithBmp(const char *image);

    //creates screen with SDL_Window* window and controls the Width and height
    void createScreen();

    //creates a renderer
    void createRenderer();

    //move the screen
    void moveScreenLeft();

    void moveScreenRight();

    void moveScreen(SDL_Rect rect);

    //move ground
    void moveGroundLeft();

    void moveGroundRight();

    void moveGround(SDL_Rect rect);

    //moves scene
    void moveScene(SDL_Rect rect);

    void moveSceneRight();

    void moveSceneLeft();

    //Destroys everything and exits the main loop
    void quitSDL();


    ~Screen();

private:



};


#endif //ACTIONPACKEDADVENTUREGAME_SCREEN_H
