#ifndef _BGMSOUNDS_H
#define _BGMSOUNDS_H

#include "game.h"
#include "monster.h"
#include <string>

using std::string;

void initBGMsounds();
void playSoundEvent();
void changesSoundEvent();
bool changesGameState(bool check_Game_State);
void removingEngine();
void PlayingBeingChased();
void ShotByCannon();
void setAllSoundToPause();
void pauseTheChasingSound();
void pauseCannonSnd();

#endif // _BGMSOUNDS_H