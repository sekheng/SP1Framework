#ifndef _PRESSUREPLATE_H
#define _PRESSUREPLATE_H

#include "game.h"
#include "traps.h"
#include "monster.h"
#include "levels.h"
#include "Loadlevel.h"
#include "block.h"
#include "item.h"
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "Framework\console.h"
#include "Framework\timer.h"
#include "playerchar.h"
#include "block.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using std::string;
using std::ifstream;
using std::stringstream;

//bool onPlate = false;
struct Plate
{
	COORD directions[20];
};

struct Hatch
{
	COORD position[20];
};

//to be placed in init
void setPlate(int x, int y, int z);

//to be placed in update
void updatePlate(int z);

//to be placed in render
void printPlate(int i);

void setHatch(int x, int y, int z);

void updateHatch(int z);

void printHatch(int i);

void resetHatch(int z);

#endif // _PRESSUREPLATE_H