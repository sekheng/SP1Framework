#ifndef _BLOCK_H
#define _BLOCK_H

#include "Framework\timer.h"
#include "game.h"
#include "Framework\console.h"
#include "traps.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>

struct Block
{
	COORD directions[20];
};

//to be placed in init
void setBlock(int x, int y, int z);

//to be placed in update
void updateBlock( int z);

//to be placed in render
void printBlock(int i);

//Restart the position of the Block
void restartBlockPosition(int z);

#endif // _BLOCK_H
