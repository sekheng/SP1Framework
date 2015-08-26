#ifndef _SPEEDCONTROL_H_
#define _SPEEDCONTROL_H_

#include "Framework\timer.h"
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>

void update_ballSpeed(int x, int y, int a, int b, int c, double w);
void update_charSpeed(double x);
void update_crazyMonSpeed(int z, double w);

#endif