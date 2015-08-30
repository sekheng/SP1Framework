#ifndef _BGMSOUNDS_H
#define _BGMSOUNDS_H

#include "game.h"
#include <string>

using std::string;

void initBGMsounds();
void playSoundEvent();
void changesSoundEvent();
bool changesGameState(bool check_Game_State);

#endif // _BGMSOUNDS_H