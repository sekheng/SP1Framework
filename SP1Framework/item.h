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
    bool collected[10];
};

void initinventorysystem();

void keys_locations( int &keyY, int & keyX);
void displayinventory( int no_of_items = 0);
void display_keys();
void gate_location( int &GateY, int &GateX);
void display_gate();

#endif // _ITEM_H