#ifndef _TRAPS_H
#define _TRAPS_H

#include "Framework\timer.h"
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>

COORD cannonballLocationR;
COORD cannonLocationR;
COORD cannonballLocationL;
COORD cannonLocationL;
COORD cannonballLocationU;
COORD cannonLocationU;
COORD cannonballLocationD;
COORD cannonLocationD;
COORD monsterR;

void cannonR();
void cannonballR(int x);

#endif  // _TRAPS_H
