#ifndef _BGMSOUNDS_H
#define _BGMSOUNDS_H

#include "game.h"
#include "monster.h"
#include <string>

using std::string;

void initBGMsounds();
void playSoundEvent();
void replayHatchSound();
bool changesGameState(bool check_Game_State);
void removingEngine();
void PlayingBeingChased();
void ShotByCannon();
void setAllSoundToPause();
void pauseTheChasingSound();
void pauseCannonSnd();
void pauseHatchSnd();
void playHatchSound();
void playGateSound();
bool check_is_there_monster_chasing();

#endif // _BGMSOUNDS_H