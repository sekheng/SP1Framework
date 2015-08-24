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

void cannonR(int &i);
void cannonL(int &i);
void cannonU(int &i);
void cannonD(int &i);

void cannonballR(int x,int z);
void cannonballL(int x,int z);
void cannonballU(int x,int z);
void cannonballD(int x,int z);

void locationR(int x,int y,int z);
void locationL(int x,int y,int z);
void locationU(int x,int y,int z);
void locationD(int x,int y,int z);

void speed(int x, int y, double w);

#endif  // _TRAPS_H
