#ifndef _BLOCK_H
#define _BLOCK_H

#include "Framework\timer.h"
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>

struct Block
{
	COORD directions[20];
};

//to be placed in init
void setBlock(int x, int y, int z);

//to be placed in update
void updateBlock(int x, int z);

//to be placed in render
void printBlock(int &i);


#endif