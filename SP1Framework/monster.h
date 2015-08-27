#ifndef _MONSTER_H
#define _MONSTER_H

#include <iostream>
#include <string>
#include "game.h"
#include "Framework\timer.h"
#include "Framework\console.h"

void crazyMonSpawn(int x,int y,int z);
void crazyMonUpdate(int z);
void crazyMon(int i);

void followMonSpawn(int x,int y,int z);
void followMonUpdate(int z, double w);
void followMon(int i);

#endif  // _MONSTER_H
