#ifndef _BGMSOUNDS_H
#define _BGMSOUNDS_H

#include "game.h"
#include <string>

using std::string;

void initBGMsounds();
void playSoundEvent();
void changesSoundEvent();
bool changesGameState(bool check_Game_State);
void removingEngine();
void PlayingThemeSong();
void PlayingBeingChased();

#endif // _BGMSOUNDS_H