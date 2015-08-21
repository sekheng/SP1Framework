#ifndef _TRAPS_H
#define _TRAPS_H

#include "Framework\timer.h"
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>

struct Cannon
{
	COORD directions[20];
	COORD position[20];
};
//COORD cannonballLocationR;
//COORD cannonLocationR;
//COORD cannonballLocationL;
//COORD cannonLocationL;
//COORD cannonballLocationU;
//COORD cannonLocationU;
//COORD cannonballLocationD;
//COORD cannonLocationD;
//COORD monsterR;

void cannonR(int &i);
void cannonballR(int x,int z);
void locationR(int x,int y,int z);

void cannonL(int &i);
void cannonballL(int x,int z);
void locationL(int x,int y,int z);

void cannonU(int &i);
void cannonballU(int x,int z);
void locationU(int x,int y,int z);

void cannonD(int &i);
void cannonballD(int x,int z);
void locationD(int x,int y,int z);

#endif  // _TRAPS_H
