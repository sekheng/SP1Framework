#ifndef _PLAYERCHAR_H
#define _PLAYERCHAR_H

#include "game.h"
#include "traps.h"
#include "monster.h"
#include "levels.h"
#include "Loadlevel.h"
#include "block.h"
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "Framework\console.h"

void characterInit();
void characterMovement(double x);
void getInput();
void characterInteraction();
void characterSpawn(int x, int y);
void characterEnd(int y, int x);

#endif // _PLAYERCHAR_H