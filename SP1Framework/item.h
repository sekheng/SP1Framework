#ifndef _ITEM_H
#define _ITEM_H

#include "Framework\timer.h"
#include "game.h"
#include "Framework\console.h"
#include "playerchar.h"
#include <iostream>
#include <iomanip>
#include <fstream>

#define MAX_ITEMS 10

using std::string;
using std::ifstream;

struct Items
{
    int num_of_Keys_ineachType;
    COORD KeysLocation[MAX_ITEMS];
    bool collected[MAX_ITEMS];
    bool check_collected_keys;
};

void initinventorysystem();

void keys_locations( int keyY, int keyX, int KeyType);
void displayinventory( int no_of_items = 0);
void display_keys();
void gate_location( int GateY, int GateX, int GateType);
void display_gate();
void update_keys();
void update_gates();
void restart_keys_and_gates();

#endif // _ITEM_H