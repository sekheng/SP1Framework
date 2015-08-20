#ifndef _PLAYERCHAR_H
#define _PLAYERCHAR_H

#include "game.h"
#include "traps.h"
#include "monster.h"
#include "levels.h"
#include "Loadlevel.h"
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "Framework\console.h"

void characterInit();
void characterMovement();
void getInput();
void characterInteraction();

#endif // _PLAYERCHAR_H