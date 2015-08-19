#ifndef _TITLE_H
#define _TITLE_H

extern int titlearr[40][150];

#include "game.h"
#include "Framework\console.h"
#include "Framework\timer.h"
#include <fstream>
#include <string>
#include <fstream>

using std::string;
using std::ifstream;

void titleconvert(int &g);
void titleconvert2(int &a, string &x, int &c);
void menuPosition();
void displayMenu();

#endif // _TITLE_H