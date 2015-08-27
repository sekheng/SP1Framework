#ifndef _MONSTER_H
#define _MONSTER_H

#include <iostream>
#include <string>
#include "game.h"
#include "Framework\timer.h"
#include "Framework\console.h"

#define MAX_SPACE 20
 struct Monster
 {
	 COORD resetCoord[MAX_SPACE];
 };

void crazyMonSpawn(int x,int y,int z);
void crazyMonUpdate(int z);
void crazyMon(int i);

void followMonSpawn(int x,int y,int z);
void followMonUpdate(int z, double w);
void followMon(int i);

void restartCrazyMonLocation(int z);
void restartFollowMonLocation(int z);

#endif  // _MONSTER_H
