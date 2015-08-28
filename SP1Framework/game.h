#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"
#include <irrklang.h>
using namespace irrklang;
#pragma comment(lib, "irrklang.lib") // link with irrklang.dll

extern StopWatch g_timer;
extern bool g_quitGame;

enum Keys
{
	K_UP,
	K_DOWN,
	K_LEFT,
	K_RIGHT,
	K_W,
	K_A,
	K_S,
	K_D,
	K_R,
	K_L,
	K_U,
	K_1,
	K_0,
	K_E,
	K_M,
	K_K,
	K_G,
	K_N,
	K_P,
	K_H,
	K_BOX,
	K_BACK,
    K_ESCAPE,
    K_ENTER,
    K_SPACE,
    K_COUNT
};

enum startscreen 
{
    menu,
    Start,
    LevelCustomized,
    LevelCustom,
    Help,
    Option,
    Exit,
    Pause,
    GameOver,
    End,
    GateAnimation,
    MAX_STATE
};

double timer( double& seconds);

void init();                // initialize your variables, allocate memory, etc
void getInput();            // get input from player
void update(double dt);     // update the game and the state of the game
void render();              // renders the current state of the game to the console
void shutdown();            // do clean up, free memory

void moveCharacter(double x);       // moves the character, collision detection, physics, etc
void processUserInput();    // checks if you should change states or do something else with the game, e.g. pause, exit
void clearScreen();         // clears the current screen and draw from scratch 
void renderMap();           // renders the map to the buffer first
void renderCharacter();     // renders the character into the buffer
void renderFramerate();     // renders debug information, frame rate, elapsed time, etc
void renderToScreen();      // dump the contents of the buffer to the screen, one frame worth of game

#endif // _GAME_H