#ifndef _ITEM_H
#define _ITEM_H

#include "Framework\timer.h"
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using std::string;
using std::ifstream;

struct Items
{
    COORD KeysLocation;
    int item[10];
};

void initinventorysystem();

void howmany_keys( int & no_of_keys);

void displayinventory( int no_of_items = 0);

#endif // _ITEM_H