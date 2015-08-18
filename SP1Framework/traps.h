#ifndef _TRAPS_H
#define _TRAPS_H

#include "Framework\timer.h"
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>

void electrical();
void pitFall();
void cannonLocationOnmapR(int x,int y);
void cannonRupdateR(int x);
void cannonR();//shoots towards right
void cannonLocationOnmapL(int x,int y);
void cannonRupdateL(int x);
void cannonL();//shoots towards left
void cannonLocationOnmapU(int x,int y);
void cannonRupdateU(int x);
void cannonU();//shoots towards up
void cannonLocationOnmapD(int x,int y);
void cannonRupdateD(int x);
void cannonD();//shoots towards down


#endif  // _TRAPS_H
