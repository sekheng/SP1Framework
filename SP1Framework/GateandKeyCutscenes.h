#ifndef _GATEANDKEYCUTSCENES_H
#define _GATEANDKEYCUTSCENES_H

#include "Framework\timer.h"
#include "game.h"
#include "Framework\console.h"
#include "item.h"
#include <fstream>
#include <string>

using std::string;
using std::ifstream;

void initGateCutscenes();

void displayGateCutscenes(double animation);

void displayOpenCutscenes();

void displayAnimationofOpenAndClose(double Timer);

#endif // _GATEANDKEYCUTSCENES_H