#ifndef _TRAPS_H
#define _TRAPS_H

#include "Framework\timer.h"
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include "playerchar.h"



//COORD cannonballLocationR;
//COORD cannonLocationR;
////COORD cannonballLocationL;
////COORD cannonLocationL;
////COORD cannonballLocationU;
////COORD cannonLocationU;
////COORD cannonballLocationD;
////COORD cannonLocationD;
////COORD monsterR;

void cannonR(int &i);
void cannonballR(int x,int z);
void locationR(int x,int y,int z);

#endif  // _TRAPS_H
